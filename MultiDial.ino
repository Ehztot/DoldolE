#include <Encoder.h> 
                      //for encoder counting  
                      // cf https://www.pjrc.com/teensy/td_libs_Encoder.html
#include <Mouse.h> 
                      //for scroll
#include <Keyboard.h>
                      //for key 

// match port
// board                                    sensor 
//      6 o |                              -| GND                                 
//      5 o |                              -| +
//      4 o |                              -| SW
//      3 o |                              -| DT               
//      2 o |                              -| CLK
// 2,3 are inturupt for better performance


Encoder Enc(3,2);
long count = -999; 



void setup() {
    Serial.begin(9600); 
                        // for serial monitor
    Serial.print("test"); 
                          // notice start
    pinMode(6,OUTPUT);
    digitalWrite(6,LOW);
                          // 6pin low for ground
    
    pinMode(5,OUTPUT);
    digitalWrite(5,HIGH);
                          //5pin high for power
    
    pinMode(4, INPUT_PULLUP);
                          // normal high 
                          // press low
        
    pinMode(3,INPUT);
                                                        
    pinMode(2,INPUT);     

    // going to add
    // RED check for multi function notice
    // multi function webmode(scroll and alt_left) / gamemode(pubg granade selector / ins:sand )  
  }

void loop() {
  long sen = Enc.read();
                         //sensing 
  if (sen != count){
    Serial.print("ct =");
    Serial.print(sen);
    Serial.println();
    count = sen;
   };
   // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset to zero");
    Enc.write(0);
    
  }
}
