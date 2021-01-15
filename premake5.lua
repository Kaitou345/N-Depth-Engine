workspace "N-Depth-Engine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"
	staticruntime "on"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "N-Depth-Engine"
	location "N-Depth-Engine"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ND_PLATFORM_WINDOWS",
			"ND_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "ND_DEBUG_BUILD"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		buildoptions "/MD"
		defines "ND_RELEASE_BUILD"
		optimize "On"
	filter "configurations:Dist"
		defines "ND_DIST_BUILD"
		buildoptions "/MD"
		optimize "On"
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"N-Depth-Engine/vendor/spdlog/include",
		"N-Depth-Engine/src"
	}
	libdirs
	{
		"bin/" .. outputdir .. "/N-Depth-Engine/"
	}
	links
	{
		"N-Depth-Engine",
		"N-Depth-Engine.lib"

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ND_PLATFORM_WINDOWS"
		}
	filter "configurations:Debug"
		defines "ND_DEBUG_BUILD"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		buildoptions "/MD"
		defines "ND_RELEASE_BUILD"
		optimize "On"
	filter "configurations:Dist"
		defines "ND_DIST_BUILD"
		buildoptions "/MD"
		optimize "On"
