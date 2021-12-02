class MEDIR_DISTANCIA{
  private:
  int TRIG = 3; /*pin del sensor ultrasónico (SU)*/
  int ECHO = 4;  /*pin del sensor ultrasónico (SU)*/
  int DURACION; /*se utiliza para calcular la distancia con el SU*/
  
  public:
//  MEDIR_DISTANCIA(int trig, int echo){
//    TRIG = trig;
//    ECHO = echo;
//  }
  
  float DISTANCIA;  /*se utiliza para calcular la distancia con el SU*/

  float Medir_distancia(){  /*Funcion que calcula la distancia co el SU*/
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    DURACION = pulseIn(ECHO, HIGH);
    DISTANCIA = DURACION / 58.2;
    return DISTANCIA;  /*regresa el valor de la distancia*/
  }

};
