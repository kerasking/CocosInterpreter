//
//  CCICurvedEdgeRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCICurvedEdgeRecord.h"
NS_CC_EXT_BEGIN
CCICurvedEdgeRecord::CCICurvedEdgeRecord(CCIBufferReader * reader,UI8 numFillBits,UI8 numLineBits):CCIShapeRecord(reader,numFillBits,numLineBits){
    this->StraightFlag = reader->readUBits(1);
    this->NumBits = reader->readUBits(4)+2;
    this->ControlDeltaX = reader->readSBits(this->NumBits);
    this->ControlDeltaY = reader->readSBits(this->NumBits);
    
    this->AnchorDeltaX = reader->readSBits(this->NumBits);
    this->AnchorDeltaY = reader->readSBits(this->NumBits);
    
    this->ShapeType = ShapeTypeCurved;
}

NS_CC_EXT_END