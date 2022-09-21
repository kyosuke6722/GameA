#include "Player.h"
#include "Bullet.h"
#include "Game.h"

Player::Player(const CVector2D& pos)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(20, 20);
	m_cnt = 0;
}
void Player::Update()
{
	if (m_cnt > 0) {
		m_cnt--;
	}
	//マウスのベクトル
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//回転値を逆算
	m_ang = atan2(vec.x, vec.y);

	//弾の発射ボタン
	if (PUSH(CInput::eMouseL) && m_cnt > 0) {
		Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
		m_cnt += 60;
	}

}
void Player::Draw()
{
	//位置
	m_img.SetPos(m_pos);
	
	//サイズ
	m_img.SetSize(40, 40);
	
	//アングル
	m_img.SetAng(m_ang);

	m_img.Draw();
}
void Player::Collision(Base* b)
{
}