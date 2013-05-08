//
//  CCICurvedEdgeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCICurvedEdgeRecord__
#define __CocosInterpreterTest__CCICurvedEdgeRecord__

#include "CCIShapeRecord.h"
NS_CC_EXT_BEGIN
class  CCICurvedEdgeRecord:public CCIShapeRecord{
public:
    CCICurvedEdgeRecord(CCIBufferReader* reader,UI8 numFillBits,UI8 numLineBits);
public:
    UI8 StraightFlag;
    UI8 NumBits;
    int ControlDeltaX;
    int ControlDeltaY;
    int AnchorDeltaX;
    int AnchorDeltaY;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCICurvedEdgeRecord__) */
