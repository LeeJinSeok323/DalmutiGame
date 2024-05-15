//// ī�� ���� ����
//
//// sub_fail_check �Լ� : ī�� ���� �� Ʋ�� ī�带 �����ߴ��� üũ (ī�� ���� ��ȿ�� üũ)
//// ----------------Ʋ�� ī�� ���� ����------------------------------
////  1) ���� ī�� ������ 1~13�� �ƴ� ���
////  2) �����ϴ� ī�尡 ���� ������ �ִ� ī�庸�� �� ���� ���
//// ----------------------------------------------------------------------------------------
//
//// check_cards �Լ� : � ī�带 �´��� �˷��ִ� �Լ�
//// card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ�
//// check_player_card �Լ� : ���� �÷��̾ ������ �ִ� ī�带 �ǽð����� ���
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stack>
//#include "[Algorithm]Sorting.h"
//
//int subCardArr[20] = { 0, };
//// ���� ī�� ����
//int beforeCardName = 99;
//int beforeCardCount = 99;
//int pass_3 = 0;
//
//int jokerCount = 0;
//
//#pragma region SubmitCardCheck �Լ� : ī�� ���� �� Ʋ�� ī�带 �����ߴ��� üũ(ī�� ���� ��ȿ�� üũ)
//int sub_fail_check(int cardName, int cardCount, char nowTurnPlayer, int playerCards[4][20], int jokerCount) //ī�� ����� ���������ִ��� üũ
//{
//    if (cardName < 0 || cardName > 13)
//    {
//        return 1; //���� ī�� ������ 1~13�� �ƴ϶�� �����ڵ� 1 return
//    }
//
//    int count = 0; // ���� ��� �ִ� ī�� ���
//    int count_J = 0; //���� ��� �ִ� ��Ŀ ī�� ���
//
//    for (int j = 0; j < 20; j++) // ���� ��� �ִ� ī�� ����� Ȯ���ϴ� �ݺ���
//    {
//        // nowTurnPlayer : ���� player�� ��Ī
//        // cardName : ������ ī�� ��ȣ
//        // ������ ������ ī�� ��ȣ�� ������ ī�� ��ȣ�� �� �� ��ġ�ϴ��� üũ
//        // ex) player2�� ������ �ִ� ���� ..... 10 10 10 10 10 10 ....
//        //10 10 10 10 10 ���� => cardName : 10, count : 6, cardCount : 5
//        if (playerCards[nowTurnPlayer][j] == cardName)
//        {
//            count = count + 1;
//            //������ ī�� ��ȣ�� ��ġ�ϴ� ���� �÷��̾ ������ �ִ� ī�� ���
//        }
//        if (playerCards[nowTurnPlayer][j] == 13)
//        {
//            count_J = count_J + 1;
//            //���� �÷��̾ ������ �ִ� ��Ŀ ���
//        }
//    }
//
//    // card_count : ������ ī���� ���
//    if (cardCount - jokerCount > count || jokerCount > count_J) return 2;               //�����Ϸ��� �� ī�� ����� ����ִ� ī�� ������� ũ�� �����ڵ� 2 return
//    if ((beforeCardCount != 99) && (cardCount != beforeCardCount)) return 3;    //������ ī�尡 ���� �÷��̾ ������ ī�� ����� ���� �ʴٸ� �����ڵ� 3 return
//    if (cardName >= beforeCardName) return 4;       //������ ī�尡 ���� �÷��̾ ������ ī�庸�� ��������� �ƴϸ� �����ڵ� 4 return
//
//
//    beforeCardName = cardName;      //���� �÷��̾ ���� ����� ī�带 ������ �� �ְ� ����
//    beforeCardCount = cardCount;    //���� �÷��̾ ������ ī�� ��� ����
//
//    return 0; //���� ���� �����̶�� 0 return
//}
//#pragma endregion
//
//#pragma region check_cards �Լ� : � ī�带 �´��� �˷��ִ� �Լ� - ������ ī�� ������ �˷��ش�.
//int check_cards(char inputCards[])         //���ڿ� �迭�� ���� ���� � ī�带 �´��� �˷��� int�� return
//{
//    // ex) 11 11 11 => i : 3, ptr : 11, cards �迭���� [11, 11, 11]
//    int cardCount = 0; // cardCount�� ������ ī�� ����
//    char* ptr = strtok(inputCards, " ");   // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
//    while (ptr != NULL)                  // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
//    {
//        subCardArr[cardCount++] = atoi(ptr);    //�߸� ���ڿ��� char���̹Ƿ� int�� ��ȯ
//        ptr = strtok(NULL, " ");         // ���� ���ڿ��� �߶� �����͸� ��ȯ
//    }
//
//    bubble_sort(subCardArr, cardCount);     //��Ŀ�� ���� ���� ���� �������� ����
//    //ex. 10 13 10 13 ����� 10 10 13 13���� ����
//    return cardCount;                       //������ ī����� return
//}
//#pragma endregion
//
//#pragma region joker_count �Լ� : ������ ī�忡 ��Ŀ�� ���� ���ԵǾ� �ִ��� �˷��ִ� �Լ�
//int joker_count(int subCardArr[20], int cardName, int cardCount)    //������ ī�忡 ��Ŀ�� ���� ���ԵǾ� �ִ��� �˷��ش�
//{
//    jokerCount = 0;
//    for (int i = 0; i < cardCount; i++)                 //������ ī�� �����ŭ �ݺ�
//    {
//        if (subCardArr[i] == 13) jokerCount++;           //������ ī�� �迭�� 13(��Ŀ)ī�尡 �ִٸ� jokerCount 1�� ���� - �ִ� 2���� �����Ұ�
//    }
//
//    return jokerCount;                                  //������ ��Ŀ ������ return
//}
//#pragma endregion
//
//#pragma region delete_submited_card �Լ� : ���� �˻���� ���� ���� ������ �Ϸ��ߴٸ� ������ ī�带 �� �÷��̾� ������ ���� �����ִ� �Լ�
//int delete_submited_card(int player_Cards[4][20], char nowTurnPlayer, int cardName, int cardCount, int jokerCount)
//{   //������ ī�带 �� �÷��̾� ������ ���� �����ش�
//    for (int i = 0; i < cardCount - jokerCount; i++) //������ ī���� '��Ŀ�� �ƴ� ī��'�� �÷��̾� ������ ī�� ����
//    {   //10 10 13 13 ����� (��ü ī�� ���) - (��Ŀ ī�� ���) = 4 - 2�� 2���� �ݺ�
//        for (int j = 0; j < 20; j++)
//        {
//            if (player_Cards[nowTurnPlayer][j] == cardName)     //������ ī���ȣ�� ��ġ�ϸ� 0���� ����
//            {
//                player_Cards[nowTurnPlayer][j] = 0;
//                break;
//            }
//        }
//    }
//    for (int i = 0; i < jokerCount; i++) //������ ī���� '��Ŀ ī��'�� �÷��̾� ������ ī�� ����
//    {   //10 10 13 13 ����� ��Ŀ ī�尡 2���̹Ƿ� 2�� �ݺ�
//        for (int j = 0; j < 20; j++)
//        {
//            if (player_Cards[nowTurnPlayer][j] == 13)           //������ ��Ŀ�� ��ġ�ϸ� 0���� ����
//            {
//                player_Cards[nowTurnPlayer][j] = 0;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#pragma endregion
//
//#pragma region card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ� (submitCard.cpp�� ������)
//int card_sub(char player_Name, int player_Cards[4][20]) //ī�� ���� �Լ�
//{
//    if (player_Cards[player_Name][19] == 0)
//    {
//        pass_3++;
//        return 0;
//    }
//    char nowTurnPlayer = player_Name;
//    int playerCards[4][20];
//    for (int i = 0; i < 4; i++) //sub_fail_check�Լ��� �μ� �Ѱ��ֱ� ���� �迭����
//    {
//        for (int j = 0; j < 20; j++)
//            playerCards[i][j] = player_Cards[i][j];
//    }
//
//    int cardName;        //������ ī�� ��ȣ
//    int cardCount;      //������ ī�� ����
//    int correctCard;      //�����ڵ� ��ȣ
//    int pass;            //pass���� ����
//    char inputCards[100];
//
//reset:
//    printf("pass�� 1, ī�������� 0�� �Է��Ͻÿ�(1.pass/0.����) : "); //pass���� Ȯ��
//    scanf("%d", &pass);
//    getchar();
//
//    if (pass_3 >= 3) { // �ƹ��ų� ������ �� �ֵ��� �Ѵ�.
//        beforeCardName = 99;
//        beforeCardCount = 99;
//    }
//
//    if (pass == 1)
//    {
//        printf("���� pass�ϼ̽��ϴ�.\n\n");
//        pass_3++;
//    }
//    else if (pass == 0) //pass���� �ʾҴٸ� ī�� ���� ���� ����
//    {
//        printf("������ ī�带 �Է��Ͻÿ� : ");
//        gets_s(inputCards);     //���ڿ��� ������ ī��� �Է¹ޱ�
//
//        cardCount = check_cards(inputCards);    //ī�� ���
//        cardName = subCardArr[0];               //ī�� ��ȣ
//
//        int jokerCount = joker_count(subCardArr, cardName, cardCount);
//
//        correctCard = sub_fail_check(cardName, cardCount, nowTurnPlayer, playerCards, jokerCount); //������ ī�� ���� ���� Ȯ��
//
//        if (correctCard == 0) printf("ī�尡 ���������� ����Ǿ����ϴ�. \n\n      %d, %d\n", beforeCardName, beforeCardCount);     //return 0 ����
//        else if (correctCard == 1) { printf("%d�� ī�尡 �������� �ʽ��ϴ�.\n\n", cardName); goto reset; }                         //return 1 ����
//        else if (correctCard == 2) { printf("%d�� ī���� ������ �����մϴ�.\n\n", cardName); goto reset; }                         //return 2 ����
//        else if (correctCard == 3) { printf("���� �÷��̾�� ���� ����� %d���� ī�带 �����ؾ� �մϴ�.\n\n", beforeCardCount); goto reset; } //return 3 ����
//        else if (correctCard == 4) { printf("���� �÷��̾ ������ %d�� ī�庸�� ���� ����� ī�带 �����ؾ��մϴ�.\n\n", beforeCardName); goto reset; } //return 4 ����
//
//        delete_submited_card(player_Cards, nowTurnPlayer, cardName, cardCount, jokerCount);
//        pass_3 = 0;
//    }
//    return 0;
//}
//
//#pragma endregion

