#ifndef __UTILITYFUNCTIONS_HPP__
#define __UTILITYFUNCTIONS_HPP__

#include <string.h>

/**
  @author: Bruce Dawson (brucedawson)
  @source: https://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/
NOTE: Commenters correctly pointed out that strncpy followed by null-termination
      is not the ideal implementation of strcpy_safe because it is inefficient
      (strncpy will zero all bytes to the end of the buffer) and maybe cut UTF-8
      characters in half. Fixing this is beyond the scope of this post, which
      was supposed to be focused on automatically inferring the buffer size
      through template magic. So, don’t forget to implement YourCopyNFunction –
      and maybe I’ll post a version next time.
*/
template <size_t charCount>
void strcpy_safe(char (& output)[charCount], const char * pSrc)
{
	//YourCopyNFunction(output, pSrc, charCount);
	// Copy the string -- don't copy too many bytes.
	strncpy(output, pSrc, charCount);
	// Ensure null-termination.
	output[charCount - 1] = 0;
}

void strcpy_safe(char * (& output), const char * pSrc)
{
	size_t charCount = sizeof(output) / sizeof(output[0]);

	if(NULL == output) return;

	//YourCopyNFunction(output, pSrc, charCount);
	// Copy the string -- don't copy too many bytes.
	strncpy(output, pSrc, charCount);
	// Ensure null-termination.
	output[charCount - 1] = 0;
}

#endif //__UTILITYFUNCTIONS_HPP__
