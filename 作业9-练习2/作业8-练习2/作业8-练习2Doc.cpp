
// ��ҵ8-��ϰ2Doc.cpp : C��ҵ8��ϰ2Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-��ϰ2.h"
#endif

#include "��ҵ8-��ϰ2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ҵ8��ϰ2Doc

IMPLEMENT_DYNCREATE(C��ҵ8��ϰ2Doc, CDocument)

BEGIN_MESSAGE_MAP(C��ҵ8��ϰ2Doc, CDocument)
END_MESSAGE_MAP()


// C��ҵ8��ϰ2Doc ����/����

C��ҵ8��ϰ2Doc::C��ҵ8��ϰ2Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ҵ8��ϰ2Doc::~C��ҵ8��ϰ2Doc()
{
}

BOOL C��ҵ8��ϰ2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��ҵ8��ϰ2Doc ���л�

void C��ҵ8��ϰ2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar >> A >> B;
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		ar << A << B;
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ҵ8��ϰ2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C��ҵ8��ϰ2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ҵ8��ϰ2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C��ҵ8��ϰ2Doc ���

#ifdef _DEBUG
void C��ҵ8��ϰ2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ҵ8��ϰ2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ҵ8��ϰ2Doc ����
