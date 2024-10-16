/* ########################## EINT — lpc17xx_exti.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief 		Configuration for EXT
 * 				- Set EXTINT, EXTMODE, EXTPOLAR register
 * @param[in]	EXTICfg	Pointer to a EXTI_InitTypeDef structure
 *              that contains the configuration information for the
 *              specified external interrupt
 * @return 		None
 **********************************************************************/
void EXTI_Config(EXTI_InitTypeDef *EXTICfg);

/*********************************************************************//**
* @brief 		Set mode for EXTI pin
* @param[in]	EXTILine	 external interrupt line, should be:
* 				- EXTI_EINT0: external interrupt line 0
* 				- EXTI_EINT1: external interrupt line 1
* 				- EXTI_EINT2: external interrupt line 2
* 				- EXTI_EINT3: external interrupt line 3
* @param[in]	mode 	external mode, should be:
* 				- EXTI_MODE_LEVEL_SENSITIVE
* 				- EXTI_MODE_EDGE_SENSITIVE
* @return 		None
*********************************************************************/
void EXTI_SetMode(EXTI_LINE_ENUM EXTILine, EXTI_MODE_ENUM mode);

/*********************************************************************//**
* @brief 		Set polarity for EXTI pin
* @param[in]	EXTILine	 external interrupt line, should be:
* 				- EXTI_EINT0: external interrupt line 0
* 				- EXTI_EINT1: external interrupt line 1
* 				- EXTI_EINT2: external interrupt line 2
* 				- EXTI_EINT3: external interrupt line 3
* @param[in]	polarity	 external polarity value, should be:
* 				- EXTI_POLARITY_LOW_ACTIVE_OR_FALLING_EDGE
* 				- EXTI_POLARITY_LOW_ACTIVE_OR_FALLING_EDGE
* @return 		None
*********************************************************************/
void EXTI_SetPolarity(EXTI_LINE_ENUM EXTILine, EXTI_POLARITY_ENUM polarity);

/*********************************************************************//**
* @brief 		Clear External interrupt flag
* @param[in]	EXTILine	 external interrupt line, should be:
* 				- EXTI_EINT0: external interrupt line 0
* 				- EXTI_EINT1: external interrupt line 1
* 				- EXTI_EINT2: external interrupt line 2
* 				- EXTI_EINT3: external interrupt line 3
* @return 		None
*********************************************************************/
void EXTI_ClearEXTIFlag(EXTI_LINE_ENUM EXTILine);