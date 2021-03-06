// CartonBoxPrint.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "CartonBoxPrint.h"
#include "PACKDoc.h"
#include "MainFrm.h"
#include "PACKView.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define MAIN_SOURCE     0
#define SUB_SOURCE      1
/////////////////////////////////////////////////////////////////////////////
// CCartonBoxPrint dialog


CCartonBoxPrint::CCartonBoxPrint(CWnd* pParent /*=NULL*/)
	: CDialog(CCartonBoxPrint::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCartonBoxPrint)
	m_replace_R1 = _T("");
	m_replace_R10 = _T("");
	m_replace_R11 = _T("");
	m_replace_R12 = _T("");
	m_replace_R13 = _T("");
	m_replace_R2 = _T("");
	m_replace_R3 = _T("");
	m_replace_R4 = _T("");
	m_replace_R5 = _T("");
	m_replace_R6 = _T("");
	m_replace_R7 = _T("");
	m_replace_R8 = _T("");
	m_replace_R9 = _T("");
	m_sreplace_R1 = _T("Carton assembly line");
	m_sreplace_R10 = _T("");
	m_sreplace_R11 = _T("");
	m_sreplace_R12 = _T("");
	m_sreplace_R13 = _T("");
	m_sreplace_R2 = _T("");
	m_sreplace_R3 = _T("");
	m_sreplace_R4 = _T("");
	m_sreplace_R5 = _T("");
	m_sreplace_R6 = _T("");
	m_sreplace_R7 = _T("");
	m_sreplace_R8 = _T("");
	m_sreplace_R9 = _T("");
	m_csCurrentProduct = _T("");
	m_csStaticCartonName = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentColor = _T("");
	m_iRadioMainSource = 0;
	//}}AFX_DATA_INIT
}


