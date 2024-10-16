/* ########################## PINSEL — lpc17xx_pinsel.h ########################## */

/* Structures ----------------------------------------------------------------- */

/** @brief Pin configuration structure */
typedef struct
{
    uint8_t Portnum;    /**< Port Number, should be PINSEL_PORT_x,
                        where x should be in range from 0 to 4 */
    uint8_t Pinnum;        /**< Pin Number, should be PINSEL_PIN_x,
                        where x should be in range from 0 to 31 */
    uint8_t Funcnum;    /**< Function Number, should be PINSEL_FUNC_x,
                        where x should be in range from 0 to 3 */
    uint8_t Pinmode;    /**< Pin Mode, should be:
                        - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
                        - PINSEL_PINMODE_TRISTATE: Tri-state
                        - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor */
    uint8_t OpenDrain;    /**< OpenDrain mode, should be:
                        - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
                        - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode */
} PINSEL_CFG_Type;

/* Public Functions ----------------------------------------------------------- */

/*********************************************************************//**
 * @brief         Configure Pin corresponding to specified parameters passed
 *                 in the PinCfg
 * @param[in]    PinCfg    Pointer to a PINSEL_CFG_Type structure
 *                    that contains the configuration information for the
 *                    specified pin.
 * @return         None
 **********************************************************************/
void PINSEL_ConfigPin(PINSEL_CFG_Type *PinCfg);