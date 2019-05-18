/************************************************************
* File       : CfgFileParser.h
* Author     : Lu Peng
* Descripton : ...
* Date       : 2018-04-06
*************************************************************/
#ifndef CFGFILEPARSER_H
#define CFGFILEPARSER_H

#include "VOS_DataType.hpp"
#include <string>

typedef struct
{
	std::string Model;              // 型号
	std::string Code;               // 编码
	std::string Barcode;            // 条码
	std::string HardwareVersion;    // 硬件版本
	std::string SoftwareVersion;    // 软件版本
	std::string Component1HardVer;  // 组件1硬件版本
	std::string Component1SoftVer;  // 组件1软件版本
	std::string Component1Bin;      // 升级bin文件名称
}STModuleInfo;

class CCfgFileParser
{
public:
	CCfgFileParser(void);
	~CCfgFileParser(void);
	std::string GetModel(void);
	std::string GetCode(void);
	std::string GetBarcode(void);
	std::string GetHardwareVersion(void);
	std::string GetSoftwareVersion(void);
	std::string GetComponent1HardVer(void);
	std::string GetComponent1SoftVer(void);
	std::string GetComponent1Bin(void);
	bool ParseSource(std::string Items);
	void ClearInfo(void);
private:
	bool ParseOneItem(std::string OneItem);
	bool AssignValueForAttribution(std::string OneItem, std::string Attribution);
	STModuleInfo Info;
};

extern CCfgFileParser CfgFileParser;

#endif