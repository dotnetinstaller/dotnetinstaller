// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Inlines for AFXCMN.H
// Contains wrappers for API's messages not in all supported
// platforms

#if (_WIN32_WINNT >= 0x0501)

#include <atlchecked.h>

AFX_INLINE HRESULT CToolTipCtrl::SetWindowTheme(LPCWSTR pszSubAppName)
	{ ASSERT(::IsWindow(m_hWnd)); return (HRESULT)::SendMessage(m_hWnd, TTM_SETWINDOWTHEME, 0, (LPARAM)pszSubAppName); }

AFX_INLINE HRESULT CComboBoxEx::SetWindowTheme(LPCWSTR pszSubAppName)
	{ ASSERT(::IsWindow(m_hWnd)); return (HRESULT)::SendMessage(m_hWnd, CBEM_SETWINDOWTHEME, 0, (LPARAM)pszSubAppName); }

AFX_INLINE void CReBarCtrl::GetBandMargins(PMARGINS pMargins)
	{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, RB_GETBANDMARGINS, 0, (LPARAM)pMargins); }

AFX_INLINE HRESULT CReBarCtrl::SetWindowTheme(LPCWSTR pszSubAppName)
	{ ASSERT(::IsWindow(m_hWnd)); return (HRESULT)::SendMessage(m_hWnd, RB_SETWINDOWTHEME, 0, (LPARAM)pszSubAppName); }

AFX_INLINE void CToolBarCtrl::GetMetrics(LPTBMETRICS ptbm) const
{ 
	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT(ptbm != NULL);
	::SendMessage(m_hWnd, TB_GETMETRICS, 0, (LPARAM)ptbm); 
}

AFX_INLINE void CToolBarCtrl::SetMetrics(LPTBMETRICS ptbm)
{ 
	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT(ptbm != NULL);
	::SendMessage(m_hWnd, TB_SETMETRICS, 0, (LPARAM)ptbm); 
}

AFX_INLINE HRESULT CToolBarCtrl::SetWindowTheme(LPCWSTR pszSubAppName)
	{ ASSERT(::IsWindow(m_hWnd)); return (HRESULT)::SendMessage(m_hWnd, TB_SETWINDOWTHEME, 0, (LPARAM)pszSubAppName); }

