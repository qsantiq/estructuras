#ifndef BITCOUNTER_H
#define BITCOUNTER_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

class bitcounter {
public:
int states[3];
int actual_s;
void change_s(bool jump);
void change_s_m(bool jump, bool gr, bool pr);
bitcounter();
bitcounter(int state);
~bitcounter();





};


#endif