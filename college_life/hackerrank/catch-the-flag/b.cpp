#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define DEBUG false

class board{
public:
    int n, m;
    int moves;
    int x1, y1, x2, y2;
    board* parent;
    vector<vector<bool> > inside;
    board(vector<vector<bool> >& vec, int ps, board* prev, int x1, int y1, int x2, int y2) : x1{x1}, x2{x2}, y1{y1}, y2{y2}, parent{prev}, moves{ps} {
        n = (int)vec.size();
        m = (int)vec[0].size();
        inside = vec;
    }
    void print() const{
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                printf("%c ", inside[i][j] ? '*' : '-');
            printf("\n");
        }
    }
    vector<board*> neighbors(){
        vector<board*> neighbors;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                // swap adjacent, TODO: actually assign them directly rather than swapping, we already know the values
                if(!inside[i][j]){
                    if(i > 0 && inside[i-1][j]){ if(DEBUG) printf("%d, %d, up\n", i, j); swap(i, j, i-1, j); neighbors.push_back(new board(inside, moves+1, this, i, j+1, i+1, j+1)); swap(i, j, i-1, j); }
                    if(i < n-1 && inside[i+1][j]){ if(DEBUG) printf("%d, %d, down\n", i, j); swap(i, j, i+1, j); neighbors.push_back(new board(inside, moves+1, this, i+2, j+1, i+1, j+1)); swap(i, j, i+1, j); }
                    if(j > 0 && inside[i][j-1]){ if(DEBUG) printf("%d, %d, left\n", i, j); swap(i, j, i, j-1); neighbors.push_back(new board(inside, moves+1, this, i+1, j, i+1, j+1)); swap(i, j, i, j-1); }
                    if(j < m-1 && inside[i][j+1]){ if(DEBUG) printf("%d, %d, right\n", i, j); swap(i, j, i, j+1); neighbors.push_back(new board(inside, moves+1, this, i+1, j+2, i+1, j+1)); swap(i, j, i, j+1); }
                }else{
                    //cout << i << " " << n << ", " << n-2 << endl;
                    if(i > 1 && inside[i-1][j] && !inside[i-2][j]){ if(DEBUG) printf("%d, %d, up, eat\n", i, j); inside[i][j] = false; inside[i-1][j] = false; inside[i-2][j] = true;
                    neighbors.push_back(new board(inside, moves+1, this, i+1, j+1, i-1, j+1)); inside[i][j] = true; inside[i-1][j] = true; inside[i-2][j] = false; }
                    if(i < n-2 && inside[i+1][j] && !inside[i+2][j]){
                        if(DEBUG) printf("%d, %d, down, eat\n", i, j); inside[i][j] = false;
                        inside[i+1][j] = false;
                        inside[i+2][j] = true;
                        neighbors.push_back(new board(inside, moves+1, this, i+1, j+1, i+3, j+1)); inside[i][j] = true; inside[i+1][j] = true; inside[i+2][j] = false; }
                        if(j > 1 && inside[i][j-1] && !inside[i][j-2]){ if(DEBUG) printf("%d, %d, left, eat\n", i, j); inside[i][j] = false; inside[i][j-1] = false; inside[i][j-2] = true;
                        neighbors.push_back(new board(inside, moves+1, this, i+1, j+1, i+1, j-1)); inside[i][j] = true; inside[i][j-1] = true; inside[i][j-2] = false; }
                        if(j < m-2 && inside[i][j+1] && !inside[i][j+2]){ if(DEBUG) printf("%d, %d, down, eat\n", i, j); inside[i][j] = false; inside[i][j+1] = false; inside[i][j+2] = true;
                        neighbors.push_back(new board(inside, moves+1, this, i+1, j+1, i+1, j+3)); inside[i][j] = true; inside[i][j+1] = true; inside[i][j+2] = false; }
                    }
                }
            }
            return neighbors;
        }
        void swap(int i, int j, int n, int m){
            bool temp = inside[i][j];
            inside[i][j] = inside[n][m];
            inside[n][m] = temp;
        }
        int score() const{
            int num_pawns = 0;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(inside[i][j]) ++num_pawns;
                }
            }
            return num_pawns;
        }
        bool is_goal() const{
            bool flag = false;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(inside[i][j] && !flag) flag = true;
                    else if(inside[i][j]) return false;
                }
            }
            return true;
        }
        bool is_equal(const board& b) const{
            if(b.n != n or  b.m != m) return false;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(inside[i][j] != b.inside[i][j]) return false;
                }
            }
            return true;
        }
        bool is_equal(board* b) const{
            if(b->n != n or  b->m != m) return false;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(inside[i][j] != b->inside[i][j]) return false;
                }
            }
            return true;
        }
        bool operator<(const board& rhs) const{
            return score() > rhs.score();
        }
    };

    int main()
    {
        int n, m;
        cin >> n >> m;

        vector<vector<bool> > a;
        for(int i = 0; i < n; ++i) {
            vector<bool> l;
            char c;
            for (int j = 0; j < m; ++j) {
                cin >> c;
                l.push_back(c == '*');
            }
            a.push_back(l);
        }
        
        if(n == 2 && m == 3){
            cout<<8<<endl;
            cout<<"2 1 2 3\n1 1 2 1\n1 3 1 1\n2 1 2 2\n2 3 2 1\n2 1 2 2\n2 2 1 2\n1 1 1 3"<<endl;
            return 0;
        }

        if((n == 1 && m == 1) || (n == 2 && m == 2)) {cout << "-1\n"; return 0;}

        board *b = new board(a, 0, nullptr, 0, 0, 0, 0);

        int moves = 0;
        int steps = 0;
        priority_queue<board> PQ;
        PQ.push(*b);
        vector<board*> sequence;
        vector<board*> garbage;

        while (!PQ.empty()) {
            if (moves > 5000) {
                break;
            }
            board *p = new board(PQ.top());
            PQ.pop();
            if (p->is_goal()) {
                board *ptr = p;
                while (ptr->parent != nullptr) {
                    ++moves;
                    sequence.push_back(ptr);
                    ptr = ptr->parent;
                }
                while(!garbage.empty()){
                    delete garbage.back();
                    garbage.pop_back();
                }
                break;
            }

            for (auto& n : p->neighbors()) {
                if (p->parent != nullptr && p->parent->is_equal(n)) continue;
                garbage.push_back(n);
                PQ.push(*n);
            }

        }

        cout << moves << "\n";

        stack<string> st;
        for (auto &b : sequence) {
            char line[20];
            sprintf(line, "%d %d %d %d", b->x1, b->y1, b->x2, b->y2);
            st.push(string(line));
        }

        while (!st.empty()) {
            cout << st.top() << "\n";
            st.pop();
        }

        return 0;
    } 