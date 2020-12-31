#pragma once


#include <guiddef.h>
#include <basetsd.h>


struct IMFMediaSource;
struct IMFAttributes;


#include "_struct.h"


namespace video_input
{

	enum enum_lock
	{
		e_lock_media_source,

		e_lock_raw_data,

		e_lock_open

	};

   class media_foundation;

	void processPixels(color32_t * src, color32_t * dst, ::u32 width, ::u32 height, ::u32 bpp, bool bRGB, bool bFlip);



} // namespace video_input

#include "device.h"
#include "device_array.h"

#include "video_input.h"


#include "department.h"




