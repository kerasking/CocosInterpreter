//
//  CCIDefineBitsJPEG2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineBitsJPEG2.h"
NS_CC_EXT_BEGIN
bool CCIDefineBitsJPEG2::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIDefineBits::initWithReader(reader, tagType, tagLength);

    return true;
}
void CCIDefineBitsJPEG2::loadImageData(UI8 * imageData){
    CCIDefineBits::loadImageData(imageData);
}
NS_CC_EXT_END