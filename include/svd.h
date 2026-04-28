#ifndef SVD_H
#define SVD_H

#include <bits/stdc++.h>
#include "matrix.h"

using namespace std;

extern int total_num;

struct SVDresult {
    matrix u;
    matrix v;
    double sigma;
};

vector<SVDresult> SVD(matrix A, int num, int t);
vector<SVDresult> adaptiveSVD(matrix A, double loss, int t);
double lossCalculate(matrix A, vector<SVDresult> svd);
double incrementalLossCalculate(matrix A, vector<SVDresult> svd, matrix B);
matrix lowRankApprox(matrix A, vector<SVDresult> svd);
matrix incrementalLowRankApprox(matrix A, vector<SVDresult> svd, matrix B);

#endif