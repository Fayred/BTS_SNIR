#include "binary_file_wav.h"

#include <iostream>
#include <string>

int main(){
    binary_file_wav *bfw = new binary_file_wav("../tests/test.wav");
    bfw->open_bin_file();
    bfw->get_header();
    bfw->close_bin_file();

    std::cout
    << "tag1 = " << bfw->get_tag1() << std::endl
    << "size1 = " << bfw->get_size1() << std::endl
    << "wav_format = " << bfw->get_wav_format() << std::endl
    << "tag2 = " << bfw->get_tag2() << std::endl
    << "nbchannel = " << bfw->get_nbchannel() << std::endl
    << "freq = " << bfw->get_freq() << std::endl
    << "bytespersec = " << bfw->get_bytepersec() << std::endl
    << "nbrbyte = " << bfw->get_nbrbyte() << std::endl
    << "nbbits = " << bfw->get_nbbits() << std::endl
    << "tag3 = " << bfw->get_tag3() << std::endl
    << "size2 = " << bfw->get_size2() << std::endl;

    return 0;
}
