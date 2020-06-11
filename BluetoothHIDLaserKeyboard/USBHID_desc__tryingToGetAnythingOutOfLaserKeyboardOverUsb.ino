#include <usbhid.h>
#include <hiduniversal.h>
#include <hidescriptorparser.h>
#include <usbhub.h>
#include "pgmstrings.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// Needs to make Sparkfun's USB Host Shield rev1.3 (DEV-09947) work with the USB Host Shield library v2.0 from Circuits@Home ( from Sparkfun-related products FAQ page )
#define MAX_RESET 7 // MAX chip pin 12
#define MAX_GPX   8 // MAX chip pin 17

class HIDUniversal2 : public HIDUniversal
{
public:
    HIDUniversal2(USB *usb) : HIDUniversal(usb) {};

protected:
    uint8_t OnInitSuccessful();
};

uint8_t HIDUniversal2::OnInitSuccessful()
{
    uint8_t    rcode;

    HexDumper<USBReadParser, uint16_t, uint16_t>    Hex;
    ReportDescParser                                Rpt;

    if ((rcode = GetReportDescr(0, &Hex)))
        goto FailGetReportDescr1;

    if ((rcode = GetReportDescr(0, &Rpt)))
	goto FailGetReportDescr2;

    return 0;

FailGetReportDescr1:
    USBTRACE("GetReportDescr1:");
    goto Fail;

FailGetReportDescr2:
    USBTRACE("GetReportDescr2:");
    goto Fail;

Fail:
    Serial.println(rcode, HEX);
    Release();
    return rcode;
}

USB Usb;
//USBHub Hub(&Usb);
HIDUniversal2 Hid(&Usb);
UniversalReportParser Uni;

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

  if (!Hid.SetReportParser(0, &Uni))
      ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1  );
}

void loop()
{
    Usb.Task();
}
