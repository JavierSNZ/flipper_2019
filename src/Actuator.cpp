#include "Actuator.h"

#include <iostream>
#include <wiringPi.h>


using namespace std;
Actuator::Actuator()
{

}
int Actuator::launchBall()
{
	pinMode(BallLauncher, OUTPUT);
	digitalWrite(BallLauncher, HIGH);
	delay(100);
	digitalWrite(BallLauncher, LOW);
	cout<<"Ball launched"<<endl;
}
