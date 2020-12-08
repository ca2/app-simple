// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#undef Context
#include <mfobjects.h>
#include <mfidl.h>
#include <mfapi.h>
#include <string.h>

#include <Strmif.h>


#include "video_device.h"
#include "format_reader.h"
#include "debug_print_out.h"
#include "image_grabber_thread.h"
#include "image_grabber.h"
#include "acme/os/windows_common/cotaskptr.h"

#pragma comment(lib, "Strmiids")

namespace video_input
{



	video_device::video_device(void) : m_bSetup(false), m_elock(e_lock_open), 
		m_emergencystopcallback(NULL), m_pUserData(NULL)
	{

	}

	void video_device::set_camera_parameters(camera_parameters parametrs)
	{
		if (m_bSetup)
		{
			if (m_pmediasource)
			{
				::u32 shift = sizeof(parameter);

				parameter * pParametr = (parameter *)(&parametrs);

				parameter * pPrevParametr = (parameter *)(&m_cameraparametersPrevious);

				IAMVideoProcAmp * pProcAmp = NULL;
				HRESULT hr = m_pmediasource->QueryInterface(IID_PPV_ARGS(&pProcAmp));

				if (SUCCEEDED(hr))
				{
					for (::u32 i = 0; i < 10; i++)
					{
						if (pPrevParametr[i].m_lCurrentValue != pParametr[i].m_lCurrentValue || pPrevParametr[i].m_lFlag != pParametr[i].m_lFlag)
							hr = pProcAmp->Set(VideoProcAmp_Brightness + i, pParametr[i].m_lCurrentValue, pParametr[i].m_lFlag);

					}

					pProcAmp->Release();
				}

				IAMCameraControl * pProcControl = NULL;
				hr = m_pmediasource->QueryInterface(IID_PPV_ARGS(&pProcControl));

				if (SUCCEEDED(hr))
				{
					for (::u32 i = 0; i < 7; i++)
					{
						if (pPrevParametr[10 + i].m_lCurrentValue != pParametr[10 + i].m_lCurrentValue || pPrevParametr[10 + i].m_lFlag != pParametr[10 + i].m_lFlag)
							hr = pProcControl->Set(CameraControl_Pan + i, pParametr[10 + i].m_lCurrentValue, pParametr[10 + i].m_lFlag);
					}

					pProcControl->Release();
				}

				m_cameraparametersPrevious = parametrs;
			}
		}
	}

	camera_parameters video_device::get_camera_parameters()
	{
		camera_parameters out;

		if (m_bSetup)
		{
			if (m_pmediasource)
			{
				::u32 shift = sizeof(parameter);

				parameter * pParametr = (parameter *)(&out);

				IAMVideoProcAmp * pProcAmp = NULL;
				HRESULT hr = m_pmediasource->QueryInterface(IID_PPV_ARGS(&pProcAmp));

				if (SUCCEEDED(hr))
				{
					for (::u32 i = 0; i < 10; i++)
					{
						parameter temp;

						hr = pProcAmp->GetRange(VideoProcAmp_Brightness + i, &temp.m_lMin, &temp.m_lMax, &temp.m_lStep, &temp.m_lDefault, &temp.m_lFlag);

						if (SUCCEEDED(hr))
						{
							long currentValue = temp.m_lDefault;

							hr = pProcAmp->Get(VideoProcAmp_Brightness + i, &currentValue, &temp.m_lFlag);

							temp.m_lCurrentValue = currentValue;

							pParametr[i] = temp;
						}
					}

					pProcAmp->Release();
				}

				IAMCameraControl * pProcControl = NULL;
				hr = m_pmediasource->QueryInterface(IID_PPV_ARGS(&pProcControl));

				if (SUCCEEDED(hr))
				{
					for (::u32 i = 0; i < 7; i++)
					{
						parameter temp;

						hr = pProcControl->GetRange(CameraControl_Pan + i, &temp.m_lMin, &temp.m_lMax, &temp.m_lStep, &temp.m_lDefault, &temp.m_lFlag);

						if (SUCCEEDED(hr))
						{
							long currentValue = temp.m_lDefault;

							hr = pProcAmp->Get(CameraControl_Pan + i, &currentValue, &temp.m_lFlag);

							temp.m_lCurrentValue = currentValue;

							pParametr[10 + i] = temp;
						}
					}

					pProcControl->Release();
				}
			}
		}

		return out;
	}

