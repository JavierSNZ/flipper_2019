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
    ballLossMonitoring();
}

int Game::launchBall()
{
    if(player.getBallNumber() == 0) //Stop if no balls is left
    {
        return 1;
    }
    else
    {
        delay(1000);
        digitalWrite(BallLauncher, HIGH);
        delay(50);
        digitalWrite(BallLauncher, LOW);
        cout<<"Ball launched"<<endl;
        player.setBallNumber(player.getBallNumber() -1);
        return 0;
    }
}
int Game::gpioInit()
{
    if(wiringPiSetupPhys()<0){              //Set Gpio numbering
        cout<<"Setup wiringPi failed"<<endl;
        return 1;
    }
    pinMode(BallLauncher, OUTPUT);
	digitalWrite(BallLauncher, LOW);
}
void Game::ballLossMonitoring()
{
    int j =0;
    while(1){
       // cout<<sensor.getValueIrSensor()<<endl;
        cout<<player.getBallNumber()<<endl;
        if(sensor.getValueIrSensor() < 830)
        {
            j = launchBall();//1 second pause
            if(j == 1)
                break;
        }
    }
}
