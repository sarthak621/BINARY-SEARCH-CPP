// User function Template for C++

class Solution {
  public:

    bool isPossible(vector<int> &stalls, int k,int mid,int n){
        int pos=stalls[0];
        int cowCnt=1;
        
        for(int i=1;i<n;i++){
            if(stalls[i]-pos >= mid){
                cowCnt++;
                pos=stalls[i];
            }
            
            if(cowCnt==k){
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high= stalls[n-1] - stalls[0];
        int ans=-1;
        
        while(low<=high){
            int mid=((low+high)/2);
            
            if( isPossible(stalls,k,mid,n)){
                ans=mid;
                low=mid+1; // in search of larger distance
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};