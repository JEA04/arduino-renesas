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
// Keine LEDs definiert. USER und HB sind als Pins definiert und werden in der Applikation dann konfiguriert.

/****** RTC CORE DEFINES *******/
#define RTC_HOWMANY 1

/****** UART CORE DEFINES ******/

#define SERIAL_HOWMANY 0        // Keine Serielle Schnittstelle auf dem Board
#define UART_INTERRUPT_COUNT 0  // NOTE: Als Bugfix hier definiert. Sobald eine serielle Schnittstelle benötigt wird,
                                //       muss dieses define entfernt werden. 

/****** WIRE CORE DEFINES ******/

#define WIRE_HOWMANY 3 // Drei I2C Schnittstellen vorhanden. (PCB I2C, PC-I2C, Module Interface I2C)
// PCB I2C
#define WIRE_SDA_PIN (28u) // P301
#define WIRE_SCL_PIN (29u) // P302
static const uint8_t PCB_I2C_SDA = WIRE_SDA_PIN;
static const uint8_t PCB_I2C_SCL = WIRE_SCL_PIN;

// Communication I2C (I2C0)
#define WIRE1_SDA_PIN (33u) // P401
#define WIRE1_SCL_PIN (32u) // P400
static const uint8_t COMM_I2C_SDA = WIRE1_SDA_PIN;
static const uint8_t COMM_I2C_SCL = WIRE1_SCL_PIN;

// Module Interface I2C (I2C1)
#define WIRE2_SDA_PIN (40u) // P502
#define WIRE2_SCL_PIN (39u) // P501
static const uint8_t SCI1_I2C_SDA = WIRE2_SDA_PIN;
static const uint8_t SCI1_I2C_SCL = WIRE2_SCL_PIN;

/****** SPI CORE DEFINES ******/

#define SPI_HOWMANY 2 // Zwei SPI Schnittstellen (PCB und Module Interface)

// PCB SPI
#define PIN_SPI_MOSI (24u) // P205
#define PIN_SPI_MISO (25u) // P206
#define PIN_SPI_SCK (23u)  // P204
// CS Pins sind separat definiert
#define FORCE_SPI_MODE (MODE_SPI)
static const uint8_t PCB_MOSI = PIN_SPI_MOSI;
static const uint8_t PCB_MISO = PIN_SPI_MISO;
static const uint8_t PCB_SCK = PIN_SPI_SCK;

// Module Interface SPI (SPIB)
#define PIN_SPI1_MOSI (18u) // P109
#define PIN_SPI1_MISO (19u) // P110
#define PIN_SPI1_SCK (20u)  // P111
#define PIN_SPI1_CS (21u)   // P112
#define FORCE_SPI1_MODE (MODE_SPI)
static const uint8_t SPIB_MOSI = PIN_SPI1_MOSI;
static const uint8_t SPIB_MISO = PIN_SPI1_MISO;
static const uint8_t SPIB_SCK = PIN_SPI1_SCK;
static const uint8_t SPIB_CS = PIN_SPI1_CS;

/****** GTP CORE DEFINES *******/

#define GTP32_HOWMANY 2
#define GTP16_HOWMANY 6
#define GPT_HOWMANY 8

/****** AGT CORE DEFINES *******/
#define AGT_HOWMANY 2

/****** CAN CORE DEFINES ******/

#define CAN_HOWMANY 1

#define PIN_CAN0_TX 13 // P103
#define PIN_CAN0_RX 12 // P102
#define PIN_CAN0_STBY (-1)

#define EXT_INTERRUPTS_HOWMANY 2

#define AVCC_MEASURE_PIN 20
#define AVCC_MULTIPLY_FACTOR 8.33

#define AR_INTERNAL_VOLTAGE 1.43f

#define USB_VID (0x2341)
#define USB_PID (0x0069)
#define USB_NAME "PZG-Module"

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