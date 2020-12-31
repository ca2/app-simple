#pragma once

namespace video_input
{



	/// The only visiable class for controlling of video devices in format singelton
	class video_input :
		virtual public ::thread, 
		virtual public ::video_input::device_array
	{
	public:

		
		::e_status		m_estatusAccessToDevices;


		video_input();
		virtual ~video_input();


		virtual ::e_status initialize(::layered * pobjectContext) override;


		virtual void install_message_routing(::channel * pchannel) override;


		// Closing video device with deviceID
		//void close_device(::u32 deviceID);

		// Setting callback function for emergency events(for example: removing video device with deviceID) with userData
		//void set_emergency_stop_event(::u32 deviceID, void * userData, void(*func)(int, void *));

		// Closing all devices
		void close_all_devices();

		DECL_GEN_SIGNAL(_001UpdateDeviceList);

		// Getting of parameters of video device with deviceID
		//camera_parameters get_camera_parameters(::u32 deviceID);

		// Setting of parameters of video device with deviceID
		//void set_camera_parameters(::u32 deviceID, camera_parameters parameters);

		// Getting numbers of existence videodevices with listing in consol
		void refresh_device_list(const ::promise::routine & routine);

		// Getting numbers of formats, which are supported by videodevice with deviceID
		//::u32 get_format_count(::u32 deviceID);

		// Getting width of ::image, which is getting from videodevice with deviceID
		//::u32 get_width(::u32 deviceID);

		// Getting height of ::image, which is getting from videodevice with deviceID
		//::u32 get_height(::u32 deviceID);

		// Getting name of videodevice with deviceID
		//string get_device_name(::u32 deviceID);


		//string get_device_id2(::u32 deviceID);

		// Getting interface MediaSource for Media Foundation from videodevice with deviceID
		//IMFMediaSource * get_media_source(::u32 deviceID);

		// Getting format with id, which is supported by videodevice with deviceID 
		//media get_format(::u32 deviceID, int unsigned id);

		// Checking of existence of the suitable video devices
		bool are_devices_accessible();

		// Checking of using the videodevice with deviceID
		//bool is_device_setup(::u32 deviceID);

		// Checking of using MediaSource from videodevice with deviceID
		//bool is_device_media_source(::u32 deviceID);

		// Checking of using Raw Data of pixels from videodevice with deviceID
		//bool is_device_raw_data_source(::u32 deviceID);

		// Setting of the state of outprinting info in consol
		void set_verbose(bool state);

		// Initialization of video device with deviceID by media type with id
		//bool setup_device(::u32 deviceID, ::u32 id = 0);

		// Initialization of video device with deviceID by wisth w, height h and fps idealFramerate
		//bool setup_device(::u32 deviceID, ::u32 w, ::u32 h, ::u32 idealFramerate = 30);

		// Checking of recivig of new frame from video device with deviceID 
		//bool is_frame_new(::u32 deviceID);

		// Writing of Raw Data pixels from video device with deviceID with correction of RedAndBlue flipping flipRedAndBlue and vertical flipping flipImage
		//bool get_pixels(::u32 deviceID, color32_t * pixels, bool flipRedAndBlue = false, bool flipImage = false);

	private:
		virtual ::e_status build_device_list();

		::e_status update_device_list();


	};


} // namespace video_input



