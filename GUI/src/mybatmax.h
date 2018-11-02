#ifndef MYBATMAX_H_INCLUDED
#define MYBATMAX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	gint MyWidth;
	gint MyHeight;
	gint MySignal;
	gint IsAnimation;
}MyWindow;

int MyBatPrecMax(int max);
int MyBatPrecMin(int min);
int MyBatState();

#endif
