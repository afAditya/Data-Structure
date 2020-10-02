#include<bits/stdc++.h>
using namespace std;

class SeperateChaining {
private:
    int bucket;
    vector< vector<int> > v;
public:
    SeperateChaining(int n) {
        // initialize
        this->bucket = n;
        v = vector< vector<int> >(n);
    }

    // hash function
    int getHashIndex(int key) {
        return key % bucket;
    }

    void insertItem(int x) {
        v[getHashIndex(x)].push_back(x);
    }

    void deleteItem(int x) {
        int index = getHashIndex(x);

        for(int i=0;i<v[index].size();i++) {
            if(v[index][i] == x) {
                v[index].erase(v[index].begin() + i);
                cout << x << " deleted!" << "\n";
                return;
            }
        }

        cout << "No element found!" << "\n";
    }

    void display() {
        for(int i=0;i<v.size();i++) {
            cout << i;
            for(int j=0;j<v[i].size();j++)
                cout << " ->" << v[i][j];
            cout << "\n";
        }
    }
};

int main() {
    vector<int> v{12,3,23,4,11,32,26,33,17,19};
    SeperateChaining sc(10);

    for(int i=0;i<10;i++)
        sc.insertItem(v[i]);

    sc.display();
}
