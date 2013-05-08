//
//  CCIClipActions.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIClipActions__
#define __CocosInterpreterTest__CCIClipActions__

#include "CCIBufferReader.h"
#include "CCIClipEventFlags.h"
NS_CC_EXT_BEGIN
class CCIClipActions {
public:
    CCIClipActions(CCIBufferReader * reader);
    virtual ~CCIClipActions();
public:
    UI16 Reserved;
    CCIClipEventFlags * AllEventFlags;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIClipActions__) */
