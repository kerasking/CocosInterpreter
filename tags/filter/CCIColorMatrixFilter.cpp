//
//  CCIColorMatrixFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIColorMatrixFilter.h"

NS_CC_EXT_BEGIN
bool CCIColorMatrixFilter::initWithFilterId(UI8 filterId, cocos2d::extension::CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    for (int i=0; i<20; i++) {
        this->Matrix[i] = reader->readFLOAT();
    }
    
    return true;
}
NS_CC_EXT_END