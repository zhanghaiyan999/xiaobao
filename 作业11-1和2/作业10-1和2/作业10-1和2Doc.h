
// ��ҵ10-1��2Doc.h : C��ҵ101��2Doc ��Ľӿ�
//


#pragma once
#include "��ҵ10-1��2Set.h"


class C��ҵ101��2Doc : public CDocument
{
protected: // �������л�����
	C��ҵ101��2Doc();
	DECLARE_DYNCREATE(C��ҵ101��2Doc)

// ����
public:
	C��ҵ101��2Set m_��ҵ101��2Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ҵ101��2Doc();
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
