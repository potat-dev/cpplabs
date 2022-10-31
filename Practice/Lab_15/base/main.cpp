// Написать программу, формирующую по исходному BMP файлу новый BMP файл
// повернутый по часовой стрелке на 90 градусов.

// Указывать имена файлов исходных и результирующих файлов в командной строке
// файлы после обработки заголовков читать целиком в динамически выделенную
// память

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct __attribute__((__packed__)) BitMapFileHeader {
  uint16_t Type;     // (2) Сигнатура "BM"
  uint32_t Size;     // (4) Размер файла
  uint16_t Reserv1;  // (2) Зарезервировано
  uint16_t Reserv2;  // (2) Зарезервировано
  uint32_t Offset;   // (4) Смещение изображения
};

struct __attribute__((__packed__)) BitMapInfoHeader {
  uint32_t Size;       // (4) Длина заголовка
  uint32_t Width;      // (4) Ширина изображения, точки
  uint32_t Height;     // (4) Высота изображения, точки
  uint16_t Planes;     // (2) Число плоскостей
  uint16_t BitCount;   // (2) Глубина цвета, бит на точку
  uint32_t Compress;   // (4) Тип компрессии
  uint32_t SizeImage;  // (4) Размер изображения, байт
  uint32_t XpelsPerM;  // (4) Горизонтальное разрешение
  uint32_t YpelsPerM;  // (4) Вертикальное разрешение
  uint32_t Colors;     // (4) Число используемых цветов
  uint32_t Palette;    // (4) Число основных цветов
};

struct __attribute__((__packed__)) BGR {
  uint8_t Blue;   // (1) Синий
  uint8_t Green;  // (1) Зеленый
  uint8_t Red;    // (1) Красный
};

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
    return 1;
  }

  ifstream fin(argv[1], ios::binary);
  if (!fin.is_open()) {
    cout << "Error: can't open file " << argv[1] << endl;
    return 1;
  }

  ofstream fout(argv[2], ios::binary);
  if (!fout.is_open()) {
    cout << "Error: can't open file " << argv[2] << endl;
    return 1;
  }

  BitMapFileHeader fileHeader;
  BitMapInfoHeader infoHeader;

  fin.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
  fin.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

  if (fileHeader.Type != 0x4D42) {
    cout << "Error: file " << argv[1] << " is not BMP file" << endl;
    return 1;
  }

  if (infoHeader.BitCount != 24) {
    cout << "Error: file " << argv[1] << " is not 24-bit BMP file" << endl;
    return 1;
  }

  BGR** pixels = new BGR*[infoHeader.Height];
  uint32_t padding = (4 - (infoHeader.Width * 3) % 4) % 4;

  // read pixels
  fin.seekg(fileHeader.Offset, ios::beg);
  for (int y = 0; y < infoHeader.Height; ++y) {
    pixels[y] = new BGR[infoHeader.Width];
    for (int x = 0; x < infoHeader.Width; ++x) {
      fin.read(reinterpret_cast<char*>(&pixels[y][x]), sizeof(BGR));
    }
    fin.seekg(padding, ios::cur);
  }

  BitMapInfoHeader newInfoHeader = infoHeader;
  newInfoHeader.Width = infoHeader.Height;
  newInfoHeader.Height = infoHeader.Width;

  BGR** newPixels = new BGR*[newInfoHeader.Height];
  for (int y = 0; y < newInfoHeader.Height; ++y) {
    newPixels[newInfoHeader.Height - y - 1] = new BGR[newInfoHeader.Width];
    for (int x = 0; x < newInfoHeader.Width; ++x) {
      newPixels[newInfoHeader.Height - y - 1][x] = pixels[x][y];
    }
  }

  fout.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
  fout.write(reinterpret_cast<char*>(&newInfoHeader), sizeof(newInfoHeader));

  fout.seekp(fileHeader.Offset, ios::beg);
  padding = (4 - (newInfoHeader.Width * 3) % 4) % 4;

  for (int y = 0; y < newInfoHeader.Height; ++y) {
    for (int x = 0; x < newInfoHeader.Width; ++x) {
      fout.write(reinterpret_cast<char*>(&newPixels[y][x]), sizeof(BGR));
    }
    fout.seekp(padding, ios::cur);
  }

  return 0;
}