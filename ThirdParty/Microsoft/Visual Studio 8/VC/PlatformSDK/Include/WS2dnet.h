//************************************************************************
//  Winsock V2.0  DECnet definitions		File: WS2DNET.H 
//************************************************************************

#ifndef WS2DNET_H
#define WS2DNET_H

#include <winsock2.h>

#pragma pack(push,ws2dnet,1)
   
//
//  DECnet WinSock Definitions
//
#define DNPROTO_NSP      1  // DECnet NSP transport protocol
#define DNPROTO_RAW    255 

#define DN_MAXADDL      20  // maximum DECnet address length
#define DN_ADDL          2  // DECnet NSP address length
#define DN_MAXOPTL      16  // Maximum DECnet optional data length
#define DN_MAXOBJL      16  // Maximum DECnet object name length
#define DN_MAXACCL      39  // Maximum DECnet access string length
#define DN_MAXALIASL   128  // Maximum DECnet alias string length
#define DN_MAXNODEL      7  // Maximum DECnet Phase IV node string length

// DECnet Extension Function Identifiers
#define WS2API_DECNET_dnet_addr     1
#define WS2API_DECNET_dnet_eof      2
#define WS2API_DECNET_dnet_getacc   3
#define WS2API_DECNET_dnet_getalias 4
#define WS2API_DECNET_dnet_htoa     5
#define WS2API_DECNET_dnet_ntoa     6
#define WS2API_DECNET_getnodeadd    7
#define WS2API_DECNET_getnodebyaddr 8
#define WS2API_DECNET_getnodebyname 9
#define WS2API_DECNET_getnodename   10
#define WS2API_DECNET_MAX           10

//
//  DECnet address structure
//  
typedef struct dn_naddr {
	unsigned short	a_len;		        // length of address  
	unsigned char   a_addr[DN_MAXADDL]; // address as bytes  
} DNNADDR, FAR *LPDNNADDR;

//
//  DECnet socket address structure
//  
typedef struct sockaddr_dn {
	unsigned short	sdn_family;	    // AF_DECnet  
	unsigned char	sdn_flags;	    // flags  
	unsigned char	sdn_objnum;	    // object number  
	unsigned short	sdn_objnamel;	// size of object name  
	char sdn_objname[DN_MAXOBJL];	// object name  
	struct dn_naddr  sdn_add;	    // node address  
} SOCKADDRDN, FAR *LPSOCKADDRDN;

#define sdn_nodeaddrl	sdn_add.a_len	// node address length  
#define sdn_nodeaddr	sdn_add.a_addr 	// node address  

//  Common DECnet object numbers (used in sockaddr_dn)
#define DNOBJECT_FAL	17		// file access listener  
#define DNOBJECT_NICE	19		// network management  
#define DNOBJECT_DTERM	23		// remote terminals  
#define DNOBJECT_MIRROR	25		// loopback mirror  
#define DNOBJECT_EVR	26		// event receiver  
#define DNOBJECT_MAIL11	27		// Mail-11 service  
#define DNOBJECT_PHONE	29		// phone utility  
#define DNOBJECT_CTERM	42		// command terminals  
#define DNOBJECT_DTR	63		// data test receiver  

//
//  DECnet node structure
//
typedef struct	nodeent_f {
	char 		FAR * n_name;   // name of node  
	unsigned short	n_addrtype;	// node address type  
	unsigned short	n_length;	// address length
	unsigned char	FAR * n_addr;	// address  
	unsigned char	FAR * n_params;	// node parameters  
	unsigned char   n_reserved[16];	// Reserved
} NODEENTF, FAR *LPNODEENTF;                                          

//
//  DECnet set/get DSO_CONDATA, DSO_DISDATA (optional data) structure
//  
typedef struct optdata_dn {
	unsigned short	opt_status;	          // extended status return  
	unsigned short	opt_optl;	          // user data length 
	unsigned char   opt_data[DN_MAXOPTL]; // user data  
} OPTDATADN, FAR *LPOPTDATADN;

