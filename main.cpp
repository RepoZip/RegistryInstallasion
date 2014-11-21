#include<stdio.h>
#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{	
	HKEY hkey, skey;
	LONG rs1, rs2, rset;
	string val = "C:\\Users\\Kelum Deshapriya\\Documents\\Visual Studio 2010\\Projects\\RightClickServer\\Debug\\RightClickServer.exe \"%1\"";

	// add right click option to docx file
	//rs1 = RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT("txtfile\\shell\\RepoZip"),0,KEY_ALL_ACCESS,&hkey);
	rs1 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("Word.Document.12\\shell\\RepoZip"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&hkey,NULL);
	if(rs1!=ERROR_SUCCESS)
	{
		MessageBox(0,"Error Opening docx Registry Key","Error",0);
	}else{
		MessageBox(0,"susccessfully create/open docx registry key","Error",0);
		rs2 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("Word.Document.12\\shell\\RepoZip\\command"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&skey,NULL);
		if(rs2!=ERROR_SUCCESS)
		{
			MessageBox(0,"Error Opening command of docx Registry Key","Error",0);
		}else{
			MessageBox(0,"susccessfully create/open command of docx registry key","Error",0);
			rset = RegSetValueEx(skey, 0, 0, REG_SZ,(LPBYTE) val.c_str() ,val.length());
			if(rs2!=ERROR_SUCCESS)
			{
				MessageBox(0,"Error setting value to command of docx Registry Key","Error",0);
			}else{
				MessageBox(0,"susccessfully set value to command of docx registry key","Error",0);
			}
			RegCloseKey(skey);
		}
		RegCloseKey(hkey);
	}
	
	// add rigt click option to folder
	rs1 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("Folder\\shell\\RepoZip"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&hkey,NULL);
	if(rs1!=ERROR_SUCCESS)
	{
		MessageBox(0,"Error Opening folder Registry Key","Error",0);
	}else{
		MessageBox(0,"susccessfully create/open folder registry key","Error",0);
		rs2 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("Folder\\shell\\RepoZip\\command"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&skey,NULL);
		if(rs2!=ERROR_SUCCESS)
		{
			MessageBox(0,"Error Opening command of floder Registry Key","Error",0);
		}else{
			MessageBox(0,"susccessfully create/open command of folder registry key","Error",0);
			rset = RegSetValueEx(skey, 0, 0, REG_SZ,(LPBYTE) val.c_str() ,val.length());
			if(rs2!=ERROR_SUCCESS)
			{
				MessageBox(0,"Error setting value to command of folder Registry Key","Error",0);
			}else{
				MessageBox(0,"susccessfully set value to command of folder registry key","Error",0);
			}
			RegCloseKey(skey);
		}
		RegCloseKey(hkey);
	}
	return 0;
}
