//
//  CCICxform.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCICxform.h"
NS_CC_EXT_BEGIN
CCICxform::CCICxform(){
}
CCICxform::CCICxform(CCIBufferReader *reader){
    reader->clearBits();
    this->HasAddTerms = reader->readUBits(1)?1:0;
    this->HasMultTerms = reader->readUBits(1)?1:0;
    
    this->Nbits = reader->readUBits(4);
    if (this->HasMultTerms) {
        this->RedMultTerm = reader->readSBits(this->Nbits);
        this->GreenMultTerm = reader->readSBits(this->Nbits);
        this->BlueMultTerm = reader->readSBits(this->Nbits);
    }
    
    if (this->HasAddTerms) {
        this->RedAddTerm = reader->readSBits(this->Nbits);
        this->GreenAddTerm = reader->readSBits(this->Nbits);
        this->BlueAddTerm = reader->readSBits(this->Nbits);
    }
    reader->clearBits();
}
bool CCICxform::hasAlpha(){
    return false;
}
NS_CC_EXT_END