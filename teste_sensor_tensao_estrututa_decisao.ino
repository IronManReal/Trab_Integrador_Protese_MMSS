#define R1 220000.0
#define R2 10000.0
#define SAMPLES 5
float acum  = 0;
int analog0 = 0;
int loops   = 0;
float v1    = 0;

void calc(){
  analog0 = analogRead(0);
  v1 = (5.0 * analog0)/1024.0;
  Serial.print("Valor da amostragem ");
  Serial.print(loops);
  Serial.print(": ");
  Serial.println(v1);
  
  if (v1 < 1){
    return;
  }
  acum += v1/(R2/(R2+R1));
  
  loops++;
  
  if(v1 >= 0.5 && v1 <= 1.0){

    Serial.print("Tensão entre 0.5 e 1.0");
  }

  if(v1 >= 1.1 && v1 <= 1.3){

    Serial.print("Tensão entre 1.1 e 1.3");
  }
  

 if(v1 >= 1.4 && v1 <= 1.5){

    Serial.print("Tensão entre 1.4 e 1.5");
  }

  if(v1 >= 1.6 && v1 <= 2.0){

    Serial.print("Tensão entre 1.6 e 2.0");
  }

  delay(200);
}
void setup() {
  pinMode(0,INPUT);
  Serial.begin(9600);
  Serial.println("Iniciando");
}

void loop() {
  calc();

}
