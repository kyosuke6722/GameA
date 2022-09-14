#include "Bullet.h"

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

	CVector2D vec = CInput::GetMousePoint() - m_pos;
	m_ang = atan2(vec.x, vec.y);

	if (PUSH(CInput::eMouseL)) {
		Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
	}




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


		break;
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		//Enemy‚ğTarget‚É•ÏX
		break;
		case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;

}




