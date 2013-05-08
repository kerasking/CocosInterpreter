//
//  CCIFrameLabel.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIFrameLabel.h"
NS_CC_EXT_BEGIN
bool CCIFrameLabel::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->name = reader->readString();
    
    return true;
}
std::string CCIFrameLabel::getName(){
    return this->name;
}
NS_CC_EXT_END