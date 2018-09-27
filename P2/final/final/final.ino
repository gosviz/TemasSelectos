#include<string.h> //para strcmp() compara cadenas
#include<math.h>
//Cambios en archivo
//Variables globales
int i;
short int contacto = 0,
          foto_Resistencia_Digital;
double  temperatura = 0,
        foto_Resistencia_Analogica = 0,
        infrarojo = 0;
char buff[20];	//Buffer serial;
float a0= 0.0505364,
      a1=0.7056092,
      a2=0.029781,
      a3=-0.00138495,
      a4=1.898157e-05;
double x, y;
  void setup(){
  //Inicialización y declaración de variables
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  
  Serial.begin(9600);   //Habilita comunicación serial
  Serial.setTimeout(100); //100ms máximo para caracter nulo
}

void loop(){

}

void serialEvent(){
  if(Serial.available()){ //Sí, hay datos en el buffer
    //Carga los datos en un buffer auxiliar
    Serial.readBytesUntil('\n', buff, 20);
    //Serial.println(buff);
    if(!strcmp(buff, "shs contact")){//Compara el buffer 
      contacto = digitalRead(2); //guarda el valor del pushbotton
      Serial.print("contacto ");
      Serial.println(contacto);
    }else if(!strcmp(buff, "shs temp")){
      temperatura = analogRead(A0);
      Serial.print("Temperatura ");
      Serial.println(temperatura);
    }else if(!strcmp(buff, "shs photord")){
      foto_Resistencia_Digital = digitalRead(3);
      Serial.print("Fotoresistencia Digital ");
      Serial.println(foto_Resistencia_Digital);
    }else if(!strcmp(buff, "shs photora")){
      foto_Resistencia_Analogica = analogRead(A1);
      Serial.print("Foto Resistencia Analógica ");
      Serial.println(foto_Resistencia_Analogica);
    }else if(!strcmp(buff, "shs infrared")){
      x = 13*pow((analogRead(A2)*0.0048828115),-1);
      y = a0+a1*x+a2*pow(x,2)+a3*pow(x,3)+a4*pow(x,4);
      Serial.print("Infrarojo ");
      Serial.println(y);
    }else{
        Serial.println("Ningun sensor con esa descripción");
    }
    memset(buff,0,sizeof(buff));//Limpia el buffer
  }
}
