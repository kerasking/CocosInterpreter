//
//  CCIPlaceObject3.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIPlaceObject3.h"
#include "CCICxformWithAlpha.h"

NS_CC_EXT_BEGIN

bool CCIPlaceObject3::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    reader->clearBits();
    this->placeFlagHasClipActions = reader->readUBits(1);
    this->placeFlagHasClipDepth  =  reader->readUBits(1);
    this->placeFlagHasName = reader->readUBits(1);
    this->placeFlagHasRatio = reader->readUBits(1);
    this->placeFlagHasColorTransform = reader->readUBits(1);
    this->placeFlagHasMatrix = reader->readUBits(1);
    this->placeFlagHasCharacter = reader->readUBits(1);
    this->placeFlagMove = reader->readUBits(1);
    
    
    this->reserved = reader->readUBits(1);
    this->placeFlagOpaqueBackground = reader->readUBits(1);
    this->placeFlagHasVisible = reader->readUBits(1);
    this->placeFlagHasImage = reader->readUBits(1);
    this->placeFlagHasClassName = reader->readUBits(1);
    this->placeFlagHasCacheAsBitmap = reader->readUBits(1);
    this->placeFlagHasBlendMode = reader->readUBits(1);
    this->placeFlagHasFilterList = reader->readUBits(1);
    
    
    reader->clearBits();

    if (!this->placeFlagHasCharacter) {
        placeType = PlaceObjectTypeModify;
    }else if(this->placeFlagMove){
        placeType = PlaceObjectTypeReplace;
    }else{
        placeType = PlaceObjectTypeNew;
    }
    
    
    this->depth = reader->readUI16();
    
    if (this->placeFlagHasClassName||(this->placeFlagHasImage&&this->placeFlagHasCharacter)) {
        this->className = reader->readString();
    }
    
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
    
    if (this->placeFlagHasFilterList) {
        this->surfaceFilterList = new CCIFilterList(reader);
    }
    if (this->placeFlagHasBlendMode) {
        this->blendMode = reader->readUI8();
    }
    if (this->placeFlagHasCacheAsBitmap) {
        this->bitmapCache = reader->readUI8();
    }
    if (this->placeFlagHasVisible) {
        this->visible = reader->readUI8();
        backgroundColor = new CCIRGBA(reader);
    }
    
    if (this->placeFlagHasClipActions) {
        //TODO
        //this->clipActions = new CCIClipActions(reader);
    }else{
        this->clipActions = NULL;
    }
    
    return true;
}
CCIFilterList * CCIPlaceObject3::getFilterList(){
    if (this->placeFlagHasFilterList) {
        return this->surfaceFilterList;
    }
    return NULL;
}
CCIPlaceObject3::~CCIPlaceObject3(){
    if (this->placeFlagHasFilterList) {
        delete this->surfaceFilterList;
    }
    if (this->placeFlagHasVisible) {
        delete backgroundColor;
    }
    if (this->placeFlagHasColorTransform) {
        delete this->colorTransform;
    }
}
NS_CC_EXT_END