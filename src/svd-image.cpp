#include <bits/stdc++.h>
#include "matrix.h"
#include "bmp.h"
#include "svd.h"

using namespace std;

int main(){
    ifstream input("./img/img1.bmp", std::ios::binary);
    ofstream output("./img/out.bmp", std::ios::binary);
    BMPIMAGE img;
    int x=16;
    int y=16;
    int k=1;
    int t=5;

    cin>>x>>y>>k;

    BMPread(input, img);
    int width=img.bmInfoHeader.biWidth;
    int rowsize=((width*3+3) & ~3);
    int height=img.bmInfoHeader.biHeight;
    
    int cntx=ceil((double)height/x);
    int cnty=ceil((double)width/y);

    matrix R(height,width);
    matrix G(height,width);
    matrix B(height,width);
    
    matrix R1(height,width);
    matrix G1(height,width);
    matrix B1(height,width);
    
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            B(i+1,j+1)=img.bmColor[(i*rowsize+j*3)+0];
            G(i+1,j+1)=img.bmColor[(i*rowsize+j*3)+1];
            R(i+1,j+1)=img.bmColor[(i*rowsize+j*3)+2];
        }
    }

    for(int i=0;i<cntx;i++){
        for(int j=0;j<cnty;j++){
            int blockH=min(x, height - i*x);
            int blockW=min(y, width - j*y);
            matrix P1(blockH,blockW);
            matrix P2(blockH,blockW);
            matrix P3(blockH,blockW);
            
            for(int p=1;p<=blockH;p++){
                for(int q=1;q<=blockW;q++){
                    P1(p,q)=B(i*x+p,j*y+q);
                    P2(p,q)=G(i*x+p,j*y+q);
                    P3(p,q)=R(i*x+p,j*y+q);
                }
            }

            matrix Q1=lowRankApprox(P1, SVD(P1, k, t));
            matrix Q2=lowRankApprox(P2, SVD(P2, k, t));
            matrix Q3=lowRankApprox(P3, SVD(P3, k, t));

            for(int p=1;p<=blockH;p++){
                for(int q=1;q<=blockW;q++){
                    Q1(p,q)=min(max(round(Q1(p,q)),0.0),255.0);
                    Q2(p,q)=min(max(round(Q2(p,q)),0.0),255.0);
                    Q3(p,q)=min(max(round(Q3(p,q)),0.0),255.0);

                    B1(i*x+p,j*y+q)=Q1(p,q);
                    G1(i*x+p,j*y+q)=Q2(p,q);
                    R1(i*x+p,j*y+q)=Q3(p,q);                    
                }
            }
                    
        }
    }

    BMPIMG24CLR(img);
    BMPcolorWrite(img,R1,G1,B1);
    BMPwrite(output, img);

    return 0;
}