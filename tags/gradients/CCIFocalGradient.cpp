//
//  CCIFocalGradient.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIFocalGradient.h"
NS_CC_EXT_BEGIN

CCIFocalGradient::CCIFocalGradient(CCIBufferReader * reader):CCIGradient(reader){
    this->FocalPoint = reader->readFIXED8();
}
NS_CC_EXT_END