void CCartonBoxPrint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCartonBoxPrint)
	DDX_Control(pDX, IDC_RADIO_CURRENT_CARTON, m_ctrRadioCurrentCarton);
	DDX_Control(pDX, IDC_RADIO_SPECIFIC_CARTON, m_ctrRadioSpecificCarton);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR_EX, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER_EX, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_BTN_PRINT_LABLE, m_btn_print);
	DDX_Text(pDX, IDC_EDIT_R1, m_replace_R1);
	DDX_Text(pDX, IDC_EDIT_R10, m_replace_R10);
	DDX_Text(pDX, IDC_EDIT_R11, m_replace_R11);
	DDX_Text(pDX, IDC_EDIT_R12, m_replace_R12);
	DDX_Text(pDX, IDC_EDIT_R13, m_replace_R13);
	DDX_Text(pDX, IDC_EDIT_R2, m_replace_R2);
	DDX_Text(pDX, IDC_EDIT_R3, m_replace_R3);
	DDX_Text(pDX, IDC_EDIT_R4, m_replace_R4);
	DDX_Text(pDX, IDC_EDIT_R5, m_replace_R5);
	DDX_Text(pDX, IDC_EDIT_R6, m_replace_R6);
	DDX_Text(pDX, IDC_EDIT_R7, m_replace_R7);
	DDX_Text(pDX, IDC_EDIT_R8, m_replace_R8);
	DDX_Text(pDX, IDC_EDIT_R9, m_replace_R9);
	DDX_Text(pDX, IDC_STATIC_R1, m_sreplace_R1);
	DDX_Text(pDX, IDC_STATIC_R10, m_sreplace_R10);
	DDX_Text(pDX, IDC_STATIC_R11, m_sreplace_R11);
	DDX_Text(pDX, IDC_STATIC_R12, m_sreplace_R12);
	DDX_Text(pDX, IDC_STATIC_R13, m_sreplace_R13);
	DDX_Text(pDX, IDC_STATIC_R2, m_sreplace_R2);
	DDX_Text(pDX, IDC_STATIC_R3, m_sreplace_R3);
	DDX_Text(pDX, IDC_STATIC_R4, m_sreplace_R4);
	DDX_Text(pDX, IDC_STATIC_R5, m_sreplace_R5);
	DDX_Text(pDX, IDC_STATIC_R6, m_sreplace_R6);
	DDX_Text(pDX, IDC_STATIC_R7, m_sreplace_R7);
	DDX_Text(pDX, IDC_STATIC_R8, m_sreplace_R8);
	DDX_Text(pDX, IDC_STATIC_R9, m_sreplace_R9);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_EDIT_CARTON_STATIC, m_csStaticCartonName);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER_EX, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR_EX, m_csCurrentColor);
	DDX_Radio(pDX, IDC_RADIO_MAIN_SOURCE, m_iRadioMainSource);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCartonBoxPrint, CDialog)
	//{{AFX_MSG_MAP(CCartonBoxPrint)
	ON_BN_CLICKED(IDC_BTN_PRINT_LABLE, OnBtnPrintLable)
	ON_BN_CLICKED(IDC_RADIO_CURRENT_CARTON, OnRadioCurrentCarton)
	ON_BN_CLICKED(IDC_RADIO_SPECIFIC_CARTON, OnRadioSpecificCarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCartonBoxPrint message handlers

BOOL CCartonBoxPrint::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_btn_print.SetIcon(IDI_ICON5);
	m_btn_print.SetActiveFgColor(RGB(0,0,255));

	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("Arial");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("Bold");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("Bold");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	//reset edit and static
	ResetControl();

	//获取config.ini路径
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CPACKView *pView=(CPACKView *)pMain->GetActiveView();
	this->m_csConfigPath.Format("%s%s_%s",pView->m_Config.m_csCFGPath,m_csCurrentProduct,m_csCurrentOrder);
	
	if(!LoadSign())
	{
		MessageBox("Load current product config.ini file Error!","Remind",MB_ICONERROR);
		return FALSE;
	}

	m_ctrRadioCurrentCarton.SetCheck(TRUE);

	this->m_csCartonName = this->m_replace_R1;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


CString CCartonBoxPrint::VariantToCString(VARIANT   var)
{   
	CString strValue;
	_variant_t var_t;
	_bstr_t bst_t;
	//time_t cur_time;
	CTime time_value;   
	COleCurrency var_currency; 
	COleDateTime cur_time;
    
	switch(var.vt)   
	{   
	case   VT_EMPTY:   
		strValue   =   _T("");   
		break;   
	case   VT_UI1:   
		strValue.Format("%d",var.bVal);   
		break;   
	case   VT_I2:   
		strValue.Format("%d",var.iVal);   
		break;   
	case   VT_I4:   
		strValue.Format("%d",var.lVal);   
		break;   
	case   VT_R4:   
		strValue.Format("%f",var.fltVal);   
		break;   
	case   VT_R8:   
		strValue.Format("%f",var.dblVal);   
		break;   
	case   VT_CY:   
		var_currency   =   var;   
		strValue   =   var_currency.Format(0);   
		break;   
	case   VT_BSTR:   
		var_t   =   var;   
		bst_t   =   var_t;   
		strValue.Format   ("%s",(const   char*)bst_t);   
		break;   
	case   VT_NULL:   
		strValue   =   _T("");   
		break;   
	case   VT_DATE:   
		//cur_time   =   (long)var.date;   
		// time_value   =   cur_time;   
		// strValue   =   time_value.Format("%Y-%m-%d");  
		cur_time   =   var; 
		strValue   =   cur_time.Format("%Y-%m-%d"); 
		break;   
	case   VT_BOOL:   
		strValue.Format("%d",var.boolVal   );   
		break;   
	default:     
		strValue   =   _T("");
		break;   
	}   
	return   strValue;   
}


BOOL CCartonBoxPrint::LoadSign()
{
	/*lucky
	GetPrivateProfileString("CARTONDISPLACE","Replace_R2R","config.iniError!",m_sreplace_R2.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R2.ReleaseBuffer();
	if(m_sreplace_R2=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R3R","config.iniError!",m_sreplace_R3.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R3.ReleaseBuffer();
	if(m_sreplace_R3=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R4R","config.iniError!",m_sreplace_R4.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R4.ReleaseBuffer();
	if(m_sreplace_R4=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R5R","config.iniError!",m_sreplace_R5.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R5.ReleaseBuffer();
	if(m_sreplace_R5=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R6R","config.iniError!",m_sreplace_R6.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R6.ReleaseBuffer();
	if(m_sreplace_R6=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R7R","config.iniError!",m_sreplace_R7.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R7.ReleaseBuffer();
	if(m_sreplace_R7=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R8R","config.iniError!",m_sreplace_R8.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R8.ReleaseBuffer();
	if(m_sreplace_R8=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R9R","config.iniError!",m_sreplace_R9.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R9.ReleaseBuffer();
	if(m_sreplace_R9=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R10R","config.iniError!",m_sreplace_R10.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R10.ReleaseBuffer();
	if(m_sreplace_R10=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R11R","config.iniError!",m_sreplace_R11.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R11.ReleaseBuffer();
	if(m_sreplace_R11=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R12R","config.iniError!",m_sreplace_R12.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R12.ReleaseBuffer();
	if(m_sreplace_R12=="config.iniError!")
		return FALSE;

	GetPrivateProfileString("CARTONDISPLACE","Replace_R13R","config.iniError!",m_sreplace_R13.GetBuffer(MAX_PATH),MAX_PATH,m_csConfigPath+"\\config\\config.ini");
	m_sreplace_R13.ReleaseBuffer();
	if(m_sreplace_R13=="config.iniError!")
		return FALSE;

	if(m_sreplace_R2!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R2))->EnableWindow(TRUE);
	else
		m_sreplace_R2=_T("");

	if(m_sreplace_R3!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R3))->EnableWindow(TRUE);
	else
		m_sreplace_R3=_T("");

	if(m_sreplace_R4!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R4))->EnableWindow(TRUE);
	else
		m_sreplace_R4=_T("");

	if(m_sreplace_R5!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R5))->EnableWindow(TRUE);
	else
		m_sreplace_R5=_T("");

	if(m_sreplace_R6!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R6))->EnableWindow(TRUE);
	else
		m_sreplace_R6=_T("");

	if(m_sreplace_R7!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R7))->EnableWindow(TRUE);
	else
		m_sreplace_R7=_T("");

	if(m_sreplace_R8!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R8))->EnableWindow(TRUE);
	else
		m_sreplace_R8=_T("");

	if(m_sreplace_R9!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R9))->EnableWindow(TRUE);
	else
		m_sreplace_R9=_T("");

	if(m_sreplace_R10!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R10))->EnableWindow(TRUE);
	else
		m_sreplace_R10=_T("");

	if(m_sreplace_R11!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R11))->EnableWindow(TRUE);
	else
		m_sreplace_R11=_T("");

	if(m_sreplace_R12!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R12))->EnableWindow(TRUE);
	else
		m_sreplace_R12=_T("");

	if(m_sreplace_R13!="0")
		((CStatic*)GetDlgItem(IDC_EDIT_R13))->EnableWindow(TRUE);
	else
		m_sreplace_R13=_T("");

	UpdateData(FALSE);
	*/  
	return TRUE;
}


void CCartonBoxPrint::ResetControl()
{
//	m_replace_R1  = _T("");
	m_replace_R2  = _T("");
	m_replace_R3  = _T("");
	m_replace_R4  = _T("");
	m_replace_R5  = _T("");
	m_replace_R6  = _T("");
	m_replace_R7  = _T("");
	m_replace_R8  = _T("");
	m_replace_R9  = _T("");
	m_replace_R10 = _T("");
	m_replace_R11 = _T("");
	m_replace_R12 = _T("");
	m_replace_R13 = _T("");
	m_sreplace_R1  = _T("Carton assembly line");
	m_sreplace_R2  = _T("");
	m_sreplace_R3  = _T("");
	m_sreplace_R4  = _T("");
	m_sreplace_R5  = _T("");
	m_sreplace_R6  = _T("");
	m_sreplace_R7  = _T("");
	m_sreplace_R8  = _T("");
	m_sreplace_R9  = _T("");
	m_sreplace_R10 = _T("");
	m_sreplace_R11 = _T("");
	m_sreplace_R12 = _T("");
	m_sreplace_R13 = _T("");
	UpdateData(FALSE);
	
	((CWnd*)GetDlgItem(IDC_EDIT_R2))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R3))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R4))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R5))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R6))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R7))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R8))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R9))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R10))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R11))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R12))->EnableWindow(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R13))->EnableWindow(FALSE);
}


