#pragma once
#include"../Base/Base.h"
class Game :public Base {
private:
	int m_cnt;//Target�̏o���J�E���g
	int m_rand;//����
	bool m_flag;//Target�̏o���t���O
public:
	Game();
	~Game();
	void Update();
};
