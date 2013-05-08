//
//  CCIBufferReader.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIBufferReader.h"

NS_CC_EXT_BEGIN
CCIBufferReader::CCIBufferReader()
{
    mDataBitSize = 0;
    mReadBitPos = 0;
    mWriteBitPos = 0;
    mLeftNbits = 0;
    mReachEnd = false;
    
}

CCIBufferReader::~CCIBufferReader()
{
}

void CCIBufferReader::setData(uint8_t* thePtr, int theCount)
{
    mData.clear();
    mData.reserve(theCount);
    mData.insert(mData.begin(), thePtr, thePtr + theCount);
    mDataBitSize = mData.size() * 8;
}

uint8_t* CCIBufferReader::getDataPtr()
{
    if (mData.size() == 0)
        return NULL;
    return &mData[0];
}

int CCIBufferReader::getDataLen() const
{
    return (mDataBitSize + 7) / 8; // Round up
}

void CCIBufferReader::clear()
{
    mReadBitPos = 0;
    mWriteBitPos = 0;
    mDataBitSize = 0;
    mData.clear();
}
UI8* CCIBufferReader::readBytes(UI32 byte) const{
    UI8* pData = new UI8[byte];
    
    for (int i=0; i<byte; i++) {
        pData[i] = this->readUI8();
    }
    return pData;
}
void  CCIBufferReader::skipBytes(UI32 byte) const{
    mReadBitPos += 8*byte;
    if (mTagPos>0) {
        mTagPos -=byte;
    }
}
UI8 CCIBufferReader::scanUI8() const
{
    if ((mReadBitPos + 7)/8 >= (int)mData.size())
    {
        return 0; // Underflow
    }
    
    if (mReadBitPos % 8 == 0)
    {
        UI8 b = mData[mReadBitPos/8];
        return b;
    }
    else
    {
        int anOfs = mReadBitPos % 8;
        
        UI8 b = 0;
        
        b = mData[mReadBitPos/8] >> anOfs;
        b |= mData[(mReadBitPos/8)+1] << (8 - anOfs);
        
        return b;
    }
}
//FIXME
UI8 CCIBufferReader::scanUBits(UI32 nbits){
    UI32 byte =0;
    if (this->mLeftNbits>0) {
        if (this->mLeftNbits>=nbits) {
            return this->mLeftByte>>(this->mLeftNbits-nbits);
        }else{
            byte = this->mLeftByte;
        }
    }
    int leftBits = nbits - this->mLeftNbits;
    byte <<=8;
    byte |=this->scanUI8();
    return byte>>(8-leftBits);
}
UI8 CCIBufferReader::readUI8() const
{
    if ((mReadBitPos + 7)/8 >= (int)mData.size())
    {
        mReachEnd = true;
        return 0; // Underflow
    }
    
    if (mReadBitPos % 8 == 0)
    {
        UI8 b = mData[mReadBitPos/8];
        mReadBitPos += 8;
        
        if (mTagPos>0) {
            mTagPos -=1;
        }
        
        return b;
    }
    else
    {
        int anOfs = mReadBitPos % 8;
        
        UI8 b = 0;
        
        b = mData[mReadBitPos/8] >> anOfs;
        b |= mData[(mReadBitPos/8)+1] << (8 - anOfs);
        
        mReadBitPos += 8;
        
        if (mTagPos>0) {
            mTagPos -=1;
        }
        
        
        return b;
    }
}


UI16 CCIBufferReader::readUI16() const
{
    UI16 ui16 = readUI8();
    ui16 |= ((UI16) readUI8() << 8);
    return ui16;
}

UI32 CCIBufferReader::readUI32() const
{
    UI32 ui32 = readUI8();
    ui32 |= ((UI32) readUI8()) << 8;
    ui32 |= ((UI32) readUI8()) << 16;
    ui32 |= ((UI32) readUI8()) << 24;
    
    return ui32;
}


FLOAT16 CCIBufferReader::readFLOAT16() const{
    return this->readUI16();
}
FLOAT  CCIBufferReader::readFLOAT() const{
    return this->readUI32();
}

FIXED CCIBufferReader::readFIXED() const{
    return this->readUI32();
}
FIXED8 CCIBufferReader::readFIXED8() const{
    return this->readUI16();
}
UI32 CCIBufferReader::readUBits(UI32 nbits)
{
    UI32 value = 0;
    UI32 readBits = 0;
    
    while (readBits<nbits) {
        UI32 leftBits = nbits - readBits;
        UI32 usingBitsNumber = 0;
        UI8 usingBits = 0;
        if (this->mLeftNbits>0) {
            usingBitsNumber = this->mLeftNbits>leftBits?leftBits:this->mLeftNbits;
            this->mLeftNbits -=usingBitsNumber;
            
            UI8 willReadByte = this->mLeftByte;
            
            
            
            usingBits = willReadByte>>this->mLeftNbits;
            UI8 maskBit = (1<<this->mLeftNbits)-1;
            this->mLeftByte = willReadByte&maskBit;
            
        }else if (leftBits>=8) {
            usingBitsNumber = 8;
            usingBits = readUI8();
            
        }else{
            UI8 lastByte = readUI8();
            usingBitsNumber = leftBits;
            
            this->mLeftNbits = 8-leftBits;
            usingBits = lastByte>>this->mLeftNbits;
            UI8 one = 1;
            UI8 maskBit = (one<<this->mLeftNbits)-1;
            this->mLeftByte = lastByte&maskBit;
        }
        
        readBits +=usingBitsNumber;
        value <<=usingBitsNumber;
        value |= usingBits;
    }
    return value;
}
int CCIBufferReader::readSBits(UI32 nbits)
{
    int value = this->readUBits(nbits);
    //check fist bit
    if (value>>(nbits-1)) {
        //negative
        UI32 zero = 0;
        int mask = zero^((1<<nbits)-1);
        value |=~mask;
    }
    
    return value;
}

float  CCIBufferReader::readFBits(UI32 nbits){
    return this->readSBits(nbits);
}
void CCIBufferReader::clearBits(){
    this->mLeftNbits = 0;
}
std::string	CCIBufferReader::readString() const
{
    std::string aString;
    while (char c = readUI8()) {
        aString +=c;
    }
    
    return aString;
}

void CCIBufferReader::begin(int length){
    mTagPos = length;
}
bool CCIBufferReader::isTagFinished(){
    return mTagPos==0;
}
void  CCIBufferReader::flush(){
    this->skipBytes(mTagPos);
}

NS_CC_EXT_END