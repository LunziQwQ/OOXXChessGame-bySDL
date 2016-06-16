extern StyleSheet SS;
class Resource {
public:
	//��Ϸ���õ���ͼƬ��Դ����
	SDL_Texture* titlePage_background = //��ҳ����
		loadTexture("resource/titlePageBG.png");
	SDL_Texture* gamePage_background =	//��Ϸҳ�����̵ı���
		loadTexture("resource/gamePageBG.png");
	SDL_Texture* chess_O =				//O����
		loadTexture("resource/Opic.png");
	SDL_Texture* chess_X =				//X����
		loadTexture("resource/Xpic.png");
	SDL_Texture* chess_BO =				//�Ŵ�Ĵ�����Ӱ��O����
		loadTexture("resource/Opic.png");
	SDL_Texture* chess_BX =				//�Ŵ�Ĵ�����Ӱ��X����
		loadTexture("resource/BX.png");
	SDL_Texture* titlePage_btn0 =		//��ҳ�ĵ�һ������
		loadTexture("resource/singleBtn.png");
	SDL_Texture* titlePage_btn1 =		//��ҳ�ĵڶ�������
		loadTexture("resource/mulitBtn.png");
	SDL_Texture* titlePage_btn2 =		//��ҳ�ĵ���������
		loadTexture("resource/helpBtn.png");
	SDL_Texture* common_alert =			//ͨ�õ�֪ͨ����
		loadTexture("resource/alert.png");
	SDL_Texture* common_yesBtn =		//֪ͨ����yes��ť
		loadTexture("resource/yes.png");
	SDL_Texture* common_noBtn =			//֪ͨ����no��ť
		loadTexture("resource/no.png");
	SDL_Texture* gamePage_title =		//��Ϸҳ����С����
		loadTexture("resource/smallTitle.png");
	SDL_Texture* gamePage_coffeeCup =	//��Ϸҳ���¿��ȱ�
		loadTexture("resource/coffeeCup.png");
	SDL_Texture* gamePage_blueNext =	//��ɫnextָʾ��
		loadTexture("resource/blueNext.png");
	SDL_Texture* gamePage_redNext =		//��ɫnextָʾ��
		loadTexture("resource/redNext.png");
	SDL_Texture* gamePage_canFill = 
		loadTexture("resource/canFill.png");
	SDL_BlendMode blending;
	int blendStatus = SDL_SetTextureBlendMode(gamePage_canFill, blending);
	int AlphaStatus = SDL_SetTextureAlphaMod(gamePage_canFill, 80);
	//TODO:rednext ��bluenext �� С���⣬���ȱ���Your turn


	//��Ϸ���õ���������Դ����-------------------------------

	//��Ϸҳ�Ҳ� NowTurn ����
	SDL_Texture* gamePage_nowTurn =	renderText("Now Turn",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);

	

	//����0-9������
	SDL_Texture* num_0 = renderText("0",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_1 = renderText("1",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_2 = renderText("2",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_3 = renderText("3",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_4 = renderText("4",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_5 = renderText("5",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_6 = renderText("6",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_7 = renderText("7",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_8 = renderText("8",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);
	SDL_Texture* num_9 = renderText("9",
		"ttf/8bitlimit.ttf",
		SS.Brown, 128, gRenderer);

	//֪ͨ������������--------------------
	SDL_Texture* alert_PairCodeText =
		renderText("Please  input  pair  code",
			"ttf/MindAntiks.ttf",
			SS.Brown, 64, gRenderer);
	SDL_Texture* alert_wantExit =
		renderText("Do you want to leave?",
			"ttf/MindAntiks.ttf",
			SS.Brown, 64, gRenderer);
	SDL_Texture* alert_willLose =
		renderText("You will lose the status.",
			"ttf/MindAntiks.ttf",
			SS.Brown, 64, gRenderer);
	SDL_Texture* alert_redWin = renderText("Red Win",
		"ttf/8bitlimit.ttf",
		SS.red, 256, gRenderer);
	SDL_Texture* alert_blueWin = renderText("Blue Win",
		"ttf/8bitlimit.ttf",
		SS.TYblue, 256, gRenderer);
	SDL_Texture* alert_drawing = renderText("Drawing",
		"ttf/8bitlimit.ttf",
		SS.Green, 256, gRenderer);
private:
	SDL_Texture* XXX() {
		SDL_Texture* temp = NULL;
		
		return temp;
	}
};

