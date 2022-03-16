#include <stdlib.h>
#include <stdio.h>

#include "structures.h"

personal_choice* create_personal(int scan_personal_neighbours)
{
	personal_choice* choice = (personal_choice*) malloc(sizeof(personal_choice));
	
	if(choice != NULL)
	{
		choice -> dies = 0;
		choice -> comes_back = 0;
		choice -> personal_neighbours = scan_personal_neighbours;
	        choice -> neighbours_indexes = (int*) malloc(sizeof(int) * scan_personal_neighbours);
	
		for(int i = 0; i < scan_personal_neighbours; i++)
		{
			choice -> neighbours_indexes[i] = i + 1;
		}
	}

	return choice;
}

personal_choice* personal_mode_interface()
{
	int 	scan_personal_neighbours;

	system("clear");

	printf("\tNEIGHBOURS INDEXES:\n\n");
	printf("\t       \u24F5  \u24F6  \u24F7\n");
	printf("\t       \u24F8  \u2b1c \u24F9\n");
	printf("\t       \u24FA  \u24FB  \u24FC\n\n");

	printf("\n\nHow many neighbours do you want to consider? (whole number between 1 and 8): ");
       	
	if( scanf("%d", &scan_personal_neighbours) != 1)
       	{
		return NULL;
       	}

        printf("\n");

	personal_choice* choice = create_personal(scan_personal_neighbours);

	if((choice -> personal_neighbours) <= 0 || (choice -> personal_neighbours) >= 9)
	{
		printf("\nNumber out of range. Exiting.\n\n");
		return NULL;
	}

	for(int i = 0; i < (choice -> personal_neighbours); i++)
        {
                printf("Index of %d neighbour: ", i + 1);
                
		if(scanf("%d", &(choice -> neighbours_indexes[i])) != 1)
		{
			return NULL;
		}
		
		for(int j = 0; j < i; j++)
        	{
                  	while((choice -> neighbours_indexes[i]) == (choice -> neighbours_indexes[j]))
                       	{
                            	printf("Already entered this index, enter again index of %d neighbour: ", i + 1);
				
				if(scanf("%d", &(choice -> neighbours_indexes[i])) != 1)
				{
					return NULL;
				}

				j = 0;
			}
		}			
	
		if((choice -> neighbours_indexes[i]) <= 0 || (choice -> neighbours_indexes[i]) >= 9)
               	{
			printf("\n\nNumber out of range. Exiting.\n\n");
                       	return NULL;
               	}      	
	}
	
	printf("\nCHOOSEN INDEXES: ");
	for(int i = 0; i < (choice -> personal_neighbours); i++)
	{
		printf("%d ", (choice -> neighbours_indexes[i]));
	}

	printf("\n\n");

        printf("RULES: \n\n");
        printf("Alive cell dies when it has X neighbours (enter a whole number between 1 and 8): ");
        
	if(scanf("%d", &(choice -> dies)) != 1)
	{
		return NULL;
	}
	
	if((choice -> dies) <= 0 || (choice -> dies) >= 8)
	{
		printf("\nNumber out of range. Exiting.\n\n");
		return NULL;
	}

	printf("Dead cell comes back to life when it has X neighbours (enter a whole number between 1 and 8): ");
        
	if(scanf("%d", &(choice -> comes_back)) != 1)
	{
		return NULL;
	}

	if((choice -> comes_back) <= 0 || (choice -> comes_back) >= 8)
	{
		return NULL;
	}

	printf("\n\n");

	return choice;
}

void free_personal(personal_choice* choice)
{
	free((choice -> neighbours_indexes));	
	free(choice);
}
