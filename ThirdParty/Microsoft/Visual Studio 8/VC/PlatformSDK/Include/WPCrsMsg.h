//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: CRSWPP_ERROR_FIRST
//
// MessageText:
//
//  CRS WebPost provider's first error message.
//
#define CRSWPP_ERROR_FIRST               0x40042200L

//
// MessageId: CRSWPP_INVALID_POSTINFO_FILE
//
// MessageText:
//
//  The PostInfo file is invalid on the server you selected.
//
#define CRSWPP_INVALID_POSTINFO_FILE     0xC0042201L

//
// MessageId: CRSWPP_NO_MATCHING_MAPURL
//
// MessageText:
//
//  The CRS project you selected has no MAPURL.
//
#define CRSWPP_NO_MATCHING_MAPURL        0xC0042202L

//
// MessageId: CRSWPP_SECURITY_PACKAGE
//
// MessageText:
//
//  The initialization of the security package failed.
//
#define CRSWPP_SECURITY_PACKAGE          0xC0042203L

//
// MessageId: CRSWPP_SECURITY_PACKAGE_NOT_FOUND
//
// MessageText:
//
//  The security package(s) required by the server could not be found on your computer.
//
#define CRSWPP_SECURITY_PACKAGE_NOT_FOUND 0xC0042204L

//
// MessageId: CRSWPP_PROJECT_BINDING_INCOMPLETE
//
// MessageText:
//
//  The CRS provider has not determined which CRS project on the server corresponds to the URL you selected.
//
#define CRSWPP_PROJECT_BINDING_INCOMPLETE 0xC0042205L

//
// MessageId: CRSWPP_SERVER_BINDING_INCOMPLETE
//
// MessageText:
//
//  The CRS provider has not determined the name of the server that corresponds to the URL you selected.
//
#define CRSWPP_SERVER_BINDING_INCOMPLETE 0xC0042206L

//
// MessageId: CRSWPP_SERVER_NOT_RESPONDING
//
// MessageText:
//
//  The CRS server is not responding.
//
#define CRSWPP_SERVER_NOT_RESPONDING     0xC0042207L

//
// MessageId: CRSWPP_FAILED_AUTH
//
// MessageText:
//
//  You do not have the necessary access privileges to publish to this CRS server.
//
#define CRSWPP_FAILED_AUTH               0xC0042208L

//
// MessageId: CRSWPP_POSTINFO_NEEDED
//
// MessageText:
//
//  The CRS provider could not retrieve all of the required information from the PostInfo file on the server.
//
#define CRSWPP_POSTINFO_NEEDED           0x40042209L

//
// MessageId: CRSWPP_BIND_FAILED
//
// MessageText:
//
//  The CRS provider could not connect to the CRS server.
//
#define CRSWPP_BIND_FAILED               0xC004220AL

