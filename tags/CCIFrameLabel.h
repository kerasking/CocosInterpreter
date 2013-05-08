//
//  CCIFrameLabel.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCIFrameLabel__
#define __CocosInterpreterTest__CCIFrameLabel__

#include "CCITypes.h"
#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN

class CCIFrameLabel : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    std::string getName();
private:
    std::string name;
    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreter__CCIFrameLabel__) */
