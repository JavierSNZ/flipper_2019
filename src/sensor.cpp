#include "sensor.h"

#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define SPI_CHAN 0
#define MY_PIN 12345

using namespace std;

Sensor::Sensor()
{
}

void Sensor::irSensorInit()
{
    wiringPiSetup();
    mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels
//    while(true)
 //   {
   //     cout<<"Distance:"<< vIrSensor << endl;
  //  }
}
int Sensor::getValueIrSensor()
{
    vIrSensor = analogRead (MY_PIN);
    //vIrSensor = vIrSensor * k;
    return vIrSensor;
}
