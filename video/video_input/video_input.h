#pragma once

#include <guiddef.h>

struct IMFMediaSource;

namespace video_input
{


	// Structure for collecting info about types of video, which are supported by current video device
	struct media
	{

		::u32				m_uFrameSize;
		::size			m_size;
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

	// Structure for collecting info about 17 parametrs of current video device
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

	/// The only visiable class for controlling of video devices in format singelton
	class video_input
	{
	public:
		virtual ~video_input(void);

		// Getting of static instance of video_input class
		static video_input & get_instance();

		// Closing video device with deviceID
		void close_device(::u32 deviceID);

		// Setting callback function for emergency events(for example: removing video device with deviceID) with userData
		void set_emergency_stop_event(::u32 deviceID, void * userData, void(*func)(int, void *));

		// Closing all devices
		void close_all_devices();

		// Getting of parametrs of video device with deviceID
		camera_parameters get_camera_parameters(::u32 deviceID);

		// Setting of parametrs of video device with deviceID
		void set_camera_parameters(::u32 deviceID, camera_parameters parametrs);

		// Getting numbers of existence videodevices with listing in consol
		::u32 list_devices(bool silent = false);

		// Getting numbers of formats, which are supported by videodevice with deviceID
		::u32 get_format_count(::u32 deviceID);

		// Getting width of ::image, which is getting from videodevice with deviceID
		::u32 get_width(::u32 deviceID);

		// Getting height of ::image, which is getting from videodevice with deviceID
		::u32 get_height(::u32 deviceID);

		// Getting name of videodevice with deviceID
		string get_video_device_name(::u32 deviceID);

		::i32 get_video_device_index(const char * pszMd5);

		string get_video_device_id2(::u32 deviceID);

		// Getting interface MediaSource for Media Foundation from videodevice with deviceID
		IMFMediaSource * get_media_source(::u32 deviceID);

		// Getting format with id, which is supported by videodevice with deviceID 
		media get_format(::u32 deviceID, int unsigned id);

		// Checking of existence of the suitable video devices
		bool are_devices_accessible();

		// Checking of using the videodevice with deviceID
		bool is_device_setup(::u32 deviceID);

		// Checking of using MediaSource from videodevice with deviceID
		bool is_device_media_source(::u32 deviceID);

		// Checking of using Raw Data of pixels from videodevice with deviceID
		bool is_device_raw_data_source(::u32 deviceID);

		// Setting of the state of outprinting info in consol
		void set_verbose(bool state);

		// Initialization of video device with deviceID by media type with id
		bool setup_device(::u32 deviceID, ::u32 id = 0);

		// Initialization of video device with deviceID by wisth w, height h and fps idealFramerate
		bool setup_device(::u32 deviceID, ::u32 w, ::u32 h, ::u32 idealFramerate = 30);

		// Checking of recivig of new frame from video device with deviceID 
		bool is_frame_new(::u32 deviceID);

		// Writing of Raw Data pixels from video device with deviceID with correction of RedAndBlue flipping flipRedAndBlue and vertical flipping flipImage
		bool get_pixels(::u32 deviceID, color32_t * pixels, bool flipRedAndBlue = false, bool flipImage = false);

	private:

		bool m_bAccessToDevices;

		video_input(void);

		void processPixels(color32_t * src, color32_t * dst, ::u32 width, ::u32 height, ::u32 bpp, bool bRGB, bool bFlip);

		void updateListOfDevices();
	};


} // namespace video_input



