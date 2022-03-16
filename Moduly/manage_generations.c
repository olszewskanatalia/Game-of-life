#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"


#ifndef OUT 
#define OUT "./Generacje_Wyjsciowe/"
#endif

#ifndef IN
#define IN "./Generacje_Wejsciowe/"
#endif


void free_generation(generation* gen_to_clear)
{
	for(int i = 0; i < gen_to_clear -> r; i++)
	{
		free(gen_to_clear -> gen[i]);
	}

	free(gen_to_clear -> gen);
	free(gen_to_clear);
}

generation* create_generation(int row, int column)
{
	generation* 	new_gen		=	(generation*) malloc(sizeof(generation));

	if(new_gen != NULL)
	{
		new_gen -> r = row;
		new_gen -> c = column;
		new_gen -> nr = 1;
		new_gen -> gen = (int**) malloc(sizeof(int*) * row);

		for(int i = 0; i < row; i++)
		{
			new_gen -> gen[i] = (int*) malloc(sizeof(double) * column);
		}
	}

	return new_gen;
}

void print_to_output(generation* gen_to_print, char* name)
{
        char*		file_name	=       (char*) malloc(sizeof(char) * (1 + strlen(OUT) + strlen(name)));
        FILE*		file;                          
       
	if(file_name == NULL)
        {
                printf("\n\tFileError\n\n");
                return;
        }
       
        strcpy(file_name, OUT);
        strcat(file_name, name);
	
	file = fopen(file_name, "w");
	
	fprintf(file, "%d %d\n", gen_to_print -> r, gen_to_print -> c);

	for(int i = 0; i < gen_to_print -> r; i++)
       	{
                for(int j = 0; j < gen_to_print -> c; j++)
                {	
                        fprintf(file, "%d ", gen_to_print -> gen[i][j]);
                }

                fprintf(file, "\n");
	}

	free(file_name);

	fclose(file);
}

generation* read_generation(char* name)
{
	
        char*		file_name 	= 	(char*) malloc(sizeof(char) * (1 + strlen(IN) + strlen(name)));
	int 		row;
       	int		column;
        FILE*		file; 	
	
 	if(file_name == NULL)
	{
		printf("\n\tFileError\n\n");
		return NULL;
	}

	strcpy(file_name, IN);
        strcat(file_name, name);

	file = fopen(file_name, "r");
	generation* gen_to_read = NULL;

	if(file != NULL)
	{
		if(fscanf(file, "%d %d", &row, &column) != 2)
		{
			printf("\n\tFileError\n\n");
			return NULL;
		}

		if((row < 3 || row > 41) && (column < 3 || column > 51))
		{
			printf("\n\tFileError\n\n");
			return NULL;
		}

		gen_to_read = create_generation(row, column);

		if(gen_to_read != NULL)
		{
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < column; j++)
				{
					if(fscanf(file,"%d",&(gen_to_read -> gen[i][j])) != 1)
					{
						printf("\n\tFileError\n\n");
						return NULL;
					}
		
					if(gen_to_read -> gen[i][j] != 0 && gen_to_read -> gen[i][j] != 1)
					{
						printf("\n\tFileError\n\n");
						return NULL;
					}
				}
			}
		}
		else
		{
			printf("\n\tFileError\n\n");
			return NULL;
		}
	}
	else
	{
		printf("\n\tFileError\n\n");
		return NULL;
	}
	
	fclose(file);
	free(file_name);

	return gen_to_read;
}
