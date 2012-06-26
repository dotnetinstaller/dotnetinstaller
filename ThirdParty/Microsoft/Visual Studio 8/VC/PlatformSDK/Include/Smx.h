/**********************************************************************/
/**                       Microsoft Windows NT                       **/
/**          Copyright(c) Microsoft Corporation 1992 - 1999          **/
/**********************************************************************/

/*
    smx.h
    This file contains the common messages, manifests, types, and
    structures used by Server Manager Extensions.

    NOTE:  You must include windows.h and lmcons.h *before* this file.
*/



#ifndef _SMX_H_
#define _SMX_H_



//
//  This is the maximum length allowed for an extension menu item.
//

#define MENU_TEXT_LEN                   50



//
//  This is the current version number of the extension interface.
//

#define SME_VERSION                     0



//
//  These are the messages sent from the extension to the
//  Server Manager application.
//
//      SM_GETSELCOUNT
//
//              Purpose - Retrieves the number of selected items in
//                        the specified listbox.
//
//              wParam  - Listbox index.  This 0-based index specifies
//                        the listbox to query.  For the Server Manager,
//                        this must always be zero.
//
//              lParam  - Points to an SMS_GETSELCOUNT structure.
//
//              Returns - TRUE  if successful, FALSE if unsuccessful.
//
//
//      SM_GETSERVERSEL[A]
//
//              Purpose - Retrieves a particular selection.
//
//              wParam  - Selection index.  This 0-based index specifies
//                        the selected item to query.  This is useful
//                        for muliple-select listboxes.  Since the Server
//                        manager uses a single-select listbox, this
//                        value must always be zero.
//
//              lParam  - Points to an SMS_GETSERVERSEL[AW] structure.
//
//              Returns - TRUE  if successful, FALSE if unsuccessful.
//
//      SM_GETCURFOCUS[AW]
//
//              Purpose - Retrieves the current application focus.
//
//              wParam  - Must be zero.
//
//              lParam  - Points to a SMS_GETCURFOCUS structure.
//
//              Returns - TRUE if successful, FALSE if unsuccessful.
//
//
//      SM_GETOPTIONS
//
//              Purpose - Retrieves the current option settings
//
//              wParam  - Must be zero.
//
//              lParam  - Points to a SMS_GETOPTIONS structure.
//
//              Returns - TRUE if successful, FALSE if unsuccessful.
//

#define SM_GETSELCOUNT                  (WM_USER + 1000)
#define SM_GETSERVERSELA                (WM_USER + 1001)
#define SM_GETSERVERSELW                (WM_USER + 1002)
#define SM_GETCURFOCUSA                 (WM_USER + 1003)
#define SM_GETCURFOCUSW                 (WM_USER + 1004)
#define SM_GETOPTIONS                   (WM_USER + 1005)

#ifdef UNICODE
#define SM_GETSERVERSEL                 SM_GETSERVERSELW
#define SM_GETCURFOCUS                  SM_GETCURFOCUSW
#else   // !UNICODE
#define SM_GETSERVERSEL                 SM_GETSERVERSELA
#define SM_GETCURFOCUS                  SM_GETCURFOCUSA
#endif  // UNICODE



//
//  These structures are used when the extension is
//  communicating with the application.
//


//
//  The SMS_LOADMENU[AW] structure is passed to the extension's
//  SMELoadMenu[AW] entrypoint when the extension is loaded.
//
//      dwVersion       - On entry to SMELoadMenu[AW], this will
//                        contain the maximum extension version
//                        supported by the Server Manager.  If the
//                        extension supports a lower version, it
//                        should set this field appropriately before
//                        returning.  The Server Manager will use
//                        the returned value to determine the
//                        capabilities of the extension.
//
//      szMenuName      - The name of the menu item that is to appear
//                        in the app's main menu.  This value will also
//                        appear in the "Help On Extensions" submene and
//                        the "View" menu.
//
//      hMenu           - A valid HMENU for the popup-menu to be inserted
//                        into the app's main menu.  Ownership of this
//                        handle transfers to the Server Manager.  The
//                        extension should *not* destroy this handle.
//
//      szHelpFileName  - The name of the help file associated with this
//                        extension.  This file will be used for the
//                        "Help On Extensions" menu.  This will also be
//                        used when the user presses [F1] while the
//                        extension's menu is dropped.
//
//      dwServerType    - A bitmask containing the appropriate server type
//                        bit associated with the extension.  It is
//                        assumed that each extension will be associated
//                        with a unique server type.  For example,
//                        SV_TYPE_WFW represents Windows for Workgroups
//                        servers.
//
//      dwMenuDelta     - The Server Manager will apply this delta
//                        to each menu ID present in hMenu.  This is
//                        to prevent conflicts with other extension's
//                        menu IDs.
//

typedef struct _SMS_LOADMENUA
{
    DWORD       dwVersion;
    CHAR        szMenuName[MENU_TEXT_LEN + 1];
    HMENU       hMenu;
    CHAR        szHelpFileName[MAX_PATH];
    DWORD       dwServerType;
    DWORD       dwMenuDelta;

} SMS_LOADMENUA, * PSMS_LOADMENUA;

