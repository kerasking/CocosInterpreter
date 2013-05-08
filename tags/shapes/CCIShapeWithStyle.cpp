//
//  CCIShapeWithStyle.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIShapeWithStyle.h"
#include "CCIEndShapeRecord.h"
#include "CCIStyleChangeRecord.h"
#include "CCIStraightEdgeRecord.h"
#include "CCICurvedEdgeRecord.h"

#include "CCIMovieTag.h"

NS_CC_EXT_BEGIN

CCIShapeWithStyle::CCIShapeWithStyle(CCIBufferReader * reader){
    this->FillStyles = new CCIFillStyleArray(reader);
    this->LineStyles = new CCILineStyleArray(reader);
    this->NumFillBits = reader->readUBits(4);
    this->NumLineBits = reader->readUBits(4);
    
    //TODO; SHAPERECORD
    CCIShapeRecord * record = NULL;
    UI32 numFillBits = this->NumFillBits;
    UI32 numLineBits = this->NumLineBits;
    
    while (reader->scanUBits(6)) {
        UI8 type = reader->scanUBits(2);
        if (type==0x02) {
            record = new CCICurvedEdgeRecord(reader,numFillBits,numLineBits);
        }else if(type == (0x01 | 0x02)){
            record = new CCIStraightEdgeRecord(reader,numFillBits,numLineBits);
        }else{
            record = new CCIStyleChangeRecord(reader,numFillBits,numLineBits);
            CCIStyleChangeRecord * styleRecord= (CCIStyleChangeRecord *)record;
            if (styleRecord->StateNewStyles) {
                numFillBits = styleRecord->NumFillBits;
                numLineBits = styleRecord->NumLineBits;
            }
        }
        ShapeRecords.push_back(record);
    }
     
    
    //End shape
    record = new CCIEndShapeRecord(reader,numFillBits,numLineBits);
    reader->clearBits();
    ShapeRecords.push_back(record);
    
}
CCIShapeWithStyle::~CCIShapeWithStyle(){
    delete this->FillStyles;
    delete this->LineStyles;
    
    for (int i=0; i<ShapeRecords.size(); i++) {
        CCIShapeRecord * record = ShapeRecords[i];
        delete record;
    }
    ShapeRecords.clear();
}
NS_CC_EXT_END