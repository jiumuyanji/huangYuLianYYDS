
// SLR1fenxiqiDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SLR1fenxiqi.h"
#include "SLR1fenxiqiDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <vector>
#include "first.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSLR1fenxiqiDlg 对话框



CSLR1fenxiqiDlg::CSLR1fenxiqiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SLR1FENXIQI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSLR1fenxiqiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, show);
}

BEGIN_MESSAGE_MAP(CSLR1fenxiqiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSLR1fenxiqiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSLR1fenxiqiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSLR1fenxiqiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSLR1fenxiqiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSLR1fenxiqiDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSLR1fenxiqiDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CSLR1fenxiqiDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSLR1fenxiqiDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CSLR1fenxiqiDlg 消息处理程序

BOOL CSLR1fenxiqiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSLR1fenxiqiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSLR1fenxiqiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSLR1fenxiqiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CSLR1fenxiqiDlg::judge()//判断是否需要扩充语法
{
	GetDlgItemTextW(IDC_EDIT1, grammer);
	string g(CT2A(grammer.GetString()));
	int i = 0;
	bool sign = true;
	while (g[i] != '\n'&&g[i]!='\0')
	{
		if (g[i] == '|') {
			MessageBox(L"需要进行语法扩充");
			sign = false;
			break;
		}
		i++;
	}
	return sign;
}

void CSLR1fenxiqiDlg::OnBnClickedButton1()//打开文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString path;
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		path = dlg.GetPathName();
		fstream f;
		f.open(path, ios::in);
		string s;
		string a;
		while (!f.eof())
		{
			getline(f, a);
			s += a;
			if (!f.eof())
			{
				s += "\n";
			}
		}
		f.close();
		SetDlgItemText(IDC_EDIT1, CA2T(s.c_str()));
	}
	else
	{
		return;
	}
}


void CSLR1fenxiqiDlg::OnBnClickedButton2()//保存文件
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog savedlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), NULL);
	if (savedlg.DoModal() == IDOK)
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);

		fstream file;
		file.open(savedlg.GetPathName(), ios::out);
		file << CW2A(str.GetString());
		file.close();
	}
	else return;
}

void CSLR1fenxiqiDlg::OnBnClickedButton3()
{
	if(judge())
	{
		MessageBox(L"无需扩充");
	}
}

void Stringsplit(const string& str, const string& splits, vector<string>& res)//分割string，用splits分割str，结果保存到res
{
	if (str == "")		return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + splits;
	size_t pos = strs.find(splits);
	int step = splits.size();

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + step, strs.size());
		pos = strs.find(splits);
	}
}

bool CSLR1fenxiqiDlg::isNoLast(string s)//判断是不是非终结符，s为非终结符返回true，s为终结符返回false
{
	bool b = false;
	for (int i = 0; i < noLast.size(); i++)
	{
		if (s == noLast[i])
		{
			b = true;
			break;
		}
	}
	return b;
}

int CSLR1fenxiqiDlg::getNoLastId(string s)//返回s对应的非终结符在，非终结符数组的位置
{
	int i = 0;
	for (i = 0; i < noLast.size(); i++)
	{
		if (s == noLast[i])
		{
			return i;
		}
	}
	return -1;
}

bool CSLR1fenxiqiDlg::notIn(string s, vector<string> f)//s不在f里返回true，s在f里返回true
{
	for (int i = 0; i < f.size(); i++)
	{
		if (s == f[i])
		{
			return false;
		}
	}
	return true;
}

