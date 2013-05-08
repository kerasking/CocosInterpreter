//
//  CCIPlaceObject2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIPlaceObject2.h"
#include "CCICxformWithAlpha.h"
NS_CC_EXT_BEGIN

bool CCIPlaceObject2::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->placeFlagHasClipActions = reader->readUBits(1);
    this->placeFlagHasClipDepth  =  reader->readUBits(1);
    this->placeFlagHasName = reader->readUBits(1);
    this->placeFlagHasRatio = reader->readUBits(1);
    this->placeFlagHasColorTransform = reader->readUBits(1);
    this->placeFlagHasMatrix = reader->readUBits(1);
    this->placeFlagHasCharacter = reader->readUBits(1);
    this->placeFlagMove = reader->readUBits(1);
    reader->clearBits();
    
    
    if (!this->placeFlagHasCharacter) {
        placeType = PlaceObjectTypeModify;
    }else if(this->placeFlagMove){
        placeType = PlaceObjectTypeReplace;
    }else{
        placeType = PlaceObjectTypeNew;
    }
    
    
    this->depth = reader->readUI16();
    if (this->placeFlagHasCharacter) {
        this->characterId =  reader->readUI16();
    }else{
        this->characterId = 0;
    }
    
    if (this->placeFlagHasMatrix) {
        this->matrix = new CCIMatrix(reader);
    }
    
    if (this->placeFlagHasColorTransform) {
        this->colorTransform = new CCICxformWithAlpha(reader);
    }
    
    if (this->placeFlagHasRatio) {
        this->ratio = reader->readUI16();
    }else{
        this->ratio = 0;
    }
    
    if (this->placeFlagHasName) {
        this->name = reader->readString();
    }
    if (this->placeFlagHasClipDepth) {
        this->clipDepth = reader->readUI16();
    }else{
        this->clipDepth = 0;
    }
    if (this->placeFlagHasClipActions) {
        //TODO
        //this->clipActions = new CCIClipActions(reader);
    }else{
        this->clipActions = NULL;
    }

    return true;
}
CCIPlaceObject2::~CCIPlaceObject2(){
    if (this->clipActions) {
        delete this->clipActions;
    }
    
}

NS_CC_EXT_END