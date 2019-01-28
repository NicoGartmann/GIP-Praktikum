#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP04.h"
using namespace std;
using namespace cimg_library;

int main()
{
	int x = 0;
	int y = 0;
	while (gip_window_not_closed())
	{ 
		gip_stop_updates(); 
		gip_load_image("Campus_Eupener_Strasse.bmp"); 
		
		gip_color c1;
		gip_color c2{ 0,0,0 };
		for (x = 0; x < gip_win_size_x; x++)
		{
			for (y=0; y < gip_win_size_y; y++)
			{
				if (gip_distance(x, y, gip_mouse_x(), gip_mouse_y())>100)
				{
					gip_set_color(x, y, c2); 
				}
				else 
				{
					gip_set_grey(x, y, gip_get_grey(x, y));
				}
			}
		}
		gip_start_updates(); 
		gip_wait(300);
	}
	return 0;
}