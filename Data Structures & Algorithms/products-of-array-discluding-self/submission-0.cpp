class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
     vector<int> result(nums.size(),0);

     int zerocount =0;
     int zeropos;
     int prod=1;

     for(int i=0;i<nums.size();i++){
        if(nums[i] ==0){
            zerocount++;
            zeropos=i;
        }
        else{
            prod*=nums[i];
        }
     }
   
    for(int i=0;i<nums.size();i++){
        if(zerocount>=2){
            return result;
        }
        else if(zerocount>0){
            if(i!= zeropos){
                result[i]=0;
            }
            else{
                result[i]=prod;
            }


        }
        else{
              result[i]=prod/nums[i];
        }    
        
    }

    return result;

    }
};
