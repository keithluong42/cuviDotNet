
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

CuviImageStats::CuviImageStats(int w, int h, int numChannels) {
	width = w;
	height = h;
	inImgSize = width * height * sizeof(unsigned char);
	outImgSize = inImgSize * numChannels;
	CPUinputPitch = bytesPerPixel * width * numChannels;
}

//Calculates histogram values of an image to display and fills a buffer of int values.
int CuviImageStats::CalcHist(unsigned char %inImgBytes, unsigned int %histResult) {

	CuviSize imgSize(width, height);
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
int CuviImageStats::GetHistSize(unsigned char %inImgBytes) {
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