//
//  DECnet set/get DSO_CONACCESS access (control data) structure
//  
typedef struct accessdata_dn {
	unsigned short	acc_accl;	            // account string length 
	unsigned char	acc_acc[DN_MAXACCL+1];	// account string  
	unsigned short	acc_passl;	            // password string length  
	unsigned char	acc_pass[DN_MAXACCL+1];	// password string  
	unsigned short	acc_userl;	            // user string length 
	unsigned char	acc_user[DN_MAXACCL+1];	// user string  
} ACCESSDATADN, FAR *LPACCESSDATADN;

//
//  DECnet call data structure (concatenated access and optional data)
//
typedef struct calldata_dn { 
    struct optdata_dn       optdata_dn;
    struct accessdata_dn    accessdata_dn;
} CALLDATADN, FAR *LPCALLDATADN;   
    
//
//  DECnet incoming access control structure
//
typedef struct dnet_accent {
    unsigned char dac_status;      // Reserved 
    unsigned char dac_type;        // DN_NONE, etc.      
    char dac_username[DN_MAXACCL+1];  
    char dac_password[DN_MAXACCL+1]; 
} DNETACCENT, FAR *LPDNETACCENT;

#define DN_NONE          0x00   
#define DN_RO            0x01
#define DN_WO            0x02
#define DN_RW            0x03

// DECnet logical link information structure
typedef struct linkinfo_dn {
	unsigned short	idn_segsize;	/* segment size for link */
	unsigned char	idn_linkstate;	/* logical link state */
}LINKINFODN, FAR *LPLINKINFODN;

#define SO_LINKINFO	        7		/* set/get link information */
#define LL_INACTIVE		    0		/* logical link inactive */
#define LL_CONNECTING	    1		/* logical link connecting */
#define LL_RUNNING		    2		/* logical link running */
#define LL_DISCONNECTING	3		/* logical link disconnecting */

#pragma pack(pop,ws2dnet)

//*********************************************************************
//  DECnet WinSock 2 extended function prototypes	
//*********************************************************************  
struct dn_naddr FAR *WSAAPI dnet_addr(const char FAR *);
int WSAAPI dnet_eof(SOCKET);
struct dnet_accent FAR *WSAAPI dnet_getacc(const struct dnet_accent FAR *);
char FAR *WSAAPI dnet_getalias(const char FAR *);
char FAR *WSAAPI dnet_htoa(const struct dn_naddr FAR *);
char FAR *WSAAPI dnet_ntoa(const struct dn_naddr FAR *);
struct dn_naddr FAR *WSAAPI getnodeadd(void);
struct nodeent_f FAR *WSAAPI getnodebyaddr(const unsigned char FAR *addr, int, int);
struct nodeent_f FAR *WSAAPI getnodebyname(const char FAR *);
char FAR *WSAAPI getnodename(void);

// typedefs for C++ compatability
typedef struct dn_naddr FAR * (WSAAPI * LPDNETADDR)(const char FAR *);
typedef int (WSAAPI * LPDNETEOF)(SOCKET);
typedef struct dnet_accent FAR * (WSAAPI * LPDNETGETACC)(const struct 
dnet_accent FAR *);
typedef char FAR * (WSAAPI * LPDNETGETALIAS)(const char FAR *);
typedef char FAR * (WSAAPI * LPDNETHTOA)(const struct dn_naddr FAR *);
typedef char FAR * (WSAAPI * LPDNETNTOA)(const struct dn_naddr FAR *);
typedef struct dn_naddr FAR * (WSAAPI * LPGETNODEADD)(void);
typedef struct nodeent_f FAR * (WSAAPI * LPGETNODEBYADDR)(const unsigned 
char FAR *addr, int, int);
typedef struct nodeent_f FAR * (WSAAPI * LPGETNODEBYNAME)(const char FAR 
*);
typedef char FAR * (WSAAPI * LPGETNODENAME)(void);

#endif	// WS2DNET_H  
