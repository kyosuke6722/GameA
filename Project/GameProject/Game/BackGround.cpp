#include"BackGround.h"
BackGround::BackGround() :Base(eType_Field)
{
	m_img = COPY_RESOURCE("Background", CImage);







}
	void BackGround::Draw()
	{
		m_img.Draw();


	}
