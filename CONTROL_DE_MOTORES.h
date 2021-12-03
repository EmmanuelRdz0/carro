class CONTROL_DE_MOTORES{
  int m_der_avanzar = 9;     //Se definen los pines que controlaran los motoresd
  int m_der_retroceder = 10;
  int m_izq_avanzar = 6;
  int m_izq_retroceder = 5;
  
  public:
//    void Avanzar_adelante(int velocidad);  //Está funcion hace que el carro valla hacia delantee.
//    void Avanzar_atras(int velocidad);    //Para ir hacia atras solo hace falta enviar un pulso alto en los pines "retroceder" y la ausensia del pulso en los pines "avanzar"
//    void Girar_derecha(int velocidad);   //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la derecha, todos los demás deben de estar con ausencia de pulso
//    void Girar_izquierda(int velocidad);    //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la izquierda, todos los demás deben de estar con ausencia de pulso
//    void Detenerse();   //Para detenerse solo hace falta dejar de enviar pulsos a los cuatro pines
//    void Girar_u_derecha(int velocidad);  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
//    void Girar_u_izquierda(int velocidad);  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.


//  CONTROL_DE_MOTORES(int m_der_avanzar, int m_der_retroceder, int m_izq_avanzar, int m_izq_retroceder){
//    this -> m_der_avanzar = m_der_avanzar;
//    this -> m_der_retroceder = m_der_retroceder;
//    this -> m_izq_avanzar = m_izq_avanzar;
//    this -> m_izq_retroceder = m_izq_retroceder;
//  }
  
  void Avanzar_adelante(int velocidad){  //Está funcion hace que el carro valla hacia delante.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);      //Se configuran los pines como pines de salida.
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad);  //Para que el carro de mueva hacia delante se tiene que mandar un pulso alto el los pines "avanzar" y un la ausencia del pulso en los pines "retroceder" para que estos hagan de gnd.
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Avanzando adelante.");
  }

  void Avanzar_atras(int velocidad){    //Para ir hacia atras solo hace falta enviar un pulso alto en los pines "retroceder" y la ausensia del pulso en los pines "avanzar"
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, 0);
    analogWrite(m_der_retroceder, velocidad);
    analogWrite(m_izq_avanzar, 0);
    analogWrite(m_izq_retroceder, velocidad);
    Serial.println("Avanzando atras.");
  }

  void Girar_derecha(int velocidad){   //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la derecha, todos los demás deben de estar con ausencia de pulso
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    int velocidad_reducida;
    velocidad_reducida = velocidad*.50;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad_reducida);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando derecha.");
  }

  void Girar_izquierda(int velocidad){    //Para girar hacia la derecha se envia pulso alto en el pin "avanzar" pero solo el de la izquierda, todos los demás deben de estar con ausencia de pulso
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    int velocidad_reducida;
    velocidad_reducida = velocidad*.50;

    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);

    analogWrite(m_der_avanzar, velocidad);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, velocidad_reducida);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando izquierda.");
  }
  
  void Detenerse(){   //Para detenerse solo hace falta dejar de enviar pulsos a los cuatro pines
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, LOW);
    analogWrite(m_der_retroceder, LOW);
    analogWrite(m_izq_avanzar, LOW);
    analogWrite(m_izq_retroceder, LOW);
    Serial.println("Se detectó un obstáculo.");
  }

  void Girar_u_derecha(int velocidad){  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, 0);
    analogWrite(m_der_retroceder, velocidad);
    analogWrite(m_izq_avanzar, velocidad);
    analogWrite(m_izq_retroceder, 0);
    Serial.println("Girando hacia derecha sobre eje central.");
  }

  void Girar_u_izquierda(int velocidad){  //Para girar sobre el eje central, se le da un sentido a un motor y el sentido contrario al otro motor.
    if(velocidad<=0)velocidad = 0;       //Control de potencia de los motores.
    if(velocidad>=255)velocidad = 255;
    
    pinMode(m_der_avanzar, OUTPUT);
    pinMode(m_der_retroceder, OUTPUT);
    pinMode(m_izq_avanzar, OUTPUT);
    pinMode(m_izq_retroceder, OUTPUT);
    
    analogWrite(m_der_avanzar, velocidad);
    analogWrite(m_der_retroceder, 0);
    analogWrite(m_izq_avanzar, 0);
    analogWrite(m_izq_retroceder, velocidad);
    Serial.println("Girando hacia derecha sobre eje central.");
  }
  /*
  void Girar_der_en_movimiento(){
  }
  void Girar_izq_en_movimiento(){
  }
  */
};

































