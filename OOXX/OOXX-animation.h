class Animation {
public:
	void scale(std::string path, SDL_Rect* rect, std::string mode, Uint32 startVal, Uint32 finalVal, int sustainFpsCount);
	void fade(std::string path, SDL_Rect* rect, std::string mode, Uint32 startVal, Uint32 finaVal, int sustainFpsCount);
	StyleSheet pullDown(SDL_Rect* rect, int FpsCount);

private:
	int FpsCount = 0;

};

void scale( std::string path,
			SDL_Rect* rect,
			std::string mode,
			Uint32 startVal,
			Uint32 finalVal,
			int sustainFpsCount) {
	
}

StyleSheet pullDown(SDL_Rect* rect, int sustainFpsCount) {
	StyleSheet SS;
	return SS;
}


/*
ͼƬ�л�����
���뵭��
��������
ƽ��

*/