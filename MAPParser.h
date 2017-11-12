// MAPParser.h: interface for the MAPParser class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <stdio.h>
#include <string>
using namespace std;

#include "Error.h"

enum
{
	eNull = 0,
	eStartBracket,
	eEndBracket,
	eString,
	ePlane,
	eCoord,
	eTexture,
	eComment,
	eEnd
};

#define ERROR_ID_NO_MEMORY_AVAILABLE 87567
#define ERROR_ID_CANT_OPEN_FILE 87568

class MAPParser : public Error
{
private:
	char* parseBuf;
	int parseSize;
	int parsePos;
	char parseData[1024];
	int parseType;
public:
	MAPParser();
	virtual ~MAPParser();

	bool SetMAPFile(const char* filename);
	bool SetMAPBuffer(char* buffer);
	void Finisch();
	bool GoToNextToken();

	char* GetToken();
	int GetType();
};

#endif
