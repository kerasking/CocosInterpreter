//
//  CCICxformWithAlpha.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-12.
//
//

#ifndef __CocosInterpreterTest__CCICxformWithAlpha__
#define __CocosInterpreterTest__CCICxformWithAlpha__

#include "CCICxform.h"
NS_CC_EXT_BEGIN
class CCICxformWithAlpha :public CCICxform{
public:
    CCICxformWithAlpha(CCIBufferReader * reader);
    virtual bool hasAlpha();
public:
    int  AlphaMultTerm;
    int  AlphaAddTerm;
    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCICxformWithAlpha__) */
