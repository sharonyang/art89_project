# Art 89 Project: Visualization of Sound
By Sharon Yang and Jiaxin Li

Compile
====

Before attempt to compile, make sure you have AVR environment set up. The
code is written in Mac environment. The AVR code base/platform can be found
and downloaded here: http://www.obdev.at/products/crosspack/index.html.

Download it, unpack and install it, and make sure you have set up properly
by running "which avrdude" in command line.

Currently, our code can be compiled when you go to firmware/ directory, and
run:
```
make
```

It simply compiles the code we have and outputs metadata of our hardware:
```
avr-gcc -Wall -Os -DF_CPU=8000000 -mmcu=atmega328 -c main.c -o main.o
avr-gcc -Wall -Os -DF_CPU=8000000 -mmcu=atmega328 -o main.elf main.o
rm -f main.hex
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
avr-size --format=avr --mcu=atmega328 main.elf
AVR Memory Usage
----------------
Device: atmega328

Program:    4612 bytes (14.1% Full)
(.text + .data + .bootloader)

Data:          0 bytes (0.0% Full)
(.data + .bss + .noinit)
```

The code compiles, and we will later test it with hardware.

The object files, etc., can be cleaned by running:
```
make clean
```


Description
====

Our project aims to convert audio data into graphics. The hardware set up
consists of a video camera, a few microphones, and a monitor. The micro-
controller converts the audio data into visualization and overlays graphics
on top of the video content.


Software Design Overview
====
The microcontroller compares the amplitude of the signals from the micro-
phones and uses this information to estimate the approimxate location of
the sound. In addition, video signal coming from the camera is broken down
by computer chip. Software receives the signal, overlays the graphics onto
the video signal, and re-sends composite video format to the monitor.


Sound Collection Logic
====
Software receives multiple incoming sound sources from multiple microphones.
It sorts the data and finds the microphone with the highest binary value
for sound and guesses the direction that the sound is coming from with
respect to the camera and the locations of the microphones.

Once the above is done, it can overlays the graphics onto the video signal.
Currently, it dispalys vertical color bars at the location of the sound.


Note for Initialization
====
Background noise is taken into account. To establish this baseline, we
first initialize the camera as well as the microphones, wait for a few
minutes for the software code to establish base conditions for the
camera, and the system would be ready to detect any sound above the
established threshold.

