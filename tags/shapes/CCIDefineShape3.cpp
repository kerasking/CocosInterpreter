//
//  CCIDefineShape3.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape3.h"
NS_CC_EXT_BEGIN

bool CCIDefineShape3::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIDefineShape2::initWithReader(reader, tagType, tagLength);
    
    return true;
}

NS_CC_EXT_END