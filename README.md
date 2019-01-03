![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# AirQuality4 Click

- **CIC Prefix**  : AIR_QUALITY4
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : Jan 2018

---


### Software Support

We provide a library for the AirQuality4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2284/air-quality-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Initializes and defines I2C bus driver and driver functions witch performs measurements of H2, TVOC, CO2 and EthOH concentracion in air.
Check documentation for more details.

Key functions :

- ``` void air_quality4_measureQuality(uint8_t *readAir) ``` - Function writes 6 bytes CO2 data (2 bytes) and TVOC data (2 bytes) with CRC data 
  for each other to buffer determined by pointer in parametar of function.
- ``` void air_quality4_getCO2AndTVOC(uint16_t *value) ``` - Function writes 2 bytes CO2 data and 2 bytes TVOC data without CRC data to buffer 
  determined by pointer in parametar of function.
- ``` void air_quality4_measureSignal(uint8_t *readAir) ``` - Function writes 6 bytes H2 data (2 bytes) and EthOH - Ethanol data (2 bytes) with 
  CRC data for each other to buffer determined by pointer in parametar of function.
- ``` void air_quality4_getH2AndEthOH(uint16_t *value) ``` - Function writes 2 bytes H2 data and 2 bytes EthOH data without CRC data to buffer 
  determined by pointer in parametar of function.

**Examples Description**

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes click driver and gets ID data.
- Application Task - Performs measurements of air concentracion for H2, EthOH, CO2 and TVOC data.
  Results of measurement shows on USBUART.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2284/air-quality-4-click) page.

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
