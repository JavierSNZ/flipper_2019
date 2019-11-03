#include "Player.h"

Player::Player()
{
    ball = 0;
}

void Player::addBall()
{
    ball = ball+1;
}
int Player::getBallNumber()
{
    return ball;
}
void Player::setBallNumber(int ballNumber)
{
    ball = ballNumber;
}
