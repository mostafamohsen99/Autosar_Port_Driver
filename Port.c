 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mustafa Mohsen
 ******************************************************************************/

#include "Port.h"
#include "port_registers.h"
#include "tm4c123gh6pm_registers.h"


#if(PORT_DEV_ERROR_DETECT == STD_ON) /*checking for errors on port*/

#include "Det.h"
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
   
#endif

STATIC const Port_Config_Channel *PORT_PIN_CHANNELS=NULL_PTR;
STATIC uint8 PORT_PIN_STATUS=PORT_NOT_INITIALIZED;


/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]:0x00
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: initalizes the portpin mode
       * set the default direction of the portpin
       * set the default resistor to input directions of the portpin
       * set the initial value of the portpins
       * set the initial pinmode of the portpins
       * set the choice to change direction of portpins
       * set the choice to change the mode of portpins
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr )
{
  boolean errors=FALSE;
#if(PORT_DEV_ERROR_DETECT == STD_ON)
  
if(ConfigPtr==NULL_PTR)
  {
  errors=TRUE;
  Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT,
		     PORT_E_PARAM_CONFIG);
  }
else
{
  
}

#endif
if(errors==FALSE)
{
  PORT_PIN_STATUS=PORT_INITIALIZED;
  uint8 count=0; /*counter to count all port configured channels*/
  PORT_PIN_CHANNELS=ConfigPtr->PORT_PINS;/* putting address of array to port_pin_channels*/
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  volatile uint32 delay = 0;
  while(count<=PORT_CONFIGURED_CHANNELS) /* while loop to access all port_config channels on Port_config*/
   {
    switch(PORT_PIN_CHANNELS[count].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<PORT_PIN_CHANNELS[count].port_num);
    delay = SYSCTL_REGCGC2_REG;
    
    if( ((PORT_PIN_CHANNELS[count].port_num == PortConf_PORT_D_PIN_7_PORT_NUM) && (PORT_PIN_CHANNELS[count].pin_num == PortConf_PORT_D_PIN_7_Port_Pin)) || ((PORT_PIN_CHANNELS[count].port_num == PortConf_PORT_F_PIN_0_PORT_NUM) && (PORT_PIN_CHANNELS[count].pin_num == PortConf_PORT_F_PIN_0_Port_Pin )) ) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = GPIO_PORTF_LOCK_REG_VALUE;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (PORT_PIN_CHANNELS[count].port_num == PortConf_PORT_C_PIN_0_PORT_NUM) && (PORT_PIN_CHANNELS[count].pin_num <= PortConf_PORT_C_PIN_3_Port_Pin) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    switch(PORT_PIN_CHANNELS[count].value)
    {
    case PORT_PIN_ADC_MODE :
      switch(count)
      {
      case PortConf_PORT_B_PIN_4_ID :
      case PortConf_PORT_B_PIN_5_ID :
      case PortConf_PORT_D_PIN_0_ID :
      case PortConf_PORT_D_PIN_1_ID :
      case PortConf_PORT_D_PIN_2_ID :
      case PortConf_PORT_D_PIN_3_ID :
      case PortConf_PORT_E_PIN_0_ID :
      case PortConf_PORT_E_PIN_1_ID :
      case PortConf_PORT_E_PIN_2_ID :
      case PortConf_PORT_E_PIN_3_ID :
      case PortConf_PORT_E_PIN_4_ID :
      case PortConf_PORT_E_PIN_5_ID :
         CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num); 
//        /*CLEAR digital mode of the pin*/
         SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
   *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(PCTL_OFFSET<< (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin));  
         break;
      default:
         break;
        
      }
      break;
      
    case PORT_PIN_DIGITAL_MODE:   //if the mode is Digital
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num); 
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(PCTL_OFFSET<< (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin));     /* Clear the PMCx bits for this pin */
      break;
    case PORT_PIN_CAN_MODE: //if the mode is can
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num); 
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);/* enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       switch(count) /*detect pin id to change it's mode*/
       {
       case PortConf_PORT_A_PIN_0_ID:
       case PortConf_PORT_A_PIN_1_ID:
       case PortConf_PORT_B_PIN_4_ID:
       case PortConf_PORT_B_PIN_5_ID:
       case PortConf_PORT_E_PIN_4_ID:
       case PortConf_PORT_E_PIN_5_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_0_CAN << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
       case PortConf_PORT_F_PIN_0_ID:
       case PortConf_PORT_F_PIN_3_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_3_CAN << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin));/*add value to pctl register*/
           break;
       default:
         break;
       }
       break;
       
    case  PORT_PIN_DIO_GPT_MODE: //if pin is dio_gpt
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count) /*detect pin id to change it's mode*/
       {
         case PortConf_PORT_B_PIN_0_ID:
         case PortConf_PORT_B_PIN_1_ID:
         case PortConf_PORT_B_PIN_2_ID:
         case PortConf_PORT_B_PIN_3_ID:
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_B_PIN_0_DIO_GPT << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
          default:
         break;
       }
      break;
      
    case PORT_PIN_WDG_MODE://when the pinmode is watch dog tiemer
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_D_PIN_4_ID:
         case PortConf_PORT_D_PIN_5_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_WDG << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
       default:
         break;
       }
      break;
      
    case PORT_PIN_PWM_MODE ://when the pin mode is pwm
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_A_PIN_6_ID:
         case PortConf_PORT_A_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_6_PWM << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
             break;
       }
      break;
      
    case PORT_PIN_UART_MODE ://when the pinmode is uart
         SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_A_PIN_0_ID:
         case PortConf_PORT_A_PIN_1_ID:
         case PortConf_PORT_B_PIN_0_ID:
         case PortConf_PORT_B_PIN_1_ID:
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_4_ID:
         case PortConf_PORT_D_PIN_5_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_E_PIN_0_ID:
         case PortConf_PORT_E_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
              *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_0_UART << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
             break;
       }
      break;
      
    case PORT_PIN_SSI_MODE://when the pin mode is ssi
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_A_PIN_2_ID:
         case PortConf_PORT_A_PIN_3_ID:
         case PortConf_PORT_A_PIN_4_ID:
         case PortConf_PORT_A_PIN_5_ID:
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
              *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_2_SSI << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
             break;     
       }
      break;
      
    case PORT_PIN_FAULT_MODE://when the pin is fault
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_F_PIN_2_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_2_FAULT << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_4_FAULT << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }
      break;
      
    case  PORT_PIN_USB_MODE://when the pin is usb
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_6_USB << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }
      break;
      
    case PORT_PIN_IDX_MODE://when the mode is IDX
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_IDX << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }
      break;
      
    case PORT_PIN_U1RTS_MODE://when the mode is u1rts
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_U1RTS << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         case PortConf_PORT_F_PIN_0_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_0_U1RTS << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }
      break;
      
    case PORT_PIN_PH_MODE ://when the mode is PH
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_PH << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }
      break;
      
    case PORT_PIN_U1CTS_MODE : //when the mode is u1cts
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_C_PIN_5_ID:
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_U1CTS << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_1_U1CTS << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }  
      break;
      
    case PORT_PIN_NMI_MODE: //when the mode is nmi
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_7_NMI << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }  
      break;
      
    case PORT_PIN_C0_MODE: //when is the mode is co
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_0_CO << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }  
      break;
      
    case PORT_PIN_TRD_MODE://if the mode is trd when there is more than trd mode one pin*
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_1_TRD << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
             break;      
       }  
      break;
      
    case PORT_PIN_PWM_MODE_2: //if the mode is pwm when there is more than pwm mode one pin*
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
       switch(count)
       {
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
             *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_B_PIN_4_PWM << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
             break;
       }
       break;
       
    case PORT_PIN_UART_MODE_2://if the mode is uart when there is more than uart mode one pin*
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);  /*enable alternate function*/
      switch(count)
      {
       case PortConf_PORT_C_PIN_4_ID:
       case PortConf_PORT_C_PIN_5_ID:
               *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_UART_1 << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;     
  default:
             break;
      }
       break;

    case PORT_PIN_SSI_MODE_2: //if the mode is ssi when there is more than ssi mode one pin*
      switch(count)
      {
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_0_SSI_3 << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
             break;     
      }
      break;
     case PORT_PIN_I2C_MODE: //when the mode is I2C
      switch(count)
      {
         case PortConf_PORT_A_PIN_6_ID:
         case PortConf_PORT_A_PIN_7_ID:
         case PortConf_PORT_B_PIN_2_ID:
         case PortConf_PORT_B_PIN_3_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_6_I2C << (PORT_PIN_CHANNELS[count].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
             break;     
      }
      break;
       default:
             break;  
    }
   
    
    
    if(PORT_PIN_CHANNELS[count].direction == PORT_PIN_OUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(PORT_PIN_CHANNELS[count].Level == PORT_PIN_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(PORT_PIN_CHANNELS[count].direction == PORT_PIN_IN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(PORT_PIN_CHANNELS[count].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(PORT_PIN_CHANNELS[count].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    else
    {
        /* Do Nothing */
    }
    
    
    count++; /*addition of pointer to struct to arrow to next index*/
   }
} 
}
/*******************************************************************************************
* Service Name:Port_SetPinDirection
* Service ID[hex]:0x01
* Sync/Async:Synchronous
* Reentrancy:Reentrant
* Parameters (in): Pin - Port Pin ID number         Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None           
* Description: Function to Set the pin direction of the port
*******************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
  boolean errors=FALSE; /* bool to check on errors*/
#if(PORT_DEV_ERROR_DETECT==STD_ON) /*check for availability of errors*/
  if(Pin>=PORT_CONFIGURED_CHANNELS)/* if pin greater than the number of configured channels*/
  {
   errors=TRUE;/*there is an error*/
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION ,
		     PORT_E_PARAM_PIN);
   /* pass error that the pin number is invalid*/
  }
  else
  {
    /* do noting*/
  }
  if(PORT_PIN_STATUS==PORT_NOT_INITIALIZED) /* check if the port not initialized on port_Init)*/
  {
    errors=TRUE; /*there is an error*/
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION ,
		     PORT_E_UNINIT ); 
/* pass error that the port doesn't begins*/
  }
  else
  {
    /* do no thing*/
  }
  if(PORT_PIN_CHANNELS[Pin].Dir==PIN_DIRECTION_FALSE) /*if there is no ability to change the direction of the pin*/
  {
    errors=TRUE; /*there is an error*/
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION ,
		     PORT_E_DIRECTION_UNCHANGEABLE);
   /*pass error that the direction will not change*/
  }
  else
  {
    /* Do nothing*/
  }
