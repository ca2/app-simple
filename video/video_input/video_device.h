#pragma once



#include "video_input.h"

struct IMFActivate;

struct IMFMediaSource;

struct IMFMediaType;

namespace video_input
{

	class image_grabber_thread;

	class ::image;

	using subtype_map = string_map < int_array >;

	using frame_rate_map = map < ::u64, ::u64, subtype_map >;

	typedef void(*emergensyStopEventCallback)(int, void *);

	/// Class for controlling of video device
	class video_device :
		virtual public matter
	{

	public:
		video_device(void);
		~video_device(void);

		void close_device();

		camera_parameters get_camera_parameters();

		void set_camera_parameters(camera_parameters parametrs);

		void set_emergency_stop_event(void * userData, void(*func)(int, void *));

		long readInfoOfDevice(IMFActivate * pActivate, ::u32 Num);

		string get_name();

		int get_format_count();

		::u32 get_width();

		::u32 get_height();

		media get_format(::u32 id);

		bool setup_device(::u32 w, ::u32 h, ::u32 idealFramerate = 0);

		bool setup_device(::u32 id);

		bool is_device_setup();

		bool is_device_media_source();

		bool is_device_raw_data_source();

		bool is_frame_new();

		IMFMediaSource * get_media_source();

		::memory * get_out_memory();

		enum enum_lock
		{
			e_lock_media_source,

			e_lock_raw_data,

			e_lock_open

		} ;

		enum_lock										m_elock;
		string											m_strName;

		__pointer(image_grabber_thread)			m_pthreadImageGrabber;

		camera_parameters								m_cameraparametersPrevious;

		::size											m_size;

		::u32												m_uCurrentNumber;

		bool												m_bSetup;

		map < ::u64, ::u64, frame_rate_map>		m_mapCaptureFormat;

		::array < media >								m_mediatypea;

		comptr < IMFMediaSource  >					m_pmediasource;

		emergensyStopEventCallback					m_emergencystopcallback;

		void *											m_pUserData;


		long enumerateCaptureFormats(IMFMediaSource * pSource);

		long setDeviceFormat(IMFMediaSource * pSource, unsigned long dwFormatIndex);

		void buildLibraryofTypes();

		int findType(::u32 size, ::u32 frameRate = 0);

		long resetDevice(IMFActivate * pActivate);

		long initDevice();

		long checkDevice(IMFAttributes * pAttributes, IMFActivate ** pDevice);

	};


} // namespace video_input



