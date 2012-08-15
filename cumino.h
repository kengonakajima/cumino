#ifndef _CUMINO_H_
#define _CUMINO_H_

#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#define EPSILON 0.000001 // from lumino

double now() ;
float len(float x0, float y0, float x1, float y1 );
void normalize( float *x, float *y, float l );

double range( double a, double b ) ;
double max( double a, double b );
double min( double a, double b );
    
bool neareq( double a, double b );

bool writeFile( const char *path, const char *data, size_t sz );
bool readFile( const char *path, const char *data, size_t *sz );


#endif
