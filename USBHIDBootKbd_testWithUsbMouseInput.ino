/*
    Testing Usb Keyboard Input on Sparkfun USB Host Shield rev 1.3 ( 09947 ) & USB Host Librayr V2. from Circuits@Home

    -> works fine 'as is' ;P
    -> combo matching working as well ;)
    => also, when connecting to usb host shield AFTER arduino boot OR disconnecting then reconnecting,
       there's NO need to hit any key to 'wake up' & start receiving keyboard keys input BUT a delay of ~1 sec seems necessary
    => Last but not least, devices with a 'dedicated' bluetooth dongle should work fine with USB HID ( NOT Bluetooth HID )
       - tested working fine for logitech k400r kbd+touchpad bluetooth combo with kbd-only parser: works
       - tested working fine for logitech m315 bluetooth mouse: works ..
       - to be tested for logitech k400r kbd+touchpad bluetooth combo with kbd & mouse parser: should work, but not yet sure if 'll be using 'hub' stuff ..
    
    last update on: 29/04/2020
    by StephaneAG - 2020
    
*/

#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// Needs to make Sparkfun's USB Host Shield rev1.3 (DEV-09947) work with the USB Host Shield library v2.0 from Circuits@Home ( from Sparkfun-related products FAQ page )
#define MAX_RESET 7 // MAX chip pin 12
#define MAX_GPX   8 // MAX chip pin 17

class MouseRptParser : public MouseReportParser
{
protected:
	void OnMouseMove	(MOUSEINFO *mi);
	void OnLeftButtonUp	(MOUSEINFO *mi);
	void OnLeftButtonDown	(MOUSEINFO *mi);
	void OnRightButtonUp	(MOUSEINFO *mi);
	void OnRightButtonDown	(MOUSEINFO *mi);
	void OnMiddleButtonUp	(MOUSEINFO *mi);
	void OnMiddleButtonDown	(MOUSEINFO *mi);
};
void MouseRptParser::OnMouseMove(MOUSEINFO *mi)
{
    Serial.print("dx=");
    Serial.print(mi->dX, DEC);
    Serial.print(" dy=");
    Serial.println(mi->dY, DEC);
};
void MouseRptParser::OnLeftButtonUp	(MOUSEINFO *mi)
{
    Serial.println("L Butt Up");
};
void MouseRptParser::OnLeftButtonDown	(MOUSEINFO *mi)
{
    Serial.println("L Butt Dn");
};
void MouseRptParser::OnRightButtonUp	(MOUSEINFO *mi)
{
    Serial.println("R Butt Up");
};
void MouseRptParser::OnRightButtonDown	(MOUSEINFO *mi)
{
    Serial.println("R Butt Dn");
};
void MouseRptParser::OnMiddleButtonUp	(MOUSEINFO *mi)
{
    Serial.println("M Butt Up");
};
void MouseRptParser::OnMiddleButtonDown	(MOUSEINFO *mi)
{
    Serial.println("M Butt Dn");
};

USB     Usb;
USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);

MouseRptParser                               Prs;

void setup()
{
    Serial.begin( 115200 );
#if !defined(__MIPSEL__)
    while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
    Serial.println("Start");

    // Needs to make Sparkfun's USB Host Shield rev1.3 (DEV-09947) work with the USB Host Shield library v2.0 from Circuits@Home ( from Sparkfun-related products FAQ page )
    pinMode(MAX_GPX, INPUT);
    pinMode(MAX_RESET, OUTPUT);
    digitalWrite(MAX_RESET, LOW);
    delay(20); // wait 20ms
    digitalWrite(MAX_RESET, HIGH);
    delay(20); // wait 20ms

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    HidMouse.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
