#include "LedControlMS.h"

#define NBR_MTX 1 //number of matrices attached is one

LedControl lc=LedControl(4,3,2, NBR_MTX);//

unsigned long delayTime=1200;  // Delay between Frames

// Put values in arrays
byte invaderla[] =
{
   B00100100,  
   B01011010,
   B10000001,
   B10000001,
   B10000001,
   B01000010,
   B00100100,
   B00011000
};

byte invaderlb[] =
{
  B00000000, 
  B01100110,
  B11111111,
  B11111111, 
  B11111111,
  B01111110,
  B00111100,
  B00011000
};



void setup()
{
   
    lc.shutdown(0,false);

lc.setIntensity(0,5);
  
   
    lc.clearDisplay(0);

}


void sinvaderla()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invaderla[i]);
  }
}

void sinvaderlb()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,1,invaderlb[i]);
  }
}



void loop()
{
// Put #1 frame on both Display
    sinvaderla();
    delay(delayTime);
//    sinvader2a();
//    delay(delayTime);


// Put #2 frame on both Display
    sinvaderlb();
    delay(delayTime);
//    sinvader2b();
//    delay(delayTime);

}
