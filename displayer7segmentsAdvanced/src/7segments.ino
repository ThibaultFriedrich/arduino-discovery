
/**

* 7 220 ohms
* 1 10k ohms
* 7 segments displayer
* 1 LDR

*/

// https://learn.adafruit.com/photocells/using-a-photocell
// https://www.arduino.cc/en/Tutorial/Calibration
// http://forum.arduino.cc/index.php?topic=141815.0

const int A = 6;
const int B = 12;
const int C = 11;
const int D = 10;
const int E = 9;
const int F = 8;
const int G = 7;

const long photoCellInput = 0;

long voltageOut = 0;

double lux = 0;

/*
Ambient light like…	Ambient light (lux)	Photocell resistance (Ω)	LDR + R (Ω)	Current thru LDR +R	Voltage across R
Dim hallway	0.1 lux	600KΩ	610 KΩ	0.008 mA	0.1 V
Moonlit night	1 lux	70 KΩ	80 KΩ	0.07 mA	0.6 V
Dark room	10 lux	10 KΩ	20 KΩ	0.25 mA	2.5 V
Dark overcast day / Bright room	100 lux	1.5 KΩ	11.5 KΩ	0.43 mA	4.3 V
Overcast day	1000 lux	300 Ω	10.03 KΩ	0.5 mA	5V
*/

/*
	0.1 600000
  1	70000
  10	10000
  100	1500
  1000 	300

  -->

  y = 1.819668322*10-15 x4 - 1.240358101*10-9 x3 + 9.064697525*10-5 x2 - 0.90973421 x + 1264.808051
*/

int tab[10][7] = {
   {LOW, LOW, LOW, LOW, LOW, LOW, HIGH}, // write 0
   {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // write 1
   {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW}, //write 2
   {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW}, //write 3
   {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW}, //write 4
   {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW}, //write 5
   {LOW, HIGH, LOW, LOW, LOW, LOW, LOW}, //write 6
   {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, //write 7
   {LOW, LOW, LOW, LOW, LOW, LOW, LOW}, //write 8
   {LOW, LOW, LOW, LOW, HIGH, LOW, LOW} //write 9
};

int i = 0;

int photoCellValue = 0;
int numberToDisplay = 0;
int photoCellResistance = 0;

void displayNumber(int number){
    if(number >= 0 && number <= 9){
      digitalWrite(A, tab[number][0]);
      digitalWrite(B, tab[number][1]);
      digitalWrite(C, tab[number][2]);
      digitalWrite(D, tab[number][3]);
      digitalWrite(E, tab[number][4]);
      digitalWrite(F, tab[number][5]);
      digitalWrite(G, tab[number][6]);
    }
}

void setup()
{
    Serial.begin(9600);

    //définition des broches en sortie
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);

    pinMode(photoCellInput, INPUT);

    //mise à l'état HAUT de ces sorties pour éteindre les LED de l'afficheur
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}


void loop()
{
  // min 0
  // max 1023
  photoCellValue = analogRead(photoCellInput);
  photoCellValue = 1023 - photoCellValue;

  numberToDisplay = map(photoCellValue, 0, 1024, 9, 0);

  displayNumber(numberToDisplay);
  Serial.print("Number to display = ");
  Serial.println(numberToDisplay);     // the raw analog reading
  delay(1000);
}
