#include <bits/stdc++.h>
#include "bmp.h"
#include "matrix.h"

using namespace std;

int main(){
    ifstream file("img1.bmp", std::ios::binary);
    BMPIMAGE img;

    BMPread(file, img);

    cout<<"==========information=========="<<endl;
    cout<<"Format:\""<<(char)img.bmFileHeader.bfType<<(char)(img.bmFileHeader.bfType>>8)<<"\""<<endl;
    cout<<"File_size:"<<img.bmFileHeader.bfSize<<" Bytes"<<endl;
    cout<<"==============================="<<endl;
    cout<<"Width:"<<img.bmInfoHeader.biWidth<<" px"<<endl;
    cout<<"Height:"<<img.bmInfoHeader.biHeight<<" px"<<endl;
    cout<<"Bit_depth:"<<img.bmInfoHeader.biBitCount<<" Bits"<<endl;
    cout<<"Compression:"<<img.bmInfoHeader.biCompression<<endl;
    cout<<"SizeImage:"<<img.bmInfoHeader.biSizeImage<<" Bytes"<<endl;
    cout<<"XPelsPerMeter:"<<img.bmInfoHeader.biXPelsPerMeter<<" px per meter"<<endl;
    cout<<"YPelsPerMeter:"<<img.bmInfoHeader.biYPelsPerMeter<<" px per meter"<<endl;
    
    cin.get(); 
    return 0;
}