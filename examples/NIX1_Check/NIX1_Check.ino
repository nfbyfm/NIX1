#include <NIX1.h>

NIX1 nixie(2,3,4,5,6, true);

void setup() 
{
  // show Zero and Dot
  nixie.setDisplayNumber(0, true);
  nixie.display();
  delay(1000);
}

void loop() 
{
  // cycle through digits 0 - 9 
  for (int i = 0; i <= 9; i++) 
  {
    nixie.setDisplayNumber(i, false);
    nixie.display();
    delay(1000);
  }

  //turn dot on / off
  nixie.toggleDot(true);
  delay(500);
  nixie.toggleDot(true);
  delay(500);
  
  // run the anti-cathode-poisoning-function
  nixie.antiCathodePoisoning(200);

  // turn everything off (dot as well)
  nixie.off(true);
  nixie.display();
  
  delay(1000);
}
