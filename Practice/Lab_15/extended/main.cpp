// Написать программу, формирующую по исходному BMP файлу новый BMP файл
// повернутый по часовой стрелке на 90 градусов.

// Указывать имена файлов исходных и результирующих файлов в командной строке
// файлы после обработки заголовков читать целиком в динамически выделенную
// память

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

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

enum RotateType {
  Rotate90,
  Rotate180,
  Rotate270,
};

enum FlipType {
  FlipHorizontal,
  FlipVertical,
  FlipBoth,
};

// rgb brightness calculation
uint8_t rgb_brightness(BGR rgb) {
  return (uint8_t)(0.299 * rgb.Red + 0.587 * rgb.Green + 0.114 * rgb.Blue);
}

class BitMap {
 private:
  BitMapFileHeader file_header_;
  BitMapInfoHeader info_header_;
  BGR* data_;

 public:
  BitMap() : data_(nullptr) {}
  BitMap(const char* filename) : data_(nullptr) { Load(filename); }

  ~BitMap() { delete[] data_; }

  void Load(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) throw runtime_error("Can't open file");

    file.read(reinterpret_cast<char*>(&file_header_), sizeof(file_header_));
    file.read(reinterpret_cast<char*>(&info_header_), sizeof(info_header_));

    if (file_header_.Type != 0x4D42) throw runtime_error("Not BMP file");
    if (info_header_.BitCount != 24) throw runtime_error("Not 24 bit BMP file");

    data_ = new BGR[info_header_.Width * info_header_.Height];
    int padding = (4 - (info_header_.Width * 3) % 4) % 4;
    file.seekg(file_header_.Offset);

    for (int i = 0; i < info_header_.Height; ++i) {
      file.read(reinterpret_cast<char*>(data_ + i * info_header_.Width),
                info_header_.Width * 3);
      file.seekg(padding, ios::cur);
    }

    file.close();
  }

  void Save(const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) throw runtime_error("Can't open file");

    file.write(reinterpret_cast<char*>(&file_header_), sizeof(file_header_));
    file.write(reinterpret_cast<char*>(&info_header_), sizeof(info_header_));

    file.seekp(file_header_.Offset);
    int padding = (4 - (info_header_.Width * 3) % 4) % 4;
    for (int i = 0; i < info_header_.Height; ++i) {
      file.write(reinterpret_cast<char*>(data_ + i * info_header_.Width),
                 info_header_.Width * 3);
      file.seekp(padding, ios::cur);
    }

    file.close();
  }

  void Print() {
    for (int y = info_header_.Height - 1; y >= 0; y--) {
      for (int x = 0; x < info_header_.Width; x++)
        cout << (rgb_brightness(data_[y * info_header_.Width + x]) > 128 ? " "
                                                                         : "#");
      cout << endl;
    }
  }

  void Rotate(RotateType rotate_type) {
    BGR* new_data = new BGR[info_header_.Width * info_header_.Height];
    int new_width = info_header_.Width;
    int new_height = info_header_.Height;

    switch (rotate_type) {
      case Rotate90:
        new_width = info_header_.Height;
        new_height = info_header_.Width;
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[(new_height - x - 1) * new_width + y] =
                data_[y * info_header_.Width + x];
        break;
      case Rotate180:
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[(info_header_.Height - y - 1) * info_header_.Width +
                     info_header_.Width - x - 1] =
                data_[y * info_header_.Width + x];
        break;
      case Rotate270:
        new_width = info_header_.Height;
        new_height = info_header_.Width;
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[x * new_width + new_width - y - 1] =
                data_[y * info_header_.Width + x];
        break;
    }

    delete[] data_;
    data_ = new_data;
    info_header_.Width = new_width;
    info_header_.Height = new_height;
  }

  void Flip(FlipType flip_type) {
    BGR* new_data = new BGR[info_header_.Width * info_header_.Height];

    switch (flip_type) {
      case FlipHorizontal:
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[y * info_header_.Width + info_header_.Width - x - 1] =
                data_[y * info_header_.Width + x];
        break;
      case FlipVertical:
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[(info_header_.Height - y - 1) * info_header_.Width + x] =
                data_[y * info_header_.Width + x];
        break;
      case FlipBoth:
        for (int y = 0; y < info_header_.Height; y++)
          for (int x = 0; x < info_header_.Width; x++)
            new_data[(info_header_.Height - y - 1) * info_header_.Width +
                     info_header_.Width - x - 1] =
                data_[y * info_header_.Width + x];
        break;
    }

    delete[] data_;
    data_ = new_data;
  }
};

int main() {
  BitMap bmp("suai.bmp");
  bmp.Print();
  bmp.Rotate(Rotate90);
  bmp.Print();
  bmp.Flip(FlipBoth);
  bmp.Print();
  bmp.Save("image_rotate.bmp");
  return 0;
}