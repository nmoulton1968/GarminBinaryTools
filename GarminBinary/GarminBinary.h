/****************************************************************************
GARMIN BINARY EXPLORER for Garmin GPS Receivers that support serial I/O.

Copyright (C) 2016 Norm Moulton

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

****************************************************************************/
// GarminBinary.h : main header file for the GARMINBINARY application
//

#if !defined(AFX_GARMINBINARY_H__6D6FB20D_647B_4CFB_AF64_29BF5015A110__INCLUDED_)
#define AFX_GARMINBINARY_H__6D6FB20D_647B_4CFB_AF64_29BF5015A110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

// Main Resource Symbols
#include "resource.h"

// Define size specific types.
typedef unsigned char   t_UINT8;
typedef unsigned short  t_UINT16;
typedef unsigned int    t_UINT32;

// Due to late decoding, need space in payload for received message's
// checksum, DLE, and ETX bytes, therefore 3 extra.
enum { PAYLOAD_BYTES = 0xFF + 3 };
typedef struct
{
    t_UINT8 Start;
    t_UINT8 CmdId;
    t_UINT8 SizeBytes;
    t_UINT8 Payload[PAYLOAD_BYTES];
    t_UINT8 ChkSum;
    t_UINT8 End1;
    t_UINT8 End2;
} t_MSG_FORMAT;

typedef enum
{
    MSG_ACK        = 0x06,

    MSG_QUERY      = 0x0A,

    MSG_ASYNC_CMD  = 0x1C,
    MSG_PSEUD_RSP  = 0x38,

    MSG_BAUD_CMD   = 0x30,
    MSG_BAUD_RSP   = 0x31,

    MSG_PVT_RSP    = 0x33,

    MSG_LATLON_RSP = 0x11,
    MSG_UTC_RSP    = 0x0E,

    MSG_ID_CMD     = 0xFE,  // Cmd Request ID
    MSG_ID_RSP     = 0xFF,  // Rsp ID
    MSG_ID_EXT     = 0xFD,  // Rsp ID Extended

} e_MSG_TYPE;

typedef enum
{
    QUERY_LATLON   = 0x02,
    QUERY_UTC      = 0x05,
    QUERY_POS_ON   = 0x31,
    QUERY_POS_OFF  = 0x32,
    QUERY_CQCQ     = 0x3A,

} e_QUERY_TYPE;

static const char MONTH[13][4] =
{
    "---", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static const double PI = 3.1415926535897932;

/////////////////////////////////////////////////////////////////////////////
// CGarminBinaryApp:
// See GarminBinary.cpp for the implementation of this class
//

class CGarminBinaryApp : public CWinApp
{
public:
    CGarminBinaryApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CGarminBinaryApp)
public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CGarminBinaryApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GARMINBINARY_H__6D6FB20D_647B_4CFB_AF64_29BF5015A110__INCLUDED_)
