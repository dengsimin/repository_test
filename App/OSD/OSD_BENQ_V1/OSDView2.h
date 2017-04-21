#ifndef __OSD_VIEW2_H__
#define __OSD_VIEW2_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "OSDFont.h"
#include "Include.h"
extern UCHAR OSD_Select_Temp;
extern BOOL bOSD_Select_Temp;
extern BOOL bShowInputNovitceFlag;
extern BOOL bShortOOLTimer;
extern BOOL bSelNum2;

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define CUSTOM_MENU_TYPE_1  0
#define CUSTOM_MENU_TYPE_2  1

#define OSDKEYINFO_UP BIT0
#define OSDKEYINFO_DN BIT1
#define OSDKEYINFO_RT BIT2
#define OSDKEYINFO_LT BIT3
#define OSDKEYINFO_EXIT BIT4
#define OSDKEYINFO_OK BIT5
#define OSDKEYINFO_TYPE_UDRLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UDOLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DRLE (OSDKEYINFO_DN|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_URLE (OSDKEYINFO_UP|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UDLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DOLE (OSDKEYINFO_DN|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UOLE (OSDKEYINFO_UP|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DIALOG (OSDKEYINFO_OK|OSDKEYINFO_EXIT)//ULEric140410
#define OSDKEYINFO_TYPE_RLE (OSDKEYINFO_RT|OSDKEYINFO_LT)//ULEric140415
#define OSDKEYINFO_TYPE_LOK (OSDKEYINFO_LT|OSDKEYINFO_OK)
#define OSDKEYINFO_TYPE_UD (OSDKEYINFO_UP|OSDKEYINFO_DN)
#define OSDKEYINFO_TYPE_UDRL (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_RT)

#define OSDFocusItm11 OSDFocusAuto
#define OSDFocusItm12 OSDFocusInput
#define OSDFocusItm13 OSDFocusHPos
#define OSDFocusItm14 OSDFocusVPos
#define OSDFocusItm15 OSDFocusClock
#define OSDFocusItm16 OSDFocusPhase

#define OSDFocusItm21 OSDFocusBr
#define OSDFocusItm22 OSDFocusCn
#define OSDFocusItm23 OSDFocusSharpness
#define OSDFocusItm24 OSDFocusGamma
#define OSDFocusItm25 OSDFocusClrTmp
#define OSDFocusItm26 OSDFocusHue
#define OSDFocusItm27 OSDFocusSaturation
#define OSDFocusItm28 OSDFocusResetColor
#define OSDFocusItm29 OSDFocusAMA

#define OSDFocusItm31 OSDFocusPicMode
#define OSDFocusItm32 OSDFocusSenseye
#define OSDFocusItm33 OSDFocusDynamicCn
#define OSDFocusItm34 OSDFocusOverScan
#define OSDFocusItm35 OSDFocusDisplayMode
#define OSDFocusItm36 OSDFocusColorFormat
#define OSDFocusItm37 OSDFocusHDMIRGBPCRange

#define OSDFocusItmAudio1 OSDFocusVolume
#define OSDFocusItmAudio2 OSDDummyFunction
#define OSDFocusItmAudio3 OSDDummyFunction

#define OSDFocusItm41 OSDFocusOSDSettings
#define OSDFocusItm42 OSDFocusCustKey1
#define OSDFocusItm43 OSDFocusCustKey2
#define OSDFocusItm44 OSDFocusCustKey3
#define OSDFocusItm45 OSDFocusDDCCi
#define OSDFocusItm46 OSDDummyFunction
#define OSDFocusItm47 OSDDummyFunction
#define OSDFocusItm48 OSDFocusAutoPwrOff
#define OSDFocusItm49 OSDFocusResNotice
#define OSDFocusItm410 OSDFocusInfo
#define OSDFocusItm411 OSDDummyFunction
#define OSDFocusItm412 OSDFocusReset

