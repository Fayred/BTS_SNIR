#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include <fstream>
#include <string>

class binary_file{
protected:
   std::ifstream file;
   std::string filename;

public:
   binary_file(std::string init_filename);
   int open_bin_file();
   void close_bin_file();
   void read_bin_file(unsigned char *, int, int);
};

#endif // BINARY_FILE_H
