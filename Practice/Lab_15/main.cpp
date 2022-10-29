// Написать программу, формирующую по исходному BMP файлу новый BMP файл
// повернутый по часовой стрелке на 90 градусов.

// Указывать имена файлов исходных и результирующих файлов в командной строке
// файлы после обработки заголовков читать целиком в динамически выделенную
// память

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "stdio.h"

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

// rgb brightness calculation
uint8_t rgb_brightness(BGR rgb) {
  return (uint8_t)(0.299 * rgb.Red + 0.587 * rgb.Green + 0.114 * rgb.Blue);
}

void pretty_print(BGR **pixels, int h, int w) {
  for (int y = h - 1; y >= 0; y--) {
    for (int x = 0; x < w; x++)
      cout << (rgb_brightness(pixels[y][x]) > 128 ? " " : "#");
      // printf("%02X %02X %02X | ", pixels[y][x].Red, pixels[y][x].Green,
      //        pixels[y][x].Blue);
    printf("\n");
  }
}

int main() {
  ifstream fin("kek2.bmp", ios::binary);
  if (!fin.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  BitMapFileHeader file;
  fin.read((char *)&file, sizeof(file));

  BitMapInfoHeader image;
  fin.read((char *)&image, sizeof(image));

  cout << "Type:            " << hex << file.Type << endl;
  cout << "Size:            " << dec << file.Size << endl;
  cout << "Reserved1:       " << dec << file.Reserv1 << endl;
  cout << "Reserved2:       " << dec << file.Reserv2 << endl;
  cout << "OffsetBits:      " << dec << file.Offset << endl;
  cout << "Size:            " << dec << image.Size << endl;
  cout << "Width:           " << dec << image.Width << endl;
  cout << "Height:          " << dec << image.Height << endl;
  cout << "Planes:          " << dec << image.Planes << endl;
  cout << "BitCount:        " << dec << image.BitCount << endl;
  cout << "Compression:     " << dec << image.Compress << endl;
  cout << "SizeImage:       " << dec << image.SizeImage << endl;
  cout << "XpelsPerMeter:   " << dec << image.XpelsPerM << endl;
  cout << "YpelsPerMeter:   " << dec << image.YpelsPerM << endl;
  cout << "ColorsUsed:      " << dec << image.Colors << endl;
  cout << "ColorsImportant: " << dec << image.Palette << endl;

  // go to the start of the image data
  fin.seekg(file.Offset, ios::beg);

  BGR **pixels = new BGR *[image.Height];
  for (int i = 0; i < image.Height; i++) pixels[i] = new BGR[image.Width];

  for (int y = 0; y < image.Height; y++) {
    for (int x = 0; x < image.Width; x++) {
      fin.read((char *)&pixels[y][x], sizeof(BGR));
    }
    // skip padding
    fin.seekg((4 - (image.Width * 3) % 4) % 4, ios::cur);
  }

  pretty_print(pixels, image.Height, image.Width);

  BGR **rotated = new BGR *[image.Width];
  for (int i = 0; i < image.Width; i++) rotated[i] = new BGR[image.Height];

  // rotate 90 degrees ccw
  BitMapFileHeader rotated_file = file;
  BitMapInfoHeader rotated_image = image;
  rotated_image.Width = image.Height;
  rotated_image.Height = image.Width;

  // rotate 90 degrees ccw
  for (int y = 0; y < rotated_image.Height; y++)
    for (int x = 0; x < rotated_image.Width; x++)
      rotated[rotated_image.Height - y - 1][x] = pixels[x][y];

  cout << "\n\n\nROTATED\n\n\n";
  pretty_print(rotated, rotated_image.Height, rotated_image.Width);

  // rotate 90 degrees cw
  // for (int y = 0; y < image.Height; y++)
  // for (int x = 0; x < image.Width; x++)
  //   rotated2[image.Width - x - 1][y] = pixels[y][x];

  // write to file
  ofstream fout("output.bmp", ios::binary);
  if (!fout.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  // image.Width = image.Height;
  // image.Height = image.Width;

  fout.write((char *)&rotated_file, sizeof(file));
  cout << "Done!" << endl;
  fout.write((char *)&rotated_image, sizeof(image));
  cout << "Done!" << endl;

  // go to the start of the image data
  fout.seekp(rotated_file.Offset, ios::beg);
  cout << "Done!" << endl;

  // write image data
  for (int y = 0; y < rotated_image.Height; y++) {
    for (int x = 0; x < rotated_image.Width; x++) {
      fout.write((char *)&rotated[y][x], sizeof(BGR));
    }
    // add padding
    fout.seekp((4 - (rotated_image.Width * 3) % 4) % 4, ios::cur);
  }

  cout << "Done!" << endl;
}