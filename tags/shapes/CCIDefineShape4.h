//
//  CCIDefineShape4.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape4__
#define __CocosInterpreterTest__CCIDefineShape4__

#include "ExtensionMacros.h"
#include "CCIDefineShape3.h"
NS_CC_EXT_BEGIN
class CCIDefineShape4 :public CCIDefineShape3{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
public:
    
};
NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIDefineShape4__) */
