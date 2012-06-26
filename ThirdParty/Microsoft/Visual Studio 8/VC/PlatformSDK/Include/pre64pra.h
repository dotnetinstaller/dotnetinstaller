// Note: For 64 bit builds only
// Currently, if the user includes WIN32.MAK and uses the $(cflags) environment variable
// several warnings will be displayed when compiling.  This creates problems when some 
// samples set warnings to errors.  So we have disabled some of the warnings.
//
// Below is a list of the warnings disabled by the PSDK in the 64 bit build environments
//
// To reenable a warning, simply comment out the pragma line containing the warning
// you wish to be displayed.


#pragma warning(disable: 4053)    // An expression of type VOID was used as an operand
#pragma warning(disable: 4100)    // Unreferenced formal parameter
#pragma warning(disable: 4115)    // Named type definition in parentheses
#pragma warning(disable: 4127)    // Conditional expression is a constant
#pragma warning(disable: 4189)    // Local Variable is initialized but not referenced
#pragma warning(disable: 4201)    // Nameless struct/union (MS C/C++ specific)
#pragma warning(disable: 4706)    // Assignment within conditional expression
