//
//  CCIGradRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIGradRecord__
#define __CocosInterpreterTest__CCIGradRecord__

#include "ExtensionMacros.h"
#include "CCIBufferReader.h"
#include "CCIRGBA.h"

NS_CC_EXT_BEGIN
class CCIGradRecord {
public:
    CCIGradRecord(CCIBufferReader * reader);
public:
    UI8 Ratio;
    ccColor4B Color;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIGradRecord__) */
