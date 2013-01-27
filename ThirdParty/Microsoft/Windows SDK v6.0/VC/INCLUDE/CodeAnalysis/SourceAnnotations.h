#if _MSC_VER >= 1400

#pragma once

#ifndef _M_CEE_SAFE  // Source annotation attributes don't work with /clr:safe

#include <stddef.h>

#pragma push_macro( "SA" )
#pragma push_macro( "REPEATABLE" )

#ifdef __cplusplus
#define SA( id ) id
#define REPEATABLE [repeatable]
#else  // !__cplusplus
#define SA( id ) SA_##id
#define REPEATABLE
#endif  // !__cplusplus

#ifdef __cplusplus
namespace vc_attributes
{
#endif  // __cplusplus

enum SA( YesNoMaybe )
{
	// Choose values that we can detect as invalid if they are or'd together
	SA( No ) = 0x0fff0001,
	SA( Maybe ) = 0x0fff0010,
	SA( Yes ) = 0x0fff0100
};

typedef enum SA( YesNoMaybe ) SA( YesNoMaybe );

enum SA( AccessType )
{
	SA( NoAccess ) = 0,
	SA( Read ) = 1,
	SA( Write ) = 2,
	SA( ReadWrite ) = 3
};

typedef enum SA( AccessType ) SA( AccessType );

#ifndef SAL_NO_ATTRIBUTE_DECLARATIONS

REPEATABLE
[source_annotation_attribute( SA( Parameter ) )]
struct PreAttribute
{
#ifdef __cplusplus
	PreAttribute();
#endif

	unsigned int Deref;
	SA( YesNoMaybe ) Valid;
	SA( YesNoMaybe ) Null;
	SA( YesNoMaybe ) Tainted;
	SA( AccessType ) Access;
	size_t ValidElementsConst;
	size_t ValidBytesConst;
	const wchar_t* ValidElements;
	const wchar_t* ValidBytes;
	const wchar_t* ValidElementsLength;
	const wchar_t* ValidBytesLength;
	size_t WritableElementsConst;
	size_t WritableBytesConst;
	const wchar_t* WritableElements;
	const wchar_t* WritableBytes;
	const wchar_t* WritableElementsLength;
	const wchar_t* WritableBytesLength;
	size_t ElementSizeConst;
	const wchar_t* ElementSize;
	SA( YesNoMaybe ) NullTerminated;
	const wchar_t* Condition;
};

REPEATABLE
[source_annotation_attribute( SA( Parameter )|SA( ReturnValue ) )]
struct PostAttribute
{
#ifdef __cplusplus
	PostAttribute();
#endif

	unsigned int Deref;
	SA( YesNoMaybe ) Valid;
	SA( YesNoMaybe ) Null;
	SA( YesNoMaybe ) Tainted;
	SA( AccessType ) Access;
	size_t ValidElementsConst;
	size_t ValidBytesConst;
	const wchar_t* ValidElements;
	const wchar_t* ValidBytes;
	const wchar_t* ValidElementsLength;
	const wchar_t* ValidBytesLength;
	size_t WritableElementsConst;
	size_t WritableBytesConst;
	const wchar_t* WritableElements;
	const wchar_t* WritableBytes;
	const wchar_t* WritableElementsLength;
	const wchar_t* WritableBytesLength;
	size_t ElementSizeConst;
	const wchar_t* ElementSize;
	SA( YesNoMaybe ) NullTerminated;
	SA( YesNoMaybe ) MustCheck;
	const wchar_t* Condition;
};

[source_annotation_attribute( SA( Parameter ) )]
struct FormatStringAttribute
{
#ifdef __cplusplus
	FormatStringAttribute();
#endif

	const wchar_t* Style;
	const wchar_t* UnformattedAlternative;
};

REPEATABLE
[source_annotation_attribute( SA( ReturnValue ) )]
struct InvalidCheckAttribute
{
#ifdef __cplusplus
	InvalidCheckAttribute();
#endif

	long Value;
};

#endif  // !SAL_NO_ATTRIBUTE_DECLARATIONS

#ifdef __cplusplus
};  // namespace vc_attributes
#endif  // __cplusplus

#pragma pop_macro( "REPEATABLE" )
#pragma pop_macro( "SA" )

#ifdef __cplusplus

#define SA_All All
#define SA_Class Class
#define SA_Constructor Constructor
#define SA_Delegate Delegate
#define SA_Enum Enum
#define SA_Event Event
#define SA_Field Field
#define SA_GenericParameter GenericParameter
#define SA_Interface Interface
#define SA_Method Method
#define SA_Module Module
#define SA_Parameter Parameter
#define SA_Property Property
#define SA_ReturnValue ReturnValue
#define SA_Struct Struct

typedef ::vc_attributes::YesNoMaybe SA_YesNoMaybe;
const ::vc_attributes::YesNoMaybe SA_Yes = ::vc_attributes::Yes;
const ::vc_attributes::YesNoMaybe SA_No = ::vc_attributes::No;
const ::vc_attributes::YesNoMaybe SA_Maybe = ::vc_attributes::Maybe;

typedef ::vc_attributes::AccessType SA_AccessType;
const ::vc_attributes::AccessType SA_NoAccess = ::vc_attributes::NoAccess;
const ::vc_attributes::AccessType SA_Read = ::vc_attributes::Read;
const ::vc_attributes::AccessType SA_Write = ::vc_attributes::Write;
const ::vc_attributes::AccessType SA_ReadWrite = ::vc_attributes::ReadWrite;

#ifndef SAL_NO_ATTRIBUTE_DECLARATIONS
typedef ::vc_attributes::PreAttribute SA_Pre;
typedef ::vc_attributes::PostAttribute SA_Post;
typedef ::vc_attributes::FormatStringAttribute SA_FormatString;
typedef ::vc_attributes::InvalidCheckAttribute SA_InvalidCheck;
#endif //!SAL_NO_ATTRIBUTE_DECLARATIONS

#else  // !__cplusplus

typedef struct PreAttribute SA_Pre;
typedef struct PreAttribute PreAttribute;

typedef struct PostAttribute SA_Post;
typedef struct PostAttribute PostAttribute;

typedef struct FormatStringAttribute SA_FormatString;
typedef struct FormatStringAttribute FormatStringAttribute;

typedef struct InvalidCheckAttribute SA_InvalidCheck;
typedef struct InvalidCheckAttribute InvalidCheckAttribute;

#endif  // __cplusplus

#endif  // !_M_CEE_SAFE

#ifdef _MANAGED

#ifdef CODE_ANALYSIS
#define SA_SUPPRESS_MESSAGE( category, id, ... ) [::System::Diagnostics::CodeAnalysis::SuppressMessage( category, id, __VA_ARGS__ )]
#define CA_SUPPRESS_MESSAGE( ... ) [System::Diagnostics::CodeAnalysis::SuppressMessage( __VA_ARGS__ )]
#define CA_GLOBAL_SUPPRESS_MESSAGE( ... ) [assembly:System::Diagnostics::CodeAnalysis::SuppressMessage( __VA_ARGS__ )]
#else  // !CODE_ANALYSIS
#define SA_SUPPRESS_MESSAGE( category, id, ... )
#define CA_SUPPRESS_MESSAGE( ... )
#define CA_GLOBAL_SUPPRESS_MESSAGE( ... ) 
#endif  // !CODE_ANALYSIS

#endif  // _MANAGED

#ifdef _PREFAST_
#define __analysis_assume(expr) __assume(expr)
#else  // !_PREFAST_
#define __analysis_assume(expr) 
#endif  // _PREFAST_

#endif  // _MSC_VER >= 1400