void CSLR1fenxiqiDlg::getTable()//设置table
{
	noLast.clear();
	table.clear();
	last.clear();
	allChar.clear();//清空上次的结果
	bool s = judge();//判断是否需要语法扩充
	if (!s) {
		return;
	}
	string g(CT2A(grammer.GetString()));//获取输入的文法
	vector<string> lines;//切割成一行一行
	Stringsplit(g, "\r\n", lines);
	vector<string> temp;
	vector<string> temp2;//把右边的用|切开
	for (int i = 0; i < lines.size(); i++)
	{
		Stringsplit(lines[i], "->", temp);//切割成左右两边
		if (temp.size() > 2)
		{
			MessageBox(L"文法错误，->输入多了");
		}
		dui d;
		d.left = temp[0];
		d.leftId = i;
		noLast.push_back(temp[0]);//保存非终结符，也就是切开的左边部分
		if (notIn(temp[0], allChar))
		{
			allChar.push_back(temp[0]);//是否在总符号集，不在就加进去
		}
		Stringsplit(temp[1], "|", temp2);//把右边的用|切开，并且有同一个左边
		for (int j = 0; j < temp2.size(); j++)
		{
			Stringsplit(temp2[j], " ", d.right);
			for (int x = 0; x < d.right.size(); x++)
			{
				if (notIn(d.right[x], allChar))
				{
					allChar.push_back(d.right[x]);//是否在总符号集，不在就加进去
				}
			}
			table.push_back(d);//把文法规则变为结构体保存起来
			d.right.clear();
		}
		temp.clear();
		temp2.clear();//把用到的中间变量清空
	}
	for (int i = 0; i < allChar.size(); i++)
	{
		if (notIn(allChar[i], last) &&!isNoLast(allChar[i]))//总文法符号-非终结符=终结符
		{
			last.push_back(allChar[i]);
		}
	}
	allChar.clear();//排序，把终结符放在前面，非终结符反正后面，服务于SLR1的构建
	for (int i = 0; i < last.size(); i++)
	{
		allChar.push_back(last[i]);
	}
	for (int i = 0; i < noLast.size(); i++)
	{
		allChar.push_back(noLast[i]);
	}
}

void CSLR1fenxiqiDlg::getFirstJi()
{
	getTable();
	firstJi.clear();
	for (int i = 0; i < noLast.size(); i++)
	{
		vector<string> a;
		firstJi.push_back(a);
	}//初始化，不然会出现数组越界
	int count = 0;
	int newCount = 0;//count和newcount用来判断first集是不是有变化
	int k = 0;//k用来处理~，也就是空
	bool Continue = true;//同上
	do
	{
		count = newCount;
		for (int i = 0; i < table.size(); i++)//所有的文法规则都过一遍
		{
			k = 0;
			Continue = true;
			while (Continue == true && k < table[i].right.size())//k指向被选中的符号，一半不是空的话，k都为0
			{
				if (isNoLast(table[i].right[k]))//如果要选中的符号是不是非终结符
				{
					int x = getNoLastId(table[i].right[k]);
					for (int j = 0; j < firstJi[x].size(); j++)//取该被选中的非终结符的first集里的符号
					{
						if (firstJi[x][j] != "~" && notIn(firstJi[x][j], firstJi[table[i].leftId]))//如果不是空，而且该被选中的符号的first集里的符号没有在对应的first集里面
						{
							firstJi[table[i].leftId].push_back(firstJi[x][j]);
							newCount++;
						}
					}
				}
				else
				{
					if (table[i].right[k] != "~" && notIn(table[i].right[k], firstJi[table[i].leftId]))//如果是终结符，就判断它自己就行，不用去first集里找
					{
						firstJi[table[i].leftId].push_back(table[i].right[k]);
						newCount++;
					}
				}
				if (isNoLast(table[i].right[k]))
				{
					if (notIn("~", firstJi[getNoLastId(table[i].right[k])]))//如果是非终结符，并且first集里没有空，那么就不需要因为有空而去找它后面的符号了
					{
						Continue = false;
					}
				}
				else if (table[i].right[k] != "~")//终结符不是空，也不需要找。
				{
					Continue = false;
				}
				else if (!notIn("~", firstJi[table[i].leftId]))//这里应该可以删了，但是忘记这里是干嘛的，还是留着吧
				{
					Continue = false;
				}
				k++;//指向下一个符号，如果continue为真就找，不是就不用管它
			}
			if (Continue == true)
			{
				if (notIn("~", firstJi[table[i].leftId]))//防止重复
				{
					firstJi[table[i].leftId].push_back("~");//如果该行文法全为空，就把空加进去
					newCount++;
				}
			}
		}
	} while (count != newCount);
}

