#include "bmp.hpp"

#include <iostream>

using namespace std;

// color brightness calculation
uint8_t rgb_brightness(BitMap::BGR color) {
  return (uint8_t)(0.299 * color.Red + 0.587 * color.Green +
                   0.114 * color.Blue);
}

/* BitMap class implementation */

BitMap::BitMap() : data_(nullptr) {}

BitMap::~BitMap() { delete[] data_; }

BitMap::BitMap(const char* filename) : data_(nullptr) { Load(filename); }

void BitMap::Load(const char* filename) {
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

void BitMap::Save(const char* filename) {
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

void BitMap::Print(uint8_t threshold, bool invert, char symbol) {
  // default behavior: print dark pixels as '#', light pixels as ' '
  for (int y = info_header_.Height - 1; y >= 0; y--) {
    for (int x = 0; x < info_header_.Width; x++)
      cout << ((rgb_brightness(data_[y * info_header_.Width + x]) < threshold)
                   ? (invert ? ' ' : symbol)
                   : (invert ? symbol : ' '));
    cout << endl;
  }
}

void BitMap::Rotate(RotateType rotate_type) {
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

void BitMap::Flip(FlipType flip_type) {
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