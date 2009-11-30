#pragma once

// inspired from http://zitomerconsulting.com/blog/2009/06/05/template-class-for-dynamic-linking/
template <typename FunctionPtr> class DllFunction
{
private:
	auto_library _dllhandle;
	FunctionPtr _procAddress;
public:
	DllFunction(LPCWSTR dllname, LPCSTR procName)
		: _procAddress(NULL)
    {
		reset(_dllhandle, ::LoadLibraryW(dllname));
		if (get(_dllhandle) != NULL)
		{
            _procAddress = (FunctionPtr)(::GetProcAddress(get(_dllhandle), procName));
        }
    }

    virtual operator FunctionPtr()
    {
        return _procAddress;
    }
};