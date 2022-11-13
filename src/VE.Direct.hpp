// VE.Direct-Protocol-3.32.pdf
#ifndef _VE_DIRECT_H_   /* Include guard */
#define _VE_DIRECT_H_

#include "GlobalDefines.hpp"
#include <Arduino.h>

struct UIStringUInt8Id {
  uint8_t id;
  char uiLabel[17]; // 16 chars null-terminated
};

struct UIStringInt8Id {
  int8_t id;
  char uiLabel[17];
};

struct UIStringUInt16Id {
  uint16_t id;
  char uiLabel[17];
};

struct UIStringUInt32Id {
  uint32_t id;
  char uiLabel[17];
};

/* Victron product group */
#define kPG_BMV_60x          0b00000001
#define kPG_BMV_70x          0b00000010
#define kPG_BMV_71x          0b00000100
#define kPG_MPPT             0b00001000
#define kPG_Phoenix_Inverter 0b00010000
#define kPG_Phoenix_Charger  0b00100000
#define kPG_All              0b00111111

const uint8_t productGroupsIndex[] = { 
  kPG_BMV_60x, 
  kPG_BMV_70x, 
  kPG_BMV_71x, 
  kPG_MPPT, 
  kPG_Phoenix_Inverter, 
  kPG_Phoenix_Charger 
};

const UIStringUInt8Id productGroupsLabels[] PROGMEM = {
  { kPG_BMV_60x, "BMV 60x" },
  { kPG_BMV_70x, "BMV 70x" },
  { kPG_BMV_71x, "BMV 71x/SmSh" },
  { kPG_MPPT, "MPPT Chrg Contrl" },
  { kPG_Phoenix_Inverter, "Phoenix Inverter" },
  { kPG_Phoenix_Charger, "Phoenix Charger" },
};

/* PID - Victron Product IDs */
#define kPID_BMV_700 0x203
#define kPID_BMV_702 0x204
#define kPID_BMV_700H 0x205
#define kPID_BlueSolar_MPPT_70_15_deprecated 0x0300
#define kPID_BlueSolar_MPPT_75_50_deprecated 0xA040
#define kPID_BlueSolar_MPPT_150_35_deprecated 0xA041
#define kPID_BlueSolar_MPPT_75_15 0xA042
#define kPID_BlueSolar_MPPT_100_15 0xA043
#define kPID_BlueSolar_MPPT_100_30_deprecated 0xA044
#define kPID_BlueSolar_MPPT_100_50_deprecated 0xA045
#define kPID_BlueSolar_MPPT_150_70 0xA046
#define kPID_BlueSolar_MPPT_150_100 0xA047
#define kPID_BlueSolar_MPPT_100_50_rev2 0xA049
#define kPID_BlueSolar_MPPT_100_30_rev2 0xA04A
#define kPID_BlueSolar_MPPT_150_35_rev2 0xA04B
#define kPID_BlueSolar_MPPT_75_10 0xA04C
#define kPID_BlueSolar_MPPT_150_45 0xA04D
#define kPID_BlueSolar_MPPT_150_60 0xA04E
#define kPID_BlueSolar_MPPT_150_85 0xA04F
#define kPID_SmartSolar_MPPT_250_100 0xA050
#define kPID_SmartSolar_MPPT_150_100_deprecated 0xA051
#define kPID_SmartSolar_MPPT_150_85_deprecated 0xA052
#define kPID_SmartSolar_MPPT_75_15 0xA053
#define kPID_SmartSolar_MPPT_75_10 0xA054
#define kPID_SmartSolar_MPPT_100_15 0xA055
#define kPID_SmartSolar_MPPT_100_30 0xA056
#define kPID_SmartSolar_MPPT_100_50 0xA057
#define kPID_SmartSolar_MPPT_150_35 0xA058
#define kPID_SmartSolar_MPPT_150_100_rev2 0xA059
#define kPID_SmartSolar_MPPT_150_85_rev2 0xA05A
#define kPID_SmartSolar_MPPT_250_70 0xA05B
#define kPID_SmartSolar_MPPT_250_85 0xA05C
#define kPID_SmartSolar_MPPT_250_60 0xA05D
#define kPID_SmartSolar_MPPT_250_45 0xA05E
#define kPID_SmartSolar_MPPT_100_20 0xA05F
#define kPID_SmartSolar_MPPT_100_20_48v 0xA060
#define kPID_SmartSolar_MPPT_150_45 0xA061
#define kPID_SmartSolar_MPPT_150_60 0xA062
#define kPID_SmartSolar_MPPT_150_70 0xA063
#define kPID_SmartSolar_MPPT_250_85_rev2 0xA064
#define kPID_SmartSolar_MPPT_250_100_rev2 0xA065
#define kPID_BlueSolar_MPPT_100_20 0xA066
#define kPID_BlueSolar_MPPT_100_20_48v 0xA067
#define kPID_SmartSolar_MPPT_250_60_rev2 0xA068
#define kPID_SmartSolar_MPPT_250_70_rev2 0xA069
#define kPID_SmartSolar_MPPT_150_45_rev2 0xA06A
#define kPID_SmartSolar_MPPT_150_60_rev2 0xA06B
#define kPID_SmartSolar_MPPT_150_70_rev2 0xA06C
#define kPID_SmartSolar_MPPT_150_85_rev3 0xA06D
#define kPID_SmartSolar_MPPT_150_100_rev3 0xA06E
#define kPID_BlueSolar_MPPT_150_45_rev2 0xA06F
#define kPID_BlueSolar_MPPT_150_60_rev2 0xA070
#define kPID_BlueSolar_MPPT_150_70_rev2 0xA071
#define kPID_SmartSolar_MPPT_VE_Can_150_70 0xA102
#define kPID_SmartSolar_MPPT_VE_Can_150_45 0xA103
#define kPID_SmartSolar_MPPT_VE_Can_150_60 0xA104
#define kPID_SmartSolar_MPPT_VE_Can_150_85 0xA105
#define kPID_SmartSolar_MPPT_VE_Can_150_100 0xA106
#define kPID_SmartSolar_MPPT_VE_Can_250_45 0xA107
#define kPID_SmartSolar_MPPT_VE_Can_250_60 0xA108
#define kPID_SmartSolar_MPPT_VE_Can_250_70 0xA109
#define kPID_SmartSolar_MPPT_VE_Can_250_85 0xA10A
#define kPID_SmartSolar_MPPT_VE_Can_250_100 0xA10B
#define kPID_SmartSolar_MPPT_VE_Can_150_70_rev2 0xA10C
#define kPID_SmartSolar_MPPT_VE_Can_150_85_rev2 0xA10D
#define kPID_SmartSolar_MPPT_VE_Can_150_100_rev2 0xA10E
#define kPID_BlueSolar_MPPT_VE_Can_150_100 0xA10F
#define kPID_BlueSolar_MPPT_VE_Can_250_70 0xA112
#define kPID_BlueSolar_MPPT_VE_Can_250_100 0xA113
#define kPID_SmartSolar_MPPT_VE_Can_250_70_rev2 0xA114
#define kPID_SmartSolar_MPPT_VE_Can_250_100_rev2 0xA115
#define kPID_SmartSolar_MPPT_VE_Can_250_85_rev2 0xA116
#define kPID_Phoenix_Inverter_12v_250va_230v_deprecated 0xA201
#define kPID_Phoenix_Inverter_24v_250va_230v_deprecated 0xA202
#define kPID_Phoenix_Inverter_48v_250va_230v_deprecated 0xA204
#define kPID_Phoenix_Inverter_12v_375va_230v_deprecated 0xA211
#define kPID_Phoenix_Inverter_24v_375va_230v_deprecated 0xA212
#define kPID_Phoenix_Inverter_48v_375va_230v_deprecated 0xA214
#define kPID_Phoenix_Inverter_12v_500va_230v_deprecated 0xA221
#define kPID_Phoenix_Inverter_24v_500va_230v_deprecated 0xA222
#define kPID_Phoenix_Inverter_48v_500va_230v_deprecated 0xA224
#define kPID_Phoenix_Inverter_12v_250va_230v 0xA231
#define kPID_Phoenix_Inverter_24v_250va_230v 0xA232
#define kPID_Phoenix_Inverter_48v_250va_230v 0xA234
#define kPID_Phoenix_Inverter_12v_250va_120v 0xA239
#define kPID_Phoenix_Inverter_24v_250va_120v 0xA23A
#define kPID_Phoenix_Inverter_48v_250va_120v 0xA23C
#define kPID_Phoenix_Inverter_12v_375va_230v 0xA241
#define kPID_Phoenix_Inverter_24v_375va_230v 0xA242
#define kPID_Phoenix_Inverter_48v_375va_230v 0xA244
#define kPID_Phoenix_Inverter_12v_375va_120v 0xA249
#define kPID_Phoenix_Inverter_24v_375va_120v 0xA24A
#define kPID_Phoenix_Inverter_48v_375va_120v 0xA24C
#define kPID_Phoenix_Inverter_12v_500va_230v 0xA251
#define kPID_Phoenix_Inverter_24v_500va_230v 0xA252 
#define kPID_Phoenix_Inverter_48v_500va_230v 0xA254
#define kPID_Phoenix_Inverter_12v_500va_120v 0xA259
#define kPID_Phoenix_Inverter_24v_500va_120v 0xA25A
#define kPID_Phoenix_Inverter_48v_500va_120v 0xA25C
#define kPID_Phoenix_Inverter_12v_800va_230v 0xA261
#define kPID_Phoenix_Inverter_24v_800va_230v 0xA262
#define kPID_Phoenix_Inverter_48v_800va_230v 0xA264
#define kPID_Phoenix_Inverter_12v_800va_120v 0xA269
#define kPID_Phoenix_Inverter_24v_800va_120v 0xA26A
#define kPID_Phoenix_Inverter_48v_800va_120v 0xA26C
#define kPID_Phoenix_Inverter_12v_1200va_230v 0xA271
#define kPID_Phoenix_Inverter_24v_1200va_230v 0xA272
#define kPID_Phoenix_Inverter_48v_1200va_230v 0xA274
#define kPID_Phoenix_Inverter_12v_1200va_120v 0xA279
#define kPID_Phoenix_Inverter_24v_1200va_120v 0xA27A
#define kPID_Phoenix_Inverter_48v_1200va_120v 0xA27C
#define kPID_Phoenix_Inverter_12v_1600va_230v 0xA281
#define kPID_Phoenix_Inverter_24v_1600va_230v 0xA282
#define kPID_Phoenix_Inverter_48v_1600va_230v 0xA284
#define kPID_Phoenix_Inverter_12v_2000va_230v 0xA291
#define kPID_Phoenix_Inverter_24v_2000va_230v 0xA292
#define kPID_Phoenix_Inverter_48v_2000va_230v 0xA294
#define kPID_Phoenix_Inverter_12v_3000va_230v 0xA2A1
#define kPID_Phoenix_Inverter_24v_3000va_230v 0xA2A2
#define kPID_Phoenix_Inverter_48v_3000va_230v 0xA2A4
#define kPID_Phoenix_Smart_IP43_Charger_12_50_1_1 0xA340
#define kPID_Phoenix_Smart_IP43_Charger_12_50_3 0xA341
#define kPID_Phoenix_Smart_IP43_Charger_24_25_1_1 0xA342
#define kPID_Phoenix_Smart_IP43_Charger_24_25_3 0xA343
#define kPID_Phoenix_Smart_IP43_Charger_12_30_1_1 0xA344
#define kPID_Phoenix_Smart_IP43_Charger_12_30_3 0xA345
#define kPID_Phoenix_Smart_IP43_Charger_24_16_1_1 0xA346
#define kPID_Phoenix_Smart_IP43_Charger_24_16_3 0xA347
#define kPID_BMV_712_Smart 0xA381
#define kPID_BMV_710H_Smart 0xA382
#define kPID_BMV_712_Smart_rev2 0xA383
#define kPID_SmartShunt_500a_50mv 0xA389
#define kPID_SmartShunt_1000a_50mv 0xA38A
#define kPID_SmartShunt_2000a_50mv 0xA38B

