//
//  CCIGradient.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIGradient__
#define __CocosInterpreterTest__CCIGradient__
#include "CCIBufferReader.h"
#include "CCIGradRecord.h"
NS_CC_EXT_BEGIN

class CCIGradient {
public:
    CCIGradient(CCIBufferReader * reader);
    virtual ~CCIGradient();
public:
    UI8     SpreadMode;
    UI8     InterpolationMode;
    UI8     NumGradients;
    std::vector<CCIGradRecord *>    GradientRecords;
};

NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCIGradient__) */
