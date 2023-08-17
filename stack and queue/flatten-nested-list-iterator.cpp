#include <bits/stdc++.h>
using namespace std;
// ******** copyed from yt (Aditya mahajan)
class NestedIterator
{
public:
    vector<int> output;
    int i = 0;
    void helper(vector<NestedIterator> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                output.push_back(nestedList[i].getInteger);
            }
            else
            {
                helper(nestedList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        helper(nestedList);
    }

    int next()
    {
        // int ans=-1;
        // if(i<output.size()){
        //     ans=output[i];
        //     i++;
        // }
        int ans = output.at(i);
        i++;
        return ans;
    }

    bool hasNext()
    {
        if (i < output.size())
        {
            return true;
        }
        else
            return false;
    }
};
//*********
int main()
{

    return 0;
}