struct VictronProduct {
  uint16_t id;
  uint8_t group;
  char uiLabel[17];
};

const uint16_t pidIndex[] = {
  kPID_BMV_700,
  kPID_BMV_702,
  kPID_BMV_700H,
  kPID_BlueSolar_MPPT_70_15_deprecated,
  kPID_BlueSolar_MPPT_75_50_deprecated,
  kPID_BlueSolar_MPPT_150_35_deprecated,
  kPID_BlueSolar_MPPT_75_15,
  kPID_BlueSolar_MPPT_100_15,
  kPID_BlueSolar_MPPT_100_30_deprecated,
  kPID_BlueSolar_MPPT_100_50_deprecated,
  kPID_BlueSolar_MPPT_150_70,
  kPID_BlueSolar_MPPT_150_100,
  kPID_BlueSolar_MPPT_100_50_rev2,
  kPID_BlueSolar_MPPT_100_30_rev2,
  kPID_BlueSolar_MPPT_150_35_rev2,
  kPID_BlueSolar_MPPT_75_10,
  kPID_BlueSolar_MPPT_150_45,
  kPID_BlueSolar_MPPT_150_60,
  kPID_BlueSolar_MPPT_150_85,
  kPID_SmartSolar_MPPT_250_100,
  kPID_SmartSolar_MPPT_150_100_deprecated,
  kPID_SmartSolar_MPPT_150_85_deprecated,
  kPID_SmartSolar_MPPT_75_15,
  kPID_SmartSolar_MPPT_75_10,
  kPID_SmartSolar_MPPT_100_15,
  kPID_SmartSolar_MPPT_100_30,
  kPID_SmartSolar_MPPT_100_50,
  kPID_SmartSolar_MPPT_150_35,
  kPID_SmartSolar_MPPT_150_100_rev2,
  kPID_SmartSolar_MPPT_150_85_rev2,
  kPID_SmartSolar_MPPT_250_70,
  kPID_SmartSolar_MPPT_250_85,
  kPID_SmartSolar_MPPT_250_60,
  kPID_SmartSolar_MPPT_250_45,
  kPID_SmartSolar_MPPT_100_20,
  kPID_SmartSolar_MPPT_100_20_48v,
  kPID_SmartSolar_MPPT_150_45,
  kPID_SmartSolar_MPPT_150_60,
  kPID_SmartSolar_MPPT_150_70,
  kPID_SmartSolar_MPPT_250_85_rev2,
  kPID_SmartSolar_MPPT_250_100_rev2,
  kPID_BlueSolar_MPPT_100_20,
  kPID_BlueSolar_MPPT_100_20_48v,
  kPID_SmartSolar_MPPT_250_60_rev2,
  kPID_SmartSolar_MPPT_250_70_rev2,
  kPID_SmartSolar_MPPT_150_45_rev2,
  kPID_SmartSolar_MPPT_150_60_rev2,
  kPID_SmartSolar_MPPT_150_70_rev2,
  kPID_SmartSolar_MPPT_150_85_rev3,
  kPID_SmartSolar_MPPT_150_100_rev3,
  kPID_BlueSolar_MPPT_150_45_rev2,
  kPID_BlueSolar_MPPT_150_60_rev2,
  kPID_BlueSolar_MPPT_150_70_rev2,
  kPID_SmartSolar_MPPT_VE_Can_150_70,
  kPID_SmartSolar_MPPT_VE_Can_150_45,
  kPID_SmartSolar_MPPT_VE_Can_150_60,
  kPID_SmartSolar_MPPT_VE_Can_150_85,
  kPID_SmartSolar_MPPT_VE_Can_150_100,
  kPID_SmartSolar_MPPT_VE_Can_250_45,
  kPID_SmartSolar_MPPT_VE_Can_250_60,
  kPID_SmartSolar_MPPT_VE_Can_250_70,
  kPID_SmartSolar_MPPT_VE_Can_250_85,
  kPID_SmartSolar_MPPT_VE_Can_250_100,
  kPID_SmartSolar_MPPT_VE_Can_150_70_rev2,
  kPID_SmartSolar_MPPT_VE_Can_150_85_rev2,
  kPID_SmartSolar_MPPT_VE_Can_150_100_rev2,
  kPID_BlueSolar_MPPT_VE_Can_150_100,
  kPID_BlueSolar_MPPT_VE_Can_250_70,
  kPID_BlueSolar_MPPT_VE_Can_250_100,
  kPID_SmartSolar_MPPT_VE_Can_250_70_rev2,
  kPID_SmartSolar_MPPT_VE_Can_250_100_rev2,
  kPID_SmartSolar_MPPT_VE_Can_250_85_rev2,
  kPID_Phoenix_Inverter_12v_250va_230v_deprecated,
  kPID_Phoenix_Inverter_24v_250va_230v_deprecated,
  kPID_Phoenix_Inverter_48v_250va_230v_deprecated,
  kPID_Phoenix_Inverter_12v_375va_230v_deprecated,
  kPID_Phoenix_Inverter_24v_375va_230v_deprecated,
  kPID_Phoenix_Inverter_48v_375va_230v_deprecated,
  kPID_Phoenix_Inverter_12v_500va_230v_deprecated,
  kPID_Phoenix_Inverter_24v_500va_230v_deprecated,
  kPID_Phoenix_Inverter_48v_500va_230v_deprecated,
  kPID_Phoenix_Inverter_12v_250va_230v,
  kPID_Phoenix_Inverter_24v_250va_230v,
  kPID_Phoenix_Inverter_48v_250va_230v,
  kPID_Phoenix_Inverter_12v_250va_120v,
  kPID_Phoenix_Inverter_24v_250va_120v,
  kPID_Phoenix_Inverter_48v_250va_120v,
  kPID_Phoenix_Inverter_12v_375va_230v,
  kPID_Phoenix_Inverter_24v_375va_230v,
  kPID_Phoenix_Inverter_48v_375va_230v,
  kPID_Phoenix_Inverter_12v_375va_120v,
  kPID_Phoenix_Inverter_24v_375va_120v,
  kPID_Phoenix_Inverter_48v_375va_120v,
  kPID_Phoenix_Inverter_12v_500va_230v,
  kPID_Phoenix_Inverter_24v_500va_230v, 
  kPID_Phoenix_Inverter_48v_500va_230v,
  kPID_Phoenix_Inverter_12v_500va_120v,
  kPID_Phoenix_Inverter_24v_500va_120v,
  kPID_Phoenix_Inverter_48v_500va_120v,
  kPID_Phoenix_Inverter_12v_800va_230v,
  kPID_Phoenix_Inverter_24v_800va_230v,
  kPID_Phoenix_Inverter_48v_800va_230v,
  kPID_Phoenix_Inverter_12v_800va_120v,
  kPID_Phoenix_Inverter_24v_800va_120v,
  kPID_Phoenix_Inverter_48v_800va_120v,
  kPID_Phoenix_Inverter_12v_1200va_230v,
  kPID_Phoenix_Inverter_24v_1200va_230v,
  kPID_Phoenix_Inverter_48v_1200va_230v,
  kPID_Phoenix_Inverter_12v_1200va_120v,
  kPID_Phoenix_Inverter_24v_1200va_120v,
  kPID_Phoenix_Inverter_48v_1200va_120v,
  kPID_Phoenix_Inverter_12v_1600va_230v,
  kPID_Phoenix_Inverter_24v_1600va_230v,
  kPID_Phoenix_Inverter_48v_1600va_230v,
  kPID_Phoenix_Inverter_12v_2000va_230v,
  kPID_Phoenix_Inverter_24v_2000va_230v,
  kPID_Phoenix_Inverter_48v_2000va_230v,
  kPID_Phoenix_Inverter_12v_3000va_230v,
  kPID_Phoenix_Inverter_24v_3000va_230v,
  kPID_Phoenix_Inverter_48v_3000va_230v,
  kPID_Phoenix_Smart_IP43_Charger_12_50_1_1,
  kPID_Phoenix_Smart_IP43_Charger_12_50_3,
  kPID_Phoenix_Smart_IP43_Charger_24_25_1_1,
  kPID_Phoenix_Smart_IP43_Charger_24_25_3,
  kPID_Phoenix_Smart_IP43_Charger_12_30_1_1,
  kPID_Phoenix_Smart_IP43_Charger_12_30_3,
  kPID_Phoenix_Smart_IP43_Charger_24_16_1_1,
  kPID_Phoenix_Smart_IP43_Charger_24_16_3,
  kPID_BMV_712_Smart,
  kPID_BMV_710H_Smart,
  kPID_BMV_712_Smart_rev2,
  kPID_SmartShunt_500a_50mv,
  kPID_SmartShunt_1000a_50mv,
  kPID_SmartShunt_2000a_50mv, 
};

