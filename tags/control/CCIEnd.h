//
//  CCIEnd.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIEnd__
#define __SwfTest__CCIEnd__
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN
class CCIEnd :public CCIMovieTag {
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
public:
    
};

NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIEnd__) */
