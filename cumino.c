/*
  lumino, rumino, jumino, cumino
 */

#include "cumino.h"


double now() {
    struct timeval tmv;
    gettimeofday( &tmv, NULL );
    return tmv.tv_sec  + (double)(tmv.tv_usec) / 1000000.0f;
}

float len(float x0, float y0, float x1, float y1 ){
    return sqrt( (x1-x0)*(x1-x0)+ (y1-y0)*(y1-y0));
}

void normalize( float *x, float *y, float l ) {
    float ll = len(0,0,*x,*y);
    if(ll==0){
        *x=0; *y=0;
    } else {
        *x = *x / ll * l;
        *y = *y / ll * l;    
    }
}

double max( double a, double b ){
    return  (a>b) ? a:b;
}
double min( double a, double b ){
    return (a<b) ? a:b;
}

double range( double a, double b ) {
    long r = random();
    double rate = (double)r / (double)(0x7fffffff);
    double _a = min(a,b);
    double _b = max(a,b);
    return _a + (_b-_a)*rate;
}

bool writeFile( const char *path, const char *data, size_t sz ){
    FILE *fp = fopen( path, "wb");
    if(!fp){
        fprintf(stderr, "cannot open file:'%s'",path);
        return false;
    }
    fwrite( data, 1, sz, fp );
    fclose(fp);
    return true;
}
bool readFile( const char *path, const char *data, size_t *sz ){

    size_t toread = *sz;
    FILE *fp = fopen( path, "rb");
    if( !fp){
        //みつからないこと前提で読むことも多いのでログしない        std::cerr << "readFile: error:" << path << std::endl;
        return false;
    }
    size_t rsz = fread( (void*)data, 1, toread, fp );
    fclose(fp);
    *sz = rsz;
    return true;
}

bool neareq( double a, double b ) {
    return( abs(a-b) < EPSILON );
}
