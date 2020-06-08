// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication8.h"
#include "MyDlg.h"
#include "afxdialogex.h"



// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONabout, &MyDlg::OnBnClickedButtonabout)
	ON_BN_CLICKED(IDC_BUTTONback, &MyDlg::OnBnClickedButtonback)
	ON_BN_CLICKED(IDC_BUTTONclear, &MyDlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTONjia, &MyDlg::OnBnClickedButtonjia)
	ON_BN_CLICKED(IDC_BUTTON, &MyDlg::OnBnClickedButtonjian)
	ON_BN_CLICKED(IDC_BUTTONcheng, &MyDlg::OnBnClickedButtoncheng)
	ON_BN_CLICKED(IDC_BUTTONchu, &MyDlg::OnBnClickedButtonchu)
	ON_BN_CLICKED(IDC_BUTTONkaifang, &MyDlg::OnBnClickedButtonkaifang)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &MyDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &MyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &MyDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &MyDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTONDian, &MyDlg::OnBnClickedButtondian)
	ON_BN_CLICKED(IDC_BUTTONpingfang, &MyDlg::OnBnClickedButtonpingfang)
	ON_BN_CLICKED(IDC_BUTTONdeng, &MyDlg::OnBnClickedButtondeng)
END_MESSAGE_MAP()


// MyDlg 消息处理程序
void MyDlg::SaveValuel()
{
	UpdateData(TRUE);
	m1 = atof(s);
	s = _T("");
	UpdateData(FALSE);

}


void MyDlg::OnBnClickedButtonabout()//关于按钮
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void MyDlg::OnBnClickedButtonback()//后退按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!s.IsEmpty())
	{
		s = s.Left(s.GetLength() - 1); //移除最右边一个字符
	}
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButtonclear()//清屏按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s = ""; //将对话框设为空，即达到清零的效果
	UpdateData(FALSE);
}



void MyDlg::OnBnClickedButtonjia()//+按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValuel(); //执行SaveValue1()函数，保存第一个数值并在按下操作符按钮后、第二个数值输出之前使编辑框空白
    m = 0; //“+”的标志，用于Calculator()函数中case的跳转判断
	
}


void MyDlg::OnBnClickedButtonjian()//-按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValuel();
	m = 1; //“-”的标志，用于Calculator()函数中case的跳转判断
}


void MyDlg::OnBnClickedButtoncheng()//*按钮
{
	// TODO: 在此添加控件通知处理程序代码

	SaveValuel();
	m = 2; //“-”的标志，用于Calculator()函数中case的跳转判断

}


void MyDlg::OnBnClickedButtonchu()// 除按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValuel();
	m = 3; //“-”的标志，用于Calculator()函数中case的跳转判断

}



void MyDlg::OnBnClickedButtonkaifang()//开方按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m1 = atof(s);//atof()函数转化成为字符串
	double f = sqrt(m1);
	//如果浮点数其实是个整数
	if (f - int(f) <= 1e-5)
	{
		s.Format("%d", (int)f);
	}
	else
	{
		s.Format("%f", f);
	}
	UpdateData(FALSE);
	
}


void MyDlg::OnBnClickedButton1()//1按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"1";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton2()//2按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"2";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton3()//3按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"3";
	UpdateData(FALSE);
}



void MyDlg::OnBnClickedButton4()//4按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"4";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton5()//5按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"5";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton6()//6按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"6";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton7()//7按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"7";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton8()//8按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"8";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton9()//9按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"9";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButton0()//0按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	s += L"0";
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButtondian()//小数点按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个
	if (-1 == s.Find(L'.'))
	{
		s += L".";
	}
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButtonpingfang()//倒数按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m1 = atof(s); //由于只有一个操作数，因此不需要等到“=”按下时才在编辑框显示结果，因此不用添加到Calculator()函数中
	double f = 1/m1;
	//如果浮点数其实是个整数
	if (f - int(f) <= 1e-5)
	{
		s.Format("%d", (int)f);
	}
	else
	{
		s.Format("%f", f);
	}
	UpdateData(FALSE);
}


void MyDlg::OnBnClickedButtondeng()//等于按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//m_iSign=0~3分别对应“+”“-”“×”“÷”，m_iSign=6对应“指数”
	if (m != 0 && m != 1 && m!= 2 && m != 3 && m!= 6)
	{
		m1 = atof(s);
	}
	//当单击输入某一个数值而没有单击操作符按钮（“+”“-”“×”“÷”“指数”）、直接单击“=”时，界面上保持显示第一个操作数
	else
		Calculator();
	UpdateData(FALSE);
}
void MyDlg::Calculator()
{
	UpdateData(TRUE);
	m2 = atof(s); //获得第二个操作数并显示在编辑框中
	double f = 0.0f; //f必须初始化，用于保留计算结果
	switch (m) //根据m_iSign标志跳转
	{
	case 0:
		f = m1 + m2;//加
		break;
	case 1:
		f = m1 - m2;//减
		break;
	case 2:
		f = m1 * m2;//乘
		break;
	case 3:
		if (m2 == 0.0f) //除法中分母不能为0，为0时需要进行如下操作
		{
			MessageBox("除数不能为0!"); //弹出提示消息框
			f = m1;
			//除数为0时直接将第一个操作数赋给结果，表示第二个操作数不算，直接继续下一步操作
		}
		else
		{
			f = m1 / m2;//除
		}
		break;
	
	default:
		break;
	}
	//计算结果处理
	//如果浮点数其实是个整数
	if (f - int(f) <= 1e-5)
	{
		s.Format("%d", (int)f);
	}
	else
	{
		s.Format("%f", f); //double型的数据转为Cstring型
	}
	UpdateData(FALSE);
}