#include "Game.h"
#include "Player.h"
#include "sensor.h"
#include "Sound.h"


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
    Sound sound;
    cout<<"Sound init done"<<endl;
    while(true){
        if(digitalRead(StartGameBtn) == false)
        {
            cout<<"Set player ball number to 3"<<endl;
            player.setBallNumber(3);
            cout<<player.getBallNumber()<<endl;
            sound.play_begin();
            ballLossMonitoring();
        }
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
    pinMode(StartGameBtn, INPUT);
	pullUpDnControl(StartGameBtn, PUD_DOWN);   //Set PullDown internal resitor 50kohm
}

int Game::launchBall()
{
    if(player.getBallNumber() == 0) //Stop if no balls is left
    {
        return 1;
    }
    else
    {
        sound.play_newBall();
        delay(1000);
        digitalWrite(BallLauncher, HIGH);
        delay(50);
        digitalWrite(BallLauncher, LOW);
        cout<<"Ball launched"<<endl;
        player.setBallNumber(player.getBallNumber() -1);
        delay(200);
        return 0;
    }
}
void Game::ballLossMonitoring()
{
    int j = 0;
    sound.play_fond();
    while(1){
       cout<<sensor.getValueIrSensor()<<endl;
        cout<<player.getBallNumber()<<endl;
        if(sensor.getValueIrSensor() < 830)
        {
            j = launchBall();//1 second pause
            if(j == 1)
                break;
        }
    }
}
