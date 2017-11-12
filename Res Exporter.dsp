# Microsoft Developer Studio Project File - Name="Res Exporter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Res Exporter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Res Exporter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Res Exporter.mak" CFG="Res Exporter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Res Exporter - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Res Exporter - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Res Exporter - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../Controls" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 Comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Res Exporter - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../Controls" /I "../Dialogs" /I "../" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Res Exporter - Win32 Release"
# Name "Res Exporter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Attribute.cpp
# End Source File
# Begin Source File

SOURCE=.\BatchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BSPFileLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\BSPManager.cpp
# End Source File
# Begin Source File

SOURCE=.\BSPOpener.cpp
# End Source File
# Begin Source File

SOURCE=.\Entity.cpp
# End Source File
# Begin Source File

SOURCE=.\EntityManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\MainEvents.cpp
# End Source File
# Begin Source File

SOURCE=.\MAPOpener.cpp
# End Source File
# Begin Source File

SOURCE=.\MAPParser.cpp
# End Source File
# Begin Source File

SOURCE=.\MAPReader.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# Begin Source File

SOURCE=.\ResourceManager.cpp
# End Source File
# Begin Source File

SOURCE=.\SkyNames.cpp
# End Source File
# Begin Source File

SOURCE=.\WadFiles.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Attribute.h
# End Source File
# Begin Source File

SOURCE=.\BatchDlg.h
# End Source File
# Begin Source File

SOURCE=.\BSPFileLoader.h
# End Source File
# Begin Source File

SOURCE=.\BSPManager.h
# End Source File
# Begin Source File

SOURCE=.\BSPOpener.h
# End Source File
# Begin Source File

SOURCE=.\Entity.h
# End Source File
# Begin Source File

SOURCE=.\EntityManager.h
# End Source File
# Begin Source File

SOURCE=.\Error.h
# End Source File
# Begin Source File

SOURCE=.\HelpDlg.h
# End Source File
# Begin Source File

SOURCE=.\Main.h
# End Source File
# Begin Source File

SOURCE=.\MAPOpener.h
# End Source File
# Begin Source File

SOURCE=.\MAPParser.h
# End Source File
# Begin Source File

SOURCE=.\MAPReader.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManager.h
# End Source File
# Begin Source File

SOURCE=.\SkyNames.h
# End Source File
# Begin Source File

SOURCE=.\WadFiles.h
# End Source File
# End Group
# Begin Group "Controls"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Controls\Button.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\Button.h
# End Source File
# Begin Source File

SOURCE=..\Controls\CommonControl.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\CommonControl.h
# End Source File
# Begin Source File

SOURCE=..\Controls\Control.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\ControlError.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\ControlError.h
# End Source File
# Begin Source File

SOURCE=..\Controls\Controls.h
# End Source File
# Begin Source File

SOURCE=..\Controls\EditBox.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\EditBox.h
# End Source File
# Begin Source File

SOURCE=..\Controls\ListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\ListBox.h
# End Source File
# Begin Source File

SOURCE=..\Controls\Window.cpp
# End Source File
# Begin Source File

SOURCE=..\Controls\Window.h
# End Source File
# End Group
# Begin Group "Dialogs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Dialogs\CustomDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\Dialogs\CustomDialog.h
# End Source File
# Begin Source File

SOURCE=..\Dialogs\Dialogs.h
# End Source File
# Begin Source File

SOURCE=..\Dialogs\FindDirectory.cpp
# End Source File
# Begin Source File

SOURCE=..\Dialogs\FindDirectory.h
# End Source File
# Begin Source File

SOURCE=..\Dialogs\OpenDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\Dialogs\OpenDialog.h
# End Source File
# Begin Source File

SOURCE=..\Dialogs\SaveDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\Dialogs\SaveDialog.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\nano4.ico
# End Source File
# End Target
# End Project
