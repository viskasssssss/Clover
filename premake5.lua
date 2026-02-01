workspace "Clover"
	architecture "x64"
	startproject "CloverLeaf"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories
IncludeDir = {}
IncludeDir["GLFW"] = "Clover/vendor/GLFW/include"
IncludeDir["Glad"] = "Clover/vendor/Glad/include"
IncludeDir["ImGui"] = "Clover/vendor/imgui"
IncludeDir["glm"] = "Clover/vendor/glm"
IncludeDir["stb_image"] = "Clover/vendor/stb_image"

group "Dependencies"
	include "Clover/vendor/GLFW"
	include "Clover/vendor/Glad"
	include "Clover/vendor/imgui"
group ""

-- Clover Engine
project "Clover"
	location "Clover"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cvpch.h"
	pchsource "Clover/src/cvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"Clover/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"

	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	buildoptions { "/utf-8" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS",
			"CLOVER_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CLOVER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CLOVER_DIST"
		runtime "Release"
		optimize "on"

-- Sandbox Project
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"Clover/vendor/spdlog/include",
		"Clover/src",
		"Clover/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}"
	}

	buildoptions { "/utf-8" }

	links
	{
		"Clover"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CLOVER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CLOVER_DIST"
		runtime "Release"
		symbols "on"

-- Clover Editor
project "CloverLeaf"
	location "CloverLeaf"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"Clover/vendor/spdlog/include",
		"Clover/src",
		"Clover/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}"
	}

	buildoptions { "/utf-8" }

	links
	{
		"Clover"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CLOVER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CLOVER_DIST"
		runtime "Release"
		symbols "on"