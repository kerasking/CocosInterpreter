//
//  CCIClipActionRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIClipActionRecord__
#define __CocosInterpreterTest__CCIClipActionRecord__

#include "CCIBufferReader.h"
#include "CCIClipEventFlags.h"
#include "CCIActionRecord.h"
NS_CC_EXT_BEGIN
class CCIClipActionRecord{
public:
    CCIClipActionRecord(CCIBufferReader * reader);
    virtual ~CCIClipActionRecord();
public:
    CCIClipEventFlags * EventFlags;
    UI32                ActionRecordSize;
    UI8                 KeyCode;
    std::vector<CCIActionRecord *>    Actions;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIClipActionRecord__) */
