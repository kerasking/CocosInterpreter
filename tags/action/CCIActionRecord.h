//
//  CCIActionRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIActionRecord__
#define __CocosInterpreterTest__CCIActionRecord__

#include "CCIBufferReader.h"
NS_CC_EXT_BEGIN
class CCIActionRecord{
public:
    CCIActionRecord(CCIBufferReader * reader);
    
public:
    UI8                 ActionCode;
    UI16                Length;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIActionRecord__) */
