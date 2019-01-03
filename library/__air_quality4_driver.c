/*
    __air_quality4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__air_quality4_driver.h"
#include "__air_quality4_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __AIR_QUALITY4_DRV_I2C__
static uint8_t _slaveAddress;
#endif
/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __AIR_QUALITY4_DRV_SPI__

void air_quality4_spiDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AIR_QUALITY4_DRV_I2C__

void air_quality4_i2cDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AIR_QUALITY4_DRV_UART__

void air_quality4_uartDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void air_quality4_getID(uint8_t *buff)
{
    uint8_t wReg[ 2 ] = {0};

    wReg[ 0 ] = 0x36;
    wReg[ 1 ] = 0x82;
        
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_10ms();
    hal_i2cRead(_slaveAddress, buff, 6, END_MODE_STOP);
}

void air_quality4_init()
{
    uint8_t wReg[ 2 ] = {0};
        
    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x03;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_STOP);
    Delay_100ms();
}

void air_quality4_measureQuality(uint8_t *readAir)
{
    uint8_t wReg[ 2 ] = {0};

    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x08;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_10ms();
    Delay_10ms();
    Delay_10ms();
    Delay_10ms();
    hal_i2cRead(_slaveAddress, readAir, 6, END_MODE_STOP);
    Delay_1sec();
}

void air_quality4_getCO2AndTVOC(uint16_t *value)
{
    uint8_t readAir[6] = {0};
        
    air_quality4_measureQuality(&readAir[0]);
        
    value[0] = readAir[0];
    value[0] <<= 8;
    value[0] |= readAir[1];
        
    value[1] = readAir[3];
    value[1] <<= 8;
    value[1] |= readAir[4];
}

void air_quality4_measureSignal(uint8_t *readAir)
{
    uint8_t wReg[ 2 ] = {0};
        
    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x50;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_100ms();
    Delay_100ms();
    Delay_10ms();
    hal_i2cRead(_slaveAddress, readAir, 6, END_MODE_STOP);
    Delay_10ms();
}

void air_quality4_getH2AndEthOH(uint16_t *value)
{
    uint8_t readAir[6] = {0};

    air_quality4_measureSignal(&readAir[0]);

    value[0] = readAir[0];
    value[0] <<= 8;
    value[0] |= readAir[1];

    value[1] = readAir[3];
    value[1] <<= 8;
    value[1] |= readAir[4];
}

void air_quality4_getBaseline(uint16_t *readAir)
{
    uint8_t wReg[ 2 ] = {0};

    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x15;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_10ms();
    hal_i2cRead(_slaveAddress, readAir, 6, END_MODE_STOP);
    Delay_10ms();
}

void air_quality4_setBaseline()
{
    uint8_t rReg[ 8 ] = {0};
   
    air_quality4_getBaseline(rReg + 2);
    rReg[0] = 0x20;
    rReg[1] = 0x1E;
   
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, rReg, 8, END_MODE_STOP);
    Delay_10ms();
}

void air_quality4_softReset()
{
    uint8_t rReg[ 2 ] = {0};
    
    rReg[0] = 0x00;
    rReg[1] = 0x06;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, rReg, 2, END_MODE_STOP);
    Delay_10ms();
    
    air_quality4_init();
}

void air_quality4_getVersion(uint8_t *version)
{
    uint8_t wReg[ 2 ] = {0};

    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x2F;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_1ms();
    hal_i2cRead(_slaveAddress, version, 3, END_MODE_STOP);
    Delay_10ms();
}

void air_quality4_measureTest(uint8_t *value)
{
    uint8_t wReg[ 2 ] = {0};

    wReg[ 0 ] = 0x20;
    wReg[ 1 ] = 0x32;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_RESTART);
    Delay_100ms();
    Delay_100ms();
    hal_i2cRead(_slaveAddress, value, 3, END_MODE_STOP);
    Delay_10ms();
}

/* -------------------------------------------------------------------------- */
/*
  __air_quality4_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */