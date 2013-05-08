//
//  CCIRemoveObject2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIRemoveObject2.h"
NS_CC_EXT_BEGIN

bool CCIRemoveObject2::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    this->depth         = reader->readUI16();
    
    return true;
}

NS_CC_EXT_END