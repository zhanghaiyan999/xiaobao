
// ��ҵ12-(���ݿ����)Doc.h : C��ҵ12���ݿ����Doc ��Ľӿ�
//


#pragma once
#include "��ҵ12-(���ݿ����)Set.h"


class C��ҵ12���ݿ����Doc : public CDocument
{
protected: // �������л�����
	C��ҵ12���ݿ����Doc();
	DECLARE_DYNCREATE(C��ҵ12���ݿ����Doc)

// ����
public:
	C��ҵ12���ݿ����Set m_��ҵ12���ݿ����Set;

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
	virtual ~C��ҵ12���ݿ����Doc();
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
