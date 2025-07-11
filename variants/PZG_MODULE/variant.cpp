#include "Arduino.h"
#include "pinmux.inc"

const uint16_t P400_b[] = {
    PIN_PWM | CHANNEL_6 | PWM_CHANNEL_A | GPT_ODD_CFG,
    PIN_SCL | CHANNEL_0,
    PIN_INTERRUPT | CHANNEL_0,
    SCI_CHANNEL | PIN_SCK | CHANNEL_0 | SCI_EVEN_CFG | LAST_ITEM_GUARD};
#define P400 P400_b

const uint16_t P408_b[] = {
    PIN_PWM | CHANNEL_5 | PWM_CHANNEL_B | GPT_ODD_CFG,
    PIN_INTERRUPT | CHANNEL_7,
    SCI_CHANNEL | PIN_CTS_RTS_SS | CHANNEL_1 | SCI_EVEN_CFG,
    SCI_CHANNEL | PIN_RX_MISO_SCL | CHANNEL_9 | SCI_ODD_CFG | LAST_ITEM_GUARD};
#define P408 P408_b

const uint16_t P014_b[] = {
    PIN_DAC | CHANNEL_0,
    PIN_ANALOG | CHANNEL_9 | LAST_ITEM_GUARD};
#define P014 P014_b

extern "C" const PinMuxCfg_t g_pin_cfg[] = {
    {BSP_IO_PORT_00_PIN_00, P000}, /* DAC !CS */
    {BSP_IO_PORT_00_PIN_01, P001}, /* ADC !CS */
    {BSP_IO_PORT_00_PIN_02, P002}, /* ADC !Reset */
    {BSP_IO_PORT_00_PIN_03, P003}, /* ADC Data Ready */
    {BSP_IO_PORT_00_PIN_04, P004}, /* ADC Start */
    {BSP_IO_PORT_00_PIN_11, P011}, /* PGA G0 */
    {BSP_IO_PORT_00_PIN_12, P012}, /* PGA G1 */
    {BSP_IO_PORT_00_PIN_13, P013}, /* PGA G2 */
    {BSP_IO_PORT_00_PIN_14, P014}, /* PGA G3 */
    {BSP_IO_PORT_00_PIN_15, P015}, /* PGA G4 */
    {BSP_IO_PORT_01_PIN_00, P100}, /* Module Interface IO0 */
    {BSP_IO_PORT_01_PIN_01, P101}, /* Module Interface IO1 */
    {BSP_IO_PORT_01_PIN_02, P102}, /* Module Interface CAN RX */
    {BSP_IO_PORT_01_PIN_03, P103}, /* Module Interface CAN TX */
    {BSP_IO_PORT_01_PIN_04, P104}, /* MUX A0 */
    {BSP_IO_PORT_01_PIN_05, P105}, /* MUX A1 */
    {BSP_IO_PORT_01_PIN_06, P106}, /* MUX A2 */
    {BSP_IO_PORT_01_PIN_07, P107}, /* MUX Enable */
    {BSP_IO_PORT_01_PIN_09, P109}, /* Module Interface SPI MOSI */
    {BSP_IO_PORT_01_PIN_10, P110}, /* Module Interface SPI MISO */
    {BSP_IO_PORT_01_PIN_11, P111}, /* Module Interface SPI SCLK */
    {BSP_IO_PORT_01_PIN_12, P112}, /* Module Interface SPI CS */
    {BSP_IO_PORT_01_PIN_13, P113}, /* Heater Relais */
    {BSP_IO_PORT_02_PIN_04, P204}, /* PCB SPI SCK */
    {BSP_IO_PORT_02_PIN_05, P205}, /* PCB SPI MOSI */
    {BSP_IO_PORT_02_PIN_06, P206}, /* PCB SPI MISO */
    {BSP_IO_PORT_02_PIN_12, P212}, /* Heartbeat LED */
    {BSP_IO_PORT_02_PIN_13, P213}, /* User LED */
    {BSP_IO_PORT_03_PIN_01, P301}, /* PCB I2C SDA (SCI2) */
    {BSP_IO_PORT_03_PIN_02, P302}, /* PCB I2C SCL (SCI2) */
    {BSP_IO_PORT_03_PIN_03, P303}, /* EEPROM Write Control */
    {BSP_IO_PORT_03_PIN_04, P304}, /* Highside Power Enable */
    {BSP_IO_PORT_04_PIN_00, P400}, /* Module Interface I2C0 SCL (PC Communication) */
    {BSP_IO_PORT_04_PIN_01, P401}, /* Module Interface I2C0 SDA (PC Communication) */
    {BSP_IO_PORT_04_PIN_02, P402}, /* Battery Relais Enable */
    {BSP_IO_PORT_04_PIN_08, P408}, /* Shunt 1 Relais Enable */
    {BSP_IO_PORT_04_PIN_09, P409}, /* Shunt 2 Relais Enable */
    {BSP_IO_PORT_04_PIN_10, P410}, /* Shunt 3 Relais Enable */
    {BSP_IO_PORT_04_PIN_11, P411}, /* Shunt 4 Relais Enable */
    {BSP_IO_PORT_05_PIN_01, P501}, /* Module Interface I2C1 SDA (SCI1)*/
    {BSP_IO_PORT_05_PIN_02, P502}, /* Module Interface I2C1 SCL (SCI1)*/
};

extern "C"
{
    unsigned int PINCOUNT_fn()
    {
        return (sizeof(g_pin_cfg) / sizeof(g_pin_cfg[0]));
    }
}

int32_t getPinIndex(bsp_io_port_pin_t p)
{
    int max_index = PINS_COUNT;
    int rv = -1;
    for (int i = 0; i < max_index; i++)
    {
        if (g_pin_cfg[i].pin == p)
        {
            rv = i;
            break;
        }
    }
    return rv;
}

#include "FspTimer.h"

void usb_post_initialization()
{
    ((R_USB_FS0_Type *)R_USB_FS0_BASE)->USBMC_b.VDCEN = 1;
}

void enableSubclockInputPins()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
    R_SYSTEM->SOSCCR_b.SOSTP = 1;
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);
}

void initVariant()
{
    // bootloader configures LED_BUILTIN as PWM output, deconfigure it to avoid spurious signals
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(3, PIN_CFG_REQ_PWM)[0]));
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(5, PIN_CFG_REQ_PWM)[0]));
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(6, PIN_CFG_REQ_PWM)[0]));
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(9, PIN_CFG_REQ_PWM)[0]));
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(10, PIN_CFG_REQ_PWM)[0]));
    FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(11, PIN_CFG_REQ_PWM)[0]));
}