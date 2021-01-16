//
//    FILE: correlation_debugging.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2020-05-17
// VERSION: 0.1.0
// PUPROSE: demo of the Correlation Library
//

#include "Correlation.h"

#define SIZE  150

Correlation C(SIZE);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  C.clear();
  Serial.print("cnt\tminX\tmaxX\tminY\tmaxY\n");
  for (int i = 0; i < SIZE; i++)
  {
    C.add(i * 10, i * 40 + 0.1 * random(10));
  }

  for (int i = 0; i < SIZE; i++)
  {
    Serial.print(C.count());
    Serial.print("\t");
    Serial.print(C.getX(i), 2);
    Serial.print("\t");
    Serial.print(C.getY(i), 2);
    Serial.println();
  }
  Serial.println();
  C.calculate();
  Serial.print("A:\t");
  Serial.println(C.getA(), 3);
  Serial.print("B:\t");
  Serial.println(C.getB(), 3);
  Serial.print("R:\t");
  Serial.println(C.getR(), 6);
  Serial.print("Rsq:\t");
  Serial.println(C.getRsquare(), 6);
  Serial.print("Esq:\t");
  Serial.println(C.getEsquare(), 3);
  Serial.println();


  for (int i = 0; i < SIZE; i++)
  {
    C.setXY(i, 0, 0);  // create flatliner;
  }
  for (int i = 0; i < SIZE; i++)
  {
    Serial.print(C.count());
    Serial.print("\t");
    Serial.print(C.getX(i), 2);
    Serial.print("\t");
    Serial.print(C.getY(i), 2);
    Serial.println();
  }
  C.calculate();
  Serial.print("A:\t");
  Serial.println(C.getA(), 3);
  Serial.print("B:\t");
  Serial.println(C.getB(), 3);
  Serial.print("R:\t");
  Serial.println(C.getR(), 6);
  Serial.print("Rsq:\t");
  Serial.println(C.getRsquare(), 6);
  Serial.print("Esq:\t");
  Serial.println(C.getEsquare(), 3);
  Serial.println();


  for (int i = 0; i < SIZE; i++)
  {
    C.setX(i, i);
  }
  for (int i = 0; i < SIZE; i++)
  {
    Serial.print(C.count());
    Serial.print("\t");
    Serial.print(C.getX(i), 2);
    Serial.print("\t");
    Serial.print(C.getY(i), 2);
    Serial.println();
  }
  C.calculate();
  Serial.print("A:\t");
  Serial.println(C.getA(), 3);
  Serial.print("B:\t");
  Serial.println(C.getB(), 3);
  Serial.print("R:\t");
  Serial.println(C.getR(), 6);
  Serial.print("Rsq:\t");
  Serial.println(C.getRsquare(), 6);
  Serial.print("Esq:\t");
  Serial.println(C.getEsquare(), 3);
  Serial.println();


  for (int i = 0; i < SIZE; i++)
  {
    C.setY(i, PI * i);
  }
  for (int i = 0; i < SIZE; i++)
  {
    Serial.print(C.count());
    Serial.print("\t");
    Serial.print(C.getX(i), 2);
    Serial.print("\t");
    Serial.print(C.getY(i), 2);
    Serial.println();
  }
  C.calculate();
  Serial.print("A:\t");
  Serial.println(C.getA(), 3);
  Serial.print("B:\t");
  Serial.println(C.getB(), 3);
  Serial.print("R:\t");
  Serial.println(C.getR(), 6);
  Serial.print("Rsq:\t");
  Serial.println(C.getRsquare(), 6);
  Serial.print("Esq:\t");
  Serial.println(C.getEsquare(), 3);
  Serial.println();


  Serial.println("\nDone...");
}

void loop()
{

}

// -- END OF FILE --
