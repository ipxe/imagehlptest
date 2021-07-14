#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <imagehlp.h>

static BOOL check_map_and_load ( const char *filename ) {
	LOADED_IMAGE image;

	/* Test ability to MapAndLoad() */
	if ( ! MapAndLoad ( filename, NULL, &image, FALSE, TRUE ) ) {
		fprintf ( stderr, "%s: failed MapAndLoad() with error %#x\n",
			  filename, GetLastError() );
		return FALSE;
	}

	/* Free resources */
	UnMapAndLoad ( &image );

	return TRUE;
}

static BOOL check_image ( const char *filename ) {
	BOOL ok;

	/* Check MapAndLoad() */
	if ( ! check_map_and_load ( filename ) )
		return FALSE;

	return TRUE;
}

int main ( int argc, char **argv ) {
	const char *filename;
	BOOL ok;
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
		ok = check_image ( filename );
		if ( ! ok )
			exit ( 1 );
		printf ( "%s: ok\n", filename );
	}

	return 0;
}
