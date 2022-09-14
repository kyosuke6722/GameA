#pragma once
#include"../Base/Base.h"

class Target :public Base {
private:
	CImage m_img;
	int m_cnt;
public:
	Target(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
