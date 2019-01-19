#include "Adafruit_GFX.h"
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 11           // Setup PWN PIN used on Arduino
const int maxScale = 8;  // Setup height of panel
const int MATRIXWIDTH = 32; // Setup width of panel

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIXWIDTH, maxScale, PIN,
  NEO_MATRIX_BOTTOM    + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);


const int yellowZone = 4; // height on led panel to display yellow
const int redZone = 6; // height on led panel to display red
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)

unsigned int sample1; // to contain random number

unsigned int curRow = 0; // looping vars for current row
unsigned int curRowNext = 0;  //looping vars for next row

const int DELAY = 100;  // delay for effect

//Colors vars initalize
uint16_t cOff;
uint16_t cRed;
uint16_t cYellow;
uint16_t cGreen;

void setup() 
{
  // Initalize matrix
  matrix.begin();  // pass in the address
  matrix.setBrightness(8);
  
   
  // Set colors used
  cOff=matrix.Color(0,0,0);
  cYellow=matrix.Color(255,165,0);
  cRed=matrix.Color(255,0,0);
  cGreen=matrix.Color(0,255,0);
   
  //Serial.begin(9600);  // Debug purposes
}
 
 
void loop() 
{

  //unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
  
  curRow = curRow%MATRIXWIDTH;
  curRowNext = (curRow+1)%MATRIXWIDTH;
   
  sample1 = random(0, maxScale); //injecting random number in place of real data

  //blank out next row
   matrix.drawPixel(curRowNext, 0, cOff);
   matrix.drawPixel(curRowNext, 1, cOff);
   matrix.drawPixel(curRowNext, 2, cOff);
   matrix.drawPixel(curRowNext, 3, cOff);
   matrix.drawPixel(curRowNext, 4, cOff);
   matrix.drawPixel(curRowNext, 5, cOff);
   matrix.drawPixel(curRowNext, 6, cOff);
   matrix.drawPixel(curRowNext, 7, cOff);
   
   // draw the new sample
   for (int i = 0; i <= sample1; i++)
   {
      if (i >= sample1)  // blank these pixels
      {
         matrix.drawPixel(curRow, i, cOff);
      }
      else if (i < yellowZone) // draw in green
      {
         matrix.drawPixel(curRow, i, cGreen);
      }
      else if (i < redZone) //draw in yellow
      {
        matrix.drawPixel(curRow, i, cYellow);
      }
      else // Red Alert!  Red Alert!
      {
         matrix.drawPixel(curRow, i, cRed);
      }
   }
   matrix.show();  // write the changes we just made to the display
   curRow++;
   
   delay(DELAY);  //small delay for effect
}
