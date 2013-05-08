//
//  CCIRect.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIRect.h"

NS_CC_EXT_BEGIN

CCIRect::CCIRect(CCIBufferReader * reader){
    reader->clearBits();
    UI32 nbits = reader->readUBits(5);
    this->Nbits = nbits;
    this->Xmin = reader->readSBits(nbits)/20.0;
    this->Xmax = reader->readSBits(nbits)/20.0;
    this->Ymin = reader->readSBits(nbits)/20.0;
    this->Ymax = reader->readSBits(nbits)/20.0;
    
    this->width = this->Xmax-this->Xmin;
    this->height = this->Ymax-this->Ymin;
    
    reader->clearBits();
}
int CCIRect::getHeight(){
    return height;
}
int CCIRect::getWidth(){
    return width;
}
CCSize CCIRect::getSize(){
    return CCSizeMake(width, height);

}
CCPoint CCIRect::getAnchorPoint(){
    return CCPointMake(-this->Xmin/(float)width, this->Ymax/(float)height);
}
CCPoint CCIRect::convertToCCSpace(int x,int y){
    int ccx = x - this->Xmin;
    int ccy = y - this->Ymax;
    return CCPointMake(ccx, -ccy);
}
NS_CC_EXT_END