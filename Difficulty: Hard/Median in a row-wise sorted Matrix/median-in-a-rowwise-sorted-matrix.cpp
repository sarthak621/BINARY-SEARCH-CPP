// User function template for C++

class Solution {
  public:
    
    
    int upperBound(vector<int>mat,int x, int n,int m){
        int low=0;
        int high=m-1;
        
        int ans=m;
        while(low<=high){
            int mid=(low+high)/2;
            if(mat[mid]>x){
                ans=mid;
                //now trying to find more mat[mid]>x which is just greater than our x
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
    
    int small_elem(vector<vector<int>> &mat,int mid, int n,int m){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+= upperBound(mat[i],mid,n,m);
        }
        
        return cnt;
    }
    
    
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(); //row 
        int m=mat[0].size(); //col
        //finding the low and high to define the range 
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
                //since we know all the row are sorted .. so that low and high lies at first and last resp
                low=min(mat[i][0], low);
                high=max(mat[i][m-1], high);
            
        }
        
        //checking up the requirement
        int req=(n*m)/2;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            //finding up the no. of smaller Elements than our mid 
            int smallerElements= small_elem(mat,mid,n,m);
            
            if(smallerElements<=req){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return low;
    }
};
