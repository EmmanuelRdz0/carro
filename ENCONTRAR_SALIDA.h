#include "Simple_MPU6050.h"         // incluye libreria Simple_MPU6050

class ENCONTRAR_SALIDA : public MEDIR_DISTANCIA, public CONTROL_DE_MOTORES{
  public:
  #define MPU6050_ADDRESS_AD0_LOW     0x68      // direccion I2C con AD0 en LOW o sin conexion
  #define MPU6050_ADDRESS_AD0_HIGH    0x69      // direccion I2C con AD0 en HIGH
  #define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW // por defecto AD0 en LOW
  
  Simple_MPU6050 mpu;       // crea objeto con nombre mpu
  int ENABLE_MPU_OVERFLOW_PROTECTION();   // activa proteccion
  float direccionSalida;
  float distancia;
  float distanciaMax;
  
  #define spamtimer(t) for (static uint32_t SpamTimer; (uint32_t)(millis() - SpamTimer) >= (t); SpamTimer = millis())
  // spamtimer funcion para generar demora al escribir en monitor serie sin usar delay()
  
  #define printfloatx(Name,Variable,Spaces,Precision,EndTxt) print(Name); {char S[(Spaces + Precision + 3)];Serial.print(F(" ")); Serial.print(dtostrf((float)Variable,Spaces,Precision ,S));}Serial.print(EndTxt);
  // printfloatx funcion para mostrar en monitor serie datos para evitar el uso se multiples print()

  MEDIR_DISTANCIA medirDistancia;
  CONTROL_DE_MOTORES avance;
  
  float encontrar_Salida (int16_t *gyro, int16_t *accel, int32_t *quat, uint32_t *timestamp) {  
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

  
  void setup_Encontrar_Salida(){
    for(int x = 0; x <= 1; x++){//Realiza la funcion de "setup"
      uint8_t val;
      #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE  // activacion de bus I2C a 400 Khz
        Wire.begin();
        Wire.setClock(400000);
      #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
      #endif
        
      Serial.begin(115200);     // inicializacion de monitor serie a 115200 bps
      while (!Serial);      // espera a enumeracion en caso de modelos con USB nativo
      //Serial.println(F("Inicio:"));   // muestra texto estatico
      
      #ifdef OFFSETS 
      #else                   // sin no existen OFFSETS
        mpu.SetAddress(MPU6050_ADDRESS_AD0_LOW).CalibrateMPU().load_DMP_Image();  // inicializacion de sensor
      #endif
        mpu.on_FIFO(encontrar_Salida());   // llamado a funcion mostrar_valores si memoria FIFO tiene valores
    }
  }

};
