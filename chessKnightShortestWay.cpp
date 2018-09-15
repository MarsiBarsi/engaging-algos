#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

struct KnightMove {
    int x, y;

    KnightMove(int x, int y): x(x), y(y) {}
};

struct ChessBoardCell {
    int x, y, steps;

    ChessBoardCell(int x, int y, int steps = 0): x(x), y(y), steps(steps) {}

    bool operator < (const ChessBoardCell &cell_to_compare) const {
        return x < cell_to_compare.x || (x == cell_to_compare.x && y < cell_to_compare.y);
    }

    bool operator == (const ChessBoardCell &cell_to_compare) const {
        return x == cell_to_compare.x && y == cell_to_compare.y;
    }
};

const KnightMove moves[] = {
    KnightMove(2, -1),
    KnightMove(2, 1),
    KnightMove(-2, 1),
    KnightMove(-2, -1),
    KnightMove(1, 2),
    KnightMove(1, -2),
    KnightMove(-1, 2),
    KnightMove(-1, -2)
};

int input_border_size() {
    int border_size;

    cout << "Board size >> ";
    cin >> border_size;
    cout << "\n";

    return border_size;
}

ChessBoardCell input_pos_with_description(string description = "coordinate") {
    int x, y;

    cout << "'x' " + description + " >> ";
    cin >> x;
    cout << "'y' " + description + " >> ";
    cin >> y;
    cout << endl;

    return ChessBoardCell(x - 1, y - 1);
}

bool check_borders(int x, int y, int board_size) {
    return x >= 0 && y >= 0 && x < board_size && y < board_size;
}

int count_steps_amount(ChessBoardCell start, ChessBoardCell finish, int board_size) {
    set<ChessBoardCell> visited_cells;
    queue<ChessBoardCell> cell_to_go_sequence;

    cell_to_go_sequence.push(start);

    while (!cell_to_go_sequence.empty()) {
        ChessBoardCell cell = cell_to_go_sequence.front();
        cell_to_go_sequence.pop();

        if (cell.x == finish.x && cell.y == finish.y) {
            return cell.steps;
        }

        if (!visited_cells.count(cell)) {
            visited_cells.insert(cell);

            for (int i = 0; i < 8; i++) {
                int next_x = cell.x + moves[i].x;
                int next_y = cell.y + moves[i].y;

                if (check_borders(next_x, next_y, board_size)) {
                    cell_to_go_sequence.push(
                            ChessBoardCell(next_x, next_y, cell.steps + 1)
                    );
                }
            }
        }
    }

    return -1;
}

int main() {
    int border_size = input_border_size();

    ChessBoardCell start = input_pos_with_description("of knigt");
    ChessBoardCell finish = input_pos_with_description("of finish cell");

    int result = count_steps_amount(start, finish, border_size);

    if (result != -1) {
        cout << "Steps: " << result << endl;
    } else {
        cout << "unreachable" << endl;
    }

    return 0;
}