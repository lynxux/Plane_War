#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss1 :public CGameObject
{
public:
	CBoss1();
	CBoss1(int x);
	~CBoss1(void);
	//static int PositionEnemy;
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + Boss1_WIDTH, m_ptPos.y + Boss1_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//获取血量
	int getblood() {
		return blood1;
	}
	//减少血量
	int setblood(int x) {
		blood1 += x;
		return blood1;
	}


	//是否可以开火发射子弹
	BOOL Fired();
	//看是否越界
	static int poi;
private:
	static const int Boss1_HEIGHT = 231;
	static const int Boss1_WIDTH = 400;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
					 //图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	int blood1;

};

