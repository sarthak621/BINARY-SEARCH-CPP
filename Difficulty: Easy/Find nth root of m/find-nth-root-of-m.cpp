class Solution {
  public:

       int pow(int x,int n){
            
            if(n==0) return 1;
            
            if(n%2==0){
                //even
                return pow(x*x,n/2);
            }
            
            else{
                //it means it is odd
                return x*pow(x*x, (n-1)/2);
            }
        }

    int nthRoot(int n, int m) {
        // Code here.
        //now we have to find the root
        

        // linear search
        for(int i=1;i<=m;i++){
            if(pow(i,n)==m){
                return i;
                break;
            }
            
            else if(pow(i,n)>m){
                break;
            }
        }
        
        return -1;
    }
};