void CCartonBoxPrint::OnBtnPrintLable() 
{
	CString temp;
	UpdateData();

	//reset
	m_csaIMEI1.RemoveAll();
	m_csaIMEI2.RemoveAll();
	m_csaIMEI3.RemoveAll();
	m_csaIMEI4.RemoveAll();
	m_csaSN.RemoveAll();
	m_csaPSN.RemoveAll();
	m_csaBT.RemoveAll();
	m_csaMAC.RemoveAll();
	m_csaWeigh.RemoveAll();
	m_csaNet.RemoveAll();

	if(m_replace_R1.IsEmpty())
	{
		MessageBox("Carton assembly line Can't be Empty!","Remind",MB_ICONQUESTION);
		((CWnd*)GetDlgItem(IDC_EDIT_R1))->SetFocus();
		return;
	}

	if(!m_sreplace_R2.IsEmpty())
	{
		if(m_replace_R2.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R2);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R2))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R3.IsEmpty())
	{
		if(m_replace_R3.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R3);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R3))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R4.IsEmpty())
	{
		if(m_replace_R4.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R4);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R4))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R5.IsEmpty())
	{
		if(m_replace_R5.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R5);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R5))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R6.IsEmpty())
	{
		if(m_replace_R6.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R6);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R6))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R7.IsEmpty())
	{
		if(m_replace_R7.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R7);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R7))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R8.IsEmpty())
	{
		if(m_replace_R8.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R8);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R8))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R9.IsEmpty())
	{
		if(m_replace_R9.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R9);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R9))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R10.IsEmpty())
	{
		if(m_replace_R10.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R10);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R10))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R11.IsEmpty())
	{
		if(m_replace_R11.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R11);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R11))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R12.IsEmpty())
	{
		if(m_replace_R12.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R12);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R12))->SetFocus();
			return;
		}
	}

	if(!m_sreplace_R13.IsEmpty())
	{
		if(m_replace_R13.IsEmpty())
		{
			temp.Format("\"%s\" Can't be Empty!",m_sreplace_R13);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			((CWnd*)GetDlgItem(IDC_EDIT_R13))->SetFocus();
			return;
		}
	}

	if(!CheckCartonName()) //检测箱号是否有效及是否封箱
	{
		return;
	}

	//获取卡通箱号打印次数
	if(!CheckLabelCount())
	{
		return;
	}

	//判断打印次数
	if(0 != m_iLabelCount)
	{
		if(this->m_iRadioMainSource == MAIN_SOURCE)
		{
			temp.Format("The number of printed %d carton! Please enter the password to continue printing",m_iLabelCount);
			MessageBox(temp,"Remind",MB_ICONQUESTION);
			
			CPassword psw;
			psw.ilevel = 0; //需普通权限验证
			if(IDOK!=psw.DoModal())
				return;
		}
	}

	if(!GetDataInfo()) //根据箱号获取相应数据
	{
		return;
	}

	if(!ReplaceResource()) //替换资源
	{
		return;
	}

	if(!GoToPrint()) //打印资源
		return;

	//更新打印次数
	this->m_iLabelCount += 1;
	if(!UpdateLabelCount())
		return;
}


