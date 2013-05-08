//
//  CCIFocalGradient.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIFocalGradient__
#define __CocosInterpreterTest__CCIFocalGradient__

#include "CCIGradient.h"
NS_CC_EXT_BEGIN
class CCIFocalGradient :public CCIGradient {
public:
    CCIFocalGradient(CCIBufferReader * reader);
    
public:
    FIXED8  FocalPoint;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIFocalGradient__) */
