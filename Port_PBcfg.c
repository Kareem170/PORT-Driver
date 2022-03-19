 /* *****************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Kareem Mohamed
 ******************************************************************************/
#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

 /**************************************************** PORT PINS INTIALIZATION ************************************************/   
   const Port_ConfigType PinsIntialization = 
   {
     /* ******************************************* PORTA INTIALIZATION ***************************************************/
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTA , PORTA_PIN0 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE ,  
      PORTA , PORTA_PIN1 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE ,
      PORTA , PORTA_PIN2 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE , 
      PORTA , PORTA_PIN3 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE ,
      PORTA , PORTA_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTA , PORTA_PIN5 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTA , PORTA_PIN6 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTA , PORTA_PIN7 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,

     /* ******************************************* PORTB INTIALIZATION ************************************************** */
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTB , PORTB_PIN0 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,  
      PORTB , PORTB_PIN1 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTB , PORTB_PIN2 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTB , PORTB_PIN3 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTB , PORTB_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTB , PORTB_PIN5 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTB , PORTB_PIN6 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTB , PORTB_PIN7 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE ,
   
     /* ******************************************* PORTC INTIALIZATION ************************************************** */
     /* *********************************** JTAG PINS PC(0-->3) ARE EXCLUDED ******************************************** */
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTC , PORTC_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTC , PORTC_PIN5 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTC , PORTC_PIN6 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTC , PORTC_PIN7 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE ,

     /* ******************************************* PORTD INTIALIZATION ************************************************** */
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTD , PORTD_PIN0 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,  
      PORTD , PORTD_PIN1 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTD , PORTD_PIN2 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTD , PORTD_PIN3 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTD , PORTD_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTD , PORTD_PIN5 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTD , PORTD_PIN6 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTD , PORTD_PIN7 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,

     /* ******************************************* PORTE INTIALIZATION ************************************************** */
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTE , PORTE_PIN0 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,  
      PORTE , PORTE_PIN1 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTE , PORTE_PIN2 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTE , PORTE_PIN3 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTE , PORTE_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTE , PORTE_PIN5 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
   
     /* ******************************************* PORTF INTIALIZATION ************************************************** */
   /*(Port_num , Pin_num , Direction , Changable_Direction , Resistor , Initial_Value , ChangableMode , Pin_Mode)*/
      PORTF , PORTF_PIN0 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,  
      PORTF , PORTF_PIN1 , PORT_PIN_OUT , ChangeDirectionOFF , OFF , PORT_PIN_LEVEL_LOW , ChangeModeOFF , GPIO_MODE  ,
      PORTF , PORTF_PIN2 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  , 
      PORTF , PORTF_PIN3 , PORT_PIN_IN , ChangeDirectionOFF , PULL_DOWN , PORT_PIN_LEVEL_LOW , ChangeModeON , GPIO_MODE  ,
      PORTF , PORTF_PIN4 , PORT_PIN_IN , ChangeDirectionOFF , PULL_UP , PORT_PIN_LEVEL_LOW , ChangeModeOFF , GPIO_MODE     
   
   } ; 