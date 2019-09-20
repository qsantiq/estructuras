#ifndef PSHARE_H
#define PSHARE_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include <bitset>
#include <math.h> 
#include"bitcounter.h"
#include"bimodal.h"
using namespace std;

class pshare {
public:
vector<long> pht_a;

vector<string> pht_h;
char prediction;
char result;
unsigned char bhr;
vector<unsigned char> pht;
vector<bitcounter> counters;
double jumps;
double fails;
double miss_rate;
double correct_rate;
long   ctaken;
long   cntaken;
long   nctaken;
long   ncntaken;

/**
*@funtion pshare
*@brief Constructor.
**/
pshare();
/**
*@funtion pshare
*@brief Constructor que define el tamano de la bht
*@param int s 
**/
pshare(int s);
/**
*@funtion ~pshare
*@brief Destructor.
**/
~pshare();

/**
*@funtion select_c
*@brief Retorna el contador que realiza la prediccion.
*@param unsigned long address
*@param int s
*@return int la posicion del contador que realiza la prediccion en la bht
**/
int select_counter(unsigned long address, int s);

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
*@param int counter_number
*@param int j
**/
void change_counter(int counter_number, int j);
/**
*@funtion update_pht
*@brief Actualiza el pattern history table.
*@param long address
*@param char j
*@param int s
*@param int ph
**/
void update_pht(long address,char j, int s, int ph);
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