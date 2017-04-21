#ifndef __OSD_VIEW3_H__
#define __OSD_VIEW3_H__

extern UCHAR ucEcoMeter_PosTab[15];
extern UCHAR ucEcoMeterCycle_PosTab[12];
//extern UCHAR *ucEcoMeterIconInfoTab[2];


extern void OSDShowDialog(UCHAR dlg, UCHAR keyID);
extern void OSDShowSelectPageButton_Bottom(UCHAR id, UCHAR act, BOOL Clr);
extern void OSDShowSelectPageButton_Left(UCHAR id, UCHAR act, BOOL Clr);
extern void OSDShowECOMeterNotice(void);
extern void OSDShowECOMeterBorder(void);
extern void OSDShowECOMeterIcon(void);
extern void OSDShowECOMeterCycle(UCHAR step);
extern void OSDShowEyeProtectMeterIcon(void);
extern void OSDShowEyeProtectMeterWin(void);
extern void OSDPageMainFrame_Left(UCHAR Offset_x, UCHAR Offset_y, UCHAR Width);
extern void OSDEnterEyeProtectMeterNotice(void);
extern void OSDDisableWinRotation(void);
extern void OSDShowLayer3PageHookIcon(UCHAR pageNum);
extern void OSDShowLayer4SliderBar(UCHAR type,UCHAR redraw);
extern BOOL isOSDClearLayer4(UCHAR ItemID);

extern UCHAR isOSDAllowDCR (void);
extern UCHAR isOSDAllowSenseyeDemo (void);
#if ENABLE_EYE_PROTECT == ON
extern BOOL isOSDAllowEyeProtect (void);
extern BOOL isOSDAllowEyeProtectMeter (void);
#endif
#if ENABLE_ECO_SENSOR == ON
extern BOOL isOSDAllowECOSensor (void);
extern BOOL isOSDAllowECOMeterRange (void);
#endif
extern BOOL isOSDAllowResNotice(void);
extern BOOL isOSDCusKeyBriConDisable(void);
extern BOOL isOSDRotationAvailable(void);
extern BOOL isOSDMainIconAvailable(UCHAR MainIconID);

#endif
