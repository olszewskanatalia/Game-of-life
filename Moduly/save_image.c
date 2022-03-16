#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"


#ifndef SIZE
#define SIZE 20
#endif

int multiplicity(int number, int difference)                                        
{                                                                                  
        int 		multiple 			= 	0;                                                                              

	while(number > 1)                                                    
        {                                                                          
                multiple++;                                                     
                number -= difference;                                               
        }                                                                                          

	return multiple;                                                                
}          

void save_generation(generation* generation_to_save)
{
	int		size_of_square			= 	SIZE;
  	const int 	x_max 				= 	(generation_to_save->c) * size_of_square; 
  	const int 	y_max 				= 	(generation_to_save->r) * size_of_square;
  	const int 	max_color_component_value 	= 	255;
  	char*		file_extention			=	".pgm";
	char*		whats_inside			= 	"./Obrazy/generation";
	char*		num_to_string			=	(char*) malloc(sizeof(char) * 100);
	char*		filename;
	FILE*		generated_image;
	unsigned char	data[y_max][x_max];

	if(num_to_string == NULL)
	{
		return;
	}

	sprintf(num_to_string, "%d", generation_to_save -> nr);
 
        filename = (char*) malloc(1 + strlen(file_extention) + strlen(whats_inside) + strlen(num_to_string));
	
	if(filename == NULL)
	{
		return;
	}

	strcpy(filename, whats_inside);
	strcat(filename, num_to_string);
	strcat(filename, file_extention);

  	for (int y = 0; y < y_max; y += size_of_square) 
  	{
		for (int x = 0; x < x_max; x += size_of_square) 
		{
      			if(generation_to_save -> gen[multiplicity(y, size_of_square)][multiplicity(x, size_of_square)] == 0)
      			{
	      			for(int i = 0; i < size_of_square; i++)
		      		{
		      			for(int j = 0; j < size_of_square; j++)
					{
						data[y + i][x + j] = 55;
					}
		      		}
      			}
      			else 
	      		{
        			for(int i = 0; i < size_of_square; i++)
        			{
              				for(int j = 0; j < size_of_square; j++)
                			{
                        			data[y + i][x + j] = 220;
	                		}
        	      		}
      			}
    		}
  	}
 
	generated_image = fopen(filename, "wb");
	fprintf(generated_image, "P5\n %d\n %d\n %d\n", x_max, y_max, max_color_component_value);
	fwrite(data, sizeof(data), 1, generated_image);
	fclose(generated_image);
	free(filename);
	free(num_to_string);
}
