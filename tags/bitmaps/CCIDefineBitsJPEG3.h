//
//  CCIDefineBitsJPEG3.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineBitsJPEG3__
#define __CocosInterpreterTest__CCIDefineBitsJPEG3__

#include "CCIDefineBitsJPEG2.h"

NS_CC_EXT_BEGIN

class CCIDefineBitsJPEG3 : public CCIDefineBitsJPEG2{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
protected:
    virtual void loadImageData(UI8* imageData);
    
protected:
    UI32 alphaDataOffset;
    UI8 * imageData;
    UI8 * bitmapAlphaData;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineBitsJPEG3__) */
