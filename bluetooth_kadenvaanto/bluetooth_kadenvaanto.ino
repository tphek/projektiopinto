/* Vastaanottaa komennon bluetoothin välityksellä terminaalilta
** ja sytyttää / sammmuttaa ledin.
** Lähettää int muuttujan terminaalille.
** 
*/

int ledPin = 13;                        // use the built in LED on pin 13 of the Uno
int state = 0;
int flag = 0;                           // make sure that you return the state only once
int luku = 32767;                       // muuttuja (kädenväännön tulos), joka lähetetään bluetoothin välityksellä

void alusta_bluetooth() {
  
    // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    Serial.begin(9600);                 // Default connection rate for my BT module
    
}

void lue_bluetooth() {
  
    // if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();            // lukee sarjaportista dataa state -muuttujaan
      flag=0;
    }
    
    // jos luettu data on '0', ledi sammutetaan
    if (state == '0') {
        digitalWrite(ledPin, LOW);
        if(flag == 0){
          Serial.println("LED: off \n");
          flag = 1;
        }
    }
    
    // jos luettu data on '1', ledi sytytetään
    else if (state == '1') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          Serial.println("LED: on \n");
          Serial.print(luku, DEC);      // kirjoitetaan muuttuja sarjaporttiin
          Serial.println("\n");
          flag = 1;
        }
    }
}

void setup() {
    alusta_bluetooth();
}

void loop() {
    lue_bluetooth();
}
