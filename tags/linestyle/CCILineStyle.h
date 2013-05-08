//
//  CCILineStyle.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCILineStyle__
#define __CocosInterpreterTest__CCILineStyle__

#include "CCIBufferReader.h"
#include "ccTypes.h"

NS_CC_EXT_BEGIN
class CCILineStyle {
public:
    CCILineStyle(CCIBufferReader * reader);
    CCILineStyle();
public:
    UI16    Width;
    ccColor4B Color;
};
NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCILineStyle__) */
