//
//  CCILineStyle.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCILineStyle.h"
#include "CCIRGBA.h"
#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN
CCILineStyle::CCILineStyle(){
    //do nothing
}
CCILineStyle::CCILineStyle(CCIBufferReader * reader){
    this->Width = reader->readUI16();
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