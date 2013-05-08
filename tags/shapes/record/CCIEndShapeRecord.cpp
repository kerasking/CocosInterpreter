//
//  CCIEndShapeRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCIEndShapeRecord.h"
NS_CC_EXT_BEGIN
CCIEndShapeRecord::CCIEndShapeRecord(CCIBufferReader * reader,UI8 numFillBits,UI8 NumLineBits):CCIShapeRecord(reader,numFillBits,NumLineBits){
    this->EndOfShape = reader->readUBits(5);
    this->ShapeType = ShapeTypeEnd;
}

NS_CC_EXT_END