#include "UI.h"
#include"GameData.h"
UI::UI():Base(eType_UI) {
	m_img = COPY_RESOURCE("UI", CImage);
}

void UI::Draw() {
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(28, 28);
		m_img.SetPos(200 - 28 * i, 0);
		m_img.Draw();
	}
	int time = GameData::m_time;
	if (time < 60) {
		m_img.SetRect(16 * 1, 16, 16 * 1 + 16, 32);
		m_img.SetSize(56, 56);
		m_img.SetPos(1280 - 56, 0);
		m_img.Draw();
	}
	else if (time < 120) {
		m_img.SetRect(16 * 2, 16, 16 * 2 + 16, 32);
		m_img.SetSize(56, 56);
		m_img.SetPos(1280 - 56, 0);
		m_img.Draw();
	}
	else if (time < 180) {
		m_img.SetRect(16 * 3, 16, 16 * 3 + 16, 32);
		m_img.SetSize(56, 56);
		m_img.SetPos(1280 - 56, 0);
		m_img.Draw();
	}
}
