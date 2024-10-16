
/* ########################## NVIC — lpc17xx_nvic.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*****************************************************************************//**
 * @brief		Enable External Interrupt
 * @param		IRQn  Number of the external interrupt to enable
 * @return      None
 *
 *  This function enables a device specific interupt in the NVIC interrupt controller.
 *  The interrupt number cannot be a negative value. 
 *******************************************************************************/
static __INLINE void NVIC_EnableIRQ(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Disable External Interrupt
 * @param		IRQn  Number of the external interrupt to disable
 * @return      None
 *
 *  This function disables a device specific interupt in the NVIC interrupt controller.
 *  The interrupt number cannot be a negative value. 
 *******************************************************************************/
static __INLINE void NVIC_DisableIRQ(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Get Pending Interrupt
 * @param		IRQn  Number of the interrupt for get pending
 * @return      0  Interrupt status is not pending
 * @return      1  Interrupt status is pending
 *
 *  This function reads the pending register in the NVIC and returns the pending bit
 *  for the specified interrupt. 
 *******************************************************************************/
static __INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Set Pending Interrupt
 * @param		IRQn  Number of the interrupt for set pending
 * @return      none
 *
 *  This function sets the pending bit for the specified interrupt. 
    The interrupt number cannot be a negative value.
 *******************************************************************************/
static __INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Clear Pending Interrupt
 * @param		IRQn  Number of the interrupt for clear pending
 * @return      none
 * 
 *  This function clears the pending bit for the specified interrupt. 
 *  The interrupt number cannot be a negative value.
 *******************************************************************************/
static __INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Get Active Interrupt
 * @param		IRQn  Number of the interrupt for get active
 * @return      0  Interrupt status is not active
 * @return      1  Interrupt status is active
 *
 *  This function reads the active register in NVIC and returns the active bit. 
 *******************************************************************************/
static __INLINE uint32_t NVIC_GetActive(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		Set Interrupt Priority
 * @param		IRQn  Number of the interrupt for set priority
 * @param		priority  Priority to set
 *
 *  This function sets the priority for the specified interrupt. The interrupt 
 *  number can be positive to specify an external (device specific) 
 *  interrupt, or negative to specify an internal (core) interrupt.
 *
 *  Note: The priority cannot be set for every core interrupt.
 *******************************************************************************/
static __INLINE void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);

/*****************************************************************************//**
 * @brief		Get Interrupt Priority
 * @param		IRQn  Number of the interrupt for get priority
 * @return      Interrupt Priority
 * 
 * This function reads the priority for the specified interrupt. The interrupt 
 * number can be positive to specify an external (device specific) 
 * interrupt, or negative to specify an internal (core) interrupt.
 *
 * The returned priority value is automatically aligned to the implemented
 * priority bits of the microcontroller.
 *******************************************************************************/
static __INLINE uint32_t NVIC_GetPriority(IRQn_Type IRQn);

/*****************************************************************************//**
 * @brief		De-initializes the NVIC peripheral registers to their default
 * 				reset values.
 * @param		None
 * @return      None
 *
 * These following NVIC peripheral registers will be de-initialized:
 * - Disable Interrupt (32 IRQ interrupt sources that matched with LPC17xx)
 * - Clear all Pending Interrupts (32 IRQ interrupt source that matched with LPC17xx)
 * - Clear all Interrupt Priorities (32 IRQ interrupt source that matched with LPC17xx)
 *******************************************************************************/
void NVIC_DeInit(void);