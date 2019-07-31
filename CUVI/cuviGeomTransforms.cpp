
#include "cuvi.h"
#include "cuviLib.h"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h> 
#include <iostream>
#include <fstream>

using namespace cuviLib;
using namespace std;

CuviGeometryTransform::CuviGeometryTransform(int w, int h) {
	width = w;
	height = h;
	inImgSize = width * height * sizeof(unsigned char);
	outImgSize = inImgSize * 3;
	CPUinputPitch = bytesPerPixel * width; // edit this only if CPU pitch is different than width of image in bytes
}

int CuviGeometryTransform::Crop(unsigned char %src, unsigned char %dest, int top, int bottom, int left, int right, int size) {
	CuviSize imgSize(width,height);
	inImgSize = size;
	
	GetBytes(src);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	//image.show();
	status = cuvi::geometryTransforms::crop(image, output, top, bottom, left, right); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	//Breaks here
	cuvi::io::saveImage(output, "C:/Program Files/cuvi/1.5.5/tests/datasets/resized.jpg");
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(dest);
	Free();
	return 0;
}