	long video_device::resetDevice(IMFActivate * pActivate)
	{
		HRESULT hr = -1;

		m_mediatypea.clear();

		//if (m_strFriendlyName)
			//CoTaskMemFree(m_strFriendlyName);

		//m_strFriendlyName = NULL;

		if (pActivate)
		{
			IMFMediaSource * pSource = NULL;

			cotaskptr < PWCHAR > pFriendlyName;

			hr = pActivate->GetAllocatedString(
				MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
				&pFriendlyName,
				NULL
			);

			m_strName = pFriendlyName;

			//::CoTaskMemFree(pFriendlyName);


			hr = pActivate->ActivateObject(
				__uuidof(IMFMediaSource),
				(void **)&pSource
			);

			enumerateCaptureFormats(pSource);

			buildLibraryofTypes();



			::acme::del(pSource);



			if (FAILED(hr))
			{
				//m_strFriendlyName = NULL;

				m_strName.Empty();

				debug_print_out * pdebugprintout = &debug_print_out::get_instance();

				pdebugprintout->print_out(L"VIDEODEVICE %i: IMFMediaSource interface cannot be created \n", m_uCurrentNumber);
			}
		}

		return hr;
	}

	long video_device::readInfoOfDevice(IMFActivate * pActivate, ::u32 Num)
	{
		HRESULT hr = -1;

		m_uCurrentNumber = Num;

		hr = resetDevice(pActivate);

		return hr;
	}

	long video_device::checkDevice(IMFAttributes * pAttributes, IMFActivate ** pDevice)
	{
		HRESULT hr = S_OK;

		IMFActivate ** ppDevices = NULL;

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		UINT32 m_cCount;

		wchar_t * newFriendlyName = NULL;

		hr = MFEnumDeviceSources(pAttributes, &ppDevices, &m_cCount);

		if (SUCCEEDED(hr))
		{
			if (m_cCount > 0)
			{
				if (m_cCount > m_uCurrentNumber)
				{
					hr = ppDevices[m_uCurrentNumber]->GetAllocatedString(
						MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
						&newFriendlyName,
						NULL
					);

					string strNewFriendlyName = newFriendlyName;

					CoTaskMemFree(newFriendlyName);

					if (SUCCEEDED(hr))
					{

						if (m_strName != strNewFriendlyName)
						{

							pdebugprintout->print_out(L"VIDEODEVICE %i: Chosen device cannot be found \n", m_uCurrentNumber);

							hr = -1;

							pDevice = NULL;
						}
						else
						{
							*pDevice = ppDevices[m_uCurrentNumber];

							(*pDevice)->AddRef();
						}
					}
					else
					{
						pdebugprintout->print_out(L"VIDEODEVICE %i: Name of device cannot be gotten \n", m_uCurrentNumber);
					}

				}
				else
				{
					pdebugprintout->print_out(L"VIDEODEVICE %i: Number of devices more than corrent number of the device \n", m_uCurrentNumber);

					hr = -1;
				}

				for (UINT32 i = 0; i < m_cCount; i++)
				{
					if (ppDevices[i])
					{

						ppDevices[i]->Release();

					}
				}

			}
			else
				hr = -1;
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE %i: List of DeviceSources cannot be enumerated \n", m_uCurrentNumber);
		}

		return hr;
	}

	long video_device::initDevice()
	{
		HRESULT hr = -1;

		comptr<IMFAttributes > pAttributes;

		comptr<IMFActivate>  pactivate;

		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		CoInitialize(NULL);

		hr = MFCreateAttributes(&pAttributes, 1);

		if (SUCCEEDED(hr))
		{
			hr = pAttributes->SetGUID(
				MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
				MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
			);
		}

		if (SUCCEEDED(hr))
		{
			hr = checkDevice(pAttributes, &pactivate);

			if (SUCCEEDED(hr) && pactivate)
			{
				
				hr = pactivate->ActivateObject(
					__uuidof(IMFMediaSource),
					(void **)&m_pmediasource
				);

				if (SUCCEEDED(hr))
				{

				}

			}
			else
			{
				pdebugprintout->print_out(L"VIDEODEVICE %i: Device there is not \n", m_uCurrentNumber);
			}
		}
		else
		{

			pdebugprintout->print_out(L"VIDEODEVICE %i: The attribute of video cameras cannot be getting \n", m_uCurrentNumber);

		}

		return hr;

	}


	media video_device::get_format(::u32 id)
	{

		if (id < m_mediatypea.size())
		{

			return m_mediatypea[id];

		}
		else
		{

			return media();

		}

	}

	int video_device::get_format_count()
	{
		return m_mediatypea.size();
	}

	void video_device::set_emergency_stop_event(void * userData, void(*func)(int, void *))
	{
		m_emergencystopcallback = func;

		m_pUserData = userData;
	}

	void video_device::close_device()
	{
		if (m_bSetup)
		{
			m_bSetup = false;

			m_pmediasource->Stop();

			if (m_elock == e_lock_raw_data)
			{
				m_pthreadImageGrabber->set_finish(&System);

				//WaitForSingleObject(m_pthreadImageGrabber->getMutexHandle(), 5000);

				m_pthreadImageGrabber.release();

			}

			m_elock = e_lock_open;

			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			pdebugprintout->print_out(L"VIDEODEVICE %i: Device is stopped \n", m_uCurrentNumber);

		}

	}


	::u32 video_device::get_width()
	{
		if (m_bSetup)
		{

			return m_size.cx;
		}
		else
		{

			return 0;

		}
	}

	::u32 video_device::get_height()
	{
		if (m_bSetup)
		{

			return m_size.cy;

		}
		else
		{

			return 0;

		}

	}

	IMFMediaSource * video_device::get_media_source()
	{
		IMFMediaSource * out = NULL;

		if (m_elock == e_lock_open)
		{
			m_elock = e_lock_media_source;

			out = m_pmediasource;
		}

		return out;
	}

	int video_device::findType(::u32 size, ::u32 frameRate)
	{
		if (m_mapCaptureFormat.size() == 0)
			return 0;

		auto & FRM = m_mapCaptureFormat[size];

		if (FRM.size() == 0)
			return 0;

		::u32 frameRateMax = 0;  
		
		subtype_map * psubtypemap = nullptr;

		if (frameRate == 0)
		{

			for (auto & pair :FRM)
			{
				if (pair.element1() >= frameRateMax)
				{
					frameRateMax = pair.element1();

					psubtypemap = &pair.element2();
				}
			}

		}
		else
		{
			for (auto & pair : FRM)
			{
				if (pair.element1() >= frameRateMax)
				{
					if (frameRate > pair.element1())
					{
						frameRateMax = pair.element1();

						psubtypemap = &pair.element2();
					}
				}
			}
		}

		if (!psubtypemap || psubtypemap->is_empty())
		{

			return 0;

		}


		auto & it = psubtypemap->begin();

		auto n = it->element2();

		if (n.size() == 0)
			return 0;

		return n[0];

	}

	void video_device::buildLibraryofTypes()
	{
		::u32 size;

		::u32 framerate;

		int m_cCount = 0;

		for (auto & mediatype :m_mediatypea)
		{
			size = mediatype.m_uFrameSize;

			framerate = mediatype.m_uFrameRate;

			auto & FRM = m_mapCaptureFormat[size];

			auto & STM = FRM[framerate];

			string subType(mediatype.m_strSubtypeName);

			auto & VN = STM[subType];

			VN.add(m_cCount);

			//STM[subType] = VN;

			//FRM[framerate] = STM;

			//m_mapCaptureFormat[size] = FRM;

			m_cCount++;
		}
	}

	long video_device::setDeviceFormat(IMFMediaSource * pSource, unsigned long  dwFormatIndex)
	{
		comptr<IMFPresentationDescriptor> ppresentationdescriptor;
		comptr < IMFStreamDescriptor> pstreamdescriptor;
		comptr <IMFMediaTypeHandler > pmediatypehandler;
		comptr < IMFMediaType> pmediatype;

		HRESULT hr = pSource->CreatePresentationDescriptor(&ppresentationdescriptor);
		if (FAILED(hr))
		{
			goto done;
		}

		BOOL fSelected;
		hr = ppresentationdescriptor->GetStreamDescriptorByIndex(0, &fSelected, &pstreamdescriptor);
		if (FAILED(hr))
		{
			goto done;
		}

		hr = pstreamdescriptor->GetMediaTypeHandler(&pmediatypehandler);
		if (FAILED(hr))
		{
			goto done;
		}

		hr = pmediatypehandler->GetMediaTypeByIndex((DWORD)dwFormatIndex, &pmediatype);
		if (FAILED(hr))
		{
			goto done;
		}

		hr = pmediatypehandler->SetCurrentMediaType(pmediatype);

	done:
		//SafeReleaseAllCount(&ppresentationdescriptor);
		//::acme::del(pstreamdescriptor);
		//::acme::del(pmediatypehandler);
		//::acme::del(pmediatype);
		return hr;
	}

	bool video_device::is_device_setup()
	{
		return m_bSetup;
	}


