#include <IRremote.h> // подключаем библиотеку для IR приемника
int ang;
IRrecv irrecv(4); // указываем пин, к которому подключен IR приемник
decode_results results;

void Motor_F()
{
  digitalWrite(7, HIGH);  // направление вращения мотора 1
  digitalWrite(8, LOW );  // направление вращения мотора 1
  digitalWrite(10, HIGH); // направление вращения мотора 2
  digitalWrite(9 , LOW ); // направление вращения мотора 2
}

void Motor_S()
{
  digitalWrite(7 , LOW ); // направление вращения мотора 1
  digitalWrite(8 , LOW ); // направление вращения мотора 1
  digitalWrite(9 , LOW ); // направление вращения мотора 2
  digitalWrite(10, LOW ); // направление вращения мотора 2
}

void Motor_L()
{
  digitalWrite(7, HIGH);  // направление вращения мотора 1
  digitalWrite(8, LOW );  // направление вращения мотора 1
  digitalWrite(10, LOW ); // направление вращения мотора 2
  digitalWrite(9 , HIGH); // направление вращения мотора 2
}

void Motor_R()
{
  digitalWrite(7, LOW );  // направление вращения мотора 1
  digitalWrite(8, HIGH);  // направление вращения мотора 1
  digitalWrite(10,HIGH);  // направление вращения мотора 2
  digitalWrite(9 , LOW ); // направление вращения мотора 2
}

void Motor_B()
{
  digitalWrite(7, LOW );  // направление вращения мотора 1
  digitalWrite(8, HIGH);  // направление вращения мотора 1
  digitalWrite(10,LOW ); // направление вращения мотора 2
  digitalWrite(9 ,HIGH); // направление вращения мотора 2
}

void setup() {
   irrecv.enableIRIn();  // запускаем прием инфракрасного сигнала
   Serial.begin(9600);   // подключаем монитор порта
   pinMode(7,  OUTPUT);  // инициализация портов как выходов
   pinMode(8,  OUTPUT); 
   pinMode(9,  OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(13, OUTPUT); // пин 13 будет выходом (англ. «output»)
   ang=0;
}
void loop() {
   if (irrecv.decode(&results)) // если данные пришли выполняем команды
   {
      Serial.println(results.value); // отправляем полученные данные на порт  
      if (results.value == 16736925) // Вперед
        { 
           digitalWrite(13, HIGH);
           Motor_F();                // включить мотор 1 2 Вперед
        }
      if (results.value == 16754775) // Назад
        { 
           digitalWrite(13, LOW);
           Motor_B();                // Назад
        }
     if (results.value == 16712445)  // Стоп
        {
           Motor_S();                // выключить мотор 1 2 
        }
     if (results.value == 16720605)  // Лево
        {
           Motor_L();                // 
        }
     if (results.value == 16761405)  // Право
        {
           Motor_R();                //
        }
     irrecv.resume(); // принимаем следующий сигнал на ИК приемнике
   }
}
