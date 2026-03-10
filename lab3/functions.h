#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef double (*FuncType)(double);

double y(double x, int n);
void printTable(double start, double end, double step, FuncType f);

#endif