//
//  CCIShapeRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCIShapeRecord.h"
NS_CC_EXT_BEGIN
CCIShapeRecord::CCIShapeRecord(CCIBufferReader * reader,UI8 NumFillBits,UI8 numLineBits){
    this->TypeFlag = reader->readUBits(1);
}

NS_CC_EXT_END