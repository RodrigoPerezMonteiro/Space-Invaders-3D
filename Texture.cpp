#include "Texture.h"
#include "ALL.h"

int num_texture=-1; //Counter to keep track of the last loaded texture

int Texture::LoadBitmap(char *filename)
{
	FILE * file;
	char temp;
	long i;

	BITMAPINFOHEADER infoheader;

	num_texture++; // The counter of the current texture is increased

	if( (file = fopen(filename, "rb"))==NULL)
	{
		cout << "Unable to open texture!!!" << endl;
		return (-1); // Open the file for reading
	}

	fseek(file, 18, SEEK_CUR);  // start reading width & height
	fread(&infoheader.biWidth, sizeof(int), 1, file);

	fread(&infoheader.biHeight, sizeof(int), 1, file);

	fread(&infoheader.biPlanes, sizeof(short int), 1, file);
	if (infoheader.biPlanes != 1) {
		cout << "Planes from " << filename << "is not 1: " << infoheader.biPlanes << endl;
		return 0;
	}

	// read the bpp
	fread(&infoheader.biBitCount, sizeof(unsigned short int), 1, file);
	if (infoheader.biBitCount != 24) {
		cout << "Bpp from " << filename << "is not 24: " << infoheader.biBitCount << endl;
		return 0;
	}

	fseek(file, 24, SEEK_CUR);

	// read the data.
	infoheader.data = (char *) malloc(infoheader.biWidth * infoheader.biHeight * 3);
	if (infoheader.data == NULL) {
		cout << "Error allocating memory for color-corrected image data" << endl;
		return 0;
	}

	if ((i = fread(infoheader.data, infoheader.biWidth * infoheader.biHeight * 3, 1, file)) != 1) {
		cout << "Error reading image data from " << filename << endl;
		return 0;
	}

	for (i=0; i<(infoheader.biWidth * infoheader.biHeight * 3); i+=3) { // reverse all of the colors. (bgr -> rgb)
		temp = infoheader.data[i];
		infoheader.data[i] = infoheader.data[i+2];
		infoheader.data[i+2] = temp;
	}


	fclose(file); // Closes the file stream

	cout << "Texture loaded..." << filename << endl;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, num_texture); // Bind the ID texture specified by the 2nd parameter

	//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x8370); // 0x8370 = GL_MIRRORED_REPEAT 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x8370);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // We don't combine the color with the original surface color, use only the texture map.

	// Finally we define the 2d texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, infoheader.biWidth, infoheader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, infoheader.data);

	// And create 2d mipmaps for the minifying function
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, infoheader.biWidth, infoheader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, infoheader.data);
	glDisable(GL_TEXTURE_2D);
	free(infoheader.data); // Free the memory we used to load the texture

	return (num_texture); // Returns the current texture OpenGL ID
}