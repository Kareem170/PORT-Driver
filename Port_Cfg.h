 /* *****************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Kareem Mohamed
 ***************************************************************************** */

#ifndef PORT_CFG_H
#define PORT_CFG_H


#define PORT_NOT_INITIALIZED            (0U)
#define PORT_INITIALIZED                (1U)

#define ChangeDirectionOFF              (0U)
#define ChangeDirectionON               (1U) 
#define PMCx_CLEAR_MASK                 (0x0000000F)
#define CONTROL_REG_UNLOCK_MASK         (0x4C4F434B)

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
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Number of Pins in MCU Excluding The JTAG PINS */
#define PORT_PinsNumbers                      (39U)   


/* Precompile option for setting Pin direction API */
#define PORT_SET_PIN_DIRECTION_API            STD_OFF
											  
/* Precompile option to set pin mode API */
#define PORT_SET_PIN_MODE_API                 (STD_ON)   

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_MODE_CHANGEABLE              (STD_ON)   
   
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_OFF)
/* *************************************** Pins numbers Definitions ******************************************************** */

/* *** PORTA Pins *** */
#define PORTA_PIN0 (0U)
#define PORTA_PIN1 (1U)
#define PORTA_PIN2 (2U)
#define PORTA_PIN3 (3U)
#define PORTA_PIN4 (4U)
#define PORTA_PIN5 (5U)
#define PORTA_PIN6 (6U)
#define PORTA_PIN7 (7U)

/* *** PORTB Pins *** */
#define PORTB_PIN0 (0U)
#define PORTB_PIN1 (1U)
#define PORTB_PIN2 (2U)
#define PORTB_PIN3 (3U)
#define PORTB_PIN4 (4U)
#define PORTB_PIN5 (5U)
#define PORTB_PIN6 (6U)
#define PORTB_PIN7 (7U)

/* *** PORTC Pins *** */
#define PORTC_PIN0     /* JTAG PIN */
#define PORTC_PIN1     /* JTAG PIN */ 
#define PORTC_PIN2     /* JTAG PIN */
#define PORTC_PIN3     /* JTAG PIN */
#define PORTC_PIN4 (4U)
#define PORTC_PIN5 (5U)
#define PORTC_PIN6 (6U)
#define PORTC_PIN7 (7U)

/* *** PORTD Pins *** */
#define PORTD_PIN0 (0U)
#define PORTD_PIN1 (1U)
#define PORTD_PIN2 (2U)
#define PORTD_PIN3 (3U)
#define PORTD_PIN4 (4U)
#define PORTD_PIN5 (5U)
#define PORTD_PIN6 (6U)
#define PORTD_PIN7 (7U)

/* *** PORTE Pins *** */
#define PORTE_PIN0 (0U)
#define PORTE_PIN1 (1U)
#define PORTE_PIN2 (2U)
#define PORTE_PIN3 (3U)
#define PORTE_PIN4 (4U)
#define PORTE_PIN5 (5U)

/* *** PORTF Pins *** */
#define PORTF_PIN0 (0U)
#define PORTF_PIN1 (1U)
#define PORTF_PIN2 (2U)
#define PORTF_PIN3 (3U)
#define PORTF_PIN4 (4U)
   
/* *********************************************** PORT Numbers Definitions ************************************************ */
#define PORTA (0U)   
#define PORTB (1U)   
#define PORTC (2U)
#define PORTD (3U)
#define PORTE (4U)   
#define PORTF (5U)   
   
/* **********************************************  PORT_PinModes ********************************************************** */   
 
/* ********** Mode 0 ************* */
#define GPIO_MODE              (0U)

/* ********** Mode 1 ************* */   
#define UART0_RX                (1U)
#define UART0_TX                (1U)
#define PB0_UART1_RX            (1U)     /* PortB PIN0 Supports UART1 Mode */
#define PB1_UART1_TX            (1U)    /* PortB PIN1 Supports UART1 Mode */
#define UART2_RX                (1U)
#define UART2_TX                (1U)
#define UART3_RX                (1U)
#define UART3_TX                (1U)
#define UART4_RX                (1U)
#define UART4_TX                (1U)
#define UART5_RX                (1U)
#define UART5_TX                (1U)
#define UART6_RX                (1U)
#define UART6_TX                (1U)   
#define UART7_RX                (1U)
#define UART7_TX                (1U)   
#define SSI3_CLK                (1U)    /* Syncronous Serial Interface 3 */
#define SSI3_FSS                (1U)    /* Syncronous Serial Interface 3 */
#define SSI3_RX                 (1U)    /* Syncronous Serial Interface 3 */
#define SSI3_TX                 (1U)    /* Syncronous Serial Interface 3 */
#define PF0_UART1_RTS           (1U)    /* UART1 Request To Send */
#define PF1_UART1_CTS           (1U)    /* UART1 Clear To Send */

   
/* *********** Mode 2 ************ */   
#define SSI0_CLK                (2U) /* Syncronous Serial Interface 0 */
#define SSI0_FSS                (2U) /* Syncronous Serial Interface 0 */
#define SSI0_RX                 (2U) /* Syncronous Serial Interface 0 */
#define SSI0_TX                 (2U) /* Syncronous Serial Interface 0 */
#define SSI2_CLK                (2U) /* Syncronous Serial Interface 2 */
#define SSI2_FSS                (2U) /* Syncronous Serial Interface 2 */
#define SSI2_RX                 (2U) /* Syncronous Serial Interface 2 */  
#define SSI2_TX                 (2U) /* Syncronous Serial Interface 2 */  
#define PC4_UART1_RX            (2U) /* PortC PIN4 Supports UART1 Mode */
#define PC5_UART1_TX            (2U) /* PortC PIN5 Supports UART1 Mode */
#define SSI1_CLK                (2U) /* Syncronous Serial Interface 1 */
#define SSI1_FSS                (2U) /* Syncronous Serial Interface 1 */
#define SSI1_RX                 (2U) /* Syncronous Serial Interface 1 */
#define SSI1_TX                 (2U) /* Syncronous Serial Interface 1 */ 

