#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для использования функции exit()

/*
  Заголовок файла (BitMapFileHeader)
  Type	2	0	Сигнатура "BM"
  Size	4	2	Размер файла
  Reserved 1	2	6	Зарезервировано
  Reserved 2	2	8	Зарезервировано
  OffsetBits	4	10	Смещение изображения от начала файла

  Информационный заголовок (BitMapInfoHeader)
  Size	4	14	Длина заголовка
  Width	4	18	Ширина изображения, точки
  Height	4	22	Высота изображения, точки
  Planes	2	26	Число плоскостей
  BitCount	2	28	Глубина цвета, бит на точку
  Compression	4	30	Тип компрессии (0 - несжатое изображение)
  SizeImage	4	34	Размер изображения, байт
  XpelsPerMeter	4	38	Горизонтальное разрешение, точки на метр
  YpelsPerMeter	4	42	Вертикальное разрешение, точки на метр
  ColorsUsed	4	46	Число используемых цветов (0 - максимально возможное для данной глубины цвета)
  ColorsImportant	4	50	Число основных цветов
*/

typedef struct {
  uint16_t  Type;             //  2  0   Сигнатура "BM"
  uint32_t  Size;             //  4  2   Размер файла
  uint8_t   Reserved;         //  2  6   Зарезервировано
  uint16_t  Reserved;         //  2  8   Зарезервировано
  uint32_t  OffsetBits;       //  4  10  Смещение изображения от начала файла
} BitMapFileHeader;

typedef struct {
  uint32_t  Size;             //  4  14  Длина заголовка
  uint32_t  Width;            //  4  18  Ширина изображения, точки
  uint32_t  Height;           //  4  22  Высота изображения, точки
  uint16_t  Planes;           //  2  26  Число плоскостей
  uint16_t  BitCount;         //  2  28  Глубина цвета, бит на точку
  uint32_t  Compression;      //  4  30  Тип компрессии
  uint32_t  SizeImage;        //  4  34  Размер изображения, байт
  uint32_t  XpelsPerMeter;    //  4  38  Горизонтальное разрешение, точки на метр
  uint32_t  YpelsPerMeter;    //  4  42  Вертикальное разрешение, точки на метр
  uint32_t  ColorsUsed;       //  4  46  Число используемых цветов
  uint32_t  ColorsImportant;  //  4  50  Число основных цветов
} BitMapInfoHeader;

typedef struct {

} ColorTable;

typedef struct {

} BitMap;

int main() {
	using namespace std;
 
	// ifstream используется для чтения содержимого файла.
	// Попытаемся прочитать содержимое файла SomeText.txt
	ifstream inf("input.bmp", ios::binary);
 
	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf) {
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
    cerr << "could not be opened for reading" << endl;
		exit(1);
	}

	// Пока есть данные, которые мы можем прочитать,
	while (inf) {
		// то перемещаем эти данные в строку, которую затем выводим на экран
    string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}
}


static unsigned short read_u16(FILE *fp) {
    unsigned char b0, b1;
    b0 = getc(fp);
    b1 = getc(fp);
    return ((b1 << 8) | b0);
}
 
 
static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}
 
 
static int read_s32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((int)(((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}