
// ��ҵ12-(���ݿ����)Set.cpp : C��ҵ12���ݿ����Set ���ʵ��
//

#include "stdafx.h"
#include "��ҵ12-(���ݿ����).h"
#include "��ҵ12-(���ݿ����)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ12���ݿ����Set ʵ��

// ���������� 2020��5��24��, 20:46

IMPLEMENT_DYNAMIC(C��ҵ12���ݿ����Set, CRecordset)

C��ҵ12���ݿ����Set::C��ҵ12���ݿ����Set(CDatabase* pdb)
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
CString C��ҵ12���ݿ����Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=E:\\access\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ҵ12���ݿ����Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��2]");
}

void C��ҵ12���ݿ����Set::DoFieldExchange(CFieldExchange* pFX)
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
// C��ҵ12���ݿ����Set ���

#ifdef _DEBUG
void C��ҵ12���ݿ����Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ҵ12���ݿ����Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

