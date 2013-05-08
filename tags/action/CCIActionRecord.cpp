//
//  CCIActionRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIActionRecord.h"
NS_CC_EXT_BEGIN

CCIActionRecord::CCIActionRecord(CCIBufferReader *reader){
    this->ActionCode = reader->readUI8();
    if (this->ActionCode > 0x80) {
        this->Length = reader->readUI16();
    }
}
NS_CC_EXT_END