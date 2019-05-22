#include <regex>  
#include <string>  
#include <vector>  
#include <list>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include "CfgFileParser.hpp"
#include "WarningList.hpp"


int main()
{
	// CfgFileParser测试
	std::string config = "<component1hardver>AA</component1hardver><softwareversion> V180 </softwareversion><hardwareversion>  A</hardwareversion><model>TBM12-2000</model><code>02600002</code><barcode>210229035410g70005</barcode><component1bin>TBM12-2000.bin</component1bin><component1softver>V167</component1softver>";

	CfgFileParser.ParseSource(config);

	std::cout << CfgFileParser.GetModel() << std::endl;
	std::cout << CfgFileParser.GetCode() << std::endl;
	std::cout << CfgFileParser.GetBarcode() << std::endl;
	std::cout << CfgFileParser.GetHardwareVersion() << std::endl;
	std::cout << CfgFileParser.GetSoftwareVersion() << std::endl;
	std::cout << CfgFileParser.GetComponent1HardVer() << std::endl;
	std::cout << CfgFileParser.GetComponent1SoftVer() << std::endl;
	std::cout << CfgFileParser.GetComponent1Bin() << std::endl;

	// WarningList测试
	std::list <int> List;
	string TempCWI;
	string TempHWI;
	WarningList.Init();
	TempCWI = "0001-01";
	WarningList.Add(TempCWI);
	WarningList.Delete("0001-01");
	WarningList.Add("0008-01");
	WarningList.Add("0005-03");
	WarningList.ClearHistoryList();
	WarningList.Clear();

	// list测试
	List.push_back(1);
	List.push_back(2);
	List.push_back(3);
	//List.remove(2);
	int y = 2;
	List.remove_if([y](int n){return n == y; });

	// vector测试
	int x = 5;
	std::vector<int> c{ 1, 2, 3, 4, 5, 6, 7 };
	remove_if(c.begin(), c.end(), [x](int n){return n < x; });
	cout << "c: ";
	for (auto i : c){
		cout << i << ' ';
	}
	c.erase(remove_if(c.begin(), c.end(), [x](int n){return n < x; }), c.end());

	// 获取系统时间，精确到ms
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("\n %4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d \n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);

	string S = to_string(sys.wYear) + "." + to_string(sys.wMonth) + "." + to_string(sys.wDay) + " "
		+ to_string(sys.wHour) + ":" + to_string(sys.wMinute) + ":" + to_string(sys.wSecond) + "." + to_string(sys.wMilliseconds);
	std::cout << S << endl;

	return 0;

}