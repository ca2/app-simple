#pragma once



namespace video_input
{


	// Structure for collecting info about types of video, which are supported by current video device
	struct media
	{

		::u32				m_uFrameSize;
		::size_i32			m_size;
		::u32				m_uYuvMatrix;
		::u32				m_uVideoLighting;
		::u32				m_uDefaultStride;
		::u32				m_uVideoChromaSiting;
		GUID				m_guidAmFormatType;
		string			m_strAmFormatTypeName;
		::u32				m_uFixedSizeSamples;
		::u32				m_uVideoNominalRange;
		::u32				m_uFrameRate;
		::u32				m_uFrameRateLow;
		::u32				m_uPixelAspectRatio;
		::u32				m_uPixelAspectRatioLow;
		::u32				m_uAllSamplesIndependent;
		::u32				m_uFrameRateRangeMin;
		::u32				m_uFrameRateRangeMinLow;
		::u32				m_uSampleSize;
		::u32				m_uVideoPrimaries;
		::u32				m_uInterlaceMode;
		::u32				m_uFrameRateRangeMax;
		::u32				m_uFrameRateRangeMaxLow;
		GUID				m_guidMajorType;
		string			m_strMajorTypeName;
		GUID				m_guidSubtype;
		string			m_strSubtypeName;

		media();
		~media();
		void Clear();
	};


	// Structure for collecting info about one parametr of current video device
	struct parameter
	{

		long m_lCurrentValue;

		long m_lMin;

		long m_lMax;

		long m_lStep;

		long m_lDefault;

		long m_lFlag;

		parameter();
	};

	// Structure for collecting info about 17 parameters of current video device
	struct camera_parameters
	{
		parameter Brightness;
		parameter Contrast;
		parameter Hue;
		parameter Saturation;
		parameter Sharpness;
		parameter Gamma;
		parameter ColorEnable;
		parameter WhiteBalance;
		parameter BacklightCompensation;
		parameter Gain;


		parameter Pan;
		parameter Tilt;
		parameter Roll;
		parameter Zoom;
		parameter Exposure;
		parameter Iris;
		parameter Focus;
	};


} // namespace video_input



