; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLCDDisplay
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SuperTX.h"

ClassCount=30
Class1=CSuperTXApp
Class2=CSuperTXDlg
Class3=CAboutDlg

ResourceCount=16
Resource1=IDD_EDIT_MIXER_SETTINGS
Resource2=IDR_MAINFRAME
Class4=CStickUnit
Class5=CLCDDisplay
Class6=CToggleSwitch
Class7=CSlider
Class8=CKnob
Resource3=IDD_EDIT_DIGITAL_SETTING
Resource4=IDD_NEW_MODEL
Class9=CMainEditDlg
Class10=CNewModelDlg
Class11=CModelListBox
Resource5=IDD_EDIT_MODEL
Class12=CEditModelDlg
Class13=CWidgetComboBox
Class14=CInputComboBox
Class15=COutputComboBox
Class16=CWidgetTemplateListBox
Resource6=IDD_NEW_WIDGET
Class17=CWidgetListBox
Resource7=IDD_EDIT_MIXER
Class18=CNewWidgetDlg
Class19=CNewTemplateDlg
Resource8=IDD_NEW_TEMPLATE
Resource9=IDD_SUPERTX_DIALOG
Class20=CEditAnalogueSettingDlg
Class21=CEditDigitalSettingDlg
Resource10=IDD_EDIT_RATE_LIMITER
Class22=CEditTemplateDlg
Resource11=IDD_EDIT_ANALOGUE_SETTING
Class23=CNewGroupIODlg
Class24=CInputListBox
Class25=COutputListBox
Resource12=IDD_NEW_IO
Class26=CEditGroupDlg
Resource13=IDD_EDIT_DELAY
Resource14=IDD_ABOUTBOX
Class27=CEditDelayDlg
Resource15=IDD_EDIT_MAIN
Class28=CEditRateLimiterDlg
Class29=CEditLinerPieceWiseWnd
Class30=CEditLinearPieceWiseDlg
Resource16=IDD_EDIT_LPW

[CLS:CSuperTXApp]
Type=0
HeaderFile=SuperTX.h
ImplementationFile=SuperTX.cpp
Filter=N

[CLS:CSuperTXDlg]
Type=0
HeaderFile=SuperTXDlg.h
ImplementationFile=SuperTXDlg.cpp
Filter=D
LastObject=CSuperTXDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SuperTXDlg.h
ImplementationFile=SuperTXDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUPERTX_DIALOG]
Type=1
Class=CSuperTXDlg
ControlCount=22
Control1=IDC_STK_LEFT,button,1342242827
Control2=IDC_STK_RIGHT,button,1342242827
Control3=IDC_SCREEN,button,1342275595
Control4=IDC_CMD_MISC1,button,1342242816
Control5=IDC_CMD_MISC2,button,1342242816
Control6=IDC_CMD_MISC3,button,1342242816
Control7=IDC_CMD_MISC4,button,1342242816
Control8=IDC_CMD_MISC5,button,1342242816
Control9=IDC_CMD_MISC6,button,1342242816
Control10=IDC_CMD_MISC7,button,1342242816
Control11=IDC_CMD_MISC8,button,1342242816
Control12=IDC_TOG_1,button,1342242827
Control13=IDC_TOG_2,button,1342242827
Control14=IDC_TOG_3,button,1342242827
Control15=IDC_TOG_4,button,1342242827
Control16=IDC_SLD_1,button,1342242827
Control17=IDC_SLD_2,button,1342242827
Control18=IDC_TOG_5,button,1342242827
Control19=IDC_TOG_6,button,1342242827
Control20=IDC_KNOB1,button,1342242827
Control21=IDC_KNOB2,button,1342242827
Control22=IDC_CMD_EDIT,button,1342242816

[CLS:CStickUnit]
Type=0
HeaderFile=StickUnit.h
ImplementationFile=StickUnit.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CStickUnit

[CLS:CLCDDisplay]
Type=0
HeaderFile=LCDDisplay.h
ImplementationFile=LCDDisplay.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CLCDDisplay

[CLS:CToggleSwitch]
Type=0
HeaderFile=ToggleSwitch.h
ImplementationFile=ToggleSwitch.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CToggleSwitch

[CLS:CSlider]
Type=0
HeaderFile=Slider.h
ImplementationFile=Slider.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CSlider

[CLS:CKnob]
Type=0
HeaderFile=Knob.h
ImplementationFile=Knob.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CKnob

