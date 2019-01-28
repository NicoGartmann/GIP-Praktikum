#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP04.h"
using namespace std;
using namespace cimg_library;
int main()
{
	gip_color c1;
	gip_color c2{ 10, 20, 30 };
	while (gip_window_not_closed())
	{
		gip_load_image("Campus_Eupener_Strasse.bmp");
		gip_get_color(gip_mouse_x(), gip_mouse_y(), c1);
		gip_draw_circle(gip_mouse_x(), gip_mouse_y(), 50, c1);
		gip_wait(300);
	}
	//system("PAUSE");
	return 0;
}