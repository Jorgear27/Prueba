/* ########################## TIMER — lpc17xx_timer.h ########################## */

/* Structures ----------------------------------------------------------------- */

/** @brief Configuration structure in TIMER mode */
typedef struct
{

	uint8_t PrescaleOption;		/**< Timer Prescale option, should be:
									- TIM_PRESCALE_TICKVAL: Prescale in absolute value
									- TIM_PRESCALE_USVAL: Prescale in microsecond value
									*/
	uint32_t PrescaleValue;		/**< Prescale value */
} TIM_TIMERCFG_Type;

/** @brief Configuration structure in COUNTER mode */
typedef struct {

	uint8_t CounterOption;		/**< Counter Option, should be:
								- TIM_COUNTER_INCAP0: CAPn.0 input pin for TIMERn
								- TIM_COUNTER_INCAP1: CAPn.1 input pin for TIMERn
								*/
	uint8_t CountInputSelect;
	uint8_t Reserved[2];
} TIM_COUNTERCFG_Type;

/** @brief Match channel configuration structure */
typedef struct {
	uint8_t MatchChannel;	/**< Match channel, should be in range
							from 0..3 */
	uint8_t IntOnMatch;		/**< Interrupt On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/
	uint8_t StopOnMatch;	/**< Stop On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/
	uint8_t ResetOnMatch;	/**< Reset On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/

	uint8_t ExtMatchOutputType;	/**< External Match Output type, should be:
							 -	 TIM_EXTMATCH_NOTHING:	Do nothing for external output pin if match
							 -   TIM_EXTMATCH_LOW:	Force external output pin to low if match
							 - 	 TIM_EXTMATCH_HIGH: Force external output pin to high if match
							 -   TIM_EXTMATCH_TOGGLE: Toggle external output pin if match.
							*/
	uint8_t Reserved[3];	/** Reserved */
	uint32_t MatchValue;	/** Match value */
} TIM_MATCHCFG_Type;

/** @brief Capture Input configuration structure */
typedef struct {
	uint8_t CaptureChannel;	/**< Capture channel, should be in range
							from 0..1 */
	uint8_t RisingEdge;		/**< caption rising edge, should be:
							- ENABLE: Enable rising edge.
							- DISABLE: Disable this function.
							*/
	uint8_t FallingEdge;		/**< caption falling edge, should be:
							- ENABLE: Enable falling edge.
							- DISABLE: Disable this function.
								*/
	uint8_t IntOnCaption;	/**< Interrupt On caption, should be:
							- ENABLE: Enable interrupt function.
							- DISABLE: Disable this function.
							*/

} TIM_CAPTURECFG_Type;

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief         Get Interrupt Status
 * @param[in]    TIMx Timer selection, should be:
 *               - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    IntFlag: interrupt type, should be:
 *                 - TIM_MR0_INT: Interrupt for Match channel 0
 *                 - TIM_MR1_INT: Interrupt for Match channel 1
 *                 - TIM_MR2_INT: Interrupt for Match channel 2
 *                 - TIM_MR3_INT: Interrupt for Match channel 3
 *                 - TIM_CR0_INT: Interrupt for Capture channel 0
 *                 - TIM_CR1_INT: Interrupt for Capture channel 1
 * @return         FlagStatus
 *                 - SET : interrupt
 *                 - RESET : no interrupt
 **********************************************************************/
FlagStatus TIM_GetIntStatus(LPC_TIM_TypeDef *TIMx, TIM_INT_TYPE IntFlag);

/*********************************************************************//**
 * @brief         Get Capture Interrupt Status
 * @param[in]    TIMx Timer selection, should be:
 *                 - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    IntFlag: interrupt type, should be:
 *                 - TIM_MR0_INT: Interrupt for Match channel 0
 *                 - TIM_MR1_INT: Interrupt for Match channel 1
 *                 - TIM_MR2_INT: Interrupt for Match channel 2
 *                 - TIM_MR3_INT: Interrupt for Match channel 3
 *                 - TIM_CR0_INT: Interrupt for Capture channel 0
 *                 - TIM_CR1_INT: Interrupt for Capture channel 1
 * @return         FlagStatus
 *                 - SET : interrupt
 *                 - RESET : no interrupt
 **********************************************************************/
FlagStatus TIM_GetIntCaptureStatus(LPC_TIM_TypeDef *TIMx, TIM_INT_TYPE IntFlag);

/*********************************************************************//**
 * @brief         Clear Interrupt pending
 * @param[in]    TIMx Timer selection, should be:
 *                - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    IntFlag: interrupt type, should be:
 *                 - TIM_MR0_INT: Interrupt for Match channel 0
 *                 - TIM_MR1_INT: Interrupt for Match channel 1
 *                 - TIM_MR2_INT: Interrupt for Match channel 2
 *                 - TIM_MR3_INT: Interrupt for Match channel 3
 *                 - TIM_CR0_INT: Interrupt for Capture channel 0
 *                 - TIM_CR1_INT: Interrupt for Capture channel 1
 * @return         None
 **********************************************************************/
void TIM_ClearIntPending(LPC_TIM_TypeDef *TIMx, TIM_INT_TYPE IntFlag)
{
    CHECK_PARAM(PARAM_TIMx(TIMx));
    CHECK_PARAM(PARAM_TIM_INT_TYPE(IntFlag));
    TIMx->IR |= TIM_IR_CLR(IntFlag);
}

