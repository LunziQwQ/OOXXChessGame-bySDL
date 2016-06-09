#pragma once
#include <stdio.h>
#include "class_BigBox.h"
#include "class_coor_9.h"
#include "class_coor_3.h"

//���ƶԷ�����λ��
void ban(int BX, int BY);

//��ǰ���������Ƿ��Ѿ�����
bool haveChess(int BX, int BY, int x, int y);

//���ӣ��ɹ�����true�����ɹ�����false
bool fill(int x, int y);

//�жϴ����̵�ʤ����
int checkBigWinner();

//���´�����ս��
void upgradeBig();


//��ǰ���
int currentplayer = 1;
//��ҽ���
void changeplayer(int &currentplayer) {
	if (currentplayer == 1) {
		currentplayer = 2;
	} else if (currentplayer == 2) {
		currentplayer = 1;
	}
}
//���ƶԷ�����λ��
void ban(int BX, int BY) {
	if (Box[BX][BY].get_winner() != 0 || Box[BX][BY].get_isFull()) {			//�������ӵ�λ��
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				if (Box[i][j].get_winner() == 0 && !Box[i][j].get_isFull()) {
					Box[i][j].set_canFill(true);
				}
			}
		}
		//printf("ban can't\n");
	} else if (Box[BX][BY].get_winner() == 0 && !Box[BX][BY].get_isFull()) {		//�������ӵ�λ��
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				if (i == BX && j == BY) {
					Box[i][j].set_canFill(true);
				} else {
					Box[i][j].set_canFill(false);
				}
			}
		}
		//printf("ban can\n");
	}
}

//��ǰ���������Ƿ��Ѿ�����
bool haveChess(int BX, int BY, int x, int y) {
	if (Box[BX][BY].get_smallBox(x, y) == 0) {
		//printf("haveChaess false\n");
		return false;
	}
	//printf("haveChaess true\n");
	return true;
}

//���ӣ��ɹ�����true�����ɹ�����false
bool fill(int x, int y) {
	//coor_9 temp_9(x, y);
	coor_3 temp_3(x, y);
	if (!haveChess(temp_3.get_BX(), temp_3.get_BY(), temp_3.get_x(), temp_3.get_y()) &&
		Box[temp_3.get_BX()][temp_3.get_BY()].get_canFill() &&
		Box[temp_3.get_BX()][temp_3.get_BY()].get_winner() == 0) {
		Box[temp_3.get_BX()][temp_3.get_BY()].set_smallBox(temp_3.get_x(), temp_3.get_y(), currentplayer);
		upgradeBig();
		ban(temp_3.get_x(), temp_3.get_y());
		printf("%d %d\n", temp_3.get_x(), temp_3.get_y());
		//printf("fill success\n");
		return true;
	} else {
		//printf("fill false\n");
		return false;
	}
}

//�жϴ����̵�ʤ����
int checkBigWinner() {
	int wx = 0, wy = 0, winner = 0;
	bool flag = false;
	for (int i = 0; i < MAX; i++) {
		//�жϵ�i���Ƿ�ﵽʤ������
		if (Box[i][0].get_winner() == Box[i][1].get_winner() &&
			Box[i][1].get_winner() == Box[i][2].get_winner() &&
			Box[i][0].get_winner() != 0) {
			wx = i, wy = 0;
			flag = true;
		}
		//�жϵ�i���Ƿ�ﵽʤ������
		if (Box[0][i].get_winner() == Box[1][i].get_winner() &&
			Box[1][i].get_winner() == Box[2][i].get_winner() &&
			Box[0][i].get_winner() != 0) {
			wx = 0, wy = i;
			flag = true;
		}
		//�ж϶Խ����ϵ������Ƿ�ﵽʤ������
		if (i == 0) {
			if (Box[i][i].get_winner() == Box[i + 1][i + 1].get_winner() &&
				Box[i + 1][i + 1].get_winner() == Box[i + 2][i + 2].get_winner() &&
				Box[i][i].get_winner() != 0) {
				wx = i, wy = i;
				flag = true;
			}
			if (Box[i][2 - i].get_winner() == Box[i + 1][1 - i].get_winner() &&
				Box[i + 1][1 - i].get_winner() == Box[i + 2][i].get_winner() &&
				Box[i][2 - i].get_winner() != 0) {
				wx = i, wy = 2 - i;
				flag = true;
			}
		}
	}
	if (flag) {
		winner = Box[wx][wy].get_winner();
	}
	return winner;
}

//���´�����ս��
void upgradeBig() {
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			Box[i][j].checkSmallWinner();
		}
	}
}