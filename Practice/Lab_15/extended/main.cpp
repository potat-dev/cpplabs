// Написать программу, формирующую по исходному BMP файлу новый BMP файл
// повернутый по часовой стрелке на 90 градусов.

// Указывать имена файлов исходных и результирующих файлов в командной строке
// файлы после обработки заголовков читать целиком в динамически выделенную
// память

#include <iostream>

#include "bmp.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
    return 1;
  }

  BitMap bmp(argv[1]);
  bmp.Print();
  bmp.Rotate(BitMap::RotateType::Rotate90);
  bmp.Print();
  bmp.Save(argv[2]);

  return 0;
}