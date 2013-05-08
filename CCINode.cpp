//
//  CCINode.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-7.
//
//

#include "CCINode.h"
#include "CCImage.h"
#include "CCIImageTag.h"
#include "CCIPlaceObject2.h"
#include "CCIPlaceObject3.h"
#include "CCIRemoveObject2.h"

#include "CCTexture2D.h"
#include "CCTextureCache.h"
#include "CCSprite.h"

#include "CCIDefineShape.h"
#include "CCIDefineSprite.h"
#include "CCAffineTransform.h"
#include "CCDirector.h"
#include "CCLayer.h"
#include "ccMacros.h"
#include "CCIStyleChangeRecord.h"
#include "CCInteger.h"

NS_CC_EXT_BEGIN


#define NodeTypeSprite 0
#define NodeTypeNode 1
#define NodeTypeCCINode 2

CCINode::CCINode(){
}
CCINode::~CCINode(){
    this->textures->release();
    this->nodes->release();
}
bool CCINode::initWithFile(std::string cci_filename){
    CCIMovie * swfMovie = CCIMovie::decodeFromFile(cci_filename);
    
    CCDictionary * nodes = CCDictionary::create();
    this->initWithTags(swfMovie->getTags(), swfMovie,nodes);
    this->setAnchorPoint(CCPointMake(0.5, 0.5));
    return true;
}
bool CCINode::initWithTags(std::vector<CCIMovieTag *> tags,CCIMovie * swfMovie,CCDictionary * nodes){
    
    this->textures = CCDictionary::create();
    this->textures->retain();
    this->nodes = nodes;
    this->nodes->retain();
    
    isPlaying = false;
    
    this->swfMovie = swfMovie;
    this->tags = tags;
    this->frameRate =this->swfMovie->getHeader()->getFrameRate();
    this->frameCount = this->swfMovie->getHeader()->getFrameCount();
    
    currentTag = 0;
    
    this->setContentSize(this->swfMovie->getHeader()->getBounds()->getSize());
    this->setAnchorPoint(CCPointMake(0, 1));//ajust position for moveclips
    this->loadImages();
    
    this->showFrame();
    return true;
}

CCINode * CCINode::create(std::string cci_filename){
    CCINode * ret = new CCINode();
    if (ret->initWithFile(cci_filename)) {
        ret->autorelease();
        return ret;
    }
    return NULL;
}
CCINode * CCINode::createWithTags(std::vector<CCIMovieTag *> tags,CCIMovie * swfMovie,CCDictionary * nodes){
    CCINode * ret = new CCINode();
    if (ret->initWithTags(tags, swfMovie,nodes)) {
        ret->autorelease();
        return ret;
    }
    return NULL;
}
void CCINode::loadImages(){
    int tagIndex = 0;
    while (true) {
        CCIMovieTag * tag = NULL;
        if (tagIndex<tags.size()) {
            tag = tags[tagIndex++];
        }else{
            tagIndex = 0;
            break;
        }
        if (tag->getTagType()==TagTypeDefineBitsLossless2 || tag->getTagType()==TagTypeDefineBitsJPEG3||tag->getTagType()==TagTypeDefineBitsJPEG2||tag->getTagType()==TagTypeDefineBits) {
            CCIImageTag* imageTag = (CCIImageTag*)tag;
            CCTexture2D * text = imageTag->getTexture();
            if (text) {
                this->textures->setObject(text, imageTag->getCharacterID());
            }
            
            
        }else if(tag->getTagType()==TagTypeDefineShape||tag->getTagType()==TagTypeDefineShape2||tag->getTagType()==TagTypeDefineShape3){
            //shape是可以放上去的精灵
            
            CCIDefineShape * defineShapeTag = (CCIDefineShape *)tag;
            CCIRect *bounds = defineShapeTag->getBounds();
            
            CCNode * shape = CCNode::create();
            //CCNode * shape = CCLayerColor::create(ccc4(200,0,0,100));
            //shape->ignoreAnchorPointForPosition(false);
            shape->setContentSize(bounds->getSize());
            
            shape->setAnchorPoint(bounds->getAnchorPoint());
            //shape->ignoreAnchorPointForPosition(true);
            
            shape->setUserObject(CCInteger::create(NodeTypeNode));
            
            CCIShapeWithStyle * style = defineShapeTag->getShapes();
            CCIFillStyleArray * fileStyles = style->FillStyles;
            this->fillNodeWithStyle(fileStyles, shape,bounds);
            
            for (int i=0; i<style->ShapeRecords.size(); i++) {
                CCIShapeRecord * record = style->ShapeRecords[i];
                if (record->ShapeType==ShapeTypeStyle){
                    CCIStyleChangeRecord * styleRecord = (CCIStyleChangeRecord *)record;
                    if (styleRecord->StateNewStyles) {
                        fileStyles = styleRecord->FillStyles;
                        this->fillNodeWithStyle(fileStyles, shape,bounds);
                    }
                }
            }
            
            this->nodes->setObject(shape, defineShapeTag->getShapeId());
            
        }else if(tag->getTagType()==TagTypeDefineSprite){
            CCIDefineSprite * sprite = (CCIDefineSprite *)tag;
            
            CCINode * node = CCINode::createWithTags(sprite->getControlTags(), this->swfMovie,this->nodes);
            
            node->setUserObject(CCInteger::create(NodeTypeCCINode));
            this->nodes->setObject(node, sprite->getSpriteId());
        }
    }
}

