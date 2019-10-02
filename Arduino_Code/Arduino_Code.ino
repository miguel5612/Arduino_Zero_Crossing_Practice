int pulse = 600; //led 1 second 1, 1 second off
int tmpFrq = 0;
int frecuencia = 0;

int pulCounted = 0;
const int LEDPin = 13;
const int btnUp = 3;
const int btnDown = 4;
const int ZCPin = 2;

unsigned long lastMeasure = 0;
unsigned long setupTime = 0;
unsigned long flagTime = 0;

bool pulsosPorSegundo = false;

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
        if(flagTime == 0) flagTime = millis();
        digitalWrite(LEDPin, HIGH);
        Serial.println("Por segundo son: " + String(frecuencia) + " Pulsos");
        Serial.println("He contado: " + String(pulCounted) + " Pulsos");
        Serial.println("Han pasado " + String((flagTime-setupTime)) + " milisegundos antes de llegar al limite impuesto");
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
  if(millis()-lastMeasure>1000){
      lastMeasure = millis();
      frecuencia = tmpFrq;
      tmpFrq = 0;
  }
  if(setupTime == 0) setupTime =  millis();
  pulCounted++;
  tmpFrq++;
}
