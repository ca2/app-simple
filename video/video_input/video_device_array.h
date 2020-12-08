#pragma once


#include <basetsd.h>


struct IMFAttributes;


namespace video_input
{


	class video_device;


	/// Class for managing of list of video devices
	class video_device_array
	{
	public:
		~video_device_array(void);

		long initDevices(IMFAttributes * pAttributes);

		static video_device_array & get_instance();

		video_device * get_device(::u32 i);

		int getCount();

		void clearDevices();

		UINT32									m_cCount;

		__pointer_array(video_device)		m_deviceptra;

		video_device_array(void);


	};



} // namespace video_input



