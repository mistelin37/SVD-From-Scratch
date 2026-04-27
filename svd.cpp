#include <bits/stdc++.h>
#include "matrix.h"
#include "svd.h"

using namespace std;

vector<SVDresult> SVD(matrix A, int num, int t){
    vector<SVDresult> res;
    matrix A1=A;
    while(num--){
        matrix v(A1.y,1);
        for(int i=1;i<=A1.y;i++) v(i,1)=(double)rand() / RAND_MAX;

        for(int i=1;i<=t;i++){
            matrix w=A1.T()*A1*v;
            v=w*(1/w.abs());
        }

        double sigma=(A1*v).abs();
        matrix u=A*v*(1/sigma);
        A1=A1-u*v.T()*sigma;

        res.push_back(SVDresult{u,v,sigma});
    }
    return res;
}

double lossCalculate(matrix A, vector<SVDresult> svd){
    matrix A1(A.x,A.y);

    for(int i=0;i<svd.size();i++)
        A1=A1+svd[i].u*svd[i].v.T()*svd[i].sigma;

    return (A-A1).abs()/A.abs();
}

matrix lowRankApprox(matrix A, vector<SVDresult> svd){
    matrix A1(A.x,A.y);

    for(int i=0;i<svd.size();i++)
        A1=A1+svd[i].u*svd[i].v.T()*svd[i].sigma;

    return A1;
}
