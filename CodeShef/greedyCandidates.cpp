#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){

     int t;
     int minSalary[10000];
     int offeredSalary[10000];
     int maxJobOffers[10000];
     string arr[10000];
     int qual[10000][10000];
     scanf("%d",&t);
     while(t--){
          int n,m;
          scanf("%d %d", &n,&m);

          for(int i = 0; i < n; i++){
               scanf("%d", &minSalary[i]);
          }

          for(int i = 0; i < m; i++){
               scanf("%d %d",  &offeredSalary[i], &maxJobOffers[i]);
          }

          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          for(int i = 0; i < n; i++){
               for(int j = 0; j < arr[i].length(); j++){
                    qual[i][j] = arr[i][j] - 48;
               }
          }

          int count = 0;
          bool flag = true;
          int company = -1;
          bool companyLeft[10000];
          memset(companyLeft,false,sizeof(bool)*m);

          long sum = 0;
          for(int i = 0; i < n; i++){
               flag = true;
               company = -1;
               int salary = -1;
               for(int j = 0; j < m; j++){
                    if(qual[i][j] == 1 && maxJobOffers[j] > 0 && offeredSalary[j] >= minSalary[i]){
                              if(salary < offeredSalary[j]){
                                   salary = offeredSalary[j];
                                   company = j;
                              }
                    }
               }
               if(company != -1){
                    count++;
                    sum = sum + salary;
                    maxJobOffers[company]--;
                    companyLeft[company] = true;
               }
          }

          int left = 0;
          for(int i = 0; i < m; i++){
               if(companyLeft[i] == false){
                    left++;
               }
          }

          printf("%d %ld %d\n",count,sum,left);

     }

     return 0;
}