bool CCartonBoxPrint::CheckCartonName()
{
	CString temp;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_replace_R1);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			temp.Format("Invalid number \'%s\' !",m_replace_R1);
			MessageBox(temp,"Remind",MB_ICONHAND);
			return FALSE;
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}
	
	return TRUE;
}


bool CCartonBoxPrint::GetDataInfo()
{
	CString sql;
	CString temp;
	_variant_t var;

	try
	{
		sql.Format("select * from ProductList where OrderName='%s' and Enable=1",this->m_csCurrentOrder);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CustomerNo");
			m_csCustomerNo=VariantToCString(var);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_replace_R1);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("datetime");
			m_csaShippingDate=VariantToCString(var);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}

	m_csBatchNo = m_csCustomerNo + m_csaShippingDate.Mid(2,2) + m_csaShippingDate.Mid(5,2) + m_csaShippingDate.Right(2);
	
	try
	{
		sql.Format("select * from %s_%s_ColorBox where CartonName='%s' and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_replace_R1);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
			temp=VariantToCString(var);
			m_csaIMEI1.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
			temp=VariantToCString(var);
			m_csaIMEI2.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
			temp=VariantToCString(var);
			m_csaIMEI3.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4");
			temp=VariantToCString(var);
			m_csaIMEI4.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			temp=VariantToCString(var);
			m_csaSN.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			temp=VariantToCString(var);
			m_csaPSN.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			temp=VariantToCString(var);
			m_csaBT.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			temp=VariantToCString(var);
			m_csaMAC.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
			temp=VariantToCString(var);
			m_csaWeigh.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			temp=VariantToCString(var);
			m_csaNet.Add(temp);

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}

	for (int i=0; i<m_csaIMEI1.GetSize(); i++)
	{
		sql.Format("UPDATE %s_%s_ProductionLine SET Pack='%s', CartonName='%s',CartonDate=getdate() where IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
			this->csCurrentLine,m_replace_R1,this->m_csaIMEI1[i]);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
			return FALSE;
		}
	}

	return TRUE;
}


