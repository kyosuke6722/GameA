#pragma once
#include"../Base/Base.h"
class Game :public Base {
private:
	int m_cnt;
	int m_rand;
	bool m_flag;
public:
	Game();
	~Game();
	void Update();
};