#endif
  if(errors==FALSE)
  {
    volatile uint32 *Port_ptr=NULL_PTR; /*pointer to hold base address of registers*/
    switch(PORT_PIN_CHANNELS[Pin].port_num)
    { 
    case 0:Port_ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; /*port_a_base_address*/
           break;
    case 1:Port_ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS;/*port_b_base_address*/
           break;
    case 2:Port_ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;/*port_c_base_address*/
           break;
    case 3:Port_ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;/*port_d_base_address*/
           break;    
    case 4:Port_ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS; /*port_e_base_address*/
           break;
    case 5:Port_ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;/*port_f_base_address*/
           break;
    }
   if(Direction==PORT_PIN_IN) /*if the direction is input*/
   {
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);
     /* add the value to the register*/
   }
   else if(Direction==PORT_PIN_OUT) /*if the direction is output*/
   {  
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);
     /* add the value to the register*/
   }
   else
   {
     /* Do no thing*/
   }
  }
}
#endif
/*******************************************************************************************
* Service Name:Port_RefreshPortDirection
* Service ID[hex]:0x02
* Sync/Async:Synchronous
* Reentrancy:Non-Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None           
* Description: Refreshes port direction
*******************************************************************************************/
void Port_RefreshPortDirection( void )
{
  boolean errors=FALSE;
  #if(PORT_DEV_ERROR_DETECT==STD_ON)
     if(PORT_PIN_STATUS==PORT_NOT_INITIALIZED) /* check if the port not initialized on port_Init)*/
  {
    errors=TRUE; /*there is an error*/
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION ,
		     PORT_E_UNINIT ); 
   /* pass error that the port doesn't begins*/
  }