typedef struct _SMS_LOADMENUW
{
    DWORD       dwVersion;
    WCHAR       szMenuName[MENU_TEXT_LEN + 1];
    HMENU       hMenu;
    WCHAR       szHelpFileName[MAX_PATH];
    DWORD       dwServerType;
    DWORD       dwMenuDelta;

} SMS_LOADMENUW, * PSMS_LOADMENUW;

#ifdef UNICODE
#define SMS_LOADMENU                    SMS_LOADMENUW
#define PSMS_LOADMENU                   PSMS_LOADMENUW
#else   // !UNICODE
#define SMS_LOADMENU                    SMS_LOADMENUA
#define PSMS_LOADMENU                   PSMS_LOADMENUA
#endif  // UNICODE


//
//  The SMS_GETSERVERSEL[AW] structure is filled in by the
//  Server Manager when it handles SM_GETSERVERSEL[AW] messages.
//  This is used to return the current selection to the extension.
//
//      szServerName    - Will receive the UNC name of the selected
//                        server.
//
//      dwServerType    - Will receive the server type mask associated
//                        with the server.  This field may be 0 if
//                        the type is unknown.
//

typedef struct _SMS_GETSERVERSELA
{
    CHAR        szServerName[MAX_PATH];
    DWORD       dwServerType;

} SMS_GETSERVERSELA, * PSMS_GETSERVERSELA;

typedef struct _SMS_GETSERVERSELW
{
    WCHAR       szServerName[MAX_PATH];
    DWORD       dwServerType;

} SMS_GETSERVERSELW, * PSMS_GETSERVERSELW;

#ifdef UNICODE
#define SMS_GETSERVERSEL                SMS_GETSERVERSELW
#define PSMS_GETSERVERSEL               PSMS_GETSERVERSELW
#else   // !UNICODE
#define SMS_GETSERVERSEL                SMS_GETSERVERSELA
#define PSMS_GETSERVERSEL               PSMS_GETSERVERSELA
#endif  // UNICODE


//
//  The SMS_GETSELCOUNT structure is filled in by the Server Manager
//  when it handles the SM_GETSELCOUNT message.  This is used to
//  return the number of selected items to the extension.  In the
//  current implementation, this will be either 0 (empty listbox)
//  or 1 (single selection).
//
//      dwItems         - The number of selected items in the listbox.
//

typedef struct _SMS_GETSELCOUNT
{
    DWORD       dwItems;
} SMS_GETSELCOUNT, * PSMS_GETSELCOUNT;


//
//  The SMS_GETCURFOCUS[AW] structure is filled in by the Server Manager
//  when it handles the SM_GETCURFOCUS message.  This is used to
//  return the current focus of the User Manager application.
//
//      szFocus         - The domain name or server name of the current
//                        focus.  Server names can be distinguished
//                        by the leading backslashes, or by dwFocusType.
//
//      dwFocusType     - This is the type of focus, either
//                        SM_FOCUS_TYPE_NT_DOMAIN
//                        SM_FOCUS_TYPE_LM_DOMAIN
//                        SM_FOCUS_TYPE_UNKNOWN_DOMAIN
//                        SM_FOCUS_TYPE_NT_SERVER
//                        SM_FOCUS_TYPE_LM_SERVER
//                        SM_FOCUS_TYPE_WFW_SERVER
//                        SM_FOCUS_TYPE_UNKNOWN_SERVER
//

#define SM_FOCUS_TYPE_NT_DOMAIN         1
#define SM_FOCUS_TYPE_LM_DOMAIN         2
#define SM_FOCUS_TYPE_UNKNOWN_DOMAIN    3
#define SM_FOCUS_TYPE_NT_SERVER         4
#define SM_FOCUS_TYPE_LM_SERVER         5
#define SM_FOCUS_TYPE_WFW_SERVER        6
#define SM_FOCUS_TYPE_UNKNOWN_SERVER    7

typedef struct _SMS_GETCURFOCUSA
{
    CHAR        szFocus[MAX_PATH];
    DWORD       dwFocusType;

} SMS_GETCURFOCUSA, * PSMS_GETCURFOCUSA;

typedef struct _SMS_GETCURFOCUSW
{
    WCHAR       szFocus[MAX_PATH];
    DWORD       dwFocusType;

} SMS_GETCURFOCUSW, * PSMS_GETCURFOCUSW;

#ifdef UNICODE
#define SMS_GETCURFOCUS             SMS_GETCURFOCUSW
#define PSMS_GETCURFOCUS            PSMS_GETCURFOCUSW
#else   // UNICODE
#define SMS_GETCURFOCUS             SMS_GETCURFOCUSA
#define PSMS_GETCURFOCUS            PSMS_GETCURFOCUSA
#endif  // UNICODE


