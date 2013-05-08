//
//  CCIRGB.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIRGB__
#define __CocosInterpreterTest__CCIRGB__

#include "CCIBufferReader.h"
#include "ExtensionMacros.h"
#include "ccTypes.h"
NS_CC_EXT_BEGIN

class CCIRGB {
public:
    CCIRGB(CCIBufferReader * reader);
    ccColor4B getColor();
public:
    UI8 Red;
    UI8 Green;
    UI8 Blue;
    UI8 Alpha;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIRGB__) */
