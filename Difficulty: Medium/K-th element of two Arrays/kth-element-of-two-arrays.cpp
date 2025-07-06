class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        
        //similar to the median of two sorted arrays
        
        if(a.size()>b.size()){
            return kthElement(b,a,k);
        }
        
        //
        int n=a.size();
        int m=b.size();
        
        int low=max(0,k-m) , high=min(n,k);
        while(low<=high){
            int Px=(low+high)/2;
            int Py= k-Px;
            
            int l1= (Px==0) ? INT_MIN : a[Px-1];
            int l2= (Py==0) ? INT_MIN : b[Py-1];
            
            int r1= (Px==n) ? INT_MAX : a[Px];
            int r2= (Py==m) ? INT_MAX : b[Py];
            
            
            //checking the validity
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            
            else if(l2>r1){
                //dec elem in l2 and inc in l1
                low=Px+1;
            }
            else{
                high=Px-1;
            }
        }
        return -1;
    }
};