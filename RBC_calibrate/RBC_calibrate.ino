// Both Colour sensors
#define S0 13
#define S1 3

// Right Colour sensor
#define S2R 5
#define S3R 6
#define sensorOutR 4
#define OER 2

// Left Colour sensor
#define S2L 7
#define S3L 8
#define sensorOutL 9 
#define OEL 12

// Type definitions
typedef struct RGBC_s {
  float R;
  float G;
  float B;
  float C;
} RGBC;
typedef bool (*funcArray)(float red,float green,float blue);

// Declaring fucntions
RGBC colour_readR();
RGBC colour_readL();

// Initialising variables
float thresh[2][4]={{48.5,51.5,55.5,61.5},{54.5,50.5,56.5,72}}; //Threshold values corresponding to testfreqs[]. Is threshold between 'sensor is too dark' and 'sensor is too light'.
float range[2][4]={{57,67,73,85},{65,69,73,102}}; //Range values corresponding to testfreqs[]. Is range of expected colour values.

void setup() {
   //pinMode(LED_BUILTIN, OUTPUT);
   
   // Colour sensor set up
   pinMode(S0, OUTPUT);
   pinMode(S1, OUTPUT);
  
   pinMode(S2R, OUTPUT);
   pinMode(S3R, OUTPUT);
   pinMode(sensorOutR, INPUT);
   pinMode(OER, OUTPUT);
   digitalWrite(OER,HIGH);
   pinMode(S2L, OUTPUT);
   pinMode(S3L, OUTPUT);
   pinMode(sensorOutL, INPUT);
   pinMode(OEL, OUTPUT);
   digitalWrite(OEL,LOW);
   
   // Setting frequency-scaling to 20%
   digitalWrite(S0,HIGH);
   digitalWrite(S1,LOW);

   Serial.begin(9600);
    
}

void loop() {
    RGBC freqL = colour_readL();
    RGBC freqR = colour_readR();

    delay(100);

    /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);*/
    
    Serial.print(freqL.R);
    Serial.print("\t");
    Serial.print(freqL.G);
    Serial.print("\t");
    Serial.print(freqL.B);
    Serial.print("\t");
    Serial.print(freqL.C);
    Serial.print("\n");

}
