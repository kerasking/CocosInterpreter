//
//  CCIMovie.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterParser__CCIMovie__
#define __CocosInterpreterParser__CCIMovie__

#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
#include <iostream.h>
#include <vector.h>

#include "CCIMovieHeader.h"
#include "CCIFileAttributes.h"
#include "CCDictionary.h"
NS_CC_EXT_BEGIN



class CCIMovie : public CCObject{
public:
    static CCIMovie *decodeFromFile(std::string filename);
    std::vector<CCIMovieTag *> getTags();
    CCIMovieHeader * getHeader();
    CCDictionary * getFrameLabels();
    static void cleanup();
    
    virtual ~CCIMovie();
private:
    CCIMovieHeader * header;
    CCIFileAttributes * fileAttributes;
    std::vector<CCIMovieTag *> tags;
    
    CCDictionary * frameLabels;
    
};


NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIMovie__) */
