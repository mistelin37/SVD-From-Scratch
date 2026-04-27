#include <bits/stdc++.h>
#include "matrix.h"

using namespace std;

struct SVDresult {
    matrix u;
    matrix v;
    double sigma;
};

vector<SVDresult> SVD(matrix A, int num, int t);
double lossCalculate(matrix A, vector<SVDresult> svd);
matrix lowRankApprox(matrix A, vector<SVDresult> svd);
