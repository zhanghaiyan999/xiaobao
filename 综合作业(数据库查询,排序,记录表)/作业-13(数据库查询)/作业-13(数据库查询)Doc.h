
// ��ҵ-13(���ݿ��ѯ)Doc.h : C��ҵ13���ݿ��ѯDoc ��Ľӿ�
//


#pragma once
#include "��ҵ-13(���ݿ��ѯ)Set.h"


class C��ҵ13���ݿ��ѯDoc : public CDocument
{
protected: // �������л�����
	C��ҵ13���ݿ��ѯDoc();
	DECLARE_DYNCREATE(C��ҵ13���ݿ��ѯDoc)

// ����
public:
	C��ҵ13���ݿ��ѯSet m_��ҵ13���ݿ��ѯSet;

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
	virtual ~C��ҵ13���ݿ��ѯDoc();
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
