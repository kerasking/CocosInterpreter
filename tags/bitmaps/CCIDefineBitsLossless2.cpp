//
//  CCIDefineBitsLossless2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIDefineBitsLossless2.h"

NS_CC_EXT_BEGIN
bool CCIDefineBitsLossless2::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIDefineBitsLossless::initWithReader(reader, tagType, tagLength);
    
    
    
    return true;
}
void CCIDefineBitsLossless2::loadImageData(UI8 * imageData){
    if (this->bitmapFormat==3) {
        //ALPHACOLORMAPDATA
        this->loadIDXA(imageData);
    }else if(this->bitmapFormat==4||this->bitmapFormat==5){
        //ALPHABITMAPDATA
        this->loadRGBA(imageData);
         
    }
}
void CCIDefineBitsLossless2::loadRGBA(UI8 *imageData){
    UI8 * data = this->unzip(imageData);
    int pos = 0;
    int index =0;
    
    UI8 * imageRGBA = new UI8[this->width*this->height*4];
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++, index += 4) {
            imageRGBA[index + 3] = data[pos++];
            imageRGBA[index + 0] = data[pos++];
            imageRGBA[index + 1] = data[pos++];
            imageRGBA[index + 2] = data[pos++];
        }
    }
    
    this->createTextureWithRGBAImage(imageRGBA);
}
void CCIDefineBitsLossless2::loadIDXA(UI8 *imageData){
    UI8 * data = this->unzip(imageData);
    int scanLength = (width + 3) & ~3;
    int tableLength = this->bitmapColorTableSize;
    
    int pos = 0;
    int index = 0;
    
    UI8 * table = new UI8[tableLength * 4];
    UI8 * indexImageData = new UI8[this->width*this->height];
    
    for (int i = 0; i < tableLength; i++, index += 4) {
        table[index + 3] = data[pos++];
        table[index + 2] = data[pos++];
        table[index + 1] = data[pos++];
        table[index] = data[pos++];
    }
    index = 0;
    
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++, index++) {
            indexImageData[index] = data[pos++];
        }
        pos += (scanLength - width);
    }
    this->createTextureWithIndexImage(indexImageData,table,tableLength * 4);
}
NS_CC_EXT_END