AFX_INLINE LRESULT CListCtrl::SetSelectedColumn(int iCol)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_SetSelectedColumn(m_hWnd, iCol);
}
AFX_INLINE DWORD CListCtrl::SetView(int iView)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_SetView(m_hWnd, iView);
}
AFX_INLINE DWORD CListCtrl::GetView() const
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_GetView(m_hWnd);
}
AFX_INLINE LRESULT CListCtrl::InsertGroup(int index, PLVGROUP pgrp)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_InsertGroup(m_hWnd, index, pgrp);
}
AFX_INLINE int CListCtrl::SetGroupInfo(int iGroupId, PLVGROUP pgrp)
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)ListView_SetGroupInfo(m_hWnd, iGroupId, pgrp);
}
AFX_INLINE int CListCtrl::GetGroupInfo(int iGroupId, PLVGROUP pgrp) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)ListView_GetGroupInfo(m_hWnd, iGroupId, pgrp);
}
AFX_INLINE LRESULT CListCtrl::RemoveGroup(int iGroupId)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_RemoveGroup(m_hWnd, iGroupId);
}
AFX_INLINE LRESULT CListCtrl::MoveGroup(int iGroupId, int toIndex)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_MoveGroup(m_hWnd, iGroupId, toIndex);
}
AFX_INLINE LRESULT CListCtrl::MoveItemToGroup(int idItemFrom, int idGroupTo)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_MoveItemToGroup(m_hWnd, idItemFrom, idGroupTo);
}
AFX_INLINE void CListCtrl::SetGroupMetrics(PLVGROUPMETRICS pGroupMetrics)
{
	ASSERT(::IsWindow(m_hWnd));
	ListView_SetGroupMetrics(m_hWnd, pGroupMetrics);
}
AFX_INLINE void CListCtrl::GetGroupMetrics(PLVGROUPMETRICS pGroupMetrics) const
{
	ASSERT(::IsWindow(m_hWnd));
	ListView_GetGroupMetrics(m_hWnd, pGroupMetrics);
}
AFX_INLINE LRESULT CListCtrl::EnableGroupView(BOOL fEnable)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_EnableGroupView(m_hWnd, fEnable);
}
AFX_INLINE BOOL CListCtrl::SortGroups(PFNLVGROUPCOMPARE _pfnGroupCompare, LPVOID _plv)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, LVM_SORTGROUPS, (WPARAM)(LPARAM)_plv, (LPARAM)_pfnGroupCompare );
}
AFX_INLINE LRESULT CListCtrl::InsertGroupSorted(PLVINSERTGROUPSORTED pStructInsert)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_InsertGroupSorted(m_hWnd, pStructInsert);
}
AFX_INLINE void CListCtrl::RemoveAllGroups()
{
	ASSERT(::IsWindow(m_hWnd));
	ListView_RemoveAllGroups(m_hWnd);
}
AFX_INLINE BOOL CListCtrl::HasGroup(int iGroupId) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_HasGroup(m_hWnd, iGroupId);
}
AFX_INLINE BOOL CListCtrl::SetTileViewInfo(PLVTILEVIEWINFO ptvi)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_SetTileViewInfo(m_hWnd, ptvi);
}
AFX_INLINE BOOL CListCtrl::GetTileViewInfo(PLVTILEVIEWINFO ptvi) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_GetTileViewInfo(m_hWnd, ptvi);
}
AFX_INLINE BOOL CListCtrl::SetTileInfo(PLVTILEINFO pti)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_SetTileInfo(m_hWnd, pti);
}
AFX_INLINE BOOL CListCtrl::GetTileInfo(PLVTILEINFO pti) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_GetTileInfo(m_hWnd, pti);
}
AFX_INLINE BOOL CListCtrl::SetInsertMark(LPLVINSERTMARK lvim)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_SetInsertMark(m_hWnd, lvim);
}
AFX_INLINE BOOL CListCtrl::GetInsertMark(LPLVINSERTMARK lvim) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)ListView_GetInsertMark(m_hWnd, lvim);
}
AFX_INLINE int CListCtrl::InsertMarkHitTest(LPPOINT pPoint, LPLVINSERTMARK lvim) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)ListView_InsertMarkHitTest(m_hWnd, pPoint, lvim);
}
AFX_INLINE int CListCtrl::GetInsertMarkRect(LPRECT pRect) const
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)ListView_GetInsertMarkRect(m_hWnd, pRect);
}
AFX_INLINE COLORREF CListCtrl::SetInsertMarkColor(COLORREF color)
{
	ASSERT(::IsWindow(m_hWnd));
	return (COLORREF)ListView_SetInsertMarkColor(m_hWnd, color);
}
AFX_INLINE COLORREF CListCtrl::GetInsertMarkColor() const
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_GetInsertMarkColor(m_hWnd);
}
AFX_INLINE BOOL CListCtrl::SetInfoTip(PLVSETINFOTIP plvInfoTip)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_SetInfoTip(m_hWnd, plvInfoTip);
}
AFX_INLINE UINT CListCtrl::GetSelectedColumn() const
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_GetSelectedColumn(m_hWnd);
}
AFX_INLINE BOOL CListCtrl::IsGroupViewEnabled() const
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_IsGroupViewEnabled(m_hWnd);
}
AFX_INLINE COLORREF CListCtrl::GetOutlineColor() const
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_GetOutlineColor(m_hWnd);
}
AFX_INLINE COLORREF CListCtrl::SetOutlineColor(COLORREF color)
{
	ASSERT(::IsWindow(m_hWnd));
	return ListView_SetOutlineColor(m_hWnd, color);
}
AFX_INLINE void CListCtrl::CancelEditLabel()
{
	ASSERT(::IsWindow(m_hWnd));
	ListView_CancelEditLabel(m_hWnd);
}

/////////////////////////////////////////////////////////////////////////////
// CLinkCtrl

AFX_INLINE CLinkCtrl::CLinkCtrl()
{ }

AFX_INLINE CLinkCtrl::~CLinkCtrl()
{
	DestroyWindow();
}

// Attributes
AFX_INLINE int CLinkCtrl::GetIdealHeight() const
{
	ASSERT(::IsWindow(m_hWnd));
	return (int) ::SendMessage(m_hWnd, LM_HITTEST, 0, 0);
}

// operations	
AFX_INLINE BOOL CLinkCtrl::SetItem(PLITEM pItem)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(pItem != NULL);
	return (BOOL) ::SendMessage(m_hWnd, LM_SETITEM, 0, (LPARAM)pItem);
}

