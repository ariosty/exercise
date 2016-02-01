/******** matrix path **********
    A 5*5 matrix contains letters a..y. Given 2 letters, output all
    the shortest paths between them. Original problem simplified because
    searching for elements is O(1).
*******************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(char matrix[][5], char a, char b) {
    int ax = (a - 'a') / 5, ay = (a - 'a') % 5;
    int bx = (b - 'a') / 5, by = (b - 'a') % 5;
    int xdiff = bx - ax, ydiff = by - ay;
    int xsign = (xdiff>0)?1:-1, ysign = (ydiff>0)?1:-1;
    vector<string> paths[5];
    string path = "";
    for (int j = 0; j <= ydiff * ysign; j++) {
        path += string(1, matrix[ax][ay+j*ysign]);
        paths[j].push_back(path);
    }
    for (int i = 1; i <= xdiff * xsign; i++) {
        for (int j = 0; j <= ydiff * ysign; j++) {
            vector<string> newPath;
            for (int k = 0; k < paths[j].size(); k++) {
                // reach from another row
                newPath.push_back(paths[j][k] + string(1, matrix[ax+i*xsign][ay+j*ysign]));
            }
            // reach from another column
            if (j > 0) {
                for (int k = 0; k < paths[j-1].size(); k++) {
                    newPath.push_back(paths[j-1][k] + string(1, matrix[ax+i*xsign][ay+j*ysign]));
                }
            }
            paths[j] = newPath;
        }
    }
    vector<string> result = paths[ydiff * ysign];
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

int main(void) {
    char matrix[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = 'a' + i * 5 + j;
    char a,b;
    cin >> a >> b;
    solve(matrix,a,b);
    return 0;
}
