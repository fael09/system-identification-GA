#include "GaAdapter.h"
//For shared memory
#include <sys/shm.h>
#include <sys/stat.h>
#include <cstdlib>
#include <stdlib.h>
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
    float erro = 0;
    float km = 0;
    float tau = 0;
    int j = 0, simple_size=1;
    float fitness = 0;
    
            
    string aux1 = chromosome->getBits().substr((0*32),((0+1)*32));
    string aux2 = chromosome->getBits().substr((1*32),((1+1)*32));
    // string aux[i] = chromosome->getBits().substr((i*32),((i+1)*32));

    km = chromosome->binToFloat(aux1);
    tau = chromosome->binToFloat(aux2);
    // del_plus//
    // del_menus//

   for (size_t i = 0; i <= 36000; i++){
        t[i] = data[i][0];  
        udet[i] = data[i][3];
        gt[i] = data[i][1];    
        
        if(udet[i] != udet[i+1]){
            j = 0;
        }
        out_model[i] = (1 - exp(t[j]/tau))*km*udet[i];
        erro = erro + abs(gt[i]-out_model[i]);
        j++;
    }

    simple_size = sizeof(gt)/4;

    fitness = 1 - erro/simple_size;
 chromosome->setFitness(fitness);	

}