[DLG:IDD_EDIT_MAIN]
Type=1
Class=CMainEditDlg
ControlCount=10
Control1=IDC_LST_MODEL_SELECT,listbox,1352728835
Control2=IDC_CMD_MODEL_SELECT,button,1476460544
Control3=IDC_CMD_MODEL_EDIT,button,1476460544
Control4=IDC_CMD_MODEL_NEW,button,1342242816
Control5=IDC_LST_WIDGETS,listbox,1352728835
Control6=IDC_CMD_WIDGETS_EDIT,button,1476460544
Control7=IDC_CMD_WIDGETS_NEW,button,1342242816
Control8=IDOK,button,1342242817
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287

[CLS:CMainEditDlg]
Type=0
HeaderFile=MainEditDlg.h
ImplementationFile=MainEditDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainEditDlg

[DLG:IDD_NEW_MODEL]
Type=1
Class=CNewModelDlg
ControlCount=4
Control1=IDC_EDT_MODEL_NAME,edit,1350631552
Control2=IDOK,button,1476460545
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CNewModelDlg]
Type=0
HeaderFile=NewModelDlg.h
ImplementationFile=NewModelDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNewModelDlg

[CLS:CModelListBox]
Type=0
HeaderFile=ModelListBox.h
ImplementationFile=ModelListBox.cpp
BaseClass=CListBox
Filter=W
LastObject=CModelListBox

[DLG:IDD_EDIT_MODEL]
Type=1
Class=CEditModelDlg
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_LST_WIDGETS,listbox,1352728835
Control3=IDC_CMD_ADD_WIDGET,button,1476460544
Control4=IDC_LST_MODEL_WIDGETS,listbox,1352728835
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CMB_DEST_WIDGET,combobox,1344340227
Control7=IDC_CMB_DEST_INPUT,combobox,1344340227
Control8=IDC_CMB_SOURCE_WIDGET,combobox,1344340227
Control9=IDC_CMB_SOURCE_OUTPUT,combobox,1344340227
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CMD_CONNECT,button,1476460544
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CMD_DELETE_WIDGET,button,1476460544
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CMD_EDIT_MIXER,button,1476460544

[CLS:CEditModelDlg]
Type=0
HeaderFile=EditModelDlg.h
ImplementationFile=EditModelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEditModelDlg
VirtualFilter=dWC

[CLS:CWidgetComboBox]
Type=0
HeaderFile=WidgetComboBox.h
ImplementationFile=WidgetComboBox.cpp
BaseClass=CComboBox
Filter=W
LastObject=CWidgetComboBox

[CLS:CInputComboBox]
Type=0
HeaderFile=InputComboBox.h
ImplementationFile=InputComboBox.cpp
BaseClass=CComboBox
Filter=W

[CLS:COutputComboBox]
Type=0
HeaderFile=OutputComboBox.h
ImplementationFile=OutputComboBox.cpp
BaseClass=CComboBox
Filter=W
LastObject=COutputComboBox

[CLS:CWidgetTemplateListBox]
Type=0
HeaderFile=WidgetTemplateListBox.h
ImplementationFile=WidgetTemplateListBox.cpp
BaseClass=CListBox
Filter=W
LastObject=CWidgetTemplateListBox

[CLS:CWidgetListBox]
Type=0
HeaderFile=WidgetListBox.h
ImplementationFile=WidgetListBox.cpp
BaseClass=CListBox
Filter=W

[DLG:IDD_NEW_WIDGET]
Type=1
Class=CNewWidgetDlg
ControlCount=4
Control1=IDC_EDT_WIDGET_NAME,edit,1350631552
Control2=IDOK,button,1476460545
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CNewWidgetDlg]
Type=0
HeaderFile=NewWidgetDlg.h
ImplementationFile=NewWidgetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNewWidgetDlg

[DLG:IDD_NEW_TEMPLATE]
Type=1
Class=CNewTemplateDlg
ControlCount=4
Control1=IDC_EDT_TEMPLATE_NAME,edit,1350631552
Control2=IDOK,button,1476460545
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CNewTemplateDlg]
Type=0
HeaderFile=NewTemplateDlg.h
ImplementationFile=NewTemplateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDT_TEMPLATE_NAME

[DLG:IDD_EDIT_ANALOGUE_SETTING]
Type=1
Class=CEditAnalogueSettingDlg
ControlCount=5
Control1=IDC_EDT_VALUE,edit,1350631552
Control2=IDC_SLD_VALUE,msctls_trackbar32,1342242840
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_LBL_TITLE,static,1342308352

[CLS:CEditAnalogueSettingDlg]
Type=0
HeaderFile=EditAnalogueSettingDlg.h
ImplementationFile=EditAnalogueSettingDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDCANCEL

