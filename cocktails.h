#define pumpGin 5
#define pumpVodka 6
#define pumpLemon 7
#define pumpTonic 8
#define pumpAperol 9
#define pumpProsecco 10
#define pumpJager 11
#define pumpMonster 12
// tempo in millisecondi che dovrebbe metterci in totale un bicchiere a riempirsi
#define glassUnityTime 10000

#include "Arduino.h"

extern bool delivery;

void GinLemon ();
void GinTonic ();
void VodkaTonic ();
void VodkaLemon ();
void JagerBomb ();
void Spritz ();
void VodkaRedbull ();
void inizialize_pomp();

