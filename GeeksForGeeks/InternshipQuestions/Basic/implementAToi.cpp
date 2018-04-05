/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method */
int atoi(string str)
{	
	int i, no = 0;
	int power = 1;
	for(i = str.size()-1; i >= 0; i--){
	    
	    if(str[i] == '-'){
	        break;
	    }

	    int x = str[i] - '0';
	    
	    if(x > 9){
	        return -1;
	    }
		
		no += power*x; 
		power *= 10;
	}
	
	return i == 0 ? -no : no;
}