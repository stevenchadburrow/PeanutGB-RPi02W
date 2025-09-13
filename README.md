# PeanutGB-RPi02W
<b>Running PeanutGB emulator on a Raspberry Pi 2W</b><br>

<a href="https://github.com/deltabeard/Peanut-GB">Link to Original Peanut-GB Repo</a><br>

<b>Connecting an ILI9341 LCD in SPI mode using pins:</b><br>
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
2) Go through installation process. Create user named ``` username ``` with pass named ``` password ```. Be sure to connect to WiFi and install the updates.<br>
3) Switch to TTY using Ctrl + Alt + F1, then ``` sudo raspi-config ```.<br>
4) Select to boot to Console instead of Desktop, disable Splash, and set VNC resolution to 640x480.<br>
5) ``` mkdir ~/PeanutGB ```, then put all files found here into that folder.
6) ``` mkdir ~/PeanutGB/ROMS ```, then put whatever Gameboy and Gameboy Color ROMs into that folder.
8) ``` sudo sh ~/PeanutGB/install.sh ```, then ``` sudo reboot ``` for changes to take effect.
9) To run: ``` sh ~/PeanutGB/run.sh ```<br>

<b>Features:</b><br>
The PeanutGB emulator used is actually a version by 'froggestspirit', found <a href="https://github.com/froggestspirit/Peanut-GB">here</a>, in order to play Gameboy Color games.<br>
All of PeanutGB is compiled using ``` gcc ``` and only uses standard Linux libraries.<br>
In order to draw to the screen, PeanutGB will draw directly to ``` /dev/fb0 ```.<br>
In order to get keyboard events, PeanutGB will read directly from ``` /dev/input/event0 ```.<br>
In order to send audio data, PeanutGB will stream directly to ``` /dev/dsp ```.<br>
Warning: ``` /dev/dsp ``` is only available after ``` sudo modprobe snd-pcm-oss ```.<br>