const VictronProduct victronProducts[] PROGMEM = {
  { kPID_BMV_700, kPG_BMV_70x, "BMV-700" },
  { kPID_BMV_702, kPG_BMV_70x, "BMV-702" },
  { kPID_BMV_700H, kPG_BMV_70x, "BMV-700H" },
  { kPID_BlueSolar_MPPT_70_15_deprecated, kPG_MPPT, "BlueSolar 70/15" },
  { kPID_BlueSolar_MPPT_75_50_deprecated, kPG_MPPT, "BlueSolar 75/50" },
  { kPID_BlueSolar_MPPT_150_35_deprecated, kPG_MPPT, "BlueSolar 150/35" },
  { kPID_BlueSolar_MPPT_75_15, kPG_MPPT, "BlueSolar 75/15" },
  { kPID_BlueSolar_MPPT_100_15, kPG_MPPT, "BlueSolar 100/15" },
  { kPID_BlueSolar_MPPT_100_30_deprecated, kPG_MPPT, "BlueSolar 100/30" },
  { kPID_BlueSolar_MPPT_100_50_deprecated, kPG_MPPT, "BlueSolar 100/50" },
  { kPID_BlueSolar_MPPT_150_70, kPG_MPPT, "BlueSolar 150/70" },
  { kPID_BlueSolar_MPPT_150_100, kPG_MPPT, "BlueSolr 150/100" },
  { kPID_BlueSolar_MPPT_100_50_rev2, kPG_MPPT, "BlueSolar 100/50" },
  { kPID_BlueSolar_MPPT_100_30_rev2, kPG_MPPT, "BlueSolar 100/30" },
  { kPID_BlueSolar_MPPT_150_35_rev2, kPG_MPPT, "BlueSolar 150/35" },
  { kPID_BlueSolar_MPPT_75_10, kPG_MPPT, "BlueSolar 75/10" },
  { kPID_BlueSolar_MPPT_150_45, kPG_MPPT, "BlueSolar 150/45" },
  { kPID_BlueSolar_MPPT_150_60, kPG_MPPT, "BlueSolar 150/60" },
  { kPID_BlueSolar_MPPT_150_85, kPG_MPPT, "BlueSolar 150/85" },
  { kPID_SmartSolar_MPPT_250_100, kPG_MPPT, "SmartSlr 250/100" },
  { kPID_SmartSolar_MPPT_150_100_deprecated, kPG_MPPT, "SmartSlr 150/100" },
  { kPID_SmartSolar_MPPT_150_85_deprecated, kPG_MPPT, "SmartSolr 150/85" },
  { kPID_SmartSolar_MPPT_75_15, kPG_MPPT, "SmartSolar 75/15" },
  { kPID_SmartSolar_MPPT_75_10, kPG_MPPT, "SmartSolar 75/10" },
  { kPID_SmartSolar_MPPT_100_15, kPG_MPPT, "SmartSolr 100/15" },
  { kPID_SmartSolar_MPPT_100_30, kPG_MPPT, "SmartSolr 100/30" },
  { kPID_SmartSolar_MPPT_100_50, kPG_MPPT, "SmartSolr 100/50" },
  { kPID_SmartSolar_MPPT_150_35, kPG_MPPT, "SmartSolr 150/35" },
  { kPID_SmartSolar_MPPT_150_100_rev2, kPG_MPPT, "SmartSlr 150/100" },
  { kPID_SmartSolar_MPPT_150_85_rev2, kPG_MPPT, "SmartSolr 150/85" },
  { kPID_SmartSolar_MPPT_250_70, kPG_MPPT, "SmartSolr 250/70" },
  { kPID_SmartSolar_MPPT_250_85, kPG_MPPT, "SmartSolr 250/85" },
  { kPID_SmartSolar_MPPT_250_60, kPG_MPPT, "SmartSolr 250/60" },
  { kPID_SmartSolar_MPPT_250_45, kPG_MPPT, "SmartSolr 250/45" },
  { kPID_SmartSolar_MPPT_100_20, kPG_MPPT, "SmartSolr 100/20" },
  { kPID_SmartSolar_MPPT_100_20_48v, kPG_MPPT, "SmartSolr 100/20" },
  { kPID_SmartSolar_MPPT_150_45, kPG_MPPT, "SmartSolr 150/45" },
  { kPID_SmartSolar_MPPT_150_60, kPG_MPPT, "SmartSolr 150/60" },
  { kPID_SmartSolar_MPPT_150_70, kPG_MPPT, "SmartSolr 150/70" },
  { kPID_SmartSolar_MPPT_250_85_rev2, kPG_MPPT, "SmartSolr 250/85" },
  { kPID_SmartSolar_MPPT_250_100_rev2, kPG_MPPT, "SmartSlr 250/100" },
  { kPID_BlueSolar_MPPT_100_20, kPG_MPPT, "BlueSolar 100/20" },
  { kPID_BlueSolar_MPPT_100_20_48v, kPG_MPPT, "BlueSolar 100/20" },
  { kPID_SmartSolar_MPPT_250_60_rev2, kPG_MPPT, "SmartSolr 250/60" },
  { kPID_SmartSolar_MPPT_250_70_rev2, kPG_MPPT, "SmartSolr 250/70" },
  { kPID_SmartSolar_MPPT_150_45_rev2, kPG_MPPT, "SmartSolr 150/45" },
  { kPID_SmartSolar_MPPT_150_60_rev2, kPG_MPPT, "SmartSolr 150/60" },
  { kPID_SmartSolar_MPPT_150_70_rev2, kPG_MPPT, "SmartSolr 150/70" },
  { kPID_SmartSolar_MPPT_150_85_rev3, kPG_MPPT, "SmartSolr 150/85" },
  { kPID_SmartSolar_MPPT_150_100_rev3, kPG_MPPT, "SmartSlr 150/100" },
  { kPID_BlueSolar_MPPT_150_45_rev2, kPG_MPPT, "BlueSolar 150/45" },
  { kPID_BlueSolar_MPPT_150_60_rev2, kPG_MPPT, "BlueSolar 150/60" },
  { kPID_BlueSolar_MPPT_150_70_rev2, kPG_MPPT, "BlueSolar 150/70" },
  { kPID_SmartSolar_MPPT_VE_Can_150_70, kPG_MPPT, "SmartSolr 150/70" },
  { kPID_SmartSolar_MPPT_VE_Can_150_45, kPG_MPPT, "SmartSolr 150/45" },
  { kPID_SmartSolar_MPPT_VE_Can_150_60, kPG_MPPT, "SmartSolr 150/60" },
  { kPID_SmartSolar_MPPT_VE_Can_150_85, kPG_MPPT, "SmartSolr 150/85" },
  { kPID_SmartSolar_MPPT_VE_Can_150_100, kPG_MPPT, "SmartSlr 150/100" },
  { kPID_SmartSolar_MPPT_VE_Can_250_45, kPG_MPPT, "SmartSolr 250/45" },
  { kPID_SmartSolar_MPPT_VE_Can_250_60, kPG_MPPT, "SmartSolr 250/60" },
  { kPID_SmartSolar_MPPT_VE_Can_250_70, kPG_MPPT, "SmartSolr 250/70" },
  { kPID_SmartSolar_MPPT_VE_Can_250_85, kPG_MPPT, "SmartSolr 250/85" },
  { kPID_SmartSolar_MPPT_VE_Can_250_100, kPG_MPPT, "SmartSlr 250/100" },
  { kPID_SmartSolar_MPPT_VE_Can_150_70_rev2, kPG_MPPT, "SmartSolr 150/70" },
  { kPID_SmartSolar_MPPT_VE_Can_150_85_rev2, kPG_MPPT, "SmartSolr 150/85" },
  { kPID_SmartSolar_MPPT_VE_Can_150_100_rev2, kPG_MPPT, "SmartSlr 150/100" },
  { kPID_BlueSolar_MPPT_VE_Can_150_100, kPG_MPPT, "BlueSolr 150/100" },
  { kPID_BlueSolar_MPPT_VE_Can_250_70, kPG_MPPT, "BlueSolar 250/70" },
  { kPID_BlueSolar_MPPT_VE_Can_250_100, kPG_MPPT, "BlueSolr 250/100" },
  { kPID_SmartSolar_MPPT_VE_Can_250_70_rev2, kPG_MPPT, "SmartSolr 250/70" },
  { kPID_SmartSolar_MPPT_VE_Can_250_100_rev2, kPG_MPPT, "SmartSlr 250/100" },
  { kPID_SmartSolar_MPPT_VE_Can_250_85_rev2, kPG_MPPT, "SmartSolr 250/85" },
  { kPID_Phoenix_Inverter_12v_250va_230v_deprecated, kPG_Phoenix_Inverter, "12V/250VA/230V" },
  { kPID_Phoenix_Inverter_24v_250va_230v_deprecated, kPG_Phoenix_Inverter, "24V/250VA/230V" },
  { kPID_Phoenix_Inverter_48v_250va_230v_deprecated, kPG_Phoenix_Inverter, "48V/250VA/230V" },
  { kPID_Phoenix_Inverter_12v_375va_230v_deprecated, kPG_Phoenix_Inverter, "12V/375VA/230V" },
  { kPID_Phoenix_Inverter_24v_375va_230v_deprecated, kPG_Phoenix_Inverter, "24V/375VA/230V" },
  { kPID_Phoenix_Inverter_48v_375va_230v_deprecated, kPG_Phoenix_Inverter, "48V/375VA/230V" },
  { kPID_Phoenix_Inverter_12v_500va_230v_deprecated, kPG_Phoenix_Inverter, "12V/500VA/230V" },
  { kPID_Phoenix_Inverter_24v_500va_230v_deprecated, kPG_Phoenix_Inverter, "24V/500VA/230V" },
  { kPID_Phoenix_Inverter_48v_500va_230v_deprecated, kPG_Phoenix_Inverter, "48V/500VA/230V" },
  { kPID_Phoenix_Inverter_12v_250va_230v, kPG_Phoenix_Inverter, "12V/250VA/230V" },
  { kPID_Phoenix_Inverter_24v_250va_230v, kPG_Phoenix_Inverter, "24V/250VA/230V" },
  { kPID_Phoenix_Inverter_48v_250va_230v, kPG_Phoenix_Inverter, "48V/250VA/230V" },
  { kPID_Phoenix_Inverter_12v_250va_120v, kPG_Phoenix_Inverter, "12V/250VA/120V" },
  { kPID_Phoenix_Inverter_24v_250va_120v, kPG_Phoenix_Inverter, "24V/250VA/120V" },
  { kPID_Phoenix_Inverter_48v_250va_120v, kPG_Phoenix_Inverter, "48V/250VA/120V" },
  { kPID_Phoenix_Inverter_12v_375va_230v, kPG_Phoenix_Inverter, "12V/375VA/230V" },
  { kPID_Phoenix_Inverter_24v_375va_230v, kPG_Phoenix_Inverter, "24V/375VA/230V" },
  { kPID_Phoenix_Inverter_48v_375va_230v, kPG_Phoenix_Inverter, "48V/375VA/230V" },
  { kPID_Phoenix_Inverter_12v_375va_120v, kPG_Phoenix_Inverter, "12V/375VA/120V" },
  { kPID_Phoenix_Inverter_24v_375va_120v, kPG_Phoenix_Inverter, "24V/375VA/120V" },
  { kPID_Phoenix_Inverter_48v_375va_120v, kPG_Phoenix_Inverter, "48V/375VA/120V" },
  { kPID_Phoenix_Inverter_12v_500va_230v, kPG_Phoenix_Inverter, "12V/500VA/230V" },
  { kPID_Phoenix_Inverter_24v_500va_230v, kPG_Phoenix_Inverter, "24V/500VA/230V" },
  { kPID_Phoenix_Inverter_48v_500va_230v, kPG_Phoenix_Inverter, "48V/500VA/230V" },
  { kPID_Phoenix_Inverter_12v_500va_120v, kPG_Phoenix_Inverter, "12V/500VA/120V" },
  { kPID_Phoenix_Inverter_24v_500va_120v, kPG_Phoenix_Inverter, "24V/500VA/120V" },
  { kPID_Phoenix_Inverter_48v_500va_120v, kPG_Phoenix_Inverter, "48V/500VA/120V" },
  { kPID_Phoenix_Inverter_12v_800va_230v, kPG_Phoenix_Inverter, "12V/800VA/230V" },
  { kPID_Phoenix_Inverter_24v_800va_230v, kPG_Phoenix_Inverter, "24V/800VA/230V" },
  { kPID_Phoenix_Inverter_48v_800va_230v, kPG_Phoenix_Inverter, "48V/800VA/230V" },
  { kPID_Phoenix_Inverter_12v_800va_120v, kPG_Phoenix_Inverter, "12V/800VA/120V" },
  { kPID_Phoenix_Inverter_24v_800va_120v, kPG_Phoenix_Inverter, "24V/800VA/120V" },
  { kPID_Phoenix_Inverter_48v_800va_120v, kPG_Phoenix_Inverter, "48V/800VA/120V" },
  { kPID_Phoenix_Inverter_12v_1200va_230v, kPG_Phoenix_Inverter, "12V/1200VA/230V" },
  { kPID_Phoenix_Inverter_24v_1200va_230v, kPG_Phoenix_Inverter, "24V/1200VA/230V" },
  { kPID_Phoenix_Inverter_48v_1200va_230v, kPG_Phoenix_Inverter, "48V/1200VA/230V" },
  { kPID_Phoenix_Inverter_12v_1200va_120v, kPG_Phoenix_Inverter, "12V/1200VA/120V" },
  { kPID_Phoenix_Inverter_24v_1200va_120v, kPG_Phoenix_Inverter, "24V/1200VA/120V" },
  { kPID_Phoenix_Inverter_48v_1200va_120v, kPG_Phoenix_Inverter, "48V/1200VA/120V" },
  { kPID_Phoenix_Inverter_12v_1600va_230v, kPG_Phoenix_Inverter, "12V/1600VA/230V" },
  { kPID_Phoenix_Inverter_24v_1600va_230v, kPG_Phoenix_Inverter, "24V/1600VA/230V" },
  { kPID_Phoenix_Inverter_48v_1600va_230v, kPG_Phoenix_Inverter, "48V/1600VA/230V" },
  { kPID_Phoenix_Inverter_12v_2000va_230v, kPG_Phoenix_Inverter, "12V/2000VA/230V" },
  { kPID_Phoenix_Inverter_24v_2000va_230v, kPG_Phoenix_Inverter, "24V/2000VA/230V" },
  { kPID_Phoenix_Inverter_48v_2000va_230v, kPG_Phoenix_Inverter, "48V/2000VA/230V" },
  { kPID_Phoenix_Inverter_12v_3000va_230v, kPG_Phoenix_Inverter, "12V/3000VA/230V" },
  { kPID_Phoenix_Inverter_24v_3000va_230v, kPG_Phoenix_Inverter, "24V/3000VA/230V" },
  { kPID_Phoenix_Inverter_48v_3000va_230v, kPG_Phoenix_Inverter, "48V/3000VA/230V" },
  { kPID_Phoenix_Smart_IP43_Charger_12_50_1_1, kPG_Phoenix_Charger, "12/50 (1+1)" },
  { kPID_Phoenix_Smart_IP43_Charger_12_50_3, kPG_Phoenix_Charger, "12/50 (3)" },
  { kPID_Phoenix_Smart_IP43_Charger_24_25_1_1, kPG_Phoenix_Charger, "24/25 (1+1)" },
  { kPID_Phoenix_Smart_IP43_Charger_24_25_3, kPG_Phoenix_Charger, "24/25 (3)" },
  { kPID_Phoenix_Smart_IP43_Charger_12_30_1_1, kPG_Phoenix_Charger, "12/30 (1+1)" },
  { kPID_Phoenix_Smart_IP43_Charger_12_30_3, kPG_Phoenix_Charger, "12/30 (3)" },
  { kPID_Phoenix_Smart_IP43_Charger_24_16_1_1, kPG_Phoenix_Charger, "24/16 (1+1)" },
  { kPID_Phoenix_Smart_IP43_Charger_24_16_3, kPG_Phoenix_Charger, "24/16 (3)" },
  { kPID_BMV_712_Smart, kPG_BMV_71x, "BMV-712 Smart" },
  { kPID_BMV_710H_Smart, kPG_BMV_71x, "BMV-710H Smart" },
  { kPID_BMV_712_Smart_rev2, kPG_BMV_71x, "BMV-712 Smart R2" },
  { kPID_SmartShunt_500a_50mv, kPG_BMV_71x, "SmartShnt 500/50" },
  { kPID_SmartShunt_1000a_50mv, kPG_BMV_71x, "SmrtShnt 1000/50" },
  { kPID_SmartShunt_2000a_50mv, kPG_BMV_71x, "SmrtShnt 2000/50" }
};

