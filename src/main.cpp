/*********************************************************************************
 *     File Name           :     src/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 14:23]
 *     Last Modified       :     [2016-09-01 09:27]
 *     Description         :      
 **********************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <fstream>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include "util.hpp"
#include "file_encrypter.hpp"
using namespace std;

void show_help() {
  printf("======================================\n");
  printf("Crypter is for encrypting payload programs to bypass security \
protocols\n");
  printf("-e or --encrypt [FILE NAME]\n");
  printf("-d or --decrypt [FILE NAME]\n");
  printf("-o or --output [FILE NAME] OPTIONAL\n");
  printf("-t or --type XOR|DES default:XOR\n");
  printf("Example: crypter -e some_binary_file -o nothing_to_see_here\n");
  printf("======================================\n");
}
int main(int argc, char **argv) {

  int opt_index =0,c=0;

  static struct option long_opts[] = {
    {"help", no_argument, 0, 'h' },
    {"type", required_argument, 0, 't'},
    {"encrypt", required_argument, 0, 'e' },
    {"decrypt", required_argument, 0, 'd' },
    {"output", optional_argument, 0, 'o' }
  };

  string output_file_name("output");
  string input_file;
  int e=0, d = 0;

  while(((c = getopt_long(argc, argv,"he:d:o:",
            long_opts, &opt_index))) != -1) {

    switch(c) {
      case 'h':
        show_help();
        break;
      case 'o':
        output_file_name = optarg; 
        break;
      case 'e':
        input_file = optarg;
        e = 1;
        break;
      case 'd':
        d = 1;
        input_file = optarg;
        break;
      case 't':

        break;
    }

  }
  if(!e && !d) {
    show_help();
    exit(1);
  }
  FileEncrypter fe(input_file, output_file_name);

  if(e) {
    if(fe.Encrypt() != E_FES_OKAY) {
      cout << "Error in encryption" <<endl;
      exit(0);
    }
  }else if(d){
    if(fe.Decrypt() != E_FES_OKAY) {
      cout << "Error in decryption" << endl;
      exit(0);
    } 
  }else {
    show_help();
    exit(1);
  }

  cout << "Output file: " << fe.GetOutputPath() << endl;

  return 0;
}
