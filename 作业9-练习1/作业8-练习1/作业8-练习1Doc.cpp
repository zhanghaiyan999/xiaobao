
// ��ҵ8-��ϰ1Doc.cpp : C��ҵ8��ϰ1Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-��ϰ1.h"
#endif

#include "��ҵ8-��ϰ1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ҵ8��ϰ1Doc

IMPLEMENT_DYNCREATE(C��ҵ8��ϰ1Doc, CDocument)

BEGIN_MESSAGE_MAP(C��ҵ8��ϰ1Doc, CDocument)
END_MESSAGE_MAP()


// C��ҵ8��ϰ1Doc ����/����

C��ҵ8��ϰ1Doc::C��ҵ8��ϰ1Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ҵ8��ϰ1Doc::~C��ҵ8��ϰ1Doc()
{
}

BOOL C��ҵ8��ϰ1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��ҵ8��ϰ1Doc ���л�

void C��ҵ8��ϰ1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << A;
	}
	else
	{
		ar >> A;// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ҵ8��ϰ1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��ҵ8��ϰ1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ҵ8��ϰ1Doc::SetSearchContent(const CString& value)
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

// C��ҵ8��ϰ1Doc ���

#ifdef _DEBUG
void C��ҵ8��ϰ1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ҵ8��ϰ1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ҵ8��ϰ1Doc ����
