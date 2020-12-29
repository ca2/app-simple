#pragma once


#include "acme/os/windows_common/comptr.h"


struct IMFMediaSource;


namespace video_input
{


	class image_grabber;


	typedef void(*emergensyStopEventCallback)(int, void *);


	/// Class for controlling of thread of the grabbing raw data from video device
	class image_grabber_thread :
		virtual public ::thread
	{
		//friend DWORD WINAPI MainThreadFunction(LPVOID lpParam);

	public:
		~image_grabber_thread(void);

		static HRESULT CreateInstance(image_grabber_thread ** ppIGT, IMFMediaSource * pSource, ::u32 deviceID);

		void start();

		void stop();

		void set_emergency_stop_event(void * userData, void(*func)(int, void *));

		image_grabber * get_image_grabber();

		//HANDLE getMutexHandle();

	//protected:

		virtual ::e_status run() override;

	//private:

		image_grabber_thread(IMFMediaSource * pSource, ::u32 deviceID);

		//HANDLE m_handle;

		//HANDLE m_hMutex;

		///DWORD   m_dwThreadIdArray;

		comptr < image_grabber > m_pimagegrabber;

		emergensyStopEventCallback igt_func;

		void * m_pUserData;

		bool m_bStop;

		::u32 m_uDevice;

	};


} // namespace video_input



