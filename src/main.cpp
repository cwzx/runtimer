#include <windows.h>
#include <cstdio>

#pragma comment( lib, "kernel32" )

int main( int argc, char** argv ) {

	LARGE_INTEGER old_count, new_count, freq;

	QueryPerformanceFrequency( &freq );

	QueryPerformanceCounter( &old_count );

	system( argv[1] );

	QueryPerformanceCounter( &new_count );

	double secs = double( new_count.QuadPart - old_count.QuadPart ) / double( freq.QuadPart );
	
	auto hours = secs / 360.0;
	auto mins = secs / 60.0;
	auto milli = secs * 1000.0;
	auto micro = secs * 1000000.0;

	if( hours >= 1.0 ) {
		printf( "Hours: %.4f\n", hours );
	} else if( mins >= 1.0 ) {
		printf( "Minutes: %.4f\n", mins );
	} else if( secs >= 1.0 ) {
		printf( "Seconds: %.4f\n", secs );
	} else if( milli >= 1.0 ) {
		printf( "Milliseconds: %.4f\n", milli );
	} else {
		printf( "Microseconds: %.4f\n", micro );
	}

}
