#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
 
int N;
int score[100];
bool visited[10001];
 
int main() {

    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; test_case++) {
 
        //초기화
        N = 0;
        memset(score, 0, sizeof(score));
        memset(visited, false , sizeof(visited));

        vector<int> canScore;
        int answer = 0;
 
        //입력
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> score[i];
        }
 
        //해법
        //0점부터 시작
        canScore.push_back(0);
        visited[0] = true;
        for (int i = 0; i < N; i++) {
            
            //현재 만들 수 있는 점수의 개수(벡터 사이즈) 저장
            int v_size = canScore.size();
 
            for (int j = 0; j < v_size; j++) {
 
                //새로운 점수 = 현재 만들 수 있는 점수 + 새로운 배점
                int newScore = canScore[j] + score[i];
 
                //이전에 만들 수 있는 점수가 아닌 경우 -> 벡터에 저장
                if (!visited[newScore]) {
                    canScore.push_back(newScore);
                    visited[newScore] = true;
                }
            }
        }
 
        //결과 갱신
        answer = canScore.size();
 
        //출력
        cout << "#" << test_case << " " << answer << "\n";
    }
 
    //종료
    return 0;
}
