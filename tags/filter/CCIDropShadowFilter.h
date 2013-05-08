//
//  CCIDropShadowFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#ifndef __SwfTest__CCIDropShadowFilter__
#define __SwfTest__CCIDropShadowFilter__

#include "CCIFilter.h"
#include "CCIRGBA.h"

NS_CC_EXT_BEGIN
class CCIDropShadowFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
    virtual ~CCIDropShadowFilter();
public:
    CCIRGBA * DropShadowColor;
    
    FIXED BlurX;
    FIXED BlurY;
    FIXED Angle;
    FIXED Distance;
    FIXED8 Strength;
    
    UI8 InnerShadow;
    UI8 Knockout;
    UI8 CompositeSource;
    UI8 Passes;
};
NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIDropShadowFilter__) */
