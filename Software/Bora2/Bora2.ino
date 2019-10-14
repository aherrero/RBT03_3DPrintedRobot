/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo ServoBase;  // create servo object to control a servo
Servo ServoArm1;  // create servo object to control a servo.
Servo ServoGripper;  // create servo object to control a servo
Servo ServoArm2;  // create servo object to control a servo

int g_BaseValue = 90;
int g_HorizValue = 90;
int g_GripperValue = 90;
int g_VertValue = 90;

int g_MaxValue = 178;
ing g_MinValue = 2;

void setup()
{
  Serial.begin(9600);

  ServoBase.attach(9);
  ServoArm1.attach(10);
  ServoGripper.attach(11);
  ServoArm2.attach(6);
}

void loop()
{

  if (Serial.available() > 0)
  {
    // read the incoming byte:
    int incomingByte = Serial.read();

    if(incomingByte == 'w')
    {
      if(g_BaseValue < g_MaxValue)
        g_BaseValue = g_BaseValue + 2;
      ServoBase.write(g_BaseValue);
    }
    else if(incomingByte == 's')
    {
      if(g_BaseValue > g_MinValue)
        g_BaseValue = g_BaseValue - 2;
      ServoBase.write(g_BaseValue);
    }
    else if(incomingByte == 'd')
    {
      if(g_HorizValue < g_MaxValue)
        g_HorizValue = g_HorizValue + 2;
      ServoArm1.write(g_HorizValue);
    }
    else if(incomingByte == 'a')
    {
      if(g_HorizValue > g_MinValue)
        g_HorizValue = g_HorizValue - 2;
      ServoArm1.write(g_HorizValue);
    }
    else if(incomingByte == 'i')
    {
      if(g_GripperValue < g_MaxValue)
        g_GripperValue = g_GripperValue + 2;
      ServoGripper.write(g_GripperValue);
    }
    else if(incomingByte == 'k')
    {
      if(g_GripperValue > g_MinValue)
        g_GripperValue = g_GripperValue - 2;
      ServoGripper.write(g_GripperValue);
    }
    else if(incomingByte == 'l')
    {
      if(g_VertValue < g_MaxValue)
        g_VertValue = g_VertValue + 2;
      ServoArm2.write(g_VertValue);
    }
    else if(incomingByte == 'j')
    {
      if(g_VertValue > g_MinValue)
        g_VertValue = g_VertValue - 2;
      ServoArm2.write(g_VertValue);
    }

    Serial.print("Base: ");
    Serial.print(g_BaseValue);
    Serial.print("Horizontal: ");
    Serial.print(g_HorizValue);
    Serial.print("Gripper: ");
    Serial.print(g_GripperValue);
    Serial.print("Vertical: ");
    Serial.println(g_VertValue);

    //delay(5);                           // waits for the servo to get there
  }
}
