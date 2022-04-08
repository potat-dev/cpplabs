#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для функции exit()

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

uint32_t get(FILE *f, uint8_t bytes) {
  uint32_t temp = 0;
  for (int i = 0; i < bytes; i++)
    temp |= getc(f) << (8 * i); // little-endian
  return temp;
}


int main() {
  FILE * in_file = fopen("input.bmp", "rb");

  BitMapFileHeader file_header;
  file_header.Type       = get(in_file, sizeof(file_header.Type));
  file_header.Size       = get(in_file, sizeof(file_header.Size));
  file_header.Reserved1  = get(in_file, sizeof(file_header.Reserved1));
  file_header.Reserved2  = get(in_file, sizeof(file_header.Reserved2));
  file_header.OffsetBits = get(in_file, sizeof(file_header.OffsetBits));

  BitMapInfoHeader info_header;
  info_header.Size            = get(in_file, sizeof(info_header.Size));
  info_header.Width           = get(in_file, sizeof(info_header.Width));
  info_header.Height          = get(in_file, sizeof(info_header.Height));
  info_header.Planes          = get(in_file, sizeof(info_header.Planes));
  info_header.BitCount        = get(in_file, sizeof(info_header.BitCount));
  info_header.Compression     = get(in_file, sizeof(info_header.Compression));
  info_header.SizeImage       = get(in_file, sizeof(info_header.SizeImage));
  info_header.XpelsPerMeter   = get(in_file, sizeof(info_header.XpelsPerMeter));
  info_header.YpelsPerMeter   = get(in_file, sizeof(info_header.YpelsPerMeter));
  info_header.ColorsUsed      = get(in_file, sizeof(info_header.ColorsUsed));
  info_header.ColorsImportant = get(in_file, sizeof(info_header.ColorsImportant));
 
  cout << "Type:        " << hex << file_header.Type       << endl;
  cout << "Size:        " << dec << file_header.Size       << endl;
  cout << "OffsetBits:  " << dec << file_header.OffsetBits << endl;
  cout << "Width:       " << dec << info_header.Width           << endl;
  cout << "Height:      " << dec << info_header.Height          << endl;
  cout << "Planes:      " << dec << info_header.Planes          << endl;
  cout << "BitCount:    " << dec << info_header.BitCount        << endl;
  cout << "Compression: " << dec << info_header.Compression     << endl;
  cout << "SizeImage:   " << dec << info_header.SizeImage       << endl;
}