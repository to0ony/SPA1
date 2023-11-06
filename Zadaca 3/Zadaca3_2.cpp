#include <iostream>
#include <vector>

using namespace std;

using lnum = long long;
using matrix = vector<vector<lnum>>;

matrix baseMatrix = { vector<lnum>{1, 1}, vector<lnum>{1, 0} }; //matrica identiteta

matrix multiplyMatrix (const matrix& A, const matrix& B){
    matrix result;
    for (int i = 0; i < A.size(); i++){ //iteracija kroz iti redak matrice A
        result.push_back(vector<lnum>{}); 
        for (int j = 0; B.size() > 0 && j < B[0].size(); j++){ //iteracija kroz joti stupac matrice B
            lnum value = 0;
            for(int k = 0; k < B.size(); k++) //kti redak matrice B
                value += A[i][k] * B[k][j];
        result[i].push_back(value);
        }
    }
    return result;
}

matrix powMatrix (const matrix& A, lnum n){
    if (n == 1)
        return A;
    if (n % 2 == 0) {
        matrix half_pow = powMatrix(A, n / 2);
        return multiplyMatrix(half_pow, half_pow);
    } else {
        matrix half_pow = powMatrix(A, (n - 1) / 2);
        matrix squared_half_pow = multiplyMatrix(half_pow, half_pow);
        return multiplyMatrix(A, squared_half_pow);
    }
}

lnum fibbCalc (lnum n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    matrix A{baseMatrix};
    matrix res = powMatrix(A, n);
    return res[0][1];
}

void fibbWrite(lnum n){
    cout << "Fibonnaci number of " << n << " is: " << fibbCalc(n) << endl; 
}

int main(){
fibbWrite(16);
fibbWrite(6);
fibbWrite(36);
fibbWrite(55);
}