
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
	usingFloats = false;
}

int CuviArithmeticLogical::Abs(unsigned char %inData, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::abs(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}

	Free();
	return 0;
}

int CuviArithmeticLogical::AbsDiff(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::absDiff(image1,image2,output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}

	Free();

	return 0;
}

int CuviArithmeticLogical::Add(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 + image2;

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	Free();

	return 0;
}

int CuviArithmeticLogical::Add(unsigned char %inImageBytes, double val, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inImageBytes);

	//Create CuviImages and fill with data
	CuviImage image, output;
	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	cuvi::arithmeticLogical::add(image, val, output);

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	Free();

	return 0;
}

int CuviArithmeticLogical::cbrt(unsigned char %inData, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	CuviImage	image32f(image.size(), CUVI_DEPTH_32F, image.channels());
	
	status = cuvi::arithmeticLogical::cbrt(image, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = image32f.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
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

int CuviArithmeticLogical::Ceil(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	if(!usingFloats)
		return -1;
	
	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::ceil(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	pin_ptr<unsigned char> outPtr = &outImgBytes;
	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::Floor(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
if (!usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::floor(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	pin_ptr<unsigned char> outPtr = &outImgBytes;
	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::NOT(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	if (usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::NOT(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }


	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);


	Free();
	return 0;
}

int CuviArithmeticLogical::AND(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	if (usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 & image2;

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);
	
	Free();
	return 0;
}

int CuviArithmeticLogical::XOR(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	if (usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 ^ image2;

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::OR(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	if(usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image1 | image2;

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);
	
	Free();
	return 0;
}

int CuviArithmeticLogical::Pow(unsigned char %inImgBytes, long power, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, image32f;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::pow(image, power, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = image32f.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
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

int CuviArithmeticLogical::Round(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	if(!usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::round(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }


	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::SHL(unsigned char %inImgBytes, int val, unsigned char %outImgBytes) {
	
	if(usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::SHL(image, val, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::SHR(unsigned char %inImgBytes, int val, unsigned char %outImgBytes) {

	if (usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::SHR(image, val, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	outBytes = (unsigned char*)malloc(outImgSize);
	status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetBytes(outImgBytes);

	Free();
	return 0;
}

int CuviArithmeticLogical::Sqrt(unsigned char %inData, unsigned char %outImgBytes) {

	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inData);

	//Create a CuvuImage and fill it with data
	CuviImage image;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	CuviImage	image32f(image.size(), CUVI_DEPTH_32F, image.channels());

	status = cuvi::arithmeticLogical::sqrt(image, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = image32f.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
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

int CuviArithmeticLogical::Subtract(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	cuvi::arithmeticLogical::subtract(image1, image2, output);

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	Free();

	return 0;
}

int CuviArithmeticLogical::Subtract(unsigned char %inImageBytes, int val, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inImageBytes);

	//Create CuviImages and fill with data
	CuviImage image, output;
	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	
	cuvi::arithmeticLogical::subtract(val, image, output);

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	Free();

	return 0;
}

int CuviArithmeticLogical::Multiply(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::multiply(image1, image2, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	
	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}
	Free();

	return 0;
}

int CuviArithmeticLogical::Multiply(unsigned char %img1, int scalar, unsigned char %outImgBytes) {

	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1);

	//Create CuviImages and fill with data
	CuviImage image, output;
	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	output = image * scalar;

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}

	Free();
	return 0;
}

//Matrix invert a one-channel 32bit image
int CuviArithmeticLogical::MatInverse(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	if (!usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f / 3;

	GetBytes(inImgBytes);

	//Create a CuviImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::invert(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	pin_ptr<unsigned char> outPtr = &outImgBytes;
	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();
	return 0;
}

//Matrix multiply two one-channel 32bit images
int CuviArithmeticLogical::MatMultiply(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	if(!usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f / 3;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::matMul(image1, image2, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }


	pin_ptr<unsigned char> outPtr = &outImgBytes;
	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();

	return 0;
}

//Matrix multiply a one-channel 32bit image with its transpose (A * A')
int CuviArithmeticLogical::MatMultiplyTrans(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	if (!usingFloats)
		return -1;

	CuviSize imgSize(width, height);
	inImgSize = outImgSize32f / 3;

	GetBytes(inImgBytes);

	//Create a CuviImage and fill it with data
	CuviImage image, output;

	status = image.create(imgSize, containerBits, 1); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::matMulTrans(image, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	pin_ptr<unsigned char> outPtr = &outImgBytes;
	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = output.download(outBytes, CPUinputPitch); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	SetFloats(outImgBytes);

	Free();
	return 0;
}

//Divide the pixel values of two images
int CuviArithmeticLogical::Divide(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes) {

	CuviSize imgSize(width, height);

	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(img1, img2);

	//Create CuviImages and fill with data
	CuviImage image1, image2, output;
	status = image1.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image1.upload(inBytes1, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image2.upload(inBytes2, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::divide(image1, image2, output); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
	}
	else {
		outBytes = (unsigned char*)malloc(outImgSize);
		status = output.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetBytes(outImgBytes);
	}

	Free();
	return 0;
}

//Calculate exponential value of each pixel
int CuviArithmeticLogical::Exp(unsigned char %inImgBytes, unsigned char %outImgBytes) {
	
	CuviSize imgSize(width, height);
	inImgSize = usingFloats ? outImgSize32f : outImgSize;

	GetBytes(inImgBytes);

	//Create a CuvuImage and fill it with data
	CuviImage image, image32f;

	status = image.create(imgSize, containerBits, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	status = cuvi::arithmeticLogical::exp(image, image32f); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	if (usingFloats) {
		pin_ptr<unsigned char> outPtr = &outImgBytes;
		outBytes = (unsigned char*)malloc(outImgSize32f);
		status = image32f.download(outBytes, CPUinputPitch * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
		SetFloats(outImgBytes);
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

//Convert an 8bit image to a 32bit image
int CuviArithmeticLogical::ImgTo32(unsigned char %inImgBytes, unsigned char %outFloats) {
	CuviSize imgSize(width, height);

	inImgSize = outImgSize;

	GetBytes(inImgBytes);

	//Create CuviImages and fill with data
	CuviImage image;
	status = image.create(imgSize, 8, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }


	//Convert from 8bit to 32bit
	CuviImage image32f(image.size(), CUVI_DEPTH_32F, image.channels());
	status = cuvi::dataExchange::convertScale(image, image32f);	if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }//Divide pixel by 255 to normalize

	outBytes = (unsigned char*)malloc(outImgSize32f);
	status = image32f.download(outBytes, CPUinputPitch * 3);
	SetFloats(outFloats);
}

//Convert a 32bit image to an 8bit image
int CuviArithmeticLogical::FloatsToImg(unsigned char %inImgBytes32, unsigned char %outImgBytes) {
	CuviSize imgSize(width, height);

	inImgSize = outImgSize32f;

	GetBytes(inImgBytes32);

	//Create CuviImages and fill with data
	CuviImage image;
	status = image.create(imgSize, 32, 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }
	status = image.upload(inBytes, width * 4 * 3); if (CUVI_SUCCESS != status) { cout << "CUVI Error: " << status << endl;	return (int)status; }

	//Convert from 32bit to 8bit
	CuviImage image8u(image.size(), CUVI_DEPTH_8U, image.channels());
	status = cuvi::dataExchange::convertScale(image, image8u);	//Divide pixel by 255 to normalize

	outBytes = (unsigned char*)malloc(outImgSize);
	status = image8u.download(outBytes, width * 3);
	SetBytes(outImgBytes);

	Free();
}

//Use this to use float values for calculation functions (ie float imgbuffer input)
void CuviArithmeticLogical::UseFloats(bool set) {
	if (set == true) {
		usingFloats = true;
		this->containerBits = 32;
		this->bytesPerPixel = 4;
		this->CPUinputPitch = this->bytesPerPixel * width;
	}
	else {
		usingFloats = false;
		this->containerBits = 8;
		this->bytesPerPixel = 1;
		this->CPUinputPitch = this->bytesPerPixel * width;	
	}
	
}

bool CuviArithmeticLogical::IsUsingFloats(){return usingFloats;}