#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "read_data.h"
float** read_data(){
		float** data = new float * [50000];
		for ( int i = 0; i < 50000; i++ ) data[i] = new float [4];


        FILE *p;
        char c = 'a';
		char num_str[20];
		int count_num = 0;
		float x;
		int i = 0;
		int j = 0;

        /* abre novamente para a leitura  */
        p = fopen("../Genetic_Algorithm/dados_cpp.csv","r");
		
        while (1){
			while(c != '\n'){
			
				while((c != ',')){
					
					fscanf(p,"%c",&c);
					if(feof(p)){
					   break;
					} 
					if (c == '\n'){
						num_str[count_num+1] = '.';
						num_str[count_num+2] = '0';
						num_str[count_num+3] = '0';
						num_str[count_num+4] = '0';
						num_str[count_num+5] = '0';
						num_str[count_num+6] = '0';
						num_str[count_num+7] = '0';
						num_str[count_num+8] = '0';
						break;
					} 
					num_str[count_num] = c;
					count_num ++;
				}
				if(feof(p)){
					break;
				}
				x =atof(num_str);
				data[i][j] = x;
				if (c == '\n'){
				}else c = 'a';
				count_num = 0;
				j++;
			}
			if(feof(p)){
				break;
			}
			c = 'a';
			j = 0;
			i++;

		}
		fclose(p);
		return data;
		
}
 
