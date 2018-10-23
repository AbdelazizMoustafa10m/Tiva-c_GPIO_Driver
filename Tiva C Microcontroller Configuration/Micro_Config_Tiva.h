/**
 *  @file  <MICRO_CONFIG_TIVA.h>
 *  @brief <Header File of The Tiva C configuration.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */


#ifndef MICRO_CONFIG_TIVA_H_
#define MICRO_CONFIG_TIVA_H_

  #include"STD_TYPES.h"

  /* System control base address and offsets.*/
  #define SYSTEM_CTL_BASE        (0x400FE000U)
  #define GPIO_CLOCKGATE_OFFSET  (0x608U)

  /* This macro is used whenever we want to write data to the microcontroller*/
  #define GPIO_DATA_WRITE_OP_CODE   (0x3FCU)

  /* GPIO PORT ADDRESS USING  APB Bus */
  #define GPIOPA_APB_BASE  (0x40004000U)
  #define GPIOPB_APB_BASE  (0x40005000U)
  #define GPIOPC_APB_BASE  (0x40006000U)
  #define GPIOPD_APB_BASE  (0x40007000U)
  #define GPIOPE_APB_BASE  (0x40024000U)
  #define GPIOPF_APB_BASE  (0x40025000U)

  /* GPIO PORT ADDRESS USING  AHB Bus */
  #define GPIOPA_AHB_BASE  (0x40058000U)
  #define GPIOPB_AHB_BASE  (0x40059000U)
  #define GPIOPC_AHB_BASE  (0x4005A000U)
  #define GPIOPD_AHB_BASE  (0x4005B000U)
  #define GPIOPE_AHB_BASE  (0x4005C000U)
  #define GPIOPF_AHB_BASE  (0x4005D000U)

  /* GPIO REGISTERS OFFSETS MAP */
  /* All PORTS Use This offset No Matter what interface Bus we Use we just OR PORT Base
   * with REG Offset */
  /* GPIO Registers Offset Can be Found @ P660 in the data sheet.*/
  #define GPIO_DATA_offset         (0x000U)
  #define GPIO_DIR_offset          (0x400U)
  #define GPIO_LOCK_offset         (0x520U)
  #define GPIO_CR_offset           (0x524U)
  #define GPIO_AFS_offset          (0x420U)
  #define GPIO_PORT_CTL_offset     (0x52CU)
  #define GPIO_PUR_offset          (0x510U)
  #define GPIO_PDR_offset          (0x514U)
  #define GPIO_DEN_offset          (0x51CU)




#endif /* MICRO_CONFIG_TIVA_H_ */