void CCINode::play(){
    if (!isPlaying) {
        currentFrame = 0;
        isPlayingFrameLabel = false;
        isPlaying = true;
        this->schedule(schedule_selector(CCINode::showFrame), 1/this->frameRate);
    }
    
}
void CCINode::stop(){
    isPlaying = false;
    isPlayingFrameLabel = false;
    this->unschedule(schedule_selector(CCINode::showFrame));
}

void CCINode::showFrame(){
    //std::vector<CCIMovieTag *> tags = this->swfMovie->getTags();

    while (true) {
        CCIMovieTag * tag = NULL;
        
        if (currentTag<tags.size()) {
            tag = tags[currentTag++];
        }else{
            
            this->removeAllChildrenWithCleanup(true);
            //this->stop();
            currentTag = 0;
            currentFrame = 0;
            break;
        }
        if(tag->getTagType()==TagTypePlaceObject||tag->getTagType()==TagTypePlaceObject2||tag->getTagType()==TagTypePlaceObject3){
            CCIPlaceObject * placeTag = (CCIPlaceObject *)tag;
            
            int charactorId = placeTag->getCharacterId();
            int depth = placeTag->getDepth();
            
            
            CCIPlaceObject2 * placeTag2 = NULL;
            if (tag->getTagType()==TagTypePlaceObject2||tag->getTagType()==TagTypePlaceObject3) {
                placeTag2 = (CCIPlaceObject2 *)tag;
            }
            
            CCNode * node;
            if (!placeTag2||placeTag2->placeType==PlaceObjectTypeNew) {
                //place1 or placetag2 new
                node = (CCNode *)this->nodes->objectForKey(charactorId);
                if (node&&node->getParent()==NULL) {
                    this->addChild(node, depth, depth);
                    CCInteger * nodeType = (CCInteger *)node->getUserObject();
                    if (nodeType->getValue()==NodeTypeCCINode) {
                        CCINode * ccinode = (CCINode *)node;
                        ccinode->play();
                    }
                }
            }else if(placeTag2&&placeTag2->placeType==PlaceObjectTypeModify){
                node = (CCNode *)this->getChildByTag(depth);
            }else if(placeTag2&&placeTag2->placeType==PlaceObjectTypeReplace){
                
                CCNode * newNode = (CCNode *)this->nodes->objectForKey(charactorId);
                
                node = (CCNode *)this->getChildByTag(depth);
                if (node) {
                    if (newNode) {
                        //get last transform matrix
                        newNode->setPosition(node->getPosition());
                        newNode->setScaleX(node->getScaleX());
                        newNode->setScaleY(node->getScaleY());
                        newNode->setSkewX(node->getSkewX());
                        newNode->setSkewY(node->getSkewY());
                    }
                    CCInteger * nodeType = (CCInteger *)node->getUserObject();
                    if (nodeType->getValue()==NodeTypeCCINode) {
                        CCINode * ccinode = (CCINode *)node;
                        ccinode->stop();
                    }
                    node->removeFromParentAndCleanup(true);
                }
                
                node = newNode;
                if (node&&node->getParent()==NULL) {
                    this->addChild(node, depth, depth);
                    CCInteger * nodeType = (CCInteger *)node->getUserObject();
                    if (nodeType->getValue()==NodeTypeCCINode) {
                        CCINode * ccinode = (CCINode *)node;
                        ccinode->play();
                    }
                }
                
            }
            
            if (node) {
                CCIMatrix * matrix = placeTag->getMatrix();
                if (matrix) {
                    int x = matrix->getTranslateX();
                    int y = matrix->getTranslateY();
                    
                    node->setPosition(this->swfMovie->getHeader()->getBounds()->convertToCCSpace(x, y));
                    //restore
                    node->setScaleX(1);
                    node->setScaleY(1);
                    node->setSkewX(0);
                    node->setSkewY(0);
                    
                    if (matrix->HasScale) {
                        node->setScaleX(matrix->getScaleX());
                        node->setScaleY(matrix->getScaleY());
                    }
                    if (matrix->HasRotate) {
                        float skewX = matrix->getSkewX();
                        float skewY = matrix->getSkewY();
                        
                        node->setSkewX(skewX);
                        node->setSkewY(skewY);
                        
                        //fix skew
                        node->setScaleX(node->getScaleX()*cos(CC_DEGREES_TO_RADIANS(-skewX)));
                        node->setScaleY(node->getScaleY()*cos(CC_DEGREES_TO_RADIANS(skewY)));
                    }
                    
                }
                CCICxform * colorTransform = placeTag->getColorTransform();
                
                int red = 255;
                int green = 255;
                int blue = 255;
                int alpha = 255;
                
                if (colorTransform) {
                    if (colorTransform->HasMultTerms) {
                        red = colorTransform->RedMultTerm-1;
                        green = colorTransform->GreenMultTerm-1;
                        blue = colorTransform->BlueMultTerm-1;
                        if (colorTransform->hasAlpha()) {
                            CCICxformWithAlpha * cxformAlpha = (CCICxformWithAlpha *)colorTransform;
                            alpha = cxformAlpha->AlphaMultTerm-1;
                        }
                    }
                    
                    if (colorTransform->HasAddTerms) {
                        //TODO no add term
                    }
                    if (red==-1) {
                        red = 0;
                    }
                    if (green ==-1) {
                        green = 0;
                    }
                    if (blue == -1) {
                        blue = 0;
                    }
                    if (alpha ==-1) {
                        alpha = 0;
                    }
                }
                
                this->applyColorTransform(node, ccc4(red, green, blue, alpha));
                
                if (tag->getTagType()==TagTypePlaceObject3) {
                    //check filters
                    CCIPlaceObject3 * placeTag3 = (CCIPlaceObject3 *)tag;
                    
                    CCIFilterList * filterList = placeTag3->getFilterList();
                        
                    if (filterList) {
                        //apply filter list
                        for (int i=0; i<filterList->NumberOfFilters; i++) {
                            //CCIFilter * filter = filterList->Filter[i];
                            
                        }
                    }
                }
            }
        }else if (tag->getTagType()==TagTypeRemoveObject||tag->getTagType()==TagTypeRemoveObject2){
            CCIRemoveObject * removeTag = (CCIRemoveObject *)tag;
            int depth = removeTag->getDepth();
            CCNode * node = this->getChildByTag(depth);
            if (node) {
                CCInteger * nodeType = (CCInteger *)node->getUserObject();
                if (nodeType->getValue()==NodeTypeCCINode) {
                    CCINode * ccinode = (CCINode *)node;
                    ccinode->stop();
                }
                node->removeFromParentAndCleanup(true);
            }
        }else if(tag->getTagType()==TagTypeFrameLabel){
            if (isPlayingFrameLabel&&currentTag!=frameLabelIndex) {
                currentTag = frameLabelIndex;
                currentFrame = 0;
                //this->removeAllChildrenWithCleanup(true);
                break;
            }
        }else if(tag->getTagType()==TagTypeShowFrame){
            if (this->delegate) {
                this->delegate->didEnterFrame(currentFrame, this->frameLabel);
            }
            currentFrame++;
            
            break;
        }
    }
}
void CCINode::applyColorTransform(cocos2d::CCNode *node, ccColor4B colorTransform){
    CCArray * children =  node->getChildren();
    for (int i=0; i<node->getChildrenCount(); i++) {
        CCNode * childNode = (CCNode *)children->objectAtIndex(i);
        CCInteger * type = (CCInteger *)childNode->getUserObject();
        if (type->getValue()==NodeTypeSprite) {
            CCSprite * sprite = (CCSprite *)childNode;
            sprite->setColor(ccc3(colorTransform.r, colorTransform.g, colorTransform.b));
            sprite->setOpacity(colorTransform.a);
        }else{
            this->applyColorTransform(childNode, colorTransform);
        }
    }
}


