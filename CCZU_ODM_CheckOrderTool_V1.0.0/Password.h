#if !defined(AFX_PASSWORD_H__5ECC3D32_385B_4E7C_854D_2C6B6085AB81__INCLUDED_)
#define AFX_PASSWORD_H__5ECC3D32_385B_4E7C_854D_2C6B6085AB81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Password.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassword dialog

class CPassword : public CDialog
{
// Construction
public:
	CPassword(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPassword)
	enum { IDD = IDD_DLG_PASSWORD };
	CEdit	m_ctrUserName;
	CEdit	m_ctrPassword;
	CString	m_csPassword;
	CString	m_csUserName;
	//}}AFX_DATA

public:
	int ilevel;   //权限等级控制


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassword)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPassword)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORD_H__5ECC3D32_385B_4E7C_854D_2C6B6085AB81__INCLUDED_)
