/* ########################## DMA — lpc17xx_gpdma.h ########################## */

/* Structures ----------------------------------------------------------------- */

/**
 * @brief GPDMA Channel configuration structure type definition
 */
typedef struct {
	uint32_t ChannelNum; 	/**< DMA channel number, should be in
								range from 0 to 7.
								Note: DMA channel 0 has the highest priority
								and DMA channel 7 the lowest priority.
								*/
	uint32_t TransferSize;	/**< Length/Size of transfer */
	uint32_t TransferWidth;	/**< Transfer width - used for TransferType is GPDMA_TRANSFERTYPE_M2M only */
	uint32_t SrcMemAddr;	/**< Physical Source Address, used in case TransferType is chosen as
								 GPDMA_TRANSFERTYPE_M2M or GPDMA_TRANSFERTYPE_M2P */
	uint32_t DstMemAddr;	/**< Physical Destination Address, used in case TransferType is chosen as
								 GPDMA_TRANSFERTYPE_M2M or GPDMA_TRANSFERTYPE_P2M */
	uint32_t TransferType;	/**< Transfer Type, should be one of the following:
							- GPDMA_TRANSFERTYPE_M2M: Memory to memory - DMA control
							- GPDMA_TRANSFERTYPE_M2P: Memory to peripheral - DMA control
							- GPDMA_TRANSFERTYPE_P2M: Peripheral to memory - DMA control
							- GPDMA_TRANSFERTYPE_P2P: Source peripheral to destination peripheral - DMA control
							*/
	uint32_t SrcConn;		/**< Peripheral Source Connection type, used in case TransferType is chosen as
							GPDMA_TRANSFERTYPE_P2M or GPDMA_TRANSFERTYPE_P2P, should be one of
							following:
							 - GPDMA_CONN_SSP0_Tx: SSP0, Tx
							 - GPDMA_CONN_SSP0_Rx: SSP0, Rx
							 - GPDMA_CONN_SSP1_Tx: SSP1, Tx
							 - GPDMA_CONN_SSP1_Rx: SSP1, Rx
							 - GPDMA_CONN_ADC: ADC
							 - GPDMA_CONN_I2S_Channel_0: I2S Channel 0
							 - GPDMA_CONN_I2S_Channel_1: I2S Channel 1
							 - GPDMA_CONN_DAC: DAC
							 - GPDMA_CONN_UART0_Tx_MAT0_0: UART0 Tx / MAT0.0
							 - GPDMA_CONN_UART0_Rx_MAT0_1: UART0 Rx / MAT0.1
							 - GPDMA_CONN_UART1_Tx_MAT1_0: UART1 Tx / MAT1.0
							 - GPDMA_CONN_UART1_Rx_MAT1_1: UART1 Rx / MAT1.1
							 - GPDMA_CONN_UART2_Tx_MAT2_0: UART2 Tx / MAT2.0
							 - GPDMA_CONN_UART2_Rx_MAT2_1: UART2 Rx / MAT2.1
							 - GPDMA_CONN_UART3_Tx_MAT3_0: UART3 Tx / MAT3.0
							 - GPDMA_CONN_UART3_Rx_MAT3_1: UART3 Rx / MAT3.1
							 */
	uint32_t DstConn;		/**< Peripheral Destination Connection type, used in case TransferType is chosen as
							GPDMA_TRANSFERTYPE_M2P or GPDMA_TRANSFERTYPE_P2P, should be one of
							following:
							 - GPDMA_CONN_SSP0_Tx: SSP0, Tx
							 - GPDMA_CONN_SSP0_Rx: SSP0, Rx
							 - GPDMA_CONN_SSP1_Tx: SSP1, Tx
							 - GPDMA_CONN_SSP1_Rx: SSP1, Rx
							 - GPDMA_CONN_ADC: ADC
							 - GPDMA_CONN_I2S_Channel_0: I2S Channel 0
							 - GPDMA_CONN_I2S_Channel_1: I2S Channel 1
							 - GPDMA_CONN_DAC: DAC
							 - GPDMA_CONN_UART0_Tx_MAT0_0: UART0 Tx / MAT0.0
							 - GPDMA_CONN_UART0_Rx_MAT0_1: UART0 Rx / MAT0.1
							 - GPDMA_CONN_UART1_Tx_MAT1_0: UART1 Tx / MAT1.0
							 - GPDMA_CONN_UART1_Rx_MAT1_1: UART1 Rx / MAT1.1
							 - GPDMA_CONN_UART2_Tx_MAT2_0: UART2 Tx / MAT2.0
							 - GPDMA_CONN_UART2_Rx_MAT2_1: UART2 Rx / MAT2.1
							 - GPDMA_CONN_UART3_Tx_MAT3_0: UART3 Tx / MAT3.0
							 - GPDMA_CONN_UART3_Rx_MAT3_1: UART3 Rx / MAT3.1
							 */
	uint32_t DMALLI;		/**< Linker List Item structure data address
							if there's no Linker List, set as '0'
							*/
} GPDMA_Channel_CFG_Type;

