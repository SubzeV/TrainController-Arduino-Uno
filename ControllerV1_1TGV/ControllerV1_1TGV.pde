import processing.serial.*;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.KeyStroke;
Serial MyPort;                                
String KeyString = "";
void setup()
{
  System.out.println("Hi");
  
  // wait for 1 second before starting to register input.
  delay(1000);
  System.out.println("Outputting now!");
  
  size(700, 500);
  MyPort = new Serial(this, "COM5", 9600); // Arduino is usually on COM3 or 5. Enter the COM on which your Arduino is on.
  MyPort.bufferUntil('\n');
  

  
}
void draw(){//Not really necessary but nice to have visual
  background(0, 0, 0);
  fill(255, 0, 0);
  text("Start using the controller...", 30, 30);
}
void serialEvent(Serial MyPort)throws Exception {
   KeyString = MyPort.readStringUntil('\n');
   KeyString = KeyString.substring(0, KeyString.indexOf(':')); // the string is split. the whole string leaving the colon is taken
   System.out.println(KeyString); // prints the serial string for debugging purpose
   Robot Arduino = new Robot(); // constructor of robot class
   switch(KeyString){
     case "Forward1" :
       Arduino.keyPress(KeyEvent.VK_D); // presses D key.
         delay(83);
       Arduino.keyRelease(KeyEvent.VK_D); // releases D key
       break;
     case "Back1" :
       Arduino.keyPress(KeyEvent.VK_A); // presses A key
         delay(83);
       Arduino.keyRelease(KeyEvent.VK_A); // releases A key
       break;
     case "Forward2" :
       Arduino.keyPress(KeyEvent.VK_QUOTE); // presses quote key.
         delay(100);
       Arduino.keyRelease(KeyEvent.VK_QUOTE); // releases quote key
       break;
     case "Back2" :
       Arduino.keyPress(KeyEvent.VK_SEMICOLON); // presses semicolon key.
         delay(100);
       Arduino.keyRelease(KeyEvent.VK_SEMICOLON); // releases semicolon key
       break;
   }
   
}
//
