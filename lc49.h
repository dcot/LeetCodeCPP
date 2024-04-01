//
// Created by clf on 2023/7/21.
//

#ifndef LEETCODECPP_LC49_H
#define LEETCODECPP_LC49_H
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
class lc49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(),key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it!= map.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};
#endif //LEETCODECPP_LC49_H
