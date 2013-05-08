//
//  CCIDefineShape4.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape4.h"
NS_CC_EXT_BEGIN
bool CCIDefineShape4::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIDefineShape3::initWithReader(reader, tagType, tagLength);
    
    return true;
}
NS_CC_EXT_END