// Error.h: interface for the Error class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ERROR_H
#define ERROR_H

struct Err
{
	int id;
	char* errdescription;
	Err* pnext;
};

class Error  
{
private:
	Err* first;

protected:
	bool PushError(int id, char* description = 0);
	bool PushErrors(Err* errors);

public:
	Error();
	virtual ~Error();

	bool PopError(Err &err);
	Err* PopErrors();
	bool HasErrors();

};

#endif
