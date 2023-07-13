int NthRoot(int n, int m) {
  // Write your code here.
   for(int i=0;pow(i,n)<=m;i++){   

      if(pow(i,n)==m){      

       return i;  

      } 
  } 
 return -1; 
}