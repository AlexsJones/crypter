/*********************************************************************************
 *     File Name           :     /home/anon/Work/crypter/src/file_encrypter.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-08-31 11:50]
 *     Last Modified       :     [2016-09-01 09:09]
 *     Description         :      
 **********************************************************************************/

#include "file_encrypter.hpp"
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MAXPATHLEN 2048
#define XOR_BYTE 0xAA
using namespace std;

FileEncrypter::FileEncrypter(string filepath, 
    string output_file):_filepath(filepath),_output_file(output_file){
  
  cout << "File Encrypter initialised with input file:" << _filepath << 
" and output file:" << _output_file << endl;
};
E_FILE_ENCRYPTER_STATUS FileEncrypter::readFromFile(char **obuffer, size_t *osize) {

  FILE *fp = fopen(_filepath.c_str(),"rb");
  if(!fp) {
    cout << "Could not open file" << endl;
    return E_FES_FAIL;
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  char *buffer = (char*)malloc(sizeof(short) * size);
  size_t r = fread(buffer,1,size,fp);
  if(r != size) {
    cout << "Read error" << endl;
    fclose(fp);
    return E_FES_FAIL;
  }
  cout << "File size is approximately: " << size / 1024 << "kb" << endl;
  fclose(fp);

  *obuffer = buffer;
  *osize = size;
  return E_FES_OKAY;
}
E_FILE_ENCRYPTER_STATUS FileEncrypter::writeToFile(char *buffer, 
    size_t size, char *filepath) {

  cout << "writing to :" << filepath << endl;
  cout << "Writing File size is approximately: " << size / 1024 << "kb" << endl;
  FILE *fp = fopen(filepath,"wb");
  if(!fp) {
    cout << "Could not open file" << endl;
    return E_FES_FAIL;
  }
  fwrite(buffer,sizeof(char), size,fp);
  fclose(fp);
  return E_FES_OKAY;
}
E_FILE_ENCRYPTER_STATUS FileEncrypter::Encrypt(void) {

  char *buffer;
  size_t size;
  readFromFile(&buffer,&size);
  int i;
  for(i =0; i != size; ++i) {

    buffer[i] ^= XOR_BYTE;
  }
  E_FILE_ENCRYPTER_STATUS e = writeToFile(buffer,size,(char*)GetOutputPath().c_str());
  free(buffer);
  return e;
}
E_FILE_ENCRYPTER_STATUS FileEncrypter::Decrypt(void) {

  char *buffer;
  size_t size;
  readFromFile(&buffer,&size);
  int i;
  for(i =0; i != size; ++i) {

    buffer[i] ^= XOR_BYTE;
  }
  E_FILE_ENCRYPTER_STATUS e = writeToFile(buffer,size,(char*)GetOutputPath().c_str());
  free(buffer);
  return e;
}
string FileEncrypter::getWorkingPath(void) {
  char temp[MAXPATHLEN];
  return ( getcwd(temp, MAXPATHLEN) ? std::string( temp ) : std::string("") );
}
string FileEncrypter::GetOutputPath(void) {

  string o = getWorkingPath();

  return o + "/" + _output_file;

}
void FileEncrypter::ExecuteOutputfile(void) {

  if(Util::IsFileValid((char*)GetOutputPath().c_str())) {


  }else {
    cout << "Cannot execute output file does not exist!" << endl;
  }
}
