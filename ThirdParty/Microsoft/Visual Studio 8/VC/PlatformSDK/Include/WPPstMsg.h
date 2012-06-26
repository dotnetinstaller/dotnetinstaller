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
// MessageId: WPP_ERROR_FIRST
//
// MessageText:
//
//  WebPost Provider first error message.
//
#define WPP_ERROR_FIRST                  0x40042380L

//
// MessageId: WPP_POST_POSTING_URL_ERROR
//
// MessageText:
//
//  The URL you selected, %1, is invalid.
//
#define WPP_POST_POSTING_URL_ERROR       0xC0042381L

//
// MessageId: WPP_POST_POSTING_SERVER_ERROR
//
// MessageText:
//
//  The Web server returned the following error: %1.
//
#define WPP_POST_POSTING_SERVER_ERROR    0xC0042382L

//
// MessageId: WPP_POST_POSTING_NO_RESPONSE_ERROR
//
// MessageText:
//
//  The Web server either is not responding or returned an unrecognized response.
//
#define WPP_POST_POSTING_NO_RESPONSE_ERROR 0xC0042383L

//
// MessageId: WPP_ERROR_LAST
//
// MessageText:
//
//  WebPost Provider last error message.
//
#define WPP_ERROR_LAST                   0x400423FFL

