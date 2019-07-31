
#include "cuvi.h"
#include "cuviLib.h"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h> 
#include <iostream>
#include <fstream>

using namespace std;
using namespace cuviLib;

CuviColorOps::CuviColorOps(int w, int h) {
	width = w;
	height = h;
	inImgSize = w * h * sizeof(unsigned char);
	outImgSize = inImgSize * 3;
	CPUinputPitch = bytesPerPixel * width; // edit this only if CPU pitch is different than width of image in bytes

}

//Performs demosaic on input byte array and writes to output byte array
int CuviColorOps::DemosaicBytes(unsigned char %inData, unsigned char %outData) {

	CuviSize imgSize(width, height);
	inImgSize = width * height * sizeof(unsigned char);

	GetBytes(inData);

	//Create a CuviImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	
	status = cuvi::colorOperations::demosaicDFPD(image, output, sensorAlignment); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outData);
	Free();

	return 0;
}


int CuviColorOps::AutoColor(unsigned char %inData, unsigned char %outData) {

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inData);

	//Create a CuviImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::colorOperations::autoColor(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outData);
	Free();

	return 0;
}

int CuviColorOps::LowLight(unsigned char %inData, unsigned char %outData) {

	CuviSize imgSize(width,height);
	inImgSize = outImgSize;
	
	GetBytes(inData);

	//Create a CuviImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::colorOperations::lowlight(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outData);
	Free();

	return 0;
}