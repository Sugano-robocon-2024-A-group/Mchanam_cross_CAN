#include <Arduino.h>
#include "auto.hpp"
#include "motor.hpp"
#include "PS4cross.hpp"
#include "tuushin.h"
//sendToutekiCommand(PS4_Circle, PS4_Triangle, PS4_R1, PS4_L1);//先に送る

bool movementComplete = true;

void moveMecanumAuto()
{
  Serial.println("Jidou");
  if (movementComplete)
  {
    return; // 移動完了したら停止
  }
  Serial.println("Unten");

  // 左方向
  targetDistance[0] = -speed[0];
  targetDistance[1] = speed[1];
  targetDistance[2] = speed[2];
  targetDistance[3] = -speed[3];

  for (int i = 0; i < 4; i++)
  {
    // 制御信号に基づいてモーターを駆動
    driveMotor(i, targetDistance[i]);
  }
  delay(1000);//この値を変えて進む距離を決める

  stopMotors();// 現在の移動を停止
  delay(1000);

  // 前方向
  targetDistance[0] = speed[0];
  targetDistance[1] = speed[1];
  targetDistance[2] = speed[2];
  targetDistance[3] = speed[3];

  for (int i = 0; i < 4; i++)
  {
    // 制御信号に基づいてモーターを駆動
    driveMotor(i, targetDistance[i]);
  }
  delay(1000); //この値を変えて進む距離を決める

  stopMotors(); // 現在の移動を停止
  delay(1000);
  
  // 前方向の移動も完了した場合、全移動完了
  movementComplete = true;
}