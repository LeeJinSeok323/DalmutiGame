// ���� �˰����� ���� 
// ���� ���� : bubble_sort �Լ�

#pragma region ���� ���� : bubble_sort �Լ�
void bubble_sort(int arr[], int size) { //ī�� ���� �Լ� - ���� ��Ʈ �˰����� �̿�
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#pragma endregion