#include <iostream> 
#define CIMGGIP_MAIN 
#include "CImgGIP05.h"
using namespace std; 
using namespace cimg_library;

int main()
{
	struct color_backup { int x, y; int R, G, B; };



	//int gip_random(int low, int high)generiert eine ganzzahlige Zufallszahl im Bereich zwischen low und high.;
	const unsigned int max_number = 50000;
	color_backup my_array[max_number];

	gip_load_image("Campus_Eupener_Strasse.bmp");
	gip_stop_updates();

	// Phase 1 ... 


	for (int i = 0; i < max_number; i++)
	{
		my_array[i].x = gip_random(0, gip_win_size_x - 1);
		my_array[i].y = gip_random(0, gip_win_size_y - 1);
		my_array[i].R = gip_get_red(my_array[i].x, my_array[i].y);
		my_array[i].G = gip_get_green(my_array[i].x, my_array[i].y);
		my_array[i].B = gip_get_blue(my_array[i].x, my_array[i].y);
	}
	// Phase 2 ... 
	for (int i = 0; i < max_number; i++)
	{
		gip_color col{ my_array[i].R , my_array[i].G, my_array[i].B };

		gip_canvas.draw_circle(my_array[i].x, my_array[i].y, 5, col);
	}

	gip_start_updates();
	system("pause");
	return 0;
}
