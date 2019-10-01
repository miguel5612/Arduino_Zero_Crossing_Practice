int pulse = 60; //led 1 second 1, 1 second off
int pulCounted = 0;
const int LEDPin = 13;
const int btnUp = 3;
const int btnDown = 4;
const int ZCPin = 2;

void setup(){
    //PIn setup
    pinMode(LEDPin, OUTPUT);
    pinMode(btnUp, INPUT_PULLUP);
    pinMode(btnDown, INPUT_PULLUP);
    //Default state
    digitalWrite(LEDPin, LOW);
    //Serial setup
    Serial.begin(9600);
    //Interrupt
     attachInterrupt(digitalPinToInterrupt(ZCPin), detectarPulsos, RISING);
    //Serial msg
    Serial.println("Setup OK"); 
}
void loop(){
    //Program condition
    if(pulCounted > pulse)
    {
        digitalWrite(LEDPin, HIGH);
        Serial.println("He contado: " + String(pulCounted) + " Pulsos");
    }
    else
    {
        digitalWrite(LEDPin, LOW);
    }
    if(!digitalRead(btnUp))
    {
        Serial.println("Incrementando la variable, pulse:" + String(pulse));
        pulse++;
        pulCounted = 0; //Resetting variable
        delay(500);
    }
    if(!digitalRead(btnDown))
    {
        Serial.println("Decrementando la variable, pulse:" + String(pulse));
        pulse--;
        pulCounted = 0; //Resetting variable
        delay(500);
    }
}

void detectarPulsos(){ 
  pulCounted++;
}
