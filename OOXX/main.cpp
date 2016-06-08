#include "string"
#include "cstring"
#include "stdio.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "OOXX-styleSheet.h"
#include "OOXX-common.h"
#include "OOXX-timer.h"
#include "OOXX-animation.h"
#include "OOXX-resource.h"
#include "OOXX-stage.h"
#include "OOXX_keyboard.h"

StyleSheet SS;			//��ʽ����
Timer timer;			//��ʱ��֡������


const int TITLEPAGE = 0;
const int GAMEPAGE = 1;


class Apple {
public:
	Apple(int i) {

	}
};

int main(int argc, char* args[]) {
	
	if (!init(SS)){										//��֤SDL�Ƿ�ɹ�����
		printf("Failed to initialize!\n");
	}else {
		bool quit = false;								//�����˳�flag
		int status = 0;
		//SDL���غ�
		Resource resource;								//����������Դ				
		Keyboard keyboard;								//���ؼ����¼���

		//��̨��ʼ��
		TitlePage titlePage(resource);
		GamePage gamePage(resource);

		//������ѭ�������û��˳�ʱ����
		while (!quit){						
			//�¼�����ѭ��
			while (SDL_PollEvent(&event) != 0){
				//�˳��¼�������ʱ������ѭ��
				if (event.type == SDL_QUIT){
					quit = true;
				}
				//����¼�
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					int x, y;
					SDL_GetMouseState(&x, &y);			//��ȡ���������

					switch (status){
					case TITLEPAGE: status = titlePage.onClick(x, y);
						break;
					case GAMEPAGE: status = gamePage.onClick(x, y);
						break;
					}
				}
				if (event.type == SDL_KEYDOWN) {
				TITLEPAGE:keyboard.onKeyPress(event.key.keysym.sym, status);
				}
			}
			

			switch (status) {
			case TITLEPAGE: 
				titlePage.load();
				break;
			case GAMEPAGE:
				gamePage.load();
				break;

			}
				
			
			SDL_RenderPresent(gRenderer);				//��Ⱦ��ǰ֡������
			SDL_RenderClear(gRenderer);					//�����һ֡������
			timer.fpsControl();							//֡������
		}
	}
	close();											//�رղ��ͷ�SDL���
	return 0;
}




//OOP
/*
Class Mouse
Class Button
Class RankList
Class GameRound
Class chessBoard
Class StyleSheet
Class Animation
Class stage
*/
//�����¼���ѡ������ѡ��ִ����Щ��������
//���������¼��Ķ�����װΪ����
//17FPS