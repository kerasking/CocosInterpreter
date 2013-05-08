//
//  CCIFilterList.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIFilterList.h"
NS_CC_EXT_BEGIN
CCIFilterList::CCIFilterList(CCIBufferReader * reader){
    this->NumberOfFilters = reader->readUI8();
    for (int i=0; i<this->NumberOfFilters; i++) {
        CCIFilter * filter = CCIFilter::next(reader);
        Filter.push_back(filter);
    }
}

CCIFilterList::~CCIFilterList(){
    for (int i=0; i<Filter.size(); i++) {
        CCIFilter * filter = Filter[i];
        delete filter;
    }
    Filter.clear();
}

NS_CC_EXT_END