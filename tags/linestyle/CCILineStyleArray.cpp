//
//  CCILineStyleArray.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCILineStyleArray.h"
#include "CCIMovieTag.h"
#include "CCILineStyle2.h"

NS_CC_EXT_BEGIN

CCILineStyleArray::CCILineStyleArray(CCIBufferReader * reader){
    this->LineStyleCount = reader->readUI8();
    this->styleCount = this->LineStyleCount;
    if (this->LineStyleCount==0xFF) {
        this->LineStyleCountExtended = reader->readUI16();
        this->styleCount = this->LineStyleCountExtended;
    }
    int tagType = reader->tagType;
    
    for (int i=0; i<this->styleCount; i++) {
        if (tagType==TagTypeDefineShape4) {
            CCILineStyle * lineStyle = new CCILineStyle2(reader);
            this->LineStyles.push_back(lineStyle);
        }else{
            CCILineStyle * lineStyle = new CCILineStyle(reader);
            this->LineStyles.push_back(lineStyle);
        }
        
    }
}
CCILineStyleArray::~CCILineStyleArray(){
    for (int i=0; i<this->LineStyles.size(); i++) {
        CCILineStyle * lineStyle = LineStyles[i];
        delete lineStyle;
    }
    LineStyles.clear();
}
NS_CC_EXT_END