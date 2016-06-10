#pragma once
#include "MAX.h"
#include "class_MIDBOX.h"
class BIGBOX{
private:
	int bigWinner = 0;
	int currentPlayer = 0;
public:
	BIGBOX(int player);

	MIDBOX Box[MAX][MAX];

	//��ȡ��ǰ���
	int get_currentPlayer();

	//�޸ĵ�ǰ���
	void set_currentPlayer(int player);

	//�ֻ���ǰ���
	void changePlayer(int currentplayer);

	//��ȡ�����̵�ʤ����
	int get_bitWinner();

	//���ӣ��ɹ�����true�����ɹ�����false
	bool fill(int x, int y);

	//���ƶԷ�����
	void ban(int BX, int BY);

	//�жϴ����̵�ʤ����
	int checkBigWinner();

	//���´�����ս��
	void upgradeBig();
};