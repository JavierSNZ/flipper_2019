#ifndef SENSOR_H
#define SENSOR_H


#include <string>

//Dans les.h, il est recommandé de ne jamais mettre la directiveusing namespace std;car cela pourrait avoir des effets néfastes, par la suite, lorsque vous utiliserez la classe.
//Par conséquent, il faut rajouter le préfixestd::devant chaquestringdu.h. Sinon, le compilateur vous sortira une erreur du typestring does not name a type Ex: std::string m_nomArme;

class Sensor

{
    public:
        Sensor();
        void irSensorInit();
        int getValueIrSensor();
    private:
        float vIrSensor;
        float k = 3.3/1024;

};

#endif // SENSOR_H
