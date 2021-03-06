#pragma once
#include "GameObject.h"
#include "resource.h"
class CEnemy :public CGameObject
{
public:
	CEnemy();
	CEnemy(int x);
	~CEnemy(void);
	//static int PositionEnemy;
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY_WIDTH, m_ptPos.y + ENEMY_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//获取血量
	int getblood() {
		return eblood;
	}
	//减少血量
	int setblood(int x) {
		eblood += x;
		return eblood;
	}

	//是否可以开火发射子弹
	BOOL Fired();
	//统计被打死的数目
	static int died_num;
private:
	static const int ENEMY_HEIGHT = 85;
	static const int ENEMY_WIDTH = 110;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	int eblood;
	
};
