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

int CUVI::CalcHist(unsigned char %inImgBytes, unsigned int %histResult) {

	CuviSize imgSize(width,height);
	unsigned int *histArr;
	GetBytes(inImgBytes);
	
	////Check that an image exists
	//if(outBytes == NULL)
	//	return -1;

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


int CUVI::FFT2D(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output, fft;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	cuvi::dataExchange::getChannel(image, output, 0);
	status = cuvi::imageTransforms::fft2(output,fft); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();
	return 0;
}


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