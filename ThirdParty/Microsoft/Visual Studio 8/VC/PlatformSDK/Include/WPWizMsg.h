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
// MessageId: WPWIZ_ERROR_FIRST
//
// MessageText:
//
//  Web Publishing Wizard first error message.
//
#define WPWIZ_ERROR_FIRST                0x40042000L

//
// MessageId: WPWIZ_ERROR_UNKNOWN
//
// MessageText:
//
//  An unknown error occurred in the Web Publishing Wizard.
//
#define WPWIZ_ERROR_UNKNOWN              0xC0042001L

//
// MessageId: WPWIZ_ERROR_PROV_QI
//
// MessageText:
//
//  The Web Publishing Wizard was unable to determine the version number of your service provider.
//
#define WPWIZ_ERROR_PROV_QI              0xC0042002L

//
// MessageId: WPWIZ_ERROR_INIT_FAILED
//
// MessageText:
//
//  An error occurred while attempting to start the Web Publishing Wizard.
//
#define WPWIZ_ERROR_INIT_FAILED          0xC0042003L

//
// MessageId: WPWIZ_ERROR_COCREATE_WEBPOST
//
// MessageText:
//
//  The Web Publishing Wizard is not installed correctly. Please uninstall and then reinstall the wizard.
//
#define WPWIZ_ERROR_COCREATE_WEBPOST     0xC0042004L

//
// MessageId: WPWIZ_ERROR_NO_PROVIDERS
//
// MessageText:
//
//  The Web Publishing Wizard could not run because there are no service providers installed.
//
#define WPWIZ_ERROR_NO_PROVIDERS         0xC0042005L

//
// MessageId: WPWIZ_ERROR_STATE_PTR
//
// MessageText:
//
//  An internal error (0x2006) occurred in the Web Publishing Wizard.
//
#define WPWIZ_ERROR_STATE_PTR            0xC0042006L

//
// MessageId: WPWIZ_ERROR_WEBPOST_PTR
//
// MessageText:
//
//  An internal error (0x2007) occurred in the Web Publishing Wizard.
//
#define WPWIZ_ERROR_WEBPOST_PTR          0xC0042007L

//
// MessageId: WPWIZ_ERROR_FILE_NOT_FOUND
//
// MessageText:
//
//  The file(s) you selected to publish could not be found.
//
#define WPWIZ_ERROR_FILE_NOT_FOUND       0xC0042008L

//
// MessageId: WPWIZ_ERROR_PROPSHEET_ERROR
//
// MessageText:
//
//  An error occurred in the user interface of the Web Publishing Wizard.
//
#define WPWIZ_ERROR_PROPSHEET_ERROR      0xC0042009L

//
// MessageId: WPWIZ_ERROR_OUTOFMEMORY
//
// MessageText:
//
//  The Web Publishing Wizard has run out of memory. Please close other running applications before continuing.
//
#define WPWIZ_ERROR_OUTOFMEMORY          0xC004200AL

//
// MessageId: WPWIZ_ERROR_LAST
//
// MessageText:
//
//  Web Publishing Wizard last error message.
//
#define WPWIZ_ERROR_LAST                 0x400420FFL

