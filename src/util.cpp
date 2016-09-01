/*********************************************************************************
 *     File Name           :     /home/anon/Work/crypter/src/util.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-08-31 13:42]
 *     Last Modified       :     [2016-08-31 13:48]
 *     Description         :      
 *********************************************************************************/
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "util.hpp"

using namespace std;

int Util::IsFileValid(char *path) {
  ifstream *fs = new ifstream();
  fs->open(path,ifstream::binary);
  if(fs->is_open()) {
    fs->close();
    delete fs;
    return 1;
  }
  delete fs;
  return 0;
}
