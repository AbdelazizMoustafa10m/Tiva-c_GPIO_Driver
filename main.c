/**
 *  @file  <main.c>
 *  @brief <main application.>
 *         <It Implements the application of interfacing the
 *          Tiva C on Board RGB LED and the two switches >
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */

#include"Micro_Config_Tiva.h"
#include"GPIO.h"
#include"MACROS_TIVA.h"
#include"STD_TYPES.h"

#define PF_SW2 0U
#define PF_SW1  4U

#define RGB_RED_PIN  1U
#define RGB_BLUE_PIN  2U
#define RGB_GREEN_PIN  3U

int main(void)
{
    /* ENABLE PORTF CLOCK*/
    GPIO_CLOCK_ENABLE(GPIOF_CLOCK);
    /* UNLOCK PORTF and ALLOW Changes to be made to the port*/
    GPIO_UNLOCK(GPIOPF_APB_BASE);
    GPIO_COMMIT_ENABLE_8PINS(GPIOPF_APB_BASE);

    /* DISABLE Alternative function for PORTF*/
    GPIO_ALFUN_SETPINS(GPIOPF_APB_BASE,0);

    /* Set the two switches as an input*/
    GPIO_DIR_SELECT(GPIOPF_APB_BASE,PF_SW1,INPUT);
    GPIO_DIR_SELECT(GPIOPF_APB_BASE,PF_SW2,INPUT);

    /* ENABLE the internal PULL UP resistance for the switches*/
    GPIO_INTERNAL_RESISTANCE(GPIOPF_APB_BASE,GPIO_PUR_offset,PF_SW1,PULL_RESISTANCE_ENABLE);
    GPIO_INTERNAL_RESISTANCE(GPIOPF_APB_BASE,GPIO_PUR_offset,PF_SW2,PULL_RESISTANCE_ENABLE);

    /* SET the three LEDS as an OUTPUT*/
    GPIO_DIR_SELECT(GPIOPF_APB_BASE,RGB_GREEN_PIN,OUTPUT);
    GPIO_DIR_SELECT(GPIOPF_APB_BASE,RGB_RED_PIN,OUTPUT);
    GPIO_DIR_SELECT(GPIOPF_APB_BASE,RGB_BLUE_PIN,OUTPUT);

    /* SET The PINS as digital Function*/
    GPIO_DIGITAL_ENABLE_PINS(GPIOPF_APB_BASE,0x1FU);

    while(1)
           {

               if(IS_PIN_CLEAR(GPIOPF_APB_BASE,PF_SW2))
               {
                   SET_PIN(GPIOPF_APB_BASE,RGB_RED_PIN);
                   CLEAR_PIN(GPIOPF_APB_BASE,RGB_BLUE_PIN);
                   CLEAR_PIN(GPIOPF_APB_BASE,RGB_GREEN_PIN);
               }
               else if(IS_PIN_CLEAR(GPIOPF_APB_BASE,PF_SW1))
               {
                   SET_PIN(GPIOPF_APB_BASE,RGB_GREEN_PIN);
                   CLEAR_PIN(GPIOPF_APB_BASE,RGB_BLUE_PIN);
                   CLEAR_PIN(GPIOPF_APB_BASE,RGB_RED_PIN);
               }
               else
               {
                 CLEAR_PIN(GPIOPF_APB_BASE,RGB_RED_PIN);
               }
               while(IS_PIN_CLEAR(GPIOPF_APB_BASE,PF_SW1) && IS_PIN_CLEAR(GPIOPF_APB_BASE,PF_SW2))
               {
                  SET_PIN(GPIOPF_APB_BASE,RGB_BLUE_PIN);
                  CLEAR_PIN(GPIOPF_APB_BASE,RGB_GREEN_PIN);
                  CLEAR_PIN(GPIOPF_APB_BASE,RGB_RED_PIN);
               }

           }

}
