/************************************************************
* File       : CfgFileParser.cpp
* Author     : Lu Peng
* Descripton : ...
* Date       : 2018-04-06
************************************************************/
#include <regex>  
#include <string>  
#include <vector>
#include <iostream>
#include "VOS_DataType.hpp"
#include "CfgFileParser.hpp"

CCfgFileParser::CCfgFileParser(void)
{
	Info.Model = "";              // 型号
	Info.Code = "";               // 编码
	Info.Barcode = "";            // 条码
	Info.HardwareVersion = "";    // 硬件版本
	Info.SoftwareVersion = "";    // 软件版本
	Info.Component1HardVer = "";  // 组件1硬件版本
	Info.Component1SoftVer = "";  // 组件1软件版本
	Info.Component1Bin = "";      // 升级bin文件名称
}

CCfgFileParser::~CCfgFileParser(void)
{}

std::string CCfgFileParser::GetModel(void)
{
	return Info.Model;
}

std::string CCfgFileParser::GetCode(void)
{
	return Info.Code;
}

std::string CCfgFileParser::GetBarcode(void)
{
	return Info.Barcode;
}

std::string CCfgFileParser::GetHardwareVersion(void)
{
	return Info.HardwareVersion;
}

std::string CCfgFileParser::GetSoftwareVersion(void)
{
	return Info.SoftwareVersion;
}

std::string CCfgFileParser::GetComponent1HardVer(void)
{
	return Info.Component1HardVer;
}

std::string CCfgFileParser::GetComponent1SoftVer(void)
{
	return Info.Component1SoftVer;
}

std::string CCfgFileParser::GetComponent1Bin(void)
{
	return Info.Component1Bin;
}

bool CCfgFileParser::ParseSource(std::string Items)
{
	std::string s = Items;
	std::smatch MatchResult;
	std::regex  Reg("<(\\w+).*>.*</\\1>");

	while (std::regex_search(s, MatchResult, Reg))
	{
		ParseOneItem(MatchResult.str());
		s = MatchResult.suffix().str();
	}

	return true;
}

bool CCfgFileParser::ParseOneItem(std::string OneItem)
{
	std::string s = OneItem;
	std::smatch MatchResult;
	std::regex  Reg("<(\\w+).*>\\s*([\\w\\.-]*)\\s*</\\1>");

	if (std::regex_match(s, MatchResult, Reg))
	{
		if (MatchResult.size() == 3)
		{
			AssignValueForAttribution(MatchResult[1].str(), MatchResult[2].str());
		}
	}

	return true;
}

bool CCfgFileParser::AssignValueForAttribution(std::string OneItem, std::string Attribution)
{
	if (OneItem == "model")
	{
		Info.Model = Attribution;
	}
	else if (OneItem == "code")
	{
		Info.Code = Attribution;
	}
	else if (OneItem == "barcode")
	{
		Info.Barcode = Attribution;
	}
	else if (OneItem == "hardwareversion")
	{
		Info.HardwareVersion = Attribution;
	}
	else if (OneItem == "softwareversion")
	{
		Info.SoftwareVersion = Attribution;
	}
	else if (OneItem == "component1hardver")
	{
		Info.Component1HardVer = Attribution;
	}
	else if (OneItem == "component1softver")
	{
		Info.Component1SoftVer = Attribution;
	}
	else if (OneItem == "component1bin")
	{
		Info.Component1Bin = Attribution;
	}
	else
	{
		return false;
	}

	return true;
}

void CCfgFileParser::ClearInfo(void)
{
	Info.Model = "";              // 型号
	Info.Code = "";               // 编码
	Info.Barcode = "";            // 条码
	Info.HardwareVersion = "";    // 硬件版本
	Info.SoftwareVersion = "";    // 软件版本
	Info.Component1HardVer = "";  // 组件1硬件版本
	Info.Component1SoftVer = "";  // 组件1软件版本
	Info.Component1Bin = "";      // 升级bin文件名称
}

CCfgFileParser CfgFileParser;

/// end of file