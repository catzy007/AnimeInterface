#ifndef MYBATMAX_H_INCLUDED
#define MYBATMAX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define boolean unsigned int
#define true 1
#define false 0

typedef struct{
	int MyWidth;
	int MyHeight;
	int MySignal;
	int IsAnimation;
}MyWindow;

int MyBatPercVal(void);
int MyBatPrecMax(int max);
int MyBatPrecMin(int min);
int MyBatState(void);

#endif
