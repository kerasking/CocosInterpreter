//
//  CCIRGBA.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIRGBA.h"
NS_CC_EXT_BEGIN

CCIRGBA::CCIRGBA(CCIBufferReader *reader):CCIRGB(reader){
    this->Alpha = reader->readUI8();
}

NS_CC_EXT_END