<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Demo - Win32 (WCE x86em) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\Alain\LOCALS~1\Temp\RSP6A6.tmp" with contents
[
/nologo /W3 /Zi /Od /D "_PROFILE" /D "_POCKET_PC" /D "DEBUG" /D "i486" /D "WIN32" /D "STRICT" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_X86_" /D "x86" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC" /D "UNICODE" /D "_UNICODE" /Fp"X86EMDbg/Demo.pch" /YX /Fo"X86EMDbg/" /Fd"X86EMDbg/" /Gz /c 
"C:\projects\Demo\toto3.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\Alain\LOCALS~1\Temp\RSP6A6.tmp" 
Creating temporary file "C:\DOCUME~1\Alain\LOCALS~1\Temp\RSP6A7.tmp" with contents
[
gx.lib commctrl.lib coredll.lib corelibc.lib aygshell.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /incremental:yes /pdb:"X86EMDbg/Demo.pdb" /debug /nodefaultlib:"OLDNAMES.lib" /nodefaultlib:libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib /out:"X86EMDbg/Demo.exe" /windowsce:emulation /MACHINE:IX86 
.\X86EMDbg\3DDisplay.obj
.\X86EMDbg\audio.obj
.\X86EMDbg\file.obj
.\X86EMDbg\graphic.obj
.\X86EMDbg\input.obj
.\X86EMDbg\mathFP.obj
.\X86EMDbg\mixer.obj
.\X86EMDbg\resman.obj
.\X86EMDbg\sys.obj
.\X86EMDbg\toto3.obj
]
Creating command line "link.exe @C:\DOCUME~1\Alain\LOCALS~1\Temp\RSP6A7.tmp"
<h3>Output Window</h3>
Compiling...
toto3.cpp
_MACROS_H_
_TYPESS_H_
_FILE_SYSTEM_H_
C:\projects\Demo\toto3.cpp(21) : warning C4007: 'main' : must be '__cdecl'
Linking...



<h3>Results</h3>
Demo.exe - 0 error(s), 1 warning(s)
</pre>
</body>
</html>
