#include "UI.h"
#include"GameData.h"
UI::UI():Base(eType_UI) {
}

void UI::Draw(){
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++,score/=10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}
}
