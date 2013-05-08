//
//  CCIBevelFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#include "CCIBevelFilter.h"

NS_CC_EXT_BEGIN
bool CCIBevelFilter::initWithFilterId(UI8 filterId, cocos2d::extension::CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    this->ShadowColor = new CCIRGBA(reader);
    
    this->HighlightColor = new CCIRGBA(reader);
    
    this->BlurX = reader->readFIXED();
    this->BlurY = reader->readFIXED();
    this->Angle = reader->readFIXED();
    this->Distance = reader->readFIXED();
    
    this->Strength = reader->readFIXED8();
    
    reader->clearBits();
    
    this->InnerShadow = reader->readUBits(1);
    this->Knockout = reader->readUBits(1);
    this->CompositeSource = reader->readUBits(1);
    this->OnTop = reader->readUBits(1);
    this->Passes = reader->readUBits(4);
    
    reader->clearBits();
    
    return true;
}
CCIBevelFilter::~CCIBevelFilter(){
    delete this->ShadowColor;
    delete this->HighlightColor;
}
NS_CC_EXT_END