
// ��ҵ11-1(�Ŵ�ͼƬ)Doc.cpp : C��ҵ111�Ŵ�ͼƬDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ11-1(�Ŵ�ͼƬ).h"
#endif

#include "��ҵ11-1(�Ŵ�ͼƬ)Set.h"
#include "��ҵ11-1(�Ŵ�ͼƬ)Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ҵ111�Ŵ�ͼƬDoc

IMPLEMENT_DYNCREATE(C��ҵ111�Ŵ�ͼƬDoc, CDocument)

BEGIN_MESSAGE_MAP(C��ҵ111�Ŵ�ͼƬDoc, CDocument)
END_MESSAGE_MAP()


// C��ҵ111�Ŵ�ͼƬDoc ����/����

C��ҵ111�Ŵ�ͼƬDoc::C��ҵ111�Ŵ�ͼƬDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ҵ111�Ŵ�ͼƬDoc::~C��ҵ111�Ŵ�ͼƬDoc()
{
}

BOOL C��ҵ111�Ŵ�ͼƬDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��ҵ111�Ŵ�ͼƬDoc ���л�

void C��ҵ111�Ŵ�ͼƬDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ҵ111�Ŵ�ͼƬDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��ҵ111�Ŵ�ͼƬDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ҵ111�Ŵ�ͼƬDoc::SetSearchContent(const CString& value)
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

// C��ҵ111�Ŵ�ͼƬDoc ���

#ifdef _DEBUG
void C��ҵ111�Ŵ�ͼƬDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ҵ111�Ŵ�ͼƬDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ҵ111�Ŵ�ͼƬDoc ����
