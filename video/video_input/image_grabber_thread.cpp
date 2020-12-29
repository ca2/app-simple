// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#undef Context
#include <mfapi.h>
#include "image_grabber_thread.h"
#include "image_grabber.h"
#include "debug_print_out.h"


//
//DWORD WINAPI MainThreadFunction( LPVOID lpParam )
//{
//	image_grabber_thread *pIGT = (image_grabber_thread *)lpParam;
//
//	pIGT->run();
//
//	return 0; 
//}


namespace video_input
{


	HRESULT image_grabber_thread::CreateInstance(image_grabber_thread ** ppIGT, IMFMediaSource * pSource, ::u32 deviceID)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		*ppIGT = new image_grabber_thread(pSource, deviceID);

		if (ppIGT == NULL)
		{
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Memory cannot be allocated\n", deviceID);

			return E_OUTOFMEMORY;
		}
		else
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Creating of the instance of image_grabber_thread\n", deviceID);

		return S_OK;
	}


	image_grabber_thread::image_grabber_thread(IMFMediaSource * pSource, ::u32 deviceID) : m_bStop(false)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		image_grabber * tempImageGrabber;

		HRESULT hr = image_grabber::CreateInstance(&tempImageGrabber, deviceID);

		m_pimagegrabber = tempImageGrabber;

		m_uDevice = deviceID;

		if (SUCCEEDED(hr))
		{

			hr = m_pimagegrabber->initImageGrabber(pSource, MFVideoFormat_RGB32);

			//::acme::del(pSource);

			if (FAILED(hr))
			{
				pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with initialization of the instance of the image_grabber class\n", deviceID);
			}
			else
			{
				pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Initialization of instance of the image_grabber class\n", deviceID);
			}

		}
		else
		{
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i There is a problem with creation of the instance of the image_grabber class\n", deviceID);
		}
	}

	void image_grabber_thread::set_emergency_stop_event(void * userData, void(*func)(int, void *))
	{
		if (func)
		{
			igt_func = func;

			m_pUserData = userData;
		}
	}

	image_grabber_thread::~image_grabber_thread(void)
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Destroing image_grabber_thread\n", m_uDevice);

	}

	void image_grabber_thread::stop()
	{
		m_bStop = true;

		if (m_pimagegrabber)
		{

			m_pimagegrabber->stopGrabbing();

			//CloseHandle(m_handle);
		}
	}

	//HANDLE image_grabber_thread::getMutexHandle()
	//{
	//	return m_hMutex;
	//}

	void image_grabber_thread::start()
	{
		begin();
		//m_handle = CreateThread(
		//	NULL,                   // default security attributes
		//	0,                      // use default stack size  
		//	MainThreadFunction,       // thread function name
		//	this,          // argument to thread function 
		//	0,                      // use default creation flags 
		//	&m_dwThreadIdArray);   // returns the thread identifier 
	}


	::e_status image_grabber_thread::run()
	{
		debug_print_out * pdebugprintout = &debug_print_out::get_instance();

		if (m_pimagegrabber)
		{
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Thread for grabbing images is started\n", m_uDevice);


			// m_hMutex = CreateMutex(NULL, true, NULL);

			HRESULT hr = m_pimagegrabber->startGrabbing();

			if (FAILED(hr))
			{
				pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with starting the process of grabbing\n", m_uDevice);
			}

		}
		else
		{
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i The thread is finished without execution of grabbing\n", m_uDevice);
		}


		if (!m_bStop)
		{
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Emergency Stop thread\n", m_uDevice);

			if (igt_func)
			{
				igt_func(m_uDevice, m_pUserData);
			}
		}
		else
			pdebugprintout->print_out(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Finish thread\n", m_uDevice);

		//ReleaseMutex(m_hMutex);

		return ::success;

	}


	image_grabber * image_grabber_thread::get_image_grabber()
	{

		return m_pimagegrabber;

	}

	
} // namespace video_input



