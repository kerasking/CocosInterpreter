//
//  CCICxform.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCICxform__
#define __CocosInterpreterTest__CCICxform__

#include "CCITypes.h"
#include "CCIBufferReader.h"
NS_CC_EXT_BEGIN
class CCICxform {
public:
    CCICxform(CCIBufferReader * reader);
    CCICxform();
    
    virtual bool hasAlpha();
public:
    bool HasAddTerms;
    bool HasMultTerms;
    UI8  Nbits;
    int  RedMultTerm;
    int  GreenMultTerm;
    int  BlueMultTerm;
    int  RedAddTerm;
    int  GreenAddTerm;
    int  BlueAddTerm;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCICxform__) */
