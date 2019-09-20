#ifndef READER_H
#define READER_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <cstdlib>
#include<vector>
#include "bimodal.h"
#include "pshare.h"
#include "gshare.h"
using namespace std;

class reader {
public:
char cadena[128];
vector<char> jump;
vector<string> pht_a;
vector<unsigned long>pht_n;
vector<long> address;
//vector<string> address_s;
//vector<char> address_c;
reader();
~reader();
void read(string path);
void read();
//void fill_pht (string path);





};


#endif