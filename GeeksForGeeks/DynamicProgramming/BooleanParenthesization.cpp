#include <bits/stdc++.h>
using namespace std;

int waysToParenthesize(string symbols, string operators){

    int n = symbols.size();

    int T[n][n];
    int F[n][n];
    int total[n][n];

    for(int i = 0; i < n; i++){
        T[i][i] = (symbols[i] == 'T') ? 1 : 0;
        F[i][i] = (symbols[i] == 'F') ? 1 : 0;
    }

    for(int i = 0; i < n; i++){
        total[i][i] = T[i][i] + F[i][i];
    }

    for(int x = 1; x < n; x++){
        int i = 0;
        for(int j = x; j < n; i++,j++){
            int sumT = 0;
            int sumF = 0;
            for(int k = i; k < j; k++){
                if(operators[k] == '&'){
                    sumT += T[i][k]*T[k+1][j];
                    sumF += total[i][k]*total[k+1][j] - T[i][k]*T[k+1][j];
                }
                if(operators[k] == '|'){
                    sumT += total[i][k]*total[k+1][j] - F[i][k]*F[k+1][j];
                    sumF += F[i][k]*F[k+1][j];
                }
                if(operators[k] == '^'){
                    sumT += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
                    sumF += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
            }
            T[i][j] = sumT%1003;
            F[i][j] = sumF%1003;
            total[i][j] = T[i][j] + F[i][j];
        }
    }

    return T[0][n-1];

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        string str;
        cin>>str;

        string symbols = "", operators = "";
        for(int i = 0; i < n; i++){
            if(str[i] == '&' || str[i] == '|' || str[i] == '^'){
                operators += str[i];
            }
            else{
                symbols += str[i];
            }
        }

        cout<<waysToParenthesize(symbols,operators)<<endl;

    }

    return 0;
}
