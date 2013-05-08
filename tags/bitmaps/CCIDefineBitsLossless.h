//
//  CCIDefineBitsLossless.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreter__CCIDefineBitsLossless__
#define __CocosInterpreter__CCIDefineBitsLossless__

#include "CCIImageTag.h"

NS_CC_EXT_BEGIN

class CCIDefineBitsLossless : public CCIImageTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);

protected:
    
    
    //Format of compressed data
    //3 = 8-bit colormapped image
    //5 = 32-bit ARGB image
    UI8     bitmapFormat;
    
    //If BitmapFormat = 3, UI8; Otherwise absent
    UI8     bitmapColorTableSize;
    
    virtual void loadImageData(UI8* imageData);
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineBitsLossless__) */
