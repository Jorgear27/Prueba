/* ########################## DAC — lpc17xx_dac.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief 		Initial ADC configuration
 * 					- Maximum	current is 700 uA
 * 					- Value to AOUT is 0
 * @param[in] 	DACx pointer to LPC_DAC_TypeDef, should be: LPC_DAC
 * @return 		None
 ***********************************************************************/
void DAC_Init(LPC_DAC_TypeDef *DACx);

/*********************************************************************//**
 * @brief 		Update value to DAC
 * @param[in] 	DACx pointer to LPC_DAC_TypeDef, should be: LPC_DAC
 * @param[in] 	dac_value : value 10 bit to be converted to output
 * @return 		None
 ***********************************************************************/
void DAC_UpdateValue (LPC_DAC_TypeDef *DACx,uint32_t dac_value);

/*********************************************************************//**
 * @brief 		Set Maximum current for DAC
 * @param[in] 	DACx pointer to LPC_DAC_TypeDef, should be: LPC_DAC
 * @param[in] 	bias : 0 is 700 uA
 * 					   1    350 uA
 * @return 		None
 ***********************************************************************/
void DAC_SetBias (LPC_DAC_TypeDef *DACx,uint32_t bias);

/*********************************************************************//**
 * @brief 		To enable the DMA operation and control DMA timer
 * @param[in]	DACx pointer to LPC_DAC_TypeDef, should be: LPC_DAC
 * @param[in] 	DAC_ConverterConfigStruct pointer to DAC_CONVERTER_CFG_Type
 * 					- DBLBUF_ENA :  enable/disable DACR double buffering feature
 * 					- CNT_ENA    :  enable/disable timer out counter
 * 					- DMA_ENA    :	enable/disable DMA access
 * @return 		None
 ***********************************************************************/
void DAC_ConfigDAConverterControl (LPC_DAC_TypeDef *DACx,DAC_CONVERTER_CFG_Type *DAC_ConverterConfigStruct);

/*********************************************************************//**
 * @brief 		Set reload value for interrupt/DMA counter
 * @param[in] 	DACx pointer to LPC_DAC_TypeDef, should be: LPC_DAC
 * @param[in] 	time_out time out to reload for interrupt/DMA counter
 * @return 		None
 ***********************************************************************/
void DAC_SetDMATimeOut(LPC_DAC_TypeDef *DACx, uint32_t time_out);