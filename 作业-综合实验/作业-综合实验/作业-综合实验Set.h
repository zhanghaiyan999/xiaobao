
// ��ҵ-�ۺ�ʵ��Set.h: C��ҵ�ۺ�ʵ��Set ��Ľӿ�
//


#pragma once

// ���������� 2020��6��8��, 19:06

class C��ҵ�ۺ�ʵ��Set : public CRecordset
{
public:
	C��ҵ�ۺ�ʵ��Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(C��ҵ�ۺ�ʵ��Set)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	column1;
	long	column2;
	long	column3;
	long	column4;
	CStringW	column5;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

