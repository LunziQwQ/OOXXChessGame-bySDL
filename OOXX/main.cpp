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
#include "MAX.h"
#include "class_coor_3.h"
#include "class_MIDBOX.h"
#include "class_BigBox.h"
#include "class_coor_9.h"
#include "function.h"
#include "OOXX_SocketManager.h"
#include "OOXX-stage.h"

//��Ҫ�õ�ǰ�����ʵ����
StyleSheet SS;			//SDL����������ʽ����
Timer timer;			//SDL����������ʱ��֡������
BIGBOX bigbox(1);		//Logic��������������

//ҳ��ı�Ŷ���
const int TITLEPAGE = 0;
const int GAMEPAGE = 1;

//Network ��ʼ��
std::string host("119.29.177.191");
std::string service("4001");
SocketManager socketManager(host, service);
char buf[100];

//���������
int main(int argc, char* args[]) {

	//��������
	socketManager.link();
	printf("Network link success\n");
	
	//��֤SDL�Ƿ�ɹ�����
	if (!init(SS)){										
		printf("Failed to initialize!\n");
	}else {
		bool quit = false;		//�����˳�flag
		int status = 0;			//��ǰ��̨���

		//��Ҫ�ȴ�SDL��ʼ����ɺ�ʵ��������

		Resource resource;		//����������Դ				

		//��̨��ʼ��
		TitlePage titlePage(resource);
		GamePage gamePage(resource);


		//������Ⱦ��ѭ�������û��˳�ʱ����
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

				//�����¼�
				if (event.type == SDL_KEYDOWN) {
					switch (status){
					case TITLEPAGE:
						titlePage.onKeyPress(event.key.keysym.sym);
						break;
					}

				}
			}
			
			//����״̬�ı仯���ò�ͬ��̨�ķ���ʵ���л���̨
			switch (status) {
			case TITLEPAGE:	
				titlePage.load();
				break;
			case GAMEPAGE:
				gamePage.load();
				break;
			}

			//Test temp
			SDL_SetRenderDrawColor(gRenderer, 0x66, 0xCC, 0xFF, 0xFF);
			SDL_RenderFillRect(gRenderer, &SS.common_musicSwitchBtn);	//ÿ��ҳ�涼���ڵ����ֿ���

			//Network define API
			int count = socketManager.receive(buf, 100);
			if (count>0)
			{
				/*
					1.  ����ȥ��������Ϣ 
					2.  error:0
					3.  red
					4.  blue
				*/
				std::string resultString(buf);

			}


			SDL_RenderPresent(gRenderer);	//��Ⱦ��ǰ֡������
			SDL_RenderClear(gRenderer);		//�����һ֡������
			timer.fpsControl();				//֡������
		}
	}
	close();		//�رղ��ͷ�SDL���
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

//��ȾMIDBOX״̬
//bigbox.Box[][].get	 //0-2 0-2 