/*
 * NIX1.cxx
 * 
 * Copyright 2019 nfbyfm
 * 
 */
#include "Arduino.h"
#include "NIX1.h"

/// Constructor
NIX1::NIX1(int A_Pin, int B_Pin, int C_Pin, int D_Pin, int Dot_Pin, bool setPinMode)
{
	_Apin = A_Pin;
	_Bpin = B_Pin;
	_Cpin = C_Pin;
	_Dpin = D_Pin;
	_Dotpin = Dot_Pin;
	
	b_APin = false;
    b_BPin = false;
    b_CPin = false;
    b_DPin = false;
    b_DotPin = false;
    
	if(setPinMode == true)
	{
		pinMode(A_Pin, OUTPUT);
		pinMode(B_Pin, OUTPUT);
		pinMode(C_Pin, OUTPUT);
		pinMode(D_Pin, OUTPUT);
		pinMode(Dot_Pin, OUTPUT);
	}
}

/// display a given number/digit (0-9) and optimally turn the dot on/off
void NIX1::setDisplayNumber(int number, bool showDot)
{
	_currentDigit = number;
	
	switch (number) 
	{
		case 0:
			b_APin = false;
			b_BPin = false;
			b_CPin = false;
			b_DPin = false;
			break;
		case 1:
			b_APin = true;
			b_BPin = false;
			b_CPin = false;
			b_DPin = false;
			break;
		case 2:
			b_APin = false;
			b_BPin = true;
			b_CPin = false;
			b_DPin = false;
			break;
		case 3:
			b_APin = true;
			b_BPin = true;
			b_CPin = false;
			b_DPin = false;
			break;
		case 4:
			b_APin = false;
			b_BPin = false;
			b_CPin = true;
			b_DPin = false;
			break;
		case 5:
			b_APin = true;
			b_BPin = false;
			b_CPin = true;
			b_DPin = false;
			break;
		case 6:
			b_APin = false;
			b_BPin = true;
			b_CPin = true;
			b_DPin = false;
			break;
		case 7:
			b_APin = true;
			b_BPin = true;
			b_CPin = true;
			b_DPin = false;
			break;
		case 8:
			b_APin = false;
			b_BPin = false;
			b_CPin = false;
			b_DPin = true;
			break;
		case 9:
			b_APin = true;
			b_BPin = false;
			b_CPin = false;
			b_DPin = true;
			break;
		default:
			// Statement(s)
			_currentDigit = -1;
			off(false);
			break;
	}
	
	//show / don't turn on Dot
	if(showDot)
	{
		b_DotPin = true;
	}
	else
	{
		b_DotPin = false;
	}

}

/// get currently displayed / set digit
int NIX1::getDisplayDigit()
{
	return _currentDigit;
}

/// turn Dot on / off, if display is set to true, 'digitalWrite' will be executed imediately (no need to call 'display()'-function)
void NIX1::toggleDot(bool display)
{
	b_DotPin != b_DotPin;
	
	if(display == true)
	{
		writeDigitalOut(_Dotpin, b_DotPin);
	}
}

/// turns each digit after the other on for the given delay-time
void NIX1::antiCathodePoisoning(int digitDisplayTime)
{
	for (int i = 0; i <= 9; i++) 
	{
		setDisplayNumber(i, false);
		display();
		delay(digitDisplayTime);
	}
  
	setDisplayNumber(0, true);
	display();
	delay(digitDisplayTime);
	setDisplayNumber(0, false);
	display();
}

/// turns all digits off and the dot as well if 'turnOffAll' is set to true
void NIX1::off(bool turnOffAll)
{
	b_APin = true;
	b_BPin = true;
	b_CPin = true;
	b_DPin = true;
	
	if(turnOffAll)
	{
		b_DotPin = false;
	}
}

void NIX1::display()
{
	writeDigitalOut(_Apin, b_APin);
	writeDigitalOut(_Bpin, b_BPin);
	writeDigitalOut(_Cpin, b_CPin);
	writeDigitalOut(_Dpin, b_DPin);
	writeDigitalOut(_Dotpin, b_DotPin);
}

void NIX1::writeDigitalOut(int pin, bool high)
{
	if(high)
	{
		digitalWrite(pin, HIGH);
	}
	else
	{
		digitalWrite(pin, LOW);
	}
}


int NIX1::APin(bool &PinHigh)
{
	PinHigh = b_APin;
	return _Apin;
}

int NIX1::BPin(bool &PinHigh)
{
	PinHigh = b_BPin;
	return _Bpin;
}

int NIX1::CPin(bool &PinHigh)
{
	PinHigh = b_CPin;
	return _Cpin;
}

int NIX1::DPin(bool &PinHigh)
{
	PinHigh = b_DPin;
	return _Dpin;
}

int NIX1::DotPin(bool &PinHigh)
{
	PinHigh = b_DotPin;
	return _Dotpin;
}
    
    
    
    
    
