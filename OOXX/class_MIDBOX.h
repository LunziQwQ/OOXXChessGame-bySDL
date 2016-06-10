#pragma once
#include "MAX.h"

//�󷽸���
class MIDBOX{
private:
//�����̱��غ��Ƿ���������
	bool canFill;

//��С�����Ƿ�����
	bool isFull;

//��С��������λ��һ�ʤ
	int winner;

//С�����ö�ά�����¼
	int smallBox[MAX][MAX];
public:
//��ʼ��С����	
	MIDBOX();
//��ȡcanFill��ֵ
	bool get_canFill();
//�޸�canFill��ֵ
	void set_canFill(bool x);
//��ȡisFull��ֵ
	bool get_isFull();
//�޸�isFull��ֵ
	void set_isFull(bool x);
//��ȡwinner��ֵ
	int get_winner();
//�޸�winner��ֵ
	void set_winner(int x);
//��ȡsmallBox��ֵ
	int get_smallBox(int x, int y);
//�޸�smallBox��ֵ
	void set_smallBox(int x, int y, int n);

//��鵱ǰС�����Ƿ�ռ��
	void ifFull();
//��鵱ǰС�����Ƿ������ʤ��������ֵΪʤ������ұ��
	void checkSmallWinner();

//��ǰ���������Ƿ��Ѿ�����
	bool haveChess(int x, int y);
};  
