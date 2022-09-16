#include "Bullet.h"
#include"GameData.h"
Bullet::Bullet(int type, const CVector2D& pos, float ang, float speed)
	:Base(type)
{
	if (type == eType_Player_Bullet)
		m_img = COPY_RESOURCE("Bullet", CImage);
	
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_ang = ang;
	m_speed = speed;

}

void Bullet::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;

	

	




}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}

void Bullet::Collision(Base* b)
{
	switch (b->m_type) {





		//Enemy��Target�ɕύX

	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();

			GameData::s_score += 100;
		}
		break;
	}
}




