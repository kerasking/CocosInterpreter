//
//  CCIClipActions.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIClipActions.h"
NS_CC_EXT_BEGIN
CCIClipActions::CCIClipActions(CCIBufferReader *reader){
    this->Reserved = reader->readUI16();
    this->AllEventFlags = new CCIClipEventFlags(reader);
}
CCIClipActions::~CCIClipActions(){
    delete this->AllEventFlags;
}
NS_CC_EXT_END