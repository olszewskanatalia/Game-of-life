#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "structures.h"
#include "save_image.h"
#include "create_new.h"
#include "manage_generations.h"

#ifndef HOW_FAST 
#define HOW_FAST 210000
#endif

int the_same(generation* one, generation* two)
{
	if(one -> r != two -> r)
	{
		return 0;
	}
	
	if(one -> c != two -> c)
	{
		return 0;
	}
	
	for(int i = 0; i < (one -> r); i++)
	{
		for(int j = 0; j < (one -> c); j++)
		{
			if(one -> gen[i][j] != two -> gen[i][j])
			{
				return 0;
			}
		}
	}

	return 1;
}


void print_generation(generation* to_print, char* mode, int how_many)
{
	system("clear");
	printf("\t\tGameOfLife\n\n");
	printf("\t\tMode in run: %s\n", mode);
	printf("\n\t\tGeneration number: %d of %d\n\n", to_print -> nr, how_many);	
	printf("\t\tPopulation: %d\n\n", population(to_print));	

	for(int i = 0; i < to_print -> r; i++)
	{	
		printf("\t\t");
		
		for(int j = 0; j < to_print -> c; j++)
		{
			if((to_print -> gen[i][j]) == 0) 
			{
				printf("\u2b1b");
			}
			else
			{	
				printf("\u2b1c");
			}
		}
		
		printf("\n");
	}

}

void make_copy(generation* next, generation* previous)
{
	next -> r = previous -> r;
	next -> c = previous -> c;
	next -> nr = previous -> nr;

	for(int i = 0; i < next -> r; i++)
	{
		for(int j = 0; j < next -> c; j++)
		{
			next -> gen[i][j] = previous -> gen[i][j];
		}
	}
}

generation* fast(generation* previous, int count, neighbour how, char to_save, int how_many_to_save, int const_count, int saved, personal_choice* choice)
{
	generation* 	next 		= 	create_generation(previous -> r, previous -> c);
	int 		any_left;

	if(to_save == 'o') 
	{
		any_left = 1;
	}
	else if(to_save == 'f') 
	{
		any_left = how_many_to_save - saved;
	}

	for(int i = 0; i < count; i++)
	{
		print_generation(previous, "FAST", const_count);

		if(to_save == 'o' && (previous -> nr) == how_many_to_save)
		{
			save_generation(previous);
			any_left--;
		}
		else if(to_save == 'f' && (previous -> nr) <= how_many_to_save)
		{
                        save_generation(previous);
			any_left--;
		}

		make_copy(next, previous);
		new_gen(previous, how, choice); 

		if(the_same(next, previous))
		{
			printf("\n\n\t\tNext generations look the same as this one\n");

			if(any_left > 0)
                        {
                        	if(to_save == 'o')
                                {
                                	previous -> nr = how_many_to_save;
                                        save_generation(previous);
                                }
                                else if(to_save == 'f')
                                {
                                	for(int i = how_many_to_save - any_left + 1; i <= how_many_to_save; i++)
                                        {
                                        	previous -> nr = i;
                                                save_generation(previous);
                                        }
                                }
                        }

			break;
		}
		
		usleep(HOW_FAST);	
	}

	printf("\n\n");

	free_generation(next);

	return previous;
}

generation* sbs(generation* previous, int count, neighbour how, char to_save, int how_many_to_save, personal_choice* choice)
{

	generation* 	next 		= 	create_generation(previous -> r, previous -> c);
	char 		question	=	'0';
	int 		any_left	=	0;

	setbuf(stdin, NULL);

	if(to_save == 'o') 
	{
		any_left = 1;
	}
	else if(to_save == 'f') 
	{
		any_left = how_many_to_save;
	}

	for(int i = 0; i < count; i++)
	{	
		print_generation(previous, "SBS", count);

		if(to_save == 'o' && (previous -> nr) == how_many_to_save)
		{
			save_generation(previous);
			any_left--;
		}
		else if(to_save == 'f' &&  (previous -> nr) <= how_many_to_save)
		{
			save_generation(previous);
			any_left--;
		}

		if(i < count - 1)
		{
			printf("\n\n\t\tClick enter to continue or e to change SBS mode: ");

			while((question = getchar()) != '\n' && question != EOF)
			{	
				if(question == 'e')
				{
					break;
				}		
			}	
		}
		else 
		{
			printf("\n\n");
		}

		printf("\n");

		if(question == 'e')
		{
			new_gen(previous, how, choice);
			fast(previous, count - i - 1, how, to_save, how_many_to_save, count, how_many_to_save - any_left, choice);
			break;
		}
		else
		{
			make_copy(next, previous);
			new_gen(previous, how, choice);

			if(the_same(next, previous))
			{
				printf("\n\n\t\tNext generations look the same as this one\n");
				
				if(any_left > 0)
				{
					if(to_save == 'o')
					{
						previous -> nr = how_many_to_save;
						save_generation(previous);
					}
					else if(to_save == 'f')
					{
						for(int i = how_many_to_save - any_left + 1; i <= how_many_to_save; i++)
						{
							previous -> nr = i;
							save_generation(previous);
						}
					}
				}

				break;
			}
		}
	}

	free_generation(next);
		
	return previous;
}
