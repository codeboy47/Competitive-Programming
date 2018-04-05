/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,
                      string pattern)
{
       unordered_map<char,char> hash;
       vector<string> arr;
       for(int i = 0; i < dict.size(); i++){
           bool flag = true;
           for(int j = 0; j < pattern.size(); j++){
               if(hash.count(pattern[j]) == 0){
                   hash[pattern[j]] = dict[i][j]; 
               }
               else{
                   if(hash[pattern[j]] != dict[i][j]){
                       flag = false;
                       break;
                   }
               }
           }
           hash.clear();
           if(flag == true && dict[i].size() == pattern.size()){
               arr.push_back(dict[i]);
           }
           
       }
       
       return arr;
}