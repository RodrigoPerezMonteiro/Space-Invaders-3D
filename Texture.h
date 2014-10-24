#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
	int num_texture;

	typedef struct                       /**** BMP file info structure ****/
	{
		unsigned int   biSize;           /* Size of info header */
		int            biWidth;          /* Width of image */
		int            biHeight;         /* Height of image */
		unsigned short biPlanes;         /* Number of color planes */
		unsigned short biBitCount;       /* Number of bits per pixel */
		unsigned int   biCompression;    /* Type of compression to use */
		unsigned int   biSizeImage;      /* Size of image data */
		int            biXPelsPerMeter;  /* X pixels per meter */
		int            biYPelsPerMeter;  /* Y pixels per meter */
		unsigned int   biClrUsed;        /* Number of colors used */
		unsigned int   biClrImportant;   /* Number of important colors */
		char *data;
	} BITMAPINFOHEADER;

public:
	int LoadBitmap(char *filename);
};

#endif