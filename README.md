# Art 89 Project: Visualization of Sound
By Sharon Yang and Jiaxin Li

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

