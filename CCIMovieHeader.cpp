//
//  CCIMovieHeader.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIMovieHeader.h"
NS_CC_EXT_BEGIN

CCIMovieHeader * CCIMovieHeader::create(cocos2d::extension::CCIBufferReader *reader){
    CCIMovieHeader * header = new CCIMovieHeader();
    header->signature1 = reader->readUI8();
    header->signature2 = reader->readUI8();
    header->signature3 = reader->readUI8();
    
    header->version = reader->readUI8();
    
    header->fileLength = reader->readUI32();
    
    
    header->rect = new CCIRect(reader);
    
    
    reader->clearBits();

    
    header->frameRate = reader->readUI16();
    header->frameCount = reader->readUI16();
    
    return header;
}

CCIMovieHeader::CCIMovieHeader(){
    
}
int CCIMovieHeader::getVersion(){
    return this->version;
}
float CCIMovieHeader::getFrameRate(){
    return this->frameRate/256.0;
}
int CCIMovieHeader::getFrameCount(){
    return this->frameCount;
}
CCIRect * CCIMovieHeader::getBounds(){
    return rect;
}
CCIMovieHeader::~CCIMovieHeader(){
    delete rect;
}
NS_CC_EXT_END