/* *********** Mode 3 ************ */
#define I2C1_SCL                (3U) /* I2C1 Mode Clock pin */
#define I2C1_SDA                (3U) /* I2C1 Mode Data Pin */
#define I2C0_SCL                (3U) /* I2C0 Mode Clock pin */  
#define I2C0_SDA                (3U) /* I2C0 Mode Data Pin */
#define I2C3_SCL                (3U) /* I2C3 Mode Clock pin */
#define I2C3_SDA                (3U) /* I2C3 Mode Data Pin */
#define I2C2_SCL                (3U) /* I2C2 Mode Clock Pin */
#define I2C2_SDA                (3U) /* I2C2 Mode Data Pin */   
#define PF0_CAN0_RX             (3U) /* CAN0 Mode RX Pin */
#define PF3_CAN0_TX             (3U) /* CAN0 Mode TX Pin */   


/* *********** Mode 4 ************ */
#define M0_PWM2                 (4U) /* M0 PWM2 Mode */
#define M0_PWM3                 (4U) /* M0 PWM3 Mode */
#define M0_PWM0                 (4U) /* M0 PWM0 Mode */
#define M0_PWM1                 (4U) /* M0 PWM1 Mode */   
#define M0_PWM6                 (4U) /* M0 PWM6 Mode */   
#define M0_PWM7                 (4U) /* M0 PWM7 Mode */   
#define M0_FAULT0               (4U) /* M0 Fault0 Mode */
#define M0_PWM4                 (4U) /* M0 PWM4 Mode */
#define M0_PWM5                 (4U) /* M0 PWM5 Mode */


/* ********** Mode 5 ************** */   
#define M1_PWM2                 (5U) /* M1 PWM2 Mode */ 
#define M1_PWM3                 (5U) /* M1 PWM3 Mode */
#define M1_PWM0                 (5U) /* M1 PWM0 Mode */ 
#define M1_PWM1                 (5U) /* M1 PWM1 Mode */
#define M1_PWM4                 (5U) /* M1 PWM4 Mode */
#define M1_PWM5                 (5U) /* M1 PWM5 Mode */
#define M1_PWM6                 (5U) /* M1 PWM6 Mode */
#define M1_PWM7                 (5U) /* M1 PWM7 Mode */
#define M1_FAULT0               (5U) /* M1 Fault0 Mode */


/* ********** Mode 6 ************* */
#define ID_X1                   (6U)
#define PH_A1                   (6U)
#define PH_B1                   (6U)
#define ID_X0                   (6U)   
#define PH_A0                   (6U)
#define PH_B0                   (6U)

/* ************ Mode 7 ************* */
#define T2CCP0                  (7U)
#define T2CCP1                  (7U)
#define T3CCP0                  (7U)
#define T3CCP1                  (7U)   
#define T1CCP0                  (7U)
#define T1CCP1                  (7U)
#define T0CCP0                  (7U)
#define T0CCP1                  (7U)
#define WT0CCP0                 (7U)
#define WT0CCP1                 (7U)
#define WT1CCP0                 (7U)
#define WT1CCP1                 (7U)
#define WT2CCP0                 (7U)
#define WT2CCP1                 (7U)   
#define WT3CCP0                 (7U)   
#define WT3CCP1                 (7U)   
#define WT4CCP0                 (7U)
#define WT4CCP1                 (7U)
#define WT5CCP0                 (7U)
#define WT5CCP1                 (7U)   
 
/* *********** Mode 8 ************** */   
#define CAN1_RX                 (8U)
#define CAN1_TX                 (8U) 
#define PB4_CAN0_RX             (8U)
#define PB5_CAN0_TX             (8U)
#define PC4_U1_RTS              (8U)   
#define PC5_U1_CTS              (8U)
#define USB0_EPEN               (8U)
#define USB0_PFLT               (8U)
#define NMI                     (8U)
#define PE4_CAN0_RX             (8U)   
#define PE5_CAN0_TX             (8U)

   
/* ********** Mode 9 *************** */
#define C0_O                    (9U)
#define C1_O                    (9U)   

   
/* ********* Mode 14 ************** */
#define TRD0                   (14U)
#define TRD1                   (14U)
#define TR_CLK                 (14U)   

/* ******* Analog Mode *********** */
#define ANALOG_MODE            (15U)


#endif /* PORT_CFG_H */