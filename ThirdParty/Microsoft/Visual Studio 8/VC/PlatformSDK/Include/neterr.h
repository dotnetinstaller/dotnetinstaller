//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1991-1999. All rights reserved.
//
//  MODULE: nmneterr.h
//
//  This is the top-level include file for all NETWORK topology error codes
//  Network Monitor driver network error codes -- DO NOT CHANGE!
//=============================================================================

#if !defined(_NMNETERR_)

#define _NMNETERR_

//=============================================================================
//  TOKENRING errors
//=============================================================================

#define NETERR_RING_STATUS_SIGNAL_LOST           0x00008000

#define NETERR_RING_STATUS_HARD_ERROR            0x00004000

#define NETERR_RING_STATUS_SOFT_ERROR            0x00002000

#define NETERR_RING_STATUS_TRANSMIT_BEACON       0x00001000

#define NETERR_RING_STATUS_LOBE_WIRE_FAULT       0x00000800

#define NETERR_RING_STATUS_AUTO_REMOVAL_ERROR    0x00000400

#define NETERR_RING_STATUS_REMOTE_RECEIVED       0x00000200

#define NETERR_RING_STATUS_COUNTER_OVERFLOW      0x00000100

#define NETERR_RING_STATUS_SIGNAL_STATION        0x00000080

#define NETERR_RING_STATUS_RECOVERY              0x00000040


//
// The following defines a bit mask to be compared with to see if
// the state of the ring should cause us to stop the current network
// capture.
//
// LobeWireFault, Signal Loss, Remove Received, and Auto Removal are
// currently the ones that fall into this category.
//
#define NETERR_RING_STOP_CAPTURE                 0x00008E00


//=============================================================================
//  ETHERNET errors
//=============================================================================

//=============================================================================
//  FDDI errors
//=============================================================================

#endif
