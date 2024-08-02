#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

bool is_valid_move(const Point& start, const Point& end, const set<Point>& board) {
    if (end == start || board.find(end) == board.end()) {
        return false;
    }
    if (start.x != end.x) {  
        return false;
    }
    if (start.y == end.y) {  
        return false;
    }
    return true;
}

void find_paths(set<Point> board, Point current, vector<Point> path, vector<vector<Point>>& all_paths, Point start) {
    if (current == start && path.size() > 1) {
        all_paths.push_back(path);
        return;
    }

    for (auto pos : board) {
        if (is_valid_move(current, pos, board)) {
            vector<Point> new_path = path;
            new_path.push_back(pos);
            set<Point> new_board = board;
            new_board.erase(pos);
            find_paths(new_board, pos, new_path, all_paths, start);
        }
    }
}

int main() {
    int num_soldiers;
    cout << "Enter the number of soldiers: ";
    cin >> num_soldiers;

    set<Point> board;

    for (int i = 0; i < num_soldiers; ++i) {
        int x, y;
        cout << "Enter coordinates for soldier " << i + 1 << " (format x y): ";
        cin >> x >> y;
        board.insert(Point(x, y));
    }

    int castle_x, castle_y;
    cout << "Enter the coordinates for your 'special' castle (format x y): ";
    cin >> castle_x >> castle_y;
    Point start(castle_x, castle_y);

    vector<vector<Point>> all_paths;
    find_paths(board, start, { start }, all_paths, start);

    cout << "Thanks. There are " << all_paths.size() << " unique paths for your 'special_castle'" << endl;

    return 0;
}
