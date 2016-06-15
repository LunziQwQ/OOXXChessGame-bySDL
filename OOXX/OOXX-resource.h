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
	//TODO:rednext ��bluenext �� С���⣬���ȱ���Your turn


	//��Ϸ���õ���������Դ����
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

	//֪ͨ������������
	SDL_Texture* alert_PairCodeText =
		renderText("Please input pair code:",
			"ttf/consolab.ttf",
			SS.Brown, 64, gRenderer);
		
private:
	SDL_Texture* XXX() {
		SDL_Texture* temp = NULL;
		
		return temp;
	}
};

