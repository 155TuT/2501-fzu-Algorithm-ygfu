/*
t2 最大子段和
分数 20
作者 陈晓梅
单位 广东外语外贸大学
给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。当所给的整数均为负数时，定义子段和为0，要求算法的时间复杂度为O(n)。

输入格式:
输入有两行：
第一行是n值（1<=n<=10000)；
第二行是n个整数。

输出格式:
输出最大子段和。

输入样例:
在这里给出一组输入。例如：
6
-2 11 -4 13 -5 -2

输出样例:
在这里给出相应的输出。例如：
20

代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int mS = 0, cS = 0;
    for(int i = 0; i < n; i++)
        cS = max(0, cS + a[i]), mS = max(mS, cS);
    cout << mS;
    return 0;
}