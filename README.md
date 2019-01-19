# LEDSideScroller
Random number side scrolling cursor
:Date: 01/20/2019
:Revision: .2a
:License: Public Domain

Generate a random number the height of an LED martix.
Draw a column on the matrix that is (random number) high.
Create a sideways scrolling effect by blanking out the next row.

== Step 1: Installation
Change variables at the top of the sketch to match your setup:
- LED matrix height
- LED matrix width
- Adjust matrix config if attaching multiple led panels
- PWN pin number

Plug in matrix to Vcc, Gnd, and the PWN PIN chosen in the sketch.
Compile/Upload code to arduino.

NOTE: Only tested with Arduino Uno.

=== License
This project is released under a Public Domain License.
