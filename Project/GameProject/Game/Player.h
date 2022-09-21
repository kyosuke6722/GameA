#pragma once
#include "../Base/Base.h"

class Player : public Base {
	CImage m_img;
	int m_cnt;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);

};