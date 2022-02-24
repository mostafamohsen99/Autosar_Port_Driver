 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mustafa Mohsen
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H



/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Dio Module Id */
#define PORT_MODULE_ID    (124U)

/* Dio Instance Id */
#define PORT_INSTANCE_ID  (0U)
/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)
/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)
/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif
   
#include "Port_Cfg.h"
 /*AUTOSAR Checking between Port_Cfg.h and port modules*/
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif
   /* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PORT_Cfg.h does not match the expected version"
#endif
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
 /* service Id for port init*/
#define PORT_INIT                   (uint8)0x00
   
/* service id for port setting direction*/
#define PORT_SET_PIN_DIRECTION      (uint8)0x01
   
/* service id to refresh the port*/
#define PORT_REFRESH_PORT_DIRECTION (uint8)0x02
   
 /* service id to get the version of the port*/
#define PORT_GET_VERSION_INFO       (uint8)0x03
   
 /*service id to set the pinmode of the portpin*/
#define PORT_SET_PIN_MODE           (uint8)0x04
   

   /*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
  /* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN               (uint8)0x0A
   
 /*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE  (uint8)0x0B
   
 /*API Port_Init service called with wrong parameter.*/
#define PORT_E_PARAM_CONFIG            (uint8)0x0C
   
 /*API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_PARAM_INVALID_MODE      (uint8)0x0D
   
 /*API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE       (uint8)0x0E
   
 /*API service called without module initialization */
#define PORT_E_UNINIT                  (uint8)0x0F
   
/* APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER           (uint8)0x10
  /*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

 /* data type carry all pin ports*/
typedef uint8 Port_PinType;

/* data type to set the pinmode to the portpin*/
typedef uint8 Port_PinModeType;
   
 /* Description: Enum to hold PIN direction */
