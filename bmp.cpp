#include <bits/stdc++.h>
#include "bmp.h"
#include "matrix.h"

using namespace std;

void BMPIMG24CLR(BMPIMAGE& img){
    img.bmFileHeader.bfType = 0x4D42;
    img.bmFileHeader.bfReserved1 = 0;
    img.bmFileHeader.bfReserved2 = 0;
    img.bmFileHeader.bfOffbits = 14+40;

    img.bmInfoHeader.biSize = 40;
    img.bmInfoHeader.biPlanes = 1;
    img.bmInfoHeader.biBitCount = 24;
    img.bmInfoHeader.biCompression = 0;
    img.bmInfoHeader.biSizeImage = 0;
    img.bmInfoHeader.biXPelsPerMeter = 0;
    img.bmInfoHeader.biYPelsPerMeter = 0;
    img.bmInfoHeader.biClrUsed = 0;
    img.bmInfoHeader.biClrImportant = 0;
}

void BMPwrite(ofstream& file, BMPIMAGE& img){
    writeValue(file, img.bmFileHeader.bfType);
    writeValue(file, img.bmFileHeader.bfSize);
    writeValue(file, img.bmFileHeader.bfReserved1);
    writeValue(file, img.bmFileHeader.bfReserved2);
    writeValue(file, img.bmFileHeader.bfOffbits);
    
    writeValue(file, img.bmInfoHeader.biSize);
    writeValue(file, img.bmInfoHeader.biWidth);
    writeValue(file, img.bmInfoHeader.biHeight);
    writeValue(file, img.bmInfoHeader.biPlanes);
    writeValue(file, img.bmInfoHeader.biBitCount);
    writeValue(file, img.bmInfoHeader.biCompression);
    writeValue(file, img.bmInfoHeader.biSizeImage);
    writeValue(file, img.bmInfoHeader.biXPelsPerMeter);
    writeValue(file, img.bmInfoHeader.biYPelsPerMeter);
    writeValue(file, img.bmInfoHeader.biClrUsed);
    writeValue(file, img.bmInfoHeader.biClrImportant);
    
    file.write(reinterpret_cast<const char*>(img.bmColor.data()), img.bmColor.size());
}

void BMPread(ifstream& file, BMPIMAGE& img){
    readValue(file, img.bmFileHeader.bfType);
    readValue(file, img.bmFileHeader.bfSize);
    readValue(file, img.bmFileHeader.bfReserved1);
    readValue(file, img.bmFileHeader.bfReserved2);
    readValue(file, img.bmFileHeader.bfOffbits);
    
    readValue(file, img.bmInfoHeader.biSize);
    readValue(file, img.bmInfoHeader.biWidth);
    readValue(file, img.bmInfoHeader.biHeight);
    readValue(file, img.bmInfoHeader.biPlanes);
    readValue(file, img.bmInfoHeader.biBitCount);
    readValue(file, img.bmInfoHeader.biCompression);
    readValue(file, img.bmInfoHeader.biSizeImage);
    readValue(file, img.bmInfoHeader.biXPelsPerMeter);
    readValue(file, img.bmInfoHeader.biYPelsPerMeter);
    readValue(file, img.bmInfoHeader.biClrUsed);
    readValue(file, img.bmInfoHeader.biClrImportant);

    int32_t xx=img.bmInfoHeader.biHeight;
    int32_t yy=img.bmInfoHeader.biWidth;
    img.bmColor.clear();
    for(int i=0;i<xx;i++){
        for(int j=0;j<yy;j++){
            uint8_t color;
            readValue(file, color);
            img.bmColor.push_back(color);
            readValue(file, color);
            img.bmColor.push_back(color);
            readValue(file, color);
            img.bmColor.push_back(color);
        }
    }

}

void BMPcolorWrite(BMPIMAGE& img, matrix R,matrix G,matrix B){
    int xx=R.x,yy=R.y;
    img.bmFileHeader.bfSize = 14+40+xx*yy*3;
    img.bmInfoHeader.biWidth = yy;
    img.bmInfoHeader.biHeight = xx;

    uint8_t colorB,colorG,colorR;
    img.bmColor.clear();
    for(int i=1;i<=xx;i++){
        for(int j=1;j<=yy;j++){
            colorB=B(i,j);
            colorG=G(i,j);
            colorR=R(i,j);
            img.bmColor.push_back(colorB);
            img.bmColor.push_back(colorG);
            img.bmColor.push_back(colorR);
        }
        for(int j=1;j<=(4-(yy*3)%4)%4;j++){//宽度对齐
            img.bmColor.push_back(0);
        }
    }
}