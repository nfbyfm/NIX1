# NIX1
 Arduino-Library for various Nixie-Tubes, driven by the K155ID1-chip. 
 You can download the latest zip [here](https://github.com/nfbyfm/NIX1/releases).
 
## Usage
 The first four parameters are for the four Pins of the K155ID1 (A, B, C and D).
 Some nixies have an additional digit (like a dot or similar), 
 which can't be directly switched by the K155ID1 (used only for the ciphers). 
 The fith parameter of the constructor represents the Pin of this digit.
 
 If using a multiplexer / shift-register for driving multiple nixies, 
 directly calling the digitalWrite-Method on the pins defined in the constructor,
 might be unwanted. The last parameter in the constructor lets you decide if 
 the output should be directly written to the digital-pins or not. 
 If set to false, you can get the pin-index and level (HIGH / LOW as boolean) by calling the methods
 from APin(bool) to DPin(bool) and DotPin(bool).
 
 For more info you can check out the example-code ("NIX1_Check").
