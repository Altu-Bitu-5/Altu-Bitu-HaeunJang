#include <deque>
#include <iostream>

using namespace std;

struct info { //벨트 정보
    int power; //내구도
    bool is_on; //로봇 여부
};

// 벨트 한 칸 회전
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back()); //마지막 칸을 맨 앞으로 옮김 
    belt.pop_back();
    belt[n - 1].is_on = false; //마지막 칸 로봇 내림
}

// 로봇을 움직일 수 있으면 한 칸 이동
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) {//뒤에서부터 로봇 위치 확인
        if (!belt[i].is_on) {
            continue;
        }
	//다음 칸에 로봇이 없고 내구도가 0이 아니라면 로봇 한 칸 전진
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            belt[i].is_on = false;
            belt[i + 1].is_on = true;
            belt[i + 1].power--;
        }
        
        belt[n - 1].is_on = false; //마지막 칸 로봇 내림
    }
}

//올리는 위치에 로봇을 올릴 수 있으면 올림
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        belt[0].is_on = true;
        belt[0].power--;
    }
}

//내구도 확인
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            count++;
        }
    }

    return count >= k; 
}

int solution(deque<info> &belt, int n, int k) {
    int step = 1;
    while (true) { //한 단계
        // 벨트 회전
        rotateBelt(belt, n);
        // 로봇 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 확인
        if (checkFinish(belt, n, k)) {
            return step;
        }
        step++;
    }
}


int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    deque<info> belt(2 * n); //회전에 유리한 deque사용 
    for (int i = 0; i < 2 * n; i++) { //내구도 저장
        cin >> belt[i].power;
        belt[i].is_on = false;
    }
    
    // 연산
    int answer = solution(belt, n, k);
    
    // 출력
    cout << answer;
}