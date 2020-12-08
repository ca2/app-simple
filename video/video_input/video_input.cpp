// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#undef Context
#include "video_input.h"
#include "media_foundation.h"
#include "video_device_array.h"
#include "video_device.h"
#include "debug_print_out.h"
//#include "::image.h"


namespace video_input
{


	parameter::parameter()
	{
		m_lCurrentValue = 0;

		m_lMin = 0;

		m_lMax = 0;

		m_lStep = 0;

		m_lDefault = 0;

		m_lFlag = 0;
	}

	media::media()
	{

		Clear();

	}

	media::~media()
	{
		Clear();
	}

	void media::Clear()
	{

		m_uFrameSize = 0;

		m_size.cx = 0;

		m_size.cy = 0;

		m_uYuvMatrix = 0;

		m_uVideoLighting = 0;

		m_uDefaultStride = 0;

		m_uVideoChromaSiting = 0;

		m_uFixedSizeSamples = 0;

		m_uVideoNominalRange = 0;

		m_uFrameRate = 0;

		m_uFrameRateLow = 0;

		m_uPixelAspectRatio = 0;

		m_uPixelAspectRatioLow = 0;

		m_uAllSamplesIndependent = 0;

		m_uFrameRateRangeMin = 0;

		m_uFrameRateRangeMinLow = 0;

		m_uSampleSize = 0;

		m_uVideoPrimaries = 0;

		m_uInterlaceMode = 0;

		m_uFrameRateRangeMax = 0;

		m_uFrameRateRangeMaxLow = 0;

		memset(&m_guidMajorType, 0, sizeof(GUID));

		memset(&m_guidAmFormatType, 0, sizeof(GUID));

		memset(&m_guidSubtype, 0, sizeof(GUID));

	}


	video_input::video_input(void) : m_bAccessToDevices(false)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		pdebugprintout->print_out(L"\n***** VIDEOINPUT LIBRARY - 2013 (Author: Evgeny Pereguda) *****\n\n");

		updateListOfDevices();