#define OSDUpItm13    OSDHPositionDown
#define OSDDnItm13    OSDHPositionUp
#define OSDUpItm14    OSDVPositionUp
#define OSDDnItm14    OSDVPositionDown
#define OSDUpItm15    OSDClockUp
#define OSDDnItm15    OSDClockDown
#define OSDUpItm16    OSDPhaseUp
#define OSDDnItm16    OSDPhaseDown

#define OSDUpItmAudio1    OSDVolumeUp
#define OSDDnItmAudio1    OSDVolumeDown

#define OSDUpItmDynContrast  OSDDynamicCnUp
#define OSDDnItmDynContrast  OSDDynamicCnDown

#define OSDUpItm21    OSDBrightnessUp
#define OSDDnItm21    OSDBrightnessDown
#define OSDUpItm22    OSDContrastUp
#define OSDDnItm22    OSDContrastDown
#define OSDUpItm23    OSDSharpnessUp
#define OSDDnItm23    OSDSharpnessDown
#define OSDUpItm24    OSDGammaUp
#define OSDDnItm24    OSDGammaDown
#define OSDUpItm25    OSDColorTempUp
#define OSDDnItm25    OSDColorTempDown
#define OSDUpItm26    OSDColorHueUp
#define OSDDnItm26    OSDColorHueDown
#define OSDUpItm27    OSDColorSaturationUp
#define OSDDnItm27    OSDColorSaturationDown


#define OSDFocusFunc1 OSDFocus3DCnv
#define OSDFuncDown1  OSD2Dto3DFmtDown
#define OSDFuncUp1    OSD2Dto3DFmtUp
#define OSDFocusFunc2 OSDFocus2Dto3DAdpt
#define OSDFuncDown2  OSD2Dto3DAdptDown
#define OSDFuncUp2    OSD2Dto3DAdptUp
#define OSDFocusFunc3 OSDFocus2Dto3DDepth
#define OSDFuncDown3  OSD2Dto3DDepthDown
#define OSDFuncUp3    OSD2Dto3DDepthUp
#define OSDFocusFunc4 OSDFocus2Dto3DView
#define OSDFuncDown4  OSD2Dto3DViewDown
#define OSDFuncUp4    OSD2Dto3DViewUp
#define OSDFocusFunc5 OSDFocus3DLRSwap
#define OSDFuncDown5  OSD3DLRSwapDown
#define OSDFuncUp5    OSD3DLRSwapUp
#define OSDFocusFunc6 OSDFocus3DTo2D
#define OSDFuncDown6  OSD3DTo2DDown
#define OSDFuncUp6    OSD3DTo2DUp

#define OSDInputDir1     OSDConfirmInputDP
#define OSDInputDir2     OSDConfirmInputHDMI
#define OSDInputDir3     OSDConfirmInputVGA
#define OSDInputDir4     OSDConfirmInputDVI

#define OSDUpDir1     OSDBrightnessUp
#define OSDDnDir1     OSDBrightnessDown
#define OSDUpDir2     OSDContrastUp
#define OSDDnDir2     OSDContrastDown
#define OSDUpDir3     OSDVolumeUp
#define OSDDnDir3     OSDVolumeDown
#define OSDUpOpt1     OSDBFMenuITMUp
#define OSDDnOpt1     OSDBFMenuITMDn
#define OSDUpOpt2     OSDSourceMenuITMUp
#define OSDDnOpt2     OSDSourceMenuITMDn


#define OSDConfirmItm11   OSDDummyFunction
#define OSDConfirmItm12   OSDConfirmInput
#define OSDConfirmItm13   OSDDummyFunction
#define OSDConfirmItm14   OSDDummyFunction
#define OSDConfirmItm15   OSDDummyFunction
#define OSDConfirmItm16   OSDDummyFunction

