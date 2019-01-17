#include <Encoder.h> 
                      //for encoder counting  
                      // cf https://www.pjrc.com/teensy/td_libs_Encoder.html
#include <Mouse.h> 
                      //for scroll
#include <Keyboard.h>
                      //for key

char alt = KEY_LEFT_ALT ;
char arrowLft = KEY_LEFT_ARROW ;
char arrowRgt = KEY_RIGHT_ARROW ;
               
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
                   //lotate count
int lotState = 0; 
                   // lotate state 
                   // 1 left
                   // 0 right 
                   // if mode change add function ex mpv
                   // 3 , 1 frame >> 
                   // 2 . 1frame <<
int pushState =0;
                   // 0 low
                   // 1 high
                   // if press T time mode change
                   // 2 low
                   // 3 high 
int mode = 0; 
               //mode1 = 0 
               //mode2 = 2                     
void setup() {
    Serial.begin(9600); 
                        // for serial monitor
    Serial.println("test"); 
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
  long rotSen = Enc.read();
  int pushSen = digitalRead(4);
                           //sensing 
  if (rotSen != count){
      Serial.print("ct =");
      Serial.print(rotSen);
      Serial.println();
    
      if(rotSen > count){
          lotState = 1;
          Serial.println("left");
        }else if(rotSen < count){
          lotState = 0;
          Serial.println("right");
        };
        
    count = rotSen;
    
    };
        
                                     // if a character is sent from the serial monitor,
                                     // reset both back to zero.
    if (Serial.available()) {
        Serial.read();
        Serial.println("Reset to zero");
        Enc.write(0);
     };
    
    pushState = pushSen + mode ; // temp
    
  if(pushState == 0){
    Serial.print(pushState);
    Keyboard.begin();
    Keyboard.press(alt);
    Keyboard.write(arrowLft);
    Keyboard.releaseAll();
    Keyboard.end();
    delay(300);
                          // go back in web browser
        } else if(pushState == 2){
          //coming sooon
          }; 
}
