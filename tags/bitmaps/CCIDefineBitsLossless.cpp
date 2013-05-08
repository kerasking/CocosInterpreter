//
//  CCIDefineBitsLossless.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIDefineBitsLossless.h"
NS_CC_EXT_BEGIN
bool CCIDefineBitsLossless::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIImageTag::initWithReader(reader, tagType, tagLength);
    
    this->bitmapFormat = reader->readUI8();
    
    this->width = reader->readUI16();
    this->height = reader->readUI16();
    
    int total = 7;
    if (this->bitmapFormat==3) {
        this->bitmapColorTableSize = reader->readUI8()+1;
        total++;
    }
    this->imageSize = tagLength-total;
    this->loadImageData(reader->readBytes(this->imageSize));
    
    
    return true;
}
void CCIDefineBitsLossless::loadImageData(UI8* imageData){
    if (this->bitmapFormat==3) {
        //COLORMAPDATA
        
        
        
    }else if(this->bitmapFormat==4){
        //BITMAPDATA PIX15
            
    }else if(this->bitmapFormat==5){
        //BITMAPDATA PIX24
    }
}

NS_CC_EXT_END