void CSLR1fenxiqiDlg::OnBnClickedButton4()//输出first
{
	// TODO: 在此添加控件通知处理程序代码
	getFirstJi();
	string output="first集合:\r\n";
	for (int i = 0; i < firstJi.size(); i++)
	{
		output += noLast[i];
		output += " : ";
		for (int j = 0; j < firstJi[i].size(); j++)
		{
			output += firstJi[i][j];
			output += " , ";
		}
		output += "\r\n";
	}
	first* pDlg = new first;
	pDlg->Create(IDD_DIALOG2, this);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->getFirstJi1(output);
}

int CSLR1fenxiqiDlg::addJi(vector<string> a, vector<string>& b)//把a的元素都加到b里面去
{
	int c=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (notIn(a[i], b)&&a[i]!="~")
		{
			b.push_back(a[i]);
			++c;
		}
	}
	return c;
}

void CSLR1fenxiqiDlg::getFollowJi()
{
	getFirstJi();
	followJi.clear();
	for (int i = 0; i < noLast.size(); i++)//初始化，防止数组越界
	{
		vector<string> a;
		followJi.push_back(a);
	}
	followJi[0].push_back("$");
	int count = 0;
	int newCount = 0;//判断是不是有变化的两个工具人变量
	do
	{
		count = newCount;
		for (int i = 0; i < table.size(); i++)//行遍历
		{
			for (int j = 0; j < table[i].right.size(); j++)//列遍历
			{
				if (isNoLast(table[i].right[j]))//如果在右边出现非终结符，那么出现的地点的下一个符号，就是这个非终结符的follow元素
				{
					if ((j + 1) == table[i].right.size())//如果该非终结符是最后一个，那它的非终结集包含它最左边那个非终结符的follow集
					{
						newCount += addJi(followJi[table[i].leftId], followJi[getNoLastId(table[i].right[j])]);
					}
					else if (isNoLast(table[i].right[j + 1]))//如果下一个是非终结符，那么下一个的first集是这个非终结符的follow集
					{
						newCount += addJi(firstJi[getNoLastId(table[i].right[j + 1])], followJi[getNoLastId(table[i].right[j])]);
					}
					else if (table[i].right[j] != "~")//空后面不会有东西相当于直接到最后
					{
						if (notIn(table[i].right[j + 1], followJi[getNoLastId(table[i].right[j])]))
						{
							followJi[getNoLastId(table[i].right[j])].push_back(table[i].right[j + 1]);
							++newCount;
						}
					}
				}
			}
		}
	} while (count != newCount);
}

void CSLR1fenxiqiDlg::OnBnClickedButton5()//输出follow集
{
	// TODO: 在此添加控件通知处理程序代码
	getFollowJi();
	string output = "follow集合:\r\n";
	for (int i = 0; i < followJi.size(); i++)
	{
		output += noLast[i];
		output += " : ";
		for (int j = 0; j < followJi[i].size(); j++)
		{
			output += followJi[i][j];
			output += " , ";
		}
		output += "\r\n";
	}
	first* pDlg = new first;
	pDlg->Create(IDD_DIALOG2, this);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->getFirstJi1(output);
}

bool CSLR1fenxiqiDlg::inItem(production B, state s)//B是不是在s里面，是的话返回true；不是false
{
	bool sign = false;
	for (int i = 0; i < s.item.size(); i++)
	{
		if (B.left == s.item[i].left&& B.point == s.item[i].point&& B.right.size() == s.item[i].right.size())
		{
			bool sign2 = true;
			for (int j = 0; j < B.right.size(); j++)
			{
				if (B.right[j] != s.item[i].right[j])
				{
					sign2 = false;
					break;
				}
			}
			if (sign2 == true)
			{
				sign = true;
				return true;
			}
		}
	}
	return false;
}

