//
//  CCIJPEGTables.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIJPEGTables__
#define __CocosInterpreterTest__CCIJPEGTables__

#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN

class CCIJPEGTables : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    virtual ~CCIJPEGTables();
private:
    UI8 * JPEGData;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIJPEGTables__) */
