#include "framework.h"


namespace video_input
{


	void processPixels(color32_t * src, color32_t * dst, ::u32 width, ::u32 height, ::u32 bpp, bool bRGB, bool bFlip)
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

				byte * pbyteDst = (byte *)dst;

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



