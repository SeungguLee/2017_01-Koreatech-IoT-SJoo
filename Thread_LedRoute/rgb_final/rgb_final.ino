int red = 13;
int green = 12;
int blue = 11;
int red1 = 10;
int green1 = 9;
int blue1 = 8;
int red2 = 7;
int green2 = 6;
int blue2 = 5;
int red3 = 4;
int green3 = 3;
int blue3 = 2;
int red4 = 14;
int green4 = 15;
int blue4 = 16;
int red5 = 17;
int green5 = 18;
int blue5 = 19;
int red6 = 22;
int green6 = 23;
int blue6 = 24;
int red7 = 25;
int green7 = 26;
int blue7 = 27;
int red8 = 28;
int green8 = 29;
int blue8 = 30;
int red9 = 31;
int green9 = 32;
int blue9 = 33;
int red10 = 34;
int green10 = 35;
int blue10 = 36;
int red11 = 37;
int green11 = 38;
int blue11 = 39;

int ran_red;
int ran_green;
int ran_blue;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(blue3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(green4, OUTPUT);
  pinMode(blue4, OUTPUT);
  pinMode(red5, OUTPUT);
  pinMode(green5, OUTPUT);
  pinMode(blue5, OUTPUT);
  pinMode(red6, OUTPUT);
  pinMode(green6, OUTPUT);
  pinMode(blue6, OUTPUT);
  pinMode(red7, OUTPUT);
  pinMode(green7, OUTPUT);
  pinMode(blue7, OUTPUT);
  pinMode(red8, OUTPUT);
  pinMode(green8, OUTPUT);
  pinMode(blue8, OUTPUT);
  pinMode(red9, OUTPUT);
  pinMode(green9, OUTPUT);
  pinMode(blue9, OUTPUT);
  pinMode(red10, OUTPUT);
  pinMode(green10, OUTPUT);
  pinMode(blue10, OUTPUT);
  pinMode(red11, OUTPUT);
  pinMode(green11, OUTPUT);
  pinMode(blue11, OUTPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop(){
  char ch = Serial.read();
  ran_red = random(126) + 130;
  ran_green = random(126) + 130;
  ran_blue = random(256);

  if(ch == '1'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, ran_red, ran_green, ran_blue);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, 0, 0, 0);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, 0, 0, 0);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '2'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, ran_red, ran_green, ran_blue);
    setColor(red3, green3, blue3, 0, 0, 0);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, 0, 0, 0);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '3'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, ran_red, ran_green, ran_blue);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, 0, 0, 0);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '4'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, ran_red, ran_green, ran_blue);
    setColor(red6, green6, blue6, 0, 0, 0);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '5'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, ran_red, ran_green, ran_blue);
    setColor(red7, green7, blue7, ran_red, ran_green, ran_blue);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '6'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, ran_red, ran_green, ran_blue);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, ran_red, ran_green, ran_blue);
    setColor(red9, green9, blue9, 0, 0, 0);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '7'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, ran_red, ran_green, ran_blue);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, ran_red, ran_green, ran_blue);
    setColor(red10, green10, blue10, ran_red, ran_green, ran_blue);
    setColor(red11, green11, blue11, 0, 0, 0);
  }else if(ch == '8'){
    setColor(red, green, blue, ran_red, ran_green, ran_blue);
    setColor(red1, green1, blue1, 0, 0, 0);
    setColor(red2, green2, blue2, 0, 0, 0);
    setColor(red3, green3, blue3, ran_red, ran_green, ran_blue);
    setColor(red4, green4, blue4, 0, 0, 0);
    setColor(red5, green5, blue5, 0, 0, 0);
    setColor(red6, green6, blue6, ran_red, ran_green, ran_blue);
    setColor(red7, green7, blue7, 0, 0, 0);
    setColor(red8, green8, blue8, 0, 0, 0);
    setColor(red9, green9, blue9, ran_red, ran_green, ran_blue);
    setColor(red10, green10, blue10, 0, 0, 0);
    setColor(red11, green11, blue11, ran_red, ran_green, ran_blue);
  }
}

void setColor(int redPin, int greenPin, int bluePin, int redColor, int greenColor, int blueColor){
  analogWrite(redPin, redColor);
  analogWrite(greenPin, greenColor);
  analogWrite(bluePin, blueColor);
}
