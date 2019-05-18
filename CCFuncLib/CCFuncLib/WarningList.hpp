/**
* @file       WarningList.h
* @brief      告警列表
* @details
* @author     Lu Peng
* @date       2019-03-21
* @version    /
* @par Copyright (c): 2016-2019 xxx. All rights reserved.
*/
#ifndef WARNINGLIST_H
#define WARNINGLIST_H

//#include "stdafx.h"
#include <list>

using namespace std;

typedef struct
{
	string Id;        ///< 告警ID
	string Name;      ///< 告警名称
	string Detail;    ///< 告警详细名称
	string Level;     ///< 告警等级
	string FailedPart;///< 失效部件
	string Source;    ///< 检测源
}SWarningItem;

typedef struct
{
	string Id;        ///< 告警ID
	string Name;      ///< 告警名称
	string Detail;    ///< 告警详细名称
	string Level;     ///< 告警等级
	string FailedPart;///< 失效部件
	string Source;
	string AppearanceTime;
}SCurrentWarningItem;

typedef struct
{
	string Id;        ///< 告警ID
	string Name;      ///< 告警名称
	string Detail;    ///< 告警详细名称
	string Level;     ///< 告警等级
	string FailedPart;///< 失效部件
	string Source;    ///< 检测源
	string AppearanceTime;
	string DisappearanceTime;
}SHistoryWarningItem;

const SWarningItem WarningMap[] =
{
    { "0001-01", "市电异常",   "电压过低",         "/",     "市电",   "市电" },
    { "0001-02", "市电异常",   "电压低",           "重要",  "市电",   "市电" },
    { "0001-03", "市电异常",   "电压高",           "重要",  "市电",   "市电" },
    { "0001-04", "市电异常",   "电压快掉",         "重要",  "市电",   "市电" },
    { "0001-05", "市电异常",   "输入浪涌",         "重要",  "市电",   "市电" },
    { "0001-06", "市电异常",   "频率低",           "重要",  "市电",   "市电" },
    { "0001-07", "市电异常",   "频率高",           "重要",  "市电",   "市电" },
    { "0001-08", "市电异常",   "电压异常",         "重要",  "市电",   "市电" },
    { "0001-09", "市电异常",   "频率异常",         "重要",  "市电",   "市电" },
    { "0001-10", "市电异常",   "相序异常",         "重要",  "市电",   "市电" },
    { "0001-11", "市电异常",   "电压不能起整流器",  "/",    "市电",   "市电" },
    { "0001-12", "市电异常",   "孤岛",             "/",    "市电",   "市电" },
    { "0002-01", "整流器故障", "硬件软起异常",      "重要", "整流器",  "整流器" },
    { "0002-02", "整流器故障", "软件软起异常",      "重要", "整流器",  "整流器" },
    { "0002-03", "整流器故障", "母线电压低",        "重要", "母线",    "整流器" },
    { "0002-04", "整流器故障", "输入电流不均衡",    "/",    "整流器",  "整流器" },
    { "0003-01", "充电器故障", "母线电压异常",      "重要", "充电器",  "充电器" },
    { "0003-02", "充电器故障", "软起异常",          "重要", "充电器",  "充电器" },
    { "0003-03", "充电器故障", "输出电压瞬时低",    "次要",  "充电器",  "充电器" },
    { "0003-04", "充电器故障", "输出电压反复低",    "重要",  "充电器",  "充电器" },
    { "0003-05", "充电器故障", "输出低压",          "重要", "充电器",  "充电器" },
    { "0003-06", "充电器故障", "输出电压快速过低",  "重要",  "放电器",  "充电器" },
    { "0003-07", "充电器故障", "放电器高压",        "重要", "放电器",  "充电器" },
    { "0003-08", "充电器故障", "放电器电压过高",     "重要", "放电器",  "充电器" },
    { "0003-09", "充电器故障", "放电器电压快速过高", "重要", "充电器",  "充电器" },
    { "0003-10", "充电器故障", "软起短路",          "重要", "放电器",  "充电器" },
    { "0004-01", "放电器故障", "放电器低压",        "重要", "放电器",  "放电器" },
    { "0004-02", "放电器故障", "母线低压",          "重要", "母线",    "放电器" },
    { "0005-01", "母线故障", "母线低压",            "重要", "母线",    "母线" },
    { "0005-02", "母线故障", "母线电压过低",        "重要", "母线",    "母线" },
    { "0005-03", "母线故障", "母线高压",            "重要", "母线",    "母线" },
    { "0005-04", "母线故障", "母线电压过高",        "重要", "母线",     "母线" },
    { "0005-05", "母线故障", "母线不平衡",          "重要", "母线",    "母线" },
    { "0006-01", "温度异常", "过温",               "重要",  "散热器",  "温度检测" },
    { "0006-02", "温度异常", "温度探头未插",        "重要", "温度探头", "温度检测" },
    { "0007-01", "风扇故障", "风扇故障",            "重要", "风扇",    "风扇" },
    { "0008-01", "锁相异常", "锁相异常",            "重要", "锁相",    "锁相" }
};

class CWarningList
{
public:
	std::list <SCurrentWarningItem> CurrentList;
	std::list <SHistoryWarningItem> HistoryList;
    bool CurrentListChanged;
    bool HistoryListChanged;

private:
	SCurrentWarningItem TempCWI;
	SHistoryWarningItem TempHWI;

public:
	CWarningList(void);
	~CWarningList(void);

	void Init(void);
	void Add(string Id);
	void Delete(string Id);
	void Clear(void);
};

extern CWarningList WarningList;

#endif
/// end of file