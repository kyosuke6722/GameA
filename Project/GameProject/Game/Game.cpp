#include "Game.h"
#include"Player.h"
#include"Target.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Target(CVector2D(640, 180)));
}

Game::~Game(){
	Base::KillAll();//�S�I�u�W�F�N�g��j��
}

void Game::Update(){
}
