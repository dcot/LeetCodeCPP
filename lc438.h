//
// Created by clf on 2023/11/12.
//

#ifndef LEETCODECPP_LC438_H
#define LEETCODECPP_LC438_H
#include <bits/stdc++.h>
using namespace std;
class lc438 {

public:
    vector<int> findAnagrams(string s, string p) {
        int plen = p.length();
        int slen = s.length();
        vector<int> ans;
        if (slen < plen) return ans;
        vector<int> scount(26);
        vector<int> pcount(26);
        for (int i = 0; i < plen ; i++) {
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }

        if (scount == pcount) ans.emplace_back(0);

        for (int i = 0; i < slen - plen; ++i) {
            scount[s[i] - 'a']--;
            scount[s[i+plen] - 'a']++;
            if (scount == pcount) {
                ans.emplace_back(i+1);
            }
        }

        return ans;
    }

};
#endif //LEETCODECPP_LC438_H
