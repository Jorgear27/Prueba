/* ########################## SysTick — lpc17xx_systick.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief 		This function initialises the system tick timer and its interrupt 
                 and start the system tick timer.
                Counter is in free running mode to generate periodical interrupts.
 * @param[in]	ticks  Number of ticks between two interrupts
 * @return 		    0  Function succeeded
 * @return          1  Function failed
 **********************************************************************/
static __INLINE uint32_t SysTick_Config(uint32_t ticks);

/*********************************************************************//**
 * @brief 		Initial System Tick with using internal CPU clock source
 * @param[in]	time	time interval(ms)
 * @return 		None
 **********************************************************************/
void SYSTICK_InternalInit(uint32_t time);

/*********************************************************************//**
 * @brief 		Initial System Tick with using external clock source
 * @param[in]	freq	external clock frequency(Hz)
 * @param[in]	time	time interval(ms)
 * @return 		None
 **********************************************************************/
void SYSTICK_ExternalInit(uint32_t freq, uint32_t time);

/*********************************************************************//**
 * @brief 		Enable/disable System Tick counter
 * @param[in]	NewState	System Tick counter status, should be:
 * 					- ENABLE
 * 					- DISABLE
 * @return 		None
 **********************************************************************/
void SYSTICK_Cmd(FunctionalState NewState);

/*********************************************************************//**
 * @brief 		Enable/disable System Tick interrupt
 * @param[in]	NewState	System Tick interrupt status, should be:
 * 					- ENABLE
 * 					- DISABLE
 * @return 		None
 **********************************************************************/
void SYSTICK_IntCmd(FunctionalState NewState);

/*********************************************************************//**
 * @brief 		Get current value of System Tick counter
 * @param[in]	None
 * @return 		current value of System Tick counter
 **********************************************************************/
uint32_t SYSTICK_GetCurrentValue(void);

/*********************************************************************//**
 * @brief 		Clear Counter flag
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void SYSTICK_ClearCounterFlag(void);
