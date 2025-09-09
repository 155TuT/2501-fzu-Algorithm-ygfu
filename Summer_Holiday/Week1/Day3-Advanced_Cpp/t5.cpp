/*
t5 枚举法的嵌套循环实现
分数 20
作者 陈越
单位 浙江大学
分书问题是指：已知 n 个人对 m 本书的喜好（n≤m），现要将 m 本书分给 n 个人，每个人只能分到 1 本书，每本书也最多只能分给 1 个人，并且还要求每个人都能分到自己喜欢的书。列出所有满足要求的方案。

本题请你尝试给出一个更为通用的嵌套循环代码模板。

输入格式：
输入第一行给出两个正整数 n 和 m（n≤m），即分书问题中的人数和书的数量。由于本题仅用于测试嵌套循环算法，故此处的 n 和 m 取固定值，分别为 n=3 和 m=4。
随后 n 行，每行给出 m 个关系矩阵元素。其中第 i 行第 j 个元素为 1 表示第 i 个人喜欢第 j 本书，为 0 则表示不喜欢。

输出格式：
按升序列出所有满足要求的方案，格式为 (s1, s2, s3)。其中si 表示第 i 个人分到了第 si 本书。

注：方案 (a1,a2,a3)<(b1,b2,b3) 是指存在 1≤k≤3，使得 ai=bi 对所有 1≤i<k 成立，并且有 ak<bk
​
输入样例：
3 4
0 1 0 1
1 0 1 0
1 1 0 0

输出样例：
(2, 3, 1)
(4, 1, 2)
(4, 3, 1)
(4, 3, 2)

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> like(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> like[i][j];
    vector<vector<int>> solutions;
    for(int book0 = 0; book0 < m; book0++){
        if(like[0][book0] != 1)continue;
        for(int book1 = 0; book1 < m; book1++){
            if(book1 == book0)continue;
            if(like[1][book1] != 1)continue;
            for(int book2 = 0; book2 < m; book2++){
                if(book2 == book0 || book2 == book1)continue;
                if(like[2][book2] != 1)continue;
                solutions.push_back({book0 + 1, book1 + 1, book2 + 1});
            }
        }
    }
    sort(solutions.begin(), solutions.end());
    for(const auto& sol : solutions)
        cout << "(" << sol[0] << ", " << sol[1] << ", " << sol[2] << ")" << endl;
    return 0;
}