RGBC colour_readR() { 
   RGBC frequency;
   // Setting red filtered photodiodes to be read
   digitalWrite(S2R,LOW);
   digitalWrite(S3R,LOW);
   // Reading the output frequency
   frequency.R = pulseIn(sensorOutR, LOW);
   
   
   // Setting Green filtered photodiodes to be read
   digitalWrite(S2R,HIGH);
   digitalWrite(S3R,HIGH);
   // Reading the output frequency
   frequency.G = pulseIn(sensorOutR, LOW);
  
  
   // Setting Blue filtered photodiodes to be read
   digitalWrite(S2R,LOW);
   digitalWrite(S3R,HIGH);
   // Reading the output frequency
   frequency.B = pulseIn(sensorOutR, LOW);
  
   // Setting Clear  to be read
   digitalWrite(S2R,HIGH);
   digitalWrite(S3R,LOW);
   // Reading the output frequency
   frequency.C = pulseIn(sensorOutR, LOW);
  
   return frequency;

}

RGBC colour_readL() { 
   RGBC frequency;
   // Setting red filtered photodiodes to be read
   digitalWrite(S2L,LOW);
   digitalWrite(S3L,LOW);
   // Reading the output frequency
   frequency.R = pulseIn(sensorOutL, LOW);
   
   
   // Setting Green filtered photodiodes to be read
   digitalWrite(S2L,HIGH);
   digitalWrite(S3L,HIGH);
   // Reading the output frequency
   frequency.G = pulseIn(sensorOutL, LOW);
  
  
   // Setting Blue filtered photodiodes to be read
   digitalWrite(S2L,LOW);
   digitalWrite(S3L,HIGH);
   // Reading the output frequency
   frequency.B = pulseIn(sensorOutL, LOW);
  
   // Setting Clear  to be read
   digitalWrite(S2L,HIGH);
   digitalWrite(S3L,LOW);
   // Reading the output frequency
   frequency.C = pulseIn(sensorOutL, LOW);
  
   return frequency;
}
