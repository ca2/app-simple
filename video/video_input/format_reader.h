#pragma once

#include <guiddef.h>

#include "video_input.h"

struct IMFMediaType;

namespace video_input
{

	/// Class for parsing info from IMFMediaType into the local media
	class format_reader
	{
	public:
		static media Read(IMFMediaType * pmediatype);
		~format_reader(void);
	private:
		format_reader(void);
	};



} // namespace video_input



