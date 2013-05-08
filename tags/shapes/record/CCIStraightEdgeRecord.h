//
//  CCIStraightEdgeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCIStraightEdgeRecord__
#define __CocosInterpreterTest__CCIStraightEdgeRecord__

#include "CCIShapeRecord.h"
NS_CC_EXT_BEGIN
class  CCIStraightEdgeRecord:public CCIShapeRecord{
public:
    CCIStraightEdgeRecord(CCIBufferReader* reader,UI8 numFillBits,UI8 numLineBits);
public:
    UI8 StraightFlag;
    UI8 NumBits;
    UI8 GeneralLineFlag;
    int DeltaX;
    int DeltaY;
    int VertLineFlag;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIStraightEdgeRecord__) */
