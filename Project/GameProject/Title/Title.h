#pragma once
#include"../Base/Base.h"

class Title :public Base {
private:
	CImage m_img;
	CImage m_score_old;
	CFont m_title_text;
	CFont m_highscore;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};
