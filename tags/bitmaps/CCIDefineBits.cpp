//
//  CCIDefineBits.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineBits.h"
#include "CCImage.h"

#define SOI 0xffd8
#define EOI 0xffd9
#define SOF0 0xFFC0
#define SOF2 0xFFC2
#define JPG 0xFFC8
#define SOFF 0xFFCF
#define DHT 0xFFC4
#define DQT 0xFFD8
#define DRI 0xFFDD
#define SOS 0xFFDA
#define RST 0xFFD0
#define APP 0xFFE0
#define COM 0xFFFE


NS_CC_EXT_BEGIN
bool CCIDefineBits::initWithReader(cocos2d::extension::CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIImageTag::initWithReader(reader, tagType, tagLength);
    imageSize = tagLength-2;
    UI8 *imageData = reader->readBytes(imageSize);
    this->loadImageData(imageData);
    
    return true;
}
void CCIDefineBits::loadImageData(UI8 * imageData){
    this->decodeInfo(imageData);
    
    CCImage::EImageFormat eImageFormat = CCImage::kFmtJpg;
    CCImage image;
    image.initWithImageData((void*)imageData, tagLength-2, eImageFormat);
    
    this->texture2d = new CCTexture2D();
    this->texture2d->initWithImage(&image);
    
}
void CCIDefineBits::decodeInfo(UI8* imageData){
    int limit = imageSize -2;
    int marker;
    int length;
    int index =0;
    while (index<limit) {
        marker = (imageData[index++] & 0xff)<<0x08|(imageData[index++]&0xff);
        if (marker == SOI||marker==EOI) {
            continue;
        }
        length = ((imageData[index++] & 0xff) << 0x08)| (imageData[index++] & 0xff);
        if (marker >= SOF0 && marker <= SOFF
            && marker != DHT && marker != JPG) {
            
            index++;
            height = ((imageData[index++] & 0xff) << 0x08)
            | (imageData[index++] & 0xff);
            width = ((imageData[index++] & 0xff) << 0x08)
            | (imageData[index++] & 0xff);
            break;
        } else {
            index += length - 2;
        }
    }
}
NS_CC_EXT_END