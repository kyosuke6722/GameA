#include "Target.h"

Target::Target(const CVector2D& pos):Base(eType_Enemy) {//Enemyタイプ(後に変更)
	m_img = COPY_RESOURCE("Target", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_rad = 16;
}

void Target::Update(){
	m_cnt++;
	if (m_cnt >= 480) {
		SetKill();//8秒後に自動的に消滅
	}
}

void Target::Draw(){
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Target::Collision(Base* b){
}
