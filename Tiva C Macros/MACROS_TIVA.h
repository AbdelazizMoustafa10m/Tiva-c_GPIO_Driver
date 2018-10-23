/**
 *  @file  <MACROS_TIVA>
 *  @brief <Header File of The Tiva C Macros.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <19-OCT-18>
 *
 */
#ifndef MACROS_TIVA_H_
#define MACROS_TIVA_H_

 /* This line access an 32 bit IO register ,  volatile keyword is to prevent optimization*/
    #define REG32_ACCESS(BASE , OFFSET)    (*(volatile uint32 *)( (BASE) | (OFFSET)))


    /* Note That in Tiva when Reading From The GPIO Data The Bit Masked with the address is the only value
     *  will be Read and the rest will be cleared */
     /* This line checks if a certain bit in any register is set and returns true if yes*/
    #define IS_PIN_SET(PORT_BASE,PIN_NO)   (REG32_ACCESS((PORT_BASE) , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) & (1U<<PIN_NO))

     /* This line checks if a certain bit in any register is cleared and returns true if yes*/
    #define IS_PIN_CLEAR(PORT_BASE,PIN_NO)  (!IS_PIN_SET((PORT_BASE),(PIN_NO)))

    /* This line sets a certain bit in any register*/
    #define SET_PIN(PORT_BASE,PIN_NO)  do{\
                                                    REG32_ACCESS(PORT_BASE , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) |= (1U<<PIN_NO) ;\
                                              }while(0)
    /* This line clears a certain bit in any register*/
    #define CLEAR_PIN(PORT_BASE,PIN_NO)    do{\
                                                    REG32_ACCESS(PORT_BASE , (GPIO_DATA_offset |GPIO_DATA_WRITE_OP_CODE)) &= (uint32) ~(1U<<PIN_NO) ;\
                                              }while(0)




#endif /* MACROS_TIVA_H_ */
