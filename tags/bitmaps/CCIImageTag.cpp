//
//  CCIImageTag.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIImageTag.h"
#include "ZipUtils.h"
#include "CCTexture2D.h"
NS_CC_EXT_BEGIN
bool CCIImageTag::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    this->characterID = reader->readUI16();
    
    return true;
}
void CCIImageTag::loadImageData(UI8* imageData){

}
CCTexture2D * CCIImageTag::getTexture(){
    return this->texture2d;
}
int CCIImageTag::getCharacterID(){
    return this->characterID;
}

UI8 * CCIImageTag::unzip(UI8 * bytes){
    int length = this->width*this->height*4;
    UI8 * data = new UI8[length];
    int count = 0;
    count = ZipUtils::ccInflateMemoryWithHint(bytes, imageSize, &data,length);
    
    UI8 * uncompressedData = new UI8[count];
    memcpy(uncompressedData,data,count);
    
    delete [] data;
    return uncompressedData;
}
void CCIImageTag::createTextureWithRGBAImage(UI8 * RGBAImageData){
    this->texture2d = new CCTexture2D();
    
    
    this->texture2d->initWithData(RGBAImageData, kTexture2DPixelFormat_RGBA8888, this->width, this->height,CCSizeMake(this->width, this->height));
    
}
void CCIImageTag::createTextureWithIndexImage(UI8 * indexImageData,UI8 * tableData,int tableLength){
    int index = 0;
    int color;
    int c = 0;
    
    UI8 * imageRGBA = new UI8[this->width*this->height*4];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++, index++,c+=4) {
            color = indexImageData[index]<<2;
            
            imageRGBA[c+3] = tableData[color+3];
            imageRGBA[c+0] = tableData[color+0];
            imageRGBA[c+1] = tableData[color+1];
            imageRGBA[c+2] = tableData[color+2];
        }
    }
    this->createTextureWithRGBAImage(imageRGBA);
}
void CCIImageTag::createTextureWithImageAndAlpha(CCImage *image,UI8 *alpha){
    unsigned char*            imageData = image->getData();
    bool                      hasAlpha = image->hasAlpha();
    
    int index = 0;
    int c = 0;
    // compute pixel format
    UI8 * imageRGBA = new UI8[width*height*4];
    if(hasAlpha)
    {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++, index++,c+=4) {
                imageRGBA[c+3] = alpha[index];
                
                imageRGBA[c+0] = imageData[c+0];
                imageRGBA[c+1] = imageData[c+1];
                imageRGBA[c+2] = imageData[c+2];
            }
        }
        this->texture2d = new CCTexture2D();
        this->texture2d->initWithData(imageRGBA, kTexture2DPixelFormat_RGBA8888, width, height, CCSizeMake(this->width, this->height));
    }
    
    delete [] imageRGBA;
    
}
CCIImageTag::~CCIImageTag(){
    delete texture2d;
}
NS_CC_EXT_END