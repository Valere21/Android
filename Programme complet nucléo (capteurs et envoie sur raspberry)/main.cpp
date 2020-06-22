#include <stdbool.h>
#include "mbed.h"
#include "SRF08.h"

RawSerial pc(USBTX, USBRX, 115200);                                  // Pour débug sur pc

RawSerial envoie(D1, D0, 115200);
AnalogIn analog_value(A0);
AnalogIn analog_value2(A1);
DigitalOut sortie(D12);


int main()
{
    int i2cAddress=0xE0;                                            // Adresse du capteur ultrason
    SRF08 srf(D4, D5, i2cAddress);
    char str[20];
    char str2[20];
    int dist;
    int dif=0;
    int valLux;
    int valUl;
    float analog;
    float analog2;

    srf.setRangeRegister(0xFF);                                     // Valeur par défault du capteur ultrason remit au démarrage
    srf.setMaxGainRegister(0x08);                                   // Le gain à 8 réduit la portée pratique à environ 2 m, mais ler capteur sera beaucoup moins sensible aux objets hors de la ligne centrale
    srf.startRanging();

    while(1) {

        analog = analog_value.read();                               // Lis les valeurs d'entrée analogique
        analog2 = analog_value2.read();

        if (analog < 0.2 && analog2 < 0.2) {                        // Capteur 1 et 2 doit être inférieur à 660mV
            valLux = 0;
            sortie = 0;                                             // Eteins la led
            wait(0.1);
        }

        if (analog > 0.4 && analog2 > 0.4) {                        // Capteur 1 et 2 doit être supérieur à 1.32V
            valLux = 1;
            sortie = 1;                                             // Allume la led
            wait(0.1);
        }

        if (srf.rangingFinished()) {                                // Si sfr à fini, alors dist obtiens la valeur de srf et la fonction est relancé
            dist = srf.getRange();
            srf.startRanging();
        }

        if(dif==0) {
            dif = dist;                                              // Récupération de la valeur d'origine au lancement du programme pour l'ultrason
        }

        if (dist <= dif-10 || dist >= dif+10) {                      // Plus ou moins 10 cm de la valeur d'origine
            valUl = 1;
            sprintf(str, "%d cm enregistre / detection!\n\r", dif);  // Débug pour USB
            pc.puts(str);
            wait(0.1);

        } else {
            valUl = 0;
            sprintf(str, "%d cm en sortie\n\r", dist);               // Débug pour USB
            pc.puts(str);
            wait(0.1);
        }
        
        if (valLux == 0 && valUl == 0) {                            // Si les 2 type de capteurs ne détecte rien alors on envoie 0
            envoie.puts("0\n");
        }
        if (valLux == 1 && valUl == 0) {                            // Si le capteur de lumière détecte quelque chose mais que le capteur ultrason ne détecte rien alors on envoie 1
            envoie.puts("1\n");
        }
        if (valLux == 0 && valUl == 1) {                            // Si le capteur de lumière ne détecte rien mais que le capteur ultrason détecte quelque chose alors on envoie 2
            envoie.puts("2\n");
        }
        if (valLux == 1 && valUl == 1) {                            // Si les 2 type de capteurs détecte quelque chose alors on envoie 3
            envoie.puts("3\n");
        }
    }
}
