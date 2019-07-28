#include <iostream>
#include <queue>
#include <string>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
using namespace std;

int N, M;

class Flip {
public:
    char arr[10][10];
    int visited[10][10];
    int dir;
    int dpt;
    int rR, cR;
    int rB, cB;
    
    Flip(char map[][10], int vis[][10] , int di, int dp, int Rr, int Cr, int Rb, int Cb){
        for (int i = 0 ; i < N; i++){
            for (int j = 0 ; j < M ; j++){
                arr[i][j] = map[i][j];
                visited[i][j] = vis[i][j];
            }
        }
        dir = di;
        dpt = dp;
        rR = Rr; cR = Cr;
        rB = Rb; cB = Cb;
    }

    void print(){
       for (int i = 0 ; i < N ; i++) {
           for (int j = 0 ; j < M ; j++)
               printf("%c", arr[i][j]);
           cout << endl;
       }
       for (int i = 0 ; i < N ; i++) {
           for (int j = 0 ; j < M ; j++)
               printf("%i", visited[i][j]);
           cout << endl;
       }
       cout << endl;
    }

    void find_dirs(int *dirs){
        for (int i = 0 ; i < 4; i++)
            dirs[i] = 0;
        if (!visited[rR][cR-1]&&(arr[rR][cR-1]=='.'||arr[rR][cR-1]=='O'))
            dirs[LEFT] = 1;
        if (!visited[rR][cR+1]&&(arr[rR][cR+1]=='.'||arr[rR][cR+1]=='O'))
            dirs[RIGHT] = 1;
        if (!visited[rR-1][cR]&&(arr[rR-1][cR]=='.'||arr[rR-1][cR]=='O'))
            dirs[UP] = 1;
        if (!visited[rR+1][cR]&&(arr[rR+1][cR]=='.'||arr[rR+1][cR]=='O'))
            dirs[DOWN] = 1;
    }

    bool move(int r, int c, int dir, bool red) {
        bool hole = false;
        char ch = arr[r][c];
        int dr = 0, dc = 0;
        if (dir == LEFT) { dc = -1; }
        else if (dir == RIGHT) { dc = 1; }
        else if (dir == UP) { dr = -1; }
        else if (dir == DOWN) { dr = 1; }
        while (dc!=0||dr!=0){
           if (arr[r][c] != 'O') arr[r][c] = '.';
           if (red) visited[r][c] = 1;
           if (arr[r][c]=='O') hole = true;
           if (arr[r + dr][c + dc] == '.'|| arr[r + dr][c + dc] == 'O'){
               r += dr; c += dc;
           } else {
               arr[r][c] = ch; break;
           }
        }
        if (red){
            rR = r; cR = c;
        } else {
            rB = r; cB = c;
        }
        return hole;
    }

    bool move_all(int dir){
        bool red_first = false;
        bool redout, bluout;
        if (dir == LEFT && cR <= cB) red_first = true;
        else if (dir == RIGHT && cR >= cB) red_first = true;
        else if (dir == UP && rR <= rB) red_first = true;
        else if (dir == DOWN && rR >= rB) red_first = true;

        if (red_first) {
            redout = move(rR, cR, dir, true);
            bluout = move(rB, cB, dir, false);
        } else {
            bluout = move(rB, cB, dir, false);
            redout = move(rR, cR, dir, true);
        }

        print();
        if (redout && !bluout)
            return true;
        return false;
    }
};

