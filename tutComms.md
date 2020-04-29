Eric Anderson on 11/18/2019 at 7:04 PM
Your tutorial seems to assume that the keyboard will automatically connect to the HC-06 module, but can that be the case? Does the HC-06 just connect to any BT device? Or is there a process to make that happen?

Liz Miller on 11/18/2019 at 8:18 PM
Eric, this project uses a computer as a host. (The keyboard is attached to the computer via USB.) First, connect your computer to the HC-06 module before using it to control the robot.

Manasi Arya on 12/08/2019 at 4:25 AM
Can you suggest how to on the car using bluetooth. I.e by pressing a button on the keyboard

Liz Miller on 12/08/2019 at 4:05 PM
The methodology outlined in this article should get you started. If you don’t want to use the computer as the “bluetooth” device, you can pair the keyboard directly to your robot’s bluetooth module, and then map keyboard keys to movement functions.

chris on 01/03/2020 at 6:58 PM
Your title is misleading you’re not actually connecting a bluetooth keyboard to the arduino robot directly. You are using a computer to control a robot via bluetooth. And that should be the title here.

Liz Miller on 01/05/2020 at 11:08 AM
Chris, the HC-06 Bluetooth module communicates serially, so the only way to use it in this example is with a host computer. If you wanted to put a computer (i.e. Raspberry Pi) on your robot, you could do that instead to have direct control.
