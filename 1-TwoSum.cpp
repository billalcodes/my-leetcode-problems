/*Problem:
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);  
        vector<int> temp(nums.size());
        // for(int i = 0; i < nums.size() ; i++){
        //     temp[i] = nums[i];
        // }
        for(int i = 0; i < nums.size(); i++){
            int temp1 = nums[i];//store the checking index in temporary vae
            for(int j = i + 1 ; j< temp.size(); j++){   //check the stored index with all other elemnts preceeding it
                if(temp1 + nums[j] == target){  //if they add up to target return the result
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
           
        }
        return result;
    }
};

