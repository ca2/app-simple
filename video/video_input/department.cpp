// https://www.codeproject.com/Tips/559437/Capturing-Video-from-Web-camera_parameters-on-Windows-and-by
#include "framework.h"
#include "_video_input.h"


namespace video_input
{

	
	department::department()
	{

		Multimedia.mediafoundation();

	}


	department::~department()
	{


	}


	::e_status department::initialize(::layered * pobjectContext)
	{

		auto estatus = ::apex::department::initialize(pobjectContext);

		if (!estatus)
		{

			return estatus;

		}

		return ::success;

	}


} // namespace video_input



