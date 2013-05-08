//
//  CCIStraightEdgeRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCIStraightEdgeRecord.h"
NS_CC_EXT_BEGIN
CCIStraightEdgeRecord::CCIStraightEdgeRecord(CCIBufferReader * reader,UI8 numFillBits,UI8 numLineBits):CCIShapeRecord(reader,numFillBits,numLineBits){
    this->StraightFlag = reader->readUBits(1);
    this->NumBits = reader->readUBits(4)+2;
    this->GeneralLineFlag = reader->readUBits(1);
    
    if (this->GeneralLineFlag==0) {
        this->VertLineFlag = reader->readSBits(1);
        if (this->VertLineFlag==0) {
            this->DeltaX = reader->readSBits(this->NumBits);
            this->DeltaY = 0;
        }else{
            this->DeltaX = 0;
            this->DeltaY = reader->readSBits(this->NumBits);
        }
    }else{
        this->DeltaX = reader->readSBits(this->NumBits);
        this->DeltaY = reader->readSBits(this->NumBits);
    }
    this->ShapeType = ShapeTypeStraight;
}

NS_CC_EXT_END