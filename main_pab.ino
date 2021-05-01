#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
int b=0;
char f,s,l,r,la,ser;
/*
void linear_actuator()
{
  
}
void servo_spray()
{
  
}*/

// setting the duty cycle of motors for different motions
void forward()
 {b=1;
  nh.loginfo("forward");
  OCR5A=330;  //M2   
  OCR4A=330;  //M1
  OCR3A=330;  //M3
  OCR1A=330;  //M4
 }
 void stop_()
 {b=2;
  nh.loginfo("stop");
  OCR5A=270;
  OCR4A=270;
  OCR3A=270;
  OCR1A=270;
 }
 void right()
 {b=3;
  nh.loginfo("right");
  OCR5A=330;
  OCR4A=420;
  OCR3A=420;
  OCR1A=330;
 }
 void left()
 {b=4;
  nh.loginfo("left");
  OCR5A=450;
  OCR4A=330;
  OCR3A=330;
  OCR1A=450;
 }
 void continue_()
 {
  nh.loginfo("none");
  if(b==1)
  forward();
  else if(b==2)
  stop_();
  else if(b==3)
  right();
  else
  left();
 }
 
 String a;
 void messageCb( const std_msgs::String& msg_){ // This fucntion obtains the messages from the controller
   //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
   //strcpy(a,toggle_msg.data);
   //nh.loginfo(toggle_msg.data);
   // the controller sends data as a string 
   //we check the respective indices for our button's state
   f= msg_.data[0]; 
   s= msg_.data[3];
   l= msg_.data[6];
   r= msg_.data[9];
   la = msg_.data[12];
   ser = msg_.data[15];
   if(f == '1')
   {
    forward();
   }
   else if(s == '1')
   {
    stop_();
   }
   else if(l == '1')
   {
    left();
   }
   else if(r == '1')
   {
    right();
   }
   else if(la == '1')
   {
    linear_actuator();
   }
   else if(ser == '1')
   {
    servo_spray();
   }
   else
   {
    continue_();
   }
 }
 
 ros::Subscriber<std_msgs::String> sub("chatter", messageCb );
 
 void setup() // setting up all motor driver pins,pwm mode and duty cycle
 {
   //pinMode(13, OUTPUT);
   nh.initNode();
   nh.subscribe(sub);
   //Serial.begin(57600);
   //Serial.begin(9600);

  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(3,OUTPUT);
  
  
DDRB |= _BV(PB5);  // pin 11    M4
TCCR1A=0;
TCCR1B=0;
TCCR1A |= _BV(WGM11);
TCCR1B |= _BV(WGM13)|_BV(CS10);
OCR1A = 270;

ICR1=500;
TCCR1A |= _BV(COM1A1);

DDRE |= _BV(PE3); //pin5     M3 
TCCR3A=0;
TCCR3B=0;
TCCR3A |= _BV(WGM31);
TCCR3B |= _BV(WGM33)|_BV(CS30);
OCR3A = 270 ;
ICR3=500;
TCCR3A |= _BV(COM3A1);

DDRH |= _BV(PH3);  // pin 6  M2        
TCCR4A=0;
TCCR4B=0;
TCCR4A |= _BV(WGM41);
TCCR4B |= _BV(WGM43)|_BV(CS40);
OCR4A = 270;
ICR4=500;
TCCR4A |= _BV(COM4A1);

DDRL |= _BV(PL3);  // pin 46     M1
TCCR5A=0;
TCCR5B=0;
TCCR5A |= _BV(WGM51);
TCCR5B |= _BV(WGM53)|_BV(CS50);
OCR5A = 270;
ICR5=500;
TCCR5A |= _BV(COM5A1);

 }
 
 void loop()
 {
   nh.subscribe(sub);
   nh.spinOnce();
   delay(100);
 }
