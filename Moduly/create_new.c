#include <stdio.h>

#include "help_create.h"
#include "structures.h"

int personal_rules(int how_many_neighbours, int is_alive, personal_choice* choice)
{
	if(is_alive == 0 && how_many_neighbours == (choice -> comes_back))
        {
                return 1;
        }
        else if(is_alive == 1 && how_many_neighbours == (choice -> dies))
        {
                return 0;
        }
        else
        {
                return is_alive;
        }
}

int rules(int how_many_neighbours, int is_alive)
{
	if(is_alive == 0 && how_many_neighbours == 3)
	{
		return 1;		
	}
	else if(is_alive == 1 && (how_many_neighbours != 2 && how_many_neighbours != 3))
	{
		return 0;
	}
	else 
	{
		return is_alive;
	}
}

int population(generation* current_generation)
{
	int 	rows 			= 	current_generation -> r;
	int 	columns 		= 	current_generation -> c;
	int 	population_number 	= 	0;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(current_generation -> gen[i][j] == 1)
			{
				population_number += 1;
			}
		}
	}

	return population_number;
}

void new_gen(generation* old_generation, neighbour how, personal_choice* choice)
{
	int**	neighbourhood 		= 	create_neighbourhood(old_generation, how, choice);
	
	old_generation -> nr = (old_generation -> nr) + 1;

	for(int i = 0; i < old_generation -> r; i++)
	{
		for(int j = 0; j < old_generation -> c; j++)
		{
			if(how == Ps || how == Pf)
			{
				old_generation -> gen[i][j] = personal_rules(neighbourhood[i][j], old_generation -> gen[i][j], choice);
			}
			else
			{
				old_generation -> gen[i][j] = rules(neighbourhood[i][j], old_generation -> gen[i][j]);
			}
		}
	}

	free_neighbourhood(old_generation, neighbourhood);	
}
