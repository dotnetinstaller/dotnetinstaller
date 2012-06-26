// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLPATH_H__
#define __ATLPATH_H__

#pragma once

#ifdef _AFX
#include <afxstr.h>
#else
#include <atlstr.h>
#endif

#ifndef _ATL_NO_DEFAULT_LIBS
#pragma comment(lib, "shlwapi.lib")
#endif  // !_ATL_NO_DEFAULT_LIBS


#pragma pack(push,_ATL_PACKING)
namespace ATL
{

namespace ATLPath
{

inline char* AddBackslash( __inout char* pszPath )
{
	return ::PathAddBackslashA( pszPath );
}

inline wchar_t* AddBackslash( __inout wchar_t* pszPath )
{
	return ::PathAddBackslashW( pszPath );
}

inline BOOL AddExtension( __inout char* pszPath, __in const char* pszExtension )
{
	return ::PathAddExtensionA( pszPath, pszExtension );
}

inline BOOL AddExtension( __inout wchar_t* pszPath, __in const wchar_t* pszExtension )
{
	return ::PathAddExtensionW( pszPath, pszExtension );
}

inline BOOL Append( __inout char* pszPath, __in const char* pszMore )
{
	return ::PathAppendA( pszPath, pszMore );
}

inline BOOL Append( __inout wchar_t* pszPath, __in const wchar_t* pszMore )
{
	return ::PathAppendW( pszPath, pszMore );
}

inline char* BuildRoot( __out_ecount(4) char* pszPath, __in int iDrive )
{
	return ::PathBuildRootA( pszPath, iDrive );
}

inline wchar_t* BuildRoot( __out_ecount(4) wchar_t* pszPath, __in int iDrive )
{
	return ::PathBuildRootW( pszPath, iDrive );
}

inline BOOL Canonicalize( __out char* pszDest, __in const char* pszSrc )
{
	return ::PathCanonicalizeA( pszDest, pszSrc );
}

inline BOOL Canonicalize( __out wchar_t* pszDest, __in const wchar_t* pszSrc )
{
	return ::PathCanonicalizeW( pszDest, pszSrc );
}

inline char* Combine( __out char* pszDest, __in const char* pszDir,
	__in const char* pszFile )
{
	return ::PathCombineA( pszDest, pszDir, pszFile );
}

inline wchar_t* Combine( __out wchar_t* pszDest, __in const wchar_t* pszDir,
	__in const wchar_t* pszFile )
{
	return ::PathCombineW( pszDest, pszDir, pszFile );
}

inline int CommonPrefix( __in const char* pszFile1, __in const char* pszFile2,
	__out char* pszDest )
{
	return ::PathCommonPrefixA( pszFile1, pszFile2, pszDest );
}

inline int CommonPrefix( __in const wchar_t* pszFile1, __in const wchar_t* pszFile2,
	__out wchar_t* pszDest )
{
	return ::PathCommonPrefixW( pszFile1, pszFile2, pszDest );
}

inline BOOL FileExists( __in const char* pszPath )
{
	return ::PathFileExistsA( pszPath );
}

inline BOOL FileExists( __in const wchar_t* pszPath )
{
	return ::PathFileExistsW( pszPath );
}

inline char* FindExtension( __in const char* pszPath )
{
	return ::PathFindExtensionA( pszPath );
}

inline wchar_t* FindExtension( __in const wchar_t* pszPath )
{
	return ::PathFindExtensionW( pszPath );
}

inline char* FindFileName( __in const char* pszPath )
{
	return ::PathFindFileNameA( pszPath );
}

inline wchar_t* FindFileName( __in const wchar_t* pszPath )
{
	return ::PathFindFileNameW( pszPath );
}

inline int GetDriveNumber( __in const char* pszPath )
{
	return ::PathGetDriveNumberA( pszPath );
}

inline int GetDriveNumber( __in const wchar_t* pszPath )
{
	return ::PathGetDriveNumberW( pszPath );
}

inline BOOL IsDirectory( __in const char* pszPath )
{
	return ::PathIsDirectoryA( pszPath );
}

inline BOOL IsDirectory( __in const wchar_t* pszPath )
{
	return ::PathIsDirectoryW( pszPath );
}

inline BOOL IsFileSpec( __in const char* pszPath )
{
	return ::PathIsFileSpecA( pszPath );
}

inline BOOL IsFileSpec( __in const wchar_t* pszPath )
{
	return ::PathIsFileSpecW( pszPath );
}

inline BOOL IsPrefix( __in const char* pszPrefix, __in const char* pszPath )
{
	return ::PathIsPrefixA( pszPrefix, pszPath );
}

inline BOOL IsPrefix( __in const wchar_t* pszPrefix, __in const wchar_t* pszPath )
{
	return ::PathIsPrefixW( pszPrefix, pszPath );
}

inline BOOL IsRelative( __in const char* pszPath )
{
	return ::PathIsRelativeA( pszPath );
}

inline BOOL IsRelative( __in const wchar_t* pszPath )
{
	return ::PathIsRelativeW( pszPath );
}

inline BOOL IsRoot( __in const char* pszPath )
{
	return ::PathIsRootA( pszPath );
}

inline BOOL IsRoot( __in const wchar_t* pszPath )
{
	return ::PathIsRootW( pszPath );
}

inline BOOL IsSameRoot( __in const char* pszPath1, __in const char* pszPath2 )
{
	return ::PathIsSameRootA( pszPath1, pszPath2 );
}

inline BOOL IsSameRoot( __in const wchar_t* pszPath1, __in const wchar_t* pszPath2 )
{
	return ::PathIsSameRootW( pszPath1, pszPath2 );
}

inline BOOL IsUNC( __in const char* pszPath )
{
	return ::PathIsUNCA( pszPath );
}

inline BOOL IsUNC( __in const wchar_t* pszPath )
{
	return ::PathIsUNCW( pszPath );
}

inline BOOL IsUNCServer( __in const char* pszPath )
{
	return ::PathIsUNCServerA( pszPath );
}

inline BOOL IsUNCServer( __in const wchar_t* pszPath )
{
	return ::PathIsUNCServerW( pszPath );
}

inline BOOL IsUNCServerShare( __in const char* pszPath )
{
	return ::PathIsUNCServerShareA( pszPath );
}

inline BOOL IsUNCServerShare( __in const wchar_t* pszPath )
{
	return ::PathIsUNCServerShareW( pszPath );
}

inline BOOL MakePretty( __inout char* pszPath )
{
	return ::PathMakePrettyA( pszPath );
}

inline BOOL MakePretty( __inout wchar_t* pszPath )
{
	return ::PathMakePrettyW( pszPath );
}

inline BOOL MatchSpec( __in const char* pszPath, __in const char* pszSpec )
{
	return ::PathMatchSpecA( pszPath, pszSpec );
}

inline BOOL MatchSpec( __in const wchar_t* pszPath, __in const wchar_t* pszSpec )
{
	return ::PathMatchSpecW( pszPath, pszSpec );
}

inline void QuoteSpaces( __inout char* pszPath )
{
	::PathQuoteSpacesA( pszPath );
}

inline void QuoteSpaces( __inout wchar_t* pszPath )
{
	::PathQuoteSpacesW( pszPath );
}

inline BOOL RelativePathTo( __out char* pszPath, __in const char* pszFrom,
	__in DWORD dwAttrFrom, __in const char* pszTo, __in DWORD dwAttrTo )
{
	return ::PathRelativePathToA( pszPath, pszFrom, dwAttrFrom, pszTo, dwAttrTo );
}

inline BOOL RelativePathTo( __out wchar_t* pszPath, __in const wchar_t* pszFrom,
	__in DWORD dwAttrFrom, __in const wchar_t* pszTo, __in DWORD dwAttrTo )
{
	return ::PathRelativePathToW( pszPath, pszFrom, dwAttrFrom, pszTo, dwAttrTo );
}

inline void RemoveArgs( __inout char* pszPath )
{
	::PathRemoveArgsA( pszPath );
}

inline void RemoveArgs( __inout wchar_t* pszPath )
{
	::PathRemoveArgsW( pszPath );
}

inline char* RemoveBackslash( __inout char* pszPath )
{
	return ::PathRemoveBackslashA( pszPath );
}

inline wchar_t* RemoveBackslash( __inout wchar_t* pszPath )
{
	return ::PathRemoveBackslashW( pszPath );
}

inline void RemoveBlanks( __inout char* pszPath )
{
	::PathRemoveBlanksA( pszPath );
}

inline void RemoveBlanks( __inout wchar_t* pszPath )
{
	::PathRemoveBlanksW( pszPath );
}

inline void RemoveExtension( __inout char* pszPath )
{
	::PathRemoveExtensionA( pszPath );
}

inline void RemoveExtension( __inout wchar_t* pszPath )
{
	::PathRemoveExtensionW( pszPath );
}

inline BOOL RemoveFileSpec( __inout char* pszPath )
{
	return ::PathRemoveFileSpecA( pszPath );
}

inline BOOL RemoveFileSpec( __inout wchar_t* pszPath )
{
	return ::PathRemoveFileSpecW( pszPath );
}

inline BOOL RenameExtension( __inout char* pszPath, __in const char* pszExt )
{
	return ::PathRenameExtensionA( pszPath, pszExt );
}

inline BOOL RenameExtension( __inout wchar_t* pszPath, __in const wchar_t* pszExt )
{
	return ::PathRenameExtensionW( pszPath, pszExt );
}

inline char* SkipRoot( __in const char* pszPath )
{
	return ::PathSkipRootA( pszPath );
}

inline wchar_t* SkipRoot( __in const wchar_t* pszPath )
{
	return ::PathSkipRootW( pszPath );
}

inline void StripPath( __inout char* pszPath )
{
	::PathStripPathA( pszPath );
}

inline void StripPath( __inout wchar_t* pszPath )
{
	::PathStripPathW( pszPath );
}

inline BOOL StripToRoot( __inout char* pszPath )
{
	return ::PathStripToRootA( pszPath );
}

inline BOOL StripToRoot( __inout wchar_t* pszPath )
{
	return ::PathStripToRootW( pszPath );
}

inline void UnquoteSpaces( __inout char* pszPath )
{
	::PathUnquoteSpacesA( pszPath );
}

inline void UnquoteSpaces( __inout wchar_t* pszPath )
{
	::PathUnquoteSpacesW( pszPath );
}

inline BOOL CompactPath( __in HDC hDC, __inout char* pszPath, __in UINT dx )
{
	return ::PathCompactPathA( hDC, pszPath, dx );
}

inline BOOL CompactPath( __in HDC hDC, __inout wchar_t* pszPath, __in UINT dx )
{
	return ::PathCompactPathW( hDC, pszPath, dx );
}

inline BOOL CompactPathEx( __out_ecount(nMaxChars) char* pszDest, __in const char* pszSrc,
	__in UINT nMaxChars, __in DWORD dwFlags )
{
	return ::PathCompactPathExA( pszDest, pszSrc, nMaxChars, dwFlags );
}

inline BOOL CompactPathEx( __out_ecount(nMaxChars) wchar_t* pszDest, __in const wchar_t* pszSrc,
	__in UINT nMaxChars, __in DWORD dwFlags )
{
	return ::PathCompactPathExW( pszDest, pszSrc, nMaxChars, dwFlags );
}

};  // namespace ATLPath

template< typename StringType >
class CPathT
{
public:
	typedef typename StringType::XCHAR XCHAR;
	typedef typename StringType::PCXSTR PCXSTR;
	typedef typename StringType::PXSTR PXSTR;

public:
	CPathT() throw()
	{
	}
	CPathT( const CPathT< StringType >& path ) :
		m_strPath( path.m_strPath )
	{
	}
	CPathT( PCXSTR pszPath ) :
		m_strPath( pszPath )
	{
	}

