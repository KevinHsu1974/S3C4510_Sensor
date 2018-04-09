// --------------------------------------------------------------------
//
//   Title     :  Thermal_Read.h
//             :
//   Library   :
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

#ifndef THERMAL_READ_H
#define THERMAL_READ_H

#ifdef __cplusplus
extern "C" {
#endif
    void Thermal_Read_Init();
    void Thermal_Read();


#ifdef __cplusplus
}
#endif

#endif /* THERMAL_READ_H */