#define OSDConfirmItm21   OSDDummyFunction
#define OSDConfirmItm22   OSDDummyFunction
#define OSDConfirmItm23   OSDDummyFunction
//#define OSDConfirmItm24   OSDExitItm24
//#define OSDConfirmItm25   OSDDummyFunction
#define OSDConfirmItm26   OSDDummyFunction
#define OSDConfirmItm27   OSDDummyFunction
//#define OSDConfirmItm28   OSDDummyFunction
//#define OSDConfirmItm29   OSDDummyFunction

#define OSDConfirmItm31   OSDDummyFunction
//#define OSDConfirmItm32   OSDDummyFunction
#define OSDConfirmItm33   OSDDummyFunction
//#define OSDConfirmItm34   OSDDummyFunction
//#define OSDConfirmItm35   OSDDummyFunction
//#define OSDConfirmItm36   OSDDummyFunction

#define OSDConfirmItmAudio1   OSDDummyFunction
#define OSDConfirmItmAudio2   OSDDummyFunction
#define OSDConfirmItmAudio3   OSDDummyFunction

#define OSDConfirmItm41   OSDDummyFunction
#define OSDConfirmItm42   OSDConfirmCustomeKey1//ULEric140331
#define OSDConfirmItm43   OSDConfirmCustomeKey2//ULEric140331
#define OSDConfirmItm44   OSDConfirmCustomeKey3//ULEric140331
//#define OSDConfirmItm45   OSDDummyFunction
//#define OSDConfirmItm46   OSDDummyFunction
//#define OSDConfirmItm47   OSDDummyFunction
//#define OSDConfirmItm48   OSDDummyFunction
//#define OSDConfirmItm49   OSDDummyFunction
//#define OSDConfirmItm410   OSDDummyFunction
//#define OSDConfirmItm411   OSDDummyFunction
//#define OSDConfirmItm412   OSDDummyFunction

#define OSDConfirmFunc1   OSDConfirm3DCnvMode
#define OSDConfirmFunc2   OSDDummyFunction
#define OSDConfirmFunc3   OSDDummyFunction
#define OSDConfirmOpt1    OSDDummyFunction
#define OSDConfirmOpt2    OSDConfirmInput

//LBL
#define OSDExitSubItmLBL        OSDExitSubItm313
#define OSDConfirmSubItmLBL     OSDConfirmSubItm313
#define OSDSubItmLBLUp          OSDSubItm313Up
#define OSDSubItmLBLDown        OSDSubItm313Down
#define OSDEnterSubItmLBL       OSDEnterSubItm313

#if LAYER_INDENT_COUNT == ON
extern USHRT fnGetLayerIndentCount(UCHAR Layer);
extern void fnResetLayerIndentCount(UCHAR Layer);
#endif
extern void ResetKeyInfoStatus(void);
extern void OSDUnSelectDialogItem(UCHAR id, BOOL isUp);
extern void OSDShowHookIcon(USHRT Attr, UCHAR id, UCHAR Layer, UCHAR font);
extern void OSDClrLayer1Menu(UCHAR id);
extern void OSDClrLayer2Menu(UCHAR id);
extern void OSDClrLayer3Menu(UCHAR id);
extern void OSDShowLayer4Menu(UCHAR id);
extern void OSDShowMainMenuIcon(UCHAR id);
extern void OSDFocusMain(UCHAR id);
extern void OSDUnselectLayer1Item(UCHAR id, BOOL isUp);
extern void OSDUnselectLayer2Item(UCHAR id, BOOL isUp);
extern void OSDUnSelectLayer3Item(UCHAR id, BOOL isUp);
extern void OSDUnSelectLayer4Item(UCHAR id, BOOL IsUp);
extern void OSDShowUpDownArrowIcon(UCHAR id);
extern void OSDSelectLayer1Icon(UCHAR id);
extern void OSDUpdateSelectPageIcon(UCHAR id, UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer, BOOL ENABLE1);
extern void OSDShowSelectPageIcon(UCHAR id, UCHAR act);
extern void OSDExitSubItms(UCHAR itm);
extern void OSDExitItms(UCHAR itm);

