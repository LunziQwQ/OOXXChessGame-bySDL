//������Ҫʹ�õ�ȫ�ֱ���
extern StyleSheet SS;
extern BIGBOX bigbox;
extern SocketManager socketManager;

//��̨�ӿ��࣬����ÿ����̨���븴д�ķ���
class Stage {

public:
	//��ǰ�������췽���Ĳ���
	Resource resource;			

	//��̨��Ŷ���
	const int TITLEPAGE = 0;
	const int GAMEPAGE = 1;

	//���������
	virtual int onClick(int x, int y) = 0;		//Music��ťͳһbtnCodeΪ233

	//virtual void onKeyPress(int keyCode) = 0;

	//������Ⱦ����
	virtual void load() = 0;

	//�˳�ת������
	virtual void exit() = 0;

private:

};

//����ҳ����̨
class TitlePage :public Stage {

public:
	//���췽��
	TitlePage(Resource temp) {
		resource = temp;
	}

	//���������
	int onClick(int x, int y) {
		int btnCode = onBtn(x, y);	//��ȡbtnCode�������ڰ����Ϸ��� 0
		printf("OnClick --> KEYCODE:%d\n", btnCode);

		if (btnCode == 233) {
			//switchMusic()
			//TODO
		}
		if (btnCode != 0) {

			//��Դ��ڴ���ʱ�ĵ���¼�
			if (isPairStatus) {
				switch (btnCode) {
				case 4:
					//do something onConfirmClick
					return TITLEPAGE;
				case 5:
					//do something onCancleClick
					isPairStatus = false;
					return TITLEPAGE;
				}
			}

			//����Դ��ڴ���ʱ����¼�
			else {
				switch (btnCode) {
				case 1:
					return GAMEPAGE;
				case 2:
					isPairStatus = true;
					return TITLEPAGE;
				}
			}
		}

		//���δ����հ�ʱĬ�ϲ��л���̨
		return TITLEPAGE;
	}

	//��������
	void onKeyPress(int keyCode) {
		
	}

	//��Ⱦ����
	void load() {
		//���ظ�������ı���
		SDL_RenderCopy(gRenderer, resource.titlePage_background, NULL, NULL);

		//����������ť
		SDL_RenderCopy(gRenderer, resource.titlePage_btn0, NULL, &SS.titlePage_btns[0]);
		SDL_RenderCopy(gRenderer, resource.titlePage_btn1, NULL, &SS.titlePage_btns[1]);
		SDL_RenderCopy(gRenderer, resource.titlePage_btn2, NULL, &SS.titlePage_btns[2]);
		

		if (isPairStatus) showInput();		//�����������Ϸ�Ǵ���������봰��
		
	}

	//��̨�˳���ת������
	void exit() {

	}

	//�ж�����������չ
	int onBtn(int x,int y) {
		SDL_Rect item;
		for (int i = 0; i < 3; i++) {
			item = SS.titlePage_btns[i];
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return i+1;
		}
		item = SS.alert_confirmBtn;		//��Ϊȷ����ť keycode = 4
		if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
			return 4;
		item = SS.alert_cancleBtn;		//��Ϊȡ����ť keycode = 5
		if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
			return 5;
		item = SS.common_musicSwitchBtn;//��Ϊmusic��ť keycode = 233
		if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
			return 233;
		return 0;
	}
private:
	//�Ƿ����˶�����Ϸ��ť�����򵯳��������봰��
	bool isPairStatus = false;		

	//��ʾ����������봰��
	void showInput() {	

		SDL_RenderCopy(gRenderer, resource.common_alert, NULL, &SS.common_alertWindow);
		SDL_RenderCopy(gRenderer, resource.alert_PairCodeText, NULL, &SS.alert_alertPairCodeText);

		SDL_RenderCopy(gRenderer, resource.common_yesBtn, NULL, &SS.alert_confirmBtn);
		SDL_RenderCopy(gRenderer, resource.common_noBtn, NULL, &SS.alert_cancleBtn);
		SDL_RenderFillRects(gRenderer, SS.alert_PairCode, 4);
	}
};



 //��Ϸҳ��̨
class GamePage :public Stage {

public:
	//���췽��
	GamePage(Resource temp) {
		resource = temp;
		memset(chessStatus, 0, sizeof(chessStatus));
	}

	//��������
	int onClick(int x, int y) {
		int btnCode = onBtn(x, y);
		printf("OnCLick --> KEYCODE:%d\n", btnCode);
		if (btnCode != 0) {
			if (btnCode < 81) {
				doStep(btnCode - 1, bigbox.get_currentPlayer());	//����λ������ұ��(��ȡ������ұ�ţ�
				return GAMEPAGE;
			}
		}
		return GAMEPAGE;
	}

	//��Ⱦ����
	void load() {

		//���ر���
		SDL_RenderCopy(gRenderer, resource.gamePage_background, NULL, NULL);
		for (int i = 0; i < 81; i++){

			if (chessStatus[i] == 1)		//���1
				SDL_RenderCopy(gRenderer, resource.chess_O, NULL, &SS.gamePage_chessPoint[i]);
			if (chessStatus[i] == 2)		//���2
				SDL_RenderCopy(gRenderer, resource.chess_X, NULL, &SS.gamePage_chessPoint[i]);
		}
	}

	//��̨�˳���ת������
	void exit() {

	}

	//�ж����λ�÷��� return BtnCode
	int onBtn(int x, int y) {
		for (int i = 0; i < 81; i++) {
			SDL_Rect item = SS.gamePage_chessPoint[i];
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return i + 1;
		}
		return 0;
	}

private:
	int gameStatus = 0;			//{0:��Ϸ����, 1 : ���1ʤ��, 2 : ���2ʤ��, 3 : ��Ϸ�����;�}
	int chessStatus[81];

	//���ӷ�����
	void doStep(int index, int player) {

		//���õ��Ƿ�������
		if ( bigbox.fill((index + 1) / 9, (index + 1) % 9)) {
			
			//������ת��Ϊ�ַ���
			char data[4];

			//��������˷���������ַ�������
			socketManager.sendMessage(itoa(index,data,10));
			chessStatus[index] = bigbox.get_currentPlayer();	//1��2
		}

		//ѯ�ʵ�ǰ��Ϸ״̬������
		gameStatus = bigbox.get_bigWinner();
	}
};