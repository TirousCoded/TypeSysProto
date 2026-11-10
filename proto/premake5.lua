

project "TypeSysProto"
	
	kind "ConsoleApp"
	targetname "TypeSysProto"
	
	files
	{
		"**.h",
		"**.cpp",
		"**.c",
		"**.txt",
		"**.taul",
		"**.yama"
	}
	
	includedirs
	{
		"../vendor/TAUL/taul"
	}
	
	links
	{
		"TAUL"
	}

	buildoptions
	{
	}

