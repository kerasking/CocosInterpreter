//
//  CCIGradRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIGradRecord.h"
#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN
CCIGradRecord::CCIGradRecord(CCIBufferReader * reader){
    this->Ratio = reader->readUI8();
    CCIRGB * rgb;
    if (reader->tagType == TagTypeDefineShape||reader->tagType == TagTypeDefineShape2) {
        rgb = new CCIRGB(reader);
    }else{
        rgb = new CCIRGBA(reader);
    }
    this->Color = rgb->getColor();
    delete rgb;

}
NS_CC_EXT_END