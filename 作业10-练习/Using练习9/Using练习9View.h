
// Using��ϰ9View.h : CUsing��ϰ9View ��Ľӿ�
//

#pragma once


class CUsing��ϰ9View : public CView
{
protected: // �������л�����
	CUsing��ϰ9View();
	DECLARE_DYNCREATE(CUsing��ϰ9View)

// ����
public:
	CUsing��ϰ9Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsing��ϰ9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Using��ϰ9View.cpp �еĵ��԰汾
inline CUsing��ϰ9Doc* CUsing��ϰ9View::GetDocument() const
   { return reinterpret_cast<CUsing��ϰ9Doc*>(m_pDocument); }
#endif

