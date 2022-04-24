/*** 
 * @Date: 2022-04-23 10:20:39
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-24 17:10:23
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;

#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
void merge(vector<long long int>&nums, long long int lbegin, long long int lend,long long int rbegin,long long int rend,long long int index,vector<long long int>&cnt) {
    long long int p1 = lbegin, p2 = rbegin;
    vector<long long int> tmp(rend - lbegin + 1);
    long long int i = 0;
    long long int pairsCnt = 0;
    while (p1 <= lend && p2 <= rend) {
        if (nums[p1] <= nums[p2]) {
            tmp[i++] = nums[p1++];
        }
        else if(nums[p1]>nums[p2]){
            pairsCnt += (lend - p1 + 1);
            tmp[i++] = nums[p2++];
        }
    }
    while (p1 <= lend) {
        tmp[i++] = nums[p1++];
    }
    while (p2 <= rend) {
        tmp[i++] = nums[p2++];
    }
    for (int i = 0; i < tmp.size(); i++) {
        nums[lbegin++] = tmp[i];
    }
    cnt[index] += pairsCnt;
}
void mergeSort(vector<long long int>& nums, long long int begin, long long int end, long long int index,vector<long long int>& cnt) {
    if (begin == end)
        return;
    long long int mid = (end - begin) / 2 + begin;
    mergeSort(nums, begin, mid,index-1,cnt);
    mergeSort(nums, mid + 1, end,index-1,cnt);
    merge(nums, begin, mid, mid + 1, end,index,cnt);
}

void print(vector<long long> &nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    long long int n;
    cin >> n;
    long long int cnt = pow(2, n);
    vector<long long int> nums;
    while (cnt--) {
        long long int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    vector<long long int> order(n+1,0);//保存不同长度的顺序对个数
    vector<long long int> reOrder(n+1,0);//保存不同长度的逆序对个数
    vector<long long int> reverse_nums(nums.rbegin(), nums.rend());
    mergeSort(nums, 0, nums.size() - 1,n,reOrder);
    mergeSort(reverse_nums, 0, reverse_nums.size() - 1, n,order);
    print(order);
    print(reOrder);
    long long int m;
    cin >> m;
    while (m--) {
        long long int q;
        cin >> q;
        long long int cnt = 0;
        for (long long int i = 1; i <= q; i++) {
            swap(order[i], reOrder[i]);//每次反转后，需要交换q范围内顺序对和逆序对的数量
        }
        print(reOrder);
        for (long long int i = 1; i <= n; i++) {
            cnt += reOrder[i];
        }
        cout << cnt << endl;
    }
    system("pause");
    return 0;
}
