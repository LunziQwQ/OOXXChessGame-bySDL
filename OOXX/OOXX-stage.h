//������Ҫʹ�õ�ȫ�ֱ���
extern StyleSheet SS;
extern BIGBOX bigbox;
extern SocketManager socketManager;

//��̨�ӿ��࣬����ÿ����̨���븴д�ķ���
class Stage {

public:
	//��ǰ�������췽���Ĳ���
	Resource resource;			
	
	//���������
	virtual int onClick(int x, int y) = 0;		//Music��ťͳһbtnCodeΪ233

	//���̰�������
	virtual void onKeyPress(int keyCode) = 0;

	//������Ⱦ����
	virtual void load() = 0;

	//�˳�ת������
	virtual void exit() = 0;

protected:
	//��̨��Ŷ���
	const int TITLEPAGE = 0;
	const int GAMEPAGE = 1;

	//���ְ����б�
	SDL_Keycode numberKey[20] = {
		SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4,
		SDLK_5, SDLK_6, SDLK_7, SDLK_8, SDLK_9,
		SDLK_KP_0, SDLK_KP_1, SDLK_KP_2, SDLK_KP_3, SDLK_KP_4,
		SDLK_KP_5, SDLK_KP_6, SDLK_KP_7, SDLK_KP_8, SDLK_KP_9,
	};

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
					if (pairCode[3] != -1) {	//������4λ����
						sendPairCode();
					} else {
						//TODO �ı��������������������
					}
					return TITLEPAGE;
				case 5:
					//do something onCancleClick
					memset(pairCode, -1, sizeof(pairCode));
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
	void onKeyPress(SDL_Keycode keycode) {

		//����Ƿ�����Ϊ����
		int NumInput = -1;
		for (int i = 0; i < 20; i++) {
			if (keycode == numberKey[i])
				NumInput = i % 10;
		}
		if (NumInput >= 0){
			for (int i = 0; i < 4; i++){
				if (pairCode[i] == -1) {
					pairCode[i] = NumInput;
					break;
				}
			}
		}
		

	}

	//��Ⱦ����
	void load() {
		//���ظ�������ı���
		SDL_RenderCopy(gRenderer, resource.titlePage_background, NULL, NULL);

		//����������ť
		SDL_RenderCopy(gRenderer, resource.titlePage_btn0, NULL, &SS.titlePage_btns[0]);
		SDL_RenderCopy(gRenderer, resource.titlePage_btn1, NULL, &SS.titlePage_btns[1]);
		SDL_RenderCopy(gRenderer, resource.titlePage_btn2, NULL, &SS.titlePage_btns[2]);
		
		//�����������Ϸ�Ǵ���������봰��
		if (isPairStatus) showInput();		
		
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

	//��ʱ�洢
	int pairCode[4] = {-1,-1,-1,-1};

	//��ʾ����������봰��
	void showInput() {	
		
		SDL_RenderCopy(gRenderer, resource.common_alert, NULL, &SS.common_alertWindow);
		SDL_RenderCopy(gRenderer, resource.alert_PairCodeText, NULL, &SS.alert_alertPairCodeText);
		SDL_RenderCopy(gRenderer, resource.common_yesBtn, NULL, &SS.alert_confirmBtn);
		SDL_RenderCopy(gRenderer, resource.common_noBtn, NULL, &SS.alert_cancleBtn);
		for (int i = 0; i < 4; i++){
			if (pairCode[i] >= 0) {
				switch (pairCode[i]){
				case 0:
					SDL_RenderCopy(gRenderer, resource.num_0, NULL, &SS.alert_PairCode[i]);
					break;
				case 1:
					SDL_RenderCopy(gRenderer, resource.num_1, NULL, &SS.alert_PairCode[i]);
					break;
				case 2:
					SDL_RenderCopy(gRenderer, resource.num_2, NULL, &SS.alert_PairCode[i]);
					break;
				case 3:
					SDL_RenderCopy(gRenderer, resource.num_3, NULL, &SS.alert_PairCode[i]);
					break;
				case 4:
					SDL_RenderCopy(gRenderer, resource.num_4, NULL, &SS.alert_PairCode[i]);
					break;
				case 5:
					SDL_RenderCopy(gRenderer, resource.num_5, NULL, &SS.alert_PairCode[i]);
					break;
				case 6:
					SDL_RenderCopy(gRenderer, resource.num_6, NULL, &SS.alert_PairCode[i]);
					break;
				case 7:
					SDL_RenderCopy(gRenderer, resource.num_7, NULL, &SS.alert_PairCode[i]);
					break;
				case 8:
					SDL_RenderCopy(gRenderer, resource.num_8, NULL, &SS.alert_PairCode[i]);
					break;
				case 9:
					SDL_RenderCopy(gRenderer, resource.num_9, NULL, &SS.alert_PairCode[i]);
					break;
				}
			}
		}
	}

	void sendPairCode() {
		std::string data = "";
		//TODO ����4λ����뵽�����
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

	//�������
	int onClick(int x, int y) {
		int btnCode = onBtn(x, y);
		printf("OnCLick --> KEYCODE:%d\n", btnCode);
		if (btnCode != 0) {
			if (btnCode < 81) {
				doStep(btnCode - 1, bigbox.get_currentPlayer());	//����λ������ұ��(��ȡ������ұ�ţ�
				return GAMEPAGE;
			}
		}
		return TITLEPAGE;
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

	//��������
	void onKeyPress(int keyCode) {

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
		if ( bigbox.fill((index) / 9, (index) % 9)) {
			
			//������ת��Ϊ�ַ���
			char data[4];

			//��������˷���������ַ�������
			socketManager.sendMessage(itoa(index, data, 10));
			chessStatus[index] = bigbox.get_currentPlayer();	//1��2
		}

		//ѯ�ʵ�ǰ��Ϸ״̬������
		gameStatus = bigbox.get_bigWinner();
	}
};