/*********************************************************************//**
 * @brief         Clear Capture Interrupt pending
 * @param[in]    TIMx Timer selection, should be
 *                - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    IntFlag interrupt type, should be:
 *                - TIM_MR0_INT: Interrupt for Match channel 0
 *                 - TIM_MR1_INT: Interrupt for Match channel 1
 *                 - TIM_MR2_INT: Interrupt for Match channel 2
 *                 - TIM_MR3_INT: Interrupt for Match channel 3
 *                 - TIM_CR0_INT: Interrupt for Capture channel 0
 *                 - TIM_CR1_INT: Interrupt for Capture channel 1
 * @return         None
 **********************************************************************/
void TIM_ClearIntCapturePending(LPC_TIM_TypeDef *TIMx, TIM_INT_TYPE IntFlag);

/*********************************************************************//**
 * @brief         Configuration for Timer at initial time
 * @param[in]     TimerCounterMode timer counter mode, should be:
 *                 - TIM_TIMER_MODE: Timer mode
 *                 - TIM_COUNTER_RISING_MODE: Counter rising mode
 *                 - TIM_COUNTER_FALLING_MODE: Counter falling mode
 *                 - TIM_COUNTER_ANY_MODE:Counter on both edges
 * @param[in]     TIM_ConfigStruct pointer to TIM_TIMERCFG_Type or
 *                 TIM_COUNTERCFG_Type
 * @return         None
 **********************************************************************/
void TIM_ConfigStructInit(TIM_MODE_OPT TimerCounterMode, void *TIM_ConfigStruct);

/*********************************************************************//**
 * @brief         Initial Timer/Counter device
 *                      Set Clock frequency for Timer
 *                     Set initial configuration for Timer
 * @param[in]    TIMx  Timer selection, should be:
 *                 - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    TimerCounterMode Timer counter mode, should be:
 *                 - TIM_TIMER_MODE: Timer mode
 *                 - TIM_COUNTER_RISING_MODE: Counter rising mode
 *                 - TIM_COUNTER_FALLING_MODE: Counter falling mode
 *                 - TIM_COUNTER_ANY_MODE:Counter on both edges
 * @param[in]    TIM_ConfigStruct pointer to TIM_TIMERCFG_Type
 *                 that contains the configuration information for the
 *                    specified Timer peripheral.
 * @return         None
 **********************************************************************/
void TIM_Init(LPC_TIM_TypeDef *TIMx, TIM_MODE_OPT TimerCounterMode, void *TIM_ConfigStruct);

/*********************************************************************//**
 * @brief         Close Timer/Counter device
 * @param[in]    TIMx  Pointer to timer device, should be:
 *                 - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @return         None
 **********************************************************************/
void TIM_DeInit (LPC_TIM_TypeDef *TIMx);

/*********************************************************************//**
 * @brief         Start/Stop Timer/Counter device
 * @param[in]    TIMx Pointer to timer device, should be:
 *              - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    NewState
 *                 -    ENABLE  : set timer enable
 *                 -    DISABLE : disable timer
 * @return         None
 **********************************************************************/
void TIM_Cmd(LPC_TIM_TypeDef *TIMx, FunctionalState NewState);

/*********************************************************************//**
 * @brief         Reset Timer/Counter device,
 *                     Make TC and PC are synchronously reset on the next
 *                     positive edge of PCLK
 * @param[in]    TIMx Pointer to timer device, should be:
 *               - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @return         None
 **********************************************************************/
void TIM_ResetCounter(LPC_TIM_TypeDef *TIMx);

/*********************************************************************//**
 * @brief         Configuration for Match register
 * @param[in]    TIMx Pointer to timer device, should be:
 *               - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]   TIM_MatchConfigStruct Pointer to TIM_MATCHCFG_Type
 * @return         None
 **********************************************************************/
void TIM_ConfigMatch(LPC_TIM_TypeDef *TIMx, TIM_MATCHCFG_Type *TIM_MatchConfigStruct);

/*********************************************************************//**
 * @brief         Update Match value
 * @param[in]    TIMx Pointer to timer device, should be:
 *               - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    MatchChannel    Match channel, should be: 0..3
 * @param[in]    MatchValue        updated match value
 * @return         None
 **********************************************************************/
void TIM_UpdateMatchValue(LPC_TIM_TypeDef *TIMx,uint8_t MatchChannel, uint32_t MatchValue);

/*********************************************************************//**
 * @brief         Configuration for Capture register
 * @param[in]    TIMx Pointer to timer device, should be:
 *               - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 *                     - CaptureChannel: set the channel to capture data
 *                     - RisingEdge    : if SET, Capture at rising edge
 *                     - FallingEdge    : if SET, Capture at falling edge
 *                     - IntOnCaption  : if SET, Capture generate interrupt
 * @param[in]   TIM_CaptureConfigStruct    Pointer to TIM_CAPTURECFG_Type
 * @return         None
 **********************************************************************/
void TIM_ConfigCapture(LPC_TIM_TypeDef *TIMx, TIM_CAPTURECFG_Type *TIM_CaptureConfigStruct);

/*********************************************************************//**
 * @brief         Read value of capture register in timer/counter device
 * @param[in]    TIMx Pointer to timer/counter device, should be:
 *              - LPC_TIM0: TIMER0 peripheral
 *                 - LPC_TIM1: TIMER1 peripheral
 *                 - LPC_TIM2: TIMER2 peripheral
 *                 - LPC_TIM3: TIMER3 peripheral
 * @param[in]    CaptureChannel: capture channel number, should be:
 *                 - TIM_COUNTER_INCAP0: CAPn.0 input pin for TIMERn
 *                 - TIM_COUNTER_INCAP1: CAPn.1 input pin for TIMERn
 * @return         Value of capture register
 **********************************************************************/
uint32_t TIM_GetCaptureValue(LPC_TIM_TypeDef *TIMx, TIM_COUNTER_INPUT_OPT CaptureChannel);