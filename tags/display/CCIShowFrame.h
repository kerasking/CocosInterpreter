//
//  CCIShowFrame.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIShowFrame__
#define __CocosInterpreterTest__CCIShowFrame__

#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN

class CCIShowFrame : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);

};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIShowFrame__) */
