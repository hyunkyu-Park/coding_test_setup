#include <iostream>

using namespace std;

const int N = 5; // 예시로 N을 5로 설정

int p[N]; // 부모 배열

void initialize(){
    for(int i=0; i<N; i++){
        p[i] = i;
    }
}

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
    // 초기화
    initialize();
    
    // find 함수 예시
    int x = find(3); // 3의 부모 노드 찾기
    cout << "Node 3의 부모 노드: " << x << endl;
    
    // merge 함수 예시
    merge(1, 2); // 1과 2를 합병
    int y = find(2); // 2의 부모 노드 찾기
    cout << "Node 2의 부모 노드: " << y << endl;
    
    return 0;
}
