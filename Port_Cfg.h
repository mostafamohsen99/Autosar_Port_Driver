 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mustafa Mohsen
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)
   
 /*spre-compile option for Port_SetPinDirection().*/  
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)
   
/* pre-compile option for Port_SetPinMode()*/  
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNELS              (43U)

/* Channel Index in the array of structures in PORT_PBcfg.c */

#define PortConf_PORT_A_PIN_0_ID       (uint8)0x00
#define PortConf_PORT_A_PIN_1_ID       (uint8)0x01
#define PortConf_PORT_A_PIN_2_ID       (uint8)0x02
#define PortConf_PORT_A_PIN_3_ID       (uint8)0x03
#define PortConf_PORT_A_PIN_4_ID       (uint8)0x04
#define PortConf_PORT_A_PIN_5_ID       (uint8)0x05
#define PortConf_PORT_A_PIN_6_ID       (uint8)0x06
#define PortConf_PORT_A_PIN_7_ID       (uint8)0x07

#define PortConf_PORT_B_PIN_0_ID       (uint8)0x08
#define PortConf_PORT_B_PIN_1_ID       (uint8)0x09
#define PortConf_PORT_B_PIN_2_ID       (uint8)0x0A
#define PortConf_PORT_B_PIN_3_ID       (uint8)0x0B
#define PortConf_PORT_B_PIN_4_ID       (uint8)0x0C
#define PortConf_PORT_B_PIN_5_ID       (uint8)0x0D
#define PortConf_PORT_B_PIN_6_ID       (uint8)0x0E
#define PortConf_PORT_B_PIN_7_ID       (uint8)0x0F

#define PortConf_PORT_C_PIN_0_ID       (uint8)0x10
#define PortConf_PORT_C_PIN_1_ID       (uint8)0x11
#define PortConf_PORT_C_PIN_2_ID       (uint8)0x12
#define PortConf_PORT_C_PIN_3_ID       (uint8)0x13
#define PortConf_PORT_C_PIN_4_ID       (uint8)0x14
#define PortConf_PORT_C_PIN_5_ID       (uint8)0x15
#define PortConf_PORT_C_PIN_6_ID       (uint8)0x16
#define PortConf_PORT_C_PIN_7_ID       (uint8)0x17

#define PortConf_PORT_D_PIN_0_ID       (uint8)0x18
#define PortConf_PORT_D_PIN_1_ID       (uint8)0x19
#define PortConf_PORT_D_PIN_2_ID       (uint8)0x1A
#define PortConf_PORT_D_PIN_3_ID       (uint8)0x1B
#define PortConf_PORT_D_PIN_4_ID       (uint8)0x1C
#define PortConf_PORT_D_PIN_5_ID       (uint8)0x1D
#define PortConf_PORT_D_PIN_6_ID       (uint8)0x1E
#define PortConf_PORT_D_PIN_7_ID       (uint8)0x1F

#define PortConf_PORT_E_PIN_0_ID       (uint8)0x20
#define PortConf_PORT_E_PIN_1_ID       (uint8)0x21
#define PortConf_PORT_E_PIN_2_ID       (uint8)0x22
#define PortConf_PORT_E_PIN_3_ID       (uint8)0x23
#define PortConf_PORT_E_PIN_4_ID       (uint8)0x24
#define PortConf_PORT_E_PIN_5_ID       (uint8)0x25

#define PortConf_PORT_F_PIN_0_ID       (uint8)0x26
#define PortConf_PORT_F_PIN_1_ID       (uint8)0x27
#define PortConf_PORT_F_PIN_2_ID       (uint8)0x28
#define PortConf_PORT_F_PIN_3_ID       (uint8)0x29
#define PortConf_PORT_F_PIN_4_ID       (uint8)0x2A

/* PORT Configured Port ID's  */

#define PortConf_PORT_A_PIN_0_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_1_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_2_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_3_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_4_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_5_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_6_PORT_NUM       (uint8)0x00
#define PortConf_PORT_A_PIN_7_PORT_NUM       (uint8)0x00
   
