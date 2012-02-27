#ifndef YAPOG_EXPORT_HPP
# define YAPOG_EXPORT_HPP

#if defined (_WIN32)
# define YAPOG_LIB __declspec (dllexport)
#else
# define YAPOG_LIB
#endif /// !defined (_WIN32)

#endif /// !YAPOG_EXPORT_HPP
