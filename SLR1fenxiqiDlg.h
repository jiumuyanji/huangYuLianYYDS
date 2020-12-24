
// SLR1fenxiqiDlg.h: 头文件
//

#pragma once
#include<string>
#include<vector>
using namespace std;

struct dui
{
	string left;
	int leftId=0;
	vector<string> right;
};

struct production
{
	string left;
	vector<string> right;
	int point = 0;
};

struct state
{
	vector<production> item;
};

// CSLR1fenxiqiDlg 对话框
class CSLR1fenxiqiDlg : public CDialogEx
{
// 构造
public:
	CSLR1fenxiqiDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SLR1FENXIQI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString grammer;
	bool judge();
	bool isNoLast(string);
	int getNoLastId(string);
	bool notIn(string, vector<string>);
	vector<string> noLast;
	vector<dui> table;
	vector<vector<string>> firstJi;
	vector<vector<string>> followJi;
	void getFirstJi();
	int addJi(vector<string>,vector<string>&);
	void getFollowJi();
	void getTable();
	vector<string> last;
	vector<string> allChar;
	bool inItem(production, state);
	state closure(state);
	state Goto(state,string);
	vector<state> LR0states;
	vector<int*> LR0;
	void getLR0();
	vector<vector<string>>SLR1;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CListCtrl show;
	bool getSLR1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
