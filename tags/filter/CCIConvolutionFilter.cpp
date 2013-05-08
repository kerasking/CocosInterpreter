//
//  CCIConvolutionFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#include "CCIConvolutionFilter.h"


NS_CC_EXT_BEGIN
bool CCIConvolutionFilter::initWithFilterId(UI8 filterId, cocos2d::extension::CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    this->MatrixX = reader->readUI8();
    this->MatrixY = reader->readUI8();
    
    this->Divisor = reader->readFLOAT();
    this->Bias = reader->readFLOAT();
    int num = this->MatrixX*this->MatrixY;
    this->Matrix = new FLOAT[num];
    for (int i=0; i<num; i++) {
        this->Matrix[i] = reader->readFLOAT();
    }
    
    this->DefaultColor = new CCIRGBA(reader);
    
    
    reader->clearBits();
    this->Reserved = reader->readUBits(6);
    this->Clamp = reader->readUBits(1);
    this->PreserveAlpha = reader->readUBits(1);
    reader->clearBits();
    return true;
}
CCIConvolutionFilter::~CCIConvolutionFilter(){
    delete this->Matrix;
    delete this->DefaultColor;
}
NS_CC_EXT_END