
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

CuviArithmeticLogical::CuviArithmeticLogical(int w, int h) {
	width = w;
	height = h;
	inImgSize = width * height * sizeof(unsigned char);
	outImgSize = inImgSize * 3;
	outImgSize32f = outImgSize * 12;
	CPUinputPitch = bytesPerPixel * width; // edit this only if CPU pitch is different than width of image in bytes
	usingFloats = false;
}

int CuviArithmeticLogical::Abs(unsigned char %inData, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::abs(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();
	return 0;
}

int CuviArithmeticLogical::AbsDiff(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::absDiff(image1,image2,output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::Add(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 + image2;
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::cbrt(unsigned char %inData, unsigned char %outImgBytes, bool floatOut) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	CuviImage	image32f(image.size(), CUVI_DEPTH_32F, image.channels()), 
				output(image.size(), CUVI_DEPTH_8U, image.channels());
	
	status = cuvi::arithmeticLogical::cbrt(image, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (floatOut) {
		outBytes = (unsigned char*)malloc(outImgSize * 4);
		status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	}
	status = cuvi::dataExchange::convertScale(image32f, output, 1.0f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();
	return 0;
}

int CuviArithmeticLogical::NOT(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::NOT(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();
	return 0;
}

int CuviArithmeticLogical::AND(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 & image2;
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::Multiply(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::multiply(image1, image2, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::Multiply(unsigned char %img1, int scalar, unsigned char %outImgBytes) {

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1);

	//Create CuviImages and fill with data
	CuviImage image, output;
	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image * scalar;
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::Divide(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::divide(image1, image2, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

//Calculate exponential value of each pixel
int CuviArithmeticLogical::Exp(unsigned char %inImgBytes, unsigned char %outImgBytes, bool floatOut) {
	CuviSize imgSize(width, height);

	if(usingFloats)
		inImgSize = outImgSize32f;
	else
		inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, image32f;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::exp(image, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (floatOut) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize * 4);
		status = image32f.download(outBytes, CPUinputPitch * 12); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		memcpy(outPtr,outBytes,outImgSize * 4);
	}
	else {
		CuviImage output(image.size(), CUVI_DEPTH_8U, image.channels());
		status = cuvi::dataExchange::convertScale(image32f, output, 1.0f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	
	Free();
	return 0;
}

//Use this to use float values for calculation functions (ie float imgbuffer input)
void CuviArithmeticLogical::UseFloats(bool set) {
	if (set == true) {
		this->containerBits = 32;
		this->bytesPerPixel = 4;
		this->CPUinputPitch = this->bytesPerPixel * width;
	}
	else {
		this->containerBits = 8;
		this->bytesPerPixel = 1;
		this->CPUinputPitch = this->bytesPerPixel * width;	
	}
	
}

bool CuviArithmeticLogical::IsUsingFloats(){return usingFloats;}