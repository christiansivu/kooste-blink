// MUutujien määrittäminen
#define NayttoON1 4
#define NayttoON2 5
#define NayttoA 10
#define NayttoB 11
#define NayttoC 12
#define NayttoD 13
#define ON HIGH
#define OFF LOW

// Alku setuppi
void setup()
{
  pinMode ( NayttoON1, OUTPUT );
  pinMode ( NayttoON2, OUTPUT );
  pinMode ( NayttoA, OUTPUT );
  pinMode ( NayttoB, OUTPUT );
  pinMode ( NayttoC, OUTPUT );
  pinMode ( NayttoD, OUTPUT );
}

void showNum(int x){
  switch( x ){
    case 2:
      digitalWrite ( NayttoA, OFF );
      digitalWrite ( NayttoB, ON );
      digitalWrite ( NayttoC, OFF );
      digitalWrite ( NayttoD, OFF );
      break;
    case 4:
      digitalWrite ( NayttoA, OFF );
      digitalWrite ( NayttoB, OFF );
      digitalWrite ( NayttoC, ON );
    digitalWrite ( NayttoD, OFF );
    break;
  }
}
void showTens(){
  digitalWrite ( NayttoON1, ON );
  digitalWrite ( NayttoON2, OFF );
}
void showOnes(){
  digitalWrite ( NayttoON1, OFF );
  digitalWrite ( NayttoON2, ON );
}
int y = 0;

void toggle(){
y++;
  if(y <= 50){
    
  
  
  showTens();
  showNum(2);
  delay(20);
  showOnes();
  showNum(4);
  delay(20);
  }
 
  if(y >= 50){
    
  
  
  showTens();
  showNum(4);
  delay(20);
  showOnes();
  showNum(2);
  delay(20);
  }
  if (y>100){
  y = 0;
  }
}

const int interval = 1000;
unsigned long vanhaAika = 0;

void vilkku(){
  unsigned long uusiAika = millis();
  if(( uusiAika - vanhaAika ) >= interval){
    vanhaAika = vanhaAika + interval;
    toggle();
  }
}
void loop()
{
  toggle();
  vilkku();
}
