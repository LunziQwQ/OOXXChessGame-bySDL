extern StyleSheet SS;
class Resource {
public:
	//��Ϸ���õ���ͼƬ��Դ����
	SDL_Texture* titlePage_background = //��ҳ����
		loadTexture("resource/background.png");
	SDL_Texture* gamePage_background =	//��Ϸҳ�����̵ı���
		loadTexture("resource/gamePage-02.png");

	//��Ϸ���õ���������Դ����
	SDL_Texture* titlePage_btn0 = //��ҳ������ť������
		renderText("Single Play",
			"ttf/consolab.ttf",
			SS.black, 32, gRenderer);
	SDL_Texture* titlePage_btn1 = 
		renderText("Multi Play",
			"ttf/consolab.ttf",
			SS.black, 32, gRenderer);
	SDL_Texture* titlePage_btn2 =
		renderText("About us & Help",
			"ttf/consolab.ttf",
			SS.black, 32, gRenderer);

	SDL_Texture* titlePage_title = //��ҳ����
		renderText("OOXX Chess!",
			"ttf/consolab.ttf",
			SS.red, 256, gRenderer);

};

