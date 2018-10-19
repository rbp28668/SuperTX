# Microsoft Developer Studio Project File - Name="SuperTX" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SuperTX - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SuperTX.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SuperTX.mak" CFG="SuperTX - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SuperTX - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SuperTX - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SuperTX - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "SuperTX - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SuperTX - Win32 Release"
# Name "SuperTX - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Adder.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalogueConverter.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalogueSetting.cpp
# End Source File
# Begin Source File

SOURCE=.\And.cpp
# End Source File
# Begin Source File

SOURCE=.\Arrows.cpp
# End Source File
# Begin Source File

SOURCE=.\ConnectForm.cpp
# End Source File
# Begin Source File

SOURCE=.\DataPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\Delay.cpp
# End Source File
# Begin Source File

SOURCE=.\DigitalSetting.cpp
# End Source File
# Begin Source File

SOURCE=.\Display.cpp
# End Source File
# Begin Source File

SOURCE=.\EditAnalogueSettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditContext.cpp
# End Source File
# Begin Source File

SOURCE=.\EditDelayDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditDigitalSettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditGroupDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditLinearPieceWiseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditModelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditModelForm.cpp
# End Source File
# Begin Source File

SOURCE=.\EditRateLimiterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditTemplateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditTemplateForm.cpp
# End Source File
# Begin Source File

SOURCE=.\EditTemplateIOForm.cpp
# End Source File
# Begin Source File

SOURCE=.\EditTemplateMixersForm.cpp
# End Source File
# Begin Source File

SOURCE=.\EditWidgetListForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Encoder.cpp
# End Source File
# Begin Source File

SOURCE=.\EncoderProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\Exponential.cpp
# End Source File
# Begin Source File

SOURCE=.\FixedWidget.cpp
# End Source File
# Begin Source File

SOURCE=.\Fonts.cpp
# End Source File
# Begin Source File

SOURCE=.\Form.cpp
# End Source File
# Begin Source File

SOURCE=.\FormManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Group.cpp
# End Source File
# Begin Source File

SOURCE=.\InputComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\InputListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\Knob.cpp
# End Source File
# Begin Source File

SOURCE=.\LCDDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\LinearPieceWise.cpp
# End Source File
# Begin Source File

SOURCE=.\logo.cpp
# End Source File
# Begin Source File

SOURCE=.\MainEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Model.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelList.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelsForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Multiplexer.cpp
# End Source File
# Begin Source File

SOURCE=.\Multiplier.cpp
# End Source File
# Begin Source File

SOURCE=.\Negate.cpp
# End Source File
# Begin Source File

SOURCE=.\NewGroupIODlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewModelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewTemplateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewWidgetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Not.cpp
# End Source File
# Begin Source File

SOURCE=.\Or.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\RateLimiter.cpp
# End Source File
# Begin Source File

SOURCE=.\RFTransmitter.cpp
# End Source File
# Begin Source File

SOURCE=.\Selection.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectionForm.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectTemplateForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Slider.cpp
# End Source File
# Begin Source File

SOURCE=.\Standard.cpp
# End Source File
# Begin Source File

SOURCE=.\StartupForm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StickUnit.cpp
# End Source File
# Begin Source File

SOURCE=.\StringEntryForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Subtracter.cpp
# End Source File
# Begin Source File

SOURCE=.\SuperTX.cpp
# End Source File
# Begin Source File

SOURCE=.\SuperTX.rc
# End Source File
# Begin Source File

SOURCE=.\SuperTXDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Switches.cpp
# End Source File
# Begin Source File

SOURCE=.\TemplateEditContext.cpp
# End Source File
# Begin Source File

SOURCE=.\TemplateList.cpp
# End Source File
# Begin Source File

SOURCE=.\TemplatesForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Threshold.cpp
# End Source File
# Begin Source File

SOURCE=.\TimerManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ToggleSwitch.cpp
# End Source File
# Begin Source File

SOURCE=.\Transmitter.cpp
# End Source File
# Begin Source File

SOURCE=.\TXEditContext.cpp
# End Source File
# Begin Source File

SOURCE=.\TXTemplateEditContext.cpp
# End Source File
# Begin Source File

SOURCE=.\Type.cpp
# End Source File
# Begin Source File

SOURCE=.\Value.cpp
# End Source File
# Begin Source File

SOURCE=.\WidgetComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\WidgetList.cpp
# End Source File
# Begin Source File

SOURCE=.\WidgetListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets.cpp
# End Source File
# Begin Source File

SOURCE=.\WidgetTemplateListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\WindowsEditContext.cpp
# End Source File
# Begin Source File

SOURCE=.\WindowsTemplateEditContext.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Adder.h
# End Source File
# Begin Source File

SOURCE=.\AnalogueConverter.h
# End Source File
# Begin Source File

SOURCE=.\AnalogueSetting.h
# End Source File
# Begin Source File

SOURCE=.\And.h
# End Source File
# Begin Source File

SOURCE=.\Arrows.h
# End Source File
# Begin Source File

SOURCE=.\BitmapDisplay.h
# End Source File
# Begin Source File

SOURCE=.\ConnectForm.h
# End Source File
# Begin Source File

SOURCE=.\DataPacket.h
# End Source File
# Begin Source File

SOURCE=.\Delay.h
# End Source File
# Begin Source File

