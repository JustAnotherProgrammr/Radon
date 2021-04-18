#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    fstream swp_file;
    swp_file.open(".swp", ios::out);
    swp_file << "1";
    swp_file.close();
    return 0;
}