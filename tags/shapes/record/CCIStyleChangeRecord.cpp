//
//  CCIStyleChangeRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCIStyleChangeRecord.h"
NS_CC_EXT_BEGIN
CCIStyleChangeRecord::CCIStyleChangeRecord(CCIBufferReader * reader,UI8 numFillBits,UI8 numLineBits):CCIShapeRecord(reader,numFillBits,numLineBits){
    this->StateNewStyles = reader->readUBits(1);
    this->StateLineStyle = reader->readUBits(1);
    
    this->StateFillStyle1 = reader->readUBits(1);
    this->StateFillStyle0 = reader->readUBits(1);
    
    this->StateMoveTo = reader->readUBits(1);
    
    if (this->StateMoveTo) {
        this->MoveBits = reader->readUBits(5);
        this->MoveDeltaX = reader->readSBits(this->MoveBits);
        this->MoveDeltaY = reader->readSBits(this->MoveBits);
    }
    if (this->StateFillStyle0) {
        this->FillStyle0 = reader->readUBits(numFillBits);
    }
    if (this->StateFillStyle1) {
        this->FillStyle1 = reader->readUBits(numFillBits);
    }
    if (this->StateLineStyle) {
        this->LineStyle = reader->readUBits(numLineBits);
    }
    if (this->StateNewStyles) {//add clearbits
        reader->clearBits();
        this->FillStyles = new CCIFillStyleArray(reader);
        this->LineStyles =  new CCILineStyleArray(reader);
        
        this->NumFillBits = reader->readUBits(4);
        this->NumLineBits = reader->readUBits(4);
    }
    
    this->ShapeType = ShapeTypeStyle;
}

NS_CC_EXT_END