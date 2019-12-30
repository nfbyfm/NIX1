/*
  NIX1.h - Library for Nixietubes using the K155N-Chip.
*/
#ifndef NIX1_h
#define NIX1_h

#include "Arduino.h"

class NIX1
{
  public:
	/// Constructor if 'setPinMode' is set to true, the 'pinMode'-function will be called
    NIX1(int A_Pin, int B_Pin, int C_Pin, int D_Pin, int Dot_Pin, bool setPinMode);    
    /// display a given number/digit (0-9) and optimally turn the dot on/off
    void setDisplayNumber(int number, bool showDot);
    /// get currently displayed / set digit
    int getDisplayDigit();	
    /// turn Dot on / off, if display is set to true, 'digitalWrite' will be executed imediately (no need to call 'display()'-function)
    void toggleDot(bool display);
    /// actually display the digits
    void display();
    /// turns each digit after the other on for the given delay-time
    void antiCathodePoisoning(int digitDisplayTime);
    /// turns all digits off and the dot as well if 'turnOffAll' is set to true
    void off(bool turnOffAll);
    
    int APin(bool &PinHigh);
    int BPin(bool &PinHigh);
    int CPin(bool &PinHigh);
    int DPin(bool &PinHigh);
    int DotPin(bool &PinHigh);
    
  private:
    int _Apin;
    int _Bpin;
    int _Cpin;
    int _Dpin;
    int _Dotpin;
    int _currentDigit;
    
    bool b_APin;
    bool b_BPin;
    bool b_CPin;
    bool b_DPin;
    bool b_DotPin;
    
    void writeDigitalOut(int pin, bool high);
};

#endif
