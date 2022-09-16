#include"BackGround.h"
BackGround::BackGround() :Base(eType_Field)
{
	m_img = COPY_RESOURCE("BackGround", CImage);
	m_img.SetSize(1280, 720);






}
	void BackGround::Draw()
	{
		m_img.Draw();


	}
