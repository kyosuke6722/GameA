#pragma once
#include"../Base/Base.h"
class Game :public Base {
private:
	int m_cnt;//Targetの出現カウント
	int m_rand;//乱数
	bool m_flag;//Targetの出現フラグ
public:
	Game();
	~Game();
	void Update();
};
