//
// Created by clf on 2023/10/15.
//

#ifndef LEETCODECPP_LC189_H
#define LEETCODECPP_LC189_H
#include<vector>
#include<utility>
using namespace std;
class lc189 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < k) {
            k =  k % nums.size();
        }
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }

    void reverse(vector<int>& nums, int l, int r) {
        int left = l;
        int right = r;
        while (left < right) {

            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
#endif //LEETCODECPP_LC189_H