void CCINode::fillNodeWithStyle(CCIFillStyleArray * fillStyles,CCNode * node,CCIRect * nodeBounds){
    if (fillStyles->FillStyles.size()>0) {
        for (int i=0; i<fillStyles->styleCount; i++) {
            CCIFillStyle * fillStyle = fillStyles->FillStyles[i];
            if (fillStyle&&fillStyle->BitmapId) {
                CCTexture2D * texture2d = (CCTexture2D *)this->textures->objectForKey(fillStyle->BitmapId);
                if (texture2d) {
                    CCSprite * sprite = CCSprite::createWithTexture(texture2d);
                    
                    //sprite->setAnchorPoint(CCPointMake(-0.5, 1.5));
                    sprite->setAnchorPoint(CCPointMake(0, 1));
                    
                    CCIMatrix * spriteMatrix = fillStyle->BitmapMatrix;
                    
                    int x = spriteMatrix->getTranslateX();
                    int y = spriteMatrix->getTranslateY();
                    
                    sprite->setPosition(nodeBounds->convertToCCSpace(x, y));
                    
                    sprite->setUserObject(CCInteger::create(NodeTypeSprite));
                    
                    if (spriteMatrix->HasScale) {
                        sprite->setScaleX(spriteMatrix->getScaleX()/20.0);
                        sprite->setScaleY(spriteMatrix->getScaleY()/20.0);
                    }
                    if (spriteMatrix->HasRotate) {
                        float skewX = spriteMatrix->getSkewX();
                        float skewY = spriteMatrix->getSkewY();
                        sprite->setSkewX(skewX);
                        sprite->setSkewY(skewY);
                        
                        //fix skew
                        sprite->setScaleX(sprite->getScaleX()*cos(CC_DEGREES_TO_RADIANS(-skewX)));
                        sprite->setScaleY(sprite->getScaleY()*cos(CC_DEGREES_TO_RADIANS(skewY)));
                    }
                    node->addChild(sprite);
                }
            }
        }
    }
}
void CCINode::gotoAndPlay(std::string frameFlag){
    if (!isPlaying) {
        currentFrame = 0;
        frameLabel = frameFlag;
        CCString* tagIndexString = (CCString*)this->swfMovie->getFrameLabels()->objectForKey(frameFlag);
        if (tagIndexString) {
            frameLabelIndex = tagIndexString->intValue()+1;
            currentTag = frameLabelIndex-1;
            isPlayingFrameLabel = true;
            isPlaying = true;
            this->removeAllChildrenWithCleanup(true);
            this->schedule(schedule_selector(CCINode::showFrame), 1/this->frameRate);
        }
        
    }
    
}
void CCINode::setResize(float resize){
    this->resize = resize;
    this->setScaleX(originalScaleX);
    this->setScaleY(originalScaleY);
}
void CCINode::setFlipX(bool flipX){
    this->flipX = flipX;
    this->setScaleX(originalScaleX);
}
void CCINode::setFlipY(bool flipY){
    this->flipY = flipY;
    this->setScaleY(originalScaleY);
}

void CCINode::setScaleX(float scaleX){
    originalScaleX = scaleX;
    float sx = scaleX*(this->flipX?-1:1)*this->resize;
    CCNode::setScaleX(sx);
}
void CCINode::setScaleY(float scaleY){
    originalScaleY = scaleY;
    float sy = scaleY*(this->flipY?-1:1)*this->resize;
    CCNode::setScaleY(sy);
}
void CCINode::setScale(float scale){
    this->setScaleX(scale);
    this->setScaleY(scale);
}
float CCINode::getScale(){
    return this->getScaleX();
}
float CCINode::getScaleX(){
    return originalScaleX;
}
float CCINode::getScaleY(){
    return originalScaleY;
}

void CCINode::setDelegate(cocos2d::extension::CCINodeFrameDelegate *delegate){
    this->delegate = delegate;
}
CCINodeFrameDelegate * CCINode::getDelegate(){
    return this->delegate;
}
NS_CC_EXT_END