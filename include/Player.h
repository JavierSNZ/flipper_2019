#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        void addBall();
        int getBallNumber();
        void setBallNumber(int ballNumber);

    protected:

    private:
        int ball;
};

#endif // PLAYER_H
