//
//  CCIFillStyle.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIFillStyle__
#define __CocosInterpreterTest__CCIFillStyle__
#include "CCIBufferReader.h"
#include "CCTypes.h"
#include "CCIMatrix.h"
#include "CCIFocalGradient.h"

NS_CC_EXT_BEGIN
class CCIFillStyle{
public:
    CCIFillStyle(CCIBufferReader * reader);
    virtual ~CCIFillStyle();
public:
    UI8 FillStyleType;
    ccColor4B Color;
    CCIMatrix * GradientMatrix = NULL;
    
    
    UI16 BitmapId;
    CCIMatrix * BitmapMatrix = NULL;
    
    CCIGradient * Gradient = NULL;
};
NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCIFillStyle__) */
