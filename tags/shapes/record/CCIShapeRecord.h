//
//  CCIShapeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCIShapeRecord__
#define __CocosInterpreterTest__CCIShapeRecord__

#include "CCIBufferReader.h"
#define ShapeTypeEnd 0
#define ShapeTypeStyle 1
#define ShapeTypeStraight 2
#define ShapeTypeCurved 3

NS_CC_EXT_BEGIN
class CCIShapeRecord {
public:
    CCIShapeRecord(CCIBufferReader * reader,UI8 NumFillBits,UI8 numLineBits);
public:
    UI8 TypeFlag;
    UI8 ShapeType;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIShapeRecord__) */
