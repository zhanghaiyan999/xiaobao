
// ��ҵ10-1��2Set.cpp : C��ҵ101��2Set ���ʵ��
//

#include "stdafx.h"
#include "��ҵ10-1��2.h"
#include "��ҵ10-1��2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ101��2Set ʵ��

// ���������� 2020��5��11��, 19:52

IMPLEMENT_DYNAMIC(C��ҵ101��2Set, CRecordset)

C��ҵ101��2Set::C��ҵ101��2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = 0;
	column3 = 0;
	column4 = 0;
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ҵ101��2Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x8868;DBQ=C:\\Users\\96415\\Documents\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ҵ101��2Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void C��ҵ101��2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Long(pFX, _T("[ѧ��]"), column2);
	RFX_Long(pFX, _T("[����]"), column3);
	RFX_Long(pFX, _T("[�绰����]"), column4);
	RFX_Text(pFX, _T("[��Ƭ]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// C��ҵ101��2Set ���

#ifdef _DEBUG
void C��ҵ101��2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ҵ101��2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

