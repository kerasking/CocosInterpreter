//
//  CCIFilterList.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIFilterList__
#define __SwfTest__CCIFilterList__

#include "CCIFilter.h"

NS_CC_EXT_BEGIN
class CCIFilterList {
public:
    CCIFilterList(CCIBufferReader * reader);
    virtual ~CCIFilterList();
    
public:
    UI8 NumberOfFilters;
    std::vector<CCIFilter *> Filter;
    
};

NS_CC_EXT_END

#endif /* defined(__SwfTest__CCIFilterList__) */
