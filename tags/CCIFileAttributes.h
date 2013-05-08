//
//  CCIFileAttributes.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCIFileAttributes__
#define __CocosInterpreterTest__CCIFileAttributes__

#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN

class CCIFileAttributes : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
private:
    //If 1, the SWF file uses hardware acceleration to blit graphics to the screen, where such acceleration is available. If 0, the SWF file will not use hardware accelerated graphics facilities. Minimum file version is 10.
    bool useDirectBlit;
    bool useGPU;
    bool hasMetadata;
    bool actionScript3;
    bool useNetwork;
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIFileAttributes__) */
