#ifndef __UTILITYFUNCTIONS_HPP__
#define __UTILITYFUNCTIONS_HPP__
/**
  @file utilityfunctions.hpp
  @brief This is a library of utility functions.

  A C-library style collection of utility functions.
*/

#include <string.h>

/**
  @brief Safely copy a C-string ensuring a NULL termination.

  From webpage:
    "The syntax is a bit weird since it combines templating on an integral
  value (instead of a type) with passing an array by reference, both of which
  are unfamiliar to many programmers. For more information on passing arrays by
  reference see this stack overflow [sic] article. Or, you can use the template
  magic quite effectively without worrying about the details of how it works."

  [Stack Overflow article](http://stackoverflow.com/questions/5724171/passing-an-array-by-reference)

  @arg @c output A reference to the destination C-string of size @c charCount.
  @arg @c pSrc The fixed size source C-string.
  @author Bruce Dawson (brucedawson)
  @remark Source:
          https://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/
  @note From webpage:
        "Commenters correctly pointed out that strncpy followed by
        null-termination is not the ideal implementation of strcpy_safe because
        it is inefficient (strncpy will zero all bytes to the end of the
        buffer) and maybe cut UTF-8 characters in half. Fixing this is beyond
        the scope of this post, which was supposed to be focused on
        automatically inferring the buffer size through template magic. So,
        don’t forget to implement YourCopyNFunction – and maybe I’ll post a
        version next time."
*/
template <size_t charCount>
void strcpy_safe(char (& output)[charCount], const char * pSrc)
{
	/// @todo Implement YourCopyNFunction(output, pSrc, charCount);
	//YourCopyNFunction(output, pSrc, charCount);
	// Copy the string -- don't copy too many bytes.
	strncpy(output, pSrc, charCount);
	// Ensure null-termination.
	output[charCount - 1] = 0;
}

/**
  @brief Safely copy a C-string ensuring a NULL termination.

  Since @c strcpy_safe(char (& output)[charCount], const char * pSrc) does not
  accept a dynamically allocated string, this version does.

  @arg @c output A reference to the destination C-string of size @c charCount.
  @arg @c pSrc The dynamically allocated source C-string.
*/
void strcpy_safe(char * (& output), const char * pSrc)
{
	size_t charCount = sizeof(output) / sizeof(output[0]);

	// Don't accept a NULL C-string pointer.
	/// @todo Thow an exception to indicate an error.
	if(NULL == output) return;

	// @todo Implement YourCopyNFunction(output, pSrc, charCount);
	//YourCopyNFunction(output, pSrc, charCount);
	// Copy the string -- don't copy too many bytes.
	strncpy(output, pSrc, charCount);
	// Ensure null-termination.
	output[charCount - 1] = 0;
}

#endif //__UTILITYFUNCTIONS_HPP__
