// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#include "_video_input.h"


namespace video_input
{


	video_input::video_input(void) : m_estatusAccessToDevices(error_not_initialized)
	{

		m_bMessageThread = true;

	}

	video_input::~video_input(void)
	{

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		pdebugprintout->print_out(L"\n***** CLOSE VIDEOINPUT LIBRARY - 2013 *****\n\n");

	}

	::e_status video_input::initialize(::layered * pobjectContext)
	{

		auto estatus = ::object::initialize(pobjectContext);

		if (!estatus)
		{

			return estatus;

		}

		estatus = begin_synch();

		if (!estatus)
		{

			return estatus;

		}

		//debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		//pdebugprintout->print_out(L"\n***** VIDEOINPUT LIBRARY - 2013 (Author: Evgeny Pereguda) *****\n\n");

		//estatus = update_device_list();

		refresh_device_list(nullptr);

		/*if (!estatus)
		{

			return estatus;

		}

		if (!m_estatusAccessToDevices)
		{
			
			pdebugprintout->print_out(L"INITIALIZATION: Ther is not any suitable video device\n");

			return m_estatusAccessToDevices;

		}*/

		return ::success;

	}


	void video_input::install_message_routing(::channel * pchannel)
	{

		::thread::install_message_routing(pchannel);

		MESSAGE_LINK(e_message_update_device_list, pchannel, this, &video_input::_001UpdateDeviceList);

	}


	void video_input::_001UpdateDeviceList(::message::message * pmessage)
	{

		update_device_list();

		::promise::routine routine(pmessage->m_lparam);

		if (routine)
		{

			routine();

		}

	}


	::e_status video_input::build_device_list()
	{

		sync_lock sl(mutex());

		HRESULT hr = S_OK;

		comptr<IMFAttributes> pAttributes;

		CoInitialize(NULL);

		hr = MFCreateAttributes(&pAttributes, 1);

		if (SUCCEEDED(hr))
		{

			hr = pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);

		}

		if (SUCCEEDED(hr))
		{

			hr = initDevices(pAttributes);

		}
		else
		{

			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			pdebugprintout->print_out(L"MEDIA FOUNDATION: The access to the video cameras denied\n");

		}