/* CS - State of operation */
#define kCS_Off 0
#define kCS_Low_Power_Or_Load_Search 1 // Load Search for inverters
#define kCS_Fault 2
#define kCS_Bulk 3
#define kCS_Absorption 4
#define kCS_Float 5
#define kCS_Storage 6
#define kCS_Equalize_Manual 7
#define kCS_Inverting 9
#define kCS_Power_Supply 11
#define kCS_Starting_Up 245
#define kCS_Repeated_Absorption 246
#define kCS_Equalize_Auto_Or_Recondition 247
#define kCS_Battery_Safe 248
#define kCS_External_Control 252

const uint8_t stateOfOperationIndex[] = { 
  kCS_Off,
  kCS_Low_Power_Or_Load_Search,
  kCS_Fault,
  kCS_Bulk,
  kCS_Absorption,
  kCS_Float,
  kCS_Storage,
  kCS_Equalize_Manual,
  kCS_Inverting,
  kCS_Power_Supply,
  kCS_Starting_Up,
  kCS_Repeated_Absorption,
  kCS_Equalize_Auto_Or_Recondition,
  kCS_Battery_Safe,
  kCS_External_Control
};

const UIStringUInt8Id stateOfOperationLabels[] PROGMEM = {
  { kCS_Off, "Off" },
  { kCS_Low_Power_Or_Load_Search, "Low Power" },
  { kCS_Fault, "Fault" },
  { kCS_Bulk, "Bulk" },
  { kCS_Absorption, "Absorption" },
  { kCS_Float, "Float" },
  { kCS_Storage, "Storage" },
  { kCS_Equalize_Manual, "Equalize Manual"},
  { kCS_Inverting, "Inverting" },
  { kCS_Power_Supply, "Power Supply"},
  { kCS_Starting_Up, "Starting Up" },
  { kCS_Repeated_Absorption, "Repeated Absrptn" },
  { kCS_Equalize_Auto_Or_Recondition, "Equalize Auto" },
  { kCS_Battery_Safe, "Battery Safe" },
  { kCS_External_Control, "External Control" }
};

