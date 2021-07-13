#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <imagehlp.h>

int main ( int argc, char **argv ) {
	const char *filename;
	BOOL ok;
	LOADED_IMAGE image;
	DWORD err;
	int i;

	/* Sanity check */
	if ( argc < 2 ) {
		fprintf ( stderr, "Syntax: %s <image> [<image>...]\n",
			  argv[0] );
		exit ( 2 );
	}

	/* Check each image */
	for ( i = 1 ; i < argc ; i++ ) {
		filename = argv[i];
		printf ( "%s... ", filename );
		ok = MapAndLoad ( filename, NULL, &image, FALSE, TRUE );
		if ( ! ok ) {
			err = GetLastError();
			printf ( "failed (error %#x)\n", err );
			exit ( 1 );
		}
		printf ( "ok\n" );
		UnMapAndLoad ( &image );
	}

	return 0;
}
