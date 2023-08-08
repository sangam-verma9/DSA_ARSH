#include <bits/stdc++.h>
using namespace std;
int ceilSearch(int arr[], int low, int high, int x)
{
    int ans = -1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 20;
    cout << "hello world" << endl;
    int index = ceilSearch(arr, 0, n - 1, x);
    cout << index << endl;
    if (index == -1)
        cout << "Ceiling of " << x
             << " doesn't exist in array ";
    else
        cout << "ceiling of " << x << " is " << arr[index];

    return 0;
}