#define PortConf_PORT_B_PIN_0_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_1_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_2_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_3_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_4_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_5_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_6_PORT_NUM       (uint8)0x01
#define PortConf_PORT_B_PIN_7_PORT_NUM       (uint8)0x01
   
#define PortConf_PORT_C_PIN_0_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_1_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_2_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_3_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_4_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_5_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_6_PORT_NUM       (uint8)0x02
#define PortConf_PORT_C_PIN_7_PORT_NUM       (uint8)0x02
   
#define PortConf_PORT_D_PIN_0_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_1_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_2_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_3_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_4_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_5_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_6_PORT_NUM       (uint8)0x03
#define PortConf_PORT_D_PIN_7_PORT_NUM       (uint8)0x03
   
#define PortConf_PORT_E_PIN_0_PORT_NUM       (uint8)0x04
#define PortConf_PORT_E_PIN_1_PORT_NUM       (uint8)0x04
#define PortConf_PORT_E_PIN_2_PORT_NUM       (uint8)0x04
#define PortConf_PORT_E_PIN_3_PORT_NUM       (uint8)0x04
#define PortConf_PORT_E_PIN_4_PORT_NUM       (uint8)0x04
#define PortConf_PORT_E_PIN_5_PORT_NUM       (uint8)0x04
   
#define PortConf_PORT_F_PIN_0_PORT_NUM       (uint8)0x05
#define PortConf_PORT_F_PIN_1_PORT_NUM       (uint8)0x05
#define PortConf_PORT_F_PIN_2_PORT_NUM       (uint8)0x05
#define PortConf_PORT_F_PIN_3_PORT_NUM       (uint8)0x05
#define PortConf_PORT_F_PIN_4_PORT_NUM       (uint8)0x05

/*port configured portpins*/

#define PortConf_PORT_A_PIN_0_Port_Pin  (uint8)0x00
#define PortConf_PORT_A_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_A_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_A_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_A_PIN_4_Port_Pin   (uint8)0x04
#define PortConf_PORT_A_PIN_5_Port_Pin   (uint8)0x05
#define PortConf_PORT_A_PIN_6_Port_Pin   (uint8)0x06
#define PortConf_PORT_A_PIN_7_Port_Pin   (uint8)0x07
   
#define PortConf_PORT_B_PIN_0_Port_Pin   (uint8)0x00
#define PortConf_PORT_B_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_B_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_B_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_B_PIN_4_Port_Pin   (uint8)0x04
#define PortConf_PORT_B_PIN_5_Port_Pin   (uint8)0x05
#define PortConf_PORT_B_PIN_6_Port_Pin   (uint8)0x06
#define PortConf_PORT_B_PIN_7_Port_Pin   (uint8)0x07
   
#define PortConf_PORT_C_PIN_0_Port_Pin   (uint8)0x00
#define PortConf_PORT_C_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_C_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_C_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_C_PIN_4_Port_Pin   (uint8)0x04
#define PortConf_PORT_C_PIN_5_Port_Pin   (uint8)0x05
#define PortConf_PORT_C_PIN_6_Port_Pin   (uint8)0x06
#define PortConf_PORT_C_PIN_7_Port_Pin   (uint8)0x07
   
#define PortConf_PORT_D_PIN_0_Port_Pin   (uint8)0x00
#define PortConf_PORT_D_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_D_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_D_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_D_PIN_4_Port_Pin   (uint8)0x04
#define PortConf_PORT_D_PIN_5_Port_Pin   (uint8)0x05
#define PortConf_PORT_D_PIN_6_Port_Pin   (uint8)0x06
#define PortConf_PORT_D_PIN_7_Port_Pin   (uint8)0x07
   
#define PortConf_PORT_E_PIN_0_Port_Pin   (uint8)0x00
#define PortConf_PORT_E_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_E_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_E_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_E_PIN_4_Port_Pin   (uint8)0x04
#define PortConf_PORT_E_PIN_5_Port_Pin   (uint8)0x05
   