BOOL CCartonBoxPrint::ReplaceResource()
{
	CStdioFile fp;
	CStdioFile fp1;
	CString temp;
	CString sTp;
	CString CommandBuff;
	CString csSourcePath;

	temp.Empty();
	CommandBuff.Empty();
	sTp.Empty();
	csSourcePath.Empty();
	
	switch (this->m_iRadioMainSource)
	{
	case MAIN_SOURCE:
		csSourcePath=this->csLocalPathtemp+"\\CartonResource.txt";
		break;
	case SUB_SOURCE:
		csSourcePath=this->csLocalPathtemp+"\\CartonResource_Sub.txt";
		break;
	default :
		csSourcePath=this->csLocalPathtemp+"\\CartonResource.txt";
		break;
	}

	if (!fp.Open(csSourcePath,CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The type of carton resource file not found, please contact the Engineer!","Remind",MB_ICONHAND);
		return FALSE;
	}
	else
	{
		while(fp.ReadString(temp))
		{
			if(temp.Find("X1X")!=-1)
			{
				temp.Replace("X1X",m_csStaticCartonName+m_replace_R1+this->Calculate_Random());
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R1R")!=-1)
			{
				temp.Replace("R1R",m_csStaticCartonName+m_replace_R1);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("T1T")!=-1)
			{
				temp.Replace("T1T",m_csBatchNo);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R2R")!=-1)
			{
				temp.Replace("R2R",m_replace_R2);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R3R")!=-1)
			{
				temp.Replace("R3R",m_replace_R3);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R4R")!=-1)
			{
				temp.Replace("R4R",m_replace_R4);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R5R")!=-1)
			{
				temp.Replace("R5R",m_replace_R5);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R6R")!=-1)
			{
				temp.Replace("R6R",m_replace_R6);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R7R")!=-1)
			{
				temp.Replace("R7R",m_replace_R7);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R8R")!=-1)
			{
				temp.Replace("R8R",m_replace_R8);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R9R")!=-1)
			{
				temp.Replace("R9R",m_replace_R9);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R10R")!=-1)
			{
				temp.Replace("R10R",m_replace_R10);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R11R")!=-1)
			{
				temp.Replace("R11R",m_replace_R11);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R12R")!=-1)
			{
				temp.Replace("R12R",m_replace_R12);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("R13R")!=-1)
			{
				temp.Replace("R13R",m_replace_R13);
				CommandBuff+=temp;
				continue;
			}
			
			//支持S4M Zebra打印机资源 begin
			if(temp.Find("XC1X")!=-1)
			{
				temp.Replace("XC1X",m_csStaticCartonName+m_replace_R1+">6"+this->Calculate_Random());
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC1R")!=-1)
			{
				temp.Replace("RC1R",m_csStaticCartonName+m_replace_R1.Left(m_replace_R1.GetLength()-1)+">6"+m_replace_R1.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("TC1T")!=-1)
			{
				temp.Replace("TC1T",m_csBatchNo.Left(m_csBatchNo.GetLength()-1)+">6"+m_csBatchNo.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC2R")!=-1)
			{
				temp.Replace("RC2R",m_replace_R2.Left(m_replace_R2.GetLength()-1)+">6"+m_replace_R2.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC3R")!=-1)
			{
				temp.Replace("RC3R",m_replace_R3.Left(m_replace_R3.GetLength()-1)+">6"+m_replace_R3.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC4R")!=-1)
			{
				temp.Replace("RC4R",m_replace_R4.Left(m_replace_R4.GetLength()-1)+">6"+m_replace_R4.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC5R")!=-1)
			{
				temp.Replace("RC5R",m_replace_R5.Left(m_replace_R5.GetLength()-1)+">6"+m_replace_R5.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC6R")!=-1)
			{
				temp.Replace("RC6R",m_replace_R6.Left(m_replace_R6.GetLength()-1)+">6"+m_replace_R6.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC7R")!=-1)
			{
				temp.Replace("RC7R",m_replace_R7.Left(m_replace_R7.GetLength()-1)+">6"+m_replace_R7.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC8R")!=-1)
			{
				temp.Replace("RC8R",m_replace_R8.Left(m_replace_R8.GetLength()-1)+">6"+m_replace_R8.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC9R")!=-1)
			{
				temp.Replace("RC9R",m_replace_R9.Left(m_replace_R9.GetLength()-1)+">6"+m_replace_R9.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC10R")!=-1)
			{
				temp.Replace("RC10R",m_replace_R10.Left(m_replace_R10.GetLength()-1)+">6"+m_replace_R10.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC11R")!=-1)
			{
				temp.Replace("RC11R",m_replace_R11.Left(m_replace_R11.GetLength()-1)+">6"+m_replace_R11.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC12R")!=-1)
			{
				temp.Replace("RC12R",m_replace_R12.Left(m_replace_R12.GetLength()-1)+">6"+m_replace_R12.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("RC13R")!=-1)
			{
				temp.Replace("RC13R",m_replace_R13.Left(m_replace_R13.GetLength()-1)+">6"+m_replace_R13.Right(1));
				CommandBuff+=temp;
				continue;
			}
			//支持S4M Zebra打印机资源 end
			CommandBuff+=temp;
		}
		fp.Close();

		//如果不满箱子那么增加空数据到数组
		int icurrentSize=0;
		icurrentSize = this->m_csaIMEI1.GetSize();
		if(this->m_iMaxCount != icurrentSize)
		{
			for(int a=icurrentSize ;a<this->m_iMaxCount ;a++)
			{
				this->m_csaIMEI1.Add("");
				this->m_csaIMEI2.Add("");
				this->m_csaIMEI3.Add("");
				this->m_csaIMEI4.Add("");
				this->m_csaSN.Add("");
				this->m_csaPSN.Add("");
				this->m_csaBT.Add("");
				this->m_csaMAC.Add("");
				this->m_csaWeigh.Add("");
				this->m_csaNet.Add("");
			}
		}
		
		for(int i=0;i<this->m_csaIMEI1.GetSize();i++)
		{
			sTp.Format("!%d!",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI1.GetAt(i));
			
			sTp.Format("@%d@",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI2.GetAt(i));
			
			sTp.Format("#%d#",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI3.GetAt(i));
			
			sTp.Format("$%d$",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI4.GetAt(i));
			
			sTp.Format("&%d&",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaSN.GetAt(i));
			
			sTp.Format("*%d*",i+1);
			if(CommandBuff.Find(sTp)!=-1)
			{
				if (bPSNStatic == TRUE)  
				{
					//PSN明码只打印流水位
					CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i).Right(this->m_csaPSN.GetAt(i).GetLength() - this->csPSNStatic.GetLength()));
				}
				else
				{
					CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i));
				}
			}
			
			sTp.Format("(%d(",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaBT.GetAt(i));
			
			sTp.Format(")%d)",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaMAC.GetAt(i));
			
			sTp.Format("+%d+",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaWeigh.GetAt(i));
			
			
			//支持S4M Zebra打印机资源 begin
			sTp.Format("!C%d!",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI1.GetAt(i).Left(this->m_csaIMEI1.GetAt(i).GetLength()-1)+">6"+this->m_csaIMEI1.GetAt(i).Right(1));
			
			sTp.Format("@C%d@",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI2.GetAt(i).Left(this->m_csaIMEI2.GetAt(i).GetLength()-1)+">6"+this->m_csaIMEI2.GetAt(i).Right(1));
			
			sTp.Format("#C%d#",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI3.GetAt(i).Left(this->m_csaIMEI3.GetAt(i).GetLength()-1)+">6"+this->m_csaIMEI3.GetAt(i).Right(1));
			
			sTp.Format("$C%d$",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaIMEI4.GetAt(i).Left(this->m_csaIMEI4.GetAt(i).GetLength()-1)+">6"+this->m_csaIMEI4.GetAt(i).Right(1));
			
			sTp.Format("&C%d&",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaSN.GetAt(i).Left(this->m_csaSN.GetAt(i).GetLength()-1)+">6"+this->m_csaSN.GetAt(i).Right(1));
			
			sTp.Format("*C%d*",i+1);
			if(CommandBuff.Find(sTp)!=-1)
			{
				char   ch;
				int    ilen = 0;           //PSN总长度
				int    isite[20];          //PSN中字母的位数
				int    iNum = 0;           //PSN中字母的个数
				CString cstmp;
				
				//获取PSN总长度
				ilen = this->m_csaPSN.GetAt(i).GetLength();
				
				//获取PSN中所有字母位数
				for(int i=0;i<ilen;i++)
				{
					ch = this->m_csaPSN.GetAt(i).GetAt(i);
					
					if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) //字母
					{
						isite[iNum] = i;
						iNum++;
					}
				}
				
				if (isite[0] == 0)    //PSN第一个字符为字母
				{
					CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i).Left(this->m_csaPSN.GetAt(i).GetLength()-1)+">6"+this->m_csaPSN.GetAt(i).Right(1));
				}
				else if (iNum == 0)   //PSN全部为数字
				{
					CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i).Left(this->m_csaPSN.GetAt(i).GetLength()-1)+">6"+this->m_csaPSN.GetAt(i).Right(1));
				}
				else  if(isite[0] != 0 && iNum != 0)     //PSN第一个字符不为字母并且PSN中包含字母
				{
					int j = 0;
					cstmp = this->m_csaPSN.GetAt(i);
					for(i=0;i<iNum;i++)
					{   
						cstmp.Insert((isite[i]+2*j),">6");
						cstmp.Insert((isite[i]+1+2*(j+1)),">5");
						j+=2;
					}
					cstmp.Insert(ilen+4*iNum-1,">6");
				
					CommandBuff.Replace(sTp,cstmp);
				}
			}
			//CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i).Left(this->m_csaPSN.GetAt(i).GetLength()-1)+">6"+this->m_csaPSN.GetAt(i).Right(1));
			//CommandBuff.Replace(sTp,this->m_csaPSN.GetAt(i).Left(6)+">6"+this->m_csaPSN.GetAt(i).Mid(6,1)+">5"+this->m_csaPSN.GetAt(i).Mid(7,4)+">6"+m_csaPSN.GetAt(i).Right(1));
			
			sTp.Format("(C%d(",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaBT.GetAt(i).Left(this->m_csaBT.GetAt(i).GetLength()-1)+">6"+this->m_csaBT.GetAt(i).Right(1));
			
			sTp.Format(")C%d)",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaMAC.GetAt(i).Left(this->m_csaMAC.GetAt(i).GetLength()-1)+">6"+this->m_csaMAC.GetAt(i).Right(1));
			
			sTp.Format("+C%d+",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaWeigh.GetAt(i).Left(this->m_csaWeigh.GetAt(i).GetLength()-1)+">6"+this->m_csaWeigh.GetAt(i).Right(1));
		
			sTp.Format("^%d^",i+1);
			   if(CommandBuff.Find(sTp)!=-1)
				   CommandBuff.Replace(sTp,this->m_csaNet.GetAt(i));

			//支持S4M Zebra打印机资源 end
		}

		fp1.Open("c:\\resource.txt",CFile::modeWrite | CFile::typeBinary | CFile::modeCreate);
		fp1.WriteString(CommandBuff);
		fp1.Close();
	}

	return TRUE;
}


BOOL CCartonBoxPrint::GoToPrint()
{
	ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE);
	return TRUE;
}


char CCartonBoxPrint::Calculate_Random()
{
	int random=0;
	for(int a=0 ; a< this->m_replace_R1.GetLength() ; a++)
	{
		random+=this->m_replace_R1.GetAt(a) - 48;
	}
	
	random = (random*3)%10;

	char value = random+48;
	return value;
}


bool CCartonBoxPrint::CheckLabelCount()
{
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_replace_R1);  //@@ Call storage course @@
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("LabelPrintCount");
			this->m_iLabelCount = var.intVal;

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}

	return TRUE;
}


bool CCartonBoxPrint::UpdateLabelCount()
{
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("UPDATE %s_%s_CartonBox SET LabelPrintCount = %d where CartonName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_iLabelCount,this->m_replace_R1);
		((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Remind",MB_ICONQUESTION);
		return FALSE;
	}

	return TRUE;
}


void CCartonBoxPrint::OnRadioCurrentCarton()
{
	// TODO: Add your control notification handler code here
	m_replace_R1 = this->m_csCartonName;
	UpdateData(FALSE);
	m_ctrRadioCurrentCarton.SetCheck(TRUE);
	m_ctrRadioSpecificCarton.SetCheck(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->EnableWindow(FALSE);
}


void CCartonBoxPrint::OnRadioSpecificCarton()
{
	// TODO: Add your control notification handler code here
	m_replace_R1.Empty();
	UpdateData(FALSE);
	m_ctrRadioSpecificCarton.SetCheck(TRUE);
	m_ctrRadioCurrentCarton.SetCheck(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->EnableWindow(TRUE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->SetFocus();
}
