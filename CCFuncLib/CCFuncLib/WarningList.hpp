/**
* @file       WarningList.h
* @brief      �澯�б�
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
	string Id;        ///< �澯ID
	string Name;      ///< �澯����
	string Detail;    ///< �澯��ϸ����
	string Level;     ///< �澯�ȼ�
	string FailedPart;///< ʧЧ����
	string Source;    ///< ���Դ
}SWarningItem;

typedef struct
{
	string Id;        ///< �澯ID
	string Name;      ///< �澯����
	string Detail;    ///< �澯��ϸ����
	string Level;     ///< �澯�ȼ�
	string FailedPart;///< ʧЧ����
	string Source;
	string AppearanceTime;
}SCurrentWarningItem;

typedef struct
{
	string Id;        ///< �澯ID
	string Name;      ///< �澯����
	string Detail;    ///< �澯��ϸ����
	string Level;     ///< �澯�ȼ�
	string FailedPart;///< ʧЧ����
	string Source;    ///< ���Դ
	string AppearanceTime;
	string DisappearanceTime;
}SHistoryWarningItem;

const SWarningItem WarningMap[] =
{
    { "0001-01", "�е��쳣",   "��ѹ����",         "/",     "�е�",   "�е�" },
    { "0001-02", "�е��쳣",   "��ѹ��",           "��Ҫ",  "�е�",   "�е�" },
    { "0001-03", "�е��쳣",   "��ѹ��",           "��Ҫ",  "�е�",   "�е�" },
    { "0001-04", "�е��쳣",   "��ѹ���",         "��Ҫ",  "�е�",   "�е�" },
    { "0001-05", "�е��쳣",   "������ӿ",         "��Ҫ",  "�е�",   "�е�" },
    { "0001-06", "�е��쳣",   "Ƶ�ʵ�",           "��Ҫ",  "�е�",   "�е�" },
    { "0001-07", "�е��쳣",   "Ƶ�ʸ�",           "��Ҫ",  "�е�",   "�е�" },
    { "0001-08", "�е��쳣",   "��ѹ�쳣",         "��Ҫ",  "�е�",   "�е�" },
    { "0001-09", "�е��쳣",   "Ƶ���쳣",         "��Ҫ",  "�е�",   "�е�" },
    { "0001-10", "�е��쳣",   "�����쳣",         "��Ҫ",  "�е�",   "�е�" },
    { "0001-11", "�е��쳣",   "��ѹ������������",  "/",    "�е�",   "�е�" },
    { "0001-12", "�е��쳣",   "�µ�",             "/",    "�е�",   "�е�" },
    { "0002-01", "����������", "Ӳ�������쳣",      "��Ҫ", "������",  "������" },
    { "0002-02", "����������", "���������쳣",      "��Ҫ", "������",  "������" },
    { "0002-03", "����������", "ĸ�ߵ�ѹ��",        "��Ҫ", "ĸ��",    "������" },
    { "0002-04", "����������", "�������������",    "/",    "������",  "������" },
    { "0003-01", "���������", "ĸ�ߵ�ѹ�쳣",      "��Ҫ", "�����",  "�����" },
    { "0003-02", "���������", "�����쳣",          "��Ҫ", "�����",  "�����" },
    { "0003-03", "���������", "�����ѹ˲ʱ��",    "��Ҫ",  "�����",  "�����" },
    { "0003-04", "���������", "�����ѹ������",    "��Ҫ",  "�����",  "�����" },
    { "0003-05", "���������", "�����ѹ",          "��Ҫ", "�����",  "�����" },
    { "0003-06", "���������", "�����ѹ���ٹ���",  "��Ҫ",  "�ŵ���",  "�����" },
    { "0003-07", "���������", "�ŵ�����ѹ",        "��Ҫ", "�ŵ���",  "�����" },
    { "0003-08", "���������", "�ŵ�����ѹ����",     "��Ҫ", "�ŵ���",  "�����" },
    { "0003-09", "���������", "�ŵ�����ѹ���ٹ���", "��Ҫ", "�����",  "�����" },
    { "0003-10", "���������", "�����·",          "��Ҫ", "�ŵ���",  "�����" },
    { "0004-01", "�ŵ�������", "�ŵ�����ѹ",        "��Ҫ", "�ŵ���",  "�ŵ���" },
    { "0004-02", "�ŵ�������", "ĸ�ߵ�ѹ",          "��Ҫ", "ĸ��",    "�ŵ���" },
    { "0005-01", "ĸ�߹���", "ĸ�ߵ�ѹ",            "��Ҫ", "ĸ��",    "ĸ��" },
    { "0005-02", "ĸ�߹���", "ĸ�ߵ�ѹ����",        "��Ҫ", "ĸ��",    "ĸ��" },
    { "0005-03", "ĸ�߹���", "ĸ�߸�ѹ",            "��Ҫ", "ĸ��",    "ĸ��" },
    { "0005-04", "ĸ�߹���", "ĸ�ߵ�ѹ����",        "��Ҫ", "ĸ��",     "ĸ��" },
    { "0005-05", "ĸ�߹���", "ĸ�߲�ƽ��",          "��Ҫ", "ĸ��",    "ĸ��" },
    { "0006-01", "�¶��쳣", "����",               "��Ҫ",  "ɢ����",  "�¶ȼ��" },
    { "0006-02", "�¶��쳣", "�¶�̽ͷδ��",        "��Ҫ", "�¶�̽ͷ", "�¶ȼ��" },
    { "0007-01", "���ȹ���", "���ȹ���",            "��Ҫ", "����",    "����" },
    { "0008-01", "�����쳣", "�����쳣",            "��Ҫ", "����",    "����" }
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