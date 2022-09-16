#include "Game.h"
#include"Player.h"
#include"Target.h"
#include"BackGround.h"
#include"UI.h"
#include"GameData.h"
#include"../Title/Title.h"

Game::Game():Base(eType_Scene) {
	m_cnt = 0;
	m_rand = rand();
	m_flag = false;
	Base::Add(new BackGround());
	//Base::Add(new Player(CVector2D(640, 360)));
	Base::Add(new Target(CVector2D(640, 64)));
	Base::Add(new UI());
}

Game::~Game(){
	Base::KillAll();//全オブジェクトを破棄
	//初期化
	GameData::s_score_old = GameData::s_score;
	GameData::s_score = 0;
	GameData::m_time = 360;
	//タイトルに戻る
	Base::Add(new Title());
}

void Game::Update() {
	GameData::m_time--;
	if (GameData::m_time < 0) {
		SetKill();
	}
	if (--m_cnt < 0&&!m_flag) {
		m_cnt = rand() %30 +60;//待機時間1～1.5秒
		m_rand = rand() % 8;
		m_flag = true;
	}
	if (m_flag) {
		switch (m_rand) {
		case 0:
			Base::Add(new Target(CVector2D(256 * m_rand + 128, 144 * 2+64)));
			break;
		case 1:
			Base::Add(new Target(CVector2D(256 * m_rand + 128, 144 * 1+64)));
			break;
		case 2:
			Base::Add(new Target(CVector2D(256 * m_rand+128, 144 * 0+64)));
			break;
		case 3:
			Base::Add(new Target(CVector2D(256 * m_rand + 128, 144 * 1+64)));
			break;
		case 4:
			Base::Add(new Target(CVector2D(256 * m_rand + 128, 144 * 2 + 64)));
			break;
		case 5:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4) + 128, 144 * 3 + 64)));
			break;
		case 6:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4) + 128, 144 * 4 + 64)));
			break;
		case 7:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4) + 128, 144 * 3+ 64)));
			break;
		}
		m_flag = false;
	}
}
