class StyleSheet {

public:
	int Down = 0;
	//�趨λ�÷���
	SDL_Rect setRect(int x, int y, int width, int height);

	//��ɫ�趨
	SDL_Color
		red = { 0xFF, 0x00, 0x00, 0xFF },
		black = { 0x00, 0x00, 0x00, 0xFF },
		white = { 0xFF, 0xFF, 0xFF, 0xFF },
		Gray = { 0xC0, 0xC0, 0xC0, 0xFF },
		Brown = { 0x60, 0x2E, 0x0B, 0xFF },
		Green = { 0x00, 0xFF, 0x00,0xFF },
		TYblue = { 0x66, 0xCC, 0xFF, 0xFF };
		

	//��Ļ�ߴ�
	const int 
		SCREEN_WIDTH = 1024,
		SCREEN_HEIGHT = 768;

	//�ؼ���λ
	SDL_Rect
		//��ҳ*********************
		titlePage_title =		//��ҳ����
		setRect((int)(SCREEN_WIDTH*0.1), 100, (int)(SCREEN_WIDTH*0.8), (int)(SCREEN_HEIGHT*0.3)),

		titlePage_btns[3] = {	//��ҳ��ť��
		setRect((int)(SCREEN_WIDTH*0.5), (int)(SCREEN_HEIGHT*0.5), (int)(SCREEN_WIDTH*0.25), 60),
		setRect((int)(SCREEN_WIDTH*0.55), (int)(SCREEN_HEIGHT*0.65), (int)(SCREEN_WIDTH*0.25), 60),
		setRect((int)(SCREEN_WIDTH*0.6), (int)(SCREEN_HEIGHT*0.8), (int)(SCREEN_WIDTH*0.25), 60),
	},


		//��Ϸҳ********************
		gamePage_chessBoard =	//��Ϸҳ����
		setRect(0, 0, (int)(SCREEN_WIDTH*0.75), SCREEN_HEIGHT),

		*gamePage_chessPoint = getChessPointRects(),	//81������

		gamePage_title =		//��Ϸҳ�Ҳ�С����
		setRect((int)(SCREEN_WIDTH*0.77), 50, (int)(SCREEN_WIDTH*0.22), 100),

		gamePage_cup =			//��Ϸҳ�Ҳ��·����ȱ�
		setRect((int)(SCREEN_WIDTH*0.77), 500, (int)(SCREEN_WIDTH*0.22), 270),

		*gamePage_midBox = getMidBoxRects(),

		gamePage_nowTurn =		//��Ϸҳ�Ҳ��м� "Now Turn" ��������
		setRect((int)(SCREEN_WIDTH*0.78), 250, (int)(SCREEN_WIDTH*0.21), 40),

		gamePage_nowTurnIMG =	//��Ϸҳ�Ҳ��м� ��ǰ�غ����� ͼƬ
		setRect((int)(SCREEN_WIDTH*0.8), 305, 160, 160),

		//֪ͨ����******************
		alert_alertPairCodeText =	//"�����������"
		setRect((int)(SCREEN_WIDTH*0.18), (int)(SCREEN_HEIGHT*0.3), 400, 50),

		alert_wantExit =	//"����Ҫ�˳�ô��"
		setRect((int)(SCREEN_WIDTH*0.22), (int)(SCREEN_HEIGHT*0.32), 400, 60),

		alert_willLose =	//"���ʧȥ��ǰ״̬"
		setRect((int)(SCREEN_WIDTH*0.18), (int)(SCREEN_HEIGHT*0.46), 500, 60),

		*alert_PairCode = getPairCodeRects(),	//�ĸ������

		alert_confirmBtn =						//֪ͨ����ȷ����ť
		setRect((int)(SCREEN_WIDTH*0.56), (int)(SCREEN_HEIGHT*0.61), 100, 70),

		alert_cancleBtn =						//֪ͨ����ȡ����ť
		setRect((int)(SCREEN_WIDTH*0.44), (int)(SCREEN_HEIGHT*0.61), 100, 70),

		alert_gameOver =							//�췽ʤ���ı�
		setRect((int)(SCREEN_WIDTH*0.18), (int)(SCREEN_HEIGHT*0.31), (int)(SCREEN_WIDTH *0.5), (int)(SCREEN_HEIGHT*0.25)),


		//ͨ��**********************
		common_musicSwitchBtn =					//�������ֿ��ư�ť
		setRect(SCREEN_WIDTH-60, SCREEN_HEIGHT-60, 50, 50),

		common_alertWindow =	//ͨ�õ�֪ͨ����
		setRect((int)(SCREEN_WIDTH*0.1), (int)(SCREEN_HEIGHT*0.2), (int)(SCREEN_WIDTH*0.8), (int)(SCREEN_HEIGHT*0.6));

private:
	SDL_Rect* getChessPointRects();
	SDL_Rect* getPairCodeRects();
	SDL_Rect* getMidBoxRects();
};

//�趨λ��
SDL_Rect StyleSheet::setRect(int x, int y, int width, int height) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y + Down;
	rect.w = width;
	rect.h = height;
	return rect;
}

//��������rects����
SDL_Rect* StyleSheet::getChessPointRects() {
	SDL_Rect* rects = new SDL_Rect[81];

	//��������
	int
		count = 0,
		pawnSize = 70,						//�������Ӵ�С
		pawnMargin = 9,						//����֮��ļ��
		areaMargin = 12,					//ÿ��3*3����֮��ļ��
		boardMargin = 20,					//���̱�Ե�����ӵļ�� - ����֮��ļ��
		prev_x = boardMargin,				//�����м��������һ�����ӵ�xƫ����
		prev_y = boardMargin + pawnMargin;	//�����м��������һ�����ӵ�yƫ����
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					rects[count++] = setRect(prev_x + pawnMargin, prev_y, pawnSize, pawnSize);
					prev_x += pawnMargin + pawnSize;
				}
				prev_x += areaMargin - pawnMargin;
			}
			prev_x = boardMargin;
			prev_y += pawnSize + pawnMargin;
		}
		prev_x = boardMargin;
		prev_y += areaMargin - pawnMargin;
	}
	return rects;
}

//������λ��֤��λ��
SDL_Rect* StyleSheet::getPairCodeRects() {
	SDL_Rect* rects = new SDL_Rect[4];
	for (int i = 0; i < 4; i++){
		rects[i] = setRect((int)(SCREEN_WIDTH*0.22)+i*(30+ (int)(SCREEN_WIDTH*0.08)), (int)(SCREEN_HEIGHT*0.39), (int)(SCREEN_WIDTH*0.08), (int)(SCREEN_HEIGHT*0.16));
	}
	return rects;
}

SDL_Rect* StyleSheet::getMidBoxRects() {
	SDL_Rect* rects = new SDL_Rect[9];
	rects[0] = setRect(30, 30, 228, 228);
	rects[1] = setRect(270, 30, 228, 228);
	rects[2] = setRect(510, 30, 228, 228);
	rects[3] = setRect(30, 270, 228, 228);
	rects[4] = setRect(270, 270, 228, 228);
	rects[5] = setRect(510, 270, 228, 228);
	rects[6] = setRect(30, 510, 228, 228);
	rects[7] = setRect(270, 510, 228, 228);
	rects[8] = setRect(510, 510, 228, 228);
	return rects;
}