// --------------------------------------------------------------------
//
//   Title     :  S3C4510_addr.h
//             :
//   Library   :
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  S3C4510 Address Register
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

#ifndef S3C4510_ADDR_H
#define S3C4510_ADDR_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define EX_BANK0_BASE	(*(volatile unsigned *) 0x3600000 )                            // For ADC, Thermal Read
#define EX_BANK1_BASE	(*(volatile unsigned *) 0x3604000 )                          // For LCD display
#define EX_BANK2_BASE	(*(volatile unsigned *) 0x3608000 )
#define EX_BANK3_BASE	(*(volatile unsigned *) 0x360c000 )
    
//External I/O Bus Control 
#define rEXTACON0 (*(volatile unsigned *)0x3FF3008)  //External I/O Bus timing
#define rEXTACON0 (*(volatile unsigned *)0x3FF3008)  //External I/O Bus timing
#define rEXTDBWTH (*(volatile unsigned *)0x3FF3010)  //External I/O Bus width
    
// GPIO Control    
#define rIOPMOD   (*(volatile unsigned *)0x3FF5000) //Mode selection
#define rIOPCON   (*(volatile unsigned *)0x3FF5004) //Control
#define rIOPDATA  (*(volatile unsigned *)0x3FF5008) //I/O Data 
    
// Timer Control
#define rTMOD     (*(volatile unsigned *)0x3FF6000) //Timer mode   
#define rTDATA0   (*(volatile unsigned *)0x3FF6004) //Timer 0 data
#define rTDATA1   (*(volatile unsigned *)0x3FF6008) //Timer 1 data    
#define rTCNT0    (*(volatile unsigned *)0x3FF600c) //Timer 0 data   
#define rTCNT1    (*(volatile unsigned *)0x3FF6010) //Timer 1 data
    
// I2C Bus Control
#define rIICCON   (*(volatile unsigned *)0x3FFF000) //Bus Control & status 
#define rIICBUF   (*(volatile unsigned *)0x3FFF004) //Bus Address  
#define rIICPS    (*(volatile unsigned *)0x3FFF008) //Data length    

// External I/O Bus Bits    
#define BUS_WIDTH_Byte    (0x1<<22)                 // Bus width: Byte for EX I/O bank1
#define BUS_WIDTH_HWORD   (0x1<<23)                 // Bus width: Half-World for EX I/O bank1
       
#ifdef __cplusplus
}
#endif

#endif /* S3C4510_ADDR_H */

