#include <bits/stdc++.h>
#include "bmp.h"
#include "matrix.h"

using namespace std;

int main(){
    ofstream file("out.bmp", std::ios::binary);
    BMPIMAGE img;

    BMPIMG24CLR(img);
    BMPcolorWrite(img, 256, 256);
    BMPwrite(file, img);

    return 0;
}