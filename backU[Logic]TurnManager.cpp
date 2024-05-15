#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "[Algorithm]queue.h"
#define MAX_NAME_LENGTH 20
#define NUM_PLAYERS 4

//�ӽ÷� �÷��̾� scanf�� �Է¹��� �÷��̾��, ��������
char players_name[NUM_PLAYERS][MAX_NAME_LENGTH] = { "Abigeil", "Biyonse", "Chars", "Daniel" };
Queue turnOrderQueue; // �Լ��� ������ ���� ���� ����
void randTurn(char players[][MAX_NAME_LENGTH]);
void initTurn(void);
char* currentTurn(void);
void endTurn(void);

void randTurn(char players[][MAX_NAME_LENGTH]) {
    srand((unsigned int)time(NULL));
    int turnOrder[4] = { 555, 555, 555, 555 }; // �ʱ�ȭ 555�� �ƴϿ��� ������.
    while (true) { // �� ������ ���Ѵ�.
        if (turnOrder[0] == 555) {  // ù���� ���� ������ �ٽ� while�� ����
            turnOrder[0] = rand() % 4;
        }
        else if (turnOrder[1] == 555) {  // �ι�° ����
            do {
                turnOrder[1] = rand() % 4;

            } while (turnOrder[1] == turnOrder[0]);
        }
        else if (turnOrder[2] == 555) { // ����° ����
            do {
                turnOrder[2] = rand() % 4;
            } while (turnOrder[2] == turnOrder[0] or turnOrder[2] == turnOrder[1]);
        }
        else if (turnOrder[3] == 555) { // �׹�° ����
            do {
                turnOrder[3] = rand() % 4;
            } while (turnOrder[3] == turnOrder[0] or turnOrder[3] == turnOrder[1] or turnOrder[3] == turnOrder[2]);
        }
        else {
            for (int i = 0; i < 4; i++) {
                printf("%d ", turnOrder[i]);

            }
            printf("\n");

            break;
        }
    } // while�� ����  turnOrder���� {0 3 2 1}�� ���� ������ ��ġ

    //turnOrder�� �°� players[][] ���ġ
    char tempP[NUM_PLAYERS][MAX_NAME_LENGTH];

    for (int i = 0; i < 4; i++) { //������� ��ġ�Ͽ� ���������� �ӽ�����
        strcpy_s(tempP[i], players_name[turnOrder[i]]);
    }
    for (int i = 0; i < 4; i++) { //�ӽ������� �������� ���������� ����
        strcpy_s(players_name[i], tempP[i]);
    }
}
void initTurn(void) { // randTurn ���� �������������� �Է¹������ �����ۼ�
    initializeQueue(&turnOrderQueue); // Q�� �Լ��� ������ ���� ��������

    for (int i = 0; i < 4; i++) { //�Է¹��� players�� Q�� ����
        enqueue(&turnOrderQueue, players_name[i]);
    }
}
char* currentTurn(void) { // ���� �� �÷��̾ char*������ ��ȯ
    return showNode(&turnOrderQueue);
}

void endTurn(void) { // ���� �� �÷��̾ �ǵڷ� 
    char* temp = dequeue(&turnOrderQueue);
    enqueue(&turnOrderQueue, temp);
}