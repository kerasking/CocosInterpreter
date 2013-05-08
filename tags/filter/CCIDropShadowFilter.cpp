//
//  CCIDropShadowFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#include "CCIDropShadowFilter.h"

NS_CC_EXT_BEGIN
bool CCIDropShadowFilter::initWithFilterId(UI8 filterId, cocos2d::extension::CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    this->DropShadowColor = new CCIRGBA(reader);
    
    
    this->BlurX = reader->readFIXED();
    this->BlurY = reader->readFIXED();
    this->Angle = reader->readFIXED();
    this->Distance = reader->readFIXED();
    
    this->Strength = reader->readFIXED8();
    
    reader->clearBits();
    
    this->InnerShadow = reader->readUBits(1);
    this->Knockout = reader->readUBits(1);
    this->CompositeSource = reader->readUBits(1);
    this->Passes = reader->readUBits(5);
    
    reader->clearBits();
        
    return true;
}
CCIDropShadowFilter::~CCIDropShadowFilter(){
    delete this->DropShadowColor;
}
NS_CC_EXT_END