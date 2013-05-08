//
//  CCIDefineBitsJPEG4.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineBitsJPEG4__
#define __CocosInterpreterTest__CCIDefineBitsJPEG4__

#include "CCIDefineBitsJPEG3.h"

NS_CC_EXT_BEGIN

class CCIDefineBitsJPEG4 : public CCIDefineBitsJPEG3{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
protected:
    virtual void loadImageData(UI8* imageData);
    
    UI16 deblockParam;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineBitsJPEG4__) */
