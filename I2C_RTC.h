// --------------------------------------------------------------------
//
//   Title     :  I2C.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  I2C driver
//             :
//   Limitation:
//             :
//   Note      :
//             :
// --------------------------------------------------------------------
//   modification history :
// --------------------------------------------------------------------
//   Version| mod. date: |
//   V1.0   | 12/15/2017 | Programming start
// --------------------------------------------------------------------

#ifndef RTC_H
#define RTC_H

#ifdef __cplusplus
extern "C" {
#endif 
    
/* IICCON bits */
#define S3C4510_IICCON_ACK_EN        (1<<3)
#define S3C4510_IICCON_INT_EN        (1<<1)
#define S3C4510_IICCON_RESET         (1<<7)
#define S3C4510_IICCON_BF            (1<<0)
#define S3C4510_IICCON_START         (0b01<<4)
#define S3C4510_IICCON_STOP          (0b10<<4)
#define S3C4510_IICCON_RESTART       (0b11<<4)

#define RTC_ADDR_WRITE  0xa2                       // RTC-8564 Write Address
#define RTC_ADDR_READ   0xa3                       // RTC-8564 Read Address
 
/* IICPS bits*/
#define S3C2410_IICCON_TCLK_PCLK19   0

/* RTC-8564 Register Address*/
#define RTC_CONTROL1	0x00
#define RTC_CONTROL2	0x01
#define RTC_SECONDS		0x02
#define RTC_MINUTES		0x03
#define RTC_HOURS		0x04
#define RTC_DAYS		0x05
#define RTC_WEEKDAYS	0x06
#define RTC_MONTHS		0x07
#define RTC_YEARS		0x08

/* I2C , RTC functions */    
void I2C_Init();
unsigned char I2C_RTC_Read( unsigned char addr );
void RTC_Get_Time ( unsigned char *sec, unsigned char *min, unsigned char *hour, 
                   unsigned char *day, unsigned char *month );

#ifdef __cplusplus
}
#endif

#endif /* RTC_H */