#endif
  if(errors==FALSE)
  {
    uint8 count=0; /*counter until PORT_CONFIGURED_CHANNELS*/
    while(count<PORT_CONFIGURED_CHANNELS) /*count until PORT_CONFIGURED_CHANNELS*/
    {
      if(PORT_PIN_CHANNELS[count].Dir==PIN_DIRECTION_TRUE) /*if the direction of the pin changed during run tinme*/
      {
        count++;/*increment the counter to go to the next pin*/
        continue; /*back again to while loop*/
      } 
      else if(PORT_PIN_CHANNELS[count].Dir==PIN_DIRECTION_FALSE) /*if the direction of the pin doesn't change during run time */
      {
           volatile uint32 *Port_ptr=NULL_PTR; /*pointer to hold base address of registers*/
           switch(PORT_PIN_CHANNELS[count].port_num)
           { 
           case 0:Port_ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; /*port_a_base_address*/
                  break;
           case 1:Port_ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS;/*port_b_base_address*/
                  break;
           case 2:Port_ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;/*port_c_base_address*/
                  break;
           case 3:Port_ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;/*port_d_base_address*/
                  break;    
           case 4:Port_ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS; /*port_e_base_address*/
                  break;
           case 5:Port_ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;/*port_f_base_address*/
                  break;
            } 
         if(PORT_PIN_CHANNELS[count].direction == PORT_PIN_IN)
         {
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num); 
         }
         else if(PORT_PIN_CHANNELS[count].direction==PORT_PIN_OUT)
         {
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIR_REG_OFFSET) , PORT_PIN_CHANNELS[count].pin_num);
         }
         else
         {
           /* Do no thing*/
         }
      }
      else
      {
        /*Do nothing*/
      }
        /*pass the value of direc to the direction of the pin again*/
      count++; /*increment the counter to go to the next pin*/
    }
  }
}
/*******************************************************************************************
* Service Name:Port_GetVersionInfo
* Service ID[hex]:0x03
* Sync/Async:Synchronous
* Reentrancy:Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo Pointer to where to store the version information of this module.
* Return value: None           
* Description: Returns the version information of this module.
*******************************************************************************************/
#if(PORT_VERSION_INFO_API ==STD_ON)
///*The function Port_GetVersionInfo shall return the version information of this module  */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  boolean errors=FALSE;
#if(PORT_DEV_ERROR_DETECT==STD_ON)
  if(versioninfo==NULL_PTR)
  {
    errors=TRUE;
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO  ,
		     PORT_E_PARAM_POINTER ); 
  }
  else
  {
    /*Do nothing*/
  }
