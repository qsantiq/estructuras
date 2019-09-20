#ifndef TOURNAMENT_H
#define TOURNAMENT_H
//trenes

#include <iostream>
#include <fstream>
#include<string>
#include <bitset>
#include<vector>
#include <math.h> 
#include <bits/stdc++.h> 
#include"bitcounter.h"
#include"bimodal.h"
#include"gshare.h"
#include"pshare.h"
using namespace std;

class tournament {
public:
vector<int> bhr;
char prediction;
char result;
char selected_p;
vector<bitcounter> counters;
gshare predictorg;
pshare predictorp;
double jumps;
double fails;
double miss_rate;
double correct_rate;
long ctaken;
long cntaken;
long nctaken;
long ncntaken;
/**
*@funtion tournament
*@brief Constructor.
**/
tournament();
/**
*@funtion tournament
*@brief Constructor que define el tamano de la bht.
*@param int s
**/
tournament(int s);
/**
*@funtion ~tournament
*@brief Destructor.
**/
~tournament();
/**
*@funtion select_c
*@brief Retorna el contador que realiza la prediccion.
*@param unsigned long address
*@param int s
*@return int la posicion del contador que define cual de los 2 predictores se usa
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
*@param int counter_numbers
*@param int j
**/
void change_counter(int counter_number, int j);

/**
*@funtion g_predict
*@brief llama a los metodos del predictor gshare instanciado en el metapredictor.
*@param long address
*@param int s
*@param int hh
*@param char j
**/
void g_predict(long address, int s, int gh, char j);
/**
*@funtion g_predict
*@brief llama a los metodos del predictor pshare instanciado en el metapredictor.
*@param long address
*@param int s
*@param int ph
*@param char j
**/
void p_predict(long address, int s, int ph, char j);

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