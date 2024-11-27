project "Render"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files
    {
        "include/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "include",
        "openGL32.lib",
		"%{DepIncludeDir.SDL}",
		"%{DepIncludeDir.libpng}",
        "%{ProjIncludeDir.ScrewExtend}"
    }

    includedirs
	{
		"SDL_image/include", 
		"%{DepIncludeDir.SDL}",
		"%{DepIncludeDir.libpng}"
	}

	links
	{
		"SDL",
		"SDL_main",
		"libpng",
        "ScrewExtend",
        "OpenGL32.lib"
	}

	defines
	{
		"LOAD_PNG",
		"LOAD_TGA"
	}

    flags
    {
        -- "NoRuntimeChecks", -- Only used on Visual Studio.
		-- "NoBufferSecurityCheck"
    }

    -- vectorextensions  "SSE"               -- Necessary to run x32.

    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

    -- warnings "off"

    location (LocationDir)
    targetdir (EXEDir)
    objdir (ObjectDir)

    -- inlining    "Explicit"
	-- intrinsics  "Off"

    filter "system:windows" 
        -- staticruntime "Off"
        systemversion "latest"
        defines { "_WINDOWS" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "On"
        defines { "_RELEASE","NDEBUG" }

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines { "_DIST","NDEBUG" }