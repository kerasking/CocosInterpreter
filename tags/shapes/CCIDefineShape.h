//
//  CCIDefineShape.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape__
#define __CocosInterpreterTest__CCIDefineShape__

#include "CCIMovieTag.h"
#include "CCIRect.h"
#include "CCIShapeWithStyle.h"
NS_CC_EXT_BEGIN
class CCIDefineShape : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    CCIShapeWithStyle * getShapes();
    int    getShapeId();
    CCIRect * getBounds();
    
    virtual ~CCIDefineShape();
private:
    UI16        shapeId;
    CCIRect*    shapeBounds;
    
    CCIShapeWithStyle * Shapes;
    
    
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineShape__) */
