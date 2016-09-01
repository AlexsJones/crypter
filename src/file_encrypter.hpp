/*********************************************************************************
*     File Name           :     src/file_encrypter.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-08-31 11:49]
*     Last Modified       :     [2016-08-31 15:38]
*     Description         :      
**********************************************************************************/

#ifndef __FILE_ENCRYPTER_H__
#define __FILE_ENCRYPTER_H__
#include "util.hpp"
#include <string>

enum E_FILE_ENCRYPTER_STATUS {
  E_FES_OKAY,
  E_FES_FAIL
};

using namespace std;
class FileEncrypter{

  public:
    FileEncrypter(string filepath, string output_file);
  
    E_FILE_ENCRYPTER_STATUS Encrypt(void);

    E_FILE_ENCRYPTER_STATUS Decrypt(void);

    string GetOutputPath(void);
    
    void ExecuteOutputfile(void);

  private:
    string _filepath;
    string _output_file;
    string getWorkingPath(void);
    E_FILE_ENCRYPTER_STATUS readFromFile(char **obuffer, 
        size_t *osize);
    E_FILE_ENCRYPTER_STATUS writeToFile(char *buffer, 
        size_t size, char *filepath);
};


#endif
