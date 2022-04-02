/* 
 *  2 Digitl 7 segment display PCB board with (2) 74HC595 shift register ICs
 *  Arduino Tutorial - www.Ardumotive.com
 *  Dev: Michalis Vasilakis // Date: 31/1/2018 // Ver:1.0
 */
#include <ShiftRegister74HC595.h>
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, 2, 3, 4); 
int greenled = 5;
int yellowled = 6;
int redled = 7;
int value,digit1,digit2,digit3,digit4; 
uint8_t  digits[] = {B11000000, //
                      B11111001, //1 
                      B10100100, //2
                      B10110000, //3 
                      B10011001, //4
                      B10010010, //5
                      B10000010, //6
                      B11111000, //7
                      B10000000, //8
                      B10010000 //9
                     };
                        
void setup() {
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);
 
}
void showNumber(int num){
  digit2= num %10;
  digit1= (num/10)%10;
  uint8_t numberToPrint[]={digits[digit2],digits[digit1]};
  sr.setAll(numberToPrint);
}

void loop(){
  digitalWrite(redled,LOW);//tat led do
  showNumber(00);
  delay(500);
  for(int i=10; i>=0; i--){
    showNumber(i);
    digitalWrite(greenled,HIGH);
    delay(500);
    delay(500);
    
  }
  digitalWrite(greenled,LOW);//tat led xanh
  delay(500);
  for(int i=5; i>=0; i--){
    showNumber(i);
    digitalWrite(yellowled,HIGH);
    delay(500);
    delay(500);
  }
  digitalWrite(yellowled,LOW);//tat led vang
  delay(500);
  for(int i=8; i>=0; i--){
    showNumber(i);
    digitalWrite(redled,HIGH);
    delay(500);
    delay(500);
  }
}
