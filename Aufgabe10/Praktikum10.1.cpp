#include <iostream> 
#define CIMGGIP_MAIN 
#include "CImgGIP03.h" 
using namespace std;


struct Box { int x;  int y;  int delta_y; };

// Die Größe jedes Kästchens (Quadrat => Länge == Breite) ... 
const int box_size = 50;

// Wieviele Kästchen passen nebeneinander ins Fenster, 
// bei Kästchengröße box_size und 20 Pixel Zwischenraum 
// zwischen den Kästchen ... 
const int box_max = gip_win_sizeX / (box_size + 20);
// Maximale Fallgeschwindigkeit (in Pixel pro Bildschirmupdate) ... 
const int box_max_delta_y = 90;

// prepare_box_at_top(): 
// Kästchen Nr. "count" am oberen Bildschirmrand "starten".  
// Fälle: // 1. Zu Beginn des Spiels 
// 2. Neustart (nach dem Anklicken), mit erhöhter Geschwindigkeit 
void prepare_box_at_top(Box &b, int count)
{
	// Setze b.x und b.y für das Kästchen ... 
	b.x = count * (box_size + 20) + 10;
	b.y = 0;
	// ... Boxen starten immer auf Höhe b.y = 0 

	// Wenn die Box bisher schon eine Fallgeschwindigkeit hatte  
	// (b.delta_y > 0 , denn Fallgeschw ==  0 bedeutet:   
	//  die Box existierte bisher noch nicht),  
	// und diese Fallgeschwindigkeit noch nicht maximal war,  
	// so erhöhe die Fallgeschwindigkeit um 10 ...  
	if (b.delta_y > 0 && b.delta_y < box_max_delta_y)
		b.delta_y += 10;
	// sonst: setze Fallgeschw auf Zufallswert
	else
		b.delta_y = gip_zufall(20, box_max_delta_y / 2);
}

// draw_boxes(): 
// Zeichne die Kästchen boxes[0] bis boxes[box_max] ... 
void draw_boxes(Box boxes[])
{
	// Lösche den bisherigen Fensterinhalt komplett, 
	// d.h. komplettes Neuzeichnen aller Kästchen etc ...  
	gip_white_background();

	// Und jetzt alle Kästchen zeichnen.  
	// Linke obere Ecke: 
	for (int i = 0; i < box_max; i++)
	{

		gip_canvas.draw_rectangle(boxes[i].x, boxes[i].y, boxes[i].x + box_size, boxes[i].y + box_size, blue);

	}
	// Größe: box_size x box_size  
	// Farbe: blue  … 
}

// update_boxes(): // 1. Berechne neue y-Koordinate (Box boxes[i] fällt um boxes[i].delta_y) 
// 2. Prüfe, ob eine Box das untere Fensterende gip_win_sizeY überschritten 
//    hat. Falls ja: gib sofort false zurück 
// 3. (Sonst:) Rufe draw_boxes() auf, gib true zurück 
bool update_boxes(Box boxes[])
{
	// Koordinaten updaten ... 

	for (int i = 0; i < box_max; i++)
	{
		boxes[i].y += boxes[i].delta_y;
		if (boxes[i].y  > gip_win_sizeY)
			return false;
	}

	draw_boxes(boxes);
	return true;


}
// Wenn Box am unteren Ende "rausgefallen",  
// dann gib false zurück ...   

// check_if_box_clicked(): // Annahme: Funktion wird nur aufgerufen, wenn die Maus wirklich 
// geklickt wurde. Die Funktion braucht dies also nicht mehr zu prüfen. 
// Nimm die Koordinaten der Mausposition und prüfe dann für jede Box, 
// ob die Koordinaten innerhalb der Box liegen. Falls ja, rufe für diese  
// Box dann prepare_box_at_top() auf. 
void check_if_box_clicked(Box boxes[])
{
	int mx = gip_mouse_x();
	int my = gip_mouse_y();
	for (int i = 0; i < box_max; i++)
	{

		if (mx >= boxes[i].x && mx <= boxes[i].x + box_size &&my >= boxes[i].y && my <= boxes[i].y + box_size)
			prepare_box_at_top(boxes[i], i);

	}
}

int main()
{
	Box boxes[box_max] = { 0 };
	bool keep_going = true;

	for (int i = 0; i < box_max; i++)
		prepare_box_at_top(boxes[i], i);

	draw_boxes(boxes);

	while (keep_going && gip_window_not_closed())
	{
		for (int loop_count = 0; loop_count < 200; loop_count++)
		{
			gip_wait(5);

			if (gip_mouse_button1_pressed())
				check_if_box_clicked(boxes);
		}

		keep_going = update_boxes(boxes);
	}

	return 0;
}
