#include <bits/stdc++.h>
using namespace std;
//************ first think (brute force)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        int n = strs.size();
        if (n == 0)
            return ans;
        vector<pair<string, vector<int>>> dic;
        for (int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            bool flag = 0;
            for (int j = 0; j < dic.size(); j++)
            {
                if (dic[j].first == s)
                {
                    dic[j].second.push_back(i);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                dic.push_back({s, {i}});
            }
        }
        // for(int i=0;i<dic.size();i++){
        //     cout<<dic[i].first<<" ";
        //     for(int j=0;j<dic[i].second.size();j++){
        //         cout<<dic[i].second[j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int i = 0; i < dic.size(); i++)
        {
            vector<string> temp;
            for (int j = 0; j < dic[i].second.size(); j++)
            {
                temp.push_back(strs[dic[i].second[j]]);
            }
            if (temp.size() != 0)
            {
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
//********  better solution (copyed from leetcode)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
//***********
int main()
{

    return 0;
}