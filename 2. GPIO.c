/* ########################## GPIO — lpc17xx_gpio.h ########################## */

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief        Set Direction for GPIO port.
 * @param[in]    portNum        Port Number value, should be in range from 0 to 4
 * @param[in]    bitValue    Value that contains all bits to set direction,
 *                             in range from 0 to 0xFFFFFFFF.
 *                             example: value 0x5 to set direction for bit 0 and bit 1.
 * @param[in]    dir            Direction value, should be:
 *                             - 0: Input.
 *                             - 1: Output.
 * @return        None
 **********************************************************************/
void GPIO_SetDir(uint8_t portNum, uint32_t bitValue, uint8_t dir);


/*********************************************************************//**
 * @brief        Set Value for bits that have output direction on GPIO port.
 * @param[in]    portNum        Port number value, should be in range from 0 to 4
 * @param[in]    bitValue    Value that contains all bits on GPIO to set,
 *                             in range from 0 to 0xFFFFFFFF.
 *                             example: value 0x5 to set bit 0 and bit 1.
 * @return        None
 **********************************************************************/
void GPIO_SetValue(uint8_t portNum, uint32_t bitValue);

/*********************************************************************//**
 * @brief        Clear Value for bits that have output direction on GPIO port.
 * @param[in]    portNum        Port number value, should be in range from 0 to 4
 * @param[in]    bitValue    Value that contains all bits on GPIO to clear,
 *                             in range from 0 to 0xFFFFFFFF.
 *                             example: value 0x5 to clear bit 0 and bit 1.
 * @return        None
 **********************************************************************/

void GPIO_ClearValue(uint8_t portNum, uint32_t bitValue);

/*********************************************************************//**
 * @brief        Read Current state on port pin that have input direction of GPIO
 * @param[in]    portNum        Port number to read value, in range from 0 to 4
 * @return        Current value of GPIO port.
 **********************************************************************/
uint32_t GPIO_ReadValue(uint8_t portNum);

/*********************************************************************//**
 * @brief        Enable GPIO interrupt (just used for P0.0-P0.30, P2.0-P2.13)
 * @param[in]    portNum        Port number to read value, should be: 0 or 2
 * @param[in]    bitValue    Value that contains all bits on GPIO to enable,
 *                             in range from 0 to 0xFFFFFFFF.
 * @param[in]    edgeState    state of edge, should be:
 *                             - 0: Rising edge
 *                             - 1: Falling edge
 * @return        None
 **********************************************************************/
void GPIO_IntCmd(uint8_t portNum, uint32_t bitValue, uint8_t edgeState);

/*********************************************************************//**
 * @brief        Get GPIO Interrupt Status (just used for P0.0-P0.30, P2.0-P2.13)
 * @param[in]    portNum        Port number to read value, should be: 0 or 2
 * @param[in]    pinNum        Pin number, should be: 0..30(with port 0) and 0..13
 *                             (with port 2)
 * @param[in]    edgeState    state of edge, should be:
 *                             - 0: Rising edge
 *                             - 1: Falling edge
 * @return        Bool    could be:
 *                         - ENABLE: Interrupt has been generated due to a rising
 *                                 edge on P0.0
 *                         - DISABLE: A rising edge has not been detected on P0.0
 **********************************************************************/
FunctionalState GPIO_GetIntStatus(uint8_t portNum, uint32_t pinNum, uint8_t edgeState);

/*********************************************************************//**
 * @brief        Clear GPIO interrupt (just used for P0.0-P0.30, P2.0-P2.13)
 * @param[in]    portNum        Port number to read value, should be: 0 or 2
 * @param[in]    bitValue    Value that contains all bits on GPIO to enable,
 *                             in range from 0 to 0xFFFFFFFF.
 * @return        None
 **********************************************************************/
void GPIO_ClearInt(uint8_t portNum, uint32_t bitValue);
