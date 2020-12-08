#pragma once

struct IMFAttributes;


namespace video_input
{


	// Class for creating of Media Foundation context
	class media_foundation
	{
	public:
		virtual ~media_foundation(void);

		static media_foundation & get_instance();

		bool buildListOfDevices();

	private:

		media_foundation(void);

	};



} // namespace video_input




