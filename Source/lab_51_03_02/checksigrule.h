#ifndef CHECKSIGRULE_H
#define CHECKSIGRULE_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define YES 1
#define NO 0
#define NOT_ENOUGH_PARAM -1
#define NO_FILE -2
#define INCOR_CONTENT -3

#define NORM_PROB 0.9973


double get_am(FILE *f, long *len);
double get_disp(FILE *f, double am, long len);
long check_seq_sigg_rule(FILE *f);


#endif