#include <iostream>

using namespace std;

const int MAX = 5;

void defMatr(int mat [][MAX], int qL, int qC);
int contZeros(int mat [][MAX], int qL, int qC, int cFix);

int main()
{
    int cl, cc, nMat[MAX][MAX];
    cin >> cl >> cc;
    defMatr(nMat, cl, cc);
    cout << (contZeros(nMat, cl, cc, cc)*100.0)/(cl*cc) << "% da matriz eh composta por 0.";
    return 0;
}

void defMatr(int mat [][MAX], int qL, int qC){
    for(int l = 0; l < qL; l++){
        for(int c = 0; c < qC; c++){
            cin >> mat[l][c];
        }
    }
}

int contZeros(int mat [][MAX], int qL, int qC, int cFix){
    if(qL == 0){
        return 0;
    }
    else{
        if(qC == 0){
            return contZeros(mat, qL-1, cFix, cFix);
        }
        else{
            return mat[qL-1][qC-1] == 0?1+contZeros(mat, qL, qC-1, cFix):0+contZeros(mat, qL, qC-1, cFix);
        }
    }
}
