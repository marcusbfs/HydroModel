workspace "HydroModels2"
	architecture "x86_64"
	configurations { "Release", "Debug"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
CPP_LIBS = os.getenv("CPP_LIBS") 

project "HydroModelsGUI"
	location "HydroModelsGUI"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"

	wx_folder = CPP_LIBS .. "/wx313"

	filter {"architecture:x86"}
		wx_lib = wx_folder .. "/lib/vc_lib"
	filter {"architecture:x86_64"}
		wx_lib = wx_folder .. "/lib/vc_x64_lib"
	filter {}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.fbp"
	}

	includedirs {
		"HydroModels2/src",
		"../include/BipartiteGraph/src",
		-- must define wxwin as a path variable!
		(wx_folder .. "/include/msvc"),
		(wx_folder .. "/include"),
	}

	links { 
		"HydroModels2",
	}

	libdirs {
		wx_lib
	}

	defines {
		--"wxMSVC_VERSION_AUTO",
	}

	filter "configurations:Release"
		optimize "On"
		symbols "Off"
		defines {"NDEBUG"}

	filter "configurations:Debug"
		symbols "On"


project "BipartiteGraph"
	location "%{wks.name}/../include/BipartiteGraph"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	filter {"toolset:msc"}
		buildoptions { "/W4"}
	filter {}

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
		symbols "Off"

project "EqNode"
	location "EqNode"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"

	filter {"toolset:msc"}
		buildoptions { "/W4"}
	filter{}


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"../include"
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
		symbols "Off"

project "HydroModels2"
	location "HydroModels2"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"

	filter {"architecture:x86"}
		antlr4_lib = CPP_LIBS .. "/antlr4/lib/x86/Release_DLL"
	filter {"architecture:x86_64"}
		antlr4_lib = CPP_LIBS .. "/antlr4/lib/x64/Release_DLL"
	filter {}

	antlr4_dll = antlr4_lib .. "/antlr4-runtime.dll"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter {"toolset:msc"}
		buildoptions { "/W4"}
	filter{}

	defines { 
		"HYDROMODELS_UIAPI_EXPORTS"
	}

	includedirs {
		CPP_LIBS .. "/antlr4/antlr4-runtime",
		"EqNode/src",
		"Solver/src",
		"../include/BipartiteGraph/src"
	}

	libdirs {
		antlr4_lib,
	}

	links { 
		"EqNode", 
		"Solver",
		"antlr4-runtime",
	}

	postbuildcommands {
		-- copy target dll to bin output
		( "{COPY} %{cfg.buildtarget.relpath} ../bin/"  .. outputdir .. "/HydroModelsGUI" ),
		-- copy antlr dll to target directory
		( "{COPY} ".. antlr4_dll .. " %{cfg.buildtarget.directory}"),
		-- copy antlr dll to bin output
		( "{COPY} ".. antlr4_dll .. " ../bin/"  .. outputdir .. "/HydroModelsGUI"),
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
		symbols "Off"


project "Solver"
	location "Solver"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	systemversion "latest"

	filter {"architecture:x86"}
		nlopt_dir = CPP_LIBS .. "/nlopt/x86-Release"
	filter {"architecture:x86_64"}
		nlopt_dir = CPP_LIBS .. "/nlopt/x64-Release"
	filter {}

	nlopt_dll = nlopt_dir .. "/bin/nlopt.dll"

	filter {"toolset:msc"}
		buildoptions { "/W4"}
	filter {}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"EqNode/src",
		"../include",
		"../include/minpack",
		nlopt_dir .. "/include",
	}

	libdirs {
		nlopt_dir .. "/lib",
	}

	links {
		"EqNode",
		"nlopt",
	}

	defines { 
		"SOLVER_DLL_EXPORT"
	}

	postbuildcommands {
		-- copy target dll to bin output
		( "{COPY} %{cfg.buildtarget.relpath} ../bin/"  .. outputdir .. "/HydroModelsGUI" ),
		-- copy nlopt dll to target directory
		( "{COPY} ".. nlopt_dll .. " %{cfg.buildtarget.directory}"),
		-- copy nlopt dll to bin output
		( "{COPY} ".. nlopt_dll .. " ../bin/"  .. outputdir .. "/HydroModelsGUI"),
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
		symbols "Off"
