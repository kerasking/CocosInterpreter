//
//  CCIMovie.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIMovie.h"
#include "CCFileUtils.h"
#include "CCIBufferReader.h"
#include "CCIFrameLabel.h"


NS_CC_EXT_BEGIN
static CCDictionary * movies = NULL;
CCIMovie * CCIMovie::decodeFromFile(std::string filename){
    
    if (!movies) {
        movies = new CCDictionary();
    }
    CCIMovie * movie = (CCIMovie *)movies->objectForKey(filename);
    if (movie) {
        return movie;
    }
    
    const char * fullPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(filename.c_str());
    int fileSize = 0;
    
    unsigned char * swfdata = CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", (unsigned long *)(&fileSize));
    
    if (fileSize < 0)
    {
        delete[] swfdata;
        return NULL;
    }
    CCIBufferReader bufferReader;
    bufferReader.setData(swfdata, fileSize);
    delete[] swfdata;
    
    
    movie = new CCIMovie();
    movie->frameLabels = CCDictionary::create();
    movie->frameLabels->retain();
    movie->header = CCIMovieHeader::create(&bufferReader);
    
    bufferReader.version = movie->header->getVersion();
    
    if (movie->header->getVersion()>=8) {
        movie->fileAttributes = (CCIFileAttributes *)CCIMovieTag::next(&bufferReader);
    }
    CCIMovieTag * tag = CCIMovieTag::next(&bufferReader);
    int tagIndex = 0;
    while (tag) {
        movie->tags.push_back(tag);
        tag = CCIMovieTag::next(&bufferReader);
        tagIndex++;
        
        if (tag&&tag->getTagType()==TagTypeFrameLabel) {
            CCIFrameLabel * frameLbl = (CCIFrameLabel *)tag;
            movie->frameLabels->setObject(CCString::createWithFormat("%d",tagIndex), frameLbl->getName());
        }
        
    }
    bufferReader.clear();
    
    movies->setObject(movie,filename);
    movie->release();
    return movie;
}
std::vector<CCIMovieTag *> CCIMovie::getTags(){
    return this->tags;
}
CCIMovieHeader * CCIMovie::getHeader(){
    return this->header;
}
CCDictionary * CCIMovie::getFrameLabels(){
    return this->frameLabels;
}
void CCIMovie::cleanup(){
    movies->release();
    movies = NULL;
}
CCIMovie::~CCIMovie(){
    for (int i=0; i<tags.size(); i++) {
        CCIMovieTag * tag = tags[i];
        delete tag;
    }
    tags.clear();
    delete header;
    delete fileAttributes;
    this->frameLabels->release();
}
NS_CC_EXT_END
