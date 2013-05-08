//
//  CCIFillStyleArray.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIFillStyleArray.h"
#include "CCIMovieTag.h"
NS_CC_EXT_BEGIN

CCIFillStyleArray::CCIFillStyleArray(CCIBufferReader * reader){
    this->FillStyleCount = reader->readUI8();
    this->styleCount = this->FillStyleCount;
    
    int tagType = reader->tagType;
    
    if (tagType!=TagTypeDefineShape&&this->FillStyleCount==0xFF) {
        this->FillStyleCountExtended = reader->readUI16();
        this->styleCount = this->FillStyleCountExtended;
    }
    for (int i=0; i<this->styleCount; i++) {
        CCIFillStyle * fillStyle = new CCIFillStyle(reader);
        this->FillStyles.push_back(fillStyle);
    }
}
CCIFillStyleArray::~CCIFillStyleArray(){
    for (int i=0; i<this->FillStyles.size(); i++) {
        CCIFillStyle * fillStyle = FillStyles[i];
        delete fillStyle;
    }
    FillStyles.clear();
}
NS_CC_EXT_END