/**
 * @brief GPDMA Linker List Item structure type definition
 */
typedef struct {
	uint32_t SrcAddr;	/**< Source Address */
	uint32_t DstAddr;	/**< Destination address */
	uint32_t NextLLI;	/**< Next LLI address, otherwise set to '0' */
	uint32_t Control;	/**< GPDMA Control of this LLI */
} GPDMA_LLI_Type;

/* Public Functions ----------------------------------------------------------- */

/********************************************************************//**
 * @brief 		Initialize GPDMA controller
 * @param 		None
 * @return 		None
 *********************************************************************/
void GPDMA_Init(void);

/********************************************************************//**
 * @brief 		Setup GPDMA channel peripheral according to the specified
 *               parameters in the GPDMAChannelConfig.
 * @param[in]	GPDMAChannelConfig Pointer to a GPDMA_CH_CFG_Type
 * @return		ERROR if selected channel is enabled before
 * 				or SUCCESS if channel is configured successfully
 *********************************************************************/
Status GPDMA_Setup(GPDMA_Channel_CFG_Type *GPDMAChannelConfig);

/*********************************************************************//**
 * @brief		Enable/Disable DMA channel
 * @param[in]	channelNum	GPDMA channel, should be in range from 0 to 7
 * @param[in]	NewState	New State of this command, should be:
 * 					- ENABLE.
 * 					- DISABLE.
 * @return		None
 **********************************************************************/
void GPDMA_ChannelCmd(uint8_t channelNum, FunctionalState NewState);

/*********************************************************************//**
 * @brief		Check if corresponding channel does have an active interrupt
 * 				request or not
 * @param[in]	type		type of status, should be:
 * 					- GPDMA_STAT_INT: 		GPDMA Interrupt Status
 * 					- GPDMA_STAT_INTTC: 	GPDMA Interrupt Terminal Count Request Status
 * 					- GPDMA_STAT_INTERR:	GPDMA Interrupt Error Status
 * 					- GPDMA_STAT_RAWINTTC:	GPDMA Raw Interrupt Terminal Count Status
 * 					- GPDMA_STAT_RAWINTERR:	GPDMA Raw Error Interrupt Status
 * 					- GPDMA_STAT_ENABLED_CH:GPDMA Enabled Channel Status
 * @param[in]	channel		GPDMA channel, should be in range from 0 to 7
 * @return		IntStatus	status of DMA channel interrupt after masking
 * 				Should be:
 * 					- SET: the corresponding channel has no active interrupt request
 * 					- RESET: the corresponding channel does have an active interrupt request
 **********************************************************************/
IntStatus GPDMA_IntGetStatus(GPDMA_Status_Type type, uint8_t channel);

/*********************************************************************//**
 * @brief		Clear one or more interrupt requests on DMA channels
 * @param[in]	type		type of interrupt request, should be:
 * 					- GPDMA_STATCLR_INTTC: 	GPDMA Interrupt Terminal Count Request Clear
 * 					- GPDMA_STATCLR_INTERR: GPDMA Interrupt Error Clear
 * @param[in]	channel		GPDMA channel, should be in range from 0 to 7
 * @return		None
 **********************************************************************/
void GPDMA_ClearIntPending(GPDMA_StateClear_Type type, uint8_t channel);