#define PortConf_PORT_F_PIN_0_Port_Pin   (uint8)0x00
#define PortConf_PORT_F_PIN_1_Port_Pin   (uint8)0x01
#define PortConf_PORT_F_PIN_2_Port_Pin   (uint8)0x02
#define PortConf_PORT_F_PIN_3_Port_Pin   (uint8)0x03
#define PortConf_PORT_F_PIN_4_Port_Pin   (uint8)0x04

/* default directions of portpins*/
#define PortConf_PORT_A_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_5_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_6_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_A_PIN_7_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

#define PortConf_PORT_B_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_5_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_6_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_B_PIN_7_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

#define PortConf_PORT_C_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_5_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_6_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_C_PIN_7_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

#define PortConf_PORT_D_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_5_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_6_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_D_PIN_7_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

#define PortConf_PORT_E_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_E_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_E_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_E_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_E_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_E_PIN_5_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

#define PortConf_PORT_F_PIN_0_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PORT_F_PIN_1_DIRECTION   (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PORT_F_PIN_2_DIRECTION   (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PORT_F_PIN_3_DIRECTION   (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PORT_F_PIN_4_DIRECTION   (Port_PinDirectionType)PORT_PIN_IN

/*default values of pullup and pulldown resistors*/
#define PortConf_PORT_A_PIN_0_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_4_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_5_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_6_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_A_PIN_7_RESISTOR   (Port_InternalResistor)OFF

#define PortConf_PORT_B_PIN_0_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_4_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_5_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_6_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_B_PIN_7_RESISTOR   (Port_InternalResistor)OFF

#define PortConf_PORT_C_PIN_0_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_4_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_5_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_6_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_C_PIN_7_RESISTOR   (Port_InternalResistor)OFF

#define PortConf_PORT_D_PIN_0_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_4_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_5_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_6_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_D_PIN_7_RESISTOR   (Port_InternalResistor)OFF

#define PortConf_PORT_E_PIN_0_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_E_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_E_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_E_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_E_PIN_4_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_E_PIN_5_RESISTOR   (Port_InternalResistor)OFF

#define PortConf_PORT_F_PIN_0_RESISTOR   (Port_InternalResistor)PULL_UP
#define PortConf_PORT_F_PIN_1_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_F_PIN_2_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_F_PIN_3_RESISTOR   (Port_InternalResistor)OFF
#define PortConf_PORT_F_PIN_4_RESISTOR   (Port_InternalResistor)PULL_UP

/*default values of portpins initial modes*/
#define PortConf_PORT_A_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_0_UART_MODE (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_A_PIN_0_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_A_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_1_UART_MODE (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_A_PIN_1_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN   
#define PortConf_PORT_A_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_2_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_A_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_3_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_A_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_4_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_A_PIN_5_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_5_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_A_PIN_6_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_6_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_A_PIN_6_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_A_PIN_7_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_A_PIN_7_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_A_PIN_7_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM

#define PortConf_PORT_B_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_0_UART_MODE (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_B_PIN_0_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_1_UART_MODE (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_B_PIN_1_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_2_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_B_PIN_2_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_3_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_B_PIN_3_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_4_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_B_PIN_4_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_B_PIN_4_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_B_PIN_4_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_4_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_B_PIN_5_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_5_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_B_PIN_5_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_B_PIN_5_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_B_PIN_5_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_5_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_B_PIN_6_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_6_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_B_PIN_6_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_B_PIN_6_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_B_PIN_7_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_B_PIN_7_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_B_PIN_7_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_B_PIN_7_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
   
#define PortConf_PORT_C_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_4_UART_4_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_4_UART_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_4_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_C_PIN_4_IDX_MODE  (Port_Pin_Mode)PORT_PIN_MODE_IDX
#define PortConf_PORT_C_PIN_4_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_C_PIN_4_U1RTS_MODE  (Port_Pin_Mode)PORT_PIN_MODE_U1RTS
#define PortConf_PORT_C_PIN_5_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_5_UART_4_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_5_UART_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_5_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_C_PIN_5_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_C_PIN_5_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_C_PIN_5_U1CTS_MODE  (Port_Pin_Mode)PORT_PIN_MODE_U1CTS
#define PortConf_PORT_C_PIN_6_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_6_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_6_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_C_PIN_6_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_C_PIN_6_USB_MODE  (Port_Pin_Mode)PORT_PIN_MODE_USB
#define PortConf_PORT_C_PIN_7_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_C_PIN_7_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_C_PIN_7_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_C_PIN_7_USB_MODE  (Port_Pin_Mode)PORT_PIN_MODE_USB   
   
