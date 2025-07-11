#pragma once

#define PIN(X, Y) (X * 16 + Y)

// Pin count
// ----
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT (PINCOUNT_fn())
#define NUM_DIGITAL_PINS (41u)

// Digital pins
// -----------
#define PIN_DAC_NCS (0u)
#define PIN_ADC_NCS (1u)
#define PIN_ADC_NRST (2u)
#define PIN_ADC_NDRDY (3u)
#define PIN_ADC_START (4u)
#define PIN_PGA_G0 (5u)
#define PIN_PGA_G1 (6u)
#define PIN_PGA_G2 (7u)
#define PIN_PGA_G3 (8u)
#define PIN_PGA_G4 (9u)
#define PIN_IO0 (10u)
#define PIN_IO1 (11u)
#define PIN_MUX_A0 (14u)
#define PIN_MUX_A1 (15u)
#define PIN_MUX_A2 (16u)
#define PIN_MUX_ENABLE (17u)
#define PIN_HEATER_RELAIS (22u)
#define PIN_LED_HB (26u)
#define PIN_LED_USER (27u)
#define PIN_EEPROM_NWC (30)
#define PIN_HS_PW_EN (31)
#define PIN_ENABLE_BAT (34)
#define PIN_ENABLE_SHUNT1 (35)
#define PIN_ENABLE_SHUNT2 (36)
#define PIN_ENABLE_SHUNT3 (37)
#define PIN_ENABLE_SHUNT4 (38)

static const uint8_t DAC_NCS = PIN_DAC_NCS;
static const uint8_t ADC_NCS = PIN_ADC_NCS;
static const uint8_t ADC_NRST = PIN_ADC_NRST;
static const uint8_t ADC_NDRDY = PIN_ADC_NDRDY;
static const uint8_t ADC_START = PIN_ADC_START;
static const uint8_t PGA_G0 = PIN_PGA_G0;
static const uint8_t PGA_G1 = PIN_PGA_G1;
static const uint8_t PGA_G2 = PIN_PGA_G3;
static const uint8_t PGA_G3 = PIN_PGA_G3;
static const uint8_t PGA_G4 = PIN_PGA_G4;
static const uint8_t IO0 = PIN_IO0;
static const uint8_t I01 = PIN_IO1;
static const uint8_t MUX_A0 = PIN_MUX_A0;
static const uint8_t MUX_A1 = PIN_MUX_A1;
static const uint8_t MUX_A2 = PIN_MUX_A2;
static const uint8_t MUX_ENABLE = PIN_MUX_ENABLE;
static const uint8_t HEATER_RELAIS = PIN_HEATER_RELAIS;
static const uint8_t LED_HB = PIN_LED_HB;
static const uint8_t LED_USER = PIN_LED_USER;
static const uint8_t EEPROM_NWC = PIN_EEPROM_NWC;
static const uint8_t HS_PW_EN = PIN_HS_PW_EN;
static const uint8_t ENABLE_BAT = PIN_ENABLE_BAT;
static const uint8_t ENABLE_SHUNT1 = PIN_ENABLE_SHUNT1;
static const uint8_t ENABLE_SHUNT2 = PIN_ENABLE_SHUNT2;
static const uint8_t ENABLE_SHUNT3 = PIN_ENABLE_SHUNT3;
static const uint8_t ENABLE_SHUNT4 = PIN_ENABLE_SHUNT4;

#define digitalPinHasPWM(p) (IS_PIN_PWM(getPinCfgs(p, PIN_CFG_REQ_PWM)[0]))
// LEDs
// ----
#define PIN_LED (13u)
#define LED_BUILTIN PIN_LED
#define LED_TX (21u)
#define LED_RX (22u)

/****** RTC CORE DEFINES *******/
#define RTC_HOWMANY 1

/****** UART CORE DEFINES ******/

#define SERIAL_HOWMANY 1
#define UART1_TX_PIN 1
#define UART1_RX_PIN 0

/****** WIRE CORE DEFINES ******/

#define WIRE_HOWMANY 1
#define WIRE_SDA_PIN 18 /* A4 */
#define WIRE_SCL_PIN 19 /* A5 */

static const uint8_t SDA = WIRE_SDA_PIN;
static const uint8_t SCL = WIRE_SCL_PIN;

/****** SPI CORE DEFINES ******/

#define SPI_HOWMANY 1

#define PIN_SPI_MOSI (11)
#define PIN_SPI_MISO (12)
#define PIN_SPI_SCK (13)
#define PIN_SPI_CS (10)
#define FORCE_SPI_MODE (MODE_SPI)

static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;
static const uint8_t CS = PIN_SPI_CS;
static const uint8_t SS = PIN_SPI_CS;

/****** GTP CORE DEFINES *******/

#define GTP32_HOWMANY 2
#define GTP16_HOWMANY 6
#define GPT_HOWMANY 8

/****** AGT CORE DEFINES *******/
#define AGT_HOWMANY 2

/****** CAN CORE DEFINES ******/

#define CAN_HOWMANY 1

#define PIN_CAN0_TX (4)
#define PIN_CAN0_RX (5)
#define PIN_CAN0_STBY (-1)

#define EXT_INTERRUPTS_HOWMANY 2

#define AVCC_MEASURE_PIN 20
#define AVCC_MULTIPLY_FACTOR 8.33

#define AR_INTERNAL_VOLTAGE 1.43f

#define USB_VID (0x2341)
#define USB_PID (0x0069)
#define USB_NAME "UNO R4 Minima"

#define VUSB_LDO_ENABLE 1

/* EEPROM DEFINES */

#define ARDUINO_FLASH_TYPE LP_FLASH
#define FLASH_BASE_ADDRESS 0x40100000
#define FLASH_TOTAL_SIZE 0x2000
#define FLASH_BLOCK_SIZE 0x400

// TODO: removeme
#ifdef __cplusplus
extern "C"
{
#endif
    void iic_slave_tei_isr(void);
    void iic_slave_eri_isr(void);
#ifdef __cplusplus
}
#endif
