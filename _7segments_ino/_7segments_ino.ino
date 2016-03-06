/* On assigne chaque LED à une broche de l'arduino */
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
//notez que l'on ne gère pas l'affichage du point, mais vous pouvez le rajouter si cela vous chante
 
const int button = 11; 
 
int buttonState; 
 
int i = 0;

int incr = 1;
 
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
    
    pinMode(button, INPUT);
    
    
    //mise à l'état HAUT de ces sorties pour éteindre les LED de l'afficheur
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    
    digitalWrite(button, HIGH);
}

void loop()
{
   buttonState = digitalRead(button);
   if(buttonState == LOW){
     incr = - incr;
     Serial.println("pushed");
   }
  
   print(i);
   
   i += incr;
   if(i == 10 && incr == 1){
     i = 0;
   } else if (i == -1 && incr -1){
     i = 9; 
   }
   delay(500);
}
