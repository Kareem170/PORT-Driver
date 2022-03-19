 /* *****************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Kareem Mohamed
 ***************************************************************************** */

#include "Port.h"
#include "tm4c123gh6pm_registers.h"
#include "Port_Reg.h"


static const Port_PIN_ConfigType *PtrConf = NULL_PTR;
static volatile uint8 Port_Status = PORT_NOT_INITIALIZED;


#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif


/* ***********************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): PinConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif

{  
  
    PtrConf = ConfigPtr->Pin_Config;
    volatile uint32 *Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    
    uint8 PinIndex ;
    Port_Status = PORT_INITIALIZED;
    volatile uint32 delay = 0;
    
    for (PinIndex =0 ;  PinIndex < PORT_PinsNumbers ; PinIndex++)
    {  
       switch(PtrConf[PinIndex].port_num)
       {
        case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
       }
      
      /* Enable clock for PORT and allow time for clock to start*/
        SYSCTL_REGCGC2_REG |= (1 << PtrConf[PinIndex].port_num);
        delay = SYSCTL_REGCGC2_REG;
    
    if( ((PtrConf[PinIndex].port_num == PORTD) && (PtrConf[PinIndex].pin_mode == PORTD_PIN7)) || ((PtrConf[PinIndex].port_num == PORTF) && (PtrConf[PinIndex].pin_num == PORTF_PIN0)) ) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = CONTROL_REG_UNLOCK_MASK;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , PtrConf[PinIndex].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
   
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    
    /************************************************ Pin Direction ****************************************/
    if(PtrConf[PinIndex].direction == PORT_PIN_OUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[PinIndex].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(PtrConf[PinIndex].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , PtrConf[PinIndex].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , PtrConf[PinIndex].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
   
    else if(PtrConf[PinIndex].direction == PORT_PIN_IN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[PinIndex].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(PtrConf[PinIndex].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , PtrConf[PinIndex].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(PtrConf[PinIndex].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PtrConf[PinIndex].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , PtrConf[PinIndex].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PtrConf[PinIndex].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    
    else
    {
        /* Do Nothing */
    }
       
    
    
/* ************************************ Setup Pin Modes ************************************************************************/    
 if (PtrConf[PinIndex].pin_mode == ANALOG_MODE)
{  
    /* ********************************************* Analog Mode  ***************************************************** */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PtrConf[PinIndex].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PtrConf[PinIndex].pin_num);        /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
}

else
{
    /* ********************************************* Digital Mode  ***************************************************** */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PtrConf[PinIndex].pin_num);  /* Clear the corresponding bit in the GPIOAMSEL register to Disable analog functionality on this pin */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PtrConf[PinIndex].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */


}

if (PtrConf[PinIndex].pin_mode == GPIO_MODE)
{
  /* ********************************************* GPIO Mode  ***************************************************** */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PtrConf[PinIndex].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(PMCx_CLEAR_MASK << (PtrConf[PinIndex].pin_num * 4));     /* Clear the PMCx bits for this pin */
}

else
{
   /* ********************************************* Alternative Modes  ***************************************************** */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PtrConf[PinIndex].pin_num);             /* Enable Alternative function for this pin by SET the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) =PtrConf[PinIndex].pin_mode;                          /* Put the mode number in the control register*/
}


   }
  }
}

/**********************************************************************************************************************************/

/* ***********************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin --> Port Pin ID number
                   Direction --> Port Pin Direction 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction
*********************************************************************************** */
#if ( PORT_SET_PIN_DIRECTION_API == STD_ON )
void Port_SetPinDirection( Port_PinType Pin,  Port_PinDirectionType Direction )
{
    volatile uint32 *Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (Port_Status == PORT_NOT_INITIALIZED)
    {
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
	PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {

    }
    if (Pin >= PORT_PinsNumbers )
    {
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
	PORT_E_PARAM_PIN);
        error = TRUE;
    } 
    else
    {

    }
        
    if(PtrConf[Pin].PortPinDirectionChangeable == ChangeDirectionOFF)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
       PORT_E_DIRECTION_UNCHANGEABLE);
       error = TRUE;
    }
    else 
    {
    
    }
#endif

/* In-case there are no errors */
if(error == FALSE)
{
    Port_Status = PORT_INITIALIZED;
	
    switch(PtrConf[Pin].port_num)
    {
        case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break; 
	case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
   
    if(Direction == PORT_PIN_IN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Pin);
    }
    
    else if(Direction == PORT_PIN_OUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Pin); 
    }    

}
}
#endif


