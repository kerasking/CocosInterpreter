//
//  CCIMatrix.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIMatrix__
#define __CocosInterpreterTest__CCIMatrix__
#include "CCITypes.h"
#include "CCIBufferReader.h"
#include "ccTypes.h"
#include "CCAffineTransform.h"
NS_CC_EXT_BEGIN
class CCIMatrix {
private:
    float a;
    float b;
    float c;
    float d;
    int   tx;
    int   ty;
    CCPoint deltaTransformPoint(CCPoint p);
public:
    CCIMatrix(CCIBufferReader * reader);
    float getScaleX();
    float getScaleY();
    
    float getSkewX();
    float getSkewY();
    float getRotation();
    int getTranslateX();
    int getTranslateY();
public:    
    bool HasScale;
    UI32 NScaleBits;
    float ScaleX = 65536.0;
    float ScaleY = 65536.0;
    bool HasRotate;
    UI32 NRotateBits;
    float RotateSkew0 = 0;
    float RotateSkew1 = 0;
    UI32 NTranslateBits;
    int  TranslateX = 0;
    int  TranslateY = 0;
    CCAffineTransform getTransform();
};
NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCIMatrix__) */
