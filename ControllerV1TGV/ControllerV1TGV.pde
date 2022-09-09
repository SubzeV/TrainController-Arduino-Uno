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
  
  try // wait for 1 second before starting to register input.
  {
    Thread.sleep(1000);
  }
  catch(InterruptedException ex)
  {
    Thread.currentThread().interrupt();
  }
  System.out.println("Outputting now!");
  
  size(700, 500);
  MyPort = new Serial(this, "COM5", 9600); // Arduino is on COM3. Enter the COM on which your Arduino is on.
  MyPort.bufferUntil('\n');
  

  
}
void draw(){//Not really necessary
  background(0, 0, 0);
  fill(255, 0, 0);
  text("Start using the controller...", 10, 10);
}
void serialEvent(Serial MyPort)throws Exception {
   KeyString = MyPort.readStringUntil('\n');
   KeyString = KeyString.substring(0, KeyString.indexOf(':')); // the string is split. the whole string leaving the colon is taken
   System.out.println(KeyString); // prints the serial string for debugging purpose
   Robot Arduino = new Robot(); // constructor of robot class
   switch(KeyString){
     case "Forward1" :
       Arduino.keyPress(KeyEvent.VK_D); // presses D key.
         try
         {
           Thread.sleep(100); // wait set amount of time (ms)
         }
         catch(InterruptedException ex)
         {
           Thread.currentThread().interrupt();
         }
       Arduino.keyRelease(KeyEvent.VK_D); // releases D key
       break;
     case "Back1" :
       Arduino.keyPress(KeyEvent.VK_A); // presses A key
         try
         {
           Thread.sleep(100); // wait set amount of time (ms)
         }
         catch(InterruptedException ex)
         {
           Thread.currentThread().interrupt();
         }
       Arduino.keyRelease(KeyEvent.VK_A); // releases A key
       break;
     case "Forward2" :
       Arduino.keyPress(KeyEvent.VK_QUOTE); // presses quote key.
         try
         {
           Thread.sleep(120); // wait set amount of time (ms)
         }
         catch(InterruptedException ex)
         {
           Thread.currentThread().interrupt();
         }
       Arduino.keyRelease(KeyEvent.VK_QUOTE); // releases quote key
       break;
     case "Back2" :
       Arduino.keyPress(KeyEvent.VK_SEMICOLON); // presses semicolon key.
         try
         {
           Thread.sleep(120); // wait set amount of time (ms)
         }
         catch(InterruptedException ex)
         {
           Thread.currentThread().interrupt();
         }
       Arduino.keyRelease(KeyEvent.VK_SEMICOLON); // releases semicolon key
       break;
   }
   
}
