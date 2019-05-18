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
	std::string Model;              // �ͺ�
	std::string Code;               // ����
	std::string Barcode;            // ����
	std::string HardwareVersion;    // Ӳ���汾
	std::string SoftwareVersion;    // ����汾
	std::string Component1HardVer;  // ���1Ӳ���汾
	std::string Component1SoftVer;  // ���1����汾
	std::string Component1Bin;      // ����bin�ļ�����
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