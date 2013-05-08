//
//  CCILineStyle2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#include "CCILineStyle2.h"
#include "CCIRGBA.h"
#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN
CCILineStyle2::CCILineStyle2(CCIBufferReader * reader){
    this->Width = reader->readUI16();
    this->StartCapStyle = reader->readUBits(2);
    this->JoinStyle = reader->readUBits(2);
    this->HasFillFlag = reader->readUBits(1);
    this->NoHScaleFlag = reader->readUBits(1);
    
    this->NoVScaleFlag = reader->readUBits(1);
    this->PixelHintingFlag = reader->readUBits(1);
    
    this->Reserved = reader->readUBits(5);
    
    this->NoClose = reader->readUBits(1);
    this->EndCapStyle = reader->readUBits(2);
    if (this->JoinStyle==2) {
        this->MiterLimitFactor = reader->readUI16();
    }
    if (this->HasFillFlag) {
        this->FillType = new CCIFillStyle(reader);
    }else{
        CCIRGB *rgb = new CCIRGBA(reader);
        this->Color = rgb->getColor();
        delete rgb;
        this->FillType = NULL;
    }
    
}
CCILineStyle2::~CCILineStyle2(){
    if (this->FillType) {
        delete this->FillType;
    }
}
NS_CC_EXT_END