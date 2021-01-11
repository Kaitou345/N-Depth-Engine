workspace "N-Depth-Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

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
		"N-Depth-Engine/vendor/spdlog/include",
		"N-Depth-Engine/src"
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

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}

	filter "configurations:Debug"
		defines "ND_DEBUG_BUILD"
		symbols "On"

	filter "configurations:Debug"
		defines "ND_RELEASE_BUILD"
		optimize "On"

	filter "configurations:Debug"
		defines "ND_DIST_BUILD"
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

	links
	{
		"N-Depth-Engine"
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
		symbols "On"

	filter "configurations:Debug"
		defines "ND_RELEASE_BUILD"
		optimize "On"

	filter "configurations:Debug"
		defines "ND_DIST_BUILD"
		optimize "On"

