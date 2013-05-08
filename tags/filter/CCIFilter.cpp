//
//  CCIFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIFilter.h"
#include "CCIColorMatrixFilter.h"
#include "CCIConvolutionFilter.h"
#include "CCIBlurFilter.h"
#include "CCIDropShadowFilter.h"
#include "CCIGlowFilter.h"
#include "CCIBevelFilter.h"


NS_CC_EXT_BEGIN

enum FilterType {
    FilterTypeDropShadowFilter = 0,
    FilterTypeBlurFilter = 1,
    FilterTypeGlowFilter = 2,
    FilterTypeBevelFilter = 3,
    FilterTypeGradientGlowFilter = 4,
    FilterTypeConvolutionFilter = 5,
    FilterTypeColorMatrixFilter = 6,
    FilterTypeGradientBevelFilter = 7,
};


CCIFilter * CCIFilter::next(CCIBufferReader * reader){
    UI8 filterId = reader->readUI8();
    CCIFilter * filer = NULL;
    switch (filterId) {
        case FilterTypeDropShadowFilter:
            filer = new CCIDropShadowFilter();
            break;
        case FilterTypeGlowFilter:
            filer = new CCIGlowFilter();
            break;
        case FilterTypeBevelFilter:
            filer = new CCIBevelFilter();
            break;
        case FilterTypeColorMatrixFilter:
            filer = new CCIColorMatrixFilter();
            break;
        case FilterTypeConvolutionFilter:
            filer = new CCIConvolutionFilter();
            break;
            
        case FilterTypeBlurFilter:
            filer = new CCIBlurFilter();
            break;
        default:
            //TODO last two filters
            break;
    }
    if (filer->initWithFilterId(filterId, reader)) {
        return filer;
    }
    return NULL;
}
bool CCIFilter::initWithFilterId(UI8 filterId, cocos2d::extension::CCIBufferReader *reader){
    this->FilterID = filterId;
    return true;
}
CCIFilter::~CCIFilter(){
}
NS_CC_EXT_END