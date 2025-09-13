# PeanutGB-RPi02W
<b>Running PeanutGB emulator on a Raspberry Pi 2W</b><br>

<a href="https://github.com/deltabeard/Peanut-GB">Link to Original Peanut-GB Repo</a><br>

<b>Connecting an ILI9341 in SPI mode using pins:</b><br>
CS = GPIO8 / Pin24<br>
MISO = GPIO9 / Pin21<br>
MOSI = GPIO10 / Pin19<br>
SCLK = GPIO11 / Pin23<br>
RESET = GPIO0 / Pin27<br>
DC = GPIO22 / Pin15<br>

<b>Connecting 3.5mm Audio Jack using pins:</b><br>
LEFT = GPIO12 / Pin32<br>
RIGHT = GPIO13 / Pin33<br>

<b>Additional Requirements:</b><br>
You will also need a USB-Micro to USB-A (Female) adapter and a HDMI-mini to HDMI adapter.<br>

<b>Instructions to Install:</b><br>
1) Re-image an 8GB+ SD Card with Raspberry Pi OS 64-bit.<br>
2) Go through installation process. Create user named ``` username ``` with pass named ``` password ```. Be sure to connect to WiFi to have complete installation.<br>
3) ``` mkdir PeanutGB ; cd PeanutGB ``` and dump all files found here into that folder.<br>
4) ``` sudo sh install.sh ```, and possibly ``` echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc ```.<br>
5) ``` sudo reboot ``` and everything should work as planned!<br>

<b>Features:</b><br>
The PeanutGB emulator used is actually a version by 'froggestspirit', found <a href="https://github.com/froggestspirit/Peanut-GB">here</a>, in order to play Gameboy Color games.<br>
All of PeanutGB is compiled using ``` gcc ``` and only uses standard Linux libraries.<br>
In order to draw to the screen, PeanutGB will draw directly to ``` /dev/fb0 ```.<br>
In order to get keyboard events, PeanutGB will read directly from ``` /dev/input/event0 ```.<br>
In order to send audio data, PeanutGB will stream directly to ``` /dev/dsp ```.<br>
Warning: ``` /dev/dsp ``` is only available after ``` sudo modprobe snd-pcm-oss ```.<br>



