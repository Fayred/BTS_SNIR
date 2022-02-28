#include "binary_file.h"

#include <fstream>
#include <iostream>

binary_file::binary_file(std::string init_filename){
    filename = init_filename;
}
int binary_file::open_bin_file(){
    if(filename.empty() == 1) return -1;
    file.open(filename, std::fstream::binary);
    if(file.is_open() == 0) return -1;
    return 0;
}
void binary_file::close_bin_file(){
    file.close();
}
void binary_file::read_bin_file(unsigned char *ptr, int position, int offset){
    file.seekg(position);

    char buffer[offset];
    file.read(buffer, offset);

    for(int i = 0; i < offset; i++){
        ptr[i] = buffer[i];
    }

    buffer[offset + 1] = '\0';
}
