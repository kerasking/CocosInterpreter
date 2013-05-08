//
//  CCIGradient.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIGradient.h"
NS_CC_EXT_BEGIN

CCIGradient::CCIGradient(CCIBufferReader * reader){
    this->SpreadMode = reader->readUBits(2);
    this->InterpolationMode = reader->readUBits(2);
    this->NumGradients = reader->readUBits(4);
    reader->clearBits();
    
    for (int i=0; i<this->NumGradients; i++) {
        CCIGradRecord * record = new CCIGradRecord(reader);
        this->GradientRecords.push_back(record);
    }
}
CCIGradient::~CCIGradient(){
    for (int i=0; i<GradientRecords.size(); i++) {
        CCIGradRecord * record = GradientRecords[i];
        delete record;
    }
    GradientRecords.clear();
}
NS_CC_EXT_END