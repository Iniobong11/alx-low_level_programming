#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid array
 * @grid: 2 dimensional grid
 * @height: height of the grid dimension
 */
void free_grid(int **grid, int height)
{
	int x;

	for (x = 0; x < height; x++)
		free(grid[x]);
	free(grid);
}
