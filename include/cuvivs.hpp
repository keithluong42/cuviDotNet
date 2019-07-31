#ifndef CUVI_VS_HPP
#define CUVI_VS_HPP

#include "cuviCore.hpp"

namespace cuvi
{
	namespace videostab
	{
		typedef struct _CuviStabilizerImpl* CuviStabilizerImpl;
		typedef struct _CuviMotionEstimatorImpl* CuviMotionEstimatorImpl;
		typedef struct _ThetaImpl* ThetaImpl;

		enum CuviMotionModel
		{
			CUVI_MOTION_TRANSLATION,
			CUVI_MOTION_DEFAULT = CUVI_MOTION_TRANSLATION
		};

		class CUVI_EXPORTS Theta
		{
		public:
			ThetaImpl _impl;
			Theta();
			~Theta();

			Cuvi32f dx() const;
			Cuvi32f dy() const;
			void reset();
		};

		class CUVI_EXPORTS CuviMotionEstimator
		{
			CuviMotionEstimatorImpl _impl;
		public:
			CuviMotionEstimator();
			CuviMotionEstimator(CuviMotionModel model);
			~CuviMotionEstimator();
			
			CuviStatus estimate(const CuviImage& frame0, const CuviImage& frame1, Theta& motion) const;
		};

		class CUVI_EXPORTS CuviVideoStabilizer
		{
			CuviStabilizerImpl _impl;
		public:
			CuviVideoStabilizer();
			CuviVideoStabilizer(const std::string& path, CuviMotionModel model = CUVI_MOTION_DEFAULT);
			~CuviVideoStabilizer();

			CuviStatus create(const std::string& path, CuviMotionModel model = CUVI_MOTION_DEFAULT);
			void release();

			Cuvi32s width() const;
			Cuvi32s height() const;
			Cuvi32s numFrames() const;
			Cuvi64f fps() const;

			CuviStatus getNextStabilizedFrame(CuviImage& stabilized) const;
		};

		
	}
}

#endif