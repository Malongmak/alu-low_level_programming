#include "main.h"
/*function that frees a 2 dimensional grid previously*/
/*created by your alloc_grid function.*/
/**
 * free_grid - function
 * @grid: first parameter
 * @height: second parameter
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int a;

	for (a = 0; a < height; a++)
	{
		free(grid[a]);
	}
	free(grid);
}
