//
//  CCIBlurFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#ifndef __SwfTest__CCIBlurFilter__
#define __SwfTest__CCIBlurFilter__

#include "CCIFilter.h"
NS_CC_EXT_BEGIN
class CCIBlurFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
public:
    FIXED BlurX;
    FIXED BlurY;
    
    UI8 Passes;
    UI8 Reserved;
};
NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIBlurFilter__) */
