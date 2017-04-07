/*
 * LCD_config.h
 *
 *  Created on: Mar 25, 2017
 *      Author: root
 */



/*
 * https://mil.ufl.edu/3744/docs/lcdmanual/commands.html
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS PIN_16
#define LCD_RW PIN_17
#define LCD_DataRegisterPORT PORTD
#define LCD_DataRegisterDIRECTION DDRD

/* Function Set */

/*
 * FS_DL :- Sets Interface Data Length
 * FS_DL = 1  8 bit Length
 * FS_DL = 0  4 bit Length
 *
 */
#define   FS_DL  1

/*
 * FS_N :- Number of Lines.
 *
 * FS_N = 0 One Line
 * FS_N = 1 Two Lines
 *
 */
#define   FS_N 1

/*
 * FS_F :- Font Size
 *
 * FS_F = 0 (5*7 dots)
 * FS_F = 1 (5*10 dots)
 *
 *
 */
#define   FS_F 0


#define FS_DB7  0
#define FS_DB6  0
#define FS_DB5  1
#define FS_DB4  FS_DL
#define FS_DB3  FS_N
#define FS_DB2  FS_F
#define FS_DB1  0
#define FS_DB0   0




/*
* DS_D :- On or OFf
* DS_D=0 Off
* DS_D=1 On
 *
 */
#define DS_D 1

/*
 * DS_C :- Cursor Display
 *
 * DS_C=0 Not Displayed
 * DS_C=1 Displayed
 *
 */
#define DS_C 1

/*
 * Character_Blink
 *
 * DS_B = 1 Blinking
 * DS_B = 0 Not Blinking
 */
#define DS_B 0

/*
 *DS :- Display ON/OFF
 */
#define DS_DB7    0
#define DS_DB6    0
#define DS_DB5    0
#define DS_DB4    0
#define DS_DB3    1
#define DS_DB2   DS_D
#define DS_DB1   DS_C
#define DS_DB0   DS_B

#endif /* LCD_CONFIG_H_ */