		return (SUCCEEDED(hr));

	}

	
	void video_input::refresh_device_list(const ::promise::routine & routine)
	{

		post_message(e_message_update_device_list, 0, routine);

	}


	::e_status video_input::update_device_list()
	{

		sync_lock sl(mutex());

		m_estatusAccessToDevices = build_device_list();

		if (!m_estatusAccessToDevices)
		{

			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			pdebugprintout->print_out(L"UPDATING: There is not any suitable video device\n");

			return ::error_failed;

		}

		return m_estatusAccessToDevices;

	}



	//IMFMediaSource * video_input::get_media_source(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//		{
	//			IMFMediaSource * out = pdevice->get_media_source();

	//			if (!out)
	//				pdebugprintout->print_out(L"VideoDevice %i: There is not any suitable IMFMediaSource interface\n", deviceID);

	//			return out;
	//		}
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return NULL;
	//}

	//bool video_input::setup_device(::u32 deviceID, ::u32 id)
	//{

	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//		{
	//			bool out = pdevice->setup_device(id);

	//			if (!out)
	//				pdebugprintout->print_out(L"VIDEODEVICE %i: This device cannot be started\n", deviceID);

	//			return out;
	//		}
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return false;
	//}

	//bool video_input::setup_device(::u32 deviceID, ::u32 w, ::u32 h, ::u32 idealFramerate)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//		{
	//			bool out = pdevice->setup_device(w, h, idealFramerate);

	//			if (!out)
	//				pdebugprintout->print_out(L"VIDEODEVICE %i: this device cannot be started\n", deviceID);

	//			return out;
	//		}
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n", deviceID);
	//	}

	//	return false;
	//}

	//media video_input::get_format(::u32 deviceID, ::u32 id)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->get_format(id);
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return media();
	//}

	//bool video_input::is_device_setup(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->is_device_setup();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return false;
	//}

	//bool video_input::is_device_media_source(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->is_device_media_source();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"Device(s): There is not any suitable video device\n");
	//	}

	//	return false;
	//}

	//bool video_input::is_device_raw_data_source(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->is_device_raw_data_source();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return false;
	//}

	//bool video_input::is_frame_new(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		if (!is_device_setup(deviceID))
	//		{
	//			if (is_device_media_source(deviceID))
	//				return false;
	//		}

	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->is_frame_new();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return false;
	//}

	//::u32 video_input::get_format_count(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->get_format_count();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return 0;
	//}


	void video_input::close_all_devices()
	{
		
		for (auto & pdevice : devicea())
		{

			pdevice->close();

		}

	}


	//void video_input::set_camera_parameters(::u32 deviceID, camera_parameters camera_parameters)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//		{

	//			pdevice->set_camera_parameters(camera_parameters);

	//		}

	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}
	//}

	//camera_parameters video_input::get_camera_parameters(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	camera_parameters out;

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			out = pdevice->get_camera_parameters();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return out;
	//}

	//void video_input::close_device(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			pdevice->close_device();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}
	//}

	//::u32 video_input::get_width(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->get_width();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return 0;
	//}

	//::u32 video_input::get_height(::u32 deviceID)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//			return pdevice->get_height();
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return 0;
	//}


	//string video_input::get_device_name(::u32 deviceID)
	//{

	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		

	//		device * pdevice = m_pdevicea->get_device(deviceID);

	//		if (pdevice)
	//		{

	//			return pdevice->get_name();

	//		}
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return L"Empty";
	//}


	//::i32 video_input::get_device_index(const char * pszMd5)
	//{

	//	::i32 iDevice = 0;

	//	for (auto & videodevice : m_pdevicea->m_deviceptra)
	//	{

	//		if (System.crypto_md5_text(pdevice->m_strName).compare_ci(pszMd5) == 0)
	//		{

	//			return iDevice;

	//		}

	//		iDevice++;

	//	}

	//	return -1;

	//}


	//string video_input::get_device_id2(::u32 uDevice)
	//{

	//	device_array & videodevicearray = device_array::get_instance();

	//	return System.crypto_md5_text(videodevicearray.m_deviceptra[uDevice]->m_strName);

	//}


	//::u32 video_input::list_devices(bool silent)
	//{
	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	int out = 0;

	//	if (m_bAccessToDevices)
	//	{
	//		
	//		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//		if (!silent)pdebugprintout->print_out(L"\nVIDEOINPUT SPY MODE!\n\n");

	//		if (!silent)pdebugprintout->print_out(L"SETUP: Looking For Capture Devices\n");

	//		for (auto & pdevice : devicea())
	//		{
	//			
	//			if (!silent)
	//			{

	//				pdebugprintout->print_out(L"SETUP: %s \n", pdevice->m_strName.c_str());

	//			}

	//		}

	//		if (!silent)pdebugprintout->print_out(L"SETUP: %i Device(s) found\n\n", out);

	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return out;

	//}


	//video_input & video_input::get_instance()
	//{

	//	return instance;
	//}

	bool video_input::are_devices_accessible()
	{
		return m_estatusAccessToDevices;
	}

	void video_input::set_verbose(bool state)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		return pdebugprintout->set_verbose(state);
	}

	/*void video_input::set_emergency_stop_event(::u32 deviceID, void * userData, void(*func)(int, void *))
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			if (func)
			{
				

				device * pdevice = m_pdevicea->get_device(deviceID);

				if (pdevice)
					pdevice->set_emergency_stop_event(userData, func);
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}
	}*/

	
	//bool video_input::get_pixels(::u32 deviceID, color32_t * dstBuffer, bool flipRedAndBlue, bool flipImage)
	//{
	//	bool success = false;

	//	::u32 bytes = 4;

	//	debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//	if (m_bAccessToDevices)
	//	{
	//		if (is_device_raw_data_source(deviceID))
	//		{
	//			

	//			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

	//			auto pmemory = m_pdevicea->get_device(deviceID)->get_out_memory();

	//			if (pmemory)
	//			{
	//				::u32 height = m_pdevicea->get_device(deviceID)->get_height();
	//				::u32 width = m_pdevicea->get_device(deviceID)->get_width();

	//				::u32 size = bytes * width * height;

	//				if (size == pmemory->size())
	//				{
	//					
	//					processPixels((color32_t *) pmemory->get_data(), dstBuffer, width, height, bytes, flipRedAndBlue, flipImage);
	//					
	//					pmemory->m_eobject -= e_object_changed;

	//					success = true;

	//				}
	//				else
	//				{
	//					pdebugprintout->print_out(L"ERROR: GetPixels() - bufferSizes do not match!\n");
	//				}
	//			}
	//			else
	//			{
	//				pdebugprintout->print_out(L"ERROR: GetPixels() - Unable to grab frame for device %i\n", deviceID);
	//			}


	//		}
	//	}
	//	else
	//	{
	//		pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
	//	}

	//	return success;
	//}

	
} // namespace video_input



