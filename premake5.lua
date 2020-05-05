workspace "Flipper"
    architecture "x64"
    
    startproject "Sandbox"

    --defining three configs, debug, release, and distribution
    configurations {"Debug", "Release", "Dist"}

--this outputdir uses tokens (e.g. "Debug-Windows-x64")
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Flipper"
    --specifying the path to place the vcxproj files
    location "Flipper"
    --same as dynamic library
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        --** specifies to recursively search child folders
        "%{prj.name}/**"
    }

    includedirs {

        "%{prj.name}/Vendor/spdlog/include",
        "%{prj.name}/Vendor/SDL2-2.0.12/include"

    }

    libdirs{
        "%{prj.name}/Vendor/SDL2-2.0.12/lib/x64/"
    }

    links{
        "SDL2main.lib",
        "SDL2_image.lib"
    }
    --filters are used to specify behaviour on different platforms
    filter "system:windows"
          cppdialect "C++17"
          staticruntime "On"
          systemversion "latest"

          --defining our macros. if we're on windows, define the windows macro!
          defines{
              "FLIPPER_PLATFORM_WINDOWS",
              "FLIPPER_BUILD_DLL"
          }

          postbuildcommands
          {
            --this is going to copy the Flipper.dll into the sandbox directory after building! finally!
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
          }

    filter "configurations:Debug"
          defines "FLIPPER_DEBUG"
          symbols "On"

    filter "configurations:Release"
          defines "FLIPPER_RELEASE"
          optimize "On"

    filter "configurations:Dist"
          defines "FLIPPER_DIST"
          optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Flipper/Vendor/spdlog/include",
        "Flipper/Vendor/SDL2-2.0.12/include",
        "Flipper/src"
    }

    libdirs{
        "Flipper/Vendor/SDL2-2.0.12/lib/x64/"
    }

    links {
        "Flipper",
        "SDL2main.lib",
        "SDL2_image.lib"
        
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "FLIPPER_PLATFORM_WINDOWS",
            "_MCBS"
        }
    
    filter "configurations:Debug"
        defines "FLIPPER_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "FLIPPER_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "FLIPPER_DIST"
        optimize "On"
