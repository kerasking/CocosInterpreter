//
//  CCIDefineBitsJPEG4.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineBitsJPEG4.h"
NS_CC_EXT_BEGIN
bool CCIDefineBitsJPEG4::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIImageTag::initWithReader(reader, tagType, tagLength);
    
    this->alphaDataOffset = reader->readUI32();
    
    this->deblockParam = reader->readUI16();
    
    imageSize =  this->alphaDataOffset;
    
    this->imageData = reader->readBytes(this->alphaDataOffset);
    
    this->bitmapAlphaData = reader->readBytes(tagLength-8-this->alphaDataOffset);
    
    this->loadImageData(imageData);
    return true;
}
void CCIDefineBitsJPEG4::loadImageData(UI8 * imageData){
    this->decodeInfo(imageData);
}
NS_CC_EXT_END