		if (!m_bAccessToDevices)
			pdebugprintout->print_out(L"INITIALIZATION: Ther is not any suitable video device\n");
	}

	void video_input::updateListOfDevices()
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		media_foundation * MF = &media_foundation::get_instance();

		m_bAccessToDevices = MF->buildListOfDevices();

		if (!m_bAccessToDevices)
			pdebugprintout->print_out(L"UPDATING: Ther is not any suitable video device\n");
	}

	video_input::~video_input(void)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		pdebugprintout->print_out(L"\n***** CLOSE VIDEOINPUT LIBRARY - 2013 *****\n\n");
	}

	IMFMediaSource * video_input::get_media_source(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
			{
				IMFMediaSource * out = pvideodevice->get_media_source();

				if (!out)
					pdebugprintout->print_out(L"VideoDevice %i: There is not any suitable IMFMediaSource interface\n", deviceID);

				return out;
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return NULL;
	}

	bool video_input::setup_device(::u32 deviceID, ::u32 id)
	{

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
			{
				bool out = pvideodevice->setup_device(id);

				if (!out)
					pdebugprintout->print_out(L"VIDEODEVICE %i: This device cannot be started\n", deviceID);

				return out;
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return false;
	}

	bool video_input::setup_device(::u32 deviceID, ::u32 w, ::u32 h, ::u32 idealFramerate)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
			{
				bool out = pvideodevice->setup_device(w, h, idealFramerate);

				if (!out)
					pdebugprintout->print_out(L"VIDEODEVICE %i: this device cannot be started\n", deviceID);

				return out;
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n", deviceID);
		}

		return false;
	}

	media video_input::get_format(::u32 deviceID, ::u32 id)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->get_format(id);
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return media();
	}

	bool video_input::is_device_setup(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->is_device_setup();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return false;
	}

	bool video_input::is_device_media_source(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->is_device_media_source();
		}
		else
		{
			pdebugprintout->print_out(L"Device(s): There is not any suitable video device\n");
		}

		return false;
	}

	bool video_input::is_device_raw_data_source(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->is_device_raw_data_source();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return false;
	}

	bool video_input::is_frame_new(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			if (!is_device_setup(deviceID))
			{
				if (is_device_media_source(deviceID))
					return false;
			}

			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->is_frame_new();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return false;
	}

	::u32 video_input::get_format_count(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->get_format_count();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return 0;
	}

	void video_input::close_all_devices()
	{
		video_device_array * pvideodevicearray = &video_device_array::get_instance();

		for (::u32 i = 0; i < pvideodevicearray->getCount(); i++)
			close_device(i);
	}

	void video_input::set_camera_parameters(::u32 deviceID, camera_parameters camera_parameters)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
			{

				pvideodevice->set_camera_parameters(camera_parameters);

			}

		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}
	}

	camera_parameters video_input::get_camera_parameters(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		camera_parameters out;

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				out = pvideodevice->get_camera_parameters();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return out;
	}

	void video_input::close_device(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				pvideodevice->close_device();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}
	}

	::u32 video_input::get_width(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->get_width();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return 0;
	}

	::u32 video_input::get_height(::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
				return pvideodevice->get_height();
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return 0;
	}


	string video_input::get_video_device_name(::u32 deviceID)
	{

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

			if (pvideodevice)
			{

				return pvideodevice->get_name();

			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return L"Empty";
	}


	::i32 video_input::get_video_device_index(const char * pszMd5)
	{

		video_device_array & videodevicearray = video_device_array::get_instance();

		::i32 iDevice = 0;

		for (auto & videodevice : videodevicearray.m_deviceptra)
		{

			if (System.crypto_md5_text(videodevice->m_strName).compare_ci(pszMd5) == 0)
			{

				return iDevice;

			}

			iDevice++;

		}

		return -1;

	}


	string video_input::get_video_device_id2(::u32 uDevice)
	{

		video_device_array & videodevicearray = video_device_array::get_instance();

		return System.crypto_md5_text(videodevicearray.m_deviceptra[uDevice]->m_strName);

	}


	::u32 video_input::list_devices(bool silent)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		int out = 0;

		if (m_bAccessToDevices)
		{
			video_device_array * pvideodevicearray = &video_device_array::get_instance();

			out = pvideodevicearray->getCount();

			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			if (!silent)pdebugprintout->print_out(L"\nVIDEOINPUT SPY MODE!\n\n");

			if (!silent)pdebugprintout->print_out(L"SETUP: Looking For Capture Devices\n");

			for (int i = 0; i < out; i++)
			{
				if (!silent)pdebugprintout->print_out(L"SETUP: %i) %s \n", i, get_video_device_name(i));
			}

			if (!silent)pdebugprintout->print_out(L"SETUP: %i Device(s) found\n\n", out);

		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return out;
	}

	video_input & video_input::get_instance()
	{
		static video_input instance;

		return instance;
	}

	bool video_input::are_devices_accessible()
	{
		return m_bAccessToDevices;
	}

	void video_input::set_verbose(bool state)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		return pdebugprintout->set_verbose(state);
	}

	void video_input::set_emergency_stop_event(::u32 deviceID, void * userData, void(*func)(int, void *))
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			if (func)
			{
				video_device_array * pvideodevicearray = &video_device_array::get_instance();

				video_device * pvideodevice = pvideodevicearray->get_device(deviceID);

				if (pvideodevice)
					pvideodevice->set_emergency_stop_event(userData, func);
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}
	}

	
	bool video_input::get_pixels(::u32 deviceID, color32_t * dstBuffer, bool flipRedAndBlue, bool flipImage)
	{
		bool success = false;

		::u32 bytes = 4;

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_bAccessToDevices)
		{
			if (is_device_raw_data_source(deviceID))
			{
				video_device_array * pvideodevicearray = &video_device_array::get_instance();

				debug_print_out * pdebugprintout = &debug_print_out::get_instance();

				auto pmemory = pvideodevicearray->get_device(deviceID)->get_out_memory();

				if (pmemory)
				{
					::u32 height = pvideodevicearray->get_device(deviceID)->get_height();
					::u32 width = pvideodevicearray->get_device(deviceID)->get_width();

					::u32 size = bytes * width * height;

					if (size == pmemory->size())
					{
						
						processPixels((color32_t *) pmemory->get_data(), dstBuffer, width, height, bytes, flipRedAndBlue, flipImage);
						
						pmemory->m_eobject -= e_object_changed;

						success = true;

					}
					else
					{
						pdebugprintout->print_out(L"ERROR: GetPixels() - bufferSizes do not match!\n");
					}
				}
				else
				{
					pdebugprintout->print_out(L"ERROR: GetPixels() - Unable to grab frame for device %i\n", deviceID);
				}


			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE(s): There is not any suitable video device\n");
		}

		return success;
	}

	void video_input::processPixels(color32_t * src, color32_t * dst, ::u32 width, ::u32 height, ::u32 bpp, bool bRGB, bool bFlip)
	{

		::u32 widthInBytes = width * bpp;

		::u32 numBytes = widthInBytes * height;

		::u32 numInts = numBytes >> 2;

		::u32 widthInInts = widthInBytes >> 2;

		int * dstInt, * srcInt;

		if (!bRGB)
		{

			int x = 0;
			int y = 0;

			if (bFlip)
			{
				for (int y = 0; y < height; y++)
				{
					dstInt = (int *)(dst + (y * widthInBytes));

					srcInt = (int *)(src + ((height - y - 1) * widthInBytes));

					memcpy(dstInt, srcInt, widthInBytes);
					//_asm
					//{
					//	mov ESI, srcInt

					//	mov EDI, dstInt

					//	mov ECX, widthInInts

					//	cld

					//	rep movsd
					//}
				}

			}
			else
			{

				memcpy(dst, src, numBytes);

				byte * pbyteDst = (byte *) dst;

				pbyteDst += 3;

				for (int i = 0; i < numBytes; i += 4)
				{

					pbyteDst[0] = 255;
					pbyteDst += 4;

				}
				//_asm
				//{
				//	mov ESI, src

				//	mov EDI, dst

				//	mov ECX, numInts

				//	cld

				//	rep movsd
				//}
			}
		}
		else
		{
			if (bFlip)
			{

				int x = 0;
				int y = (height - 1) * widthInBytes;
				src += y;

				for (::u32 i = 0; i < numBytes; i += 4)
				{
					if (x >= width)
					{
						x = 0;
						src -= widthInBytes * 2;
					}

					*dst = *(src + 2);
					dst++;

					*dst = *(src + 1);
					dst++;

					*dst = *src;
					dst++;

					src += 3;
					x++;
				}
			}
			else
			{
				for (::u32 i = 0; i < numBytes; i += 4)
				{
					*dst = *(src + 3);
					dst++;

					*dst = *(src + 2);
					dst++;

					*dst = *(src + 1);
					dst++;

					*dst = *src;
					dst++;

					src += 4;
				}
			}
		}

	}


} // namespace video_input



