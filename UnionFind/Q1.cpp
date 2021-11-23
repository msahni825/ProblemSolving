class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(parent[x]==-1){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unionn(int x, int y){
        int xd=find(x);
        int yd=find(y);
        if(xd!=yd){
            parent[xd]=yd;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        parent.resize(1000000+1,-1);
        for(auto a:nums){
            int n=a;
            int count=0;
            while(n%2==0){
                n>>=1;
                count++;
            }
            if(count){
                unionn(a,2);
            }
            for(int i=3;i<=sqrt(n);i++){
                int c=0;
                while(n%i==0){
                    n=n/i;
                    c++;
                }
                if(c){
                    unionn(a,i);
                }
            }
                if(n>2){
                    unionn(a,n);
                }
            }
        unordered_map<int,int> mp;
        for(auto a:nums){
            mp[find(a)]++;
        }
        int ans=1;
        for(auto m:mp){
            ans=max(ans,m.second);
        }
        return ans;
    }
};
