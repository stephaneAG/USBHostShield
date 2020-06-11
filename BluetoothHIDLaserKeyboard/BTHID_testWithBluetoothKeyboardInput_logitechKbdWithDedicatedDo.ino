/*
 Example sketch for the HID Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */

 /*
    Testing Usb Keyboard Input on Sparkfun USB Host Shield rev 1.3 ( 09947 ) & USB Host Librayr V2. from Circuits@Home

    -> works fine 'as is' ;P
    -> combo matching working as well ;)
    => also, when connecting to usb host shield AFTER arduino boot OR disconnecting then reconnecting,
       there's NO need to hit any key to 'wake up' & start receiving keyboard keys input BUT a delay of ~1 sec seems necessary
    
    last update on: 29/04/2020
    by StephaneAG - 2020
    
*/

#include <BTHID.h>
#include <usbhub.h>
#include "KeyboardParser.h"
#include "MouseParser.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// Needs to make Sparkfun's USB Host Shield rev1.3 (DEV-09947) work with the USB Host Shield library v2.0 from Circuits@Home ( from Sparkfun-related products FAQ page )
#define MAX_RESET 7 // MAX chip pin 12
#define MAX_GPX   8 // MAX chip pin 17

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the class in two ways */
// This will start an inquiry and then pair with your device - you only have to do this once
// If you are using a Bluetooth keyboard, then you should type in the password on the keypad and then press enter
//BTHID bthid(&Btd, PAIR, "0000"); // didn't work for my logitech bluetooth keyboard, which uses a dedicated bluetooth dongle
//BTHID bthid(&Btd, PAIR, ""); // didn't work for my logitech bluetooth keyboard, which uses a dedicated bluetooth dongle
//BTHID bthid(&Btd, PAIR, "1234"); // ran oncec to get something printed over serial ( pin that is set & pairing ol )

// After that you can simply create the instance like so and then press any button on the device
//BTHID bthid(&Btd);
//BTHID bthid(&Btd, "0000");
BTHID bthid(&Btd, "");

// TO DIGG: hci_connect pairWithHID connectToHIDDevice
//Btd-> hci_connect(0x000000000427);

KbdRptParser keyboardPrs;
MouseRptParser mousePrs;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif

  // Needs to make Sparkfun's USB Host Shield rev1.3 (DEV-09947) work with the USB Host Shield library v2.0 from Circuits@Home ( from Sparkfun-related products FAQ page )
  pinMode(MAX_GPX, INPUT);
  pinMode(MAX_RESET, OUTPUT);
  digitalWrite(MAX_RESET, LOW);
  delay(20); // wait 20ms
  digitalWrite(MAX_RESET, HIGH);
  delay(20); // wait 20ms

  // R: here, the following where NOT triggered when not appyling Sparkfun's hints ?! :|..
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }

  bthid.SetReportParser(KEYBOARD_PARSER_ID, &keyboardPrs);
  bthid.SetReportParser(MOUSE_PARSER_ID, &mousePrs);

  // If "Boot Protocol Mode" does not work, then try "Report Protocol Mode"
  // If that does not work either, then uncomment PRINTREPORT in BTHID.cpp to see the raw report
  bthid.setProtocolMode(USB_HID_BOOT_PROTOCOL); // Boot Protocol Mode
  //bthid.setProtocolMode(HID_RPT_PROTOCOL); // Report Protocol Mode

  Serial.print(F("\r\nHID Bluetooth Library Started"));

  // TO DIGG: hci_connect pairWithHID connectToHIDDevice
  //Serial.println(bthid.connected);
  //Btd->hci_state = Btd.HCI_CONNECTED_DEVICE_STATE;
  Btd.hci_connect(0x00,0x00,0x00,0x00,0x04,0x27);
  //bthid.pair();
  //bthid.pBtd.hci_connect(0x000000000427);

}
void loop() {
  Usb.Task();
}
