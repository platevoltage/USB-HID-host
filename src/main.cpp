#include "variant.h"
#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include <SPI.h>

#include "hidjoystickrptparser.h"




USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

void setup() {

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
        // Usb.Task();
        delay(100);
        count++;

}

