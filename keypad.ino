#include <Keypad.h>
#include "pitches.h"
const byte ROWS=4;
const byte COLS=4;
int duration=200;
const byte Buzzer=13;
const int rhythm=500;
char index;
int SoundLeng;
char song_tone;
char ch;
char keys[ROWS][COLS]={
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[ROWS]={7,8,9,10};
byte colPins[COLS]={3,4,5,6};
int
pitch[]={0,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,
NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};

float song[] = {5,0.5, 1+7,0.5, 2+7,0.5, 3+7,0.5, 2+7,0.5, 3+7,0.5,
 4+7,0.5, 5+7,0.5, 5+7,0.5, 5+7,0.5, 4+7,0.5,
3+7,0.5,
 2+7,0.5, 2+7,1, 0,0.5, 5,0.5, 1+7,0.5, 2+7,0.5,
3+7,0.5,
 2+7,0.5, 3+7,0.5, 4+7,0.5, 5+7,0.5, 5+7,0.5,
5+7,0.5,
 6+7,0.5, 5+7,1, 2+7,0.5, 3+7,0.5, 1+7,1, 1+7,0.5,
6,0.5,
 2+7,0.5, 2+7,0.5, 3+7,0.5, 3+7,0.5, 1+7,1, 5+7,0.5,
 1+7,0.5, 5,0.5, 1+7,0.5, 7,0.5, 1+7,0.5, 0,1,
1+7,0.5,
 6,0.5, 2+7,0.5, 2+7,0.5, 3+7,0.5, 3+7,0.5, 4+7,0.5,
4+7,0.5,
 4+7,0.5, 3+7,0.5, 2+7,0.5, 1+7,0.5, 1+7,1, -1};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS,
COLS);

void setup() {
 pinMode(Buzzer,OUTPUT);
 Serial.begin(9600);
}
void loop() {
 char key = keypad.getKey();
 if(key!=NO_KEY){
 switch(key){
 case '0':
 tone(Buzzer,NOTE_B5,duration);
 break;
 case '1':
 tone(Buzzer,NOTE_C4,duration);
 break;
 case '2':
 tone(Buzzer,NOTE_D4,duration);
 break;
 case '3':
 tone(Buzzer,NOTE_E4,duration);
 break;
 case '4':
 tone(Buzzer,NOTE_F4,duration);
 break;
 case '5':
 tone(Buzzer,NOTE_G4,duration);
 break;
 case '6':
 tone(Buzzer,NOTE_A4,duration);
 break;
 case '7':
 tone(Buzzer,NOTE_B4,duration);
 break;
 case '8':
 tone(Buzzer,NOTE_C5,duration);
 break;
 case '9':
 tone(Buzzer,NOTE_D5,duration);
 break;
 case 'A':
 tone(Buzzer,NOTE_E5,duration);
 break;
 case 'B':
 tone(Buzzer,NOTE_F5,duration);
 break;
 case 'C':
 tone(Buzzer,NOTE_G5,duration);
 break;
 case 'D':
 tone(Buzzer,NOTE_A5,duration);
 break;
 case 'E':
 tone(Buzzer,NOTE_B5,duration);
 break;
 case 'F':
 tone(Buzzer,NOTE_B5,duration);
 break;
 }
 }

 if(Serial.read()=='S')
 {
 ch=Serial.read();
 Serial.println("Sing");
 index=0;
 while (1) {
 song_tone = char(song[index]);
 index++;
 SoundLeng = int(song[index]*rhythm);
 index++;
 if (song_tone==-1)
 break;
 else if (song_tone==0)
 delay(SoundLeng*1.3);
 else {
 tone(Buzzer, pitch[song_tone], SoundLeng);
 delay(SoundLeng*1.3);
 }
 }
 }
}
