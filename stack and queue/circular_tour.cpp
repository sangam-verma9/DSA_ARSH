#include <bits/stdc++.h>
using namespace std;
// ****** Naive approach ********
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump arr[], int n)
    {
        // Your code here
        int start = 0;
        int end = 1;

        int curr_petrol = arr[start].petrol - arr[start].distance;

        /* Run a loop while all petrol pumps are not visited.
        And we have reached first petrol pump again with 0 or more petrol */
        while (end != start || curr_petrol < 0)
        {
            // If current amount of petrol in truck becomes less than 0, then
            // remove the starting petrol pump from tour
            while (curr_petrol < 0 && start != end)
            {
                // Remove starting petrol pump. Change start
                curr_petrol -= arr[start].petrol - arr[start].distance;
                start = (start + 1) % n;

                // If 0 is being considered as start again, then there is no
                // possible solution
                if (start == 0)
                    return -1;
            }

            // Add a petrol pump to current tour
            curr_petrol += arr[end].petrol - arr[end].distance;

            end = (end + 1) % n;
        }

        // Return starting point
        return start;
    }
};
//**********  optimized approach ********
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int balence = 0;
        int start = 0;
        int kami = 0;
        for (int i = 0; i < n; i++)
        {
            balence += p[i].petrol - p[i].distance;
            if (balence < 0)
            {
                start = i + 1;
                kami += balence;
                balence = 0;
            }
        }
        if (balence + kami >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
//*************
int main()
{

    return 0;
}