/* ERR - Error codes */
/*  (relevant when the device is in the fault state).
 *  Note1: Error 19 can be ignored, this condition regularly occurs during start-up or shutdown of the MPPT charger. 
 *  Since version 1.15 this error will no longer be reported. 
 *  
 *  Note2: Error 21 can be ignored for 5 minutes, this condition regularly occurs during start-up or shutdown 
 *  of the MPPT charger. Since version 1.16 this warning will no longer be reported when it is not persistent.
 */
#define kERR_No_Error 0
#define kERR_Battery_Voltage_Too_High 2
#define kERR_Charger_Temperature_Too_High 17
#define kERR_Charger_Over_Current 18
#define kERR_Charger_Current_Reversed 19
#define kERR_Bulk_Time_Limit_Exceeded 20
#define kERR_Current_Sensor_Issue 21 // Sensor bias/sensor broken
#define kERR_Terminals_Overheated 26
#define kERR_Converter_Issue 28 // Dual converter models only
#define kERR_Solar_Panel_Input_Voltage_Too_High 33
#define kERR_Solar_Panel_Input_Current_Too_High 34
#define kERR_Input_Shutdown_Excessive_Battery_Voltage 38
#define kERR_Input_Shutdown_Current_Flow_During_Off_Mode 39
#define kERR_Lost_Communication_With_One_Of_Devices 65
#define kERR_Synchronised_Charging_Device_Configuration_Issue 66
#define kERR_BMS_Connection_Lost 67
#define kERR_Network_Misconfigured 68
#define kERR_Factory_Calibration_Data_Lost 116
#define kERR_Invalid_Firmware 117
#define kERR_User_Settings_Invalid 119

