// --------------------------------------------------------------------
//
//   Title     :  I2C.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  I2C driver to RTC-8564 accessing
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

#include "S3C4510_addr.h"
#include "I2C_RTC.h"

// Function to wait for the I2C transaction to complete
void I2C_Init(){
    rIICCON = S3C4510_IICCON_RESET;                              // Reset I2C bus
    rIICPS = S3C2410_IICCON_TCLK_PCLK19;                         // Setup I2C clock ; system clock/19
    rIICCON = S3C4510_IICCON_ACK_EN | S3C4510_IICCON_INT_EN;     // Enable automatically ACK and interrupt     
}

unsigned char I2C_RTC_Read( unsigned char addr ) {   // Function for read information from RTC via I2C
    rIICBUF = RTC_ADDR_READ;                                     // Send RTC-8564 slave address to buffer
    rIICCON |= S3C4510_IICCON_START;                             // Send the slave address
   
    rIICBUF = addr;
    rIICCON |= S3C4510_IICCON_RESTART;                           // Send the register address of slave
    rIICCON |= S3C4510_IICCON_BF;                                // Set the "Buffer Flag" bit
     usleep(1000);
    unsigned char data = rIICBUF;                                             // Read the data from IIC shift buffer
    rIICCON &= 0xf7;                                             // Reset the ACK bit to signal the end of read operation                                  
    rIICCON &= S3C4510_IICCON_STOP;
 
    return data;
}

void RTC_Get_Time (unsigned char *sec, unsigned char *min, unsigned char *hour, 
                   unsigned char *day, unsigned char *month ) {   
    I2C_Init();
    usleep(1000);
    
    // Get timing data from RTC registers
    *sec = I2C_RTC_Read(RTC_SECONDS) &0x7f;                     
    *min = I2C_RTC_Read(RTC_MINUTES) &0x7f;
    *hour = I2C_RTC_Read(RTC_HOURS) &0x3f;
    *day = I2C_RTC_Read(RTC_DAYS) &0x3f;
    *month = I2C_RTC_Read(RTC_DAYS) &0x1f;
} 
