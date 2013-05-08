//
//  CCIClipEventFlags.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIClipEventFlags__
#define __CocosInterpreterTest__CCIClipEventFlags__

#include "CCIBufferReader.h"
NS_CC_EXT_BEGIN
class CCIClipEventFlags{
public:
    CCIClipEventFlags(CCIBufferReader * reader);
    
public:
    UI8  ClipEventKeyUp;
    UI8  ClipEventKeyDown;
    UI8  ClipEventMouseUp;
    UI8  ClipEventMouseDown;
    UI8  ClipEventMouseMove;
    UI8  ClipEventUnload;
    UI8  ClipEventEnterFrame;
    UI8  ClipEventLoad;
    UI8  ClipEventDragOver;
    UI8  ClipEventRollOut;
    UI8  ClipEventRollOver;
    UI8  ClipEventReleaseOutside;
    UI8  ClipEventRelease;
    UI8  ClipEventPress;
    UI8  ClipEventInitialize;
    UI8  ClipEventData;
    
    UI16 Reserved1;
    UI8  ClipEventConstruct;
    
    UI8  ClipEventKeyPress;
    UI8  ClipEventDragOut;
    UI16 Reserved2;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIClipEventFlags__) */
