// based on http://yaab-arduino.blogspot.ca/2015/05/beating-heart-with-arduino-and-max7219.html

int INTENSITYMIN = 0; // minimum brightness, valid range [0,15]
int INTENSITYMAX = 8; // maximum brightness, valid range [0,15]

int DIN_PIN = 2;      // data in pin    -|
int CS_PIN = 3;       // load (CS) pin   |-- Défini les pins où les yeux sont connectés
int CLK_PIN = 4;      // clock pin      -|

// MAX7219 registers
byte MAXREG_DECODEMODE = 0x09;
byte MAXREG_INTENSITY  = 0x0a;
byte MAXREG_SCANLIMIT  = 0x0b;
byte MAXREG_SHUTDOWN   = 0x0c;
byte MAXREG_DISPTEST   = 0x0f;

const unsigned char eyes1[] = //Cette variable s'occupe de la position 1 des yeux
{
  B00111100,
  B01111110,
  B11111111,
  B11100111,
  B11100111,
  B11111111,
  B01111110,
  B00111100,
};

const unsigned char eyes2[] = //Cette variable s'occupe de la position 2 des yeux
{
  B00111100,
  B01111110,
  B11111111,
  B11110011,
  B11110011,
  B11111111,
  B01111110,
  B00111100,
};


const unsigned char eyes3[] = //Cette variable s'occupe de la position 3 des yeux
{
  B00111100,
  B01111110,
  B11110011,
  B11110011,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
};
const unsigned char eyes4[] = //Cette variable s'occupe de la position 4 des yeux
{
  B00111100,
  B01111110,
  B11111001,
  B11111001,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
};



void setup ()
{
  pinMode(DIN_PIN, OUTPUT); //  -|
  pinMode(CLK_PIN, OUTPUT); //   |-- Défini les pins des yeux comme des outputs
  pinMode(CS_PIN, OUTPUT);  //  -|

  // initialization of the MAX7219
  setRegistry(MAXREG_SCANLIMIT, 0x07);
  setRegistry(MAXREG_DECODEMODE, 0x00);  // using an led matrix (not digits)
  setRegistry(MAXREG_SHUTDOWN, 0x01);    // not in shutdown mode
  setRegistry(MAXREG_DISPTEST, 0x00);    // no display test
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);

  // dessine eyes1
  setRegistry(1, eyes1[0]);
  setRegistry(2, eyes1[1]);
  setRegistry(3, eyes1[2]);
  setRegistry(4, eyes1[3]);
  setRegistry(5, eyes1[4]);
  setRegistry(6, eyes1[5]);
  setRegistry(7, eyes1[6]);
  setRegistry(8, eyes1[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
}


void loop ()
{
  
  // dessine eyes1
  setRegistry(1, eyes1[0]);
  setRegistry(2, eyes1[1]);
  setRegistry(3, eyes1[2]);
  setRegistry(4, eyes1[3]);
  setRegistry(5, eyes1[4]);
  setRegistry(6, eyes1[5]);
  setRegistry(7, eyes1[6]);
  setRegistry(8, eyes1[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(5000);
  
  // dessine eyes2
  setRegistry(1, eyes2[0]);
  setRegistry(2, eyes2[1]);
  setRegistry(3, eyes2[2]);
  setRegistry(4, eyes2[3]);
  setRegistry(5, eyes2[4]);
  setRegistry(6, eyes2[5]);
  setRegistry(7, eyes2[6]);
  setRegistry(8, eyes2[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(50);
  
    // dessine eyes3
  setRegistry(1, eyes3[0]);
  setRegistry(2, eyes3[1]);
  setRegistry(3, eyes3[2]);
  setRegistry(4, eyes3[3]);
  setRegistry(5, eyes3[4]);
  setRegistry(6, eyes3[5]);
  setRegistry(7, eyes3[6]);
  setRegistry(8, eyes3[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(50);
  
  // dessine eyes4
  setRegistry(1, eyes4[0]);
  setRegistry(2, eyes4[1]);
  setRegistry(3, eyes4[2]);
  setRegistry(4, eyes4[3]);
  setRegistry(5, eyes4[4]);
  setRegistry(6, eyes4[5]);
  setRegistry(7, eyes4[6]);
  setRegistry(8, eyes4[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(2000);
  
  // dessine eyes3
  setRegistry(1, eyes3[0]);
  setRegistry(2, eyes3[1]);
  setRegistry(3, eyes3[2]);
  setRegistry(4, eyes3[3]);
  setRegistry(5, eyes3[4]);
  setRegistry(6, eyes3[5]);
  setRegistry(7, eyes3[6]);
  setRegistry(8, eyes3[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(50);
  
    // dessine eyes2
  setRegistry(1, eyes2[0]);
  setRegistry(2, eyes2[1]);
  setRegistry(3, eyes2[2]);
  setRegistry(4, eyes2[3]);
  setRegistry(5, eyes2[4]);
  setRegistry(6, eyes2[5]);
  setRegistry(7, eyes2[6]);
  setRegistry(8, eyes2[7]);
  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
  delay(50);
}


void setRegistry(byte reg, byte value)
{
  digitalWrite(CS_PIN, LOW);

  putByte(reg);   // specify register
  putByte(value); // send data

  digitalWrite(CS_PIN, LOW);
  digitalWrite(CS_PIN, HIGH);
}

void putByte(byte data) // Affiche les images sur les leds
{
  byte i = 8;
  byte mask;
  while (i > 0)
  {
    mask = 0x01 << (i - 1);        // get bitmask
    digitalWrite( CLK_PIN, LOW);   // tick
    if (data & mask)               // choose bit
      digitalWrite(DIN_PIN, HIGH); // send 1
    else
      digitalWrite(DIN_PIN, LOW);  // send 0
    digitalWrite(CLK_PIN, HIGH);   // tock
    --i;                           // move to lesser bit
  }
}
