#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int max(int a, int b){
    return (a>b) ? a : b;
}

char* lcs(char* x, char* y, int a, int b){
    int temp[a+1][b+1];

    for (int i=0; i<=a; i++){
        for (int j=0; j<=b; j++) {
            if (i == 0 || j == 0) {
                temp[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1]){
                temp[i][j] = temp[i - 1][j - 1] + 1;
            }
            else {
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
            }
        }
    }

    int index = temp[a][b];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = a, j = b;
    while (i > 0 && j > 0){
        if (x[i-1] == y[j-1]){
            lcs[index-1] = x[i-1];
            i--; j--; index--;
        }
        else if (temp[i-1][j] > temp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
  //  cout << lcs;
    return lcs;
}

string longestCommonSubseq(string x, string y){
    char x1[x.length()];
    char y1[y.length()];

    for(int i =0; i <sizeof(x1);i++){
        x1[i] = x[i];
    }
    for(int i =0; i <sizeof(y1);i++){
         y1[i] = y[i];
    }

    string final(lcs(x1, y1, sizeof(x1), sizeof(y1)));

    return final;
}


int main(int argc, char* argv[]) {
    string string1;
    string string2;

    cin >> string1;
    cin >> string2;

    cout << longestCommonSubseq(string1, string2);

    return 0;
}
