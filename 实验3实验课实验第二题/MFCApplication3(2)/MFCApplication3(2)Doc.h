
// MFCApplication3(2)Doc.h : CMFCApplication32Doc ��Ľӿ�
//


#pragma once


class CMFCApplication32Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication32Doc();
	DECLARE_DYNCREATE(CMFCApplication32Doc)

// ����
public:

// ����
public:
	int A, B;
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
	virtual ~CMFCApplication32Doc();
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
