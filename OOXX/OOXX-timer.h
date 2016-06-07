class Timer{
public:
	void fpsControl();				//����֡��
	Uint32 fpsCount = 0;			//֡��������������ÿ��Ⱦһ֡�������

private:
	const Uint32 fps = 30;			//֡��������֡�����޸����������
	const Uint32 FPS = 1000 / fps;	//һ֡��������Tick
	Uint32 fpsTimer = 0;			//��һ֡��Tick
};

void Timer::fpsControl() {
	if (SDL_GetTicks() - fpsTimer < FPS) {
		SDL_Delay(FPS - SDL_GetTicks() + fpsTimer);
	}
	fpsTimer = SDL_GetTicks();
	fpsCount++;
	printf("FPS Count:%d\r", fpsCount);
}