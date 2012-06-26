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
// MessageId: FTPWPP_ERROR_FIRST
//
// MessageText:
//
//  CFtpWpp's first error message.
//
#define FTPWPP_ERROR_FIRST               0x40042300L

//
// MessageId: FTPWPP_ERROR_INETOPEN_FAILED
//
// MessageText:
//
//  The FTP provider could not connect to the internet.
//
#define FTPWPP_ERROR_INETOPEN_FAILED     0xC0042301L

//
// MessageId: FTPWPP_ERROR_AUTHENTICATION_FAILED
//
// MessageText:
//
//  The FTP provider could not log in to the FTP server.
//
#define FTPWPP_ERROR_AUTHENTICATION_FAILED 0xC0042302L

//
// MessageId: FTPWPP_ERROR_LAST
//
// MessageText:
//
//  CFtpWpp's last error message.
//
#define FTPWPP_ERROR_LAST                0x400423FFL

