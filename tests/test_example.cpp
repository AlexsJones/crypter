/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-14 15:35]
 *     Description         :      
 **********************************************************************************/
#include <assert.h>
#include <iostream>

using namespace std;


void test_example_case() {
  assert(1 == 1);
}

int main(int argc, char **argv) {
  
  cout << "Running example test" << endl;
  test_example_case();

  return 0;
}
