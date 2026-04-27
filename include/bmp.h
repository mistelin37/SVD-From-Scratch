#include <bits/stdc++.h>
#include "matrix.h"

using namespace std;

struct BMPFILEHEADER{
    uint16_t bfType;
    uint32_t bfSize;         
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffbits; 
};

struct BMPINFOHEADER{
    uint32_t biSize;       
    int32_t biWidth;            
    int32_t biHeight;           
    uint16_t biPlanes;      
    uint16_t biBitCount;   
    uint32_t biCompression; 
    uint32_t biSizeImage;   
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;     
    uint32_t biClrImportant;
};

struct BMPIMAGE{
    BMPFILEHEADER bmFileHeader;
    BMPINFOHEADER bmInfoHeader;
    vector<uint8_t> bmColor;
};

template<typename T>
void writeValue(ofstream& file, const T& value) {
    file.write(reinterpret_cast<const char*>(&value), sizeof(T));
}
template<typename T>
void readValue(ifstream& file, T& value) {
    file.read(reinterpret_cast<char*>(&value), sizeof(T));
}

void BMPIMG24CLR(BMPIMAGE& img);
void BMPwrite(ofstream& file, BMPIMAGE& img);
void BMPread(ifstream& file, BMPIMAGE& img);
void BMPcolorWrite(BMPIMAGE& img, matrix R,matrix G,matrix B);