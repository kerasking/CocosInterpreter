//
//  CCIFileAttributes.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIFileAttributes.h"
NS_CC_EXT_BEGIN
bool CCIFileAttributes::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->useDirectBlit = reader->readUBits(1)==1;
    
    reader->readUBits(1);
    
    this->useGPU = reader->readUBits(1)==1;
    this->hasMetadata = reader->readUBits(1)==1;
    this->actionScript3 = reader->readUBits(1)==1;
    
    reader->readUBits(2);
    
    this->useNetwork = reader->readUBits(1)==1;
    //剩下跳过
    reader->skipBytes(tagLength-1);
    return true;
}

NS_CC_EXT_END