// START - goto�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include "[Algorithm]Sorting.h"

int subCardArr[20] = { 0, };
int beforeCardName = 99;
int beforeCardCount = 99;
int pass_3 = 0;
int jokerCount = 0;

int sub_fail_check(int cardName, int cardCount, char nowTurnPlayer, int playerCards[4][20], int jokerCount) {
    if (cardName < 0 || cardName > 13) {
        return 1;
    }

    int count = 0;
    int count_J = 0;

    for (int j = 0; j < 20; j++) {
        if (playerCards[nowTurnPlayer][j] == cardName) {
            count = count + 1;
        }
        if (playerCards[nowTurnPlayer][j] == 13) {
            count_J = count_J + 1;
        }
    }

    if (cardCount - jokerCount > count || jokerCount > count_J) return 2;
    if ((beforeCardCount != 99) && (cardCount != beforeCardCount)) return 3;
    if (cardName >= beforeCardName) return 4;

    beforeCardName = cardName;
    beforeCardCount = cardCount;

    return 0;
}

int check_cards(char inputCards[]) {
    int cardCount = 0;
    char* ptr = strtok(inputCards, " ");
    while (ptr != NULL) {
        subCardArr[cardCount++] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }

    bubble_sort(subCardArr, cardCount);

    return cardCount;
}

