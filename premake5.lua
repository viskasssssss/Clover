workspace "Clover"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Clover"
	location "Clover"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cvpch.h"
	pchsource "Clover/src/cvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Clover/src"
	}

	buildoptions { "/utf-8" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS",
			"CLOVER_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "CLOVER_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "CLOVER_DIST"
		symbols "On"

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
		"Clover/vendor/spdlog/include",
		"Clover/src"
	}

	buildoptions { "/utf-8" }

	links
	{
		"Clover"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "CLOVER_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "CLOVER_DIST"
		symbols "On"