#include "Simple_MPU6050.h"         // incluye libreria Simple_MPU6050

class ENCONTRAR_SALIDA : public MEDIR_DISTANCIA, public CONTROL_DE_MOTORES{
  public:
  
  static Simple_MPU6050 mpu;       // crea objeto con nombre mpu
  static int ENABLE_MPU_OVERFLOW_PROTECTION();   // activa proteccion
  static float direccionSalida;
  static float distancia;
  static float distanciaMax;
  
  static spamtimer(uint8_t t){
    for(static uint32_t SpamTimer; (uint32_t)(millis() - SpamTimer) >= (t); SpamTimer = millis())
   }
  // spamtimer funcion para generar demora al escribir en monitor serie sin usar delay()
  
  static void encontrar_Salida (int16_t *gyro, int16_t *accel, int32_t *quat, uint32_t *timestamp) {  
    MEDIR_DISTANCIA medirDistancia;  //instancia medirDistancia con la clase MEDIR_DISTANCIA
    CONTROL_DE_MOTORES avance;       //instancia avance con la clase CONTROL_DE_MOTORES
    
    for(int x = 0; x >= 1500; x++){
      uint8_t SpamDelay = 10;      // demora para escribir en monitor serie de 100 mseg
      Quaternion q;         // variable necesaria para calculos posteriores
      VectorFloat gravity;        // variable necesaria para calculos posteriores
      float ypr[3] = { 0, 0, 0 };     // array para almacenar valores de yaw, pitch, roll
      float xyz[3] = { 0, 0, 0 };     // array para almacenar valores convertidos a grados de yaw, pitch, roll
      spamtimer(SpamDelay) {      // si han transcurrido al menos 100 mseg entonces proceder
        mpu.GetQuaternion(&q, quat);    // funcion para obtener valor para calculo posterior
        mpu.GetGravity(&gravity, &q);   // funcion para obtener valor para calculo posterior
        mpu.GetYawPitchRoll(ypr, &q, &gravity); // funcion obtiene valores de yaw, ptich, roll
        mpu.ConvertToDegrees(ypr, xyz);   // funcion convierte a grados sexagesimales
  //      Serial.printfloatx(F("Yaw")  , xyz[0], 9, 4, F(",   "));  // muestra en monitor serie rotacion de eje Z, yaw
  //      Serial.printfloatx(F("Pitch"), xyz[1], 9, 4, F(",   "));  // muestra en monitor serie rotacion de eje Y, pitch
  //      Serial.printfloatx(F("Roll") , xyz[2], 9, 4, F(",   "));  // muestra en monitor serie rotacion de eje X, roll
  //      Serial.println();       // salto de linea
      }
  
      distancia = medirDistancia.Medir_distancia();
      if(distancia > distanciaMax){
        distanciaMax = distancia;
        direccionSalida = xyz[0];
      } 
    }
    
    int limiteInferior = direccionSalida - 1;
    int limiteSuperior = direccionSalida + 1;
    while(direccionSalida >= limiteInferior || direccionSalida <= limiteSuperior){
      avance.Girar_u_derecha(200);
    }
    
    distancia = medirDistancia.Medir_distancia();
    if(distancia <= (distanciaMax - 5)){
      avance.Avanzar_adelante(200);
      delay(distancia*100);
      avance.Detenerse();
    }
  }

  
  static void setup_Encontrar_Salida(word address){
    for(int x = 0; x <= 1; x++){//Realiza la funcion de "setup"
      uint8_t val;
      if (I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE) {  // activacion de bus I2C a 400 Khz
        Wire.begin();
        Wire.setClock(400000);
      } else if (I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE) {
        Fastwire::setup(400, true);
      }
        
      Serial.begin(115200);     // inicializacion de monitor serie a 115200 bps
      while (!Serial);      // espera a enumeracion en caso de modelos con USB nativo
      //Serial.println(F("Inicio:"));   // muestra texto estatico
      
      if (OFFSETS == NULL) { // sin no existen OFFSETS                
        mpu.SetAddress(address).CalibrateMPU().load_DMP_Image();  // inicializacion de sensor
      }
      
      mpu.on_FIFO(encontrar_Salida);   // llamado a funcion mostrar_valores si memoria FIFO tiene valores
    }
  }

};
