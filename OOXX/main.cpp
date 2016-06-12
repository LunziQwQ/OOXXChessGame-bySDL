#include "string"
#include "cstring"
#include "sstream"
#include "stdio.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "OOXX-styleSheet.h"
#include "OOXX-common.h"
#include "OOXX-timer.h"
#include "OOXX-animation.h"
#include "OOXX-resource.h"
#include "OOXX_keyboard.h"
#include "MAX.h"
#include "class_coor_3.h"
#include "class_MIDBOX.h"
#include "class_BigBox.h"
#include "class_coor_9.h"
#include "function.h"
#include "OOXX_SocketManager.h"
#include "OOXX-stage.h"

StyleSheet SS;			//��ʽ����
Timer timer;			//��ʱ��֡������

BIGBOX bigbox(1);

const int TITLEPAGE = 0;
const int GAMEPAGE = 1;

std::string host("119.29.177.191");
std::string service("4001");
SocketManager socketManager(host, service);
char buf[1000];

int main(int argc, char* args[]) {

	std::string code("code:12");
	socketManager.link();
	socketManager.sendMessage(code.data());
	
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
				//TITLEPAGE:keyboard.onKeyPress(event.key.keysym.sym, status);
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
			//Test
			SDL_SetRenderDrawColor(gRenderer, 0x66, 0xCC, 0xFF, 0xFF);
			SDL_RenderFillRect(gRenderer, &SS.common_musicSwitchBtn);//ÿ��ҳ�涼���ڵ����ֿ���



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