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
    int detect;
    int detect2;
    float analog;
    float analog2;

    srf.setRangeRegister(0xFF);                                     // Valeur par défault du capteur ultrason remit au démarrage
    srf.setMaxGainRegister(0x08);                                   // Le gain à 8 réduit la portée pratique à environ 2 m, mais ler capteur sera beaucoup moins sensible aux objets hors de la ligne centrale
    srf.startRanging();

    while(1) {

        analog = analog_value.read();                               // Lis les valeurs d'entrée analogique
        analog2 = analog_value2.read();

        if (analog < 0.2 && analog2 < 0.2) {                        // Capteur 1 et 2 doit être inférieur à 660mV
            sortie = 0;                                             // Eteins la led
            detect2 = 0;                                            // Met la valeur à 0
            sprintf(str2, "lumiere:%d\0", detect2);                   // Envoie sur la raspberry "lumière:" ainsi que la valeur 0
            envoie.puts(str2);
            wait(0.2);                                            
        }

        if (analog > 0.4 && analog2 > 0.4) {                        // Capteur 1 et 2 doit être supérieur à 1.32V

            sortie = 1;                                             // Allume la led
            detect2 = 1;                                            // Met la valeur à 1
            sprintf(str2, "lumiere:%d\0", detect2);
            envoie.puts(str2);                                      // Envoie sur la raspberry "lumière:" ainsi que la valeur 1

            wait(0.2);                                             
        }

        if (srf.rangingFinished()) {

            dist = srf.getRange();
            sprintf(str, "%d cm en sortie\n\r", dist);              // Débug pour USB
            pc.puts(str);
            srf.startRanging();                                     // Re-start de la fonction pour la prochaine valeur
            detect = 0;
            sprintf(str, "ultrason:%d\0", detect);                  // Envoie sur la raspberry "ultrason:" ainsi que la valeur 0
            envoie.puts(str);
            wait(0.2);


        }

        if(dif==0) {
            dif = dist;                                              // Récupération de la valeur d'origine au lancement du programme
        }

        if (dist <= dif-10 || dist >= dif+10) {                      // Plus ou moins 10 cm de la valeur d'origine

            sprintf(str, "%d cm enregistre / detection!\n\r", dif);  // Débug pour USB
            pc.puts(str);
            detect = 1;
            sprintf(str, "ultrason:%d\0", detect);                   // Envoie sur la raspberry "ultrason:" ainsi que la valeur 1
            envoie.puts(str);
            wait(0.2);

        }
    }
}
