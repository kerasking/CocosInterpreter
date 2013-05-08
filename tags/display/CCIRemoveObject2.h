//
//  CCIRemoveObject2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIRemoveObject2__
#define __CocosInterpreterTest__CCIRemoveObject2__
#include "ExtensionMacros.h"
#include "CCIRemoveObject.h"
NS_CC_EXT_BEGIN

class CCIRemoveObject2 : public CCIRemoveObject{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);

};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIRemoveObject2__) */
