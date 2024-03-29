#pragma once

namespace cuviLib {
	public ref class CUVI {
		public:
			int width, height;
			int outImgSize;
			int histBinCount;
			CUVI();
			
			int FFT2D(unsigned char %inImgBytes, unsigned char %outImgBytes);
			void SetSize(int w, int h);

		protected:
			int inImgSize;
			unsigned char *inBytes, *outBytes;
			unsigned char *inBytes1, *inBytes2;	//For 2 image operations
			CuviStatus status;
			CuviBayerSeq sensorAlignment;
			Cuvi32s containerBits, bytesPerPixel, CPUinputPitch;

			void GetBytes(unsigned char %inImgBytes);
			void GetBytes(unsigned char %inImgBytes1, unsigned char %inImgBytes2, int length);
			void GetBytes(unsigned char %inImgBytes, int length);
			void GetBytes(unsigned char %inData1, unsigned char %inData2);
			void SetBytes(unsigned char %outImgBytes);
			void SetBytes(unsigned char %outImgBytes, int length);
			void SetFloats(unsigned char %outFloats);
			void Free();
	};

	public ref class CuviColorOps : public CUVI{
		public:
			CuviColorOps(int w, int h);
			int DemosaicBytes(unsigned char %inBytes, unsigned char %outBytes);
			int LowLight(unsigned char %inBytes, unsigned char %outBytes);
			int AutoColor(unsigned char %inBytes, unsigned char %outBytes);
	};

	public ref class CuviArithmeticLogical : public CUVI{
		public:
			unsigned char *img32f;
			int outImgSize32f;

			CuviArithmeticLogical(int w, int h, int channels);
			int Abs(unsigned char %inBytes, unsigned char %outBytes);
			int AbsDiff(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Add(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Add(unsigned char %inImageBytes, double val, unsigned char %outImgBytes);
			int cbrt(unsigned char %inData, unsigned char %outImgBytes);
			int Ceil(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int Floor(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int NOT(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int AND(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int XOR(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int OR(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Pow(unsigned char %inImgBytes, long power, unsigned char %outImgBytes);
			int Round(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int SHL(unsigned char %inImgBytes, int val, unsigned char %outImgBytes);
			int SHR(unsigned char %inImgBytes, int val, unsigned char %outImgBytes);
			int Sqrt(unsigned char %inData, unsigned char %outImgBytes);
			int Subtract(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Subtract(unsigned char %inImageBytes, int val, unsigned char %outImgBytes);
			int Multiply(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Multiply(unsigned char %img1, int scalar, unsigned char %outImgBytes);
			int MatInverse(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int MatMultiply(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int MatMultiplyTrans(unsigned char %inImgBytes, unsigned char %outImgBytes);
			int Divide(unsigned char %img1, unsigned char %img2, unsigned char %outImgBytes);
			int Exp(unsigned char %inImgBytes, unsigned char %outImgBytes);

			int ImgTo32(unsigned char %inImgBytes, unsigned char %outFloats);
			int FloatsToImg(unsigned char %inImgBytes32, unsigned char %outImgBytes);
			void UseFloats(bool set);
			bool IsUsingFloats();

		private:
			bool usingFloats;
			int numChannels;
	};

	public ref class CuviGeometryTransform : public CUVI {
		public:
			CuviGeometryTransform(int w, int h);
			int Crop(unsigned char %src, unsigned char %dest, int top, int bottom, int left, int right, int size);
	};

	public ref class CuviImageStats : public CUVI {
		public:
			CuviImageStats(int w, int h, int numChannels);
			int CalcHist(unsigned char %inImgBytes, unsigned int %histResult);
			int GetHistSize(unsigned char %inImgBytes);

	};
}

