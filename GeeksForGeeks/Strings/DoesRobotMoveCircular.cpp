#include <bits/stdc++.h>
using namespace std;

#define N 0
#define E 1
#define S 2
#define W 3
 
// This function returns true if the given path is circular, else false
bool isCircular(char path[]) {
  int x = 0, y = 0;
  int dir = N;
 
  for (int i=0; path[i]; i++)
  {
      char move = path[i];

      if (move == 'R')
        dir = (dir + 1)%4;
      else if (move == 'L')
        dir = (4 + dir - 1)%4;

      else // if (move == 'G')
      {
         if (dir == N)
            y++;
         else if (dir == E)
            x++;
         else if (dir == S)
            y--;
         else // dir == W
            x--;
      }
  }
 
  return (x == 0 && y == 0);
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          int x = 0, y = 0;
          char dir = 'N';
        for(int i = 0; i  < strlen(str); i++){  
          if(str[i] == 'G'){
                if(dir == 'N'){
                    y++;   
                }
                else if(dir == 'S'){
                    y--;   
                }
                else if(dir == 'E'){
                    x++;   
                }
                else if(dir == 'W'){
                    x--;   
                }
                
          }
          if(str[i] == 'L'){
                if(dir == 'N'){
                    dir = 'W';   
                } 
                else if(dir == 'S'){
                    dir = 'E';   
                }
                else if(dir == 'E'){
                    dir = 'N';   
                }
                else if(dir == 'W'){
                    dir = 'S';   
                }
          }
          if(str[i] == 'R'){
                if(dir == 'N'){
                    dir = 'E';   
                } 
                else if(dir == 'S'){
                    dir = 'W';   
                }
                else if(dir == 'E'){
                    dir = 'S';   
                }
                else if(dir == 'W'){
                    dir = 'N';   
                }
          }
        }
        
        if(x == 0 && y == 0){
            cout<<"Circular"<<endl;
        }
        else{
            cout<<"Not Circular"<<endl;
        }
    }
     return 0;
}