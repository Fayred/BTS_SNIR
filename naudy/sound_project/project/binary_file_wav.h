#ifndef BINARY_FILE_WAV_H
#define BINARY_FILE_WAV_H

#include "binary_file.h"

#include <string>

class binary_file_wav:public binary_file{
private:
    char tag1[5];
    unsigned int size1;
    char wav_format[5];
    char tag2[5];
    unsigned int lgdef;
    unsigned int file_format;
    unsigned int nbchannel;
    unsigned int freq;
    unsigned int bytepersec;
    unsigned int nbrbyte;
    unsigned int nbbits;
    char tag3[5];
    unsigned int size2;

public:
    binary_file_wav(std::string);
    void get_header();
    std::string get_tag1();
    unsigned int get_size1();
    std::string get_wav_format();
    std::string get_tag2();
    unsigned int get_lgdef();
    unsigned int get_file_format();
    unsigned int get_nbchannel();
    unsigned int get_freq();
    unsigned int get_bytepersec();
    unsigned int get_nbrbyte();
    unsigned int get_nbbits();
    std::string get_tag3();
    unsigned int get_size2();
};

#endif // BINARY_FILE_WAV_H