	operator const StringType& () const throw()
	{
		return m_strPath;
	}
	operator StringType& () throw()
	{
		return m_strPath;
	}
	operator PCXSTR() const throw()
	{
		return m_strPath;
	}
	CPathT< StringType >& operator+=( __in PCXSTR pszMore )
	{
		Append( pszMore );

		return *this;
	}

	void AddBackslash()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength()+1 );
		ATLPath::AddBackslash( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	BOOL AddExtension( __in PCXSTR pszExtension )
	{
		PXSTR pszBuffer;
		BOOL bResult;

		// If NULL is passed, shlwapi's PathAddExtension API adds ".EXE"
		int nLenExtension = (pszExtension == NULL) ? 4 : StringType::StringLength(pszExtension);
		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength()+nLenExtension);
		bResult = ATLPath::AddExtension( pszBuffer, pszExtension );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	BOOL Append( __in PCXSTR pszMore )
	{
		PXSTR pszBuffer;
		BOOL bResult;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength()+StringType::StringLength( pszMore )+1 );
		bResult = ATLPath::Append( pszBuffer, pszMore );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	void BuildRoot( __in int iDrive )
	{
		PXSTR pszBuffer;

		ATLASSERT( iDrive >= 0 );
		ATLASSERT( iDrive <= 25 );

		pszBuffer = m_strPath.GetBuffer( 3 );
		ATLPath::BuildRoot( pszBuffer, iDrive );
		m_strPath.ReleaseBuffer();
	}
	void Canonicalize()
	{
		PXSTR pszBuffer;
		StringType strResult;

		pszBuffer = strResult.GetBuffer( m_strPath.GetLength() );
		ATLPath::Canonicalize( pszBuffer, m_strPath );
		strResult.ReleaseBuffer();

		m_strPath = strResult;
	}
	void Combine( __in PCXSTR pszDir, __in PCXSTR pszFile )
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( MAX_PATH );
		ATLPath::Combine( pszBuffer, pszDir, pszFile );
		m_strPath.ReleaseBuffer();
	}
	CPathT< StringType > CommonPrefix( __in PCXSTR pszOther )
	{
		PXSTR pszBuffer;
		int nLength;
		CPathT< StringType > pathResult;

		pszBuffer = pathResult.m_strPath.GetBuffer( __max( m_strPath.GetLength(), StringType::StringLength( pszOther ) ) );
		nLength = ATLPath::CommonPrefix( m_strPath, pszOther, pszBuffer );
		pathResult.m_strPath.ReleaseBuffer( nLength );

		return pathResult;
	}
	BOOL CompactPath( __in HDC hDC, __in UINT nWidth )
	{
		PXSTR pszBuffer;
		BOOL bResult;

		// PathCompactPath can actually _increase_ the length of the path
		pszBuffer = m_strPath.GetBuffer( MAX_PATH );
		bResult = ATLPath::CompactPath( hDC, pszBuffer, nWidth );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	BOOL CompactPathEx( __in UINT nMaxChars, __in DWORD dwFlags = 0 )
	{
		StringType strResult;
		BOOL bResult;
		PXSTR pszBuffer;

		pszBuffer = strResult.GetBuffer( nMaxChars );
		bResult = ATLPath::CompactPathEx( pszBuffer, m_strPath, nMaxChars,
			dwFlags );
		strResult.ReleaseBuffer();

		m_strPath = strResult;

		return bResult;
	}
	BOOL FileExists() const
	{
		return ATLPath::FileExists( m_strPath );
	}
	int FindExtension() const
	{
		PCXSTR pszBuffer;
		PCXSTR pszExtension;

		pszBuffer = m_strPath;
		pszExtension = ATLPath::FindExtension( pszBuffer );
		if( *pszExtension == 0 )
			return -1;
		else
			return int( pszExtension-pszBuffer );
	}
	int FindFileName() const
	{
		PCXSTR pszBuffer;
		PCXSTR pszFileName;

		pszBuffer = m_strPath;
		pszFileName = ATLPath::FindFileName( pszBuffer );
		if( *pszFileName == 0 )
			return -1;
		else
			return int( pszFileName-pszBuffer );
	}
	int GetDriveNumber() const
	{
		return ATLPath::GetDriveNumber( m_strPath );
	}
	StringType GetExtension() const
	{
		int iExtension;
		StringType strExtension;

		iExtension = FindExtension();
		if( iExtension != -1 )
			strExtension = m_strPath.Mid( iExtension );

		return strExtension;
	}
	BOOL IsDirectory() const
	{
		return ATLPath::IsDirectory( m_strPath );
	}

	BOOL IsFileSpec() const
	{
		return ATLPath::IsFileSpec( m_strPath );
	}
	BOOL IsPrefix( PCXSTR pszPrefix ) const
	{
		return ATLPath::IsPrefix( pszPrefix, m_strPath );
	}
	BOOL IsRelative() const
	{
		return ATLPath::IsRelative( m_strPath );
	}
	BOOL IsRoot() const
	{
		return ATLPath::IsRoot( m_strPath );
	}
	BOOL IsSameRoot( PCXSTR pszOther ) const
	{
		return ATLPath::IsSameRoot( m_strPath, pszOther );
	}
	BOOL IsUNC() const
	{
		return ATLPath::IsUNC( m_strPath );
	}
	BOOL IsUNCServer() const
	{
		return ATLPath::IsUNCServer( m_strPath );
	}
	BOOL IsUNCServerShare() const
	{
		return ATLPath::IsUNCServerShare( m_strPath );
	}
	BOOL MakePretty()
	{
		PXSTR pszBuffer;
		BOOL bResult;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		bResult = ATLPath::MakePretty( pszBuffer );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	BOOL MatchSpec( __in PCXSTR pszSpec ) const
	{
		return ATLPath::MatchSpec( m_strPath, pszSpec );
	}
	void QuoteSpaces()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength()+2 );
		ATLPath::QuoteSpaces( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	BOOL RelativePathTo( __in PCXSTR pszFrom, __in DWORD dwAttrFrom, 
		__in PCXSTR pszTo, __in DWORD dwAttrTo )
	{
		PXSTR pszBuffer;
		BOOL bResult;

		pszBuffer = m_strPath.GetBuffer( MAX_PATH );
		bResult = ATLPath::RelativePathTo( pszBuffer, pszFrom, dwAttrFrom,
			pszTo, dwAttrTo );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	void RemoveArgs()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::RemoveArgs( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	void RemoveBackslash()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::RemoveBackslash( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	void RemoveBlanks()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::RemoveBlanks( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	void RemoveExtension()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::RemoveExtension( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	BOOL RemoveFileSpec()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		BOOL bResult = ATLPath::RemoveFileSpec( pszBuffer );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	BOOL RenameExtension( __in PCXSTR pszExtension )
	{
		PXSTR pszBuffer;
		BOOL bResult;

		pszBuffer = m_strPath.GetBuffer( MAX_PATH );
		bResult = ATLPath::RenameExtension( pszBuffer, pszExtension );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	int SkipRoot() const
	{
		PCXSTR pszBuffer;
		PXSTR pszResult;

		pszBuffer = m_strPath;
		pszResult = ATLPath::SkipRoot( pszBuffer );

		return int( pszResult-pszBuffer );
	}
	void StripPath()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::StripPath( pszBuffer );
		m_strPath.ReleaseBuffer();
	}
	BOOL StripToRoot()
	{
		PXSTR pszBuffer;
		BOOL bResult;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		bResult = ATLPath::StripToRoot( pszBuffer );
		m_strPath.ReleaseBuffer();

		return bResult;
	}
	void UnquoteSpaces()
	{
		PXSTR pszBuffer;

		pszBuffer = m_strPath.GetBuffer( m_strPath.GetLength() );
		ATLPath::UnquoteSpaces( pszBuffer );
		m_strPath.ReleaseBuffer();
	}

public:
	StringType m_strPath;
};

typedef CPathT< CString > CPath;
typedef CPathT< CStringA > CPathA;
typedef CPathT< CStringW > CPathW;

};  // namespace ATL
#pragma pack(pop)

#endif  //__ATLPATH_H__