extern void OSDFocus3DCnv(void);
extern void OSDFocus2Dto3DAdpt(void);
extern void OSDFocus2Dto3DDepth(void);
extern void OSDFocus2Dto3DView(void);
extern void OSDFocus3DLRSwap(void);
extern void OSDFocus3DTo2D(void);
extern void OSDShowThrDCnvMenu(UCHAR redraw);
extern void OSDShow2Dto3DAdpt(UCHAR redraw);
extern void OSDShow2Dto3DDepth(UCHAR redraw);
extern void OSDShow2Dto3DView(UCHAR redraw);
extern void OSDShow3DLRSwap(UCHAR redraw);
extern void OSDShow3DTo2D(UCHAR redraw);
extern void OSDFocusAuto(void);
extern void OSDFocusSharpness();
extern void OSDFocusHue();
extern void OSDFocusSaturation();
extern void OSDFocusResetColor();
extern void OSDFocusAMA();
extern void OSDFocusPicMode();
extern void OSDFocusSenseye();
extern void OSDFocusDynamicCn();
extern void OSDFocusDisplayMode();
extern void OSDFocusSmartScaling(void);
extern void OSDFocusOverScan();
extern void OSDFocusColorFormat();
extern void OSDFocusHDMIRGBPCRange();
extern void OSDFocusOSDSettings();
extern void OSDFocusCustKey1();
extern void OSDFocusCustKey2();
extern void OSDFocusCustKey3();
extern void OSDFocusDDCCi();
extern void OSDFocusHdmiAutoSwitch();
extern void OSDFocusAutoPwrOff();
extern void OSDFocusResNotice();
extern void OSDFocusInfo();
extern void OSDColorHueUp();
extern void OSDColorHueDown();
extern void OSDColorSaturationUp();
extern void OSDColorSaturationDown();
//extern void OSDColorResetColorUp();
//extern void OSDColorResetColorDown();
extern void OSDColorAMAUp();
extern void OSDColorAMADown();
//extern void OSDSensEye(void);
extern void OSDAudioMuteUp();
extern void OSDAudioSelectUp();
extern void OSDAudioSelectDown();
extern void OSDAudioSelect();
extern void OSDDynamicCnUp();
extern void OSDDynamicCnDown();
extern void OSDSetOverScan();
extern void OSDBColorFormatUp();
extern void OSDBColorFormatDown();
extern void OSDHDMIRGBPCRangeUp();
extern void OSDHDMIRGBPCRangeDown();
extern void OSDSettingUp();
extern void OSDSettingDown();
//extern void OSDCustKey1Up();
//extern void OSDCustKey1Down();
//extern void OSDCustKey2Up();
//extern void OSDCustKey2Down();
//extern void OSDCustKey3Up();
//extern void OSDCustKey3Down();
extern void OSDDDCCiUp();
extern void OSDDDCCiDown();
extern void OSDDDCCIConfirm();
extern void OSDAutoPowOffUp();
extern void OSDAutoPowOffDown();
extern void OSDResNoticeUp();
extern void OSDResNoticeDown();
extern void OSDCustomerMenuUp(void);
extern void OSDCustomerMenuDown(void);
extern void OSDShowInputMenu(void);
extern void OSDShowAutoAdjustmentMenu(void);
extern void OSDShowPictureModeMenu(void);
extern void OSDShowDisplayModeMenu(void);
extern void OSDShowVolumeMenu(void);
extern void OSDShowMuteMenu(void);//ULEric140402
extern void OSDShowLBLMenu(void);
extern void OSDShowEyeProtectMenu(UCHAR type);
extern void OSDShowECOMenu(UCHAR type);

extern void OSDShowSmartReminderMenu(void);
extern void OSDShowBrightnessMenu(void);
extern void OSDShowContrastMenu(void);
extern void OSDShowAnimationMenu(void);

