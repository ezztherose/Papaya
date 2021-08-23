workspace "Papaya"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildconfig}-%{cfg.system}-%{cfg.architecture}"

project "Papaya"
	location "Papaya"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/prj.name")
	objdir ("bin-int/" .. outputdir .. "/prj.name")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PAPY_PLATFORM_WINDOWS",
			"PAPY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "PAPY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PAPY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PAPY_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/prj.name")
	objdir ("bin-int/" .. outputdir .. "/prj.name")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Papaya/vendor/spdlog/include",
		"Papaya/src"
	}

	links
	{
		"Papaya"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PAPY_PLATFORM_WINDOWS"
		}

	
	filter "configurations:Debug"
		defines "PAPY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PAPY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PAPY_DIST"
		optimize "On"