#endif
  if(errors==FALSE)
  {
    /* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
  }
  else
  {
   /* Do NoThing*/ 
  }
}
#endif
/*******************************************************************************************
* Service Name:Port_SetPinMode
* Service ID[hex]:0x04
* Sync/Async:Synchronous
* Reentrancy:Reentrant
* Parameters (in): Pin    Port Pin Id number                      Mode             New Port Pin Mode
* Parameters (inout): None
* Parameters (out): versioninfo Pointer to where to store the version information of this module.
* Return value: None           
* Description: Set the port pin mode
*******************************************************************************************/
#if(PORT_SET_PIN_MODE_API == STD_ON)

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
  boolean errors=FALSE;
  #if(PORT_DEV_ERROR_DETECT == STD_ON)
   if(Pin>=PORT_CONFIGURED_CHANNELS)/* if pin greater than the number of configured channels*/
  {
   errors=TRUE;/*there is an error*/
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,
		     PORT_E_PARAM_PIN);
   /* pass error that the pin number is invalid*/
  }
  else
  {
    /* Do nothing*/
  }
  
   if(PORT_PIN_STATUS==PORT_NOT_INITIALIZED) /* check if the port not initialized on port_Init)*/
  {
    errors=TRUE; /*there is an error*/
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,
		     PORT_E_UNINIT ); 
/* pass error that the port doesn't begins*/
  }
  else
  {
    /*Do no thing*/
  }
   if(PORT_PIN_CHANNELS[Pin].Mod==PIN_MODE_FALSE) /*if there is no ability to change the direction of the pin*/
  {
    errors=TRUE; /*there is an error*/
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE ,
		     PORT_E_MODE_UNCHANGEABLE);
   /*pass error that the direction will not change*/
  }
  else
  {
    /* Do nothing*/
  }
