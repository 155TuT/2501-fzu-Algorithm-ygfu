/*
t3 列出连通集
分数 25
作者 陈越
单位 浙江大学
给定一个有 n 个顶点和 m 条边的无向图，请用深度优先遍历（DFS）和广度优先遍历（BFS）分别列出其所有的连通集。假设顶点从 0 到 n−1 编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第 1 行给出 2 个整数 n (0<n≤10) 和 m，分别是图的顶点数和边数。随后 m 行，每行给出一条边的两个端点。每行中的数字之间用 1 空格分隔。

输出格式:
按照"{ v1 v2 ... vk}"的格式，每行输出一个连通集。先输出 DFS 的结果，再输出 BFS 的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5

输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void DFS(int v, vector<bool>& visited, const vector<vector<int>>& graph, vector<int>& component){
    visited[v] = true;
    component.push_back(v);
    for(int i = 0; i < graph.size(); i++)
        if(graph[v][i] == 1 && !visited[i])DFS(i, visited, graph, component);
}
void BFS(int v, vector<bool>& visited, const vector<vector<int>>& graph, vector<int>& component){
    queue<int> q;
    visited[v] = true;
    component.push_back(v);
    q.push(v);
    while (!q.empty()){
        int current = q.front();
        q.pop();
        for (int i = 0; i < graph.size(); i++) {
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = true;
                component.push_back(i);
                q.push(i);
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> component;
            DFS(i, visited, graph, component);
            cout << "{ ";
            for(int v : component)cout << v << " ";
            cout << "}" << endl;
        }
    }
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> component;
            BFS(i, visited, graph, component);
            cout << "{ ";
            for(int v : component)cout << v << " ";
            cout << "}" << endl;
        }
    }
    return 0;
}