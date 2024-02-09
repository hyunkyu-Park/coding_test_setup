#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
        ListNode *slow_pointer = head, *fast_pointer = head;
        while (fast_pointer != nullptr && fast_pointer->next != nullptr) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            if (slow_pointer == fast_pointer) {
                return true;
            }
        }
        return false;
    }

int main() {
    ListNode *head_with_cycle = new ListNode(1);
    head_with_cycle->next = new ListNode(2);
    head_with_cycle->next->next = new ListNode(3);
    // head_with_cycle->next->next->next = head_with_cycle;  // 순환 연결

    // 함수 호출 및 결과 출력
    if (hasCycle(head_with_cycle)) {
        std::cout << "순환이 존재합니다." << std::endl;
    } else {
        std::cout << "순환이 존재하지 않습니다." << std::endl;
    }

    // 메모리 해제
    delete head_with_cycle->next->next;
    delete head_with_cycle->next;
    delete head_with_cycle;
    return 0;
}