state CSLR1fenxiqiDlg::closure(state s) //求s的闭包
{
	state s1 = s;
	int count = s1.item.size();//判断是否变化
	do
	{
		count= s1.item.size();
		for (int i = 0; i < s1.item.size(); i++)//行遍历
		{
			if (s1.item[i].point < s1.item[i].right.size())//点在最后，不加会越界
			{
				string B = s1.item[i].right[s1.item[i].point];//B为点后面那个符号
				if (isNoLast(B))//终结符不用处理
				{
					for (int j = 0; j < table.size(); j++)//把文法规则里，用B开头的都找出来，点指向第一个，
					{
						if (table[j].left == B)
						{
							production temp;
							temp.left = B;
							temp.point = 0;
							for (int k = 0; k < table[j].right.size(); k++)
							{
								temp.right.push_back(table[j].right[k]);
							}
							if (temp.right[0] == "~")//如果第一个是空的话，点放在空后面
							{
								temp.point++;
							}
							if (!inItem(temp, s1))
							{
								s1.item.push_back(temp);
							}
							if (temp.right[0] == "~")
							{
								temp.point--;
							}
						}
					}
				}
			}
		}
	} while (count != s1.item.size());
	return s1;
}

state CSLR1fenxiqiDlg::Goto(state s, string n)//看看s经过n可以变为什么状态
{
	state s1;
	for (int i = 0; i < s.item.size(); i++)
	{
		if (s.item[i].point < s.item[i].right.size())//找点后面是n的文法，把点往后面移一位。然后丢在s1里面
		{
			if (s.item[i].right[s.item[i].point] == n)
			{
				s.item[i].point++;
				s1.item.push_back(s.item[i]);
			}
		}
	}
	return s1;
}
void CSLR1fenxiqiDlg::getLR0()
{
	getTable();
	LR0states.clear();
	LR0.clear();
	production a;
	a.left = table[0].left;
	a.point = 0;
	for (int i = 0; i < table[0].right.size(); i++)//初始化，防越界
	{
		a.right.push_back(table[0].right[i]);
	}
	state s;
	s.item.push_back(a);
	s = closure(s);
	LR0states.push_back(s);//把第一个状态搞好，
	int* next = new int[allChar.size()];
	for (int i = 0; i < allChar.size(); i++)//把LR（0）表初始化
	{
		next[i] = -1;
	}
	LR0.push_back(next);
	for (int x = 0; x < LR0.size(); x++)
	{
		for (int i = 0; i < allChar.size(); i++)
		{
			s = LR0states[x];
			s = Goto(s, allChar[i]);
			if (s.item.size() != 0)
			{
				s = closure(s);
				int j = 0;
				for (j = 0; j < LR0states.size(); j++)//看看生成的闭包是不是已经有了，
				{
					if (s.item.size() == LR0states[j].item.size())
					{
						int k;
						for (k = 0; k < s.item.size(); k++)
						{
							if (!inItem(s.item[k], LR0states[j]))
							{
								break;
							}
						}
						if (k == s.item.size())//有了的话，就修改LR（0）指向原来那个
						{
							LR0[x][i] = j;
							break;
						}
					}
				}
				if (j == LR0states.size())//没有就加进去
				{
					LR0states.push_back(s);
					next = new int[allChar.size()];
					for (int i = 0; i < allChar.size(); i++)
					{
						next[i] = -1;
					}
					LR0.push_back(next);
					LR0[x][i] = LR0.size() - 1;//指向新加进去的那个
				}
			}
		}
	}
}

