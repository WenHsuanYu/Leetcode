class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;
        unordered_map<int,int> umap;
        int count=0;
        for(int i:nums)
            umap[i]++;
        
        for(auto & it:umap)
            freq[it.second].push_back(it.first);
        
        for(int j=nums.size();j>=0;j--)
        {  
            if(freq[j].empty()==false)
            {
                
                for(auto n:freq[j])
                    res.push_back(n);
            }
            
            if(res.size()==k)
                break;
        }   
        
       
         return res;     
    }
};