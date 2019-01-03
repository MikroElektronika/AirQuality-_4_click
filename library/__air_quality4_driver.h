/*
    __air_quality4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __air_quality4_driver.h
@brief    AirQuality4 Driver
@mainpage AirQuality4 Click
@{

@image html sch.jpg

@}

@defgroup   AIR_QUALITY4
@brief      AirQuality4 Click Driver
@{

| Global Library Prefix | **AIR_QUALITY4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _AIR_QUALITY4_H_
#define _AIR_QUALITY4_H_

/** 
 * @macro T_AIR_QUALITY4_P
 * @brief Driver Abstract type 
 */
#define T_AIR_QUALITY4_P    const uint8_t*

/** @defgroup AIR_QUALITY4_COMPILE Compilation Config */              /** @{ */

//  #define   __AIR_QUALITY4_DRV_SPI__                            /**<     @macro __AIR_QUALITY4_DRV_SPI__  @brief SPI driver selector */
   #define   __AIR_QUALITY4_DRV_I2C__                            /**<     @macro __AIR_QUALITY4_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __AIR_QUALITY4_DRV_UART__                           /**<     @macro __AIR_QUALITY4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup AIR_QUALITY4_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup AIR_QUALITY4_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup AIR_QUALITY4_INIT Driver Initialization */              /** @{ */

#ifdef   __AIR_QUALITY4_DRV_SPI__
void air_quality4_spiDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P spiObj);
#endif
#ifdef   __AIR_QUALITY4_DRV_I2C__
void air_quality4_i2cDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P i2cObj, uint8_t slave);
#endif
#ifdef   __AIR_QUALITY4_DRV_UART__
void air_quality4_uartDriverInit(T_AIR_QUALITY4_P gpioObj, T_AIR_QUALITY4_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup AIR_QUALITY4_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Get ID function
 *
 * param[out] *buff     Pointer to the buffer when data will be writen
 *
 * Function writes 48-bit ID data to buffer determined by pointer in parametar of function.
 */
void air_quality4_getID(uint8_t *buff);

/**
 * @brief Initialization function
 *
 * Function initializes click and starts measurement.
 */
void air_quality4_init();

/**
 * @brief Generic read function
 *
 * param[out] *readAir     Pointer to the buffer when data will be writen
 *
 * Function writes 6 bytes CO2 data (2 bytes) and TVOC data (2 bytes) with CRC data for each other
 * to buffer determined by pointer in parametar of function.
 */
void air_quality4_measureQuality(uint8_t *readAir);

/**
 * @brief Read CO2 and TVOC function
 *
 * param[out] *value     Pointer to the buffer when data will be writen
 *
 * Function writes 2 bytes CO2 data and 2 bytes TVOC data without CRC data to buffer determined 
 * by pointer in parametar of function.
 */
void air_quality4_getCO2AndTVOC(uint16_t *value);

/**
 * @brief Generic read function
 *
 * param[out] *readAir     Pointer to the buffer when data will be writen
 *
 * Function writes 6 bytes H2 data (2 bytes) and EthOH - Ethanol data (2 bytes) with CRC data for each other
 * to buffer determined by pointer in parametar of function.
 */
void air_quality4_measureSignal(uint8_t *readAir);

/**
 * @brief Read H2 and EthOH function
 *
 * param[out] *value     Pointer to the buffer when data will be writen
 *
 * Function writes 2 bytes H2 data and 2 bytes EthOH data without CRC data to buffer determined 
 * by pointer in parametar of function.
 */
void air_quality4_getH2AndEthOH(uint16_t *value);

/**
 * @brief Get Baseline function
 *
 * param[out] *readAir     Pointer to the buffer when data will be writen
 *
 * Function writes 6 bytes baseline data for the two air quality signals and CRC data for each other
 * to buffer determined by pointer in parametar of function.
 * This data should be stored on an external memory.
 */
void air_quality4_getBaseline(uint16_t *readAir);

/**
 * @brief Set Baseline function
 *
 * Function writes 6 bytes baseline data on I2C bus for the two air quality signals and CRC data for each other.
 */
void air_quality4_setBaseline();

/**
 * @brief Software reset function
 *
 * Function calls general reset witch resets all states on the chip and initializes chip again.
 * Function will not reset external memory state.
 */
void air_quality4_softReset();

/**
 * @brief Get version function
 *
 * param[out] *version     Pointer to the buffer when data will be writen
 *
 * Function writes chip version data to buffer determined by pointer in parametar of function.
 */
void air_quality4_getVersion(uint8_t *version);

/**
 * @brief Measure test function
 *
 * param[out] *value     Pointer to the buffer when data will be writen
 *
 * Function writes measurement test data to buffer determined by pointer in parametar of function.
 */
void air_quality4_measureTest(uint8_t *value);
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_AirQuality4_STM.c
    @example Click_AirQuality4_TIVA.c
    @example Click_AirQuality4_CEC.c
    @example Click_AirQuality4_KINETIS.c
    @example Click_AirQuality4_MSP.c
    @example Click_AirQuality4_PIC.c
    @example Click_AirQuality4_PIC32.c
    @example Click_AirQuality4_DSPIC.c
    @example Click_AirQuality4_AVR.c
    @example Click_AirQuality4_FT90x.c
    @example Click_AirQuality4_STM.mbas
    @example Click_AirQuality4_TIVA.mbas
    @example Click_AirQuality4_CEC.mbas
    @example Click_AirQuality4_KINETIS.mbas
    @example Click_AirQuality4_MSP.mbas
    @example Click_AirQuality4_PIC.mbas
    @example Click_AirQuality4_PIC32.mbas
    @example Click_AirQuality4_DSPIC.mbas
    @example Click_AirQuality4_AVR.mbas
    @example Click_AirQuality4_FT90x.mbas
    @example Click_AirQuality4_STM.mpas
    @example Click_AirQuality4_TIVA.mpas
    @example Click_AirQuality4_CEC.mpas
    @example Click_AirQuality4_KINETIS.mpas
    @example Click_AirQuality4_MSP.mpas
    @example Click_AirQuality4_PIC.mpas
    @example Click_AirQuality4_PIC32.mpas
    @example Click_AirQuality4_DSPIC.mpas
    @example Click_AirQuality4_AVR.mpas
    @example Click_AirQuality4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __air_quality4_driver.h

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