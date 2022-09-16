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
	Base::KillAll();//�S�I�u�W�F�N�g��j��
}

void Game::Update(){
	if (--m_cnt < 0) {
		m_cnt = rand() % 120 + 180;//�ҋ@����3�`5�b
		m_rand = rand() % 10;
		m_flag = true;
	}
	if (m_flag) {
		switch (m_rand) {
		case 0:
			Base::Add(new Target(CVector2D(256*m_rand,144*(2-m_rand))));
			break;
		case 1:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * (2 - m_rand))));
			break;
		case 2:
			Base::Add(new Target(CVector2D(256 * m_rand, 144 * (2 - m_rand))));
			break;
		case 3:
			Base::Add(new Target(CVector2D(256 * m_rand, 120)));
			break;
		case 4:
			Base::Add(new Target(CVector2D(256*m_rand, 120)));
			break;
		case 5:
			Base::Add(new Target(CVector2D(256 * (m_rand-4), 120)));
			break;
		case 6:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 120)));
			break;
		case 7:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 120)));
			break;
		case 8:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 120)));
			break;
		case 9:
			Base::Add(new Target(CVector2D(256 * (m_rand - 4), 120)));
			break;
	}
}
