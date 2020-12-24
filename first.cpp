// first.cpp: 实现文件
//

#include "pch.h"
#include "SLR1fenxiqi.h"
#include "first.h"
#include "afxdialogex.h"


// first 对话框

IMPLEMENT_DYNAMIC(first, CDialogEx)

first::first(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

first::~first()
{
}

void first::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(first, CDialogEx)
END_MESSAGE_MAP()

void first::getFirstJi1(string s)
{
	SetDlgItemText(IDC_EDIT1, CA2T(s.c_str()));
}

// first 消息处理程序
