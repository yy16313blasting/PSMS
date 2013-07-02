#include "stdafx.h"
#include "Record.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Record record;
	record.SetTitle("Hello");
	cout<<record.GetContent()<<endl;
	getchar();
	return 0;
}