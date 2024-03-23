int binary_search(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 중간 요소가 찾는 요소인 경우
        if (arr[mid] == target)
            return mid;

        // 중간 요소가 찾는 요소보다 작은 경우
        else if (arr[mid] < target)
            left = mid + 1;

        // 중간 요소가 찾는 요소보다 큰 경우
        else
            right = mid - 1;
    }

    // 요소를 찾지 못한 경우
    return -1;
}