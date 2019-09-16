#include "GaAdapter.h"
//For shared memory
#include <sys/shm.h>
#include <sys/stat.h>
#include <cstdlib>
#include <math.h>   
#include "read_data.h"
using namespace std;
//--------------------------------------------------------------------------
//Auxiliary methods

//---------------------------------------------------------------------------



void GaAdapter::callTest(Chromosome* chromosome) {
    
    float** data;
    data = read_data();
    float udet[36000];
    float t[36000];
    float gt[36000];
    float out_model[36000];
    float erro = 20;
    float km;
    float tau;
    float out_model;
    for (size_t i = 0; i < 36000; i++){
        t[i] = data[i][0];  
        udet[i] = data[i][3];
        gt[i] = data[i][1];    
    }


    
    
    
    
    string aux1 = chromosome->getBits().substr((0*32),((0+1)*32));
    string aux2 = chromosome->getBits().substr((1*32),((1+1)*32));
    // string aux[i] = chromosome->getBits().substr((i*32),((i+1)*32));

    km = chromosome->binToFloat(aux1);
    tau = chromosome->binToFloat(aux2);
   
    out_model = (1 - exp(t/tau))*km*udet;
    out_model = out_model;
   

 float fitness = 1/erro;
 chromosome->setFitness(fitness);	
 // mudar o 1 arg; 
}
