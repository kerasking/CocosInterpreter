//
//  CCIDefineShape3.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape3__
#define __CocosInterpreterTest__CCIDefineShape3__

#include "ExtensionMacros.h"
#include "CCIDefineShape2.h"
NS_CC_EXT_BEGIN
class CCIDefineShape3 : public CCIDefineShape2{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
public:
    
};
NS_CC_EXT_END
#endif /* defined(__CocosInterpreterTest__CCIDefineShape3__) */
