#include "Game.h"
#include"Player.h"
#include"Target.h"
#include"BackGround.h"

Game::Game():Base(eType_Scene) {
	m_cnt = 0;
	m_rand = rand();
	m_flag = false;
	Base::Add(new BackGround());
	//Base::Add(new Player(CVector2D(640, 360)));
	Base::Add(new Target(CVector2D(640, 120)));
}

Game::~Game(){
	Base::KillAll();//全オブジェクトを破棄
}

void Game::Update() {
	if (--m_cnt < 0&&!m_flag) {
		m_cnt = rand() % 120 +60;//待機時間1〜3秒
		m_rand = rand() % 8;
		m_flag = true;
	}
	if (m_flag) {
		switch (m_rand) {
		case 0:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * 2+64)));
			break;
		case 1:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * 1+64)));
			break;
		case 2:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * 0+64)));
			break;
		case 3:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * 1+64)));
			break;
		case 4:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * 2 + 64)));
			break;
		case 5:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 144 * 3 + 64)));
			break;
		case 6:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 144 * 4 + 64)));
			break;
		case 7:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 144 * 3+ 64)));
			break;
		}
		m_flag = false;
	}
}
