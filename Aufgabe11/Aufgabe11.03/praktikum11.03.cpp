#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP04.h"
using namespace std;
using namespace cimg_library;
int main()
{
	const int box_size = 30; // ... Groesse der einzelnen Kaestchen
	const int border = 20; // ... Rand links und oben bis zu den ersten Kaestchen
	const int grid_size = 10;
	int grid[grid_size][grid_size] = { 0 };
	int next_grid[grid_size][grid_size] = { 0 };
	
	// Erstes Spielfeld vorbelegen (per Zufallszahlen) ...
	for (int x = 0; x < grid_size; x++)
	{
		for (int y = 0; y < grid_size; y++)
		{
			grid[x][y] = gip_random(0, 1); //jedem element wird ein zufallswert zugewiesen, 0 oder 1
		}
	}
	while (gip_window_not_closed())
	{
		// Spielfeld anzeigen ...
		//gip_stop_updates();
		// ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				if (grid[x][y] == 1)
					gip_draw_rectangle(border + y*box_size, border + x*box_size, (border + y*box_size) + box_size, (border + x*box_size) + box_size, green);
				else
					gip_draw_rectangle(border + y*box_size, border + x*box_size, (border + y*box_size) + box_size, (border + x*box_size) + box_size, white);
			}
		}
		//gip_start_updates();
		//gip_sleep(3);
		// Berechne das naechste Spielfeld ...
		// Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
		// mit in die Betrachtungen einbezogen werden.
		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...
		// ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				int counter = 0; 
				for (int x1 = x - 1; x1 <= x + 1; x1++)
					for (int y1 = y - 1; y1 <= y + 1; y1++)
					{
						if (x1 >= 0 && x1 <= grid_size && y1 >= 0 && y1 <= grid_size)
						{
							if (grid[x1][y1] == 1)
								counter++;
						}
					}
				if (grid[x][y] == 1) counter--;
				if (counter == 3 && grid[x][y] == 0) next_grid[x][y] = 1; 
				else if ((counter == 2 || counter == 3) && grid[x][y] == 1) next_grid[x][y] = 1; 
			}
			
		}
		// Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...
		// ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				grid[x][y] = next_grid[x][y];
				next_grid[x][y] = 0;
			}
		}

	}
	return 0;
}