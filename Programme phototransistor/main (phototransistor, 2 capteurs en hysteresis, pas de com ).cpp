#include "mbed.h"

AnalogIn analog_value(A0);
AnalogIn analog_value2(A1);
DigitalOut sortie(D1);


int main()
{
    float analog;
    float analog2;


    while(1) {

        analog = analog_value.read();           // Lis les valeurs d'entrée analogique
        analog2 = analog_value2.read();

        if (analog < 0.2 && analog2 < 0.2) {    // Capteur 1 et 2 doit être inférieur 660mV pour éteindre la sortie
            sortie = 0;                         // Envoie 0
        }

        if (analog > 0.4 && analog2 > 0.4) {    // Capteur 1 et 2 doit être supérieur 1.32V pour allumer la sortie
            sortie = 1;                         // Envoie 1


            wait(0.4);                          // 400 ms
        }
    }
}
