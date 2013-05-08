//
//  CCIMovieTag.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIMovieTag.h"
#include "CCIFileAttributes.h"
#include "CCISetBackgroundColor.h"
#include "CCIFrameLabel.h"


#include "CCIDefineBitsLossless.h"
#include "CCIDefineBitsLossless2.h"
#include "CCIDefineBits.h"
#include "CCIDefineBitsJPEG2.h"
#include "CCIDefineBitsJPEG3.h"
#include "CCIDefineBitsJPEG4.h"

#include "CCIJPEGTables.h"

#include "CCIPlaceObject.h"
#include "CCIPlaceObject2.h"
#include "CCIPlaceObject3.h"
#include "CCIRemoveObject.h"
#include "CCIRemoveObject2.h"
#include "CCIShowFrame.h"


#include "CCIDefineShape.h"
#include "CCIDefineShape2.h"
#include "CCIDefineShape3.h"
#include "CCIDefineShape4.h"

#include "CCIDefineSprite.h"

#include "CCIEnd.h"

#include "CCPlatformMacros.h"
#include "CCCommon.h"
NS_CC_EXT_BEGIN

bool CCIMovieTag::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    this->tagType = tagType;
    this->tagLength = tagLength;
    return true;
}

CCIMovieTag * CCIMovieTag::next(CCIBufferReader *reader)
{
    UI16 tagCodeAndLength = reader->readUI16();
    if (reader->mReachEnd) {
        return NULL;
    }
    int tagType = tagCodeAndLength>>6;
    int tagLength = (tagType<<6)^tagCodeAndLength;
    if (tagLength==63) {
        tagLength = reader->readUI32();
    }
    CCIMovieTag * tag = NULL;
    std::string logString;
    switch (tagType) {
        case TagTypeFileAtrributes:
            tag = new CCIFileAttributes();
            logString = "CCIFileAttributes";
            break;
        case TagTypeSetBackgroundColor:
            tag = new CCISetBackgroundColor();
            logString = "CCISetBackgroundColor";
            break;
        case TagTypeEnd:
            tag = new CCIEnd();
            logString = "CCIEnd";
            break;
        case TagTypeFrameLabel:
            tag = new CCIFrameLabel();
            logString = "CCIFrameLabel";
            break;
        case TagTypeDefineBitsLossless:
            tag = new CCIDefineBitsLossless();
            logString = "CCIDefineBitsLossless";
            break;
        case TagTypeDefineBitsLossless2:
            tag = new CCIDefineBitsLossless2();
            logString = "CCIDefineBitsLossless2";
            break;
        case TagTypeDefineBits:
            tag = new CCIDefineBits();
            logString = "CCIDefineBits";
            break;
        case TagTypeDefineBitsJPEG2:
            tag = new CCIDefineBitsJPEG2();
            logString = "CCIDefineBitsJPEG2";
            break;
        case TagTypeDefineBitsJPEG3:
            tag = new CCIDefineBitsJPEG3();
            logString = "CCIDefineBitsJPEG3";
            break;
        case TagTypeDefineBitsJPEG4:
            tag = new CCIDefineBitsJPEG4();
            logString = "CCIDefineBitsJPEG4";
            break;
        case TagTypeJPEGTables:
            tag = new CCIJPEGTables();
            logString = "CCIJPEGTables";
            break;
         
        case TagTypePlaceObject:
            tag = new CCIPlaceObject();
            logString = "CCIPlaceObject";
            break;
        case TagTypePlaceObject2:
            tag = new CCIPlaceObject2();
            logString = "CCIPlaceObject2";
            break;
        case TagTypePlaceObject3:
            tag = new CCIPlaceObject3();
            logString = "CCIPlaceObject3";
            break;
        case TagTypeRemoveObject:
            tag = new CCIRemoveObject();
            logString = "CCIRemoveObject";
            break;
        case TagTypeRemoveObject2:
            tag = new CCIRemoveObject2();
            logString = "CCIRemoveObject2";
            break;
        case TagTypeShowFrame:
            tag = new CCIShowFrame();
            logString = "CCIShowFrame";
            break;
            
        case TagTypeDefineShape:
            tag = new CCIDefineShape();
            logString = "CCIDefineShape";
            break;
        case TagTypeDefineShape2:
            tag = new CCIDefineShape2();
            logString = "CCIDefineShape2";
            break;
        case TagTypeDefineShape3:
            tag = new CCIDefineShape3();
            logString = "CCIDefineShape3";
            break;
        case TagTypeDefineShape4:
            tag = new CCIDefineShape4();
            logString = "CCIDefineShape4";
            break;
        case TagTypeDefineSprite:
            tag = new CCIDefineSprite();
            logString = "CCIDefineSprite";
            break;
        default:
            tag = new CCIMovieTag();
            logString = "unknow tag ****************";
            CCLog("unknow tag %d",tagType);
            //skip if do not understand
            
            break;
    }
    
    CCLog(logString.c_str());
    
    reader->begin(tagLength);
    reader->tagType = tagType;
    if (tag&&tag->initWithReader(reader, tagType, tagLength)) {
        reader->flush();
        return tag;
    }
    
    reader->flush();
    return NULL;
}
int CCIMovieTag::getTagType(){
    return this->tagType;
}
CCIMovieTag::~CCIMovieTag(){
}
NS_CC_EXT_END