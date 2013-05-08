//
//  CCIFillStyle.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIFillStyle.h"
#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN

CCIFillStyle::CCIFillStyle(CCIBufferReader * reader){
    this->FillStyleType = reader->readUI8();
    if (this->FillStyleType==0x00) {
        CCIRGB * rgb;
        if (reader->tagType == TagTypeDefineShape||reader->tagType == TagTypeDefineShape2) {
            rgb = new CCIRGB(reader);
        }else{
            rgb = new CCIRGBA(reader);
        }
        this->Color = rgb->getColor();
    }else if (this->FillStyleType==0x10||this->FillStyleType==0x12||this->FillStyleType==0x13) {
        this->GradientMatrix = new CCIMatrix(reader);
        if (this->FillStyleType==0x13) {
            this->Gradient = new CCIFocalGradient(reader);
        }else{
            this->Gradient = new CCIGradient(reader);
        }
    }else if(this->FillStyleType==0x40||this->FillStyleType==0x41||this->FillStyleType==0x42||this->FillStyleType==0x43){
        this->BitmapId = reader->readUI16();
        this->BitmapMatrix = new CCIMatrix(reader);
    }
}
CCIFillStyle::~CCIFillStyle(){
    if (this->GradientMatrix) {
        delete this->GradientMatrix;
    }
    if (this->BitmapMatrix) {
        delete this->BitmapMatrix;
    }
    if (this->Gradient) {
        delete this->Gradient;
    }
}
NS_CC_EXT_END