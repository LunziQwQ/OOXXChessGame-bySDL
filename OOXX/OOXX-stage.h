//������Ҫʹ�õ�ȫ�ֱ���
extern StyleSheet SS;
extern BIGBOX bigbox;
extern SocketManager socketManager;
extern bool isMulti;
extern bool isFirst;

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

	//�Ƿ�����֪ͨ����
	bool isAlertStatus = false;

	//���ְ����б�
	SDL_Keycode numberKey[20] = {
		SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4,
		SDLK_5, SDLK_6, SDLK_7, SDLK_8, SDLK_9,
		SDLK_KP_0, SDLK_KP_1, SDLK_KP_2, SDLK_KP_3, SDLK_KP_4,
		SDLK_KP_5, SDLK_KP_6, SDLK_KP_7, SDLK_KP_8, SDLK_KP_9,
	};

};

//����ҳ����̨-----------------------------------------------------------
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

		if (btnCode != 0) {

			//��Դ��ڴ���ʱ�ĵ���¼�
			if (isAlertStatus) {
				switch (btnCode) {
				case 4:
					if (pairCode[3] != -1) {	//������4λ����
						sendPairCode();
						isMulti = true;
						isAlertStatus = false;
						return GAMEPAGE;
					} else {
						memset(pairCode, -1, sizeof(pairCode));
						isAlertStatus = false;
						return TITLEPAGE;
					}
					return TITLEPAGE;
				case 5:
					memset(pairCode, -1, sizeof(pairCode));
					isAlertStatus = false;
					return TITLEPAGE;
				}
			}

			//����Դ��ڴ���ʱ����¼�
			else {
				switch (btnCode) {
				case 1:
					return GAMEPAGE;
				case 2:
					isAlertStatus = true;
					return TITLEPAGE;
				case 3:
					system("explorer \"https://github.com/LunziQwQ/OOXXChessGame-bySDL\" ");
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
		if (isAlertStatus) showInput();
		
	}

	//��̨�˳���ת������
	void exit() {

	}

	//�ж�����������չ
	int onBtn(int x,int y) {
		SDL_Rect item;
		if (!isAlertStatus) {
			for (int i = 0; i < 3; i++) {
				item = SS.titlePage_btns[i];
				if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
					return i + 1;
			}
		}
		if (isAlertStatus) {
			item = SS.alert_confirmBtn;		//��Ϊȷ����ť keycode = 4
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 4;
			item = SS.alert_cancleBtn;		//��Ϊȡ����ť keycode = 5
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 5;
		}
		return 0;
	}
private:
	//�Ƿ����˶�����Ϸ��ť�����򵯳��������봰��

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
		for (int i = 0; i < 4; i++)	{
			std::stringstream ss;
			ss << pairCode[i];
			std::string temp;
			ss >> temp;
			data += temp;
		}
		data = "code:" + data;
		socketManager.sendMessage(data.c_str());
		//TODO ����4λ����뵽�����
	}
};



 //��Ϸҳ��̨-----------------------------------------------------------------
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
			//������Ϸ״̬
			if (!isAlertStatus && bigbox.get_bigWinner() == 0) {
				if (btnCode <= 81) {

					if (!isMulti
						|| (isMulti && bigbox.get_currentPlayer() == 1 && isFirst)
						|| (isMulti && bigbox.get_currentPlayer() != 1 && !isFirst)) {

						doStep(btnCode - 1, bigbox.get_currentPlayer());	//����λ������ұ��(��ȡ������ұ�ţ�
						return GAMEPAGE;
					}
				}
				if (btnCode == 100) {
					isAlertStatus = true;
				}

			//��������Ϸ��������������Alert
			}else if (isAlertStatus && bigbox.get_bigWinner() != 0) {
				if (btnCode == 99) {
					isAlertStatus = false;
					bigbox.reset_BIG(1);
					memset(chessStatus, 0, sizeof(chessStatus));
					return TITLEPAGE;
				}
			//�������Ƿ���Ϸ����Alert
			}else if (isAlertStatus && bigbox.get_bigWinner() == 0) {
				if (btnCode == 99) {
					isAlertStatus = false;
					bigbox.reset_BIG(1);
					memset(chessStatus, 0, sizeof(chessStatus));
					return TITLEPAGE;
				}
				if (btnCode == 98) {
					isAlertStatus = false;
					return GAMEPAGE;
				}

			}
		}
		return GAMEPAGE;
	}

	//��Ⱦ����
	void load() {

		//���ر���
		SDL_RenderCopy(gRenderer, resource.gamePage_background, NULL, NULL);
		SDL_RenderCopy(gRenderer, resource.gamePage_title, NULL, &SS.gamePage_title);
		SDL_RenderCopy(gRenderer, resource.gamePage_nowTurn, NULL, &SS.gamePage_nowTurn); 
		SDL_RenderCopy(gRenderer, resource.gamePage_coffeeCup, NULL, &SS.gamePage_cup);

		//�Ҳ� NowTurn ����ͼƬ
		if (bigbox.get_currentPlayer() == 1)
			SDL_RenderCopy(gRenderer, resource.chess_BX, NULL, &SS.gamePage_nowTurnIMG);
		else
			SDL_RenderCopy(gRenderer, resource.chess_BO, NULL, &SS.gamePage_nowTurnIMG);

		for (int i = 0; i < 81; i++){
			if (chessStatus[i] == 1)		//���1
				SDL_RenderCopy(gRenderer, resource.chess_O, NULL, &SS.gamePage_chessPoint[i]);
			if (chessStatus[i] == 2)		//���2
				SDL_RenderCopy(gRenderer, resource.chess_X, NULL, &SS.gamePage_chessPoint[i]);
		}

		if (!isMulti						
			|| (isMulti && bigbox.get_currentPlayer() == 1 && isFirst)
			|| (isMulti && bigbox.get_currentPlayer() != 1 && !isFirst)) {
			showWhereCanFill();			
		}

		showMidBoxStatus();
		
		if (bigbox.get_bigWinner() != 0) {	//��Ϸ���ֽ��
			isAlertStatus = true;
			SDL_RenderCopy(gRenderer, resource.common_alert, NULL, &SS.common_alertWindow);
			SDL_RenderCopy(gRenderer, resource.common_yesBtn, NULL, &SS.alert_confirmBtn);

			if (bigbox.get_bigWinner() == 1)
				SDL_RenderCopy(gRenderer, resource.alert_redWin, NULL, &SS.alert_gameOver);
			if (bigbox.get_bigWinner() == 2)
				SDL_RenderCopy(gRenderer, resource.alert_blueWin, NULL, &SS.alert_gameOver);
			if (bigbox.get_bigWinner() == 3)
				SDL_RenderCopy(gRenderer, resource.alert_drawing, NULL, &SS.alert_gameOver);
		}
		//������Ƿ��˳�Aleat
		if (bigbox.get_bigWinner() == 0 && isAlertStatus) {
			SDL_RenderCopy(gRenderer, resource.common_alert, NULL, &SS.common_alertWindow);
			SDL_RenderCopy(gRenderer, resource.common_yesBtn, NULL, &SS.alert_confirmBtn);
			SDL_RenderCopy(gRenderer, resource.common_noBtn, NULL, &SS.alert_cancleBtn);
			SDL_RenderCopy(gRenderer, resource.alert_wantExit, NULL, &SS.alert_wantExit);
			SDL_RenderCopy(gRenderer, resource.alert_willLose, NULL, &SS.alert_willLose);
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
		//������Ϸ״̬
		if (!isAlertStatus && bigbox.get_bigWinner() == 0) {
			for (int i = 0; i < 81; i++) {
				SDL_Rect item = SS.gamePage_chessPoint[i];
				if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
					return i + 1;
			}
			SDL_Rect item = SS.gamePage_title;
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 100;	//����alert�Ƿ��˳����˵�

		//��������Ϸ��������������Alert
		} else if(isAlertStatus && bigbox.get_bigWinner() != 0){
			SDL_Rect item = SS.alert_confirmBtn;
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 99;	//���ȷ��
		//�������Ƿ���Ϸ����Alert
		} else if (isAlertStatus && bigbox.get_bigWinner() == 0) {
			SDL_Rect item = SS.alert_confirmBtn;
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 99;	//���ȷ��
			item = SS.alert_cancleBtn;
			if (!(x<item.x || x>(item.x + item.w) || y<item.y || y>(item.y + item.h)))
				return 98;	//���ȡ��
		}
		return 0;
	}

	void getMultiStep(std::string result) {
		int index = atoi(result.c_str());
		if (bigbox.fill((index) / 9, (index) % 9)) {
			chessStatus[index] = bigbox.get_currentPlayer();
		}
	}

	//������ڿ���������ʱ��ʾ������һ���Ŀ���������    ����������*****************************************
	void onHover(int x, int y) {
		int btnCode = onBtn(x, y);
		if (btnCode != 0) {
			int index = (btnCode - 1) / 9 % 3 * 3 + (btnCode - 1) % 9 % 3;
			COOR_3 temp((btnCode - 1) / 9, (btnCode - 1) % 9);
			if (bigbox.Box[temp.get_BX()][temp.get_BY()].get_canFill()
				&& !bigbox.Box[temp.get_BX()][temp.get_BY()].haveChess(temp.get_x(),temp.get_y())) {	//��ǰ���λ�ÿ�����

				if (bigbox.Box[index / 3][index % 3].get_winner() == 0) {	//ӳ��midBox������

					if (bigbox.get_currentPlayer() == 1)
						SDL_RenderCopy(gRenderer, resource.gamePage_blueNext, NULL, &SS.gamePage_midBox[index]);
					else
						SDL_RenderCopy(gRenderer, resource.gamePage_redNext, NULL, &SS.gamePage_midBox[index]);

				} else {

					for (int i = 0; i < 9; i++) {
						if (bigbox.Box[i / 3][i % 3].get_winner() == 0) {

							if (bigbox.get_currentPlayer() == 1)
								SDL_RenderCopy(gRenderer, resource.gamePage_blueNext, NULL, &SS.gamePage_midBox[i]);
							else
								SDL_RenderCopy(gRenderer, resource.gamePage_redNext, NULL, &SS.gamePage_midBox[i]);

						}
					}

				}

			}
		}
	}


private:
	int gameStatus = 0;			//{0:��Ϸ����, 1 : ���1ʤ��, 2 : ���2ʤ��, 3 : ��Ϸ�����;�}
	int chessStatus[81];


	//���ӷ�����
	void doStep(int index, int player) {

		//���õ��Ƿ�������
		if ( bigbox.fill((index) / 9, (index) % 9)) {

			//��Ϊ����ģʽ׷�����ݷ���
			if (isMulti) {

				//������ת��Ϊ�ַ���
				char data[4];
				//��������˷���������ַ�������
				socketManager.sendMessage(itoa(index, data, 10));
				cout << data << endl;
			}
			chessStatus[index] = bigbox.get_currentPlayer();	//1��2
		}

		//ѯ�ʵ�ǰ��Ϸ״̬������
		gameStatus = bigbox.get_bigWinner();
	}

	//��ʾ�����ӵ����� ��͸��ɫ��
	void showWhereCanFill() {
		for (int i = 0; i < 9; i++){
			if (bigbox.Box[i / 3][i % 3].get_canFill()) {
				SDL_RenderCopy(gRenderer, resource.gamePage_canFill, NULL, &SS.gamePage_midBox[i]);
			}
		}
	}

	//��ʾMIDBOXս��
	void showMidBoxStatus() {
		for (int i = 0; i < 9; i++){
			if (bigbox.Box[i / 3][i % 3].get_winner() == 1)
				SDL_RenderCopy(gRenderer, resource.chess_BX, NULL, &SS.gamePage_midBox[i]);
			if (bigbox.Box[i / 3][i % 3].get_winner() == 2)
				SDL_RenderCopy(gRenderer, resource.chess_BO, NULL, &SS.gamePage_midBox[i]);
			//if (bigbox.Box[i / 3][i % 3].get_winner() == 3)
				//TODO ����ʱMIDBOX��״̬

		}
	}


};