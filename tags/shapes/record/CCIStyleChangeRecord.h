//
//  CCIStyleChangeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCIStyleChangeRecord__
#define __CocosInterpreterTest__CCIStyleChangeRecord__

#include "CCIShapeRecord.h"
#include "CCIFillStyleArray.h"
#include "CCILineStyleArray.h"

NS_CC_EXT_BEGIN
class  CCIStyleChangeRecord:public CCIShapeRecord{
public:
    CCIStyleChangeRecord(CCIBufferReader* reader,UI8 numFillBits,UI8 numLineBits);
public:
    UI8 StateNewStyles;
    UI8 StateLineStyle;
    UI8 StateFillStyle1;
    UI8 StateFillStyle0;
    UI8 StateMoveTo;
    
    UI8 MoveBits;
    int MoveDeltaX;
    int MoveDeltaY;
    
    UI32 FillStyle0;
    UI32 FillStyle1;
    UI32 LineStyle;
    
    CCIFillStyleArray * FillStyles;
    CCILineStyleArray * LineStyles;
    
    UI8 NumFillBits;
    UI8 NumLineBits;
    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIStyleChangeRecord__) */