const uint8_t errorCodesIndex[] = { 
  kERR_No_Error,
  kERR_Battery_Voltage_Too_High,
  kERR_Charger_Temperature_Too_High,
  kERR_Charger_Over_Current,
  kERR_Charger_Current_Reversed,
  kERR_Bulk_Time_Limit_Exceeded,
  kERR_Current_Sensor_Issue,
  kERR_Terminals_Overheated,
  kERR_Converter_Issue,
  kERR_Solar_Panel_Input_Voltage_Too_High,
  kERR_Solar_Panel_Input_Current_Too_High,
  kERR_Input_Shutdown_Excessive_Battery_Voltage,
  kERR_Input_Shutdown_Current_Flow_During_Off_Mode,
  kERR_Lost_Communication_With_One_Of_Devices,
  kERR_Synchronised_Charging_Device_Configuration_Issue,
  kERR_BMS_Connection_Lost,
  kERR_Network_Misconfigured,
  kERR_Factory_Calibration_Data_Lost,
  kERR_Invalid_Firmware,
  kERR_User_Settings_Invalid
};

const UIStringUInt8Id errorCodesLabels[] PROGMEM = {
  { kERR_No_Error, "No Error" },
  { kERR_Battery_Voltage_Too_High, "Bat V To High" },
  { kERR_Charger_Temperature_Too_High, "Chrgr T To High" },
  { kERR_Charger_Over_Current, "Chrgr Over Curr" },
  { kERR_Charger_Current_Reversed, "Chrgr I Reversed" },
  { kERR_Bulk_Time_Limit_Exceeded, "Bulk Time Limit" },
  { kERR_Current_Sensor_Issue, "I Sensor Issue" },
  { kERR_Terminals_Overheated, "Terminals Overht" },
  { kERR_Converter_Issue, "Converter Issue" },
  { kERR_Solar_Panel_Input_Voltage_Too_High, "PV Inp V To High" },
  { kERR_Solar_Panel_Input_Current_Too_High, "PV Inp I To High" },
  { kERR_Input_Shutdown_Excessive_Battery_Voltage, "Excessive Bat V" },
  { kERR_Input_Shutdown_Current_Flow_During_Off_Mode, "I Flow Off Mode" },
  { kERR_Lost_Communication_With_One_Of_Devices, "Comm Lost" },
  { kERR_Synchronised_Charging_Device_Configuration_Issue, "Sync Chrg Issue" },
  { kERR_BMS_Connection_Lost, "BMS Conn Lost" },
  { kERR_Network_Misconfigured, "Network Misconf" },
  { kERR_Factory_Calibration_Data_Lost, "Callibrtion Lost" },
  { kERR_Invalid_Firmware, "Invalid Firmware" },
  { kERR_User_Settings_Invalid, "User Sett Invald" }
};

/* AR - Alarm Reason (Bitmap) for BMVs and Inverters*/
#define kAR_Low_Voltage 1
#define kAR_High_Voltage 2
#define kAR_Low_SOC 4
#define kAR_Low_Starter_Voltage 8
#define kAR_High_Starter_Voltage 16
#define kAR_Low_Temperature 32
#define kAR_High_Temperature 64
#define kAR_Mid_Voltage 128
#define kAR_Overload 256
#define kAR_DC_Ripple 512
#define kAR_Low_AC_Out_Voltage 1024
#define kAR_High_AC_Out_Voltage 2048
#define kAR_Short_Circuit 4096
#define kAR_BMS_Lockout 8192

const uint16_t alarmReasonsIndex[] = {
  kAR_Low_Voltage,
  kAR_High_Voltage,
  kAR_Low_SOC,
  kAR_Low_Starter_Voltage,
  kAR_High_Starter_Voltage,
  kAR_Low_Temperature,
  kAR_High_Temperature,
  kAR_Mid_Voltage,
  kAR_Overload,
  kAR_DC_Ripple,
  kAR_Low_AC_Out_Voltage,
  kAR_High_AC_Out_Voltage,
  kAR_Short_Circuit,
  kAR_BMS_Lockout
};

const UIStringUInt16Id alarmReasonsLabels[] PROGMEM = {
  { kAR_Low_Voltage, "Low Voltage" },
  { kAR_High_Voltage, "High Voltage" },
  { kAR_Low_SOC, "Low SOC" },
  { kAR_Low_Starter_Voltage, "Low Starter V" },
  { kAR_High_Starter_Voltage, "High Starter V" },
  { kAR_Low_Temperature, "Low Temperature" },
  { kAR_High_Temperature, "High Temperature" },
  { kAR_Mid_Voltage, "Mid Voltage" },
  { kAR_Overload, "Overload" },
  { kAR_DC_Ripple, "DC Ripple" },
  { kAR_Low_AC_Out_Voltage, "Low AC Out V" },
  { kAR_High_AC_Out_Voltage, "High AC Out V" },
  { kAR_Short_Circuit, "Short Circuit" },
  { kAR_BMS_Lockout, "BMS Lockout" }
};

