//
//  CCIRemoveObject.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIRemoveObject__
#define __CocosInterpreterTest__CCIRemoveObject__
#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN

class CCIRemoveObject : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    UI16    getDepth();
protected:
    UI16    characterId;
    UI16    depth;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIRemoveObject__) */
