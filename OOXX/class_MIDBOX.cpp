#include "MAX.h"
#include "class_MIDBOX.h"
#include "class_COOR_3.h"
#include <stdio.h>
//��ʼ��С����	
MIDBOX::MIDBOX() {
	canFill = true;
	isFull = false;
	winner = 0;
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			smallBox[i][j] = 0;
		}
	}
}
//��ȡcanFill��ֵ
bool MIDBOX::get_canFill() {
	return canFill;
}
//�޸�canFill��ֵ
void MIDBOX::set_canFill(bool x) {
	canFill = x;
}
//��ȡisFull��ֵ
bool MIDBOX::get_isFull() {
	return isFull;
}
//�޸�isFull��ֵ
void MIDBOX::set_isFull(bool x) {
	isFull = x;
}
//��ȡwinner��ֵ (0,1,2,3)
int MIDBOX::get_winner() {
	return winner;
}
//�޸�winner��ֵ
void MIDBOX::set_winner(int x) {
	winner = x;
}
//��ȡsmallBox��ֵ
int MIDBOX::get_smallBox(int x, int y) {
	return smallBox[x][y];
}
//�޸�smallBox��ֵ
void MIDBOX::set_smallBox(int x, int y, int n) {
	smallBox[x][y] = n;
	//printf("set small success\n");
}

//��鵱ǰС�����Ƿ�ռ��
void MIDBOX::ifFull() {
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			if (smallBox[i][j] != 0) {
				isFull = false;
				return;
			}
		}
	}
	isFull = true;
	return;
}
//��鵱ǰС�����Ƿ������ʤ��������ֵΪʤ������ұ��
void MIDBOX::checkSmallWinner() {
	int wx = 0, wy = 0;
	bool flag = false;
	for (int i = 0; i < MAX; i++) {
		//�жϵ�i���Ƿ�ﵽʤ������
		if (smallBox[i][0] == smallBox[i][1] &&
			smallBox[i][1] == smallBox[i][2] &&
			smallBox[i][0] != 0) {
			wx = i, wy = 0;
			flag = true;
		}
		//�жϵ�i���Ƿ�ﵽʤ������
		if (smallBox[0][i] == smallBox[1][i] &&
			smallBox[1][i] == smallBox[2][i] &&
			smallBox[0][i] != 0) {
			wx = 0, wy = i;
			flag = true;
		}
		//�ж϶Խ����ϵ������Ƿ�ﵽʤ������
		if (i == 0) {
			if (smallBox[i][i] == smallBox[i + 1][i + 1] &&
				smallBox[i + 1][i + 1] == smallBox[i + 2][i + 2] &&
				smallBox[i][i] != 0) {
				wx = i, wy = i;
				flag = true;
			}
			if (smallBox[i][2 - i] == smallBox[i + 1][1 - i] &&
				smallBox[i + 1][1 - i] == smallBox[i + 2][i] &&
				smallBox[i][2 - i] != 0) {
				wx = i, wy = 2 - i;
				flag = true;
			}
		}
	}
	if (flag) {
		winner = smallBox[wx][wy];
	}
	if (winner == 0 && !get_isFull()){
		winner = 4;
	}
}

bool MIDBOX::haveChess(int x, int y) {
	if (get_smallBox(x, y) == 0) {
		printf("haveChess false\n");
		return false;
	}
	printf("haveChess true\n");
	return true;
}

void MIDBOX::reset_MID() {
	canFill = true;
	isFull = false;
	winner = 0;
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			smallBox[i][j] = 0;
		}
	}
}
