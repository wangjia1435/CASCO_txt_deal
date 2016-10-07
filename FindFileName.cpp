// FindFileName.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
void TraverseFolder(LPCTSTR lpPath);

int _tmain(int argc, _TCHAR* argv[])
{
	TraverseFolder("D:\\ResearchContent\\Exercise_Programm\\CogCount\\TEST");
	//system("pause");
	return 0;
}

//�����ļ��к���
void TraverseFolder(LPCTSTR lpPath)
{

    TCHAR szFind[MAX_PATH] = {_T("\0")};
    WIN32_FIND_DATA findFileData;
    BOOL bRet;
 
    _tcscpy_s(szFind, MAX_PATH, lpPath);
    _tcscat_s(szFind, _T("\\*.*"));     //����һ��Ҫָ��ͨ�������Ȼ�����ȡ�����ļ���Ŀ¼
 
    HANDLE hFind = ::FindFirstFile(szFind, &findFileData);
    if (INVALID_HANDLE_VALUE == hFind)
    {
		printf_s("maybe file director error");
        return;
    }
 
    //�����ļ���
    while (TRUE)
    {
        if (findFileData.cFileName[0] != _T('.'))
        {//���ǵ�ǰ·�����߸�Ŀ¼�Ŀ�ݷ�ʽ
            _tprintf(_T("%s\\%s\n"), lpPath, findFileData.cFileName);
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {//����һ����ͨĿ¼
                //������һ����Ҫɨ����ļ���·��
                _tcscpy_s(szFind, MAX_PATH, lpPath);    
                _tcscat_s(szFind, _T("\\"));    
                _tcscat_s(szFind, findFileData.cFileName);
                ///_tcscat_s(szNextDir, _T("\\*"));
                //������Ŀ¼
                TraverseFolder(szFind);
            }
        }
        //����ǵ�ǰ·�����߸�Ŀ¼�Ŀ�ݷ�ʽ����������ͨĿ¼����Ѱ����һ��Ŀ¼�����ļ�
        bRet = ::FindNextFile(hFind, &findFileData);
        if (!bRet)
        {//��������ʧ��
            //cout << "FindNextFile failed, error code: " 
            //  << GetLastError() << endl;
            break;
        }
    }
 
    ::FindClose(hFind);
}