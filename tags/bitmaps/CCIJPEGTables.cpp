//
//  CCIJPEGTables.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIJPEGTables.h"
NS_CC_EXT_BEGIN
bool CCIJPEGTables::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->JPEGData = reader->readBytes(tagLength);
    return true;
}
CCIJPEGTables::~CCIJPEGTables(){
    delete JPEGData;
}
NS_CC_EXT_END