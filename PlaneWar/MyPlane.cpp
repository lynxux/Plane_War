#include "stdafx.h"
#include "MyPlane.h"


CMyPlane::CMyPlane()
{
	m_nHorMotion=0;//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	m_nVerMotion=0;//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	m_nWait=0;//������ʱ
	m_ptPos.x = 500;
	m_ptPos.y = 500;
	blood = 400;
}


CMyPlane::~CMyPlane()
{

}

BOOL CMyPlane::Draw(CDC *pDC,BOOL bPause) {
	


    CMyPlane::m_ptPos.x += m_nHorMotion * 6;
	CMyPlane::m_ptPos.y += m_nVerMotion * 6;
	//CString s;
	//s.Format(_T("Ѫ��"));
	//s.Format(_T("�������꣨%d,%d��"), m_nHorMotion, m_nVerMotion);
	//pDC->SetBkMode(TRANSPARENT);
	//pDC->TextOutW(20, 1000, _T("Ѫ��"));

	return m_Images.Draw(pDC, 0, CMyPlane::m_ptPos, ILD_NORMAL);
}

BOOL CMyPlane::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_ME, RGB(255,255,255), PLANE_WIDTH, PLANE_HEIGHT, 1);
}

BOOL CMyPlane::Fired() {
	return true;
}


//��ʼ����̬��Ա
CImageList CMyPlane::m_Images;

