/*******************************************************************************
 *                 Register Abstraction / STRUCTS
 ******************************************************************************/

// CORE
/** \brief  Union type to access the Application Program Status Register (APSR).*/
typedef union
{
  struct
  {
#if (__CORTEX_M != 0x04)
    uint32_t _reserved0:27;              /*!< bit:  0..26  Reserved                           */
#else
    uint32_t _reserved0:16;              /*!< bit:  0..15  Reserved                           */
    uint32_t GE:4;                       /*!< bit: 16..19  Greater than or Equal flags        */
    uint32_t _reserved1:7;               /*!< bit: 20..26  Reserved                           */
#endif
    uint32_t Q:1;                        /*!< bit:     27  Saturation condition flag          */
    uint32_t V:1;                        /*!< bit:     28  Overflow condition code flag       */
    uint32_t C:1;                        /*!< bit:     29  Carry condition code flag          */
    uint32_t Z:1;                        /*!< bit:     30  Zero condition code flag           */
    uint32_t N:1;                        /*!< bit:     31  Negative condition code flag       */
  } b;                                   /*!< Structure used for bit  access                  */
  uint32_t w;                            /*!< Type      used for word access                  */ 
} APSR_Type;



/** \brief  Union type to access the Interrupt Program Status Register (IPSR).*/
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /*!< bit:  0.. 8  Exception number                   */
    uint32_t _reserved0:23;              /*!< bit:  9..31  Reserved                           */
  } b;                                   /*!< Structure used for bit  access                  */
  uint32_t w;                            /*!< Type      used for word access                  */
} IPSR_Type;



// NVIC
/** \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).*/
typedef struct
{
  __IO uint32_t ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
       uint32_t RESERVED0[24];                                   
  __IO uint32_t ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
       uint32_t RSERVED1[24];                                    
  __IO uint32_t ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
       uint32_t RESERVED2[24];                                   
  __IO uint32_t ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
       uint32_t RESERVED3[24];                                   
  __IO uint32_t IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
       uint32_t RESERVED4[56];                                   
  __IO uint8_t  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
       uint32_t RESERVED5[644];                                  
  __O  uint32_t STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;                                               



// SYSTICK
/** \brief  Structure type to access the System Timer (SysTick).*/
typedef struct
{
  __IO uint32_t CTRL;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IO uint32_t LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  __IO uint32_t VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  __I  uint32_t CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

 
/* Memory mapping of Cortex-M3 Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address                  */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address           */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address              */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address                 */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */

#define InterruptType       ((InterruptType_Type *) SCS_BASE)         /*!< Interrupt Type Register           */
#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct          */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */
#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct         */
#define ITM                 ((ITM_Type *)           ITM_BASE)         /*!< ITM configuration struct          */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< Core Debug configuration struct   */

#if (__MPU_PRESENT == 1)
  #define MPU_BASE          (SCS_BASE +  0x0D90UL)                    /*!< Memory Protection Unit            */
  #define MPU               ((MPU_Type*)            MPU_BASE)         /*!< Memory Protection Unit            */
#endif




/*******************************************************************************
 *                 			NVIC functions
 ******************************************************************************/

/** \brief  Enable External Interrupt

    This function enables a device specific interupt in the NVIC interrupt controller.
    The interrupt number cannot be a negative value. 

    \param [in]      IRQn  Number of the external interrupt to enable
 */
static __INLINE void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* enable interrupt */
}


/** \brief  Disable External Interrupt

    This function disables a device specific interupt in the NVIC interrupt controller.
    The interrupt number cannot be a negative value. 

    \param [in]      IRQn  Number of the external interrupt to disable
 */
static __INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* disable interrupt */
}


/** \brief  Get Pending Interrupt

    This function reads the pending register in the NVIC and returns the pending bit
    for the specified interrupt. 

    \param [in]      IRQn  Number of the interrupt for get pending
    \return             0  Interrupt status is not pending
    \return             1  Interrupt status is pending
 */
static __INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((NVIC->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* Return 1 if pending else 0 */
}


/** \brief  Set Pending Interrupt

    This function sets the pending bit for the specified interrupt. 
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the interrupt for set pending
 */
static __INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* set interrupt pending */
}


/** \brief  Clear Pending Interrupt

    This function clears the pending bit for the specified interrupt. 
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the interrupt for clear pending
 */
static __INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* Clear pending interrupt */
}


/** \brief  Get Active Interrupt

    This function reads the active register in NVIC and returns the active bit. 
    \param [in]      IRQn  Number of the interrupt for get active
    \return             0  Interrupt status is not active
    \return             1  Interrupt status is active
 */
static __INLINE uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((NVIC->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* Return 1 if active else 0 */
}


/** \brief  Set Interrupt Priority

    This function sets the priority for the specified interrupt. The interrupt 
    number can be positive to specify an external (device specific) 
    interrupt, or negative to specify an internal (core) interrupt.

    Note: The priority cannot be set for every core interrupt.

    \param [in]      IRQn  Number of the interrupt for set priority
    \param [in]  priority  Priority to set
 */
static __INLINE void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff); } /* set Priority for Cortex-M  System Interrupts */
  else {
    NVIC->IP[(uint32_t)(IRQn)] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff);    }        /* set Priority for device specific Interrupts  */
}


/** \brief  Get Interrupt Priority

    This function reads the priority for the specified interrupt. The interrupt 
    number can be positive to specify an external (device specific) 
    interrupt, or negative to specify an internal (core) interrupt.

    The returned priority value is automatically aligned to the implemented
    priority bits of the microcontroller.

    \param [in]   IRQn  Number of the interrupt for get priority
    \return             Interrupt Priority
 */
static __INLINE uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - __NVIC_PRIO_BITS)));  } /* get priority for Cortex-M  system interrupts */
  else {
    return((uint32_t)(NVIC->IP[(uint32_t)(IRQn)]           >> (8 - __NVIC_PRIO_BITS)));  } /* get priority for device specific interrupts  */
}


/** \brief  System Reset

    This function initiate a system reset request to reset the MCU.
 */
static __INLINE void NVIC_SystemReset(void)
{
  __DSB();                                                     /* Ensure all outstanding memory accesses included
                                                                  buffered write are completed before reset */              
  SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      | 
                 (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) | 
                 SCB_AIRCR_SYSRESETREQ_Msk);                   /* Keep priority group unchanged */
  __DSB();                                                     /* Ensure completion of memory access */              
  while(1);                                                    /* wait until reset */
}










/*******************************************************************************
 *                 		SYSTICK functions
 ******************************************************************************/

/** \brief  System Tick Configuration

    This function initialises the system tick timer and its interrupt and start the system tick timer.
    Counter is in free running mode to generate periodical interrupts.

    \param [in]  ticks  Number of ticks between two interrupts
    \return          0  Function succeeded
    \return          1  Function failed
 */
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
                                                               
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
