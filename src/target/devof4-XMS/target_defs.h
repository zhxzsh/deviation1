#ifndef _DEVO_F4_XMS_TARGET_H_
#define _DEVO_F4_XMS_TARGET_H_

#if defined HAS_4IN1_FLASH && HAS_4IN1_FLASH
    // Use 4-in-1 flash
    #define _SPI_FLASH_PORT           2 //SPI2
    #define _SPI_FLASH_CSN_PIN       {GPIOB, GPIO12}
    #define _SPI_FLASH_SCK_PIN       {GPIOB, GPIO13}
    #define _SPI_FLASH_MISO_PIN      {GPIOB, GPIO14}
    #define _SPI_FLASH_MOSI_PIN      {GPIOB, GPIO15}

    #define SPIFLASH_SECTOR_OFFSET 0
    #define SPIFLASH_SECTORS 4096
    #define SPIFLASH_TYPE W25QxxBV
#else
    #define HAS_FLASH_DETECT 1
    #define SPIFLASH_SECTOR_OFFSET 0
#endif

#include "../common/devo/common_devo.h"

#define TXID 0xF4
#define VECTOR_TABLE_LOCATION 0x3000

#define LCD_WIDTH 24
#define LCD_HEIGHT 12

#define CHAR_WIDTH 12
#define CHAR_HEIGHT 18

#if defined BUILDTYPE_DEV && ! defined EMULATOR
//No room for debug and standard gui
 #define HAS_STANDARD_GUI   0
#else
 #define HAS_STANDARD_GUI   1
#endif

#define HAS_ADVANCED_GUI    1
#define HAS_PERMANENT_TIMER 0
#define HAS_TELEMETRY       1
#define HAS_EXTENDED_TELEMETRY 0
#define HAS_TOUCH           0
#define HAS_RTC             0
#define HAS_VIBRATINGMOTOR  1
#define HAS_DATALOG         1
#define HAS_SCANNER         0
#define HAS_LAYOUT_EDITOR   0
#define HAS_EXTRA_SWITCHES  OPTIONAL
#define HAS_EXTRA_BUTTONS   0
#define HAS_MULTIMOD_SUPPORT 1
#define HAS_MAPPED_GFX      0
#define HAS_CHAR_ICONS      1
#define HAS_VIDEO           8
#define HAS_EXTENDED_AUDIO  0
#define HAS_AUDIO_UART5     0
#define HAS_MUSIC_CONFIG    0

#define NO_LANGUAGE_SUPPORT 1

#define DEBUG_WINDOW_SIZE   0
#define MIN_BRIGHTNESS      0
#define DEFAULT_BATTERY_ALARM 6600
#define DEFAULT_BATTERY_CRITICAL 6200
#define MAX_BATTERY_ALARM 8700
#define MIN_BATTERY_ALARM 6000

#define MAX_POWER_ALARM 60

#define NUM_OUT_CHANNELS 12
#define NUM_VIRT_CHANNELS 10

#define NUM_TRIMS 6
#define NUM_TOGGLES 5
#define MAX_POINTS 13
#define NUM_MIXERS ((NUM_OUT_CHANNELS + NUM_VIRT_CHANNELS) * 4)

#define INP_HAS_CALIBRATION 4

/* Compute voltage from y = 2.1592x + 0.2493 */
#define VOLTAGE_NUMERATOR 324
#define VOLTAGE_OFFSET    382

#endif //_DEVO_F4_XMS_TARGET_H_
