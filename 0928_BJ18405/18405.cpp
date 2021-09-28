#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct virus
{
    int x;
    int y;
    int k;

    virus(int x, int y, int k) {
        this->x = x;
        this->y = y;
        this->k = k;
    }

    bool operator<(virus &v) {
        return k > v.k;
    }
};

vector<virus> vec;
int map[201][201];
int dx[] = { 0, 0, -1, 1 }; // 상하좌우 x좌표
int dy[] = { 1, -1, 0, 0 }; // 상하좌우 y좌표
int n, k;
int s, x, y;

void BFS()
{
    queue<virus> q;

    // 큐에 바이러스에 대한 정보를 넣어줌
    for (int i = 0; i < vec.size(); i++) {
        q.push(vec[i]);
    }

    // s초 동안 바이러스의 증식을 진행
    while (s-- && !q.empty()) {
        virus v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            
            // 시험관의 범위를 벗어나거나 이미 바이러스가 있는 경우 건너뜀
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny])
                continue;
            
            map[nx][ny] = v.k;
            q.push({ nx, ny, k });
        }
    }
    cout << map[x][y] << "\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N * N 크기의 시험관의 데이터를 입력받음
    // 바이러스의 정보를 벡터에 저장
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j]) vec.push_back({ i, j, map[i][j] });
        }
    }
    // 낮은 종류의 바이러스부터 증식하므로 k값을 기준으로 오름차순 정렬함
    sort(vec.begin(), vec.end());

    cin >> s >> x >> y;
    BFS();

    return 0;
}