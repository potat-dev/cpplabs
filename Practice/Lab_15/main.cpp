#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "stdio.h"

// указывать имена файлов исходных и результирующих файлов в командной строке
// ! файлы, после обработки заголовков, читать целиком в динамически заказанную память

using namespace std;

struct BitMapFileHeader {
  uint16_t Type;             //  2  0   Сигнатура "BM"
  uint32_t Size;             //  4  2   Размер файла
  uint16_t Reserved1;        //  2  6   Зарезервировано
  uint16_t Reserved2;        //  2  8   Зарезервировано
  uint32_t OffsetBits;       //  4  10  Смещение изображения от начала файла
};

struct BitMapInfoHeader {
  uint32_t Size;             //  4  14  Длина заголовка
  uint32_t Width;            //  4  18  Ширина изображения, точки
  uint32_t Height;           //  4  22  Высота изображения, точки
  uint16_t Planes;           //  2  26  Число плоскостей
  uint16_t BitCount;         //  2  28  Глубина цвета, бит на точку
  uint32_t Compression;      //  4  30  Тип компрессии
  uint32_t SizeImage;        //  4  34  Размер изображения, байт
  uint32_t XpelsPerMeter;    //  4  38  Горизонтальное разрешение, точки на метр
  uint32_t YpelsPerMeter;    //  4  42  Вертикальное разрешение, точки на метр
  uint32_t ColorsUsed;       //  4  46  Число используемых цветов
  uint32_t ColorsImportant;  //  4  50  Число основных цветов
};

struct BGRA {
  uint8_t Blue;
  uint8_t Green;
  uint8_t Red;
  uint8_t Alpha;
  
  BGRA (uint32_t i) {
    Blue  = (i >> 24) & 0xFF;
    Green = (i >> 16) & 0xFF;
    Red   = (i >>  8) & 0xFF;
    Alpha = (i >>  0) & 0xFF;
  }
};

uint32_t get(FILE *f, uint8_t bytes) {
  uint32_t temp = 0;
  for (int i = 0; i < bytes; i++)
    temp |= getc(f) << (8 * i); // little-endian
  return temp;
}

void put(FILE *f, uint32_t data, uint8_t bytes) {
  for (int i = 0; i < bytes; i++)
    putc((data >> (i * 8)) & 0xff, f);
}

bool grayscale(BGRA *c) {
  double temp =
    ((0.30 * (double)(c->Red)) +
    (0.59 * (double)(c->Green)) +
    (0.11 * (double)(c->Blue))) / 256.0;
  return (temp > 0.5);
}


int main() {
  FILE * input = fopen("kek2.bmp", "rb");
  FILE * output = fopen("output.bmp", "wb");

  BitMapFileHeader file;
  file.Type       = get(input, sizeof(file.Type));
  file.Size       = get(input, sizeof(file.Size));
  file.Reserved1  = get(input, sizeof(file.Reserved1));
  file.Reserved2  = get(input, sizeof(file.Reserved2));
  file.OffsetBits = get(input, sizeof(file.OffsetBits));

  BitMapInfoHeader image;
  image.Size            = get(input, sizeof(image.Size));
  image.Width           = get(input, sizeof(image.Width));
  image.Height          = get(input, sizeof(image.Height));
  image.Planes          = get(input, sizeof(image.Planes));
  image.BitCount        = get(input, sizeof(image.BitCount));
  image.Compression     = get(input, sizeof(image.Compression));
  image.SizeImage       = get(input, sizeof(image.SizeImage));
  image.XpelsPerMeter   = get(input, sizeof(image.XpelsPerMeter));
  image.YpelsPerMeter   = get(input, sizeof(image.YpelsPerMeter));
  image.ColorsUsed      = get(input, sizeof(image.ColorsUsed));
  image.ColorsImportant = get(input, sizeof(image.ColorsImportant));
 
  cout << "Type:        " << hex << file.Type         << endl;
  cout << "Size:        " << dec << file.Size         << endl;
  cout << "OffsetBits:  " << dec << file.OffsetBits   << endl;
  cout << "Width:       " << dec << image.Width       << endl;
  cout << "Height:      " << dec << image.Height      << endl;
  cout << "Planes:      " << dec << image.Planes      << endl;
  cout << "BitCount:    " << dec << image.BitCount    << endl;
  cout << "Compression: " << dec << image.Compression << endl;
  cout << "SizeImage:   " << dec << image.SizeImage   << endl;

  fseek(input, file.OffsetBits, SEEK_SET);

  BGRA ** pixels = (BGRA **) malloc(image.Width * sizeof(BGRA *));
  for (int x = 0; x < image.Width; x++) {
    pixels[x] = (BGRA *) malloc(image.Height * sizeof(BGRA));
    for (int y = 0; y < image.Height; y++) {
      pixels[x][y].Blue = get(input, 1);
      // ?  pixels[x][y].Green = get(input, 1);
      // ?  pixels[x][y].Red = get(input, 1);
      // ?  pixels[x][y].Alpha = get(input, 1);

      // pixels[x][y] = (BGRA) get(input, sizeof(BGRA));
      // printf(grayscale(&pixels[x][y]) ? " " : "#");
      // cout << grayscale(&pixels[x][y]);
    }
    // cout << endl;
    // printf("\n");
  }

  // for (int y = 0; y < image.Height; y++) {
  //   for (int x = 0; x < image.Width; x++) {
  //     printf(grayscale(&pixels[y][x]) ? " " : "#");
  //   }
  //   printf("\n");
  // }

  put(output, file.Type      , sizeof(file.Type      ));
  put(output, file.Size      , sizeof(file.Size      ));
  put(output, file.Reserved1 , sizeof(file.Reserved1 ));
  put(output, file.Reserved2 , sizeof(file.Reserved2 ));
  put(output, file.OffsetBits, sizeof(file.OffsetBits));

  put(output, image.Size           , sizeof(image.Size           ));
  put(output, image.Width          , sizeof(image.Width          ));
  put(output, image.Height         , sizeof(image.Height         ));
  put(output, image.Planes         , sizeof(image.Planes         ));
  put(output, image.BitCount       , sizeof(image.BitCount       ));
  put(output, image.Compression    , sizeof(image.Compression    ));
  put(output, image.SizeImage      , sizeof(image.SizeImage      ));
  put(output, image.XpelsPerMeter  , sizeof(image.XpelsPerMeter  ));
  put(output, image.YpelsPerMeter  , sizeof(image.YpelsPerMeter  ));
  put(output, image.ColorsUsed     , sizeof(image.ColorsUsed     ));
  put(output, image.ColorsImportant, sizeof(image.ColorsImportant));

  // ? fseek(input, 54, SEEK_SET);
  // ? for (int i = 0; i < 1024; i++)
  // ?   put(output, get(input, 1), 1);

  for (int x = 0; x < image.Width; x++) {
    for (int y = 0; y < image.Height; y++) {
      put(output, pixels[x][y].Blue, 1);
      // ? put(output, pixels[x][image.Height - y - 1].Green, 1);
      // ? put(output, pixels[x][image.Height - y - 1].Red, 1);
      // ? put(output, pixels[x][image.Height - y - 1].Alpha, 1);
    }
  }
}