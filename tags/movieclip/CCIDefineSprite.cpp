//
//  CCIDefineSprite.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIDefineSprite.h"
NS_CC_EXT_BEGIN

bool CCIDefineSprite::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->spriteId = reader->readUI16();
    this->frameCount = reader->readUI16();
    
    CCIMovieTag * tag = CCIMovieTag::next(reader);
    while (tag&&tag->getTagType()!=TagTypeEnd) {
        controlTags.push_back(tag);
        tag = CCIMovieTag::next(reader);
    }
    if (tag) {
        controlTags.push_back(tag);
    }
    
    return true;
}
std::vector<CCIMovieTag *> CCIDefineSprite::getControlTags(){
    return this->controlTags;
}
UI16 CCIDefineSprite::getSpriteId(){
    return this->spriteId;
}
CCIDefineSprite::~CCIDefineSprite(){
    for (int i=0; i<this->controlTags.size(); i++) {
        CCIMovieTag * tag = controlTags[i];
        delete tag;
    }
    controlTags.clear();
}
NS_CC_EXT_END