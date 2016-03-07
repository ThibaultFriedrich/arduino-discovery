/* On assigne chaque LED à une broche de l'arduino */
const int A = 9;
const int B = 10;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
//notez que l'on ne gère pas l'affichage du point, mais vous pouvez le rajouter si cela vous chante
 
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 20;
volatile long humanValue = 5;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;
 

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
 
 
void print(int number){
    digitalWrite(A, tab[number][0]);
    digitalWrite(B, tab[number][1]);
    digitalWrite(C, tab[number][2]);
    digitalWrite(D, tab[number][3]);
    digitalWrite(E, tab[number][4]);
    digitalWrite(F, tab[number][5]);
    digitalWrite(G, tab[number][6]);
}


void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue --;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue ++;
  
  humanValue = encoderValue/4;

  lastEncoded = encoded; //store this value for next time
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
     
    
    //mise à l'état HAUT de ces sorties pour éteindre les LED de l'afficheur
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop()
{
  
  if(humanValue > 9){
      print(9);  
  } else if(humanValue < 0){
      print(0);
  } else {
      print(humanValue);
  }  

   delay(1000);
}