int joker_count(int subCardArr[20], int cardName, int cardCount) {
    jokerCount = 0;
    for (int i = 0; i < cardCount; i++) {
        if (subCardArr[i] == 13) jokerCount++;
    }

    return jokerCount;
}

int delete_submited_card(int player_Cards[4][20], char nowTurnPlayer, int cardName, int cardCount, int jokerCount) {
    for (int i = 0; i < cardCount - jokerCount; i++) {
        for (int j = 0; j < 20; j++) {
            if (player_Cards[nowTurnPlayer][j] == cardName) {
                player_Cards[nowTurnPlayer][j] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < jokerCount; i++) {
        for (int j = 0; j < 20; j++) {
            if (player_Cards[nowTurnPlayer][j] == 13) {
                player_Cards[nowTurnPlayer][j] = 0;
                break;
            }
        }
    }

    return 0;
}

#pragma region card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ� (submitCard.cpp�� ������)
int card_sub(char player_Name, int player_Cards[4][20]) //ī�� ���� �Լ�
{
    if (player_Cards[player_Name][19] == 0)
    {
        pass_3++;
        return 0;
    }
    char nowTurnPlayer = player_Name;
    int playerCards[4][20];
    for (int i = 0; i < 4; i++) //sub_fail_check�Լ��� �μ� �Ѱ��ֱ� ���� �迭����
    {
        for (int j = 0; j < 20; j++)
            playerCards[i][j] = player_Cards[i][j];
    }

    int cardName = 0;        //������ ī�� ��ȣ
    int cardCount = 0;      //������ ī�� ����
    int correctCard = 0;      //�����ڵ� ��ȣ
    int pass = 0;            //pass���� ����
    char inputCards[100];

    while (pass != 1)
    {
        printf("pass�� 1, ī�������� 0�� �Է��Ͻÿ�(1.pass/0.����) : "); //pass���� Ȯ��
        scanf("%d", &pass);
        getchar();

        if (pass_3 >= 3) { // �ƹ��ų� ������ �� �ֵ��� �Ѵ�.
            beforeCardName = 99;
            beforeCardCount = 99;
        }

        if (pass == 1)
        {
            printf("���� pass�ϼ̽��ϴ�.\n\n");
            pass_3++;
            break;
        }
        else if (pass == 0) //pass���� �ʾҴٸ� ī�� ���� ���� ����
        {
            printf("������ ī�带 �Է��Ͻÿ� : ");
            gets_s(inputCards);     //���ڿ��� ������ ī��� �Է¹ޱ�

            cardCount = check_cards(inputCards);    //ī�� ���
            cardName = subCardArr[0];               //ī�� ��ȣ

            int jokerCount = joker_count(subCardArr, cardName, cardCount);

            correctCard = sub_fail_check(cardName, cardCount, nowTurnPlayer, playerCards, jokerCount); //������ ī�� ���� ���� Ȯ��

            if (correctCard == 0) {
                printf("ī�尡 ���������� ����Ǿ����ϴ�. \n\n      %d, %d\n", beforeCardName, beforeCardCount);     //return 0 ����
                delete_submited_card(player_Cards, nowTurnPlayer, cardName, cardCount, jokerCount);
                pass_3 = 0;
                break;
            }
            else if (correctCard == 1) {
                printf("%d�� ī�尡 �������� �ʽ��ϴ�.\n\n", cardName);
            }
            else if (correctCard == 2) {
                printf("%d�� ī���� ������ �����մϴ�.\n\n", cardName);
            }
            else if (correctCard == 3) {
                printf("������ ������ ī�庸�� ���� ������ ī�带 ������ �� �����ϴ�.\n\n");
            }
            else if (correctCard == 4) {
                printf("������ ������ ī��� ���� ������ ī�带 �����ؾ� �մϴ�.\n\n");
            }
            else if (correctCard == 5) {
                printf("ī���� ��ȣ�� �ùٸ��� �ʽ��ϴ�.\n\n");
            }
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���.\n\n");
        }
    }
    return 0;
}

