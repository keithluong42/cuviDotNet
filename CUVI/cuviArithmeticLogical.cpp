
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
	outImgSize32f = outImgSize * 4;
	CPUinputPitch = bytesPerPixel * width; // edit this only if CPU pitch is different than width of image in bytes

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

int CuviArithmeticLogical::cbrt(unsigned char %inData, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::cbrt(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize * 4);
	status = output.download(outBytes, width * 12); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

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
	status = image.upload(inBytes1, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image * scalar;
	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	SetBytes(outImgBytes);
	Free();

	return 0;
}

int CuviArithmeticLogical::Img8to32(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	CuviSize imgSize(width,height);

	GetBytes(inImgBytes);

	CuviImage image;
	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	CuviImage output32f(image.size(),CUVI_DEPTH_32F,image.channels());
	image.setDataBits(8);	//Saying input image has 8bit depth
	output32f.setDataBits(32);

	status = cuvi::dataExchange::bitConversion(image, output32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	pin_ptr<unsigned char> outptr = &outImgBytes;

	output32f.download(outptr, (width * image.channels() * 4));
}
