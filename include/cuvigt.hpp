#ifndef CUVIGT_HPP
#define CUVIGT_HPP

#ifndef __cplusplus
#error This Header Requires A C++ Compiler
#endif

#include "cuviCore.hpp"

namespace cuvi
{
	namespace geometryTransforms
	{
		CUVI_EXPORTS CuviStatus crop(const CuviImage& src, CuviImage& dst, const Cuvi32s top, const Cuvi32s bottom, const Cuvi32s left, const Cuvi32s right, const CuviStream& stream = CuviStream());

		CUVI_EXPORTS CuviStatus resize(const CuviImage& src, CuviImage& dst, CuviInterpolationType inter = CUVI_INTER_LINEAR, const CuviStream& stream = CuviStream());

		CUVI_EXPORTS CuviStatus flipImage(const CuviImage& src, CuviImage& dst, const CuviFlipType type = CUVI_FLIP_LEFT_RIGHT, const CuviStream& stream = CuviStream());
		
		CUVI_EXPORTS CuviStatus transpose(const CuviImage& src, CuviImage& dst, const CuviStream& stream = CuviStream());
		
		CUVI_EXPORTS CuviStatus rotate(const CuviImage& src, CuviImage& dst, const Cuvi32f angle, const CuviRotationType type = CUVI_ROTATE_CENTER, const CuviStream& stream = CuviStream());
		
		CUVI_EXPORTS CuviStatus warpAffine(const CuviImage& src, CuviImage& dst, Cuvi64f coeffs[2][3], const CuviStream& stream = CuviStream());
		
		CUVI_EXPORTS CuviStatus warpAffineBack(const CuviImage& src, CuviImage& dst, Cuvi64f coeffs[2][3], const CuviStream& stream = CuviStream());
	}
}

#endif
