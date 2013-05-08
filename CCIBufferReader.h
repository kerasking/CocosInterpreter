//
//  CCIBufferReader.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCIBufferReader__
#define __CocosInterpreterTest__CCIBufferReader__

#include <iostream>
#include "CCITypes.h"


NS_CC_EXT_BEGIN

class CCIBufferReader{
public:
    ByteVector				mData;
    int						mDataBitSize;
    mutable int				mReadBitPos;
    mutable int				mWriteBitPos;
    
    mutable int             mTagPos;
    
    mutable bool            mReachEnd;
public:
    CCIBufferReader();
    virtual ~CCIBufferReader();
    void					setData(uint8_t* thePtr, int theCount);
    UI8 *                    getDataPtr();
    int						getDataLen() const;
    void					clear();
    
    UI8                     readUI8() const;
    UI16                    readUI16() const;
    UI32                    readUI32() const;
    
    FLOAT16                 readFLOAT16() const;
    FLOAT                   readFLOAT() const;
    
    int                     readSBits(UI32 nbits);
    UI32                    readUBits(UI32 nbits);
    float                   readFBits(UI32 nbits);
    
    void                    clearBits();
    UI8                     scanUBits(UI32 nbits);
    UI8                     scanUI8() const;
    std::string				readString() const;
    UI8 *                   readBytes(UI32 byte) const;
    
    FIXED                   readFIXED() const;
    FIXED8                  readFIXED8() const;
    
    
    void                    skipBytes(UI32 byte) const;
    
    
    
    
    void                    begin(int length);
    bool                    isTagFinished();
    void                    flush();
    
    int                     version;
    int                     tagType;
    
    
private:
    UI8                     mLeftByte;
    UI32                    mLeftNbits;    
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIBufferReader__) */
