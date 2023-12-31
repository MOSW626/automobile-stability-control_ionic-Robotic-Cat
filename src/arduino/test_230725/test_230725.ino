#include <Wire.h>
int fw , bw;
int ENA = 8;
int ENB = 9;
int ENC = 10;
int END = 11;
int INA1 = 30;
int INA2 = 31;
// A : 1) LOW, 2) HOGH >> forward
int INB1 = 32;
int INB2 = 33;
// B : 1) HIGH, 2) LOW >> forward
int INC1 = 34;
int INC2 = 35;
// C : 1) LOW, 2) HOGH >> forward
int IND1 = 36;
int IND2 = 37;
// D : 1) HIGH, 2) LOW >> forward

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);

  pinMode(ENC, OUTPUT);
  pinMode(INC1, OUTPUT);
  pinMode(INC2, OUTPUT);

  pinMode(END, OUTPUT);
  pinMode(IND1, OUTPUT);
  pinMode(IND2, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(ENC, HIGH);
  digitalWrite(END, HIGH);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  analogWrite(ENC, 100);
  analogWrite(END, 100);

  Wire.begin();
  Serial.begin(9600);
}


// ================================================================
// ===                       MOTOR CONTROL                      ===
// ================================================================
/*
void forward(int Va, int Vb, int Vc, int Vd)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INB2, LOW);
  digitalWrite(INC1, LOW);
  digitalWrite(INC2, HIGH);
  digitalWrite(IND1, HIGH);
  digitalWrite(IND2, LOW);
}

void backward(int Va, int Vb, int Vc, int Vd)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INB2, HIGH);
  digitalWrite(INC1, HIGH);
  digitalWrite(INC2, LOW);
  digitalWrite(IND1, LOW);
  digitalWrite(IND2, HIGH);
}
*/

/*void FWard_Fwheel(int Va, int Vb)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INB2, LOW);
}

void BWard_Fwheel(int Va, int Vb)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);

  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INB2, HIGH);
}

void ForwrdFW_BackwardBW(int Va, int Vb, int Vc, int Vd);
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INB2, LOW);
  digitalWrite(INC1, HIGH);
  digitalWrite(INC2, LOW);
  digitalWrite(IND1, LOW);
  digitalWrite(IND2, HIGH);
}

void BackwardFW_ForwardBW(int Va, int Vb, int Vc, int Vd);
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INB2, HIGH);
  digitalWrite(INC1, LOW);
  digitalWrite(INC2, HIGH);
  digitalWrite(IND1, HIGH);
  digitalWrite(IND2, LOW);
}*/
void mc(int fb, int di,int v)
{
  if(fb == 1){//앞바퀴
    if(di == 1){//정회전
      analogWrite(ENA, v);
      analogWrite(ENB, v);

      digitalWrite(INA1, LOW);
      digitalWrite(INA2, HIGH);
      digitalWrite(INB1, HIGH);
      digitalWrite(INB2, LOW);
    }else{
      analogWrite(ENA, v);
      analogWrite(ENB, v);

      digitalWrite(INA1, HIGH);
      digitalWrite(INA2, LOW);
      digitalWrite(INB1, LOW);
      digitalWrite(INB2, HIGH);
    }
  }else{//뒷바퀴
    if(di== 1){//정회전
      analogWrite(ENC, v);
      analogWrite(END, v);

      digitalWrite(INC1, LOW);
      digitalWrite(INC2, HIGH);
      digitalWrite(IND1, HIGH);
      digitalWrite(IND2, LOW);
    }else{//역회전
      analogWrite(ENC, v);
      analogWrite(END, v);

      digitalWrite(INC1, HIGH);
      digitalWrite(INC2, LOW);
      digitalWrite(IND1, LOW);
      digitalWrite(IND2, HIGH);
    }
  }
}
/*void FW_forward(int Va, int Vb)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INB2, LOW);
}

void FW_stop(int Va, int Vb)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);

  digitalWrite(INA1, LOW);
  digitalWrite(INA2, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INB2, LOW);
}

void FW_backward(int Va, int Vb)
{
  analogWrite(ENA, Va);
  analogWrite(ENB, Vb);

  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);
  digitalWrite(INB1, LOW);
  digitalWrite(INB2, HIGH);
}

void BW_forward(int Vc, int Vd)
{
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INC1, LOW);
  digitalWrite(INC2, HIGH);
  digitalWrite(IND1, HIGH);
  digitalWrite(IND2, LOW);
}

void BW_stop(int Vc, int Vd)
{
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INC1, LOW);
  digitalWrite(INC2, LOW);
  digitalWrite(IND1, LOW);
  digitalWrite(IND2, LOW);
}

void BW_backward(int Vc, int Vd)
{
  analogWrite(ENC, Vc);
  analogWrite(END, Vd);

  digitalWrite(INC1, HIGH);
  digitalWrite(INC2, LOW);
  digitalWrite(IND1, LOW);
  digitalWrite(IND2, HIGH);
}
*/
void loop()
{
  int d = 1000;
  mc(1,1,255);//바퀴, 방향, 속도
  mc(0,1,255);
}
