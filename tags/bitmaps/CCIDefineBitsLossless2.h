//
//  CCIDefineBitsLossless2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreter__CCIDefineBitsLossless2__
#define __CocosInterpreter__CCIDefineBitsLossless2__

#include "CCIDefineBitsLossless.h"

NS_CC_EXT_BEGIN

class CCIDefineBitsLossless2 : public CCIDefineBitsLossless{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
protected:
    virtual void loadImageData(UI8 * imageData);
    
private:
    void loadRGBA(UI8 * imageData);
    void loadIDXA(UI8 * imageData);
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineBitsLossless2__) */