	::memory * video_device::get_out_memory()
	{

		if (!m_bSetup) return NULL;

		if (m_pthreadImageGrabber.get())
		{
		
			return m_pthreadImageGrabber->get_image_grabber()->get_memory();

		}
		else
		{
			debug_print_out * pdebugprintout = &debug_print_out::get_instance();

			pdebugprintout->print_out(L"VIDEODEVICE %i: The instance of image_grabber_thread class does not exist  \n", m_uCurrentNumber);
		}
		return NULL;
	}

	bool video_device::is_frame_new()
	{
		if (!m_bSetup) return false;

		if (m_elock == e_lock_raw_data || m_elock == e_lock_open)
		{
			if (m_elock == e_lock_open)
			{
				m_elock = e_lock_raw_data;

				image_grabber_thread * temp;

				HRESULT hr = image_grabber_thread::CreateInstance(&temp, m_pmediasource, m_uCurrentNumber);

				m_pthreadImageGrabber.reset(temp);

				if (FAILED(hr))
				{
					debug_print_out * pdebugprintout = &debug_print_out::get_instance();

					pdebugprintout->print_out(L"VIDEODEVICE %i: The instance of image_grabber_thread class cannot be created.\n", m_uCurrentNumber);

					return false;
				}

				m_pthreadImageGrabber->set_emergency_stop_event(m_pUserData, m_emergencystopcallback);

				m_pthreadImageGrabber->start();

				return true;
			}

			if (m_pthreadImageGrabber.get())
			{

				return m_pthreadImageGrabber->get_image_grabber()->get_memory()->m_eobject.is(e_object_changed);

			}

		}

		return false;
	}

	bool video_device::is_device_media_source()
	{
		if (m_elock == e_lock_media_source) return true;

		return false;
	}

	bool video_device::is_device_raw_data_source()
	{
		if (m_elock == e_lock_raw_data) return true;

		return false;
	}

	bool video_device::setup_device(::u32 id)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (!m_bSetup)
		{
			HRESULT hr = -1;

			hr = initDevice();

			if (SUCCEEDED(hr))
			{
				m_size = m_mediatypea[id].m_size;

				hr = setDeviceFormat(m_pmediasource, (DWORD)id);

				m_bSetup = (SUCCEEDED(hr));

				if (m_bSetup)
					pdebugprintout->print_out(L"\n\nVIDEODEVICE %i: Device is setuped \n", m_uCurrentNumber);

				m_cameraparametersPrevious = get_camera_parameters();

				return m_bSetup;
			}
			else
			{
				pdebugprintout->print_out(L"VIDEODEVICE %i: Interface IMFMediaSource cannot be got \n", m_uCurrentNumber);

				return false;
			}
		}
		else
		{
			pdebugprintout->print_out(L"VIDEODEVICE %i: Device is setuped already \n", m_uCurrentNumber);

			return false;
		}
	}

	bool video_device::setup_device(::u32 w, ::u32 h, ::u32 idealFramerate)
	{
		::u32 id = findType(w * h, idealFramerate);

		return setup_device(id);
	}

	
	string video_device::get_name()
	{
		
		return m_strName;

	}


	video_device::~video_device(void)
	{

		close_device();

	}


	long video_device::enumerateCaptureFormats(IMFMediaSource * pSource)
	{
		comptr<IMFPresentationDescriptor> ppresentationdescriptor;
		comptr<IMFStreamDescriptor> pstreamdescriptor;
		comptr<IMFMediaTypeHandler> pmediatypehandler;
		comptr<IMFMediaType> pmediatype;

		HRESULT hr = pSource->CreatePresentationDescriptor(&ppresentationdescriptor);
		if (FAILED(hr))
		{
			goto done;
		}

		BOOL fSelected;
		hr = ppresentationdescriptor->GetStreamDescriptorByIndex(0, &fSelected, &pstreamdescriptor);
		if (FAILED(hr))
		{
			goto done;
		}

		hr = pstreamdescriptor->GetMediaTypeHandler(&pmediatypehandler);
		if (FAILED(hr))
		{
			goto done;
		}

		DWORD cTypes = 0;
		hr = pmediatypehandler->GetMediaTypeCount(&cTypes);
		if (FAILED(hr))
		{
			goto done;
		}

		for (DWORD i = 0; i < cTypes; i++)
		{
			hr = pmediatypehandler->GetMediaTypeByIndex(i, &pmediatype);

			if (FAILED(hr))
			{
				goto done;
			}

			media MT = format_reader::Read(pmediatype);

			m_mediatypea.push_back(MT);

			//SafeReleaseAllCount(&pmediatype);
		}

	done:
		
		///SafeReleaseAllCount(&ppresentationdescriptor);
		
		return hr;

	}



} // namespace video_input


