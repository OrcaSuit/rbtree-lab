#include<stdio.h>


//배열 요소를 교환하는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 힙을 구성하는 함수 
void heapify(int arr[], int n, int i) {
    int largest = i; //가장 큰 값의 인덱스를 초기화 
    int left = 2 * i + 1; // 왼쪽 자식 인덱스
    int right = 2 * i + 2; // 오른쪽 자식 인덱스 

    //왼쪽 자식이 현재 요소보다 크면 인덱스를 갱신
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    //오른쪽 자식이 현재 요소보다 크면 인덱스를 갱신
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    //가장 큰 값이 현재 요소가 아니라면 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        //재귀적으로 하위 힙을 재구성 
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    //초기 힙 구성
    for (int i = n / 2 - i; i >= 0; --i) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("정렬된 배열 : \n");
    printArray(arr, n);

    return 0;
}

