#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "[Logic]cardDistribute.h" // ī�� �й� ���� 
#include "[Logic]submitCard.h" // ī�� ���� ���� (��ȿ�� üũ ����)
#include "[Logic]turnManager.h" // �� ���� ����
#include "[Algorithm]sorting.h" // ���� �˰��� ����
#include "[Logic]PrintPlayerCards.h" // ī�� ���


#define NUM_PLAYERS 4

int main()
{
    srand(time(NULL));
    int player1, player2, player3, player4;
    int NumPlayers = 4; // �÷��̾� �ο� �� (����� 4������ ����)
    int players[4][20];


    distributeCards(NumPlayers, players); // ī�� �й� 
    printPlayerCards(players); // �й��� ī�� ���

    printf("\n\n\n\n\n");

    PlayerTurnManagement(players);



    return 0;
}