/* OR - Off Reason (Bitmap) */
#define kOR_No_Input_Power 0x00000001
#define kOR_Switched_Off_Power_Switch 0x00000002
#define kOR_Switched_Off_Device_Mode_Register 0x00000004
#define kOR_Remote_Input 0x00000008
#define kOR_Protection_Active 0x00000010
#define kOR_Paygo 0x00000020
#define kOR_BMS 0x00000040
#define kOR_Engine_Shutdown_Detection 0x00000080
#define kOR_Analysing_Input_Voltage 0x00000100

const uint32_t offReasonsIndex[] = {
  kOR_No_Input_Power,
  kOR_Switched_Off_Power_Switch,
  kOR_Switched_Off_Device_Mode_Register,
  kOR_Remote_Input,
  kOR_Protection_Active,
  kOR_Paygo,
  kOR_BMS,
  kOR_Engine_Shutdown_Detection,
  kOR_Analysing_Input_Voltage,
};

const UIStringUInt32Id offReasonsLabels[] PROGMEM = {
  { kOR_No_Input_Power, "No Input Power" },
  { kOR_Switched_Off_Power_Switch, "Switched Off SW" },
  { kOR_Switched_Off_Device_Mode_Register, "Switched Off Reg" },
  { kOR_Remote_Input, "Remote Input" },
  { kOR_Protection_Active, "Protectn Active" },
  { kOR_Paygo, "Paygo" },
  { kOR_BMS, "BMS" },
  { kOR_Engine_Shutdown_Detection, "Engine Shutdown" },
  { kOR_Analysing_Input_Voltage, "Analysing Inp V" }
};

/* CAP_BLE - Off Reason (Bitmap) */
#define kCAP_BLE_Supports_Switching_Off 0x00000001
#define kCAP_BLE_Switching_Off_Is_Permanent 0x00000002

const uint32_t bleOffReasonsIndex[] {
  kCAP_BLE_Supports_Switching_Off,
  kCAP_BLE_Switching_Off_Is_Permanent
};

const UIStringUInt32Id bleOffReasonsLabels[] PROGMEM = {
  { kCAP_BLE_Supports_Switching_Off, "BLE Supp Sw Off" },
  { kCAP_BLE_Switching_Off_Is_Permanent, "Sw Off is Permnt" }
};

/* MPPT - Tracker operation state */
#define kMPPT_Off 0
#define kMPPT_Voltage_Or_Current_Limited 1
#define kMPPT_Tracker_Active 2

const uint8_t mpptStatesIndex[] = {
  kMPPT_Off,
  kMPPT_Voltage_Or_Current_Limited,
  kMPPT_Tracker_Active
};

const UIStringUInt8Id mpptStatesLabels[] PROGMEM = {
  { kMPPT_Off, "Off" },
  { kMPPT_Voltage_Or_Current_Limited, "V or I Limited" },
  { kMPPT_Tracker_Active, "Active" }
};

/* MODE for Inverters and Chargers */
#define kMODE_Charger 1
#define kMODE_Inverter 2
#define kMODE_Off 4
#define kMODE_Eco 5
#define kMODE_Hibernate 253

const uint8_t deviceModesIndex[] = {
  kMODE_Charger,
  kMODE_Inverter,
  kMODE_Off,
  kMODE_Eco,
  kMODE_Hibernate
};

const UIStringUInt8Id deviceModesLabels[] PROGMEM = {
  { kMODE_Charger, "Charger" },
  { kMODE_Inverter, "Inverter" },
  { kMODE_Off, "Off" },
  { kMODE_Eco, "Eco" },
  { kMODE_Hibernate, "Hibernate" },
};

/* MON - DC monitor modes */
#define kMON_Solar_Charger -9
#define kMON_Wind_Turbine -8
#define kMON_Shaft_Generator -7
#define kMON_Alternator -6
#define kMON_Fuel_Cell -5
#define kMON_Water_Generator -4
#define kMON_DC_DC_Charger -3
#define kMON_AC_Charger -2
#define kMON_Generic_Source -1
#define kMON_Battery_Monitor 0
#define kMON_Generic_Load 1
#define kMON_Electric_Drive 2
#define kMON_Fridge 3
#define kMON_Water_Pump 4
#define kMON_Bilge_Pump 5
#define kMON_DC_System 6
#define kMON_Inverter 7
#define kMON_Water_Heater 8

const int8_t dcMonitorIndex[] = {
  kMON_Solar_Charger,
  kMON_Wind_Turbine,
  kMON_Shaft_Generator,
  kMON_Alternator,
  kMON_Fuel_Cell,
  kMON_Water_Generator,
  kMON_DC_DC_Charger,
  kMON_AC_Charger,
  kMON_Generic_Source,
  kMON_Battery_Monitor,
  kMON_Generic_Load,
  kMON_Electric_Drive,
  kMON_Fridge,
  kMON_Water_Pump,
  kMON_Bilge_Pump,
  kMON_DC_System,
  kMON_Inverter,
  kMON_Water_Heater
};

const UIStringInt8Id dcMonitorLabels[] PROGMEM = {
  { kMON_Solar_Charger, "Solar Charger" },
  { kMON_Wind_Turbine, "Wind Turbine" },
  { kMON_Shaft_Generator, "Shaft Generator" },
  { kMON_Alternator, "Alternator" },
  { kMON_Fuel_Cell, "Fuel Cell" },
  { kMON_Water_Generator, "Water Generator" },
  { kMON_DC_DC_Charger, "DC-DC Charger" },
  { kMON_AC_Charger, "AC Charger" },
  { kMON_Generic_Source, "Generic Source" },
  { kMON_Battery_Monitor, "Battery Monitor" },
  { kMON_Generic_Load, "Generic Load" },
  { kMON_Electric_Drive, "Electric Drive" },
  { kMON_Fridge, "Fridge" },
  { kMON_Water_Pump, "Water Pump" },
  { kMON_Bilge_Pump, "Bilge Pump" },
  { kMON_DC_System, "DC System" },
  { kMON_Inverter, "Inverter" },
  { kMON_Water_Heater, "Water Heater" }
};

enum ValueParser {
  text,
  textOnOff,
  timeHours,
  hex16bit,
  hex32bit,
  dec8bit,
  decU8bit,
  dec16Bit,
  decU16bit,
  decU32bit,
  floatNum
};

/* Text data fields */
const char dataFieldsIndex[][9] = {
  "V", // 0
  "V2", // 1
  "V3", // 2
  "VS", // 3
  "VM", // 4
  "DM", // 5
  "VPV",  // 6
  "PPV", // 7
  "I", // 8
  "I2", // 9
  "I3", // 10
  "IL", // 11
  "LOAD", // 12
  "T", // 13
  "P", // 14
  "CE", // 15
  "SOC", // 16
  "TTG", // 17
  "Alarm", // 18
  "Relay", // 19
  "AR", // 20
  "OR", // 21
  "H1", // 22
  "H2", // 23
  "H3", // 24
  "H4", // 25
  "H5", // 26
  "H6", // 27
  "H7", // 28
  "H8", // 29
  "H9", // 30
  "H10", // 31
  "H11", // 32
  "H12", // 33
  "H13", // 34
  "H14", // 35
  "H15", // 36
  "H16", // 37
  "H17", // 38
  "H18", // 39
  "H19", // 40
  "H20", // 41
  "H21", // 42
  "H22", // 43
  "H23", // 44
  "ERR", // 45
  "CS", // 46
  "BMV", // 47
  "FW", // 48
  "FWE", // 49
  "PID", // 50
  "SER#", // 51
  "HSDS", // 52
  "MODE", // 53
  "AC_OUT_V", // 54
  "AC_OUT_I", // 55
  "AC_OUT_S", // 56
  "WARN", // 57
  "MPPT", // 58
  "MON" // 59
};