//
//  The SMS_GETOPTIONS structure is filled in by the Server Manager
//  when it handles the SM_GETOPTIONS message.  This is used to
//  return the current option settings of the Server Manager
//  application.
//
//      fSaveSettingsOnExit     - Should Server Manager settings be saved
//                                on exit?
//
//      fConfirmation           - Should permanent and/or dangerous
//                                actions be confirmed?  In the current
//                                Server Manager implementation, this
//                                will always be TRUE.
//

typedef struct _SMS_GETOPTIONS
{
    BOOL        fSaveSettingsOnExit;
    BOOL        fConfirmation;

} SMS_GETOPTIONS, * PSMS_GETOPTIONS;


//
//  The SMS_VALIDATE[AW] structure is passed between the Server Manager
//  application and the extension to validate a particular "alien"
//  (non-LANMan) server.
//
//      pszServer       - The (UNC) name of the server to validate.  This
//                        is filled in by the Server Manager.
//
//      pszType         - The type string to display in the Server Manager's
//                        main window.  This is filled in by the extension.
//
//      pszComment      - The comment to display in the Server Manager's
//                        main window.  This is filled in by the extension.
//

typedef struct _SMS_VALIDATEA
{
    const CHAR * pszServer;
    CHAR       * pszType;
    CHAR       * pszComment;

} SMS_VALIDATEA, * PSMS_VALIDATEA;

typedef struct _SMS_VALIDATEW
{
    const WCHAR * pszServer;
    WCHAR       * pszType;
    WCHAR       * pszComment;

} SMS_VALIDATEW, * PSMS_VALIDATEW;

#ifdef UNICODE
#define SMS_VALIDATE                SMS_VALIDATEW
#define PSMS_VALIDATE               PSMS_VALIDATEW
#else   // UNICODE
#define SMS_VALIDATE                SMS_VALIDATEA
#define PSMS_VALIDATE               PSMS_VALIDATEA
#endif  // UNICODE



//
//  These are the names of the extension entrypoints.
//

#define SZ_SME_UNLOADMENU               "SMEUnloadMenu"
#define SZ_SME_INITIALIZEMENU           "SMEInitializeMenu"
#define SZ_SME_REFRESH                  "SMERefresh"
#define SZ_SME_MENUACTION               "SMEMenuAction"

#define SZ_SME_LOADMENUW                "SMELoadMenuW"
#define SZ_SME_GETEXTENDEDERRORSTRINGW  "SMEGetExtendedErrorStringW"
#define SZ_SME_VALIDATEW                "SMEValidateW"

#define SZ_SME_LOADMENUA                "SMELoadMenuA"
#define SZ_SME_GETEXTENDEDERRORSTRINGA  "SMEGetExtendedErrorStringA"
#define SZ_SME_VALIDATEA                "SMEValidateA"

#ifdef UNICODE
#define SZ_SME_LOADMENU                 SZ_SME_LOADMENUW
#define SZ_SME_GETEXTENDEDERRORSTRING   SZ_SME_GETEXTENDEDERRORSTRINGW
#define SZ_SME_VALIDATE                 SZ_SME_VALIDATEW
#else   // !UNICODE
#define SZ_SME_LOADMENU                 SZ_SME_LOADMENUA
#define SZ_SME_GETEXTENDEDERRORSTRING   SZ_SME_GETEXTENDEDERRORSTRINGA
#define SZ_SME_VALIDATE                 SZ_SME_VALIDATEA
#endif  // UNICODE



//
//  Typedefs for the extension entrypoints.
//

typedef DWORD (PASCAL * PSMX_LOADMENU)( HWND          hWnd,
                                        PSMS_LOADMENU psmsload );

typedef LPTSTR (PASCAL * PSMX_GETEXTENDEDERRORSTRING)( VOID );

typedef VOID (PASCAL * PSMX_UNLOADMENU)( VOID );

typedef VOID (PASCAL * PSMX_INITIALIZEMENU)( VOID );

typedef VOID (PASCAL * PSMX_REFRESH)( HWND hwndParent );

typedef VOID (PASCAL * PSMX_MENUACTION)( HWND hwndParent, DWORD dwEventId );

typedef BOOL (PASCAL * PSMX_VALIDATE)( PSMS_VALIDATE psmsvalidate );



//
//  Prototypes for the extension entrypoints.
//

DWORD PASCAL SMELoadMenuA( HWND           hWnd,
                           PSMS_LOADMENUA psmsload );

DWORD PASCAL SMELoadMenuW( HWND           hWnd,
                           PSMS_LOADMENUW psmsload );

LPSTR  PASCAL SMEGetExtendedErrorStringA( VOID );

LPWSTR PASCAL SMEGetExtendedErrorStringW( VOID );

VOID PASCAL SMEUnloadMenu( VOID );

VOID PASCAL SMEInitializeMenu( VOID );

VOID PASCAL SMERefresh( HWND hwndParent );

VOID PASCAL SMEMenuAction( HWND hwndParent, DWORD dwEventId );

BOOL PASCAL SMEValidateA( PSMS_VALIDATEA psmsValidate );

BOOL PASCAL SMEValidateW( PSMS_VALIDATEW psmsValidate );



#endif  // _SMX_H_