#define PortConf_PORT_D_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_0_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_D_PIN_0_SSI_3_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_0_SSI_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_0_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_D_PIN_0_PWM_6_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_D_PIN_0_PWM_0_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_D_PIN_0_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_1_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_D_PIN_1_SSI_3_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_1_SSI_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_1_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_D_PIN_1_PWM_7_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_D_PIN_1_PWM_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_D_PIN_1_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_2_SSI_3_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_2_SSI_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_2_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_D_PIN_2_FAULT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_FAULT
#define PortConf_PORT_D_PIN_2_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_2_USB_MODE  (Port_Pin_Mode)PORT_PIN_MODE_USB
#define PortConf_PORT_D_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_3_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_D_PIN_3_SSI_3_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_3_SSI_1_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_D_PIN_3_IDX_MODE  (Port_Pin_Mode)PORT_PIN_MODE_IDX
#define PortConf_PORT_D_PIN_3_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_3_USB_MODE  (Port_Pin_Mode)PORT_PIN_MODE_USB
#define PortConf_PORT_D_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_4_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_D_PIN_4_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_5_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_5_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_D_PIN_5_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_6_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_6_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_D_PIN_6_FAULT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_FAULT
#define PortConf_PORT_D_PIN_6_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_D_PIN_6_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_7_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_D_PIN_7_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_D_PIN_7_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_D_PIN_7_WDG_MODE  (Port_Pin_Mode)PORT_PIN_MODE_WDG
#define PortConf_PORT_D_PIN_7_NMI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_NMI
   
#define PortConf_PORT_E_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_0_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_0_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_E_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_1_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_1_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_E_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_2_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_3_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_4_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_4_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_E_PIN_4_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_E_PIN_4_PWM_4_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_E_PIN_4_PWM_2_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_E_PIN_4_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_E_PIN_5_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_E_PIN_5_ADC_MODE  (Port_Pin_Mode)PORT_PIN_MODE_ADC
#define PortConf_PORT_E_PIN_5_UART_MODE  (Port_Pin_Mode)PORT_PIN_MODE_UART
#define PortConf_PORT_E_PIN_5_I2C_MODE  (Port_Pin_Mode)PORT_PIN_MODE_I2C
#define PortConf_PORT_E_PIN_5_PWM_5_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_E_PIN_5_PWM_3_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_E_PIN_4_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN

