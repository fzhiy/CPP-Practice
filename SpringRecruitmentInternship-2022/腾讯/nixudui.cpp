/*** 
 * @Date: 2022-04-24 18:11:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-24 18:49:18
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(vector<ll> &nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


void merge_sort(vector<int>& nums, vector<int>& copy, int low, int high, int idx, vector<ll>& order) {
    if (low >= high) return ;
    int mid = low + (high - low) / 2;
    int start1 = low, end1 = mid;
    int start2 = mid + 1, end2 = high;
    merge_sort(nums, copy, start1, end1, idx - 1, order);
    merge_sort(nums, copy, start2, end2, idx - 1, order);
    ll index = low, cnt = 0;
    while (start1 <= end1 && start2 <= end2) {
        if (nums[start1] > nums[start2]) {
            copy[index ++] = nums[start2 ++];
            cnt += (end1 - start1 + 1);     // 构成的逆序对
        } else {
            copy[index ++] = nums[start1 ++];
        }
    }
    while (start1 <= end1) {
        copy[index ++] = nums[start1 ++];
    }
    while (start2 <= end2) {
        copy[index ++] = nums[start2 ++];
    }
    for (index = low; index <= high; index ++) {
        nums[index] = copy[index];
    }
    order[idx] += cnt;
    // print(nums);
}

int main() {
    int n, m;
    while (cin >> n) {
        int p = 1 << n, q;
        vector<int> a(p);
        for (int i = 0; i < p; i ++) {
            cin >> a[i];
        }
        vector<ll> order(n + 1, 0);        // order[i]对应 分组大小为2^i 的顺序对的个数
        vector<ll> reOrder(n + 1, 0);       // reOrder[i] 对应分组大小为2^i 的逆序对的个数
        vector<int> b(a.rbegin(), a.rend());
        vector<int> copy(p, 0);
        merge_sort(a, copy, 0, p - 1, n, reOrder);
        copy.clear();
        merge_sort(b, copy, 0, p - 1, n, order);
        // cout << "排序后的结果: \n";
        // print(a);
        // print(b);
        // cout << "==============\n";
        // print(order);
        // print(reOrder);
        cin >> m;
        while (m --) {
            cin >> q;
            for (int i = 1; i <= q; i ++) {
                swap(order[i], reOrder[i]);
            }
            ll res = 0;
            for (int i = 1; i <= n; i ++) {
                res += reOrder[i];
            }
            cout << res << endl;
        }
    }
    return 0;
}