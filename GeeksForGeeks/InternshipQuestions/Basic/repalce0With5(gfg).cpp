/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// This is math question

/*you are required to complete this method*/
int convertFive(int n){

     int ans = 0;
     int power = 1;
     while(n !=  0){
          if(n%10 == 0){
               ans += 5*power;
          }else{
               ans += (n%10)*power;
          }
          n /= 10;
          power *= 10;
     }
    return ans;
}