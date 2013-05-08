//
//  CCILineStyle2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCILineStyle2__
#define __CocosInterpreterTest__CCILineStyle2__

#include "CCIBufferReader.h"
#include "ccTypes.h"
#include "CCIFillStyle.h"
#include "CCILineStyle.h"
NS_CC_EXT_BEGIN
class CCILineStyle2 :public CCILineStyle{
public:
    CCILineStyle2(CCIBufferReader * reader);
    virtual ~CCILineStyle2();
public:
    UI16    Width;
    UI8     StartCapStyle;
    UI8     JoinStyle;
    UI8     HasFillFlag;
    UI8     NoHScaleFlag;
    UI8     NoVScaleFlag;
    UI8     PixelHintingFlag;
    UI8     Reserved;
    UI8     NoClose;
    UI8     EndCapStyle;
    UI16    MiterLimitFactor;
    
    
    ccColor4B Color;
    CCIFillStyle * FillType;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCILineStyle2__) */