#define PortConf_PORT_F_PIN_0_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_F_PIN_0_U1RTS_MODE  (Port_Pin_Mode)PORT_PIN_MODE_U1RTS
#define PortConf_PORT_F_PIN_0_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_F_PIN_0_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_F_PIN_0_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_F_PIN_0_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_F_PIN_0_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_F_PIN_0_NMI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_NMI
#define PortConf_PORT_F_PIN_0_C0_MODE  (Port_Pin_Mode)PORT_PIN_MODE_C0
#define PortConf_PORT_F_PIN_1_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_F_PIN_1_U1CTS_MODE  (Port_Pin_Mode)PORT_PIN_MODE_U1CTS
#define PortConf_PORT_F_PIN_1_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_F_PIN_1_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_F_PIN_1_PH_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PH
#define PortConf_PORT_F_PIN_1_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_F_PIN_1_TRD_MODE  (Port_Pin_Mode)PORT_PIN_MODE_TRD
#define PortConf_PORT_F_PIN_1_C0_MODE  (Port_Pin_Mode)PORT_PIN_MODE_C0
#define PortConf_PORT_F_PIN_2_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_F_PIN_2_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_F_PIN_2_FAULT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_FAULT
#define PortConf_PORT_F_PIN_2_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_F_PIN_2_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_F_PIN_2_TRD_MODE  (Port_Pin_Mode)PORT_PIN_MODE_TRD
#define PortConf_PORT_F_PIN_3_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_F_PIN_3_CAN_MODE  (Port_Pin_Mode)PORT_PIN_MODE_CAN
#define PortConf_PORT_F_PIN_3_SSI_MODE  (Port_Pin_Mode)PORT_PIN_MODE_SSI
#define PortConf_PORT_F_PIN_3_PWM_MODE  (Port_Pin_Mode)PORT_PIN_MODE_PWM
#define PortConf_PORT_F_PIN_3_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_F_PIN_3_TRD_MODE  (Port_Pin_Mode)PORT_PIN_MODE_TRD
#define PortConf_PORT_F_PIN_4_DIO_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO
#define PortConf_PORT_F_PIN_4_FAULT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_FAULT
#define PortConf_PORT_F_PIN_4_IDX_MODE  (Port_Pin_Mode)PORT_PIN_MODE_IDX
#define PortConf_PORT_F_PIN_4_DIO_GPT_MODE  (Port_Pin_Mode)PORT_PIN_MODE_DIO_GPT
#define PortConf_PORT_F_PIN_4_USB_MODE  (Port_Pin_Mode)PORT_PIN_MODE_USB
   
/*port  default initial values*/
#define PortConf_PORT_A_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_5_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_6_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_A_PIN_7_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW

#define PortConf_PORT_B_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_5_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_6_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_B_PIN_7_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW

#define PortConf_PORT_C_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_5_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_6_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_C_PIN_7_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW

#define PortConf_PORT_D_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_5_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_6_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_D_PIN_7_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW

#define PortConf_PORT_E_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_E_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_E_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_E_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_E_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_E_PIN_5_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW

#define PortConf_PORT_F_PIN_0_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_HIGH
#define PortConf_PORT_F_PIN_1_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_F_PIN_2_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_F_PIN_3_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_LOW
#define PortConf_PORT_F_PIN_4_LEVEL_VALUE  (Port_Pin_Level_Value)PORT_PIN_HIGH

/*default port pins directions changed*/
#define PortConf_PORT_A_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_5_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_6_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_A_PIN_7_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE

#define PortConf_PORT_B_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_5_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_6_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_B_PIN_7_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE

#define PortConf_PORT_C_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_5_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_6_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_C_PIN_7_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE

#define PortConf_PORT_D_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_5_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_6_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_D_PIN_7_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE

#define PortConf_PORT_E_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_E_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_E_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_E_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_E_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE
#define PortConf_PORT_E_PIN_5_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_TRUE

#define PortConf_PORT_F_PIN_0_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_FALSE
#define PortConf_PORT_F_PIN_1_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_FALSE
#define PortConf_PORT_F_PIN_2_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_FALSE
#define PortConf_PORT_F_PIN_3_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_FALSE
#define PortConf_PORT_F_PIN_4_DIRECTION_CHANGEABLE  (Port_Pin_Direction_Changeable)PIN_DIRECTION_FALSE
   
/*default portpins mode changeable values*/
#define PortConf_PORT_A_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_5_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_6_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_A_PIN_7_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE

#define PortConf_PORT_B_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_5_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_6_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_B_PIN_7_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE

#define PortConf_PORT_C_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_FALSE
#define PortConf_PORT_C_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_FALSE
#define PortConf_PORT_C_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_FALSE
#define PortConf_PORT_C_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_FALSE
#define PortConf_PORT_C_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_C_PIN_5_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_C_PIN_6_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_C_PIN_7_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE

#define PortConf_PORT_D_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_5_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_6_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_D_PIN_7_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE

#define PortConf_PORT_E_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_E_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_E_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_E_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_E_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_E_PIN_5_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE

#define PortConf_PORT_F_PIN_0_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_F_PIN_1_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_F_PIN_2_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_F_PIN_3_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#define PortConf_PORT_F_PIN_4_MODE_CHANGEABLE  (Port_Pin_Mode_Changeable)PIN_MODE_TRUE
#endif

