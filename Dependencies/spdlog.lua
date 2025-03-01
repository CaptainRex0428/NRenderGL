project "spdlog"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    files
    {
        "spdlog/src/**.cpp"
    }

    includedirs
    {
        "spdlog/include"
    }

    links
    {
    }

    defines
	{
        "SPDLOG_COMPILED_LIB"
	}

    flags
    {
        -- "NoRuntimeChecks", -- Only used on Visual Studio.
		-- "NoBufferSecurityCheck"
    }

    -- vectorextensions  "SSE"               -- Necessary to run x32.

    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus","/utf-8"}

    warnings "off"

    location (LocationDir)
    targetdir (TargetDir)
    objdir (ObjectDir)

    -- inlining    "Explicit"
	-- intrinsics  "Off"

    -- postbuildcommands
	-- {
		-- ("{COPY} %{cfg.buildtarget.relpath} "..DynamicDir)
	-- }

    filter "system:windows" 
        staticruntime "Off"
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