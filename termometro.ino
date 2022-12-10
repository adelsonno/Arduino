// inclusione della libreria LiquidCrystal.h
#include <LiquidCrystal.h>
#include <math.h>
// inizializza la libreria con i numeri dei pin dell'interfaccia
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//------------------------------------------
//sensore di temperatura ky-013

int ThermistorPin = A1;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

//-----------------------


void setup() {
  // impostazione del numero di colonne e righe del display
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Posiziona il cursore in colonna 0 e riga 0
  lcd.setCursor(0, 0);
  // Stampa il messaggio
  lcd.print("Termometro");
}

void loop() {
  // Posiziona il cursore in colonna 0 e riga 0
  lcd.setCursor(0, 1);

    //codice sensore temperatura---------------------
    Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
    T = T - 273.15; //convert Kelvin to Celcius
    //-------------------------------------------------
  Serial.println(T);
    lcd.print("T ");
    lcd.print(T);
 
}
