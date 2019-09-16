#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include "read_data.h"
		
int main () {
		float** data = read_data();
		float udet[36000];
        float t[36000];
        float gt[36000];

		for (size_t i = 0; i <= 36000; i++)
    {
     	t[i] = data[i][0];  
        udet[i] = data[i][3];
        gt[i] = data[i][1];   
	 	printf("%f:%f:%f\n",t[i],udet[i],gt[i]);
    }
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
		

