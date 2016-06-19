#pragma once
#include "MAX.h"
#include "class_MIDBOX.h"
class BIGBOX{
private:
	int bigWinner = 0;
	int currentPlayer = 1;
public:
	BIGBOX(int player);

	MIDBOX Box[MAX][MAX];

	//��ȡ��ǰ���
	int get_currentPlayer();

	//�޸ĵ�ǰ���
	void set_currentPlayer(int player);

	//�ֻ���ǰ���
	void changePlayer(int currentplayer);

	//��ȡ�����̵�ʤ����	{0:��Ϸ����, 1:���1ʤ��, 2:���2ʤ��, 3:��Ϸ�����;�}
	int get_bigWinner();

	//���ӣ��ɹ�����true�����ɹ�����false
	bool fill(int x, int y);

	//���ƶԷ�����
	void ban(int BX, int BY);

	//�жϴ����̵�ʤ����
	void checkBigWinner();

	//���´�����ս��
	void upgradeBig();

	//������������
	void reset_BIG(int player);
};
