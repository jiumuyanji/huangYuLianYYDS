#pragma once
#include <string>
using namespace std;

// first 对话框

class first : public CDialogEx
{
	DECLARE_DYNAMIC(first)

public:
	first(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~first();
	void getFirstJi1(string);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
