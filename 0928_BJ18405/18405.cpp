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
int dx[] = { 0, 0, -1, 1 }; // �����¿� x��ǥ
int dy[] = { 1, -1, 0, 0 }; // �����¿� y��ǥ
int n, k;
int s, x, y;

void BFS()
{
    queue<virus> q;

    // ť�� ���̷����� ���� ������ �־���
    for (int i = 0; i < vec.size(); i++) {
        q.push(vec[i]);
    }

    // s�� ���� ���̷����� ������ ����
    while (s-- && !q.empty()) {
        virus v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            
            // ������� ������ ����ų� �̹� ���̷����� �ִ� ��� �ǳʶ�
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

    // N * N ũ���� ������� �����͸� �Է¹���
    // ���̷����� ������ ���Ϳ� ����
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j]) vec.push_back({ i, j, map[i][j] });
        }
    }
    // ���� ������ ���̷������� �����ϹǷ� k���� �������� �������� ������
    sort(vec.begin(), vec.end());

    cin >> s >> x >> y;
    BFS();

    return 0;
}