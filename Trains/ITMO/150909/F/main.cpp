#include <bits/stdc++.h>

class State {
private:
    static const int p = 239017;
public:
    std::vector<std::vector<int>> field = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    State() {
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            field[i][j] = 0;
    }

    State(int other[3][3]) {
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            field[i][j] = other[i][j];
    }

    State(State const& other) {
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            field[i][j] = other.field[i][j];
    }

    void shift_row_this(int row) {
        int tmp = field[row][2];
        for (int i = 0; i < 2; i++) {
            field[row][i + 1] = field[row][i];
        }
        field[row][0] = tmp;
    }

    State shift_row(int row) {
        State new_state;
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_state.field[i][j] = field[i][j];
        new_state.shift_row_this(row);
        return new_state;
    }

    void rshift_row_this(int row) {
        int tmp = field[row][0];
        for (int i = 1; i < 3; i++) {
            field[row][i - 1] = field[row][i];
        }
        field[row][2] = tmp;
    }

    State rshift_row(int row) {
        State new_state;
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_state.field[i][j] = field[i][j];
        new_state.rshift_row_this(row);
        return new_state;
    }

    void shift_column_this(int column) {
        int tmp = field[2][column];
        for (int i = 0; i < 2; i++) {
            field[i + 1][column] = field[i][column];
        }
        field[0][column] = tmp;
    }

    State shift_column(int column) {
        State new_state;
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_state.field[i][j] = field[i][j];
        new_state.shift_column_this(column);
        return new_state;
    }

    void rshift_column_this(int column) {
        int tmp = field[0][column];
        for (int i = 1; i < 3; i++) {
            field[i - 1][column] = field[i][column];
        }
        field[2][column] = tmp;
    }

    State rshift_column(int column) {
        State new_state;
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_state.field[i][j] = field[i][j];
        new_state.rshift_column_this(column);
        return new_state;
    }

    int hash() {
        int result = 0;
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            result = result * 9 + field[i][j];
        }    
        return result;
    }

    bool is_magic() {
        bool ok = true;
        int res = field[0][0] + field[0][1] + field[0][2];
        ok &= field[1][0] + field[1][1] + field[1][2] == res;
        ok &= field[2][0] + field[2][1] + field[2][2] == res;
        ok &= field[0][0] + field[1][0] + field[2][0] == res;
        ok &= field[0][1] + field[1][1] + field[2][1] == res;
        ok &= field[0][2] + field[1][2] + field[2][2] == res;
        ok &= field[0][0] + field[1][1] + field[2][2] == res;
        ok &= field[0][2] + field[1][1] + field[0][2] == res;
        return ok;
    }
};

bool operator < (State a, State b) {
    return a.hash() < b.hash();
}

const int MAXQ = 1e6 + 100;

State q[MAXQ];
std::map<State, int> distance;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int start[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &start[i][j]);
        }
    }
    State start_state(start);
    int head = 0, tail = 0;
    q[tail++] = start_state;
    distance[start_state] = 0;
    while (head != tail) {
        State cur = q[head++];
        if (head == MAXQ) {
            head = 0;
        }
        if (cur.is_magic()) {
            
        }
        for (int i = 0; i < 3; i++) {
            State new_state = cur.shift_row(i);
            if (distance.find(new_state) == distance.end()) {
                distance[new_state] = distance[cur] + 1;
                q[tail++] = new_state;
                if (tail == MAXQ) {
                    tail = 0;
                }
            }
            new_state = cur.rshift_row(i);
            if (distance.find(new_state) == distance.end()) {
                distance[new_state] = distance[cur] + 1;
                q[tail++] = new_state;
                if (tail == MAXQ) {
                    tail = 0;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            State new_state = cur.shift_column(i);
            if (distance.find(new_state) == distance.end()) {
                distance[new_state] = distance[cur] + 1;
                q[tail++] = new_state;
                if (tail == MAXQ) {
                    tail = 0;
                }
            }
            new_state = cur.rshift_column(i);
            if (distance.find(new_state) == distance.end()) {
                distance[new_state] = distance[cur] + 1;
                q[tail++] = new_state;
                if (tail == MAXQ) {
                    tail = 0;
                }
            }
        }
    }
    return 0;
}