[DLG:IDD_EDIT_DIGITAL_SETTING]
Type=1
Class=CEditDigitalSettingDlg
ControlCount=5
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_RAD_ON,button,1342308361
Control4=IDC_RAD_OFF,button,1342177289
Control5=IDC_LBL_TITLE,static,1342308352

[CLS:CEditDigitalSettingDlg]
Type=0
HeaderFile=EditDigitalSettingDlg.h
ImplementationFile=EditDigitalSettingDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_EDIT_MIXER]
Type=1
Class=CEditTemplateDlg
ControlCount=24
Control1=IDCANCEL,button,1342242816
Control2=IDC_LST_WIDGETS,listbox,1352728835
Control3=IDC_CMD_ADD_WIDGET,button,1476460544
Control4=IDC_LST_TEMPLATE_WIDGETS,listbox,1352728835
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CMB_DEST_WIDGET,combobox,1344340227
Control7=IDC_CMB_DEST_INPUT,combobox,1344340227
Control8=IDC_CMB_SOURCE_WIDGET,combobox,1344340227
Control9=IDC_CMB_SOURCE_OUTPUT,combobox,1344340227
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CMD_CONNECT,button,1476460544
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CMD_DELETE_WIDGET,button,1476460544
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CMD_EDIT_MIXER,button,1476460544
Control16=IDC_STATIC,button,1342177287
Control17=IDC_CMD_ADD_INPUT,button,1342242816
Control18=IDC_CMD_DELETE_INPUT,button,1342242816
Control19=IDC_LST_INPUTS,listbox,1352728835
Control20=IDC_STATIC,button,1342177287
Control21=IDC_CMD_ADD_OUTPUT,button,1342242816
Control22=IDC_CMD_DELETE_OUTPUT,button,1342242816
Control23=IDC_LST_OUTPUTS,listbox,1352728835
Control24=IDC_CMD_FREEZE,button,1476460544

[CLS:CEditTemplateDlg]
Type=0
HeaderFile=EditTemplateDlg.h
ImplementationFile=EditTemplateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LST_WIDGETS

[DLG:IDD_NEW_IO]
Type=1
Class=CNewGroupIODlg
ControlCount=6
Control1=IDC_EDT_NAME,edit,1350631552
Control2=IDC_RAD_ANALOGUE,button,1342373897
Control3=IDC_RAD_DIGITAL,button,1342177289
Control4=IDOK,button,1476591617
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352

[CLS:CNewGroupIODlg]
Type=0
HeaderFile=newgroupiodlg.h
ImplementationFile=newgroupiodlg.cpp
BaseClass=CDialog
LastObject=CNewGroupIODlg

[CLS:CInputListBox]
Type=0
HeaderFile=InputListBox.h
ImplementationFile=InputListBox.cpp
BaseClass=CListBox
Filter=W
LastObject=CInputListBox

[CLS:COutputListBox]
Type=0
HeaderFile=OutputListBox.h
ImplementationFile=OutputListBox.cpp
BaseClass=CListBox
Filter=W
LastObject=COutputListBox

[DLG:IDD_EDIT_MIXER_SETTINGS]
Type=1
Class=CEditGroupDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_LST_WIDGETS,listbox,1352728835
Control3=IDC_CMD_EDIT,button,1476460544

[CLS:CEditGroupDlg]
Type=0
HeaderFile=EditGroupDlg.h
ImplementationFile=EditGroupDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_EDIT_DELAY]
Type=1
Class=CEditDelayDlg
ControlCount=4
Control1=IDC_EDT_DELAY,edit,1350631552
Control2=IDOK,button,1476460545
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_EDIT_RATE_LIMITER]
Type=1
Class=CEditRateLimiterDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDT_TRANSIT_TIME,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CEditDelayDlg]
Type=0
HeaderFile=EditDelayDlg.h
ImplementationFile=EditDelayDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEditDelayDlg

[CLS:CEditRateLimiterDlg]
Type=0
HeaderFile=EditRateLimiterDlg.h
ImplementationFile=EditRateLimiterDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDT_TRANSIT_TIME

[CLS:CEditLinerPieceWiseWnd]
Type=0
HeaderFile=EditLinerPieceWiseWnd.h
ImplementationFile=EditLinerPieceWiseWnd.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CEditLinerPieceWiseWnd

[DLG:IDD_EDIT_LPW]
Type=1
Class=CEditLinearPieceWiseDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CEditLinearPieceWiseDlg]
Type=0
HeaderFile=EditLinearPieceWiseDlg.h
ImplementationFile=EditLinearPieceWiseDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEditLinearPieceWiseDlg

