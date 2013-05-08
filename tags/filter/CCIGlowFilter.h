//
//  CCIGlowFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#ifndef __SwfTest__CCIGlowFilter__
#define __SwfTest__CCIGlowFilter__

#include "CCIFilter.h"
#include "CCIRGBA.h"

NS_CC_EXT_BEGIN
class CCIGlowFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
    virtual ~CCIGlowFilter();
public:
    CCIRGBA * GlowColor;
    
    FIXED BlurX;
    FIXED BlurY;
    
    FIXED8 Strength;
    
    UI8 InnerGlow;
    UI8 Knockout;
    UI8 CompositeSource;
    UI8 Passes;
};
NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIGlowFilter__) */
