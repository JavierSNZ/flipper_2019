#include "Game.h"
#include "Player.h"
#include "sensor.h"

#include <iostream>
#include <wiringPi.h>


using namespace std;
//write gpio readall to see pin disposition in xterminal

Game::Game()
{
    cout<<"Game initialising..."<<endl;
    gpioInit();     //Set Gpio numbering
    Sensor sensor;
    sensor.irSensorInit();
    Player player;   //Set player's ball number
    launchBall();       //LaunchBall
    ballLossMonitoring();
}

int Game::launchBall()
{
	pinMode(BallLauncher, OUTPUT);
	digitalWrite(BallLauncher, HIGH);
	delay(1000);
	digitalWrite(BallLauncher, LOW);
	cout<<"Ball launched"<<endl;
	return 0;
}
int Game::gpioInit()
{
    if(wiringPiSetupPhys()<0){              //Set Gpio numbering
        cout<<"Setup wiringPi failed"<<endl;
        return 1;
    }
}
void Game::ballLossMonitoring()
{
    int i = 1;
    while(i == 1){
        cout<<sensor.getValueIrSensor()<<endl;
        cout<<player.getBallNumber()<<endl;
        if(sensor.getValueIrSensor() > 690)
        {
            player.setBallNumber(player.getBallNumber() -1);
            if(player.getBallNumber() == 0) //Stop if no balls is left
            {
                i = 0;
            }
            else
            {
                launchBall();
                delay(1000);    //1 second pause
            }
        }
    }
}
