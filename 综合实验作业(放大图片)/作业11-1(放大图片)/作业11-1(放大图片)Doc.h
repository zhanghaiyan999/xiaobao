
// ��ҵ11-1(�Ŵ�ͼƬ)Doc.h : C��ҵ111�Ŵ�ͼƬDoc ��Ľӿ�
//


#pragma once
#include "��ҵ11-1(�Ŵ�ͼƬ)Set.h"


class C��ҵ111�Ŵ�ͼƬDoc : public CDocument
{
protected: // �������л�����
	C��ҵ111�Ŵ�ͼƬDoc();
	DECLARE_DYNCREATE(C��ҵ111�Ŵ�ͼƬDoc)

// ����
public:
	C��ҵ111�Ŵ�ͼƬSet m_��ҵ111�Ŵ�ͼƬSet;

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
	virtual ~C��ҵ111�Ŵ�ͼƬDoc();
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
