#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

struct UnionFind{
    vector<int> parent;
    vector<int> rank;//高さ
    //vector<int> size;//サイズ

    //高さ
    UnionFind(int n) : parent(n),rank(n,0){
        for(int i=0;i<n;i++) parent[i] = i;
    }

    //サイズ
    /*
    UnionFind(int n) : parent(n),size(n,1){
        for(int i=0;i<n;i++) parent[i] = i;
    }
    */

    //経路圧縮あり
    int findroot(int x) {
        if(parent[x] != x) parent[x] = findroot(parent[x]);//親を再帰的に更新
        return parent[x];
    }

    //木の高さでの更新
    void unite(int x, int y){
        x = findroot(x);
        y = findroot(y);
        if(x == y) return;//同集合の場合
        if(rank[x] < rank[y]) parent[x] = y;//低いほうを高いほうにつける
        else if(rank[x] > rank[y]) parent[y] = x;
        else{
            parent[x] = y;//yが根になるので、yをインクリメント
            rank[y]++;
        }
    }

    //木のサイズでの更新
    //boolでfalse、trueを返している理由は不明だが、問題によりそう。
    /*
    bool unite(int x,int y){
        x = findroot(x);
        y = findroot(y);
        if(x == y) return false;//同集合の場合
        if(size[x] < size[y]){//小さい方に大きい方をつける
            parent[x] = y;
            size[y] += size[x];
        }else{
            parent[y] = x;
            size[x] += size[y];
        }
        return true;
    }
    */
};

int main(){
  //使用方法
    UnionFind uf(5);//要素数5

    cout << uf.findroot(3) << " " << uf.findroot(4) << endl;
    uf.unite(3,4);
    cout << uf.findroot(3) << " " << uf.findroot(4) << endl;
}