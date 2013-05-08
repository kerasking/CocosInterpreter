//
//  CCIRemoveObject.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIRemoveObject.h"
NS_CC_EXT_BEGIN

bool CCIRemoveObject::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    this->characterId = reader->readUI16();
    this->depth         = reader->readUI16();
    
    return true;
}
UI16 CCIRemoveObject::getDepth(){
    return this->depth;
}
NS_CC_EXT_END