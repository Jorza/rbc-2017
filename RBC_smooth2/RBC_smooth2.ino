// Defining inputs
#define ENA_PWM 10 // Turning on motor 1
#define IN1 A0
#define IN2 A1 // Power of wheels for 1
#define ENB_PWM 10 // Turning on motor 2
#define IN3 A3
#define IN4 A4 // Power of wheels for 2

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
bool LisRed(float red,float green,float blue);
bool LisGreen(float red,float green,float blue);
bool LisBlue(float red,float green,float blue);
bool LisClear(float red,float green,float blue);
bool RisRed(float red,float green,float blue);
bool RisGreen(float red,float green,float blue);
bool RisBlue(float red,float green,float blue);
bool RisClear(float red,float green,float blue);
void drive(float power,bool dir,float mod);

// Initialising variables
int followCol=0; //Start following red
int followSide=0; //Start following on left side of line
float thresh[2][4]={{48.5,51.5,55.5,61.5},{54.5,50.5,56.5,72}}; //Threshold values corresponding to testfreqs[]. Is threshold between 'sensor is too dark' and 'sensor is too light'.
float range[2][4]={{57,67,73,85},{65,69,73,102}}; //Range values corresponding to testfreqs[]. Is range of expected colour values.
float gain=512;
float power=100;
float mod=0;
float negpos=0;
bool dir=HIGH;
float tole=3;
funcArray isColour[2][4]={{LisRed,LisGreen,LisBlue,LisClear},{RisRed,RisGreen,RisBlue,RisClear}};

void setup() {
  // Motor set up
	// The parameter 9600 is the baud rate of the serial communication channel.
	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(ENA_PWM, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB_PWM, OUTPUT);
 
   // Colour sensor set up
   pinMode(S0, OUTPUT);
   pinMode(S1, OUTPUT);
  
   pinMode(S2R, OUTPUT);
   pinMode(S3R, OUTPUT);
   pinMode(sensorOutR, INPUT);
   pinMode(OER, OUTPUT);
   digitalWrite(OER,LOW);
   pinMode(S2L, OUTPUT);
   pinMode(S3L, OUTPUT);
   pinMode(sensorOutL, INPUT);
   pinMode(OEL, OUTPUT);
   digitalWrite(OEL,LOW);
   
   // Setting frequency-scaling to 20%
   digitalWrite(S0,HIGH);
   digitalWrite(S1,LOW);
    
}

void loop() {
    RGBC freqL = colour_readL();
    RGBC freqR = colour_readR();
    
    //Gives list of colours in order. Used to pass values to isColour
    float allfreqs[2][4]={{freqL.R,freqL.G,freqL.B,freqL.C},{freqR.R,freqR.G,freqR.B,freqR.C}};
    
    //Has i and j corresponding to the colour to track, when the colour is as given in allfreqs[i,j]
    float testfreqs[2][4]={{freqL.G,freqL.R,freqL.R,freqL.G},{freqR.G,freqR.R,freqR.R,freqR.G}};
    // When on red (followCol=0), track green.
    // When on green or blue (followCol=1 or 2), track red.
    // On black lines (followCol=3), track green.
    
    
    /*// Tests for new colour
    for(int i=0;i<2;i++){
      for(int j=0;j<3;j++){
        if (isColour[i][j](allfreqs[i][0],allfreqs[i][1],allfreqs[i][2]) && followSide!=i %% followCol!=j) {
          followSide=i;
          followCol=j;
        }
      }
    }*/

   // Tests for black, skip over until finds red again
   if (isColour[followSide][3](allfreqs[followSide][0],allfreqs[followSide][1],allfreqs[followSide][2])) {
     while (!isColour[followSide][0](allfreqs[followSide][0],allfreqs[followSide][1],allfreqs[followSide][2])){
       RGBC freqL = colour_readL();
       RGBC freqR = colour_readR();
       float allfreqs[2][4]={{freqL.R,freqL.G,freqL.B,freqL.C},{freqR.R,freqR.G,freqR.B,freqR.C}};
       drive((power/2),dir,0);
       delay(50);
     }
     float testfreqs[2][4]={{freqL.G,freqL.R,freqL.R,freqL.G},{freqR.G,freqR.R,freqR.R,freqR.G}};
   }

   if (followSide==0) negpos=-1;
   if (followSide==1) negpos=1;
    
    mod=(testfreqs[followSide][followCol]-thresh[followSide][followCol])*gain/(range[followSide][followCol]);
    drive(power,dir,mod);
    delay(50);
}
