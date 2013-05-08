//
//  CCIFillStyleArray.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIFillStyleArray__
#define __CocosInterpreterTest__CCIFillStyleArray__

#include "ExtensionMacros.h"
#include "CCIBufferReader.h"
#include "CCIFillStyle.h"
NS_CC_EXT_BEGIN
class CCIFillStyleArray {
public:
    CCIFillStyleArray(CCIBufferReader * reader);
    virtual ~CCIFillStyleArray();
    
public:
    int     styleCount;
    UI8     FillStyleCount;
    UI16    FillStyleCountExtended;
    std::vector<CCIFillStyle *> FillStyles;
    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIFillStyleArray__) */
