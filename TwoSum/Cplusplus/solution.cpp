#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> hashTable;

        // For each element in the vector
        for (int i = 0; i < nums.size(); i++) {        
            // Calculate the target - the current element
            int targetMinusElement = target - nums[i];

            // Check if this value exists in our hash table
            // If yes, then we found the pair
            std::unordered_map<int,int>::const_iterator search = hashTable.find(targetMinusElement);
            if (search != hashTable.end()) { 
                // hashTable.insert({vec[i], sumMinusElement}); // [arr[i], sumMinusElement]
                if (search->second > i) {
                    return {i, search->second};
                }
                else {
                    return {search->second, i};
                }
            }

            // Add the current element to the hash table as a {value, index} pair
            hashTable.insert({nums[i], i});
        }

        // If there is no solution, return the impossible pair of indices [-1, -1]
        // Our assumption of exactly one solution guarantees us that this will not happen, but this avoids any errors if there happens to be bad input
        // Note, however, that if there are multiple solutions, this function will only return the first one it finds.
        return {-1, -1};
    };
};