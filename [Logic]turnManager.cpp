#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "[Logic]submitCard.h"
#include "[Logic]PrintPlayerCards.h"

int turn = 0;
extern int pass_3;

void PlayerTurnManagement(int players[4][20]) {

    srand(time(NULL));
    int turn = rand() % 4 + 1;
    if (turn == 1)
    {
        while (1) {
            getchar();
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);

            printPlayerCards(players);
        }
    }
    else if (turn == 2)
    {
        while (1) {
            getchar();
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);

            printPlayerCards(players);
        }
    }
    else if (turn == 3)
    {
        while (1) {
            getchar();
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);

            printPlayerCards(players);
        }
    }
    else if (turn == 4)
    {
        while (1) {
            getchar();
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);

            printPlayerCards(players);
        }
    }

    printf("\n\n\n");
}