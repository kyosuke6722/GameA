#include "Game.h"
#include"Player.h"
#include"Target.h"
#include"BackGround.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new BackGround());
	//Base::Add(new Player(CVector2D(640, 360)));
	Base::Add(new Target(CVector2D(640, 120)));
}

Game::~Game(){
	Base::KillAll();//�S�I�u�W�F�N�g��j��
}

void Game::Update(){
}
