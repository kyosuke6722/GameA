#include "Target.h"

Target::Target(const CVector2D& pos):Base(eType_Enemy) {//Enemy�^�C�v(��ɕύX)
	m_img = COPY_RESOURCE("Target", CImage);
	m_pos = pos;
	m_img.SetRect(728, 213, 2781, 2267);
	m_img.SetSize(128, 128);
	m_img.SetCenter(64, 64);
	m_rad = 16;
}

void Target::Update(){
	m_cnt++;
	if (m_cnt >= 300) {
		SetKill();//5�b��Ɏ����I�ɏ���
	}
}

void Target::Draw(){
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Target::Collision(Base* b){
}
