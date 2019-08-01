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

CUVI::CUVI() {
	sensorAlignment = CuviBayerSeq::CUVI_BAYER_RGGB;
	containerBits = 8;
	bytesPerPixel = containerBits / 8;
}

//Calculates histogram values of an image to display and fills a buffer of int values.
int CUVI::CalcHist(unsigned char %inImgBytes, unsigned int %histResult) {

	CuviSize imgSize(width,height);
	unsigned int *histArr;
	GetBytes(inImgBytes);

	CuviImage histImg;
	status = histImg.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = histImg.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	

	CuviHistogram hist(histImg.type());

	status = cuvi::imageStatistics::calcHist(histImg, hist); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	histArr = hist.hist();

	pin_ptr<unsigned int> outPtr = &histResult;
	memcpy(outPtr, histArr, (histBinCount * sizeof(unsigned int)));
	
	return 0;
}

//Returns int buffer size required to hold histogram values
int CUVI::GetHistSize(unsigned char %inImgBytes) {
	CuviSize imgSize(width, height);
	GetBytes(inImgBytes);
	
	CuviImage histImg;
	status = histImg.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = histImg.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	CuviHistogram hist(histImg.type());
	cuvi::imageStatistics::calcHist(histImg, hist); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	histBinCount = hist.binCount();

	return histBinCount;
}

//Fast Fourier Transform
int CUVI::FFT2D(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, channelImage, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	//Getting one channel to generate the fft
	status = cuvi::dataExchange::getChannel(image, channelImage, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = cuvi::imageTransforms::fft2(channelImage, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();
	return 0;
}

//Adjust the size of the image
void CUVI::SetSize(int w, int h){
	width = w;
	height = h;
	inImgSize = w * h * sizeof(unsigned char);
	outImgSize = 3 * inImgSize;
	CPUinputPitch = bytesPerPixel * width; 
}


//Import image byte array
void CUVI::GetBytes(unsigned char %inImgBytes) {
	pin_ptr<unsigned char> data = &inImgBytes;

	inBytes = (unsigned char*)malloc(inImgSize);
	memcpy(inBytes, (unsigned char*)data, inImgSize);
}

void CUVI::GetBytes(unsigned char %inImgBytes1, unsigned char %inImgBytes2, int length) {
	pin_ptr<unsigned char> data = &inImgBytes1;
	inImgSize = length;

	inBytes1 = (unsigned char*)malloc(inImgSize);
	memcpy(inBytes1, (unsigned char*)data, inImgSize);


	data = &inImgBytes2;
	inBytes2 = (unsigned char*)malloc(inImgSize);
	memcpy(inBytes2, (unsigned char*)data, inImgSize);
}

void CUVI::GetBytes(unsigned char %inImgBytes, int length) {
	pin_ptr<unsigned char> data = &inImgBytes;
	inBytes = (unsigned char*)malloc(length);
	inImgSize = length;
	memcpy(inBytes, (unsigned char*)data, inImgSize);
}

void CUVI::GetBytes(unsigned char %inImgBytes1, unsigned char %inData2) {
	pin_ptr<unsigned char> data = &inImgBytes1;

	inBytes1 = (unsigned char*)malloc(inImgSize);
	memcpy(inBytes1, (unsigned char*)data, inImgSize);


	data = &inData2;
	inBytes2 = (unsigned char*)malloc(inImgSize);
	memcpy(inBytes2, (unsigned char*)data, inImgSize);
}


//Export image byte array
void CUVI::SetBytes(unsigned char %outImgBytes) {
	pin_ptr<unsigned char> data = &outImgBytes;

	memcpy(data, outBytes, outImgSize);
}

void CUVI::Free() {
	if (inBytes != NULL) {
		free(inBytes);
		inBytes = NULL;
	}
	if (inBytes1 != NULL) {
		free(inBytes1);
		inBytes1 = NULL;
	}
	if (inBytes2 != NULL) {
		free(inBytes2);
		inBytes2 = NULL;
	}
	if (outBytes != NULL) {
		free(outBytes);
		outBytes = NULL;
	}
}