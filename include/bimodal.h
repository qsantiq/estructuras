#ifndef BIMODAL_H
#define BIMODAL_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include <math.h> 
#include"bitcounter.h"
#include <bitset>
using namespace std;

class bimodal {
public:
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


/**
*@funtion bimodal
*@brief Constructor.
**/
bimodal();
/**
*@funtion tournament
*@brief Constructor que define el tamano de la bht.
*@param int s
**/
bimodal(int s);
/**
*@funtion bimodal
*@brief Destructor.
**/
~bimodal();
/**
*@funtion select_c
*@brief Retorna el contador que realiza la prediccion.
*@param int s
*@param unsigned long address
*@return int la posicion del contador que realiza la prediccion en la bht
**/
int select_c(int s, unsigned long address);
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
*@param bool jump
**/
void change_counter(int counter_number, bool jump);

/**
*@funtion ALL
*@brief Realiza todas las funciones para el proceso de prediccion.
*@param int s
*@param bool o
**/
void ALL( int s, int gh, int ph, int o);


};


#endif