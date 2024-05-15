// ī�� �й� ���� ����
// �� �÷��̾�鿡�� ī�带 �й����ش�.

// NumPlayers : �÷��̾� ��
// playerCards : �� �÷��̾ ������ �ִ� ī�� �迭
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_CARDS 80 // ī�� ���� 80��

#pragma region distributeCards �Լ� : ī�� �й� ����
void distributeCards(int NumPlayers, int playerCards[4][20]) {
    int num_cards_per_player = NUM_CARDS / NumPlayers;
    int cards[NUM_CARDS];
    int idx = 0;

    // ī�� �ʱ�ȭ
    for (int i = 1; i <= 12; i++) {
        for (int j = 0; j < i; j++) {
            cards[idx++] = i;
        }
    }
    cards[idx++] = 13;  // ��Ŀ ī��
    cards[idx++] = 13;

    // ī�� ����
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // ī�� �й�
    int k = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j++) {
            playerCards[j][i] = cards[k++];
        }
    }
}
#pragma endregion