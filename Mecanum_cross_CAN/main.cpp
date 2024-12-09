#include <Arduino.h>
#include <PS4Controller.h>
#include "motor.hpp"
#include "PS4cross.hpp"

int speed = 255;  // (0~255)
int Ashimawari_Command=0;

void setup()
{
  setupMotors();
  stopMotors();

  Serial.begin(115200);
  PS4.begin("1c:69:20:e6:20:d2");
  Serial.println("Ready.");
}

void loop()
{
  Ashimawari_Command=0;
  if (PS4.Right()){Ashimawari_Command=3;
      }
      if (PS4.Down()){Ashimawari_Command=2;
      }
      if (PS4.Up()){Ashimawari_Command=1;
      }
      if (PS4.Left()){Ashimawari_Command=4;
      }
      if (PS4.UpRight()){Ashimawari_Command=5;
      }
      if (PS4.DownRight()){Ashimawari_Command=6;
      }
      if (PS4.UpLeft()){Ashimawari_Command=7;
      }
      if (PS4.DownLeft()){Ashimawari_Command=8;
      }
  PS4Cross(speed, Ashimawari_Command);
  for (int i = 0; i < 4; i++)
  {
    driveMotor(i, targetDistance[i]);
  }
}
