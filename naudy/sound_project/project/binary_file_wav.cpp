#include "binary_file_wav.h"

#include <iostream>
#include <string>

binary_file_wav::binary_file_wav(std::string init_filename): binary_file(init_filename){

}
void binary_file_wav::get_header(){
    // ptr, pos, nbyte
    read_bin_file((unsigned char*)&tag1, 0, 4);
    read_bin_file((unsigned char*)&size1, 4, 4);
    read_bin_file((unsigned char*)&wav_format, 8, 4);
    read_bin_file((unsigned char*)&tag2, 12, 4);
    read_bin_file((unsigned char*)&lgdef, 16, 4);
    read_bin_file((unsigned char*)&file_format, 20, 2);
    read_bin_file((unsigned char*)&nbchannel, 22, 2);
    read_bin_file((unsigned char*)&freq, 24, 4);
    read_bin_file((unsigned char*)&bytepersec, 28, 4);
    read_bin_file((unsigned char*)&nbrbyte, 32, 2);
    read_bin_file((unsigned char*)&nbbits, 34, 2);
    read_bin_file((unsigned char*)&tag3, 36, 4);
    read_bin_file((unsigned char*)&size2, 40, 4);
}
std::string binary_file_wav::get_tag1(){
    return std::string(tag1);
}
unsigned int binary_file_wav::get_size1(){
    return size1;
}
std::string binary_file_wav::get_wav_format(){
    return std::string(wav_format);
}
std::string binary_file_wav::get_tag2(){
    return std::string(tag2);
}
unsigned int binary_file_wav::get_lgdef(){
    return lgdef;
}
unsigned int binary_file_wav::get_file_format(){
    return file_format;
}
unsigned int binary_file_wav::get_nbchannel(){
    return nbchannel;
}
unsigned int binary_file_wav::get_freq(){
    return freq;
}
unsigned int binary_file_wav::get_bytepersec(){
    return bytepersec;
}
unsigned int binary_file_wav::get_nbrbyte(){
    return nbrbyte;
}
unsigned int binary_file_wav::get_nbbits(){
    return nbbits;
}
std::string binary_file_wav::get_tag3(){
    return std::string(tag3);
}
unsigned int binary_file_wav::get_size2(){
    return size2;
}