/* 

Victron Implementation guidelines 

When implementing a VE.Text parser it is recommended to reserve two buffers. 
For the field label a buffer of 9 bytes is needed and for the field value a buffer length of 33 bytes is required. 
The value should be parsed as soon as a single field is received and should then be stored in a temporary record. 
The maximum number of fields in a block is 22; keep at least 22 temporary records. Once the complete block is validated 
by evaluating the checksum, the contents of the temporary records can be copied to its corresponding final records. 
If the checksum turned out to be invalid, the temporary records need to be cleared.

*/

struct DataField {
  char label[9];
  char uiUnits[4];
  char uiLabel[17]; // My LCD is 16 chars by 2 rows
  ValueParser valueParser;
  float valueMultiplier;
  uint8_t valuePrecision; // num of digits after the decimal point 
  uint8_t productGroups; // bitmap,
  char originalValue[33];
};

const DataField dataFields[] PROGMEM = {
  { "V", "V", "Battery Voltage", decU16bit, 0.001, 3, kPG_All },
  { "V2", "V", "Bat 2 Voltage", decU16bit, 0.001, 3, kPG_Phoenix_Charger },
  { "V3", "V", "Bat 3 Voltage", decU16bit, 0.001, 3, kPG_Phoenix_Charger },
  { "VS", "V", "Aux Voltage", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "VM", "V", "Mid-p Voltage", decU16bit, 0.001, 3, kPG_BMV_70x | kPG_BMV_71x },
  { "DM", "%", "Mid-p Deviation", decU8bit, 1, 0, kPG_BMV_70x | kPG_BMV_71x },
  { "VPV", "V", "PV Voltage", decU16bit, 0.001, 3, kPG_MPPT },
  { "PPV", "W", "PV Power", decU16bit, 1, 0, kPG_MPPT },
  { "I", "A", "Battery Current", decU16bit, 0.001, 3, kPG_All },
  { "I2", "A", "Bat 2 Current", decU16bit, 0.001, 3, kPG_Phoenix_Charger },
  { "I3", "A", "Bat 3 Current", decU16bit, 0.001, 3, kPG_Phoenix_Charger },
  { "IL", "A", "Load Current", decU16bit, 0.001, 3, kPG_MPPT },
  { "LOAD" , "", "Load Output", text, 0, 0, kPG_MPPT },
  { "T" , "C", "Battery Temp", floatNum, 1, 2, kPG_BMV_70x | kPG_BMV_71x },
  { "P" , "W", "Instant Power", decU16bit, 1, 0, kPG_BMV_70x | kPG_BMV_71x },
  { "CE" , "Ah", "Instant Power", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "SOC", "%", "State Of Charge", decU8bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "TTG", "Min", "Time To Go", decU32bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "Alarm", "", "Alarm", textOnOff, 0, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "Relay", "", "Relay State", textOnOff, 0, 0, kPG_All },
  { "AR", "", "Alarm Reason", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x | kPG_Phoenix_Inverter },
  { "OR", "", "Off Reason", hex32bit, 0, 0, kPG_MPPT | kPG_Phoenix_Inverter },
  { "H1", "Ah", "Deepest Dischrg", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H2", "Ah", "Last Discharge", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H3", "Ah", "Avg Discharge", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H4", "", "Charge Cycles", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H5", "", "Full Discharges", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H6", "Ah", "Ah Cumulative", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H7", "V", "Min Bat V", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H8", "V", "Max Bat V", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H9", "H", "", timeHours, 1, 1, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H10", "", "Auto Syncs", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H11", "", "Low V Alarms", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H12", "", "High V Alarms", decU16bit, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H13", "", "Low Aux V Alarms", decU16bit, 1, 0, kPG_BMV_60x },
  { "H14", "", "High Aux V Alrms", decU16bit, 1, 0, kPG_BMV_60x },
  { "H15", "V", "Min Aux Bat V", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H16", "V", "Max Aux Bat V", decU16bit, 0.001, 3, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "H17", "kWh", "Energy Produced", decU32bit, 0.01, 2, kPG_BMV_70x | kPG_BMV_71x },
  { "H18", "kWh", "Energy Consumed", decU32bit, 0.01, 2, kPG_BMV_70x | kPG_BMV_71x },
  { "H19", "kWh", "Yeld Total", decU32bit, 0.01, 2, kPG_MPPT },
  { "H20", "kWh", "Yeld Today", decU32bit, 0.01, 2, kPG_MPPT },
  { "H21", "W", "Max P Today", decU16bit, 1, 0, kPG_MPPT },
  { "H22", "kWh", "Yeld Yesterday", decU32bit, 0.01, 2, kPG_MPPT },
  { "H23", "W", "Max P Yesterday", decU16bit, 1, 0, kPG_MPPT },
  { "ERR", "", "Error Code", decU8bit, 1, 0, kPG_MPPT | kPG_Phoenix_Charger },
  { "CS", "", "State Of Operatn", decU8bit, 1, 0, kPG_MPPT | kPG_Phoenix_Inverter | kPG_Phoenix_Charger },
  { "BMV", "", "Model Descriptn", text, 1, 0, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x },
  { "FW", "", "Firmware", decU16bit, 0.01, 2, kPG_BMV_60x | kPG_BMV_70x | kPG_BMV_71x | kPG_MPPT | kPG_Phoenix_Inverter },
  { "FWE", "", "Firmware", hex32bit, 1, 0, kPG_Phoenix_Charger },
  { "PID", "", "Product ID", hex16bit, 1, 0, kPG_BMV_70x | kPG_BMV_71x | kPG_MPPT | kPG_Phoenix_Inverter | kPG_Phoenix_Charger },
  { "SER#", "", "Serial Number", text, 1, 0, kPG_MPPT | kPG_Phoenix_Inverter | kPG_Phoenix_Charger },
  { "HSDS", "", "Day Seq Number", decU16bit, 1, 0, kPG_MPPT },
  { "MODE", "", "Device Mode", decU8bit, 1, 0, kPG_Phoenix_Inverter | kPG_Phoenix_Charger },
  { "AC_OUT_V", "V", "AC Out Voltage", decU32bit, 0.01, 2, kPG_Phoenix_Inverter },
  { "AC_OUT_I", "A", "AC Out Current", decU32bit, 0.1, 1, kPG_Phoenix_Inverter },
  { "AC_OUT_S", "VA", "AC Out apparnt P", decU16bit, 1, 0, kPG_Phoenix_Inverter },
  { "WARN", "", "Warning Reason", decU16bit, 1, kPG_Phoenix_Inverter }, // same as AR, bitmap
  { "MPPT", "", "MPPT State", decU8bit, 1, 0, kPG_MPPT },
  { "MON", "", "DC Monitor Mode", dec8bit, 1, 0, kPG_BMV_71x },
};

/* Function definitions */

int getProductIndex(uint16_t byPID);
VictronProduct *getProduct(int atIndex);

int getProductGroupIndex(int byGroupId);
UIStringUInt8Id *getProductGroup(int atIndex);

int getDataFieldIndex(char *fieldLabel);
DataField *getDataField(int atIndex);

int getStateOfOperationIndex(uint8_t byID);
UIStringUInt8Id *getStateOfOperation(int atIndex);

int getMPPTStateIndex(uint8_t byID);
UIStringUInt8Id *getMPPTState(int atIndex);

int getErrorIndex(uint8_t byID);
UIStringUInt8Id *getError(int atIndex);

UIStringUInt32Id *getOffReason(int atIndex);

#endif // include guard
