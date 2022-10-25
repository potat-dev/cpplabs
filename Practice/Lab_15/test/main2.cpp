#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "stdio.h"

// указывать имена файлов исходных и результирующих файлов в командной строке
// ! файлы, после обработки заголовков, читать целиком в динамически заказанную
// память

using namespace std;

struct __attribute__((__packed__)) BitMapFileHeader {
  uint16_t Type;       //  2  0   Сигнатура "BM"
  uint32_t Size;       //  4  2   Размер файла
  uint16_t Reserved1;  //  2  6   Зарезервировано
  uint16_t Reserved2;  //  2  8   Зарезервировано
  uint32_t OffsetBits;  //  4  10  Смещение изображения от начала файла
};

struct __attribute__((__packed__)) BitMapInfoHeader {
  uint32_t Size;      //  4  14  Длина заголовка
  uint32_t Width;     //  4  18  Ширина изображения, точки
  uint32_t Height;    //  4  22  Высота изображения, точки
  uint16_t Planes;    //  2  26  Число плоскостей
  uint16_t BitCount;  //  2  28  Глубина цвета, бит на точку
  uint32_t Compression;  //  4  30  Тип компрессии
  uint32_t SizeImage;  //  4  34  Размер изображения, байт
  uint32_t XpelsPerMeter;  //  4  38  Горизонтальное разрешение, точки на метр
  uint32_t YpelsPerMeter;  //  4  42  Вертикальное разрешение, точки на метр
  uint32_t ColorsUsed;  //  4  46  Число используемых цветов
  uint32_t ColorsImportant;  //  4  50  Число основных цветов
};

struct BGR {
  uint8_t Blue;
  uint8_t Green;
  uint8_t Red;
};

void put(FILE *f, uint32_t data, uint8_t bytes) {
  for (int i = 0; i < bytes; i++) putc((data >> (i * 8)) & 0xff, f);
}

bool grayscale(BGR *c) {
  double temp = ((0.30 * (double)(c->Red)) + (0.59 * (double)(c->Green)) +
                 (0.11 * (double)(c->Blue))) /
                256.0;
  return (temp > 0.5);
}

void pretty_print(BGR **pixels, int h, int w) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++)
      printf("%02X %02X %02X | ", pixels[y][x].Red, pixels[y][x].Green,
             pixels[y][x].Blue);
    // printf(grayscale(&pixels[y][x]) ? " " : "#");
    printf("\n");
  }
}

int main() {
  ifstream fin("kek.bmp", ios::binary);
  if (!fin.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  BitMapFileHeader file;
  fin.read((char *)&file, sizeof(file));

  BitMapInfoHeader image;
  fin.read((char *)&image, sizeof(image));

  // fread(&file, sizeof(BitMapFileHeader), 1, input);
  // fread(&image, sizeof(BitMapInfoHeader), 1, input);

  cout << "Type:            " << hex << setw(4) << setfill('0') << file.Type
       << endl;
  cout << "Size:            " << hex << setw(8) << setfill('0') << file.Size
       << endl;
  cout << "Reserved1:       " << hex << setw(4) << setfill('0')
       << file.Reserved1 << endl;
  cout << "Reserved2:       " << hex << setw(4) << setfill('0')
       << file.Reserved2 << endl;
  cout << "OffsetBits:      " << hex << setw(8) << setfill('0')
       << file.OffsetBits << endl;
  cout << "Size:            " << hex << setw(8) << setfill('0') << image.Size
       << endl;
  cout << "Width:           " << hex << setw(8) << setfill('0') << image.Width
       << endl;
  cout << "Height:          " << hex << setw(8) << setfill('0') << image.Height
       << endl;
  cout << "Planes:          " << hex << setw(4) << setfill('0') << image.Planes
       << endl;
  cout << "BitCount:        " << hex << setw(4) << setfill('0')
       << image.BitCount << endl;
  cout << "Compression:     " << hex << setw(8) << setfill('0')
       << image.Compression << endl;
  cout << "SizeImage:       " << hex << setw(8) << setfill('0')
       << image.SizeImage << endl;
  cout << "XpelsPerMeter:   " << hex << setw(8) << setfill('0')
       << image.XpelsPerMeter << endl;
  cout << "YpelsPerMeter:   " << hex << setw(8) << setfill('0')
       << image.YpelsPerMeter << endl;
  cout << "ColorsUsed:      " << hex << setw(8) << setfill('0')
       << image.ColorsUsed << endl;
  cout << "ColorsImportant: " << hex << setw(8) << setfill('0')
       << image.ColorsImportant << endl;

  BGR **pixels = new BGR *[image.Height];
  for (int i = 0; i < image.Height; i++) pixels[i] = new BGR[image.Width];

  for (int y = 0; y < image.Height; y++)
    for (int x = 0; x < image.Width; x++) {
      pixels[y][x].Blue = fin.get();
      pixels[y][x].Green = fin.get();
      pixels[y][x].Red = fin.get();
    }

  pretty_print(pixels, image.Height, image.Width);

  // put(output, file.Type, sizeof(file.Type));
  // put(output, file.Size, sizeof(file.Size));
  // put(output, file.Reserved1, sizeof(file.Reserved1));
  // put(output, file.Reserved2, sizeof(file.Reserved2));
  // put(output, file.OffsetBits, sizeof(file.OffsetBits));

  // put(output, image.Size, sizeof(image.Size));
  // put(output, image.Width, sizeof(image.Width));
  // put(output, image.Height, sizeof(image.Height));
  // put(output, image.Planes, sizeof(image.Planes));
  // put(output, image.BitCount, sizeof(image.BitCount));
  // put(output, image.Compression, sizeof(image.Compression));
  // put(output, image.SizeImage, sizeof(image.SizeImage));
  // put(output, image.XpelsPerMeter, sizeof(image.XpelsPerMeter));
  // put(output, image.YpelsPerMeter, sizeof(image.YpelsPerMeter));
  // put(output, image.ColorsUsed, sizeof(image.ColorsUsed));
  // put(output, image.ColorsImportant, sizeof(image.ColorsImportant));

  // fseek(input, 54, SEEK_SET);
  // for (int i = 0; i < 1024; i++) put(output, get(input, 1), 1);

  // for (int x = 0; x < image.Width; x++) {
  //   for (int y = 0; y < image.Height; y++) {
  //     put(output, pixels[x][y].Blue, 1);
  //     put(output, pixels[x][y].Green, 1);
  //     put(output, pixels[x][y].Red, 1);
  //     // put(output, pixels[x][y].Alpha, 1);
  //   }
  // }

  cout << "Done!" << endl;
}