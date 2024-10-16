/* ########################## ADC — lpc17xx_adc.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief         Initial for ADC
 *                     + Set bit PCADC
 *                     + Set clock for ADC
 *                     + Set Clock Frequency
 * @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
 * @param[in]    rate ADC conversion rate, should be <=200KHz
 * @return         None
 **********************************************************************/
void ADC_Init(LPC_ADC_TypeDef *ADCx, uint32_t rate);

/*********************************************************************//**
* @brief         Close ADC
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @return         None
**********************************************************************/
void ADC_DeInit(LPC_ADC_TypeDef *ADCx);

/*********************************************************************//**
* @brief         Get Result conversion from A/D data register
* @param[in]    channel number which want to read back the result
* @return         Result of conversion
*********************************************************************/
uint32_t ADC_GetData(uint32_t channel);

/*********************************************************************//**
* @brief         Set start mode for ADC
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    start_mode Start mode choose one of modes in
*                 'ADC_START_OPT' enumeration type definition, should be:
*                 - ADC_START_CONTINUOUS
*                 - ADC_START_NOW
*                 - ADC_START_ON_EINT0
*                 - ADC_START_ON_CAP01
*                - ADC_START_ON_MAT01
*                - ADC_START_ON_MAT03
*                - ADC_START_ON_MAT10
*                - ADC_START_ON_MAT11
* @return         None
*********************************************************************/
void ADC_StartCmd(LPC_ADC_TypeDef *ADCx, uint8_t start_mode);


/*********************************************************************//**
* @brief         ADC Burst mode setting
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    NewState
*                 -    1: Set Burst mode
*                 -    0: reset Burst mode
* @return         None
**********************************************************************/
void ADC_BurstCmd(LPC_ADC_TypeDef *ADCx, FunctionalState NewState);

/*********************************************************************//**
* @brief         Set AD conversion in power mode
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    NewState
*                 -    1: AD converter is optional
*                 -    0: AD Converter is in power down mode
* @return         None
**********************************************************************/
void ADC_PowerdownCmd(LPC_ADC_TypeDef *ADCx, FunctionalState NewState);

/*********************************************************************//**
* @brief         Set Edge start configuration
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    EdgeOption is ADC_START_ON_RISING and ADC_START_ON_FALLING
*                     0:ADC_START_ON_RISING
*                     1:ADC_START_ON_FALLING
* @return         None
**********************************************************************/
void ADC_EdgeStartConfig(LPC_ADC_TypeDef *ADCx, uint8_t EdgeOption);

/*********************************************************************//**
* @brief         ADC interrupt configuration
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    IntType: type of interrupt, should be:
*                 - ADC_ADINTEN0: Interrupt channel 0
*                 - ADC_ADINTEN1: Interrupt channel 1
*                 ...
*                 - ADC_ADINTEN7: Interrupt channel 7
*                 - ADC_ADGINTEN: Individual channel/global flag done generate an interrupt
* @param[in]    NewState:
*                     - SET : enable ADC interrupt
*                     - RESET: disable ADC interrupt
* @return         None
**********************************************************************/
void ADC_IntConfig (LPC_ADC_TypeDef *ADCx, ADC_TYPE_INT_OPT IntType, FunctionalState NewState);

/*********************************************************************//**
* @brief         Enable/Disable ADC channel number
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    Channel channel number
* @param[in]    NewState Enable or Disable
*
* @return         None
**********************************************************************/
void ADC_ChannelCmd (LPC_ADC_TypeDef *ADCx, uint8_t Channel, FunctionalState NewState);

/*********************************************************************//**
* @brief         Get ADC result
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    channel: channel number, should be 0...7
* @return         Data conversion
**********************************************************************/
uint16_t ADC_ChannelGetData(LPC_ADC_TypeDef *ADCx, uint8_t channel);

/*********************************************************************//**
* @brief         Get ADC Chanel status from ADC data register
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]    channel: channel number, should be 0..7
* @param[in]      StatusType
*                           0:Burst status
*                       1:Done     status
* @return         SET / RESET
**********************************************************************/
FlagStatus ADC_ChannelGetStatus(LPC_ADC_TypeDef *ADCx, uint8_t channel, uint32_t StatusType);

/*********************************************************************//**
* @brief         Get ADC Data from AD Global register
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @return         Result of conversion
**********************************************************************/
uint32_t ADC_GlobalGetData(LPC_ADC_TypeDef *ADCx);

/*********************************************************************//**
* @brief         Get ADC Chanel status from AD global data register
* @param[in]    ADCx pointer to LPC_ADC_TypeDef, should be: LPC_ADC
* @param[in]      StatusType
*                           0:Burst status
*                       1:Done     status
* @return         SET / RESET
**********************************************************************/
FlagStatus    ADC_GlobalGetStatus(LPC_ADC_TypeDef *ADCx, uint32_t StatusType);