void drive(float power,bool dir,float mod){
    float modA = 0;
    float modB = 0;
    float modSign=0;
    bool MC11;
    bool MC12;
    bool MC21;
    bool MC22;
    
    if (dir == HIGH) {
    MC11 = HIGH;
    MC12 = LOW;
    MC21 = HIGH;
    MC22 = LOW;
    }
    else if (dir == LOW) {
    MC11 = LOW;
    MC12 = HIGH;
    MC21 = LOW;
    MC22 = HIGH;
    }
    if (abs(mod)>abs(power)){
       modSign=mod/(abs(mod));
       mod = abs(power)*modSign;
    }
    if (mod<0) {
      modA = -mod;
      modB = 0;
    }
    if (mod>0){
      modA = 0;
      modB = mod;
    } 
      analogWrite(ENA_PWM, power - modA); //Enables the motor 1
      digitalWrite(ENB_PWM, power - modB); //Enables the motor 2
      digitalWrite(IN1, MC11); //Turns the wheels one way
      digitalWrite(IN2, MC12);
      digitalWrite(IN3, MC21);
      digitalWrite(IN4, MC22);
}
