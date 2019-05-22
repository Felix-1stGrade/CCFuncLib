/**
* @file       WarningList.h
* @brief      告警列表
* @details
* @author     Lu Peng
* @date       2019-03-21
* @version    /
* @par Copyright (c): 2016-2019 xxx. All rights reserved.
*/
//#include "stdafx.h"
#include "WarningList.hpp"
#include "VOS_DataType.hpp"
#include <time.h>
#include <windows.h> 
#include <string>

CWarningList::CWarningList(void)
{
	CurrentList.clear();
	HistoryList.clear();

	CurrentListChanged = false;
	HistoryListChanged = false;
}

CWarningList::~CWarningList(void)
{
	CurrentList.clear();
	HistoryList.clear();
}

void CWarningList::Clear(void)
{
	CurrentList.clear();
	HistoryList.clear();
}

void CWarningList::Init(void)
{
	CurrentList.clear();
	HistoryList.clear();

	CurrentListChanged = false;
	HistoryListChanged = false;
}

void CWarningList::Add(string Id)
{
	SYSTEMTIME NowTime;
	GetLocalTime(&NowTime);

	std::list<SCurrentWarningItem>::iterator CWL_it;
	for (CWL_it = CurrentList.begin(); CWL_it != CurrentList.end(); CWL_it++)
	{
		if (CWL_it->Id == Id)
		{
			return;
		}
	}

	INT16 i;
	for (i = 0; i < sizeof(WarningMap) / sizeof(SWarningItem); i++)
	{
		if (WarningMap[i].Id == Id)
		{
			break;
		}
	}

	if (i >= sizeof(WarningMap) / sizeof(SWarningItem))
	{
		return;
	}

	TempCWI.Id = WarningMap[i].Id;
	TempCWI.Name = WarningMap[i].Name;
	TempCWI.Detail = WarningMap[i].Detail;
	TempCWI.Level = WarningMap[i].Level;
	TempCWI.FailedPart = WarningMap[i].FailedPart;
	TempCWI.Source = WarningMap[i].Source;
	TempCWI.AppearanceTime = to_string(NowTime.wYear) + "/" + to_string(NowTime.wMonth) + "/" + to_string(NowTime.wDay) + " "
		+ to_string(NowTime.wHour) + ":" + to_string(NowTime.wMinute) + ":" + to_string(NowTime.wSecond) + "." + to_string(NowTime.wMilliseconds);

	CurrentList.push_back(TempCWI);
	CurrentListChanged = true;
}

void CWarningList::Delete(string Id)
{
	SYSTEMTIME NowTime;
	GetLocalTime(&NowTime);

	std::list<SCurrentWarningItem>::iterator CWL_it;
	for (CWL_it = CurrentList.begin(); CWL_it != CurrentList.end(); CWL_it++)
	{
		if (CWL_it->Id == Id)
		{
			break;
		}
	}

	if (CWL_it == CurrentList.end())
	{
		return;
	}

	TempHWI.Id = CWL_it->Id;
	TempHWI.Name = CWL_it->Name;
	TempHWI.Detail = CWL_it->Detail;
	TempHWI.Level = CWL_it->Level;
	TempHWI.FailedPart = CWL_it->FailedPart;
	TempHWI.Source = CWL_it->Source;
	TempHWI.AppearanceTime = CWL_it->AppearanceTime;
	TempHWI.DisappearanceTime = to_string(NowTime.wYear) + "/" + to_string(NowTime.wMonth) + "/" + to_string(NowTime.wDay) + " "
		+ to_string(NowTime.wHour) + ":" + to_string(NowTime.wMinute) + ":" + to_string(NowTime.wSecond) + "." + to_string(NowTime.wMilliseconds);

	//CurrentList.remove_if([Id](SCurrentWarningItem Item){return Item.Id == Id;});
	CurrentList.erase(CWL_it);
	CurrentListChanged = true;

	HistoryList.push_back(TempHWI);
	HistoryListChanged = true;
}

// 清空历史告警列表
void CWarningList::ClearHistoryList(void)
{
	HistoryList.clear();
}

CWarningList WarningList;

/// end of file