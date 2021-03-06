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
#include "OOXX_SocketManager.h"
#include "OOXX-stage.h"

//需要用的前置类的实例化
StyleSheet SS;			//SDL————样式表类
Timer timer;			//SDL————计时（帧）器类
BIGBOX bigbox(1);		//Logic————大棋盘

bool isMulti = false;	//当前游戏是否为多人游戏
bool isFirst = false;	//本玩家是否为先手

//页面的编号定义
const int TITLEPAGE = 0;
const int GAMEPAGE = 1;

//Network 初始化
std::string host("119.29.177.191");
std::string service("4001");
SocketManager socketManager(host, service);
char buf[100];

//主函数入口
int main(int argc, char* args[]) {

	//网络连接
	socketManager.link();
	printf("Network link success\n");
	
	//验证SDL是否成功加载
	if (!init(SS)){										
		printf("Failed to initialize!\n");
	}else {
		bool quit = false;		//程序退出flag
		int status = 0;			//当前舞台编号

		//需要等待SDL初始化完成后实例化的类
		Resource resource;		//加载纹理资源				
		TitlePage titlePage(resource);
		GamePage gamePage(resource);


		//程序渲染主循环，当用户退出时结束
		while (!quit){		

			//事件处理循环
			while (SDL_PollEvent(&event) != 0){

				//退出事件：触发时跳出主循环
				if (event.type == SDL_QUIT){
					quit = true; 
				}

				//鼠标事件
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					int x, y;
					SDL_GetMouseState(&x, &y);			//获取鼠标点击坐标

					switch (status){
					case TITLEPAGE: status = titlePage.onClick(x, y);
						break;
					case GAMEPAGE: status = gamePage.onClick(x, y);
						break;
					}
				}

				//按键事件
				if (event.type == SDL_KEYDOWN) {
					switch (status){
					case TITLEPAGE:
						titlePage.onKeyPress(event.key.keysym.sym);
						break;
					}

				}
			}
			
			//根据状态的变化调用不同舞台的方法实现切换舞台
			switch (status) {
			case TITLEPAGE:	
				titlePage.load();
				break;
			case GAMEPAGE:
				gamePage.load();
				//单机模式下，或为自己的回合时开启提示
				if (!isMulti 
					|| (isMulti && bigbox.get_currentPlayer()==1 && isFirst)
					|| (isMulti && bigbox.get_currentPlayer() != 1 && !isFirst)) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					gamePage.onHover(x, y);
				}
				break;
			}

			//Network define API
			int count = socketManager.receive(buf, 100);
			if (count>0)
			{
				std::string resultString(buf);
				if (resultString.find("red") != string::npos) {
					isFirst = true;
				} else if (resultString.find("blue") != string::npos) {
					isFirst = false;
				} else if (resultString.find("error") != string::npos) {

				} else {
					//接受远程玩家的坐标
					gamePage.getMultiStep(resultString);
				}
			}

			SDL_RenderPresent(gRenderer);	//渲染当前帧的纹理
			SDL_RenderClear(gRenderer);		//清除上一帧的纹理
			timer.fpsControl();				//帧数控制
		}
	}
	close();		//关闭并释放SDL相关
	return 0;
}




//渲染MIDBOX状态
//bigbox.Box[][].get	 //0-2 0-2 