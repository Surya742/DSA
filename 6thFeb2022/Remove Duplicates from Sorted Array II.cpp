// Remove Duplicates from Sorted Array II

// Given an integer array nums sorted in non-decreasing order, 
// remove some duplicates in-place such that each unique element 
// appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some 
// languages, you must instead have the result be placed in the first 
// part of the array nums. More formally, if there are k elements after 
// removing the duplicates, then the first k elements of nums should hold 
// the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.
// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 2) return 2;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int cnt = 1;
            int ref = 0;
            if(i+1 <= nums.size()-1){
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j] == x){
                        if(cnt >= 2){
                            nums.erase(nums.begin()+j);
                            j = j-1;
                        }
                        cnt++;
                        ref = j;
                    }
                }
            }
            if(ref){
                i = ref;
            }
        }
        return nums.size();
    }
};