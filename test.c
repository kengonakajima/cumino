#include "cumino.h"

int main(int argc, char **argv ) {

    double nt = now();
    assert( nt > time(NULL));
    printf( "now:%f\n", nt );

    float l = len(1,1,2,2);
    assert( neareq( l, sqrt(2)));

    float x=2,y=2;
    normalize( &x, &y, 1 );
    assert( neareq( x, sqrt(2)/2));
    assert( neareq( y, sqrt(2)/2));

    assert( max(1,2)==2);
    assert( max(2,1)==2);
    assert( max(-1,-2)==-1);
    assert( max(-2,-1)==-1);    

    assert( min(1,2)==1);
    assert( min(2,1)==1);
    assert( min(-1,-2)==-2);
    assert( min(-2,-1)==-2);    

    for(int i=0;i<100000;i++){
        double r = range( 0,100.0 );
        assert( r >=0 );
        assert( r < 100.0 );
    }

    assert( writeFile( "/tmp/cuminotest", "hoge", 4 ) );
    char buf[100];
    size_t sz=4;
    assert( readFile( "/tmp/cuminotest", buf, &sz ));
    assert( sz==4);
    assert(buf[0]=='h');
    assert(buf[1]=='o');
    assert(buf[2]=='g');
    assert(buf[3]=='e');

    printf("test OK\n");
    return 0;
}
