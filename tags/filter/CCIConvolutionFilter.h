//
//  CCIConvolutionFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#ifndef __SwfTest__CCIConvolutionFilter__
#define __SwfTest__CCIConvolutionFilter__
#include "CCIFilter.h"
#include "CCIRGBA.h"

NS_CC_EXT_BEGIN
class CCIConvolutionFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
    virtual ~CCIConvolutionFilter();
public:
    UI8 MatrixX;
    UI8 MatrixY;
    FLOAT Divisor;
    FLOAT Bias;
    FLOAT * Matrix;
    CCIRGBA * DefaultColor;
    UI8 Reserved;
    UI8 Clamp;
    UI8 PreserveAlpha;
};
NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIConvolutionFilter__) */
