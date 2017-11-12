// MAPParser.cpp: implementation of the MAPParser class.
//
//////////////////////////////////////////////////////////////////////

#include "MAPParser.h"
#include <string.h>
#include <sys/stat.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MAPParser::MAPParser()
{
	this->parseBuf = 0;
	this->parseSize = 0;
	this->parsePos = 0;
	this->parseType = eNull;
}

MAPParser::~MAPParser()
{
	Finisch();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool MAPParser::SetMAPFile(const char* filename)
{
	bool res = true;
	FILE *file;
	size_t numread;
	struct _stat status;

	if (_stat(filename, &status) == 0)
	{
		this->parseSize = (int)status.st_size + 1;

		if (this->parseBuf)
			delete this->parseBuf;

		this->parseBuf = new char[this->parseSize];

		if (this->parseBuf)
		{
			file = fopen(filename, "rt");
			if (file)
			{
				numread = fread(this->parseBuf, sizeof(char), this->parseSize, file);
				this->parseBuf[numread] = '\0';

				fclose(file);
				return true;
			}
			else
			{
				return PushError(ERROR_ID_CANT_OPEN_FILE);
			}
		}
		else
		{
			return PushError(ERROR_ID_NO_MEMORY_AVAILABLE);
		}
	}
	else
	{
		return PushError(ERROR_ID_CANT_OPEN_FILE);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool MAPParser::SetMAPBuffer(char* buffer)
{
	this->parseSize = strlen(buffer);

	this->parseBuf = new char[this->parseSize];
	
	if (this->parseBuf == 0)
	{
		PushError(ERROR_ID_NO_MEMORY_AVAILABLE);
		return false;
	}
	strncpy(this->parseBuf, buffer, this->parseSize);
	return true;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void MAPParser::Finisch()
{
	if (this->parseBuf)
	{
		delete [] this->parseBuf;
	}
	this->parseBuf = 0;
	this->parseSize = 0;
	this->parsePos = 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool MAPParser::GoToNextToken()
{
	bool res = false;

	while (this->parsePos < this->parseSize)
	{
		if (this->parseBuf[this->parsePos] != ' ' && this->parseBuf[this->parsePos] != '\n' && this->parseBuf[this->parsePos] != '\t')
			break;
		this->parsePos++;
	}

	if (this->parsePos <= this->parseSize)
	{
		int len = 0;
		memset(this->parseData, 0, sizeof(this->parseData));

		switch (this->parseBuf[this->parsePos])
		{
		case '}':
			{
				this->parseData[0] = this->parseBuf[this->parsePos];
				len = 1;
				this->parseType = eEndBracket;
				break;
			}

		case '{':
			{
				this->parseData[0] = this->parseBuf[this->parsePos];
				len = 1;
				this->parseType = eStartBracket;
				break;
			}

		case '\"':
			{
				this->parsePos++;
				do
				{
					this->parseData[len] = this->parseBuf[this->parsePos+len];
					len++;
				} while (this->parseBuf[this->parsePos+len] != '\"');
				this->parseType = eString;
				break;
			}

		case '(':
			{
				
				do
				{
					this->parseData[len] = this->parseBuf[this->parsePos+len];
					len++;
				} while (this->parseBuf[this->parsePos+len] != '\n');
				this->parseType = ePlane;
				break;
			}

		case '\0':
			{
				this->parseType = eEnd;
				break;
			}

		default:
			{
				do
				{
					this->parseData[len] = this->parseBuf[this->parsePos+len];
					len++;
				} while ((this->parseBuf[this->parsePos+len] != '\n') && this->parseBuf[this->parsePos+len] != '\0');
				this->parseType = eComment;
			}
		}
		this->parseData[len] = '\0';
		this->parsePos += len;
		this->parsePos++;
		res = true;
	}
	return res;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
char* MAPParser::GetToken()
{
	return this->parseData;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int MAPParser::GetType()
{
	return this->parseType;
}
