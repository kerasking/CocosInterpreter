//
//  CCIRGBA.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIRGBA__
#define __CocosInterpreterTest__CCIRGBA__

#include "CCIRGB.h"

NS_CC_EXT_BEGIN

class CCIRGBA :public CCIRGB{
public:
    CCIRGBA(CCIBufferReader * reader);
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIRGBA__) */
