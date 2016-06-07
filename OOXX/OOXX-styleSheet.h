class StyleSheet {
public:
	int Down = 0;
	//�趨λ�÷���
	SDL_Rect setRect(int x, int y, int width, int height);
	SDL_Rect* getChessPoint();

	//��ɫ�趨
	SDL_Color
		red = { 0xFF, 0x00, 0x00, 0xFF },
		black = { 0x00, 0x00, 0x00, 0xFF },
		white = { 0xFF, 0xFF, 0xFF, 0xFF },
		TYblue = { 0x66, 0xCC, 0xFF, 0xFF };
		

	//��Ļ�ߴ�
	const int 
		SCREEN_WIDTH = 1024,
		SCREEN_HEIGHT = 768;

	//�ؼ���λ
	SDL_Rect
		titlePage_title =		//��ҳ����
		setRect(SCREEN_WIDTH*0.1, 100, SCREEN_WIDTH*0.8, SCREEN_HEIGHT*0.3),

		titlePage_btns[3] = {	//��ҳ��ť��
		setRect(SCREEN_WIDTH*0.375, SCREEN_HEIGHT*0.5, SCREEN_WIDTH*0.25, 60),
		setRect(SCREEN_WIDTH*0.375, SCREEN_HEIGHT*0.65, SCREEN_WIDTH*0.25, 60),
		setRect(SCREEN_WIDTH*0.375, SCREEN_HEIGHT*0.8, SCREEN_WIDTH*0.25, 60),
		},

		gamePage_chessBoard =	//��Ϸҳ����
		setRect(0, 0, SCREEN_WIDTH*0.75, SCREEN_HEIGHT),

		*gamePage_chessPoint = getChessPoint(),

		gamePage_title =		//��Ϸҳ�Ҳ�С����
		setRect(SCREEN_WIDTH*0.75, 100, SCREEN_WIDTH*0.2, 200);

	
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
SDL_Rect* StyleSheet::getChessPoint() {
	SDL_Rect* rects = new SDL_Rect[81];
	//��������
	int
		count = 0,
		pawnSize = 68,						//�������Ӵ�С
		pawnMargin = 10,					//����֮��ļ��
		areaMargin = 20,					//ÿ��3*3����֮��ļ��
		boardMargin = 15,					//���̱�Ե�����ӵļ�� - ����֮��ļ��
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

