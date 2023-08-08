#include <bits/stdc++.h>
using namespace std;
//****** my approach but stuck one testcase because somehow leetcode find randomlele in arr
class RandomizedCollection
{
public:
    vector<pair<int, int>> v;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == val)
            {
                v[i].second++;
                return false;
            }
        }
        v.push_back({val, 1});
        return true;
    }

    bool remove(int val)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == val)
            {
                if (v[i].second > 1)
                {
                    v[i].second--;
                    return true;
                }
                else
                {
                    v.erase(v.begin() + i);
                    return true;
                }
            }
        }
        return false;
    }

    int getRandom()
    {
        int size = v.size();
        int randompos = rand() % size;
        return v[randompos].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//********  copyed approach (from leetcode)

int main()
{

    return 0;
}