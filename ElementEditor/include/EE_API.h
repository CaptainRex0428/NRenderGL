#pragma once

#ifdef _WINDOWS
#ifdef ELEMENT_EDITOR_DLL_EXPORT
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif // _DLL_EXPORT
#endif // _WINDOWS