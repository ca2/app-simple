// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#undef Context
#include <Mfobjects.h>
#include <Mfidl.h>
#include "video_device_array.h"
#include "video_device.h"
#include "debug_print_out.h"


namespace video_input
{


	video_device_array::video_device_array(void) : m_cCount(0)
	{
	}

	void video_device_array::clearDevices()
	{
		//array<video_device *>::iterator i = m_deviceptra.begin();

		//for (; i != m_deviceptra.end(); ++i)
			//delete (*i);

		m_deviceptra.clear();
	}

	video_device_array::~video_device_array(void)
	{
		clearDevices();
	}

	video_device * video_device_array::get_device(::u32 i)
	{
		if (i >= m_deviceptra.size())
		{
			return NULL;
		}

		if (i < 0)
		{
			return NULL;
		}

		return m_deviceptra[i];
	}

	
	long video_device_array::initDevices(IMFAttributes * pAttributes)
	{

		HRESULT hr = S_OK;

		IMFActivate ** ppDevices = NULL;

		clearDevices();

		hr = MFEnumDeviceSources(pAttributes, &ppDevices, &m_cCount);

		if (SUCCEEDED(hr))
		{

			if (m_cCount > 0)
			{

				for (UINT32 i = 0; i < m_cCount; i++)
				{

					auto pvideodevice = __new(video_device);

					pvideodevice->readInfoOfDevice(ppDevices[i], i);

					m_deviceptra.push_back(pvideodevice);

				}

			}
			else
			{

				hr = -1;

			}

		}
		else
		{
			
			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			pdebugprintout->print_out(L"VIDEODEVICES: The instances of the video_device class cannot be created\n");

		}

		return hr;

	}


	int video_device_array::getCount()
	{

		return m_deviceptra.size();

	}


	video_device_array & video_device_array::get_instance()
	{

		static video_device_array instance;

		return instance;

	}


} // namespace video_input


