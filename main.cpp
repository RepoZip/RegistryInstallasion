#include<stdio.h>
#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{	
	HKEY hkey, skey;
	LONG rs1, rs2, rset;
	string val = "C:\\Users\\Kelum Deshapriya\\Documents\\Visual Studio 2010\\Projects\\RightClickServer\\Debug\\RightClickServer.exe \"%1\"";

	//rs1 = RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT("txtfile\\shell\\RepoZip"),0,KEY_ALL_ACCESS,&hkey);
	rs1 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("docxfile\\shell\\RepoZip"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&hkey,NULL);
	if(rs1!=ERROR_SUCCESS)
	{
		MessageBox(0,"Error Opening first Registry Key","Error",0);
	}else{
		MessageBox(0,"susccessfully create/open first registry key","Error",0);
		rs2 = RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("txtfile\\shell\\RepoZip\\command"),0,NULL,REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,NULL,&skey,NULL);
		if(rs2!=ERROR_SUCCESS)
		{
			MessageBox(0,"Error Opening second Registry Key","Error",0);
		}else{
			MessageBox(0,"susccessfully create/open second registry key","Error",0);
			rset = RegSetValueEx(skey, 0, 0, REG_SZ,(LPBYTE) val.c_str() ,val.length());
			if(rs2!=ERROR_SUCCESS)
			{
				MessageBox(0,"Error setting value to second Registry Key","Error",0);
			}else{
				MessageBox(0,"susccessfully set value to second registry key","Error",0);
			}
			RegCloseKey(skey);
		}
		RegCloseKey(hkey);

	}
	return 0;
}