typedef enum
{
   PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/*shall be configurable with a number of port pin modes*/
typedef enum
{
  PORT_PIN_MODE_ADC,
  PORT_PIN_MODE_DIO,
  PORT_PIN_MODE_CAN,
  PORT_PIN_MODE_DIO_GPT,
  PORT_PIN_MODE_WDG,
  PORT_PIN_MODE_PWM,
  PORT_PIN_MODE_UART,
  PORT_PIN_MODE_SSI,
  PORT_PIN_MODE_FAULT,
  PORT_PIN_MODE_USB,
  PORT_PIN_MODE_IDX,
  PORT_PIN_MODE_U1RTS,
  PORT_PIN_MODE_PH,
  PORT_PIN_MODE_U1CTS,
  PORT_PIN_MODE_NMI,
  PORT_PIN_MDDE_C0,
  PORT_PIN_MODE_TRD,
  PORT_PIN_MODE_PWM_2,
  PORT_PIN_MODE_UART_2,
  PORT_PIN_MODE_SSI_2,
  PORT_PIN_MODE_I2C
  
}Port_Pin_Mode;

/*enum used to determine initial values*/
typedef enum
{
  PORT_PIN_LOW, PORT_PIN_HIGH
}Port_Pin_Level_Value;

/*Enum to allow to change the direction of the pin*/
typedef enum
{
  PIN_DIRECTION_FALSE,PIN_DIRECTION_TRUE
}Port_Pin_Direction_Changeable;

/*enum to allow to change the mode of the pin*/
typedef enum
{
  PIN_MODE_FALSE,PIN_MODE_TRUE
}Port_Pin_Mode_Changeable;

/*shall be used for the symbolic name of a Port Pin.*/
typedef struct
{
 /* member contains the port number*/
   uint8 port_num;
   
  /*memeber contains the pin number*/
   uint8 pin_num;
   
   /*member contains the direction of the  port pin*/
   Port_PinDirectionType direction;
   
   /*member contains the resistor if it's input*/
   Port_InternalResistor resistor;
   
   /*member contains the Mode of the port pin*/
   Port_Pin_Mode value;
   
   /*member contains the level_value of the port_pin*/
   Port_Pin_Level_Value Level;
   
   /*member determines if the direction of the portpin can be changed*/
   Port_Pin_Direction_Changeable Dir;
   
   /*member determines if the mode of the portpin can be changed*/
   Port_Pin_Mode_Changeable Mod;	
}Port_Config_Channel;
 
 /*Port_Config to pass the parameters*/
typedef struct Port_ConfigType
{
	Port_Config_Channel PORT_PINS[PORT_CONFIGURED_CHANNELS];
} Port_ConfigType;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*function for port initialization*/
void Port_Init(const Port_ConfigType* ConfigPtr );

#if(PORT_SET_PIN_DIRECTION_API==STD_ON)
/*The function Port_SetPinDirection shall set the port pin direction during runtime.*/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif

///*The function Port_RefreshPortDirection shall refresh the direction of all configured ports to the configured direction (PortPinDirection). */
void Port_RefreshPortDirection( void );

#if(PORT_VERSION_INFO_API ==STD_ON)
///*The function Port_GetVersionInfo shall return the version information of this module  */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

#if(PORT_SET_PIN_MODE_API==STD_ON)
///*The function Port_SetPinMode shall set the port pin mode of the referenced pin during runtime.   */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif

/*******************************************************************************
 *                       used variables on main                                    *
 *******************************************************************************/
/* value to unlock pins*/
#define GPIO_PORTF_LOCK_REG_VALUE              (uint32)0x4C4F434B  

/*PCTL mask offset*/
#define PCTL_OFFSET                            (uint32)0x0000000F 

/*value to shift left pins*/
#define Shifting_Pin                           (uint8)0x04

/*analog value of the pin*/
#define PORT_PIN_ADC_MODE                   (Port_PinModeType)0

/*digital value of the pin*/
#define PORT_PIN_DIGITAL_MODE                  (Port_PinModeType)1
   
/*CAN Mode of pin*/
#define  PORT_PIN_CAN_MODE                   (Port_PinModeType)2
  
/*gpt mode of pin*/
#define  PORT_PIN_DIO_GPT_MODE                (Port_PinModeType)3
   
/*watch dog timer mode of pin*/
#define  PORT_PIN_WDG_MODE                    (Port_PinModeType)4
   
/*pwm mode of pin*/   
#define  PORT_PIN_PWM_MODE                     (Port_PinModeType)5
 
/*uart mode of pin*/
#define  PORT_PIN_UART_MODE                   (Port_PinModeType)6
   
/*ssi mode of pin*/
#define  PORT_PIN_SSI_MODE                    (Port_PinModeType)7
   
/*fault mode of pin*/
#define  PORT_PIN_FAULT_MODE                  (Port_PinModeType)8
   
/*usb mode of pin*/
#define  PORT_PIN_USB_MODE                    (Port_PinModeType)9
   
/*idx mode of pin*/
#define  PORT_PIN_IDX_MODE                     (Port_PinModeType)10
   
/*u1rts mode of pin*/
#define  PORT_PIN_U1RTS_MODE                  (Port_PinModeType)11
   
/*ph mode of pin*/
#define  PORT_PIN_PH_MODE                     (Port_PinModeType)12
   
/*u1cts mode of pin*/
#define  PORT_PIN_U1CTS_MODE                  (Port_PinModeType)13
   
/*nmi mode of pin*/
#define  PORT_PIN_NMI_MODE                    (Port_PinModeType)14
   
/*co mode of pin*/
#define  PORT_PIN_C0_MODE                     (Port_PinModeType)15
   
/*trd mode of pin*/
#define  PORT_PIN_TRD_MODE                    (Port_PinModeType)16
   
/* when we can use one mode with different types on one pin*/
   
/*nmi mode of pin*/
#define  PORT_PIN_PWM_MODE_2                    (Port_PinModeType)17
   
/*co mode of pin*/
#define  PORT_PIN_UART_MODE_2                     (Port_PinModeType)18
   
/*trd mode of pin*/
#define  PORT_PIN_SSI_MODE_2                    (Port_PinModeType)19

/*trd mode of pin*/
#define  PORT_PIN_I2C_MODE                    (Port_PinModeType)20
/* pctl values of each pin*/
 
#define  PORT_A_PIN_0_UART                    (uint8)0x01
#define  PORT_A_PIN_0_CAN                     (uint8)0x08

#define  PORT_A_PIN_2_SSI                     (uint8)0x02

#define  PORT_A_PIN_6_I2C                     (uint8)0x03
#define  PORT_A_PIN_6_PWM                     (uint8)0x05

   

#define  PORT_B_PIN_0_DIO_GPT                 (uint8)0x07





#define  PORT_B_PIN_4_PWM                     (uint8)0x04










   

#define  PORT_C_PIN_4_UART_1                  (uint8)0x02

#define  PORT_C_PIN_4_IDX                     (uint8)0x06
#define  PORT_C_PIN_4_WDG                     (uint8)0x07
#define  PORT_C_PIN_4_U1RTS                   (uint8)0x08

#define  PORT_C_PIN_5_UART_1                  (uint8)0x02

#define  PORT_C_PIN_5_PH                      (uint8)0x06

#define  PORT_C_PIN_5_U1CTS                   (uint8)0x08



#define  PORT_C_PIN_6_USB                     (uint8)0x08  



   
#define  PORT_D_PIN_0_SSI_3                   (uint8)0x01












#define  PORT_D_PIN_2_FAULT                   (uint8)0x04
#define  PORT_D_PIN_7_NMI                     (uint8)0x08
#define  PORT_F_PIN_0_U1RTS                   (uint8)0x01
#define  PORT_F_PIN_0_CO                      (uint8)0x09
#define  PORT_F_PIN_1_U1CTS                   (uint8)0x01
#define  PORT_F_PIN_1_TRD                     (uint8)0x0E
#define  PORT_F_PIN_3_SSI                     (uint8)0x02
#define  PORT_F_PIN_3_CAN                     (uint8)0x03
#define  PORT_F_PIN_4_FAULT                   (uint8)0x05
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;



#endif /* PORT_H */
