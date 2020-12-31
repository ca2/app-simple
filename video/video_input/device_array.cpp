// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#include "_video_input.h"


namespace video_input
{


	device_array::device_array() 
	{
	}

	//void device_array::clearDevices()
	//{
	//	//array<device *>::iterator i = m_deviceptra.begin();

	//	//for (; i != m_deviceptra.end(); ++i)
	//		//delete (*i);

	//	remove_all();
	//}

	device_array::~device_array(void)
	{
		//clearDevices();
	}

	//device * device_array::get_device(::u32 i)
	//{
	//	if (i >= m_deviceptra.size())
	//	{
	//		return NULL;
	//	}

	//	if (i < 0)
	//	{
	//		return NULL;
	//	}

	//	return m_deviceptra[i];
	//}

	//
	long device_array::initDevices(IMFAttributes * pAttributes)
	{

		HRESULT hr = S_OK;

		IMFActivate ** ppDevices = NULL;

		m_devicea.remove_all();

		UINT32 cCount  = 0;

		hr = MFEnumDeviceSources(pAttributes, &ppDevices, &cCount);

		if (SUCCEEDED(hr))
		{

			if (cCount > 0)
			{

				for (UINT32 i = 0; i < cCount; i++)
				{

					auto pdevice = __new(device);

					pdevice->readInfoOfDevice(ppDevices[i], i);

					add_device(pdevice);

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

			pdebugprintout->print_out(L"VIDEODEVICES: The instances of the device class cannot be created\n");

		}

		for (DWORD i = 0; i < cCount; i++)
		{
			
			SafeRelease(&ppDevices[i]);

		}

		CoTaskMemFree(ppDevices);

		return hr;

	}


	device * device_array::get_device_by_id2(const char * pszMd5)
	{

		for (auto & pdevice : devicea())
		{

			if (pdevice->get_id2().compare_ci(pszMd5) == 0)
			{

				return pdevice;

			}

		}

		return nullptr;

	}
	
	
	device * device_array::get_device_by_name(const char * pszName)
	{


		for (auto & pdevice : devicea())
		{

			if (pdevice->get_name().compare_ci(pszName) == 0)
			{

				return pdevice;

			}

		}

		return nullptr;

	}



	//int device_array::getCount()
	//{

	//	return m_deviceptra.size();

	//}


	//device_array & device_array::get_instance()
	//{

	//	static device_array instance;

	//	return instance;

	//}


} // namespace video_input


