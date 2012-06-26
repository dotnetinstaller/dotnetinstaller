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
// MessageId: WEBPOST_ERROR_FIRST
//
// MessageText:
//
//  Web Publishing Wizard first error message.
//
#define WEBPOST_ERROR_FIRST              0x40042100L

//
// MessageId: WEBPOST_ERROR_UNKNOWN
//
// MessageText:
//
//  An unknown error occurred in the Web Publishing Wizard.
//
#define WEBPOST_ERROR_UNKNOWN            0xC0042101L

//
// MessageId: WEBPOST_ERROR_PROVCLSID_UNKNOWN
//
// MessageText:
//
//  The Web Publishing Wizard could not locate the service provider used to transfer files to your Web server.
//
#define WEBPOST_ERROR_PROVCLSID_UNKNOWN  0xC0042102L

//
// MessageId: WEBPOST_ERROR_SITE_CORRUPT
//
// MessageText:
//
//  The Web Publishing Wizard could not retrieve all of the required information about your Web server.
//
#define WEBPOST_ERROR_SITE_CORRUPT       0xC0042103L

//
// MessageId: WEBPOST_ERROR_PROV_CORRUPT
//
// MessageText:
//
//  The Web Publishing Wizard could not retrieve all of the required information about this service provider.
//
#define WEBPOST_ERROR_PROV_CORRUPT       0xC0042104L

//
// MessageId: WEBPOST_ERROR_PROV_DLL
//
// MessageText:
//
//  The Web Publishing Wizard could not locate the file(s) for the requested service provider.
//
#define WEBPOST_ERROR_PROV_DLL           0xC0042105L

//
// MessageId: WEBPOST_ERROR_PROV_EP
//
// MessageText:
//
//  The file(s) for the requested service provider are either corrupt or outdated.
//
#define WEBPOST_ERROR_PROV_EP            0xC0042106L

//
// MessageId: WEBPOST_ERROR_INIT_FAILED
//
// MessageText:
//
//  An error occurred while attempting to start the Web Publishing Wizard.
//
#define WEBPOST_ERROR_INIT_FAILED        0xC0042107L

//
// MessageId: WEBPOST_ERROR_LIST_SITES
//
// MessageText:
//
//  An error occurred while the Web Publishing Wizard was enumerating the Web servers to which you have previously published.
//
#define WEBPOST_ERROR_LIST_SITES         0xC0042108L

//
// MessageId: WEBPOST_ERROR_SITE_EXISTS
//
// MessageText:
//
//  The Web Publishing Wizard could not use the requested descriptive name for your Web server because another Web server already uses the name.
//
#define WEBPOST_ERROR_SITE_EXISTS        0xC0042109L

//
// MessageId: WEBPOST_ERROR_CREATE_SITE
//
// MessageText:
//
//  An error occurred while the Web Publishing Wizard was saving information about your Web server.
//
#define WEBPOST_ERROR_CREATE_SITE        0xC004210AL

//
// MessageId: WEBPOST_ERROR_SITE_DOESNOTEXIST
//
// MessageText:
//
//  Your computer does not contain any information about the Web server you have selected.
//
#define WEBPOST_ERROR_SITE_DOESNOTEXIST  0xC004210BL

//
// MessageId: WEBPOST_ERROR_DELETE_SITE
//
// MessageText:
//
//  An error occurred while the Web Publishing Wizard was deleting information about your Web server.
//
#define WEBPOST_ERROR_DELETE_SITE        0xC004210CL

//
// MessageId: WEBPOST_ERROR_ENUM_PROVS
//
// MessageText:
//
//  An error occurred while the Web Publishing Wizard was enumerating the service providers on this system.
//
#define WEBPOST_ERROR_ENUM_PROVS         0xC004210DL

//
// MessageId: WEBPOST_ERROR_PROV_QI
//
// MessageText:
//
//  The Web Publishing Wizard was unable to determine the version number of your service provider.
//
#define WEBPOST_ERROR_PROV_QI            0xC004210EL

//
// MessageId: WEBPOST_ERROR_POST_FILES
//
// MessageText:
//
//  An error occurred while the Web Publishing Wizard was attempting to publish your files.
//
#define WEBPOST_ERROR_POST_FILES         0xC004210FL

//
// MessageId: WEBPOST_ERROR_COCREATE_WIZARD
//
// MessageText:
//
//  The Web Publishing Wizard is not installed correctly. Please uninstall and then reinstall the wizard.
//
#define WEBPOST_ERROR_COCREATE_WIZARD    0xC0042110L

//
// MessageId: WEBPOST_ERROR_POSTINFO_REQUIRED
//
// MessageText:
//
//  Your service provider requires that a PostInfo file be located on the server. No PostInfo file could be located.
//
#define WEBPOST_ERROR_POSTINFO_REQUIRED  0xC0042111L

//
// MessageId: WEBPOST_ERROR_AUTOBIND_FAILED
//
// MessageText:
//
//  The service provider could not be automatically selected for your Web server.
//
#define WEBPOST_ERROR_AUTOBIND_FAILED    0xC0042112L

//
// MessageId: WEBPOST_ERROR_BAD_PROV_PTR
//
// MessageText:
//
//  The Web Publishing Wizard was not able to obtain a valid pointer to the requested service provider.
//
#define WEBPOST_ERROR_BAD_PROV_PTR       0xC0042113L

//
// MessageId: WEBPOST_ERROR_PROV_NOT_IN_POSTINFO
//
// MessageText:
//
//  The Web server you selected does not indicate support for the service provider you selected.
//
#define WEBPOST_ERROR_PROV_NOT_IN_POSTINFO 0x80042114L

//
// MessageId: WEBPOST_ERROR_EXTENDED_ERROR
//
// MessageText:
//
//  Web Publishing Wizard extended error.
//
#define WEBPOST_ERROR_EXTENDED_ERROR     0xC0042116L

//
// MessageId: WEBPOST_ERROR_NO_EXT_ERR_INFO
//
// MessageText:
//
//  An extended error occurred in the Web Publishing Wizard, but the error message could not be retrieved.
//
#define WEBPOST_ERROR_NO_EXT_ERR_INFO    0xC0042117L

//
// MessageId: WEBPOST_ERROR_INVALID_POSTINFO
//
// MessageText:
//
//  The PostInfo file on the server is invalid.
//
#define WEBPOST_ERROR_INVALID_POSTINFO   0x40042118L

//
// MessageId: WEBPOST_ERROR_NO_POSTINFO
//
// MessageText:
//
//  There is no PostInfo file on the server.
//
#define WEBPOST_ERROR_NO_POSTINFO        0x40042119L

//
// MessageId: WEBPOST_ERROR_HTTP_GET_FAILED
//
// MessageText:
//
//  The Web Publishing Wizard was not able to retrieve the first file published using an HTTP connection.
//
#define WEBPOST_ERROR_HTTP_GET_FAILED    0x4004211AL

//
// MessageId: WEBPOST_ERROR_LAST
//
// MessageText:
//
//  Web Publishing Wizard last error message.
//
#define WEBPOST_ERROR_LAST               0x400421FFL

