#include"Title.h"
#include"../Game/GameData.h"
#include "../Game/Game.h"


Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64),
m_highscore("C:\\Windows\\Fonts\\msgothic.ttc", 40)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_score_old = COPY_RESOURCE("UI", CImage);
	m_img.SetSize(1280, 720);
}

Title::~Title()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[����
	Base::Add(new Game());
}
void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	//�����\��
	m_title_text.Draw(64*7, 300, 0, 0, 0, "�I���ăQ�[��");
	m_title_text.Draw(64*8.5, 500, 0, 0, 0, "Push Z");
	m_highscore.Draw(64 * 15.5, 510, 0, 0, 0, "�n�C�X�R�A");
	int score = GameData::s_score_old;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_score_old.SetRect(16 * s, 32, 16 * s + 16, 48);
		m_score_old.SetSize(40, 40);
		m_score_old.SetPos(64*19 - 40 * i, 520);
		m_score_old.Draw();
	}
}


