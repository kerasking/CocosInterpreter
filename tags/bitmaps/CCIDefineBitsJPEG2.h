//
//  CCIDefineBitsJPEG2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineBitsJPEG2__
#define __CocosInterpreterTest__CCIDefineBitsJPEG2__

#include "CCIDefineBits.h"

NS_CC_EXT_BEGIN

class CCIDefineBitsJPEG2 : public CCIDefineBits{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
protected:
    virtual void loadImageData(UI8* imageData);
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineBitsJPEG2__) */