void CSLR1fenxiqiDlg::OnBnClickedButton6()//输出LR(0)
{
	// TODO: 在此添加控件通知处理程序代码
	getLR0();
	string output = "LR(0) states集:\r\n";
	for (int i = 0; i < LR0states.size(); i++)
	{
		output += "state "+to_string(i);
		output += ":\r\n";
		for (int j = 0; j < LR0states[i].item.size(); j++)
		{
			output += LR0states[i].item[j].left + "->";
			for (int k = 0; k < LR0states[i].item[j].right.size(); k++)
			{
				if (k == LR0states[i].item[j].point)
				{
					output += " . ";
				}
				output += LR0states[i].item[j].right[k] + " ";
			}
			if (LR0states[i].item[j].point == LR0states[i].item[j].right.size())
			{
				output += " . ";
			}
			output += "\r\n";
		}
		output += "\r\n";
	}
	first* pDlg = new first;
	pDlg->Create(IDD_DIALOG2, this);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->getFirstJi1(output);//上面的为输出序号对应的状态的文法有什么，下面为DFA表
	while (show.DeleteColumn(0));
	show.DeleteAllItems();
	show.InsertColumn(0, L"状态/文法符号", LVCFMT_CENTER, 100);
	DWORD dwStyle = show.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES;
	show.SetExtendedStyle(dwStyle);
	for (int x = 1; x <= allChar.size(); x++)
	{
		CString a=CA2T(allChar[x - 1].c_str()); 
		show.InsertColumn(x, a, LVCFMT_CENTER, 50);
	}
	CString a;
	for (int i = 0; i < LR0.size(); i++)
	{
		a.Format(_T("%d"), i);
		show.InsertItem(i, a);
		for (int j = 0; j < allChar.size(); j++)
		{
			if (LR0[i][j] != -1)
			{
				a.Format(_T("%d"), LR0[i][j]);
				show.SetItemText(i, j + 1, a);
			}
			else
			{
				show.SetItemText(i, j + 1, L" ");
			}
		}
	}
}

bool CSLR1fenxiqiDlg::getSLR1()
{
	getLR0();
	getFollowJi();
	SLR1.clear();
	for (int i = 0; i < LR0.size(); i++)//把上面的LR(0)拷贝一张，修改一下要输出的东西，如果是终结符前面加个s
	{
		vector<string> temp;
		for (int j = 0; j < allChar.size(); j++)
		{
			if (LR0[i][j] != -1)
			{
				if (isNoLast(allChar[j]))
				{
					temp.push_back(to_string(LR0[i][j]));
				}
				else
				{
					temp.push_back("s" + to_string(LR0[i][j]));
				}
			}
			else
			{
				temp.push_back(" ");
			}
		}
		SLR1.push_back(temp);
		temp.clear();
	}
	for (int i = 0; i < LR0states.size(); i++)//找出归约项 i，k确定在表里的位置，j确定是第几个产生式
	{
		for (int j = 0; j < LR0states[i].item.size(); j++)
		{
			if (LR0states[i].item[j].point == LR0states[i].item[j].right.size())//如果该产生式的点在最后面，那么可以归约
			{
				int k = 0;
				for (k = 0; k < noLast.size(); k++)
				{
					if (noLast[k] == LR0states[i].item[j].left)
					{
						break;
					}
				}                                                                //看看归约成什么，k表示归约出来的东西，在follow集的第几行
				for (int l = 0; l < followJi[k].size(); l++)					//文法里第一个输入的东西，也就是第一个非终结符，这里是不会被用到的，刚好用来处理$.
				{																	//第一个非终结符的位置是在终结符符的末尾，这就是为什么我前面要调allChar的顺序了
					if (followJi[k][l] == "$" && LR0states[i].item[j].left == noLast[0])
					{
						SLR1[i][last.size()] = "acc";
					}
					else if (followJi[k][l] == "$")
					{
						if (SLR1[i][last.size()] != " ")						//这里如果要填入的地方不为空，证明前面输入想要的符号，既可以跳转，又可以归约，有二义性，要报错。
						{
							string z = "不符合SLR（1）文法！\r\nACTION(" + to_string(i) + ",$)冲突，原为" + SLR1[i][last.size()] + "预填入";
							z += "r(" + LR0states[i].item[j].left + "->";
							for (int n = 0; n < LR0states[i].item[j].right.size(); n++)
							{
								z += LR0states[i].item[j].right[n];
							}
							z += ")";
							MessageBox(CA2T(z.c_str()));
							return false;
						}
						else
						{
																					//没有填东西就，把r（用来规约的文法规则）存进去。
						}
						{
							SLR1[i][last.size()] = "r(" + LR0states[i].item[j].left + "->";
							for (int n = 0; n < LR0states[i].item[j].right.size(); n++)
							{
								SLR1[i][last.size()] += LR0states[i].item[j].right[n];
							}
							SLR1[i][last.size()] += ")";
						}
					}
					for (int m = 0; m < last.size(); m++)                                 //同上
					{
						if (last[m] == followJi[k][l])
						{
							if (SLR1[i][m] != " ")
							{
								string z = "不符合SLR（1）文法！\r\nACTION(" + to_string(i) + "，" + last[m] + ")发生冲突，原为" + SLR1[i][m] + "预填入";
								z += "r(" + LR0states[i].item[j].left + "->";
								for (int n = 0; n < LR0states[i].item[j].right.size(); n++)
								{
									z += LR0states[i].item[j].right[n];
								}
								z += ")";
								MessageBox(CA2T(z.c_str()));
								return false;
							}
							else
							{
								SLR1[i][m] = "r(" + LR0states[i].item[j].left + "->";
								for (int n = 0; n < LR0states[i].item[j].right.size(); n++)
								{
									SLR1[i][m] += LR0states[i].item[j].right[n];
								}
								SLR1[i][m] += ")";
							}
						}
					}
				}
			}
		}
	}
	return true;
}

