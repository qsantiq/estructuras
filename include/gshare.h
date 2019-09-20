#ifndef GSHARE_H
#define GSHARE_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include <bitset>
#include <math.h> 
#include"bitcounter.h"
#include"bimodal.h"
using namespace std;

class gshare {
public:
//vector<int> bhr;
unsigned char bhr;
char prediction;
char result;
vector<bitcounter> counters;
double jumps;
double fails;
double miss_rate;
double correct_rate;
long ctaken;
long cntaken;
long nctaken;
long ncntaken;


gshare();
gshare(int s);
~gshare();

/**
*@funtion select_c
*@brief Retorna el contador que realiza la prediccion.
*@param unsigned long address
*@param int s
*@param int gh
*@return int la posicion del contador que realiza la prediccion en la bht
**/
int select_counter(unsigned long address,int s, int gh );

/**
*@funtion predict
*@brief Realiza la prediccion
*@param int c
**/
void predict(int c);
/**
*@funtion compare
*@brief Compara la prediccion con el resultado y devuelve si el salto se debia tomar o no.
*@param char j
*@return bool 1 si el salto se debia tomar, 0 en caso contrario
**/
bool compare(char j);

/**
*@funtion change_counter
*@brief llama a la funcion para cambiar el estado del contador.
*@param counter_number
*@param int j
**/
void change_counter(int counter_number, int j);
/**
*@funtion update_bhr
*@brief Actualiza el branch history register.
*@param int gh
*@param char j
**/
void update_bhr(int gh, char j);
/**
*@funtion ALL
*@brief Realiza todas las funciones para el proceso de prediccion.
*@param int s
*@param int gh
*@param bool o
**/
void ALL( int s, int gh, int ph, int o);
};

#endif