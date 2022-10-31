#include <cstdint>
#include <fstream>
#include <stdexcept>

class BitMap {
 public:
  struct __attribute__((__packed__)) BitMapFileHeader {
    uint16_t Type;     // (2) Сигнатура "BM"
    uint32_t Size;     // (4) Размер файла
    uint16_t Reserv1;  // (2) Зарезервировано
    uint16_t Reserv2;  // (2) Зарезервировано
    uint32_t Offset;   // (4) Смещение изображения
  };

  struct __attribute__((__packed__)) BitMapInfoHeader {
    uint32_t Size;      // (4) Длина заголовка
    uint32_t Width;     // (4) Ширина изображения, точки
    uint32_t Height;    // (4) Высота изображения, точки
    uint16_t Planes;    // (2) Число плоскостей
    uint16_t BitCount;  // (2) Глубина цвета, бит на точку
    uint32_t Compress;  // (4) Тип компрессии
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

  BitMap();
  ~BitMap();

  BitMap(const char* filename);
  void Load(const char* filename);
  void Save(const char* filename);

  void Print(uint8_t threshold = 127, bool invert = false, char symbol = '#');

  void Rotate(RotateType rotate_type);
  void Flip(FlipType flip_type);

 private:
  BitMapFileHeader file_header_;
  BitMapInfoHeader info_header_;
  BGR* data_;
};
