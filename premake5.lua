workspace "Clover"
	architecture "x64"

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

include "Clover/vendor/GLFW"
include "Clover/vendor/Glad"
include "Clover/vendor/imgui"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Clover/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLOVER_PLATFORM_WINDOWS",
			"CLOVER_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CLOVER_DEBUG"
		buildoptions "/MDd"
		symbols "On"

		defines
		{
			"CLOVER_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
		defines "CLOVER_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Debug"
		defines "CLOVER_DIST"
		buildoptions "/MD"
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
		"Clover/src",
		"%{IncludeDir.GLFW}",
		"Clover/vendor",
		"%{IncludeDir.glm}"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Debug"
		defines "CLOVER_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Debug"
		defines "CLOVER_DIST"
		buildoptions "/MD"
		symbols "On"