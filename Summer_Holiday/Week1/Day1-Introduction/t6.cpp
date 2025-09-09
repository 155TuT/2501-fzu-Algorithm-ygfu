/*  
t6 直方图最大矩形面积
分数 20
作者 张庆
单位 集美大学
一个直方图是由许多矩形组成的，要求在给定的直方图中找出最大的矩形面积。假定直方图矩形数量不超出1000个。

假定所有矩形的宽度都为1个单位。给出的直方图中有7个矩形，高度分别是6，2，5，4，5，1，6，其中连续的矩形能组成的最大的矩形面积是12。

实现提示：考虑使用栈解决此问题。

输入格式:
第一行输入直方图中矩形的数量。
第二行输入一组直方图的高度，每个高度用空格符间隔。

输出格式:
输出连续矩形能组成的最大矩形面积。

输入样例:
在这里给出一组输入。例如：
7
6 2 5 4 5 1 6

输出样例:
在这里给出相应的输出。例如：
12

代码长度限制 16 KB
时间限制 10 ms
内存限制 64 MB
栈限制 8192 KB
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];
    vector<int> left(n);
    vector<int> right(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if (st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if (st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        if (area > max_area) {
            max_area = area;
        }
    }
    cout << max_area << endl;
    return 0;
}