extern StyleSheet SS;
class Resource {
public:
	//��Ϸ���õ���ͼƬ��Դ����
	SDL_Texture* titlePage_background = //��ҳ����
		loadTexture("resource/background.png");
	SDL_Texture* gamePage_background =	//��Ϸҳ�����̵ı���
		loadTexture("resource/gamePage-02.png");
	SDL_Texture* chess_O =				//O����
		loadTexture("resource/Opic.png");
	SDL_Texture* chess_X =				//X����
		loadTexture("resource/Xpic.png");

	//��Ϸ���õ���������Դ����
	SDL_Texture* titlePage_btn0 = //��ҳ������ť������
		renderText("Single Play",
			"ttf/consolab.ttf",
			SS.black, 64, gRenderer);
	SDL_Texture* titlePage_btn1 = 
		renderText("Multi Play",
			"ttf/consolab.ttf",
			SS.black, 64, gRenderer);
	SDL_Texture* titlePage_btn2 =
		renderText("About us & Help",
			"ttf/consolab.ttf",
			SS.black, 64, gRenderer);

	SDL_Texture* titlePage_title = //��ҳ����
		renderText("OOXX Chess!",
			"ttf/consolab.ttf",
			SS.red, 256, gRenderer);

	//����0-9������
	SDL_Texture* num_0 = renderText("0",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_1 = renderText("1",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_2 = renderText("2",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_3 = renderText("3",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_4 = renderText("4",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_5 = renderText("5",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_6 = renderText("6",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_7 = renderText("7",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_8 = renderText("8",
		"ttf/consolab.ttf",
		SS.black, 64, gRenderer);
	SDL_Texture* num_9 = renderText("9",
			"ttf/consolab.ttf",
			SS.black, 64, gRenderer); 

	//֪ͨ������������
	SDL_Texture* alert_PairCodeText =
		renderText("Please input pair code:",
			"ttf/consolab.ttf",
			SS.black, 64, gRenderer);
		
private:
	SDL_Texture* XXX() {
		SDL_Texture* temp = NULL;
		
		return temp;
	}
};