void CSLR1fenxiqiDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (getSLR1())
	{
		MessageBox(L"符合SLR(1)文法！");
	}
}


void CSLR1fenxiqiDlg::OnBnClickedButton8()//输出SLR1,和上面的LR(0)差不多
{
	if (!getSLR1())
	{
		return;
	}
	string output = "SLR(1) states集:\r\n";
	output += "action:\r\n";
	for(int i=0;i<last.size();i++)
	{
		output += last[i] + " ";
	}
	output += "\r\n";
	output += "goto:\r\n";
	for (int i = 1; i < noLast.size(); i++)
	{
		output += noLast[i] + " ";
	}
	output += "\r\n";
	for (int i = 0; i < LR0states.size(); i++)
	{
		output += "state " + to_string(i);
		output += ":\r\n";
		for (int j = 0; j < LR0states[i].item.size(); j++)
		{
			output += LR0states[i].item[j].left + "->";
			for (int k = 0; k < LR0states[i].item[j].right.size(); k++)
			{
				if (k == LR0states[i].item[j].point)
				{
					output += " . ";
				}
				output += LR0states[i].item[j].right[k] + " ";
			}
			if (LR0states[i].item[j].point == LR0states[i].item[j].right.size())
			{
				output += " . ";
			}
			output += "\r\n";
		}
		output += "\r\n";
	}
	first* pDlg = new first;
	pDlg->Create(IDD_DIALOG2, this);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->getFirstJi1(output);
	allChar[last.size()] = "$";
	while (show.DeleteColumn(0));
	show.DeleteAllItems();
	show.InsertColumn(0, L"状态/文法符号", LVCFMT_CENTER, 100);
	DWORD dwStyle = show.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES;
	show.SetExtendedStyle(dwStyle);
	for (int x = 1; x <= allChar.size(); x++)
	{
		CString a = CA2T(allChar[x - 1].c_str());
		show.InsertColumn(x, a, LVCFMT_CENTER, 100);
	}
	CString a;
	for (int i = 0; i < LR0.size(); i++)
	{
		a.Format(_T("%d"), i);
		show.InsertItem(i, a);
		for (int j = 0; j < allChar.size(); j++)
		{
			show.SetItemText(i, j + 1, CA2T(SLR1[i][j].c_str()));
		}
	}
}