SOURCE=.\DigitalSetting.h
# End Source File
# Begin Source File

SOURCE=.\Display.h
# End Source File
# Begin Source File

SOURCE=.\EditAnalogueSettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditContext.h
# End Source File
# Begin Source File

SOURCE=.\EditDelayDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditDigitalSettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditGroupDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditLinearPieceWiseDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditModelDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditModelForm.h
# End Source File
# Begin Source File

SOURCE=.\EditRateLimiterDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditTemplateDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditTemplateForm.h
# End Source File
# Begin Source File

SOURCE=.\EditTemplateIOForm.h
# End Source File
# Begin Source File

SOURCE=.\EditTemplateMixersForm.h
# End Source File
# Begin Source File

SOURCE=.\EditWidgetListForm.h
# End Source File
# Begin Source File

SOURCE=.\Encoder.h
# End Source File
# Begin Source File

SOURCE=.\EncoderProxy.h
# End Source File
# Begin Source File

SOURCE=.\Error.h
# End Source File
# Begin Source File

SOURCE=.\Exponential.h
# End Source File
# Begin Source File

SOURCE=.\FixedWidget.h
# End Source File
# Begin Source File

SOURCE=.\Form.h
# End Source File
# Begin Source File

SOURCE=.\FormManager.h
# End Source File
# Begin Source File

SOURCE=.\Group.h
# End Source File
# Begin Source File

SOURCE=.\InputComboBox.h
# End Source File
# Begin Source File

SOURCE=.\InputListBox.h
# End Source File
# Begin Source File

SOURCE=.\Knob.h
# End Source File
# Begin Source File

SOURCE=.\LCDDisplay.h
# End Source File
# Begin Source File

SOURCE=.\LinearPieceWise.h
# End Source File
# Begin Source File

SOURCE=.\MainEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainForm.h
# End Source File
# Begin Source File

SOURCE=.\Model.h
# End Source File
# Begin Source File

SOURCE=.\ModelList.h
# End Source File
# Begin Source File

SOURCE=.\ModelListBox.h
# End Source File
# Begin Source File

SOURCE=.\ModelsForm.h
# End Source File
# Begin Source File

SOURCE=.\Multiplexer.h
# End Source File
# Begin Source File

SOURCE=.\Multiplier.h
# End Source File
# Begin Source File

SOURCE=.\Negate.h
# End Source File
# Begin Source File

SOURCE=.\NewGroupIODlg.h
# End Source File
# Begin Source File

SOURCE=.\NewModelDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewTemplateDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewWidgetDlg.h
# End Source File
# Begin Source File

SOURCE=.\Not.h
# End Source File
# Begin Source File

SOURCE=.\Or.h
# End Source File
# Begin Source File

SOURCE=.\OutputComboBox.h
# End Source File
# Begin Source File

SOURCE=.\OutputListBox.h
# End Source File
# Begin Source File

SOURCE=.\RateLimiter.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RFTransmitter.h
# End Source File
# Begin Source File

SOURCE=.\Selection.h
# End Source File
# Begin Source File

SOURCE=.\SelectionForm.h
# End Source File
# Begin Source File

SOURCE=.\SelectTemplateForm.h
# End Source File
# Begin Source File

SOURCE=.\Slider.h
# End Source File
# Begin Source File

SOURCE=.\Standard.h
# End Source File
# Begin Source File

SOURCE=.\StartupForm.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StickUnit.h
# End Source File
# Begin Source File

SOURCE=.\StringEntryForm.h
# End Source File
# Begin Source File

SOURCE=.\Subtracter.h
# End Source File
# Begin Source File

SOURCE=.\SuperTX.h
# End Source File
# Begin Source File

SOURCE=.\SuperTXDlg.h
# End Source File
# Begin Source File

SOURCE=.\Switches.h
# End Source File
# Begin Source File

SOURCE=.\TemplateEditContext.h
# End Source File
# Begin Source File

SOURCE=.\TemplateList.h
# End Source File
# Begin Source File

SOURCE=.\TemplatesForm.h
# End Source File
# Begin Source File

SOURCE=.\Threshold.h
# End Source File
# Begin Source File

SOURCE=.\TimerManager.h
# End Source File
# Begin Source File

SOURCE=.\ToggleSwitch.h
# End Source File
# Begin Source File

SOURCE=.\Transmitter.h
# End Source File
# Begin Source File

SOURCE=.\TXEditContext.h
# End Source File
# Begin Source File

SOURCE=.\TXTemplateEditContext.h
# End Source File
# Begin Source File

SOURCE=.\Type.h
# End Source File
# Begin Source File

SOURCE=.\Value.h
# End Source File
# Begin Source File

SOURCE=.\WidgetComboBox.h
# End Source File
# Begin Source File

SOURCE=.\WidgetList.h
# End Source File
# Begin Source File

SOURCE=.\WidgetListBox.h
# End Source File
# Begin Source File

SOURCE=.\Widgets.hpp
# End Source File
# Begin Source File

SOURCE=.\WidgetTemplateListBox.h
# End Source File
# Begin Source File

SOURCE=.\WindowsEditContext.h
# End Source File
# Begin Source File

SOURCE=.\WindowsTemplateEditContext.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\SuperTX.ico
# End Source File
# Begin Source File

SOURCE=.\res\SuperTX.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