extern void OSDTurnOnOSD(void);
extern void OSDShowTopPageMenu(void);
extern void OSDCloseTopPageMenu(void);
extern void OSDShowInputIcon();
extern BOOL OSDIsMainItemValid(UCHAR id);
extern BOOL OSDIsSubItemValid(UCHAR id);
extern BOOL GetCustomeKeyState(UCHAR Customekeystate);
extern BOOL OSDIsLayer3ItemValid(UCHAR id);
extern void OSDShowSourceMenu(void);
extern void OSDShowFuncMenu(void);
extern void OSDCloseFuncMenu(void);
extern void OSDClearFuncMenu(void);
extern void OSDFocusFuncMenu(UCHAR id);
extern void OSDUnselectFuncItem(UCHAR id);
extern BOOL OSDIsFuncItemValid(UCHAR id);
extern BOOL OSDUserUpdate(void);
extern BOOL OSDTmgUpdate(void);
extern BOOL OSDSysUpdate(void);
extern BOOL OSDCalUpdate(void);
extern void OSDClosed(void);
extern void OSDInitFrame(UCHAR osdw, UCHAR osdh, USHRT clr);
extern void OSDShowNum(UCHAR x, UCHAR y, UCHAR value);
extern void OSDShowNum2(UCHAR x, UCHAR y, UCHAR value,UCHAR index);
extern void OSDShowSliderBar(UCHAR x, UCHAR y, UCHAR value, BOOL Sel, UCHAR Color);
extern void OSDMovePosition(void);
extern void OSDFocusBr(void);
extern void OSDFocusCn(void);
extern void OSDFocusAnimation(void);
extern void OSDFocusGamma(void);
extern void OSDFocusPhase(void);
extern void OSDFocusClock(void);
extern void OSDFocusInput(void);
extern void OSDFocusHPos(void);
extern void OSDFocusVPos(void);
extern void OSDFocusVolume(void);
extern void OSDFocusClrTmp(void);
extern void OSDFocusInput(void);
extern void OSDFocusReset(void);
extern void OSDShowLayer3SliderBar(UCHAR type,UCHAR redraw, BOOL Dlg);
extern void OSDShowBrightness(UCHAR redraw, BOOL Dlg);
extern void OSDShowContrast(UCHAR redraw, BOOL dlg);
extern void OSDShowSharpness(UCHAR redraw, BOOL Dlg);
extern void OSDShowHue(UCHAR redraw, BOOL Dlg);
extern void OSDShowSaturation(UCHAR redraw, BOOL Dlg);
extern void OSDShowPhase(UCHAR redraw, BOOL Dlg);
extern void OSDShowClock(UCHAR redraw, BOOL Dlg);
extern void OSDShowHPos(UCHAR redraw, BOOL Dlg);
extern void OSDShowVPos(UCHAR redraw, BOOL Dlg);
extern void OSDShowRGain(UCHAR redraw, BOOL Dlg);
extern void OSDShowGGain(UCHAR redraw, BOOL Dlg);
extern void OSDShowBGain(UCHAR redraw, BOOL Dlg);
extern void OSDShowVolume(UCHAR redraw, BOOL Dlg);
extern void OSDShowDynamicContrast(UCHAR redraw);
extern void OSDShowOSDTran(UCHAR redraw);
extern void OSDShowTimer(UCHAR redraw);
extern void OSDShowOD(UCHAR redraw);
extern void OSDBrightnessUp(void);
extern void OSDBrightnessDown(void);
extern void OSDContrastUp(void);
extern void OSDContrastDown(void);
extern void OSDCustVolumeDown(void);
extern void OSDCustVolumeUp(void);
extern void OSDCustBrightnessUp(void);
extern void OSDCustBrightnessDown(void);
extern void OSDCustContrastUp(void);
extern void OSDCustContrastDown(void);
extern void OSDCusAnimationUp(void);
extern void OSDCusAnimationDown(void);
extern void OSDSharpnessUp(void);
extern void OSDSharpnessDown(void);
extern void OSDVolumeUp(void);
extern void OSDVolumeDown(void);
extern void OSDGammaUp(void);
extern void OSDGammaDown(void);
extern void OSDPhaseUp(void);
extern void OSDPhaseDown(void);
extern void OSDClockUp(void);
extern void OSDClockDown(void);
extern void OSDHPositionUp(void);
extern void OSDHPositionDown(void);
extern void OSDVolumeUp(void);
extern void OSDVolumeDown(void);
extern void OSDVPositionUp(void);
extern void OSDVPositionDown(void);
extern void OSDColorTempUp(void);
extern void OSDColorTempDown(void);
extern void OSDRGainUp(void);
extern void OSDRGainDown(void);
extern void OSDGGainUp(void);
extern void OSDGGainDown(void);
extern void OSDBGainUp(void);
extern void OSDBGainDown(void);
extern void OSDInputSourceUp(void);
extern void OSDInputSourceDown(void);
extern void OSDDCRUp(void);
extern void OSDDCRDown(void);
extern void OSDAspectRatioUp(void);
extern void OSDAspectRatioDown(void);
extern void OSDSenseyeDemoUp(void);
extern void OSDSenseyeDemoDown(void);
extern void OSDODUp(void);
extern void OSDODDown(void);
extern void OSDShowBFMenu(void);
extern void OSDUpdateAutoTuneBar(UCHAR percentage);
extern void OSDShowComponentTimingResolution(UCHAR x, UCHAR y);
extern void OSDPerformAuto(void);
extern void OSDPerformAutoTune(void);
extern void OSDPerformNormal(void);
extern void OSDShowOSDLock(void);
extern void OSDShowNoSync(void);
extern void OSDShowNoCable(void);
extern void OSDShowOOL(void);
extern void OSDShowOOR(void);
extern void OSDSourceMenuITMUp(void);
extern void OSDSourceMenuITMDn(void);
extern void OSDBFMenuITMUp(void);
extern void OSDBFMenuITMDn(void);
extern void OSDBFMenuITMConfirm(BOOL bconfirm);
extern void OSDConfirmOSDRotation(void);
extern void OSDConfirmLanguage(void);
extern void OSDConfirmInput(void);
extern void OSDConfirmRecall(void);
extern void OSDConfirm3DCnvMode(void);
extern void OSDShowSelectPageMainFrame(UCHAR Type);
extern void OSDBlinkTopPageButton(UCHAR id);
extern void OSDBlinkSelectPageButton(UCHAR id, UCHAR act, BOOL Clr);
extern void OSDShowNoticeIcon(UCHAR Xoffset);
extern void OSDShowBenQMainFrame(UCHAR Type);

