
// ��ҵ-13(���ݿ��ѯ)Doc.cpp : C��ҵ13���ݿ��ѯDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ-13(���ݿ��ѯ).h"
#endif

#include "��ҵ-13(���ݿ��ѯ)Set.h"
#include "��ҵ-13(���ݿ��ѯ)Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ҵ13���ݿ��ѯDoc

IMPLEMENT_DYNCREATE(C��ҵ13���ݿ��ѯDoc, CDocument)

BEGIN_MESSAGE_MAP(C��ҵ13���ݿ��ѯDoc, CDocument)
END_MESSAGE_MAP()


// C��ҵ13���ݿ��ѯDoc ����/����

C��ҵ13���ݿ��ѯDoc::C��ҵ13���ݿ��ѯDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ҵ13���ݿ��ѯDoc::~C��ҵ13���ݿ��ѯDoc()
{
}

BOOL C��ҵ13���ݿ��ѯDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}



#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ҵ13���ݿ��ѯDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��ҵ13���ݿ��ѯDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ҵ13���ݿ��ѯDoc::SetSearchContent(const CString& value)
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

// C��ҵ13���ݿ��ѯDoc ���

#ifdef _DEBUG
void C��ҵ13���ݿ��ѯDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ҵ13���ݿ��ѯDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ҵ13���ݿ��ѯDoc ����
