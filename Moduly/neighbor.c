#include "neighbor.h"

int personal_flat_world(generation* world_generation, int row, int column, personal_choice* choice)
{

	int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
        
	for(int i = 0; i < (choice -> personal_neighbours); i++)
	{	
		if(row != 0 && (choice -> neighbours_indexes[i]) == 2)	
		{
			neighbours += world_generation -> gen[row - 1][column];         
		}
		else if(row != r - 1 && (choice -> neighbours_indexes[i]) == 7)        
		{
			neighbours += world_generation -> gen[row + 1][column];         
		}
		else if(column != 0 && (choice -> neighbours_indexes[i]) == 4)	
		{
			neighbours += world_generation -> gen[row][column - 1];         
		}
		else if(column != c - 1 && (choice -> neighbours_indexes[i]) == 5) 	
		{
			neighbours += world_generation -> gen[row][column + 1];         
		}
		else if(row != 0 && column != c - 1 && (choice -> neighbours_indexes[i]) == 3)        
		{
			neighbours += world_generation -> gen[row - 1][column + 1];     
		}
		else if(row != 0 && column != 0 && (choice -> neighbours_indexes[i]) == 1)
		{
			neighbours += world_generation -> gen[row - 1][column - 1];     
		}
		else if(row != r - 1 && column != c - 1 && (choice -> neighbours_indexes[i]) == 8)        
		{
			neighbours += world_generation -> gen[row + 1][column + 1];     
		}
		else if(row != r - 1 && column != 0 && (choice -> neighbours_indexes[i]) == 6)
		{
			neighbours += world_generation -> gen[row + 1][column - 1];     
		}
	}

	return neighbours;
}

int personal_sphere_world(generation* world_generation, int row, int column, personal_choice* choice)
{
	int     neighbours      =       0;
        int     c               =       world_generation -> c;
        int     r               =       world_generation -> r;
	 
	for(int i = 0; i < (choice -> personal_neighbours); i++)
	{
		if((choice -> neighbours_indexes[i]) == 2)
		{
        		neighbours += world_generation -> gen[(row + r - 1) % r][column];
		}
		else if((choice -> neighbours_indexes[i]) == 7)
		{
			neighbours += world_generation -> gen[(row + r + 1) % r][column];
		}
		else if((choice -> neighbours_indexes[i]) == 4)
		{
			neighbours += world_generation -> gen[row][(column + c - 1) % c];
		}
		else if((choice -> neighbours_indexes[i]) == 5)
		{
			neighbours += world_generation -> gen[row][(column + c + 1) % c];
		}
		else if((choice -> neighbours_indexes[i]) == 3)
		{
			neighbours += world_generation -> gen[(row + r - 1) % r][(column + c + 1) % c];
		}
		else if((choice -> neighbours_indexes[i]) == 1)
		{
			neighbours += world_generation -> gen[(row + r - 1) % r][(column + c - 1) % c];
        	}
		else if((choice -> neighbours_indexes[i]) == 8)
		{
			neighbours += world_generation -> gen[(row + r + 1) % r][(column + c + 1) % c];
		}
		else if((choice -> neighbours_indexes[i]) == 6)
		{
			neighbours += world_generation -> gen[(row + r + 1) % r][(column + c - 1) % c];
		}
	}

	return neighbours;
}

int moore_sphere_world(generation* world_generation, int row, int column)
{       
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r	 	= 	world_generation -> r;

        neighbours += world_generation -> gen[(row + r - 1) % r][column];                  
        neighbours += world_generation -> gen[(row + r + 1) % r][column];                 
        neighbours += world_generation -> gen[row][(column + c - 1) % c];                
        neighbours += world_generation -> gen[row][(column + c + 1) % c];               
        neighbours += world_generation -> gen[(row + r - 1) % r][(column + c + 1) % c];
        neighbours += world_generation -> gen[(row + r - 1) % r][(column + c - 1) % c];
        neighbours += world_generation -> gen[(row + r + 1) % r][(column + c + 1) % c];
        neighbours += world_generation -> gen[(row + r + 1) % r][(column + c - 1) % c];

        return neighbours;

}       

int moore_flat_world(generation* world_generation, int row, int column)
{
	int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
        	
	if(row != 0)	
	{
		neighbours += world_generation -> gen[row - 1][column];         
	}
	else if(row != r - 1)        
	{
		neighbours += world_generation -> gen[row + 1][column];         
	}
	else if(column != 0)	
	{
		neighbours += world_generation -> gen[row][column - 1];         
	}
	else if(column != c - 1) 	
	{
		neighbours += world_generation -> gen[row][column + 1];         
	}
	else if(row != 0 && column != c - 1)        
	{
		neighbours += world_generation -> gen[row - 1][column + 1];     
	}
	else if(row != 0 && column != 0)	
	{
		neighbours += world_generation -> gen[row - 1][column - 1];     
	}	
	else if(row != r - 1 && column != c - 1)        
	{
		neighbours += world_generation -> gen[row + 1][column + 1];     
	}
	else if(row != r - 1 && column != 0)
	{
		neighbours += world_generation -> gen[row + 1][column - 1];     
	}

	return neighbours;
}

int neumann_sphere_world(generation* world_generation, int row, int column)
{
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
	
	neighbours += world_generation -> gen[(row + r - 1) % r][column];       
        neighbours += world_generation -> gen[(row + r + 1) % r][column];       
        neighbours += world_generation -> gen[row][(column + c - 1) % c];       
        neighbours += world_generation -> gen[row][(column + c + 1) % c];       

        return neighbours;
}

int neumann_flat_world(generation* world_generation, int row, int column)
{
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
	
	if(row != 0)
	{
                neighbours += world_generation -> gen[row - 1][column];         
	}
	else if(row != r - 1)
	{
		neighbours += world_generation -> gen[row + 1][column]; 
	}
	else if(column != 0)
	{
		neighbours += world_generation -> gen[row][column - 1]; 
	}
	else if(column != c - 1)
	{
 		neighbours += world_generation -> gen[row][column + 1]; 
	}

        return neighbours;
}
