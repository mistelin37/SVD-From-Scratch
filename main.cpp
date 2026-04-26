#include <bits/stdc++.h>
#include "bmp.h"

using namespace std;
/*
struct matrix{
    int x;
    int y;
    vector<double> data;
    matrix() : x(0), y(0) {}
    matrix(int xx,int yy) : x(xx), y(yy), data(xx*yy) {}

    double& operator()(int i,int j){
        return data[(i-1)*y+(j-1)];
    }
    
    void print(){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cout<<(*this)(i,j)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    matrix operator+(matrix M){
        if(x!=M.x||y!=M.y) return matrix();
        matrix ans(x,y);
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                ans(i,j)=(*this)(i,j)+M(i,j);
        return ans;
    }
    matrix operator-(){
        matrix ans(x,y);
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                ans(i,j)=-(*this)(i,j);
        return ans;
    }
    matrix operator-(matrix M){
        return *this+(-M);
    }
    matrix operator*(matrix M){
        if(y!=M.x) return matrix();
        matrix ans(x,M.y);
        for(int i=1;i<=x;i++)
            for(int j=1;j<=M.y;j++){
                double tmp=0;
                for(int k=1;k<=y;k++)
                    tmp+=(*this)(i,k)*M(k,j);
                ans(i,j)=tmp;
            }
        return ans;
    }
    matrix operator*(double k){
        matrix ans(x,y);
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                ans(i,j)=k*(*this)(i,j);
        return ans;        
    }
    matrix T(){
        matrix ans(y,x);
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                ans(j,i)=(*this)(i,j);
        return ans;        
    }
};
*/

int main(){
    ofstream file("out.bmp", std::ios::binary);
    BMPIMAGE img;

    BMPIMG24CLR(img);
    BMPcolorWrite(img, 256, 256);
    BMPwrite(file, img);

    return 0;
}