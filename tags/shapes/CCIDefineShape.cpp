//
//  CCIDefineShape.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape.h"
NS_CC_EXT_BEGIN
bool CCIDefineShape::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    this->shapeId = reader->readUI16();
    this->shapeBounds = new CCIRect(reader);
    
    this->Shapes = new CCIShapeWithStyle(reader);
    
    return true;
}
CCIShapeWithStyle * CCIDefineShape::getShapes(){
    return this->Shapes;
}
int CCIDefineShape::getShapeId(){
    return this->shapeId;
}
CCIRect * CCIDefineShape::getBounds(){
    return this->shapeBounds;
}
CCIDefineShape::~CCIDefineShape(){
    delete this->shapeBounds;
    delete this->Shapes;
}
NS_CC_EXT_END