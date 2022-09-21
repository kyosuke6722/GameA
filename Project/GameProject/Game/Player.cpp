#include "Player.h"

Player::Player(const CVector2D& pos)
	:Base(eType_Player)
{
	//m_img.Load("Image/Player.png");
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(20, 20);

}
void Player::Update()
{
	//マウスのベクトル
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//回転値を逆算
	m_ang = atan2(vec.x, vec.y);

}
void Player::Draw()
{
	m_img.SetPos(600, 300);
	m_img.SetSize(40, 40);
	m_img.SetAng(m_ang);
	m_img.Draw();
}
void Player::Collision(Base* b)
{
}