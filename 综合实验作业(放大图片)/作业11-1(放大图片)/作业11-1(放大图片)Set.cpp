
// ��ҵ11-1(�Ŵ�ͼƬ)Set.cpp : C��ҵ111�Ŵ�ͼƬSet ���ʵ��
//

#include "stdafx.h"
#include "��ҵ11-1(�Ŵ�ͼƬ).h"
#include "��ҵ11-1(�Ŵ�ͼƬ)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ111�Ŵ�ͼƬSet ʵ��

// ���������� 2020��5��18��, 10:58

IMPLEMENT_DYNAMIC(C��ҵ111�Ŵ�ͼƬSet, CRecordset)

C��ҵ111�Ŵ�ͼƬSet::C��ҵ111�Ŵ�ͼƬSet(CDatabase* pdb)
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
CString C��ҵ111�Ŵ�ͼƬSet::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=E:\\access\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ҵ111�Ŵ�ͼƬSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��2]");
}

void C��ҵ111�Ŵ�ͼƬSet::DoFieldExchange(CFieldExchange* pFX)
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
// C��ҵ111�Ŵ�ͼƬSet ���

#ifdef _DEBUG
void C��ҵ111�Ŵ�ͼƬSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ҵ111�Ŵ�ͼƬSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

