PREFIX=/usr/bin
CC=$(PREFIX)/arm-linux-gnueabihf-gcc-6
LD=$(PREFIX)/arm-linux-gnueabihf-ld

CFLAGS= -g -Wall
OBJS= Smart_Sensor.o I2C_RTC.o LCD.o Remote_Send.o Thermal_Read.o UART.o
 
S3C4510_Sensor : $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean
clean :
	rm -f *.o