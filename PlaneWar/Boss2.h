#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss2 :public CGameObject
{
public:
	CBoss2();
	CBoss2(int x);
	~CBoss2(void);
	//static int PositionEnemy;
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + Boss2_WIDTH, m_ptPos.y + Boss2_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//��ȡѪ��
	int getblood() {
		return blood1;
	}
	//����Ѫ��
	int setblood(int x) {
		blood1 += x;
		return blood1;
	}


	//�Ƿ���Կ������ӵ�
	BOOL Fired();
	//���Ƿ�Խ��
	static int poi;
private:
	static const int Boss2_HEIGHT = 307;
	static const int Boss2_WIDTH = 384;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
					 //ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
	int blood1;

};

