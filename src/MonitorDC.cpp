//////////////////////////////////////////////////
// CMonitor - wrapper to Win32 multi-monitor API
//
// Author: Donald Kackman
// Email:  dkackman_2000@yahoo.com
// Copyright 2002, Donald Kackman
//
// You may freely use or modify this code provided this
// Copyright is included in all derived versions.
//
///////////////////////////////////////////////////

//
//David Campbell's article
//How to Exploit Multiple Monitor Support in Memphis and Windows NT 5.0
//is very helpful for multimonitor api calls
//http://www.microsoft.com/msj/defaultframe.asp?page=/msj/0697/monitor/monitor.htm&nav=/msj/0697/newnav.htm
//
// MonitorDC.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorDC.h"
#include "MultiMonitor.h"

// CMonitorDC

CMonitorDC::CMonitorDC(CMonitor* pMonitor)
{
	ASSERT( pMonitor );
	ASSERT( pMonitor->IsMonitor() );

	VERIFY( Attach( pMonitor->CreateDC() ) );
}

CMonitorDC::~CMonitorDC()
{
	VERIFY( DeleteDC() );
}

// CMonitorDC member functions
