 /* *****************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Kareem Mohamed
 ***************************************************************************** */

#ifndef PORT_H
#define PORT_H

#include "Port_Cfg.h"
#include "Common_Macros.h"
#include "Std_Types.h"

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (120U)

/* PORT Instance Id */
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


/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif      
 
/* ************************************ DET Error classification ********************************************************** */   
#define PORT_E_PARAM_PIN 0x0A                    /* Invalid Port Pin ID requested */
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0B      /* Port Pin not configured as changeable*/  
#define PORT_E_PARAM_CONFIG 0x0C               /* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_INVALID_MODE 0x0D        /* API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE 0x0E        /* API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_UNINIT 0x0F                  /* API service called without module initialization*/
#define PORT_E_PARAM_POINTER 0x10          /* APIs called with a Null Pointer */  


/* *****************************************************************************
 *                      API Service Id Macros                                 *
 ***************************************************************************** */
/* Service ID for PORT INIT */
#define PORT_INIT_SID                  (uint8)0x00

/* Service ID for PORT SET PIN DIRECTION */
#define Port_SET_PIN_DIRECTION_SID     (uint8)0x01

/* Service ID for Port Refresh PortDirection */
#define Port_RefreshPortDirection_SID       (uint8)0x02

/* Service ID for Port Get Version Info */
#define Port_GetVersionInfo_SID             (uint8)0x03

/* Service ID for Port Set PinMode */
#define Port_SetPinMode_SID                 (uint8)0x04
      
/* ******************************************************************************
 *                              Module Data Types                              *
 ****************************************************************************** */

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to decide the pin direction changable or not */
 
typedef boolean PortPinDirectionChangeable;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

typedef uint8 Port_PinType;

typedef enum
{
  PORT_PIN_LEVEL_LOW,PORT_PIN_LEVEL_HIGH
}PortPinLevelValue;

/* Description: typedef for number of pin modes in certain port */
typedef uint8 Port_PinModeType;

/* Description: Enum to decide the pin mode changable or not */
typedef enum
{
    ChangeModeOFF , ChangeModeON
}Port_PinModeChangable;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirectionType direction;
    PortPinDirectionChangeable ChangableDirection;
    Port_InternalResistor resistor;
    PortPinLevelValue initial_value;
    Port_PinModeChangable ChangableMode;
    Port_PinModeType pin_mode;
    
}Port_PIN_ConfigType;

/* Array of 38 structure for  MCU Pins Execluding JTAG PINS */
typedef struct 
{
   Port_PIN_ConfigType Pin_Config[PORT_PinsNumbers];

}Port_ConfigType;

/* ******************************************************************************
 *                      Function Prototypes                                    *
 ****************************************************************************** */

/* ***********************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): PinConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
*********************************************************************************** */
void Port_Init(const Port_ConfigType *ConfigPtr );



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
void Port_SetPinDirection( Port_PinType Pin,  Port_PinDirectionType Direction );
#endif




/* ***********************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refreshes port direction. 
*********************************************************************************** */
void Port_RefreshPortDirection( void ); 



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
void Port_GetVersionInfo( Std_VersionInfoType *versioninfo );
#endif



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
*********************************************************************************** */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif

extern const Port_ConfigType PinsIntialization;


#endif /* PORT_H */
