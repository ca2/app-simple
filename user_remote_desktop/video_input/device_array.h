#pragma once




namespace video_input
{


	class device;


	/// Class for managing of list of video devices
	class device_array :
		virtual public matter
	{
	public:


		DECLARE_ARRAY_OF(device_array, device, ::video_input::device);

		device_array(void);

		virtual ~device_array(void);

		long initDevices(IMFAttributes * pAttributes);

		device * get_device_by_id2(const char * pszMd5);
		device * get_device_by_name(const char * pszMd5);


		//device * get_device(::u32 i);

		//int getCount();

		//void clearDevices();




	};



} // namespace video_input



