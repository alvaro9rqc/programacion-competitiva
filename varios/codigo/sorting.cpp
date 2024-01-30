#include <bits/stdc++.h>

using namespace std;

void merge(int le, int ri, vector<int> &nums)
{
}

void mergeSort(int le, int ri, vector<int> &nums) // sort elements in array nums from [le, le+1, ...., ri]
{
    if (le == ri) // base case when n = 1
    {
        return;
    }
    if (le < ri) // n > 1, n is the total number of elements for sorting
    {
        int mid = (le + ri) / 2;
        mergeSort(le, mid, nums);
        mergeSort(mid + 1, ri, nums);
        // merge
        // merge(le, ri, nums);
        // given that nums[le, ..., mid] && nums[mid+1, ... , ri] ares sorted, how can I sorted the array [le, ...,,ri] ?
        // index p1                p2
        //     [le, ...., mid]    [mid + 1, ..., ri]
        int p1 = le,
            p2 = mid + 1;
        vector<int> tmp;
        while (p1 <= mid || p2 <= ri)
        {
            if (p1 <= mid && p2 <= ri)
            {
                if (nums[p1] <= nums[p2])
                {
                    tmp.push_back(nums[p1]);
                    p1++;
                }
                else
                {
                    tmp.push_back(nums[p2]);
                    p2++;
                }
            }
            else
            {
                if (p1 <= mid)
                {
                    tmp.push_back(nums[p1]);
                    p1++;
                }
                else
                {
                    tmp.push_back(nums[p2]);
                    p2++;
                }
            }
        }
        int i = 0;
        for (int elem : tmp)
        {
            nums[le + i] = elem;
            i++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 3, 1, 8, 4};

    return 0;
}
