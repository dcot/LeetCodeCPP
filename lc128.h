//
// Created by clf on 2023/7/22.
//

#ifndef LEETCODECPP_LC128_H
#define LEETCODECPP_LC128_H
#include <bits/stdc++.h>
using namespace std;
class lc128 {
public:
    int longestConsecutive(const vector<int>& nums) {

        unordered_set<int> set;
        for (const int &num : nums) {
            set.emplace(num);
        }

        int max = 0;
        for (const int &num : nums) {
            int currentMax = 1;
            if (!set.count(num-1)) {
                int currentNum = num;
                while(set.count(currentNum+1)) {
                    currentNum++;
                    currentMax++;
                }
            }
            max = std::max(max, currentMax);
        }

        return max;
    }
};
#endif //LEETCODECPP_LC128_H
