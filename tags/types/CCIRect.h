//
//  CCIRect.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIRect__
#define __CocosInterpreterTest__CCIRect__

#include "CCIBufferReader.h"
#include "ccTypes.h"
NS_CC_EXT_BEGIN
class CCIRect{
public:
    CCIRect(CCIBufferReader * reader);
    
    int getWidth();
    int getHeight();
    
    CCSize getSize();
    CCPoint getAnchorPoint();
    
    CCPoint convertToCCSpace(int x,int y);
public:
    UI32 Nbits;
    int Xmin;
    int Xmax;
    int Ymin;
    int Ymax;
private:
    int width;
    int height;
};
NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCIRect__) */
