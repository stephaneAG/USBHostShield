# USBHostShield
repo dedicated to hacks done using the USB Host Library V2.0 from Circuits@Home

### A little (sad) story :/
Few days ( hours ? ) ago, I was digging how to receive HID devices ( keyboard & mouse ) data ( keystrokes & movements ) to an Arduino, in wired ( usb ) & wireless ( bluetooth ) setups.

The need being different that most tutorials on the web ( which for the most part, have the Arduino/uC act as a HID device ), it took some more digging to implement the opposite, but I can say it works fine ( for the setups I could test ) :)

While looking for clues on how to implement this, I stumbled upon a tutorial that was behind a paywall .. ( grrr :/ ... )
After trying to find the same info elsewhere ( for free :) ), it seemed I couldn't, so maybe ( MAYBE ) the content of the said tutorial was worth paying for it ( and 2 bucks won't kill me .. ), moreover if it took some time for the author to digg & implement such use case ..

Before paying, I digged a little how the content on the page was blurred ( via css ) & obfuscated ( characters remapping ), but couldn't get much from it ( even if I could de-obfuscate the content, it seemed to be the same as the content visible, only garbaged to seem like being additional infos, but it's not, and the rest of the tutorial's content was not even loaded in the page .. )

So, I paid .. and after doing so ( & subscribing cuz otherwise I couldn't get access to the content I paid for .. ), I could finally access the content of that 'badass tutorial' ..

.. that's when I got disillusioned: the content of that tutorial was in no way what the page url, title & intro advertised ! :( ..

.. fact even sadder: contrary to most tuts I read everyday ( like most of us :) ), most written by hackers that responsibly tell their audience they're 'no expert nor engineer whatsoever' ( but that do indeed provide great infos + interesting comments to be digged ), this one was written by someone who, as the page mentionned, is an actual electronic engineer & teaches for the MiT ( ! )

Well, being used to find great infos @ code with MIT license on github, or from MIT engineers / teachers / students, I was quite shocked at that claim, moreover if the content provided is in no way as good & thorough as the tuts we find for free ..

.. I'm most happy finding code & tuts for free, and won't hesitate to click on a 'gimme a beer button' for such ( or share what I build with said code or thanks to having read it in the 1st place ), but that, NO !

I also wouldn't have made a story about this if there wasn't a pay wall prior to being given info from a misleading advertising ..

.. but here we are, so what I did was simple:

- 1st, I asked for a refund ( 2$ aint' much, but I prefer bying a beer to some dev or a cofee to a stranger in need that contributing to what I feel is some sort of scam

- 2nd, I posted a 'little angry' comment on the tutorials' page ( but it 'll only be visible to the people that already paid for the said tutorial, that's fishy .. ), and still waiting for it to be 'validated' by the author ( whcih it won't I guess .. )

- 3rd, I'm posting the code I hacked together, for free ( as usual ), on the present repo: ENJOY !

BUT, before doing so, let's re-post what I commented on the said-tutorial as well as a link to it, for everyone to see & make their own opinion on that ( I guess people won't be as 'angry' as me on the subject, but one day later, I still find my points relevant .. )

This being said, whishing you a good read, & hopefully you'll be able to implement your needs & get a bang from your bucks by paying for neat hardware, not crappy tutorials ;) ..

Also, VERY BIG THANKS ( as usual ) to the devs responsible for the USB Host Library V2.0, without wich none of this could have been possible :)

Last but not least ( just in case ), the lib/code I reference was available since 2013, so no excuse on this, sorry ;) ..

### paying for crappy stuff & then raging in a comment, my way

Here's the link to the tutorial claiming to allow controlling an Arduino via a bluetooth keyboard BUT instead showing how to send keystrokes from a computer's keyboard to an Arduino via bluetooth serial connection ( SPP ):

https://www.learnrobotics.org/blog/control-arduino-robot-bluetooth-keyboard/

Here's my comment:
```
Hi
I've just paid few dollars to access a tutorial ( which I'm NOT used to, most of the time I share my knowledge FREELY & hope others 'll do the same if can be done .. ).

This being said,
- your comment on @chris comment is COMPLETELY IREELEVANT
- indeed, in the page URL, the title, and other sentences ( ex: "In this tutorial we will show you how to configure the HC-06 Bluetooth module to drive a 2WD Arduino Mobile Robot with your Bluetooth keyboard."), you continue misleading for the readers that have not paid yet.
- for what it's worth, and from a "teacher at MIT", I'd presume you'd know better the HUGE difference ( and that possibly the module may be reprogrammed to act as a host, not slave, as the HC-05 .. this is not the case, or is it ? but a rather simple example .. )
- so, you're either incompetent on the subject or just deliberately committed what could be called an "intellectual fraud"
- whatever the reason, I'd been happy giving you few bucks for a rocking tutorial, but NO, I WON'T pay for stuff I already know, available for free & better elsewhere, thanks.

Sorry, but looking forward to NOT read tutorial from you again :/ ..
( also, I want my money back, I'm didn't get what I paid for, and I wouldn't have paid for such crap .. )

Nevertheless, wishing you a very nice day, I hope you learned something(s) ..
```

Moreover, re-reading one of the comments from another indivudual, than succint answer given is what we're actually after, but sadly what's not given in the tutorial, nor any relevant link
```
// author's answer
The methodology outlined in this article should get you started. If you don’t want to use the computer as the “bluetooth” device, you can pair the keyboard directly to your robot’s bluetooth module, and then map keyboard keys to movement functions.
```

R: the 'whole' comments have been copied to the 'tutComms.md' file ( just to make sure it wouldn't be deleted & no longer accessible, hopefully I won't get into troubles for saving those here ..

### What we' interested in ( yay! )

Currently, we can:
- receive keystrokes from a wired keyboard ( 1st tested to make sure the lib behaved as expected )
- receive keystrokes & touchpad/mouse buttons/movements from devices providing a dedicated bluetooth dongle
  ( tested with logitech k400r keyboard+touchpad combo & logitech m315 mouse )
- I have to get some bluetooth devices without dedicated bluetooth dongle to test those in my current setup ( that is, using a USB Host Shield to pair & received stuff )
- I also plan on trying to get some bluetooth module act as a 'HID receiver' ( bluetooth master ) ,but gotta digg more on the subject, since I couldn't find any infos 'ready as is' on the net ( feel free giving me hints on this ;) ), BUT the author of the tutorial seemed to have something in mind on this ? (```you can pair the keyboard directly to your robot’s bluetooth module, and then map keyboard keys to movement functions``` -> am I getting this wrong ? and why not any link shared ? :| .. )

The code for all of this is hosted in the current repo, with naming conventions for convenience ;)

Enjoy, and give kudos to the lib's devs: they are the ones we should give money to in the 1st place ...
+
