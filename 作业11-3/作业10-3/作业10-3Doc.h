
// ��ҵ10-3Doc.h : C��ҵ103Doc ��Ľӿ�
//


#pragma once
#include "��ҵ10-3Set.h"


class C��ҵ103Doc : public CDocument
{
protected: // �������л�����
	C��ҵ103Doc();
	DECLARE_DYNCREATE(C��ҵ103Doc)

// ����
public:
	C��ҵ103Set m_��ҵ103Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ҵ103Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
