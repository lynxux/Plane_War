// PlaneWarView.cpp : CPlaneWarView ���ʵ��
//
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PlaneWar.h"
#endif
//#include <Winuser.h>
#include <afxwin.h>
#include "resource.h"
#include "PlaneWarDoc.h"
#include "PlaneWarView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPlaneWarView

IMPLEMENT_DYNCREATE(CPlaneWarView, CView)

BEGIN_MESSAGE_MAP(CPlaneWarView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//	ON_WM_ERASEBKGND()
	//	ON_WM_PAINT()
	//ON_WM_ERASEBKGND()
	//ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CPlaneWarView ����/����

CPlaneWarView::CPlaneWarView()
{
	// TODO: �ڴ˴���ӹ������
	//SetTimer(0, 1000, NULL);
	i = 0;
	j = 400;
	k = 400;
	nodied = 0;
	accupt = 0;
}

CPlaneWarView::~CPlaneWarView()
{


}

BOOL CPlaneWarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlaneWarView ����

void CPlaneWarView::OnDraw(CDC* pDC)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CPlaneWarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPlaneWarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPlaneWarView ���

#ifdef _DEBUG
void CPlaneWarView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarDoc* CPlaneWarView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarDoc)));
	return (CPlaneWarDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarView ��Ϣ�������


void CPlaneWarView::OnTimer(UINT_PTR nIDEvent)
{

	CView::OnTimer(nIDEvent);
	//TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CDC cdc;//�ڴ滺��CDC
	CBitmap *cacheBitmap = new CBitmap;//�ڴ��г��ص���ʱͼ�񻺳�λͼ
	cdc.CreateCompatibleDC(pDC);//�õ�ǰ�豸CDC��ʼ������CDC  
	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//��pDC��λ����ͼ�Ĺ�ϵ��cdc�������λ����ͼ�У�������֮����һ���Խ�����λͼ�������Ļ
	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	//�滻cdcԭ���Ļ�����Ϊ����λͼ������cdc��������ݾ�д���˻���λͼ��
	CDC cdc1;
	cdc1.CreateCompatibleDC(pDC);

	//if (CEnemy::died_num)
	//��������
	CBitmap back;
	back.LoadBitmapW(IDB_background);
	CBitmap *old = cdc1.SelectObject(&back);
	bgsp += 10;
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &cdc1, 0, 0, 1024, 768, SRCCOPY);




	/*CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(rect);
	CBitmap cacheBitmap;
	cacheBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height()); CDC cdc; cdc.CreateCompatibleDC(pDC);
	cdc.SelectObject(&cacheBitmap);
	{
	CBitmap back;
	back.LoadBitmapW(IDB_background);
	BITMAP bm;
	back.GetBitmap(&bm);
	CDC cdc1;
	cdc1.CreateCompatibleDC(&cdc);
	cdc1.SelectObject(&back);
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &cdc1, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	}*/


	//���̿���
	if (myplane != NULL) {
		short key;
		key = GetKeyState(87);
		if ((key & 0x80) != 0) {
			myplane->SetVerMotion(-1);
		}
		key = GetKeyState(83);
		if ((key & 0x80) != 0) {
			myplane->SetVerMotion(1);
		}
		key = GetKeyState(65);
		if ((key & 0x80) != 0) {
			myplane->SetHorMotion(-1);
		}
		key = GetKeyState(68);
		if ((key & 0x80) != 0) {
			myplane->SetHorMotion(1);
		}
	}

	//�����ҷ�ս��
	if (myplane != NULL)
		myplane->Draw(&cdc, false);

	//��Ϸ����
	else if (myplane == NULL) {
		CFont font;
		font.CreateFont(100, 100, 0, 0, 700, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, _T("Courier New"));
		cdc.SelectObject(&font);
		cdc.SetTextColor(RGB(255,9,0));
		cdc.SetBkMode(TRANSPARENT);
		cdc.TextOutW(700, 200, _T("K.O.��"));
		cdc.TextOutW(500, 350, _T("YOU DIED��"));
	}
	//��Ϸ������ʾ
	if (myplane != NULL) {
		CFont font;
		font.CreateFont(15, 15, 0, 0, 700, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, _T("Courier New"));
		cdc.SelectObject(&font);
		cdc.SetTextColor(RGB(255, 255, 0));
		cdc.SetBkMode(TRANSPARENT);
		//cdc.TextOutW(10, 30, _T("��ǰ���֣�"));
		CString s;
		s.Format(_T("��ǰ����: %d"),accupt);
		cdc.TextOutW(10, 50, s);

	}
	else if (myplane == NULL) {
		CFont font;
		font.CreateFont(50, 50, 0, 0, 700, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, _T("Courier New"));
		cdc.SelectObject(&font);
		cdc.SetTextColor(RGB(255, 5, 0));
		cdc.SetBkMode(TRANSPARENT);
		CString s;
		s.Format(_T("YOU GOT: %d Points"), accupt);
		cdc.TextOutW(450, 500, s);
	}


	//�����ҵ��ӵ�J
	if (myplane != NULL) {
		POSITION bpos = BombList.GetHeadPosition();
		POSITION bpos2;
		while (bpos != NULL) {
			bpos2 = bpos;
			CBomb *_bomb = (CBomb *)BombList.GetNext(bpos);
			if (_bomb->GetPoint().y < -10) {
				BombList.RemoveAt(bpos2);
				delete(_bomb);
			}
			else {
				_bomb->Draw(&cdc, false);
			}
		}
	}

	//�����ҵ��ӵ�K
	if (myplane != NULL) {
		POSITION b1pos = Bomb1List.GetHeadPosition();
		POSITION b1pos2;
		while (b1pos != NULL) {
			b1pos2 = b1pos;
			CBullet1 *_1bomb = (CBullet1 *)Bomb1List.GetNext(b1pos);
			if (_1bomb->GetPoint().y < -10) {
				Bomb1List.RemoveAt(b1pos2);
				delete(_1bomb);
			}
			else {
				_1bomb->Draw(&cdc, false);
			}
		}
	}

	//���Ƶл�
	//boss1���֣���ͨ�л���������
	if (myplane != NULL) {
		if (nIDEvent == 4 && CEnemy::died_num < 40) {
			EnemyList.AddTail(new CEnemy(0));
		}
		else if (nIDEvent == 5) {
			EnemyList.AddTail(new CEnemy(0));
		}
		POSITION pos = EnemyList.GetHeadPosition();
		POSITION pos2;
		while (pos != NULL) {
			pos2 = pos;
			CEnemy *_enemy = (CEnemy *)EnemyList.GetNext(pos);
			if (_enemy->GetPoint().y > rect.bottom || _enemy->GetPoint().x<rect.left || _enemy->GetPoint().x + 110 > rect.right) {
				EnemyList.RemoveAt(pos2);
				delete(_enemy);
			}
			else {
				_enemy->Draw(&cdc, false);
				//�л��ӵ�����
				if (myplane != NULL) {
					if (nIDEvent == 3 && (_enemy->GetPoint().x - myplane->GetPoint().x < 600) && (_enemy->GetPoint().x - myplane->GetPoint().x > -600))
						BallList.AddTail(new CBall(_enemy->GetPoint().x + 40, _enemy->GetPoint().y + 85, 0));
				}
			}
		}
	}

	//����С�л�
	if (myplane != NULL) {
		if (nIDEvent == 5 && CEnemy::died_num < 40) {
			Enemy_little_List.AddTail(new CEnemy_little);
			Enemy_little_List.AddTail(new CEnemy_little);
		}
		else if (nIDEvent == 6 && CEnemy::died_num < 40) {
			Enemy_little_List.AddTail(new CEnemy_little);
		}
		//boss���֣�С�л���������
		else if (nIDEvent == 3 && CEnemy::died_num > 40) {
			Enemy_little_List.AddTail(new CEnemy_little);
			Enemy_little_List.AddTail(new CEnemy_little);
		}

		POSITION elpos = Enemy_little_List.GetHeadPosition();
		POSITION elpos2;
		while (elpos != NULL) {
			elpos2 = elpos;
			CEnemy_little *_enemy_l = (CEnemy_little *)Enemy_little_List.GetNext(elpos);
			if (_enemy_l->GetPoint().y > rect.bottom || _enemy_l->GetPoint().x<rect.left || _enemy_l->GetPoint().x + 110 > rect.right) {
				Enemy_little_List.RemoveAt(elpos2);
				delete(_enemy_l);
			}
			else {
				_enemy_l->Draw(&cdc, false);
				//�л��ӵ�����
				if (myplane != NULL) {
					if (nIDEvent == 7 && (_enemy_l->GetPoint().x - myplane->GetPoint().x < 600) && (_enemy_l->GetPoint().x - myplane->GetPoint().x > -600))
						Enemy_ball_little.AddTail(new CBall_litlle(_enemy_l->GetPoint().x + 20, _enemy_l->GetPoint().y + 20, 0));
				}
			}
		}
	}

	//����boss1
	if (boss1 != NULL) {
		if (CEnemy::died_num > 40) {
			boss1->Draw(&cdc, false);
			if (nIDEvent == 7) {
				BossBullet1List.AddTail(new CBoss1Bullet1(boss1->GetPoint().x + 200, boss1->GetPoint().y + 231, 2));
				BossBullet1List.AddTail(new CBoss1Bullet1(boss1->GetPoint().x + 133, boss1->GetPoint().y + 111, 1));
				BossBullet1List.AddTail(new CBoss1Bullet1(boss1->GetPoint().x + 266, boss1->GetPoint().y + 111, -1));
			}
			else if (nIDEvent == 8) {
				BossBullet2List.AddTail(new CBoss1Bullet2(boss1->GetPoint().x + 200, boss1->GetPoint().y + 231));
			}
		}
		if (boss1->GetPoint().x + 400 > rect.Width())
			CBoss1::poi = 1;
		else if (boss1->GetPoint().x < 0)
			CBoss1::poi = 0;
	}

	//����boss1���ӵ�1
	if (boss1 != NULL) {
		POSITION BossBullet1pos = BossBullet1List.GetHeadPosition();
		POSITION BossBullet1pos2;
		while (BossBullet1pos != NULL) {
			BossBullet1pos2 = BossBullet1pos;
			CBoss1Bullet1 *_BossBullet1 = (CBoss1Bullet1 *)BossBullet1List.GetNext(BossBullet1pos);
			if (_BossBullet1->GetPoint().y > rect.Height()) {
				BossBullet1List.RemoveAt(BossBullet1pos2);
				delete(_BossBullet1);
			}
			else
				_BossBullet1->Draw(&cdc, false);
		}

	}

	//����boss1���ӵ�2
	if (boss1 != NULL) {
		POSITION BossBullet2pos = BossBullet2List.GetHeadPosition();
		POSITION BossBullet2pos2;
		while (BossBullet2pos != NULL) {
			BossBullet2pos2 = BossBullet2pos;
			CBoss1Bullet2 *_BossBullet2 = (CBoss1Bullet2 *)BossBullet2List.GetNext(BossBullet2pos);
			if (_BossBullet2->GetPoint().y > rect.Height()) {
				BossBullet2List.RemoveAt(BossBullet2pos2);
				delete(_BossBullet2);
			}
			else
				_BossBullet2->Draw(&cdc, false);
		}

	}


	//���Ƶл��ӵ�
	POSITION Ebulletpos = BallList.GetHeadPosition();
	POSITION Ebulletpos2;
	while (Ebulletpos != NULL) {
		Ebulletpos2 = Ebulletpos;
		CBall *_ball = (CBall *)BallList.GetNext(Ebulletpos);
		if (_ball->GetPoint().y > rect.Height()) {
			BallList.RemoveAt(Ebulletpos2);
			delete(_ball);
		}
		else
			_ball->Draw(&cdc, false);
	}

	//����С�л��ӵ�
	POSITION Elbulletpos = Enemy_ball_little.GetHeadPosition();
	POSITION Elbulletpos2;
	while (Elbulletpos != NULL) {
		Elbulletpos2 = Elbulletpos;
		CBall_litlle *_lball = (CBall_litlle *)Enemy_ball_little.GetNext(Elbulletpos);
		if (_lball->GetPoint().y > rect.Height()) {
			Enemy_ball_little.RemoveAt(Elbulletpos2);
			delete(_lball);
		}
		else
			_lball->Draw(&cdc, false);
	}


	//�ҵ��ӵ�J����ͨ�л�
	if (myplane != NULL) {
		POSITION mybpos = BombList.GetHeadPosition();
		POSITION mybpos2;
		while (mybpos != NULL) {
			mybpos2 = mybpos;
			CBomb *_mybpos = (CBomb *)BombList.GetNext(mybpos);
			POSITION e_pos = EnemyList.GetHeadPosition();
			POSITION e_pos2;
			while (e_pos != NULL) {
				e_pos2 = e_pos;
				CEnemy *_e_pos = (CEnemy *)EnemyList.GetNext(e_pos);
				CRect explo;
				if (explo.IntersectRect(_mybpos->GetRect(), _e_pos->GetRect()) != 0) {
					//���ּ���
					accupt += 50;
					//ͳ�ƴ򵽵���ͨ�ɻ���Ŀ
					CEnemy::died_num++;
					//��ըЧ��
					ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 30, _e_pos->GetPoint().y + 30));
					ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 45, _e_pos->GetPoint().y + 10));
					ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 15, _e_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 5, _e_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 5, _e_pos->GetPoint().y + 30));
					BombList.RemoveAt(mybpos2);
					delete(_mybpos);
					//_mybpos = NULL;
					EnemyList.RemoveAt(e_pos2);
					delete(_e_pos);
					break;
				}
			}
		}
	}

	//�ҵ��ӵ�K����ͨ�л�
	if (myplane != NULL) {
		POSITION myb1pos = Bomb1List.GetHeadPosition();
		POSITION myb1pos2;
		while (myb1pos != NULL) {
			myb1pos2 = myb1pos;
			CBullet1 *_myb1pos = (CBullet1 *)Bomb1List.GetNext(myb1pos);
			POSITION ee_pos = EnemyList.GetHeadPosition();
			POSITION ee_pos2;
			while (ee_pos != NULL) {
				ee_pos2 = ee_pos;
				CEnemy *_ee_pos = (CEnemy *)EnemyList.GetNext(ee_pos);
				CRect explo;
				if (explo.IntersectRect(_myb1pos->GetRect(), _ee_pos->GetRect()) != 0) {
					//���ּ���
					_ee_pos->setblood(-5);
					//��ըЧ��
					ExploList.AddTail(new CExplosion(_ee_pos->GetPoint().x + 30, _ee_pos->GetPoint().y + 30));
					ExploList.AddTail(new CExplosion(_ee_pos->GetPoint().x + 45, _ee_pos->GetPoint().y + 10));
					ExploList.AddTail(new CExplosion(_ee_pos->GetPoint().x + 15, _ee_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_ee_pos->GetPoint().x + 5, _ee_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_ee_pos->GetPoint().x + 5, _ee_pos->GetPoint().y + 30));
					Bomb1List.RemoveAt(myb1pos2);
					delete(_myb1pos);
					//EnemyList.RemoveAt(ee_pos2);
					if (_ee_pos->getblood() <= 0) {
						EnemyList.RemoveAt(ee_pos2);
						delete(_ee_pos);
						//ͳ�ƴ򵽵���ͨ�ɻ���Ŀ
						CEnemy::died_num++;
						accupt += 20;
					}
					break;
				}
			}
		}
	}


	//�ҵ��ӵ�J��С�л�
	if (myplane != NULL) {
		POSITION mybpos = BombList.GetHeadPosition();
		POSITION mybpos2;
		while (mybpos != NULL) {
			mybpos2 = mybpos;
			CBomb *_mybpos = (CBomb *)BombList.GetNext(mybpos);
			POSITION e_l_pos = Enemy_little_List.GetHeadPosition();
			POSITION e_l_pos2;
			while (e_l_pos != NULL) {
				e_l_pos2 = e_l_pos;
				CEnemy_little *_e_l_pos = (CEnemy_little *)Enemy_little_List.GetNext(e_l_pos);
				CRect explo;
				if (explo.IntersectRect(_mybpos->GetRect(), _e_l_pos->GetRect()) != 0) {
					//���ּ���
					accupt += 50;
					//��ըЧ��
					ExploList.AddTail(new CExplosion(_e_l_pos->GetPoint().x + 30, _e_l_pos->GetPoint().y + 30));
					ExploList.AddTail(new CExplosion(_e_l_pos->GetPoint().x + 45, _e_l_pos->GetPoint().y + 10));
					ExploList.AddTail(new CExplosion(_e_l_pos->GetPoint().x + 15, _e_l_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_e_l_pos->GetPoint().x + 5, _e_l_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_e_l_pos->GetPoint().x + 5, _e_l_pos->GetPoint().y + 30));
					BombList.RemoveAt(mybpos2);
					delete(_mybpos);
					Enemy_little_List.RemoveAt(e_l_pos2);
					delete(_e_l_pos);
					break;
				}
			}

		}
	}

	//�ҵ��ӵ�K��С�л�
	if (myplane != NULL) {
		POSITION myb11pos = Bomb1List.GetHeadPosition();
		POSITION myb11pos2;
		while (myb11pos != NULL) {
			myb11pos2 = myb11pos;
			CBullet1 *_mybkpos = (CBullet1 *)Bomb1List.GetNext(myb11pos);
			POSITION ee_l_pos = Enemy_little_List.GetHeadPosition();
			POSITION ee_l_pos2;
			while (ee_l_pos != NULL) {
				ee_l_pos2 = ee_l_pos;
				CEnemy_little *_ee_l_pos = (CEnemy_little *)Enemy_little_List.GetNext(ee_l_pos);
				CRect explo;
				if (explo.IntersectRect(_mybkpos->GetRect(), _ee_l_pos->GetRect()) != 0) {
					//���ּ���
					accupt += 50;
					//��ըЧ��
					ExploList.AddTail(new CExplosion(_ee_l_pos->GetPoint().x + 30, _ee_l_pos->GetPoint().y + 30));
					ExploList.AddTail(new CExplosion(_ee_l_pos->GetPoint().x + 45, _ee_l_pos->GetPoint().y + 10));
					ExploList.AddTail(new CExplosion(_ee_l_pos->GetPoint().x + 15, _ee_l_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_ee_l_pos->GetPoint().x + 5, _ee_l_pos->GetPoint().y + 50));
					ExploList.AddTail(new CExplosion(_ee_l_pos->GetPoint().x + 5, _ee_l_pos->GetPoint().y + 30));
					Bomb1List.RemoveAt(myb11pos2);
					delete(_mybkpos);
					Enemy_little_List.RemoveAt(ee_l_pos2);
					delete(_ee_l_pos);
					break;
				}
			}

		}
	}

	//�ҵ��ӵ�J��boss
	if (myplane != NULL&&boss1 != NULL&&CEnemy::died_num>40) {
		POSITION myb1pos = BombList.GetHeadPosition();
		POSITION myb1pos2;
		while (myb1pos != NULL) {
			myb1pos2 = myb1pos;
			CBomb *_myb1pos = (CBomb *)BombList.GetNext(myb1pos);
			CRect explo11;
			if (explo11.IntersectRect(_myb1pos->GetRect(), boss1->GetRect()) != 0) {
				//���ּ���
				accupt += 10;
				boss1->setblood(-10);
				//��ըЧ��
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 200, boss1->GetPoint().y + 70));
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 170, boss1->GetPoint().y + 100));
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 140, boss1->GetPoint().y + 70));
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 140, boss1->GetPoint().y + 120));
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 200, boss1->GetPoint().y + 120));
				ExploList.AddTail(new CExplosion(boss1->GetPoint().x + 120, boss1->GetPoint().y + 70));
				ExploList.AddTail(new CExplosion(boss1->GetPoint().x + 200, boss1->GetPoint().y + 70));
				BombList.RemoveAt(myb1pos2);
				delete(_myb1pos);
				if (boss1->getblood() < 0) {
					boss1 = NULL;
					//���ּ���
					accupt += 500;

				}
				break;

			}
		}
	}

	//�ҵ��ӵ�K��boss
	if (myplane != NULL&&boss1 != NULL&&CEnemy::died_num>40) {
		POSITION mybkkpos = Bomb1List.GetHeadPosition();
		POSITION mybkkpos2;
		while (mybkkpos != NULL) {
			mybkkpos2 = mybkkpos;
			CBullet1 *_myb1kpos = (CBullet1 *)Bomb1List.GetNext(mybkkpos);
			CRect explo11k;
			if (explo11k.IntersectRect(_myb1kpos->GetRect(), boss1->GetRect()) != 0) {
				//���ּ���
				accupt += 5;
				boss1->setblood(-3);
				//��ըЧ��
				Expl_bigList.AddTail(new CExpl_big(boss1->GetPoint().x + 150, boss1->GetPoint().y + 100));
				ExploList.AddTail(new CExplosion(boss1->GetPoint().x + 120, boss1->GetPoint().y + 120));
				ExploList.AddTail(new CExplosion(boss1->GetPoint().x + 200, boss1->GetPoint().y + 120));
				Bomb1List.RemoveAt(mybkkpos2);
				delete(_myb1kpos);
				if (boss1->getblood() < 0) {
					boss1 = NULL;
					//���ּ���
					accupt += 50;
				}
				break;

			}
		}
	}



	//��ͨ�л��ӵ�����
	if (myplane != NULL) {
		POSITION ebpos = BallList.GetHeadPosition();
		POSITION ebpos2;
		while (ebpos != NULL) {
			ebpos2 = ebpos;
			CBall *_ebpos = (CBall *)BallList.GetNext(ebpos);
			CRect exp;
			if (exp.IntersectRect(_ebpos->GetRect(), myplane->GetRect()) != 0 && nodied ==0 ) {
				myplane->setblood(-100);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				BallList.RemoveAt(ebpos2);
				delete(_ebpos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}

	//С�л��ӵ�����
	if (myplane != NULL) {
		POSITION elbpos = Enemy_ball_little.GetHeadPosition();
		POSITION elbpos2;
		while (elbpos != NULL) {
			elbpos2 = elbpos;
			CBall_litlle *_elbpos = (CBall_litlle *)Enemy_ball_little.GetNext(elbpos);
			CRect exp1;
			if (exp1.IntersectRect(_elbpos->GetRect(), myplane->GetRect()) != 0 && nodied == 0) {
				myplane->setblood(-50);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				Enemy_ball_little.RemoveAt(elbpos2);
				delete(_elbpos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}

	//boss���ӵ�1����
	if (myplane != NULL&&boss1 != NULL&&CEnemy::died_num>40) {
		POSITION bb1pos = BossBullet1List.GetHeadPosition();
		POSITION bb1pos2;
		while (bb1pos != NULL) {
			bb1pos2 = bb1pos;
			CBoss1Bullet1 *_bbpos = (CBoss1Bullet1 *)BossBullet1List.GetNext(bb1pos);
			CRect exp111;
			if (exp111.IntersectRect(_bbpos->GetRect(), myplane->GetRect()) != 0 && nodied == 0) {
				myplane->setblood(-50);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				BossBullet1List.RemoveAt(bb1pos2);
				delete(_bbpos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}

	//boss�ӵ�2����
	if (myplane != NULL&&boss1 != NULL&&CEnemy::died_num>40) {
		POSITION bb2pos = BossBullet2List.GetHeadPosition();
		POSITION bb2pos2;
		while (bb2pos != NULL) {
			bb2pos2 = bb2pos;
			CBoss1Bullet2 *_bb2pos = (CBoss1Bullet2 *)BossBullet2List.GetNext(bb2pos);
			CRect exp1111;
			if (exp1111.IntersectRect(_bb2pos->GetRect(), myplane->GetRect()) != 0 && nodied == 0) {
				myplane->setblood(-150);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				BossBullet2List.RemoveAt(bb2pos2);
				delete(_bb2pos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}



	//��ͨ�л�������ײ
	if (myplane != NULL) {
		POSITION epos = EnemyList.GetHeadPosition();
		POSITION epos2;
		while (epos != NULL) {
			epos2 = epos;
			CEnemy *_epos = (CEnemy *)EnemyList.GetNext(epos);
			CRect ex;
			if (ex.IntersectRect(_epos->GetRect(), myplane->GetRect()) != 0 && nodied == 0) {
				myplane->setblood(-200);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				EnemyList.RemoveAt(epos2);
				delete(_epos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}


	//С�л�������ײ
	if (myplane != NULL) {
		POSITION elpos = Enemy_little_List.GetHeadPosition();
		POSITION elpos2;
		while (elpos != NULL) {
			elpos2 = elpos;
			CEnemy_little *_elpos = (CEnemy_little *)Enemy_little_List.GetNext(elpos);
			CRect ex2;
			if (ex2.IntersectRect(_elpos->GetRect(), myplane->GetRect()) != 0 && nodied == 0) {
				myplane->setblood(-100);
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
				ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
				Enemy_little_List.RemoveAt(elpos2);
				delete(_elpos);
				if (myplane->getblood() < 0) {
					myplane = NULL;
				}
				break;
			}
		}
	}

	//boss������ײ
	if (myplane != NULL&&boss1 != NULL&&CEnemy::died_num>40 && nodied == 0) {
		CRect exx;
		if (exx.IntersectRect(myplane->GetRect(), boss1->GetRect()) != 0) {
			ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 15, myplane->GetPoint().y + 30));
			ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 60, myplane->GetPoint().y + 30));
			ExploList.AddHead(new CExplosion(myplane->GetPoint().x + 45, myplane->GetPoint().y + 60));
			myplane = NULL;
		}
	}


	//С�л��ӵ�����ͨ�л��ӵ���ըЧ��
	POSITION Explopos = ExploList.GetHeadPosition();
	POSITION Explopos2;
	while (Explopos != NULL) {
		Explopos2 = Explopos;
		CExplosion *_explo = (CExplosion *)ExploList.GetNext(Explopos);
		if (_explo->GetPoint().y < -10) {
			ExploList.RemoveAt(Explopos2);
			delete(_explo);
		}
		else
			_explo->Draw(&cdc, false);
	}

	//boss�Ĵ�ըЧ��
	POSITION Explo_big_pos = Expl_bigList.GetHeadPosition();
	POSITION Explo_big_pos2;
	while (Explo_big_pos != NULL) {
		Explo_big_pos2 = Explo_big_pos;
		CExplosion *_explob = (CExplosion *)Expl_bigList.GetNext(Explo_big_pos);
		if (_explob->GetPoint().y < -10) {
			Expl_bigList.RemoveAt(Explo_big_pos2);
			delete(_explob);
		}
		else
			//if(nIDEvent == 9)
			_explob->Draw(&cdc, false);
	}


	//�ҷ�ս��Ѫ����ʾ
	if (myplane != NULL) {
		CFont font;
		font.CreateFont(20, 20, 0, 0, 1500, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, _T("΢���ź�"));
		cdc.SelectObject(&font);
		cdc.SetTextColor(RGB(255, 255, 0));
		cdc.SetBkMode(TRANSPARENT);
		cdc.TextOutW(10, 920, _T("Ѫ��:"));
		int num = myplane->getblood();
		if (num == 400)
			cdc.TextOutW(10, 945, _T("||||||||||||||||"));
		if (num >= 350 && num <400)
			cdc.TextOutW(10, 945, _T("||||||||||||||"));
		if (num >= 300 && num <350)
			cdc.TextOutW(10, 945, _T("||||||||||||"));
		if (num >= 250 && num <300)
			cdc.TextOutW(10, 945, _T("||||||||||"));
		if (num >= 200 && num <250)
			cdc.TextOutW(10, 945, _T("||||||||"));
		if (num >= 150 && num <200)
			cdc.TextOutW(10, 945, _T("||||||"));
		if (num >= 100 && num <150)
			cdc.TextOutW(10, 945, _T("||||"));
		if (num >= 50 && num <100)
			cdc.TextOutW(10, 945, _T("||"));
		if (num < 50)
			cdc.TextOutW(10, 945, _T("|"));
	}
	//bossѪ����ʾ
	if (boss1 != NULL&&CEnemy::died_num>40) {
		CFont font;
		font.CreateFont(20, 20, 0, 0, 1500, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, _T("΢���ź�"));
		cdc.SelectObject(&font);
		cdc.SetTextColor(RGB(255, 255, 0));
		cdc.SetBkMode(TRANSPARENT);
		cdc.TextOutW(10, 10, _T("Ѫ��:"));
		int num = boss1->getblood();
		if (num == 1000)
			cdc.TextOutW(10, 25, _T("|||||||||||||||||||||||||||||||"));
		if (num >= 900 && num < 1000)
			cdc.TextOutW(10, 25, _T("||||||||||||||||||||||||||||"));
		if (num >= 800 && num < 900)
			cdc.TextOutW(10, 25, _T("||||||||||||||||||||||||"));
		if (num >= 700 && num < 800)
			cdc.TextOutW(10, 25, _T("|||||||||||||||||||||"));
		if (num >= 600 && num < 700)
			cdc.TextOutW(10, 25, _T("||||||||||||||||||"));
		if (num >= 500 && num < 600)
			cdc.TextOutW(10, 25, _T("|||||||||||||||"));
		if (num >= 400 && num < 500)
			cdc.TextOutW(10, 25, _T("||||||||||||"));
		if (num >= 300 && num < 400)
			cdc.TextOutW(10, 25, _T("|||||||||"));
		if (num >= 200 && num < 300)
			cdc.TextOutW(10, 25, _T("||||||"));
		if (num >= 100 && num < 200)
			cdc.TextOutW(10, 25, _T("|||"));
		if (num <= 50)
			cdc.TextOutW(10, 25, _T("|"));

	}


	//����������cdc�е��������͵�һ��������pDC�У����������Ļ��
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//�ͷŶ���cdc
	cdc.DeleteDC();
	//�ͷŻ���λͼ
	cacheBitmap->DeleteObject();
	//�ͷ�һ��pDC
	ReleaseDC(pDC);


	/*pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	ReleaseDC(pDC);*/


}


int CPlaneWarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������


	//��Ӷ�ʱ������������������������������������������������������������������������������������������������
	SetTimer(1, 1, NULL);
	SetTimer(2, 120, NULL);
	SetTimer(3, 1250, NULL);   //�л��ӵ���ʱ��
	SetTimer(4, 1000, NULL);   //�л����ֶ�ʱ����
	SetTimer(5, 4000, NULL);     //�л����ֶ�ʱ����
	SetTimer(6, 700, NULL);     //С�л����ֶ�ʱ��
	SetTimer(7, 900, NULL);    //С�л��ӵ���ʱ��
	SetTimer(8, 5000, NULL);   //BOSS�ӵ�2��ʱ��
	//SetTimer(9, 100, NULL);      //��ըЧ����ʱ��

	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
	CEnemy_little::LoadImage();
	CBall_litlle::LoadImage();
	CBoss1::LoadImage();
	CBoss1Bullet1::LoadImage();
	CBoss1Bullet2::LoadImage();
	CBullet1::LoadImage();
	CExpl_big::LoadImage();
	return 0;
}

//�ɻ��Ŀո����ҿ���
void CPlaneWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{


	//J�����ӵ�1
	if (nChar == 74 && myplane != NULL && nChar != 75) {
		BombList.AddTail(new CBomb(myplane->GetPoint().x + 52, myplane->GetPoint().y - 57));
	}
	//K�����ӵ�1
	if (nChar == 75 && myplane != NULL && nChar != 74) {
		Bomb1List.AddTail(new CBullet1(myplane->GetPoint().x + 52, myplane->GetPoint().y - 57, 0));
		Bomb1List.AddTail(new CBullet1(myplane->GetPoint().x + 40, myplane->GetPoint().y - 47, 1));
		Bomb1List.AddTail(new CBullet1(myplane->GetPoint().x + 60, myplane->GetPoint().y - 47, -1));

	}
	if (nChar == 66) {
		nodied = 1;
	}



	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CPlaneWarView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (myplane != NULL) {
		if (nChar == 87) {
			myplane->SetVerMotion(0);


		}
		if (nChar == 83) {
			myplane->SetVerMotion(0);


		}
		if (nChar == 65) {
			myplane->SetHorMotion(0);

		}
		if (nChar == 68) {
			myplane->SetHorMotion(0);

		}
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}