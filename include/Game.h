#ifndef GAME_H
#define GAME_H

#include "sensor.h"
#include "Player.h"


#include <iostream>
#include <wiringPi.h>


class Game{

public:
//Variable Declaration
	Game();
	int launchBall();
	int gpioInit();
	void ballLossMonitoring();
	//Everyone has access to these data
private:
	int BallLauncher = 40;	//Only this class has access
	Sensor sensor;
    Player player;
};

#endif // GAME_H