AFX_INLINE BOOL CLinkCtrl::SetItemID(int iLink, LPCWSTR szID)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(lstrlenW(szID) <= MAX_LINKID_TEXT);
	if (lstrlenW(szID) > MAX_LINKID_TEXT)
		return FALSE;	

	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_ITEMID;
	item.iLink = iLink;
	::ATL::Checked::wcscpy_s(item.szID, _countof(item.szID), szID);	

	return SetItem(&item);
}

AFX_INLINE BOOL CLinkCtrl::SetItemUrl(int iLink, LPCWSTR szUrl)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(lstrlenW(szUrl) <= L_MAX_URL_LENGTH);
	if (lstrlenW(szUrl) >= L_MAX_URL_LENGTH)
		return FALSE;

	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_URL;
	item.iLink = iLink;
	::ATL::Checked::wcscpy_s(item.szUrl, _countof(item.szUrl), szUrl);	

	return SetItem(&item);
}

AFX_INLINE BOOL CLinkCtrl::SetItemState(int iLink, UINT state, UINT stateMask /*= 0xFFFFFFFF*/)
{
	ASSERT(::IsWindow(m_hWnd));
	LITEM item;		
	item.mask = LIF_ITEMINDEX | LIF_STATE;
	item.iLink = iLink;
	item.state = state;
	item.stateMask = stateMask;

	return SetItem(&item);
}

AFX_INLINE BOOL CLinkCtrl::GetItem(PLITEM pItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(pItem != NULL);
	return (BOOL) ::SendMessage(m_hWnd, LM_GETITEM, 0, (LPARAM)pItem);
}

AFX_INLINE BOOL CLinkCtrl::GetItemID(int iLink, CString& strID) const
{
	ASSERT(::IsWindow(m_hWnd));
	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_ITEMID;
	item.iLink = iLink;

	if (!GetItem(&item))
		return FALSE;

	strID = item.szID;
	return TRUE;
}

AFX_INLINE BOOL CLinkCtrl::GetItemID(__in int iLink, __out_ecount_z(cchID) LPWSTR szID, __in UINT cchID) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(szID != NULL);
	ASSERT(cchID >= MAX_LINKID_TEXT);
	if (szID!=NULL)
	{
		szID[0]=L'\0';
	}
	if (szID == NULL || cchID < MAX_LINKID_TEXT)
		return FALSE;

	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_ITEMID;
	item.iLink = iLink;

	if (!GetItem(&item))
		return FALSE;

	::ATL::Checked::wcscpy_s(szID, cchID, item.szID);
	return TRUE;
}

AFX_INLINE BOOL CLinkCtrl::GetItemUrl(int iLink, CString& strUrl) const
{
	ASSERT(::IsWindow(m_hWnd));
	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_URL;
	item.iLink = iLink;

	if (!GetItem(&item))
		return FALSE;

	strUrl = item.szUrl;
	return TRUE;
}

AFX_INLINE BOOL CLinkCtrl::GetItemUrl(__in int iLink, __out_ecount_z(cchUrl) LPWSTR szUrl, __in UINT cchUrl) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(szUrl != NULL);
	ASSERT(cchUrl >= L_MAX_URL_LENGTH);
	if(szUrl!=NULL)
	{
		szUrl[0]=L'\0';
	}
	if (szUrl == NULL || cchUrl < L_MAX_URL_LENGTH)
		return FALSE;

	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_URL;
	item.iLink = iLink;

	if (!GetItem(&item))
		return FALSE;

	::ATL::Checked::wcscpy_s(szUrl, cchUrl, item.szUrl);
	return TRUE;
}

AFX_INLINE BOOL CLinkCtrl::GetItemState(int iLink, UINT *pnState, UINT stateMask /*= 0xFFFFFFFF*/) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(pnState != NULL);
	if (pnState == NULL)
		return FALSE;

	LITEM item;
	item.mask = LIF_ITEMINDEX | LIF_URL;
	item.iLink = iLink;
	item.stateMask = stateMask;

	if (!GetItem(&item))
		return FALSE;

	*pnState = item.state;
	return TRUE;
}


AFX_INLINE BOOL CLinkCtrl::HitTest(PLHITTESTINFO phti)  const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(phti != NULL);
	return (BOOL) ::SendMessage(m_hWnd, LM_HITTEST, 0, (LPARAM)phti);
}

#endif	// _WIN32_WINNT >= 0x0501
