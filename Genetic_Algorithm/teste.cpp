#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include "read_data.h"
#include <stdlib.h>
#include <math.h>  
		
int main () {
	    float** data;
    data = read_data();
    float udet[36000];
    float t[36000];
    float gt[36000];
    float out_model[36000];
    float erro = 0;
    float km = 24.8884;
    float tau = 0.1244;
    int j = 0, simple_size=1;
    float fitness = 0;
    
            

    // string aux[i] = chromosome->getBits().substr((i*32),((i+1)*32));

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
	printf("%i: %f",simple_size,fitness);
		return 0;
	}

		// for ( int n = 0; n < i; n++)
		// {
		// 	for ( j = 0; j < 5; j++)
		// 	{
		// 		printf("%f ",dados[n][j]);
		// 	}
		// 	printf("\n");
		// }
		