/**********************************************************************************************************************************/

/* ***********************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refreshes port direction. 
************************************************************************************/
void Port_RefreshPortDirection( void )
{

#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* check if the Port driver is initialized*/
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_RefreshPortDirection_SID,
		PORT_E_UNINIT);
                
	}
	else {}
#endif       
	
   volatile uint32 *Port_Ptr = NULL_PTR;    /* point to the required Port Registers base address */
   uint8 Pin_Index;                         /* index to configure each pin (39)*/    
    
   for (Pin_Index = 0; Pin_Index < PORT_PinsNumbers ; Pin_Index++) 
     {
       if(PtrConf[Pin_Index].ChangableDirection == ChangeDirectionOFF)     /*Check that if PORT pin is UNchangable in RunTime*/ 
       {
              
	  switch(PtrConf[Pin_Index].port_num)
          {
            case 0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break; 
	   case 1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	   case 2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	   case 3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
           case 4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
           case 5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
          }
    
    
        /*Read Pin Direction */
        if(BIT_IS_SET(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[Pin_Index].pin_num))
        {
             SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[Pin_Index].pin_num); 
        }
       
        else if(BIT_IS_CLEAR(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[Pin_Index].pin_num))
        {
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PtrConf[Pin_Index].pin_num); 
        }
    
        else 
        {
           /* No Action Required */
        }
    
       }
       
       else if(PtrConf[Pin_Index].ChangableDirection == ChangeDirectionON) /*If the POrt pin is changable exclude it*/
       {   
          continue;
       }
    
     }  //End of for loop
}


/**********************************************************************************************************************************/

/* ***********************************************************************************
* Service Name: Port_SetPinModes
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in):Pin --> Port Pin ID number  
                 Mode --> New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin mode. 
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
   volatile uint32 *Port_Ptr = NULL_PTR;    /* point to the required Port Registers base address */
   boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (Port_Status == PORT_NOT_INITIALIZED)
    {
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
	PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {

    }
    if (Pin >= PORT_PinsNumbers )
    {
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
	PORT_E_PARAM_PIN);
        error = TRUE;
    } 
    else
    {

    }
    
    if (Mode <=9 || Mode == 14 ||  Mode == 15)
    {
    
    }
    
    else
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
       PORT_E_PARAM_INVALID_MODE);
       error = TRUE;
    }  
    
    if(PtrConf[Pin].ChangableMode == ChangeModeOFF)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
       PORT_E_MODE_UNCHANGEABLE);
       error = TRUE;
    }
    else 
    {
    
    }
#endif
   
   
   if( error == FALSE )
{     
switch(PtrConf[Pin].port_num)
{
   case 0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break; 
   case 1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
   case 2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
   case 3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
   case 4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
	    break;
   case 5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
}

/************************************* Setup Pin Modes ************************************************************************/    
 if (Mode == ANALOG_MODE)
{  
    /* ********************************************* Analog Mode  ***************************************************** */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin);      /* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin);     /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
}

else
{
    /* ********************************************* Digital Mode  ***************************************************** */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin);  /* Clear the corresponding bit in the GPIOAMSEL register to Disable analog functionality on this pin */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin);     /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */


}

if (Mode == GPIO_MODE)
{
  /* ********************************************* GPIO Mode  ***************************************************** */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(PMCx_CLEAR_MASK << (Pin * 4));     /* Clear the PMCx bits for this pin */
}

else
{
   /* ********************************************* Alternative Modes  ***************************************************** */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin);             /* Enable Alternative function for this pin by SET the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) = Mode;                          /* Put the mode number in the control register*/
  }
 }
}
#endif

/**********************************************************************************************************************************/

/* ***********************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): version Info --> Pointer to where to store the version information of this module. 
* Return value: None
* Description: Returns the version information of this module.
*********************************************************************************** */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType *versioninfo )
{

#if (PORT_DEV_ERROR_DETECT == STD_ON)
       /* Check if the pointer is not a Null pointer */
        if(NULL_PTR == versioninfo)
        {
            /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_GET_VERSION_INFO_SID ,PORT_E_PARAM_POINTER);
        }
        else
#endif 
        {

            versioninfo->vendorID =(uint16)PORT_VENDOR_ID;

            versioninfo->moduleID =(uint16)PORT_MODULE_ID;

            versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;

            versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;

            versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
        }
}
#endif