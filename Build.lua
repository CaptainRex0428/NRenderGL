include "Dependencies.lua"
include "Directory.lua"

workspace "ElementEngine"
	architecture "x64"
	startproject "ElementEngine"
	configurations{
		"Debug",
		"Release",
        "Dist"
	}

    filter "system:windows"
    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
	
group "Engine"
	include "ElementEngine/ElementEngine.lua"
group "Engine/Component"
	include "ElementEditor/ElementEditor.lua"
	include "ElementRuntime/ElementRuntime.lua"
group "Engine/Extend"
	include "Extend/ScrewExtend/ScrewExtend.lua"
	
group "Dependencies"
	include "Dependencies/SDL.lua"
	include "Dependencies/SDL_image.lua"
	include "Dependencies/glad.lua"
	include "Dependencies/glfw.lua"
	include "Dependencies/imgui.lua"
	include "Dependencies/libpng.lua"
	include "Dependencies/zlib.lua"

	include "Dependencies/dlg.lua"
	include "Dependencies/freetype.lua"
	include "Dependencies/harfbuzz.lua"
	include "Dependencies/SDL_ttf.lua"

	include "Dependencies/spdlog.lua"
	
group "Dependencies/Examples"
	include "Dependencies/SDL_image_Example.lua"
	include "Dependencies/dlg_example.lua"
	include "Dependencies/SDL_ttf_Example.lua"