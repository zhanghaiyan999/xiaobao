
// ��ҵ-13(���ݿ��ѯ)Set.cpp : C��ҵ13���ݿ��ѯSet ���ʵ��
//

#include "stdafx.h"
#include "��ҵ-13(���ݿ��ѯ).h"
#include "��ҵ-13(���ݿ��ѯ)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ13���ݿ��ѯSet ʵ��

// ���������� 2020��5��25��, 21:40

IMPLEMENT_DYNAMIC(C��ҵ13���ݿ��ѯSet, CRecordset)

C��ҵ13���ݿ��ѯSet::C��ҵ13���ݿ��ѯSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = 0;
	column3 = 0;
	column4 = 0;
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ҵ13���ݿ��ѯSet::GetDefaultConnect()
{
	return _T("DSN=zzz;DBQ=E:\\access\\Database4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ҵ13���ݿ��ѯSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��4]");
}

void C��ҵ13���ݿ��ѯSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Long(pFX, _T("[����]"), column2);
	RFX_Long(pFX, _T("[����]"), column3);
	RFX_Long(pFX, _T("[�ֻ�����]"), column4);
	RFX_Text(pFX, _T("[��Ƭ]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// C��ҵ13���ݿ��ѯSet ���

#ifdef _DEBUG
void C��ҵ13���ݿ��ѯSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ҵ13���ݿ��ѯSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

