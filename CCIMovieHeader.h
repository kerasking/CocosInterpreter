//
//  CCIMovieHeader.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCIMovieHeader__
#define __CocosInterpreterTest__CCIMovieHeader__

#include "ExtensionMacros.h"
#include <stdint.h>
#include "CCIBufferReader.h"
#include "CCITypes.h"
#include "CCIRect.h"
NS_CC_EXT_BEGIN


class CCIMovieHeader{
public:
    static CCIMovieHeader * create(CCIBufferReader * reader);
    int getVersion();
    float getFrameRate();
    int getFrameCount();
    
    int getWidth();
    int getHeight();
    CCIRect * getBounds();
    
    virtual ~CCIMovieHeader();
private:
    CCIMovieHeader();
    UI8 signature1;
    UI8 signature2;
    UI8 signature3;
    UI8 version;
    UI32 fileLength;

    float frameRate;
    UI16 frameCount;

    CCIRect * rect;
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIMovieHeader__) */
