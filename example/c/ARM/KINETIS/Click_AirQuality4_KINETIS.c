/*
Example for AirQuality4 Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes click driver and gets ID data.
- Application Task - Performs measurements of air concentracion for H2, EthOH, CO2 and TVOC data.
  Results of measurement shows on USBUART.

*/

#include "Click_AirQuality4_types.h"
#include "Click_AirQuality4_config.h"

uint8_t buffer_data[6];
uint16_t data_buffer[2];
char text[256] = {0};

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_AIR_QUALITY4_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    air_quality4_i2cDriverInit( (T_AIR_QUALITY4_P)&_MIKROBUS1_GPIO, (T_AIR_QUALITY4_P)&_MIKROBUS1_I2C, 0x58 );
    mikrobus_logWrite("Air Quality 4 initialize....", _LOG_LINE);
    Delay_ms(100);
    
    air_quality4_init();
    air_quality4_getID(&buffer_data[0]);
}

void applicationTask()
{
    air_quality4_getH2AndEthOH(&data_buffer[0]);

    IntToStr(data_buffer[0], text);
    mikrobus_logWrite("H2 value is: ", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_LINE);

    IntToStr(data_buffer[1], text);
    mikrobus_logWrite("EthOH value is: ", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_LINE);

    air_quality4_setBaseline();
    
    air_quality4_getCO2AndTVOC(&data_buffer[0]);
    
    IntToStr(data_buffer[0], text);
    mikrobus_logWrite("CO2 value is: ", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_LINE);

    IntToStr(data_buffer[1], text);
    mikrobus_logWrite("TVOC value is: ", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_LINE);
    
    Delay_ms(1000);
}

void main()
{
    systemInit();
    applicationInit();

    while(1)
    {
        applicationTask();
    }
}