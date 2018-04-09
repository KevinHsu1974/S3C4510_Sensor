// --------------------------------------------------------------------
//
//   Title     :  Thermal_Read.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  LM35 Thermal Sensor Read via TI ADC0804
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
#include "Thermal_Read.h"

void Thermal_Read_Init() {        // Initialize External I/O bank 1 for accessing ADC0804    
   rEXTDBWTH &= 0xff3fffff;      // EXTDBWTH[23:22]=0b00, Disable the External I/O bank 1 
   usleep(1);
   rEXTDBWTH |= (0x1<<22);       // EXTDBWTH[23:22]=0b01, Set the bus width to "Byte"
   usleep(1);
   rIOPMOD &=0xfffffffe;         // Type of GPIO "P0" => input; as the signal of ADC translation done
   usleep(1);
    
}

void Thermal_Read(double *temperature) {
   EX_BANK1_BASE = 0x0;                          // Trigger ADC0804 to start the ADC translation : cs=0,wr=0
   usleep(1000);
   while ( (rIOPDATA & 0x1) == 0 ) {             // Pooling the interrupt status(nINT) at GPIO "P0", translation is completed while nINT = 0  
      int value = EX_BANK1_BASE;                 // Read the digital value
      double volts = ( value * 3.3 ) / 256;      // Translate digital value into volts ; 8-bit resolution
      *temperature = volts / ( 10.0/1000.0 );    // Translate volts into degrees; 1 degree = 10mV 
   }
   
} // End of Thermal_Read

