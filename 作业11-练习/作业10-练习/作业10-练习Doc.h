
// ��ҵ10-��ϰDoc.h : C��ҵ10��ϰDoc ��Ľӿ�
//


#pragma once
#include "��ҵ10-��ϰSet.h"


class C��ҵ10��ϰDoc : public CDocument
{
protected: // �������л�����
	C��ҵ10��ϰDoc();
	DECLARE_DYNCREATE(C��ҵ10��ϰDoc)

// ����
public:
	C��ҵ10��ϰSet m_��ҵ10��ϰSet;

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
	virtual ~C��ҵ10��ϰDoc();
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
