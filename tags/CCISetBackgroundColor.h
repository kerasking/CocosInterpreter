//
//  CCISetBackgroundColor.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCISetBackgroundColor__
#define __CocosInterpreterTest__CCISetBackgroundColor__

#include "CCITypes.h"
#include "CCIMovieTag.h"
#include "ccTypes.h"
NS_CC_EXT_BEGIN

class CCISetBackgroundColor : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
private:
    ccColor4B backgroundColor;
    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCISetBackgroundColor__) */
