/**
 * \file LCD_NHDC12864.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 27, 2018
 *
 **************************************************************************
 *
 * Module Name:  LCD_NHDC12864.h
 *
 * \brief Implements the drivers of the LCD NHDC1264.
 *
 * \section References
 * NHDC1264 Datasheet
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   27-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef LCD_NHDC12864_h
#define LCD_NHDC12864_h

#ifdef __cplusplus
extern "C"
{
#endif

//Defines
/**LCD Pin mapping*/
#define LCD_A0     GPIO_PIN_5 //PB5
#define LCD_WR     GPIO_PIN_5 //PE5
#define LCD_RD     GPIO_PIN_4 //PB4
#define LCD_D0     GPIO_PIN_5 //PA5
#define LCD_D1     GPIO_PIN_6 //PA6
#define LCD_D2     GPIO_PIN_7 //PA7
#define LCD_D3     GPIO_PIN_2 //PA2
#define LCD_D4     GPIO_PIN_3 //PA3
#define LCD_D5     GPIO_PIN_4 //PA4
#define LCD_D6     GPIO_PIN_2 //PB2
#define LCD_D7     GPIO_PIN_0 //PE0

/**LCD driver configurations*/
#define COMP_LCD_CONFIG_VECTOR 11	/**Config vector length*/
                                      
#define COMM 0						/**Command mode*/
#define DATA 1						/**Data mode*/
#define STATUS 2					/**Status mode*/
                                      
#define MAX_COL 127					/**Maximum number of LCD columns*/
#define MAX_LIN 63                  /**Maximum number of LCD lines*/
#define MAX_PAGE 7                  /**Maximum number of LCD pages*/

/**LCD NHD-C12864B2Z commands*/
#define LCD_ON              0xAF
#define LCD_OFF             0xAE
#define LCD_RAM_LINE        0x40  //mask 6bit low
#define LCD_RAM_PAGE        0xB0  //mask 4bit low
#define LCD_RAM_COL_H       0x10  //mask 4bit low
#define LCD_RAM_COL_L       0x00  //mask 4bit low
#define LCD_RD_STATUS       0x00  //mask 4bit high
#define LCD_RAM_SEG_NORMAL  0xA0
#define LCD_RAM_SEG_REVERSE 0xA1
#define LCD_NORMAL          0xA6
#define LCD_REVERSE         0xA7
#define LCD_ALL_POINTS_ON   0xA5
#define LCD_ALL_POINTS_OFF  0xA4
#define LCD_BIAS_1_9        0xA2
#define LCD_BIAS_1_7        0xA3
#define LCD_RD_MF_WR        0xE0
#define LCD_END             0xEE
#define LCD_RESET           0xE2
#define LCD_COM_OUT_NORMAL  0xC0  
#define LCD_COM_OUT_REVERSE 0xC8  
#define LCD_PWR_CRT         0x28  //mask 3bit low
#define LCD_RES_RATIO       0x20  //mask 3bit low
#define LCD_VOL_MODE        0x81
#define LCD_VOL_REG         0x00  //mask 6bit low
#define LCD_SLEEP           0xAC
#define LCD_NO_SLEEP        0xAD
#define LCD_BOOST_2X_3X_4X  0xF8
#define LCD_BOOST_5X        0x01
#define LCD_BOOST_6X        0x03
#define LCD_NOP             0xE3

extern const char times8[95*7];

void LCDInitializeNHDC12864(void);
void LCDWrite(char mode, char data);
//unsigned char LCDRead(char mode);
void LCDSetStartLine(char addr);
void LCDSetColumn(char addr);
void LCDSetPage(char addr);
void LCDClear(void);
void LCDReverseBlink(char nBlink);
void LCDWriteChar7x8(const char *alphabet, char letter);
void LCDWriteString(const char *alphabet, char *str);

#ifdef __cplusplus
}
#endif

#endif