int main(){
    cin >> N >> M;
    
	int rR, cR, rB, cB;
    char map[10][10];
    int vis[10][10];
	
	string input;
    for (int i = 0 ; i < N; i++){
		cin >> input;
        for (int j = 0 ; j < M ; j++){
			map[i][j] = input[j];
            
            if (map[i][j]=='#')
                vis[i][j] = 1;
            else
                vis[i][j] = 0;
            
			if (map[i][j] == 'R') {
                rR = i;
                cR = j;
            }
			if (map[i][j] == 'B') {
                rB = i;
                cB = j;
            }
        }
    }
    
    vis[rR][cR] = 1;
    Flip init(map, vis, -1, 0, rR, cR, rB, cB);
//    init.move_all(LEFT);
//    init.move_all(DOWN);
//    init.move_all(RIGHT);

    // BFS
    queue<Flip> q;
    q.push(init);

    int *dirs = new int[4];
    while(!q.empty()){
        Flip flip = q.front();
        q.pop();
        if (flip.move_all(flip.dir)) {
           cout << flip.dpt << endl;
           return 0;
        }

        flip.find_dirs(dirs);
//        for(int i = 0 ; i < 4; i++)
//            cout << dirs[i];
//        cout << endl;

        if (dirs[LEFT]) {
            flip.visited[flip.rR][flip.cR-1] = 1;
            Flip temp(flip.arr, flip.visited, LEFT, flip.dpt+1, flip.rR, flip.cR, flip.rB, flip.cB);
            q.push(temp);
        }
        if (dirs[RIGHT]){
            flip.visited[flip.rR][flip.cR+1] = 1;
            Flip temp(flip.arr, flip.visited, RIGHT, flip.dpt+1, flip.rR, flip.cR, flip.rB, flip.cB);
            q.push(temp);
        }
        if (dirs[UP]) {
            flip.visited[flip.rR-1][flip.cR] = 1;
            Flip temp(flip.arr, flip.visited, UP, flip.dpt+1, flip.rR, flip.cR, flip.rB, flip.cB);
            q.push(temp);
        }
        if (dirs[DOWN]){
            Flip temp(flip.arr, flip.visited, DOWN, flip.dpt+1, flip.rR, flip.cR, flip.rB, flip.cB);
            q.push(temp);
            flip.visited[flip.rR+1][flip.cR] = 1;
        }
    }

    cout << "-1" << endl;
    return 0;
}

/*
 맵은 만들수 있냐? 길은 . 벽은 # 구멍은 O 빨간 공은 R 파란 공은 B
 문자열로! 하자

 일단 움직이는 것은 만들 수 있냐? 끝까지 움직이면 되네
    빨간공을 지정된 방향으로 나아가도 배열값이 0인 동안 앞으로 추진시켜
    추진하면서 2가 있으면 일단 빨간 공은 나간거야
    파란 공도 같은 방향으로 움직여
    빨간공 파란공 누가 먼저 움직여야 하냐면 좌표가 더 앞선 공을 먼저 움직여야 해
    파란 공이 추진하면서 2가 있으면 파란 공도 나간거라 그 길은 못 가
    움직였을 때 내가 온 방향으로 돌아가면 안되
    빨간 공이나 파란 공도 움직일 곳이 없으면 더는 움직일 수 없어
 
 순서도를 짜보자
 
 큐에 집어넣을때 뭘 넣을까? --> 위로
 자료의 구조는?
 클래스에 인트 박자
 
 큐에 뭐가 남았니?
    큐에서 기울임을 꺼내자
    방문하자
        빨간 공이 파란 공보다 앞섰니?
            R을 옮겨보자
                차례로 방문하자 (기록)
                O가 있었니?
            B를 옮겨보자
                O가 있었니?
            R은 O 있고 B는 O 없으면 성공
        혹은 반대로 파란 공이 빨간 공보다 앞섰니?
            B을 옮겨보자
                O가 있었니?
            R를 옮겨보자
                차례로 방문하자 (기록)
                O가 있었니?
            R은 O 있고 B는 O 없으면 성공
 
    빨간 공이 방문하지 않은 방향이 있니?
        있으면 큐에 기울임을 다 넣자
            기울일 방향 이전 기울인 방향 넣어주자 (1 L 2 R 3 U 4 D)
            깊이는 하나씩 늘려주자, 근데 다음 깊이가 11이 되면 넣지 말자 (D)
            좌표 넣어주자 (rR cR rB cB)
 
    옮겨주는 모듈 만들까
        기원
        방향
        기록여부
        ---
        O여부
 */

