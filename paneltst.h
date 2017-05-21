//#ifndef Panel_h
#define Panel_h
#include <Filters.h>
#include <Hall.h>
#include <Arduino.h>
#include <ArduinoJson.h>

#define cmd_motor 0x01
#define cmd_motdone 0x04
#define setM 0x02
#define power 0x03
#define Pi1 A0
#define Pi2 A1
#define Pi3 A2
#define Pi4 A3
#define Pi5 A4


struct frame{
  uint8_t command;
  uint8_t param[4];
};
bool Movemotor(frame& nam,int pin){
    uint8_t position =nam.param[2];
    if (position==0x64){
      analogWrite(pin,255);
    }
    else if(position==0x32){
      analogWrite(pin,255/2);
    }
    nam.command=cmd_motdone;
    return true;
  };
bool setMotor(frame& nam,int pin){
  analogWrite(pin,0);
  nam.command=cmd_motdone;
  return true;
};
JsonObject& askPower(frame& nu,frame& nam){
  float currnt1=Askforit(A0);
  StaticJsonBuffer<200> jsonBuffer;
  //uint8_t currnt2=Askforit(A1);
  //uint8_t currnt3=Askforit(A2);
  //uint8_t currnt=Askforit(A3);
  //uint8_t Volta=Askforit(A4);
  //uint8_t currnt1=1;
  //uint8_t currnt2=0;
  //uint8_t currnt3=0;
  //uint8_t currnt=0;
  //uint8_t Volta=0;
  //String jon=
  //  "{\"Panel\":\"1\",\"corriente 1\":";
  //String son= jon+currnt1+'}';

  //char json[]="";
  //son.toCharArray(json, 8);
  char json[] =
      "{\"Panel\":\"1\",\"Corriente\":\"A}";
  JsonObject& root = jsonBuffer.parseObject(json);

  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root["time"].as<long>();
  float currnt1 = root["sensor"];


};
