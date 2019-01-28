#include"sort.h"
void sortiere(int a[], const int i)
{
	for (int j = 1; j <= i - 1; j++)
	{
			int g = a[j], h = j;
			while (h > 0 && a[h - 1] > g)
			{
				a[h] = a[h - 1];
				h = h - 1;
			}

			a[h] = g;
	}
}