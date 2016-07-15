#pragma once
#include "GameObject.h"
#include "resource.h"
class CBall_litlle :public CGameObject
{
public:
	CBall_litlle(int x, int y, int nMontion);
	~CBall_litlle(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();


	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BALL1_HEIGHT, m_ptPos.y + BALL1_HEIGHT));
	}
private:
	static const int BALL1_HEIGHT = 15;
	static const int BALL1_WIDTH = 15;
	static CImageList m_Images;
	int    m_nMotion;
};
