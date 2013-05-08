//
//  CCIImageTag.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIImageTag__
#define __CocosInterpreterTest__CCIImageTag__

#include "ExtensionMacros.h"
#include "CCIMovieTag.h"
#include "CCImage.h"
#include "CCTexture2D.h"
NS_CC_EXT_BEGIN

class CCIImageTag : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    CCTexture2D * getTexture();
    int getCharacterID();
    virtual ~CCIImageTag();
protected:
    UI16    characterID;
    
    CCTexture2D * texture2d;
    
    int imageSize;
    int width;
    int height;
    
    virtual void loadImageData(UI8* imageData);
    
    void createTextureWithRGBAImage(UI8 * RGBAImageData);
    void createTextureWithIndexImage(UI8 * indexImageData,UI8 * tableData,int tableLength);
    UI8 * unzip(UI8 * bytes);
    
    void createTextureWithImageAndAlpha(CCImage *image,UI8 * alpha);
};

NS_CC_EXT_END

#endif /* defined(__CocosInterpreterTest__CCIImageTag__) */
