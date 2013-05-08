//
//  CCIClipEventFlags.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIClipEventFlags.h"
NS_CC_EXT_BEGIN
CCIClipEventFlags::CCIClipEventFlags(CCIBufferReader *reader){
    
    
    this->ClipEventKeyUp = reader->readUBits(1)?1:0;
    this->ClipEventKeyDown = reader->readUBits(1)?1:0;
    this->ClipEventMouseUp = reader->readUBits(1)?1:0;
    this->ClipEventMouseDown = reader->readUBits(1)?1:0;
    this->ClipEventMouseMove = reader->readUBits(1)?1:0;
    this->ClipEventUnload = reader->readUBits(1)?1:0;
    this->ClipEventEnterFrame = reader->readUBits(1)?1:0;
    this->ClipEventLoad = reader->readUBits(1)?1:0;
    this->ClipEventDragOver = reader->readUBits(1)?1:0;
    this->ClipEventRollOut = reader->readUBits(1)?1:0;
    this->ClipEventRollOver = reader->readUBits(1)?1:0;
    this->ClipEventReleaseOutside = reader->readUBits(1)?1:0;
    this->ClipEventRelease = reader->readUBits(1)?1:0;
    this->ClipEventPress = reader->readUBits(1)?1:0;
    this->ClipEventInitialize = reader->readUBits(1)?1:0;
    this->ClipEventData = reader->readUBits(1)?1:0;
    
    if (reader->version>=6) {
        this->Reserved1 = reader->readUBits(5);
        this->ClipEventConstruct = reader->readUBits(1)?1:0;
        this->ClipEventKeyPress = reader->readUBits(1)?1:0;
        this->ClipEventDragOut = reader->readUBits(1)?1:0;
        this->Reserved2 = reader->readUBits(8);
    }
    
    

}
NS_CC_EXT_END