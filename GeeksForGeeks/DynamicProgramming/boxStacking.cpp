#include <bits/stdc++.h>
using namespace std;


class Box{
public:
  int h, w, l;
};

bool compare (Box &a, Box &b) {
    if(b.l*b.w == a.l*a.w)
        return a.h > b.h;
    return a.l*a.w > b.l*b.w; // decreasing order
}

int maxHeight(int height[],int width[],int length[],int n){

    // always keep length greater than width
    for(int i = 0; i < n; i++){
        if(width[i] >= length[i]) {
                int temp=width[i];
                width[i]=length[i];
                length[i]=temp;
            }
    }

    Box rot[3*n];
    int index = 0;
    for (int i = 0; i < n; i++){

      rot[index].h = height[i];
      rot[index].l = length[i];
      rot[index].w = width[i];
      index++;

      // First rotation of box
      rot[index].h = length[i];
      rot[index].l = max(width[i],height[i]); // length should be greater than width always
      rot[index].w = min(width[i],height[i]);
      index++;

      // Second rotation of box
      rot[index].h = width[i];
      rot[index].l = max(length[i],height[i]); // length should be greater than width always
      rot[index].w = min(length[i],height[i]);
      index++;
   }

   int N = 3*n; // Now the number of boxes is 3n

   sort(rot, rot+N, compare); // sort on the basis of lxb base area

    for (int i = 0; i < N; i++ )
       printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].l);

   int dp[N];
   dp[0] = rot[0].h;
   for (int i = 1; i < N; i++ ){
      int ans = 0;
      for (int j = i-1; j >= 0; j--){
         if(rot[i].w < rot[j].w && rot[i].l < rot[j].l ){
              ans = max(ans,dp[j]);
          }
      }
      dp[i] = ans + rot[i].h;
   }

   int maxH = -1;
   for ( int i = 0; i < N; i++ )
      maxH = max(maxH,dp[i]);

   return maxH;
}
