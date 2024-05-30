#include "variant.h"
#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include <SPI.h>

#include "hidjoystickrptparser.h"



#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"
// #include "custom_config.h"
#include "sdk_config.h" // Ensure this is included after your custom config

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

APP_PWM_INSTANCE(PWM1,1);                   // Create the instance "PWM1" using TIMER1.

static volatile bool ready_flag;            // A flag indicating PWM status.

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
    ready_flag = true;
}
uint32_t value;
void setup() {

//     ret_code_t err_code;

//     /* 2-channel PWM, 200Hz, output on DK LED pins. */
//     app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_2CH(5000L, BSP_LED_0, BSP_LED_1);

//     /* Switch the polarity of the second channel. */
//     pwm1_cfg.pin_polarity[1] = APP_PWM_POLARITY_ACTIVE_HIGH;

//     /* Initialize and enable PWM. */
//     err_code = app_pwm_init(&PWM1,&pwm1_cfg,pwm_ready_callback);
//     APP_ERROR_CHECK(err_code);
//     app_pwm_enable(&PWM1);

    
        Serial.begin(115200);
        Serial.println("Start");

        if (Usb.Init() == -1)
                Serial.println("OSC did not start.");

        delay(200);

        if (!Hid.SetReportParser(0, &Joy))
                ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);


}

int count = 0;
void loop() {
        Usb.Task();
        // for (uint8_t i = 0; i < 40; ++i)
        // {
        //     value = (i < 20) ? (i * 5) : (100 - (i - 20) * 5);

        //     ready_flag = false;
        //     /* Set the duty cycle - keep trying until PWM is ready... */
        //     while (app_pwm_channel_duty_set(&PWM1, 0, value) == NRF_ERROR_BUSY);

        //     /* ... or wait for callback. */
        //     while (!ready_flag);
        //     APP_ERROR_CHECK(app_pwm_channel_duty_set(&PWM1, 1, value));
        //     nrf_delay_ms(25);
        // }

}

