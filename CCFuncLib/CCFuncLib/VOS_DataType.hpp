/************************************************************
* File       : VOS_DataType.h
* Author     : Lu Peng
* Descripton : ...
* Date       : 2018-04-06
************************************************************/
#ifndef VOS_DATATYPE_H
#define VOS_DATATYPE_H

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;

typedef short INT16;
//typedef long  INT32;

typedef unsigned short UINT16;
//typedef unsigned long  UINT32;

// typedef enum{false = 0, true = 1} bool;
typedef enum{SUCCESS, FAIL, EMPTY, NOT_EMPTY, FULL} ErrCodeT;

#endif