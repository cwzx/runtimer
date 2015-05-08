#include <windows.h>
#include <cstdio>

#pragma comment( lib, "kernel32" )

void print( double secs ) {
	static constexpr double threshold = 1.0;
	auto hours = secs / 360.0;
	auto mins = secs / 60.0;
	auto milli = secs * 1.0e3;
	auto micro = secs * 1.0e6;
	auto nano = secs * 1.0e9;

	if( hours >= threshold ) {
		printf( "%.4f hours", hours );
	} else if( mins >= threshold ) {
		printf( "%.4f mins", mins );
	} else if( secs >= threshold ) {
		printf( "%.4f s", secs );
	} else if( milli >= threshold ) {
		printf( "%.4f ms", milli );
	} else if( micro >= threshold ) {
		printf( "%.4f us", micro );
	} else {
		printf( "%.4f ns", nano );
	}
}

int main( int argc, char** argv ) {

	if( argc < 2 ) return 0;

	LARGE_INTEGER old_count, new_count, freq;

	QueryPerformanceFrequency( &freq );

	QueryPerformanceCounter( &old_count );

	system(argv[1]);

	QueryPerformanceCounter( &new_count );

	double secs = double( new_count.QuadPart - old_count.QuadPart ) / double( freq.QuadPart );
	
	printf("\nTime: ");
	print(secs);
	printf("\n");

}
