project "glad"
    kind "SharedLib"
    language "C"

    files
    {
        "glad/include/glad/glad.h",
        "glad/include/KHR/khrplatform.h",
        "glad/src/glad.c"
    }

    includedirs
    {
        "glad/include"
    }

    location (LocationDir)
    targetdir (TargetDir)
    objdir (ObjectDir)

    postbuildcommands
    {
     ("{COPY} %{cfg.buildtarget.relpath} "..DynamicDir)
    }

  filter "system:windows"
    systemversion "latest"
    staticruntime "off"
    defines{"_WINDOWS","_WIN64"}

	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
    defines{"_DEBUG"}
	
	filter "configurations:Release"
		runtime "Release"
		optimize "Speed"
    defines{"_RELEASE","NDEBUG"}
    
  filter "configurations:Dist"
    runtime "Release"
    optimize "on"
    defines{"_DIST","NDEBUG"}