extern void OSDClearFrameBorder(UCHAR x, UCHAR y, UCHAR length, UCHAR height);
extern void OSDClearFrame(UCHAR Type);

extern void OSDShowTopPageMainFrame();
extern void OSDPageMainFrame(UCHAR Offsetx, UCHAR Offsety, UCHAR Width);
#if 0
extern void OSDShowDialogFrame(UCHAR osdw, UCHAR osdh);
#else
extern void OSDShowDialogFrame(UCHAR x, UCHAR y, UCHAR osdw, UCHAR osdh);
#endif
extern void OSDShowTrianIcon(UCHAR ucMethod, UCHAR id, UCHAR SeparaterLine);
extern void OSDShowStringSeparater(UCHAR LayerNum, BOOL Clr);
extern void OSDShowLayerSeparater(UCHAR SeparaterNum, UCHAR TrianglePos, BOOL Clr);
extern void OSDShowTitleString(void);
extern void OSDShowModeString(void);
extern void OSDShowLayer3Item(UCHAR id);
extern void OSDShowBigWin(UCHAR ucLayer, UCHAR ucBoarder);
extern void OSDShowMainMenu(void);
extern void OSDShowSmallWin(UCHAR id, UCHAR ucLayer);
extern void OSDInitialize(BOOL bForceInit);
extern void OSDShowLowBlueLightStrings(UCHAR x, UCHAR y);
extern void OSDShowCurrentResolution(UCHAR x, UCHAR y);
extern void OSDShowOptimumResolution(UCHAR x, UCHAR y);
extern void OSDSetPosition(USHRT x,USHRT y);
extern UCHAR OSDUpdateKeyInfo(BOOL bUpdate,USHRT usOsdState);//ULEric140328
extern void OSDShowItemHookIcon(UCHAR id,UCHAR ucPosX,UCHAR ucPosY,UCHAR ucCheckValue);//ULEric140331
extern void SetReShowMenuIdx(USHRT usReShowIdx);
extern void OSDReShowMenu(void);//ULEric140331
extern void OSDUpdateArrowIcon(USHRT usAttr, UCHAR ucType,UCHAR ucLayer);
extern void OSDSetAspectRatio(UCHAR ucAspectRatioType);//ULEric140402
extern void OSDSetBFMenuITM(UCHAR ucPictMode);//ULEric140402
extern void OSDClearItemHookIcon(UCHAR ucLayer);//ULEric140403
extern void OSDClearKeyColor(BOOL bIsRepratKey);//ULEric140409
extern BOOL OSDCheckBarAdjItem(void);//ULEric140409
extern void OSDClearDialogSpaceFrame(UCHAR sw, UCHAR sh, UCHAR ew, UCHAR eh);//ULEric140410
extern void OSDDialogBlinkSelectIcon(UCHAR ucIcon);//ULEric140410
extern UCHAR OSDGetTempPicMode(void);
extern void OSDShowCusKeyHook(UCHAR id, UCHAR CustomerKey);//ULEric140411
extern void OSDClearItemString(UCHAR ucLayerNo,UCHAR ucStart);
extern void OSDDPModeUp();
extern void OSDDPModeDown();
extern void OSDDPAutoSwitchUp();
extern void OSDDPAutoSwitchDown();
extern void OSDHDMIAutoSwitchUp();
extern void OSDHDMIAutoSwitchDown();
extern void OSDShowSmarReminder(void);
extern void OSDShowSensEyeDemo(void);
extern void OSDConfirmInputVGA(void);
extern void OSDConfirmInputDVI(void);
extern void OSDConfirmInputHDMI(void);
extern void OSDConfirmInputDP(void);
extern void OSDShowTiltleString(void);
extern void OSDShowAutoIcon(void);
extern BOOL OSDIsCustomkeyItemValid(UCHAR id);
extern void OSDDisableLayerWindow(void);
extern void OSDClearLayer(UCHAR LayerNum);
extern void OSDDrawTrianIcon(UCHAR Layer, UCHAR TmpID, UCHAR iconIdx, USHRT attr);
extern void OSDDrawLayerSeparaterLine(UCHAR x ,UCHAR y, BOOL Clr);
extern void OSDClearLayer3(void);

extern void OSDSmartScalingUp(void);
extern void OSDSmartScalingDown(void);
extern void OSDDrawCustomMenuFrame(UCHAR FrameType);
extern void OSDDrawCustomMenuFrame(UCHAR FrameType);
extern UCHAR isCustomMenuSlider(void);
extern UCHAR isAnyCustomKey(UCHAR type);
extern void OSDUpdateCustomHook (UCHAR x, UCHAR y, UCHAR value);
extern void OSDDrawCustomHook (UCHAR x, UCHAR y, UCHAR value);

extern BOOL OSDCheckHookIcon(void);
void OSDUpdateSelectPageIcon_Left(UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer);
void OSDUpdateSelectPageIcon_Bottom(UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer);

void OSDEyeProtectBrightnessUp(void);
void OSDEyeProtectBrightnessDown(void);

#endif