#endif
  if(errors==FALSE)
  {
    volatile uint32 *Port_ptr=NULL_PTR; /*pointer to hold base address of registers*/
    switch(PORT_PIN_CHANNELS[Pin].port_num)
    { 
    case 0:Port_ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; /*port_a_base_address*/
           break;
    case 1:Port_ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS;/*port_b_base_address*/
           break;
    case 2:Port_ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;/*port_c_base_address*/
           break;
    case 3:Port_ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;/*port_d_base_address*/
           break;    
    case 4:Port_ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS; /*port_e_base_address*/
           break;
    case 5:Port_ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;/*port_f_base_address*/
           break;
    }
    switch(Mode)
    {
    case PORT_PIN_ADC_MODE :
      switch(Pin)
      {
      case PortConf_PORT_B_PIN_4_ID :
      case PortConf_PORT_B_PIN_5_ID :
      case PortConf_PORT_D_PIN_0_ID :
      case PortConf_PORT_D_PIN_1_ID :
      case PortConf_PORT_D_PIN_2_ID :
      case PortConf_PORT_D_PIN_3_ID :
      case PortConf_PORT_E_PIN_0_ID :
      case PortConf_PORT_E_PIN_1_ID :
      case PortConf_PORT_E_PIN_2_ID :
      case PortConf_PORT_E_PIN_3_ID :
      case PortConf_PORT_E_PIN_4_ID :
      case PortConf_PORT_E_PIN_5_ID :
         CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num); 
//        /*CLEAR digital mode of the pin*/
         SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
   *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) &= ~(PCTL_OFFSET<< (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin));  
         break;
      default:
         Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /* if the pin doesn't have this mode*/
         break;
        
      }
      break;
      
    case PORT_PIN_DIGITAL_MODE:   //if the mode is Digital
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num); 
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) &= ~(PCTL_OFFSET<< (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin));     /* Clear the PMCx bits for this pin */
      break;
    case PORT_PIN_CAN_MODE: //if the mode is can
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num); 
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);/* enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
       switch(Pin) /*detect pin id to change it's mode*/
       {
       case PortConf_PORT_A_PIN_0_ID:
       case PortConf_PORT_A_PIN_1_ID:
       case PortConf_PORT_B_PIN_4_ID:
       case PortConf_PORT_B_PIN_5_ID:
       case PortConf_PORT_E_PIN_4_ID:
       case PortConf_PORT_E_PIN_5_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_0_CAN << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
       case PortConf_PORT_F_PIN_0_ID:
       case PortConf_PORT_F_PIN_3_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_3_CAN << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin));/*add value to pctl register*/
           break;
       default:
         Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*THERE IS NO ANOTHER PIN AVAIABLE TO THIS MODE*/
         break;
       }
       break;
       
    case  PORT_PIN_DIO_GPT_MODE: //if pin is dio_gpt
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin) /*detect pin id to change it's mode*/
       {
         case PortConf_PORT_B_PIN_0_ID:
         case PortConf_PORT_B_PIN_1_ID:
         case PortConf_PORT_B_PIN_2_ID:
         case PortConf_PORT_B_PIN_3_ID:
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_B_PIN_0_DIO_GPT << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
          default:
         Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
         break;
       }
      break;
      
    case PORT_PIN_WDG_MODE://when the pinmode is watch dog tiemer
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_D_PIN_4_ID:
         case PortConf_PORT_D_PIN_5_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
            *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_WDG << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
           break;
       default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
         break;
       }
      break;
      
    case PORT_PIN_PWM_MODE ://when the pin mode is pwm
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_A_PIN_6_ID:
         case PortConf_PORT_A_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
            *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_6_PWM << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;
       }
      break;
      
    case PORT_PIN_UART_MODE ://when the pinmode is uart
         SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_A_PIN_0_ID:
         case PortConf_PORT_A_PIN_1_ID:
         case PortConf_PORT_B_PIN_0_ID:
         case PortConf_PORT_B_PIN_1_ID:
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_4_ID:
         case PortConf_PORT_D_PIN_5_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_E_PIN_0_ID:
         case PortConf_PORT_E_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
              *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_0_UART << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;
       }
      break;
      
    case PORT_PIN_SSI_MODE://when the pin mode is ssi
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_A_PIN_2_ID:
         case PortConf_PORT_A_PIN_3_ID:
         case PortConf_PORT_A_PIN_4_ID:
         case PortConf_PORT_A_PIN_5_ID:
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
              *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_2_SSI << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;     
       }
      break;
      
    case PORT_PIN_FAULT_MODE://when the pin is fault
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_F_PIN_2_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_2_FAULT << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_4_FAULT << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }
      break;
      
    case  PORT_PIN_USB_MODE://when the pin is usb
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_C_PIN_7_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_6_USB << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }
      break;
      
    case PORT_PIN_IDX_MODE://when the mode is IDX
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_D_PIN_3_ID:
         case PortConf_PORT_F_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_IDX << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }
      break;
      
    case PORT_PIN_U1RTS_MODE://when the mode is u1rts
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_4_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_4_U1RTS << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         case PortConf_PORT_F_PIN_0_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_0_U1RTS << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }
      break;
      
    case PORT_PIN_PH_MODE ://when the mode is PH
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_C_PIN_6_ID:
         case PortConf_PORT_D_PIN_6_ID:
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_PH << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }
      break;
      
    case PORT_PIN_U1CTS_MODE : //when the mode is u1cts
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_C_PIN_5_ID:
            *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_U1CTS << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_1_U1CTS << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }  
      break;
      
    case PORT_PIN_NMI_MODE: //when the mode is nmi
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_D_PIN_7_ID:
         case PortConf_PORT_F_PIN_0_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_7_NMI << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }  
      break;
      
    case PORT_PIN_C0_MODE: //when is the mode is co
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_F_PIN_0_ID:
         case PortConf_PORT_F_PIN_1_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_0_CO << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }  
      break;
      
    case PORT_PIN_TRD_MODE://if the mode is trd when there is more than trd mode one pin*
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_F_PIN_1_ID:
         case PortConf_PORT_F_PIN_2_ID:
         case PortConf_PORT_F_PIN_3_ID:
           *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_F_PIN_1_TRD << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
          default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;      
       }  
      break;
      
    case PORT_PIN_PWM_MODE_2: //if the mode is pwm when there is more than pwm mode one pin*
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
       switch(Pin)
       {
         case PortConf_PORT_B_PIN_4_ID:
         case PortConf_PORT_B_PIN_5_ID:
         case PortConf_PORT_B_PIN_6_ID:
         case PortConf_PORT_B_PIN_7_ID:
         case PortConf_PORT_C_PIN_4_ID:
         case PortConf_PORT_C_PIN_5_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
             *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_B_PIN_4_PWM << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;
       }
       break;
       
    case PORT_PIN_UART_MODE_2://if the mode is uart when there is more than uart mode one pin*
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable Digital*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);      /* clear the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_PIN_CHANNELS[Pin].pin_num);  /*enable alternate function*/
      switch(Pin)
      {
       case PortConf_PORT_C_PIN_4_ID:
       case PortConf_PORT_C_PIN_5_ID:
               *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_C_PIN_5_UART_1 << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
             break;     
  default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;
      }
       break;

    case PORT_PIN_SSI_MODE_2: //if the mode is ssi when there is more than ssi mode one pin*
      switch(Pin)
      {
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_D_PIN_2_ID:
         case PortConf_PORT_D_PIN_3_ID:
            *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_D_PIN_0_SSI_3 << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;     
      }
      break;
     case PORT_PIN_I2C_MODE: //when the mode is I2C
      switch(Pin)
      {
         case PortConf_PORT_A_PIN_6_ID:
         case PortConf_PORT_A_PIN_7_ID:
         case PortConf_PORT_B_PIN_2_ID:
         case PortConf_PORT_B_PIN_3_ID:
         case PortConf_PORT_D_PIN_0_ID:
         case PortConf_PORT_D_PIN_1_ID:
         case PortConf_PORT_E_PIN_4_ID:
         case PortConf_PORT_E_PIN_5_ID:
            *(volatile uint32 *)((volatile uint8 *)Port_ptr + PORT_CTL_REG_OFFSET) |= (PORT_A_PIN_6_I2C << (PORT_PIN_CHANNELS[Pin].pin_num * Shifting_Pin)); /*add value to pctl register*/
              break;
         default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;     
      }
      break;
       default:
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE); /*there is no another valid pin for this mode*/
             break;  
    }
  }
  else
  {
    /* Do Nothing*/
  }
  
}
#endif

 