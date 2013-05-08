//
//  CCIDoAction.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIDoAction__
#define __SwfTest__CCIDoAction__
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN
class CCIDoAction :public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
private:
    
    UI8 actionEndFlag;
};
NS_CC_EXT_END
#endif /* defined(__SwfTest__CCIDoAction__) */
