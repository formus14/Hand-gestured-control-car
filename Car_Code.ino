// N.B. test with the postive and the negative terminals of the battery what are the pins in the car board that ..
// lead the car to move forwad ,backward ,left and right ;
// so you can connect them soon after to the microcontroller pins as shown below.

int r = 11; // this represents the right pin
int l = 3;  // this represents the left pin
int f = 5;  // this represents the forward pin
int b = 6;  // this represents the back pin

int flag=true;
int potvalue;

void setup()
{
  Serial.begin(9600);           
  pinMode(r, INPUT);
  pinMode(l, INPUT);
  pinMode(f, INPUT);
  pinMode(b, INPUT);
}

void loop ()
{
  if (flag==true)
{
  Serial.println('b');
  flag=false;
}
  while( Serial.available() == 0);
 char data = Serial.read() ;
 Serial.println(data);
 if(data=='1')
 {movfoward1();}
  if(data=='2')
 {movfoward2();}
  if(data=='3')
 {movfoward3();}
  if(data=='4')
 {movright();}
  if(data=='5')
 {movleft();}
  if(data=='6')
 {movbackward();}

}

int movright() 
{
digitalWrite(r,HIGH);
digitalWrite(l,LOW);
Serial.println("Car is moving right");
}

int movleft() 
{
digitalWrite(l,HIGH);
digitalWrite(r,LOW);
Serial.println("Car is moving left");
}

int movfoward1() 
{
potvalue = 341;
analogWrite(f, potvalue);
digitalWrite(b,LOW);
Serial.println("Car is moving on the  1st gear"); 
}

int movfoward2() 
{
potvalue = 682;
analogWrite(f, potvalue);
digitalWrite(b,LOW);
Serial.println("Car is moving on the  2nd gear");
}

int movfoward3() 
{
potvalue = 1023;
analogWrite(f, potvalue);
digitalWrite(b,LOW);
Serial.println("Car is moving on the 3rd gear");
}

int movbackward() 
{
digitalWrite(b,HIGH);
digitalWrite(f,LOW);
Serial.println("Car is moving on the reverse gear");
}
