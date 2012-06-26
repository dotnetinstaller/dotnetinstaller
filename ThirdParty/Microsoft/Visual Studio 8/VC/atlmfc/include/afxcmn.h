// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXCMN_H__
#define __AFXCMN_H__

#ifdef _AFX_NO_AFXCMN_SUPPORT
	#error Windows Common Control classes not supported in this library variant.
#endif

#ifndef __AFXWIN_H__
	#include <afxwin.h>
#endif

#pragma once

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif
#ifndef _AFX_FULLTYPEINFO
#pragma component(mintypeinfo, on)
#endif

#ifndef IMAGE_BITMAP
#define IMAGE_BITMAP 0
#endif

/////////////////////////////////////////////////////////////////////////////

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#if (_WIN32_WINNT >= 0x0501)
	#include <uxtheme.h>
#endif	// _WIN32_WINNT >= 0x0501

#ifndef _AFX_NO_RICHEDIT_SUPPORT
	#ifndef _RICHEDIT_
		#include <richedit.h>
	#endif
	#ifdef __AFXOLE_H__  // only include richole if OLE support is included
		#ifndef _RICHOLE_
			#include <richole.h>
			#define _RICHOLE_
		#endif
	#else
		struct IRichEditOle;
		struct IRichEditOleCallback;
	#endif
#endif

#ifdef _AFX_ALL_WARNINGS
#pragma warning(push)
#endif

#pragma warning(disable: 4263 4264)  // base class method is hidden

/////////////////////////////////////////////////////////////////////////////
// AFXCMN - MFC COMCTL32 Control Classes

// Classes declared in this file

//TOOLINFO
	class CToolInfo;

//CObject
	class CImageList;
	//CCmdTarget;
		//CWnd
			// class CListBox;
				class CDragListBox;
			class CListCtrl;
			class CTreeCtrl;
			class CSpinButtonCtrl;
			class CHeaderCtrl;
			class CSliderCtrl;
			class CProgressCtrl;
			// class CComboBox;
				class CComboBoxEx;
			class CHotKeyCtrl;
			class CToolTipCtrl;
			class CTabCtrl;
			class CAnimateCtrl;
			class CToolBarCtrl;
			class CStatusBarCtrl;
			class CRichEditCtrl;
			class CIPAddressCtrl;

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA

/////////////////////////////////////////////////////////////////////////////
// CToolInfo

#ifdef _UNICODE
class CToolInfo : public tagTOOLINFOW
#else
class CToolInfo : public tagTOOLINFOA
#endif
{
public:
	TCHAR szText[256];
};

/////////////////////////////////////////////////////////////////////////////
// CDragListBox

class CDragListBox : public CListBox
{
	DECLARE_DYNAMIC(CDragListBox)

// Constructors
public:
	CDragListBox();

// Attributes

	// find item index at given point
	int ItemFromPt(CPoint pt, BOOL bAutoScroll = TRUE) const;

// Operations

	// draws insertion line
	virtual void DrawInsert(int nItem);

// Overridables

	// Override to respond to beginning of drag event.
	virtual BOOL BeginDrag(CPoint pt);

	// Overrdie to react to user cancelling drag.
	virtual void CancelDrag(CPoint pt);

	// Called as user drags. Return constant indicating cursor.
	virtual UINT Dragging(CPoint pt);

	// Called when user releases mouse button to end drag event. 
	virtual void Dropped(int nSrcIndex, CPoint pt);

// Implementation
public:
	int m_nLast;
	void DrawSingle(int nIndex);
	virtual void PreSubclassWindow();
	virtual ~CDragListBox();

protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

/////////////////////////////////////////////////////////////////////////////
// CStatusBarCtrl

// NOTE: This class must remain a binary-compatible subset
// of CStatusBar. Do not add data members or virtual functions
// directly to this class.
class CStatusBarCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual OK here - CWnd has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CStatusBarCtrl)

// Constructors
public:
	CStatusBarCtrl();

	// Generic creator
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	// Generic creator allowing extended style bits
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes

	// Sets text in a particular pane.
	BOOL SetText(LPCTSTR lpszText, int nPane, int nType);

	// Retrieves text from a particular pane.
	CString GetText(int nPane, int* pType = NULL) const;
	int GetText(LPTSTR lpszText, int nPane, int* pType = NULL) const;

	// Gets the legnth of text in a particular pane without
	// retreiving the actual text.
	int GetTextLength(int nPane, int* pType = NULL) const;

	// Sets size of individual panes within the control.
	BOOL SetParts(int nParts, int* pWidths);

	// Returns sizes of each pane within the control.
	int GetParts(int nParts, int* pParts) const;

	// Get sizes of all borders in on control.
	BOOL GetBorders(int* pBorders) const;
	BOOL GetBorders(int& nHorz, int& nVert, int& nSpacing) const;

	// Sets the minimum allowable height for the control.
	void SetMinHeight(int nMin);

	// Sets the control to have one single pane and no subdivisions.
	BOOL SetSimple(BOOL bSimple = TRUE);

	// Gets the bounding rectangle of a specific pane. 
	BOOL GetRect(int nPane, LPRECT lpRect) const;

	// Determines if the control has one single pane.
   BOOL IsSimple() const;

	// Returns tooltip text for the given pane. 
   CString GetTipText(int nPane) const;

	// Sets tooltip text for the given pane.
   void SetTipText(int nPane, LPCTSTR pszTipText);

	// Sets background color for all panes in the control.
   COLORREF SetBkColor(COLORREF cr);

	// Sets icon for the given pane.
   BOOL SetIcon(int nPane, HICON hIcon);

// Overridables
	// Override to perform owner draw. Control must
	// have the owner draw style.
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	// virtual OK here - ~CWnd is virtual
	virtual ~CStatusBarCtrl();
protected:
	// virtual OK here - CWnd makes this virtual
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

/////////////////////////////////////////////////////////////////////////////
// CListCtrl

// NOTE: This class must remain a binary-compatible subset
// of CListView. Do not add data members or virtual functions
// directly to this class.
class CListCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual is OK here - CWnd has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CListCtrl)

// Constructors
public:
	CListCtrl();

	// Generic creator
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	// Generic creator allowing extended style bits
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	// Retrieves the background color for the control.  
	COLORREF GetBkColor() const;

	// Sets background color for the control.
	BOOL SetBkColor(COLORREF cr);

	// Retrieves the image list associated with the control.
	CImageList* GetImageList(int nImageList) const;

	// Sets the image list associated with this control.
	CImageList* SetImageList(CImageList* pImageList, int nImageListType);

	// Retrieves the tool tip control associated with this control.
   CToolTipCtrl* GetToolTips() const;

	// Sets the tool tip control to be used by this control.  
   CToolTipCtrl* SetToolTips(CToolTipCtrl* pWndTip);

	// Retrieves the number of items in the control.
	int GetItemCount() const;

	// Retrieves a description of a particular item in the control.
	BOOL GetItem(LVITEM* pItem) const;

	// Sets information to an existing item in the control.
	BOOL SetItem(const LVITEM* pItem);
	BOOL SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem,
		int nImage, UINT nState, UINT nStateMask, LPARAM lParam);
	BOOL SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem,
		int nImage, UINT nState, UINT nStateMask, LPARAM lParam, int nIndent);

	// Determines which item attributes are maintained by the application
	// instead of the control itself.
	UINT GetCallbackMask() const;

	// Specifies which item attributes are maintained by the application
	// instead of the control itself.
	BOOL SetCallbackMask(UINT nMask);

	// Get the next item after nItem matching flags in nFlags.
	int GetNextItem(int nItem, int nFlags) const;

	// Gets first item selected in the control and prepares for
	// finding other selected items (if the control has the multiple
	// selection style).
	POSITION GetFirstSelectedItemPosition() const;

	// Finds the next selected item, after a previous call
	// to GetFirstSelectedItemPosition().
	int GetNextSelectedItem(POSITION& pos) const;

	// Retrieves the bounding rectangle for a particular item.
	BOOL GetItemRect(int nItem, LPRECT lpRect, UINT nCode) const;

	// Find the location of a particular item in the control,
	// relative to the control's client area.
	BOOL SetItemPosition(int nItem, POINT pt);
	BOOL GetItemPosition(int nItem, LPPOINT lpPoint) const;

	// Determines the width of a string as displayed in report mode.
	int GetStringWidth(LPCTSTR lpsz) const;

	// Retrieves the edit control associated with the currently edited
	// item in the control.
	CEdit* GetEditControl() const;

	// Retrieves information about a column in a report-mode control.
	BOOL GetColumn(int nCol, LVCOLUMN* pColumn) const;

	// Sets information about a column in a report-mode control.
	BOOL SetColumn(int nCol, const LVCOLUMN* pColumn);

	// Retrieves the width of a column in a report-mode control.
	int GetColumnWidth(int nCol) const;

	// Sets the width of a column in a report-mode control.
	BOOL SetColumnWidth(int nCol, int cx);

	BOOL GetViewRect(LPRECT lpRect) const;

	// Retrieves foreground color of text labels in the control.
	COLORREF GetTextColor() const;

	// Sets foreground color of text labels in the control.
	BOOL SetTextColor(COLORREF cr);

	// Retrieves background color of text labels in the control.
	COLORREF GetTextBkColor() const;

	// Sets background color of text labels in the control.
	BOOL SetTextBkColor(COLORREF cr);

	// Retreives the index of the topmost visible item in the control.
	int GetTopIndex() const;

	// Retreives the number of items displayed at one time
	// the control's client area.
	int GetCountPerPage() const;

	// Retrieves the current origin of the client area.
	BOOL GetOrigin(LPPOINT lpPoint) const;

	// Sets the state of a particular item.
	BOOL SetItemState(int nItem, LVITEM* pItem);
	BOOL SetItemState(int nItem, UINT nState, UINT nMask);

	// Retrieves the state of a particular item.
	UINT GetItemState(int nItem, UINT nMask) const;

	// Retrieves the text associated with a particular item.
	CString GetItemText(int nItem, int nSubItem) const;
	int GetItemText(__in int nItem, __in int nSubItem, __out_ecount_part_z(nLen, return + 1) LPTSTR lpszText, __in int nLen) const;

	// Sets the text associated with a particular item.
	BOOL SetItemText(int nItem, int nSubItem, LPCTSTR lpszText);

	// Sets the count of items in the control. The control will use
	// this value to preallocate memory for its own storage; you may
	// exceed the item count at any time, but accurate preallocation
	// can help performance.
	void SetItemCount(int nItems);

	// Sets the data (lParam) associated with a particular item.
	BOOL SetItemData(int nItem, DWORD_PTR dwData);

	// Retrieves the data (lParam) associated with a particular item.
	DWORD_PTR GetItemData(int nItem) const;

	// Retreives the number of selected items in the control.
	UINT GetSelectedCount() const;
	BOOL SetColumnOrderArray(int iCount, LPINT piArray);
	BOOL GetColumnOrderArray(LPINT piArray, int iCount = -1);

	// Sets minimum spacing of items in the icon view. 
	CSize SetIconSpacing(CSize size);
	CSize SetIconSpacing(int cx, int cy);

	// Retrieves a reference to the header control in
	// a report-mode control.
	CHeaderCtrl* GetHeaderCtrl();

	// Retrieves the cursor used over hot items. (Only valid for
	// controls with the LVS_EX_TRACKSELECT style.)
	HCURSOR GetHotCursor();

	// Sets cursor to be used over hot items. (Only used in controls
	// with the LVS_EX_TRACKSELECT style.)
	HCURSOR SetHotCursor(HCURSOR hc);

	BOOL GetSubItemRect(int iItem, int iSubItem, int nArea, CRect& ref);

	// Retrieves the item currently hot-selected, or -1 if none.
	int GetHotItem();

	// Sets the item to be currently hot-selected.
	int SetHotItem(int iIndex);

	// Retrieves the item with the selection mark, or -1 if none.
   int GetSelectionMark();

	// Sets the item with the selection mark. 
	int SetSelectionMark(int iIndex);

	// Retrieves the control-specific extended style bits.
   DWORD GetExtendedStyle();

	// Sets the control-specific extended style bits.
	DWORD SetExtendedStyle(DWORD dwNewStyle);

	// Determines the visual feature of a subitem control under
	// the specified point.
	int SubItemHitTest(LPLVHITTESTINFO pInfo);

	// Sets up virtual work areas within the control.
   void SetWorkAreas(int nWorkAreas, LPRECT lpRect);

	// Updates expected item count for a virtual control.
   BOOL SetItemCountEx(int iCount, DWORD dwFlags = LVSICF_NOINVALIDATEALL);

	// Calculates the approximate minimum size required to
	// display the passed number of items.
   CSize ApproximateViewRect(CSize sz = CSize(-1, -1),
		int iCount = -1) const;

	// Retrieves information about the background image in the control.
   BOOL GetBkImage(LVBKIMAGE* plvbkImage) const;

	// Retrieves the delay (in milliseconds) for the mouse to hover
	// over an item before it is selected.
   DWORD GetHoverTime() const;

	// Retrieves the rectangles defining the workareas in the control.
   void GetWorkAreas(int nWorkAreas, LPRECT prc) const;

	// Sets the image used in the background of the control.
   BOOL SetBkImage(HBITMAP hbm, BOOL fTile = TRUE,
		int xOffsetPercent = 0, int yOffsetPercent = 0);
   BOOL SetBkImage(__in_z LPTSTR pszUrl, __in BOOL fTile = TRUE,
		__in int xOffsetPercent = 0, __in int yOffsetPercent = 0);
   BOOL SetBkImage(LVBKIMAGE* plvbkImage);

	// Sets the delay (in milliseconds) for the mouse to hover
	// over an item before it is selected.
   DWORD SetHoverTime(DWORD dwHoverTime = (DWORD)-1);

	// Returns the number of work areas in the control.
   UINT GetNumberOfWorkAreas() const;

	// Retrieves the checked state of a particular item. Only useful
	// on controls with the LVS_EX_CHECKBOXES style.
   BOOL GetCheck(int nItem) const;

	// Sets the checked state of a particular item. Only useful
	// on controls with the LVS_EX_CHECKBOXES style.
   BOOL SetCheck(int nItem, BOOL fCheck = TRUE);

// Operations

	// Adds an item to the control.
	int InsertItem(const LVITEM* pItem);
	int InsertItem(int nItem, LPCTSTR lpszItem);
	int InsertItem(int nItem, LPCTSTR lpszItem, int nImage);

	// Removes a single item from the control.
	BOOL DeleteItem(int nItem);

	// Removes all items from the control.
	BOOL DeleteAllItems();

	// Finds an item in the control matching the specified criteria.  
	int FindItem(LVFINDINFO* pFindInfo, int nStart = -1) const;

	// Determines the visual feature of the control under
	// the specified point.
	int HitTest(LVHITTESTINFO* pHitTestInfo) const;
	int HitTest(CPoint pt, UINT* pFlags = NULL) const;

	// Causes the control to scroll its content so the specified item
	// is completely (or at least partially, depending on the
	// bPartialOK parameter) visible.
	BOOL EnsureVisible(int nItem, BOOL bPartialOK);

	// Forces the control to scroll its client area
	// by the specified amount.
	BOOL Scroll(CSize size);

	// Forces the control to repaint a specific range of items.
	BOOL RedrawItems(int nFirst, int nLast);

	// Causes the control to rearrange items within its client area.
	BOOL Arrange(UINT nCode);

	// Causes the control to enter edit mode on the speficied item.  
	CEdit* EditLabel(int nItem);

	// Inserts a column into a report-mode control.
	int InsertColumn(int nCol, const LVCOLUMN* pColumn);
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);

	// Deletes a column from a report-mode control.
	BOOL DeleteColumn(int nCol);

	// Creates a drag-time image from a particular item in the control.
	CImageList* CreateDragImage(int nItem, LPPOINT lpPoint);

	// Forces the control to repaint a specific item.
	BOOL Update(int nItem);

	// Call to sort items using a custom comparison function.
	BOOL SortItems(PFNLVCOMPARE pfnCompare, DWORD_PTR dwData);

#if (_WIN32_WINNT >= 0x0501)

	LRESULT SetSelectedColumn(int iCol);
	DWORD SetView(int iView);
	DWORD GetView() const;
	LRESULT InsertGroup(int index, PLVGROUP pgrp);
	int SetGroupInfo(int iGroupId, PLVGROUP pgrp);
	int GetGroupInfo(int iGroupId, PLVGROUP pgrp) const;	
	LRESULT RemoveGroup(int iGroupId);	
	LRESULT MoveGroup(int iGroupId, int toIndex);
	LRESULT MoveItemToGroup(int idItemFrom, int idGroupTo);
	void SetGroupMetrics(PLVGROUPMETRICS pGroupMetrics);
	void GetGroupMetrics(PLVGROUPMETRICS pGroupMetrics) const;
	LRESULT EnableGroupView(BOOL fEnable);
	BOOL SortGroups(PFNLVGROUPCOMPARE _pfnGroupCompare, LPVOID _plv);
	LRESULT InsertGroupSorted(PLVINSERTGROUPSORTED pStructInsert);
	void RemoveAllGroups();
	BOOL HasGroup(int iGroupId) const;
	BOOL SetTileViewInfo(PLVTILEVIEWINFO ptvi);
	BOOL GetTileViewInfo(PLVTILEVIEWINFO ptvi) const;	
	BOOL SetTileInfo(PLVTILEINFO pti);
	BOOL GetTileInfo(PLVTILEINFO pti) const;		
	BOOL SetInsertMark(LPLVINSERTMARK lvim);
	BOOL GetInsertMark(LPLVINSERTMARK lvim) const;	
	int InsertMarkHitTest(LPPOINT pPoint, LPLVINSERTMARK lvim) const;
	int GetInsertMarkRect(LPRECT pRect) const;
	COLORREF SetInsertMarkColor(COLORREF color);
	COLORREF GetInsertMarkColor() const;
	BOOL SetInfoTip(PLVSETINFOTIP plvInfoTip);
	UINT GetSelectedColumn() const;
	BOOL IsGroupViewEnabled() const;
	COLORREF GetOutlineColor() const;
	COLORREF SetOutlineColor(COLORREF color);
	void CancelEditLabel();

#endif	// _WIN32_WINNT >= 0x0501






// Overridables
	// Override to perform owner draw. Control must
	// have the owner draw style.
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	int InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState,
		UINT nStateMask, int nImage, LPARAM lParam);
	// virtual OK here - ~CWnd is virtual
	virtual ~CListCtrl();
protected:
	void RemoveImageList(int nImageList);
	// virtual OK here - CWnd makes this virtual
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
protected:
	//{{AFX_MSG(CListCtrl)
	afx_msg void OnNcDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrl

// NOTE: This class must remain a binary-compatible subset
// of CTreeView. Do not add data members or virtual functions
// directly to this class.
class CTreeCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual OK - CWnd has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CTreeCtrl)

// Constructors
public:
	CTreeCtrl();

	// Generic creator
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	// Generic creator allowing extended style bits
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes

	// Retrieves the bounding rectangle for the specified item.
	BOOL GetItemRect(HTREEITEM hItem, LPRECT lpRect, BOOL bTextOnly) const;

	// Gets the count of items in the control.
	UINT GetCount() const;

	// Returns the level-to-level indentation (in pixels).
	UINT GetIndent() const;

	// Sets the level-to-level indentation (in pixels).
	void SetIndent(UINT nIndent);

	// Retrieves the image list associated with the control.
	CImageList* GetImageList(UINT nImageList) const;

	// Sets the image list associated with this control.
	CImageList* SetImageList(CImageList* pImageList, int nImageListType);

	// Retrieves the next item having the given relationship with the
	// specified item.
	HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode) const;

	// Retrieves the next child item after the specified item.
	HTREEITEM GetChildItem(HTREEITEM hItem) const;

	// Retrieves the next sibling item after the specified item.
	HTREEITEM GetNextSiblingItem(HTREEITEM hItem) const;

	// Retrieves the previous sibling item of the specified item.
	HTREEITEM GetPrevSiblingItem(HTREEITEM hItem) const;

	// Retrieves the parent of the specified item.
	HTREEITEM GetParentItem(HTREEITEM hItem) const;

	// Retrieves the topmost visible item in the control.
	HTREEITEM GetFirstVisibleItem() const;

	// Retrieves the next visible item after the specified item.
	HTREEITEM GetNextVisibleItem(HTREEITEM hItem) const;

	// Retrieves the previous visible item before the specified item.
	HTREEITEM GetPrevVisibleItem(HTREEITEM hItem) const;

	// Retrieves the higlighted item, NULL if none.
	HTREEITEM GetSelectedItem() const;

	// Retrieves the currently drop-highlighted item, NULL if none.
	HTREEITEM GetDropHilightItem() const;								  

	// Retrieves the root item of the control, NULL if none.
	HTREEITEM GetRootItem() const;

	// Retrieves information about a particular item in the control.
	BOOL GetItem(TVITEM* pItem) const;

	// Retrieves the text associated with the given item.
	CString GetItemText(HTREEITEM hItem) const;

	// Retrieves the images associated with the given item.
	BOOL GetItemImage(HTREEITEM hItem, int& nImage,
		int& nSelectedImage) const;

	// Retrieves the state of the given item. 
	UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const;

	// Retreives the user-supplied data associated with the given item.
	DWORD_PTR GetItemData(HTREEITEM hItem) const;

	// Sets the state of the an item.
	BOOL SetItem(TVITEM* pItem);
	BOOL SetItem(HTREEITEM hItem, UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam);

	// Sets the text of the specified item.
	BOOL SetItemText(HTREEITEM hItem, LPCTSTR lpszItem);

	// Sets the image on the specified item.
	BOOL SetItemImage(HTREEITEM hItem, int nImage, int nSelectedImage);

	// Sets the state of the specified item.
	BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask);

	// Sets the user data on the specified item.
	BOOL SetItemData(HTREEITEM hItem, DWORD_PTR dwData);

	// Determines if the specified item has children.
	BOOL ItemHasChildren(HTREEITEM hItem) const;

	// Retrieves the edit control used to perform in-place editing.
	CEdit* GetEditControl() const;

	// Gets the count of items presently visible in the control.
	UINT GetVisibleCount() const;

	// Retrieves the tool tip control associated with this control.
   CToolTipCtrl* GetToolTips() const;

	// Sets the tool tip control to be used by this control.  
   CToolTipCtrl* SetToolTips(CToolTipCtrl* pWndTip);

	// Retrieves the background colour used throughout the control.
   COLORREF GetBkColor() const;

	// Sets the background color to be used throughout the control.
   COLORREF SetBkColor(COLORREF clr);

	// Retrieves the height of items in the control.
   SHORT GetItemHeight() const;

	// Sets the height of items in the control.
   SHORT SetItemHeight(SHORT cyHeight);

	 // Retrieves the text color used for all items in the control.
	COLORREF GetTextColor() const;

	 // Sets the text color used for all items in the control.
	COLORREF SetTextColor(COLORREF clr);

	 // Sets the insertion mark to the specified item in the control.
	BOOL SetInsertMark(HTREEITEM hItem, BOOL fAfter = TRUE);

	 // Gets the checked state of the specified item in the control.
	 // (Only useful on a control with the TVS_CHECKBOXES style.)
	 BOOL GetCheck(HTREEITEM hItem) const;

	 // Sets the checked state of the specified item in the control.
	 // (Only useful on a control with the TVS_CHECKBOXES style.)
	BOOL SetCheck(HTREEITEM hItem, BOOL fCheck = TRUE);


	COLORREF GetInsertMarkColor() const;
	COLORREF SetInsertMarkColor(COLORREF clrNew);

	 // Sets the maximum time (in milliseconds) the control will
	 // spend smooth scrolling its content.
	 UINT SetScrollTime(UINT uScrollTime);

	 // Retrieves the maximum time (in milliseconds) the control will
	 // spend smooth scrolling its content.
	 UINT GetScrollTime() const;

#if _WIN32_IE >= 0x0500
	COLORREF GetLineColor() const;
	COLORREF SetLineColor(COLORREF clrNew = CLR_DEFAULT);
#endif

// Operations

	// Inserts a new item to the control.
	HTREEITEM InsertItem(LPTVINSERTSTRUCT lpInsertStruct);
	HTREEITEM InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
		HTREEITEM hParent, HTREEITEM hInsertAfter);
	HTREEITEM InsertItem(LPCTSTR lpszItem, HTREEITEM hParent = TVI_ROOT,
		HTREEITEM hInsertAfter = TVI_LAST);
	HTREEITEM InsertItem(LPCTSTR lpszItem, int nImage, int nSelectedImage,
		HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);

	// Removes the specified item from the control.
	BOOL DeleteItem(HTREEITEM hItem);

	// Removes all items from the control.
	BOOL DeleteAllItems();

	// Expands the children of the specified item.  
	BOOL Expand(HTREEITEM hItem, UINT nCode);

	// Selects the specified item.
	BOOL Select(HTREEITEM hItem, UINT nCode);

	// Selects the specified item.
	BOOL SelectItem(HTREEITEM hItem);

	// Selects an item to be the drop target in the control.
	BOOL SelectDropTarget(HTREEITEM hItem);

	// Draws the specified item as the drop target for the control.
	BOOL SelectSetFirstVisible(HTREEITEM hItem);

	// Begins editing the label of the specified item.
	CEdit* EditLabel(HTREEITEM hItem);

	// Determines the visual feature of the control under
	// the specified point.
	HTREEITEM HitTest(CPoint pt, UINT* pFlags = NULL) const;
	HTREEITEM HitTest(TVHITTESTINFO* pHitTestInfo) const;

	// Create a drag image for the specified item.
	CImageList* CreateDragImage(HTREEITEM hItem);

	// Sorts all children of the specified item.
	BOOL SortChildren(HTREEITEM hItem);

	// Scrolls the control to ensure the specified item is visible.
	BOOL EnsureVisible(HTREEITEM hItem);

	// Sorts items in the control using the provided callback function.
	BOOL SortChildrenCB(LPTVSORTCB pSort);

// Implementation
protected:
	void RemoveImageList(int nImageList);

public:
	// virtual OK here - ~CWnd is virtual
	virtual ~CTreeCtrl();
	//{{AFX_MSG(CTreeCtrl)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonCtrl

class CSpinButtonCtrl : public CWnd
{
	DECLARE_DYNAMIC(CSpinButtonCtrl)

// Constructors
public:
	CSpinButtonCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	BOOL SetAccel(int nAccel, UDACCEL* pAccel);
	UINT GetAccel(int nAccel, UDACCEL* pAccel) const;
	int SetBase(int nBase);
	UINT GetBase() const;
	CWnd* SetBuddy(CWnd* pWndBuddy);
	CWnd* GetBuddy() const;
	int SetPos(int nPos);
	int GetPos() const;
	void SetRange(short nLower, short nUpper);
	void SetRange32(int nLower, int nUpper);
	DWORD GetRange() const;
	void GetRange(int &lower, int& upper) const;
	void GetRange32(int &lower, int& upper) const;

#if _WIN32_IE >= 0x0500
	int GetPos32(LPBOOL lpbError = NULL) const;
	int SetPos32(int nPos);
#endif

// Implementation
public:
	virtual ~CSpinButtonCtrl();
};

/////////////////////////////////////////////////////////////////////////////
// CSliderCtrl

class CSliderCtrl : public CWnd
{
	DECLARE_DYNAMIC(CSliderCtrl)

// Constructors
public:
	CSliderCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	int GetLineSize() const;
	int SetLineSize(int nSize);
	int GetPageSize() const;
	int SetPageSize(int nSize);
	int GetRangeMax() const;
	int GetRangeMin() const;
	void GetRange(int& nMin, int& nMax) const;
	void SetRangeMin(int nMin, BOOL bRedraw = FALSE);
	void SetRangeMax(int nMax, BOOL bRedraw = FALSE);
	void SetRange(int nMin, int nMax, BOOL bRedraw = FALSE);
	void GetSelection(int& nMin, int& nMax) const;
	void SetSelection(int nMin, int nMax);
	void GetChannelRect(LPRECT lprc) const;
	void GetThumbRect(LPRECT lprc) const;
	int GetPos() const;
	void SetPos(int nPos);
	UINT GetNumTics() const;
	DWORD* GetTicArray() const;
	int GetTic(int nTic) const;
	int GetTicPos(int nTic) const;
	BOOL SetTic(int nTic);
	void SetTicFreq(int nFreq);
	CWnd* GetBuddy(BOOL fLocation = TRUE) const;
	CWnd* SetBuddy(CWnd* pWndBuddy, BOOL fLocation = TRUE);
	CToolTipCtrl* GetToolTips() const;
	void SetToolTips(CToolTipCtrl* pWndTip);
	int SetTipSide(int nLocation);

// Operations
	void ClearSel(BOOL bRedraw = FALSE);
	void ClearTics(BOOL bRedraw = FALSE);

// Implementation
public:
	virtual ~CSliderCtrl();
};

/////////////////////////////////////////////////////////////////////////////
// CProgressCtrl

class CProgressCtrl : public CWnd
{
	DECLARE_DYNAMIC(CProgressCtrl)

// Constructors
public:
	CProgressCtrl();
	// Generic creator
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	// Generic creator allowing extended style bits
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes

	// Sets range of values for the control. (16-bit limit)
   void SetRange(short nLower, short nUpper);

	// Sets range of values for the control. (32-bit limit)
   void SetRange32(int nLower, int nUpper);

	// Retrieves range of values for the control. (32-bit limit)
   void GetRange(int& nLower, int& nUpper);

	// Gets the current position within the set range of the control.
	int GetPos();

	// Sets the current position within the set range of the control.
	int SetPos(int nPos);

	// Displaces the current position within the set range of the
   // control by the passed value.  
	int OffsetPos(int nPos);

	// Sets the step by which increments happen with a call to StepIt().
	int SetStep(int nStep);

	// Sets the control's background color.
   COLORREF SetBkColor(COLORREF clrNew);

// Operations

	// Steps the control by the value set with SetStep().
	int StepIt();

// Implementation
public:
	virtual ~CProgressCtrl();
};

/////////////////////////////////////////////////////////////////////////////
// CComboBoxEx

class CComboBoxEx : public CComboBox
{
	DECLARE_DYNAMIC(CComboBoxEx)

// Constructors
public:
	CComboBoxEx();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Operations
   using CComboBox::DeleteItem;
	int DeleteItem(int iIndex);
	BOOL GetItem(COMBOBOXEXITEM* pCBItem);
	int InsertItem(const COMBOBOXEXITEM* pCBItem);
	BOOL SetItem(const COMBOBOXEXITEM* pCBItem);

// Attributes
	BOOL HasEditChanged();
	DWORD GetExtendedStyle() const;
	DWORD SetExtendedStyle(DWORD dwExMask, DWORD dwExStyles);
	CEdit* GetEditCtrl();
	CComboBox* GetComboBoxCtrl();
	CImageList* GetImageList() const;
	CImageList* SetImageList(CImageList* pImageList);

#if (_WIN32_WINNT >= 0x0501)
	HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
#endif

	// These functions are supported by the Windows ComboBox control,
	// but not supported by the Windows ComboBoxEx control.

	int Dir(UINT attr, LPCTSTR lpszWildCard);
	int FindString(int nIndexStart, LPCTSTR lpszFind) const;
	int AddString(LPCTSTR lpszString);
	BOOL SetEditSel(int nStartChar, int nEndChar);
	int InsertString(int nIndex, LPCTSTR lpszString);

// Implementation
public:
	virtual ~CComboBoxEx();
};

/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrl

class CHeaderCtrl : public CWnd
{
	DECLARE_DYNAMIC(CHeaderCtrl)

// Constructors
public:
	CHeaderCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	int GetItemCount() const;
	BOOL GetItem(int nPos, HDITEM* pHeaderItem) const;
	BOOL SetItem(int nPos, HDITEM* pHeaderItem);
	CImageList* GetImageList() const;
	CImageList* SetImageList(CImageList* pImageList);
	BOOL GetItemRect(int nIndex, LPRECT lpRect) const;
	BOOL GetOrderArray(LPINT piArray, int iCount);
	BOOL SetOrderArray(int iCount, LPINT piArray);
	int OrderToIndex(int nOrder) const;

#if _WIN32_IE >= 0x0500
	int GetBitmapMargin() const;
	int SetBitmapMargin(int nWidth);
#endif

// Operations
	int InsertItem(int nPos, HDITEM* phdi);
	BOOL DeleteItem(int nPos);
	BOOL Layout(HDLAYOUT* pHeaderLayout);
	CImageList* CreateDragImage(int nIndex);
	int SetHotDivider(CPoint pt);
	int SetHotDivider(int nIndex);

#if _WIN32_IE >= 0x0500
	int SetFilterChangeTimeout(DWORD dwTimeOut);
	int EditFilter(int nColumn, BOOL bDiscardChanges);
	int ClearFilter(int nColumn);
	int ClearAllFilters();
#endif

// Overridables
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	virtual ~CHeaderCtrl();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);

};

/////////////////////////////////////////////////////////////////////////////
// CHotKeyCtrl

class CHotKeyCtrl : public CWnd
{
	DECLARE_DYNAMIC(CHotKeyCtrl)

// Constructors
public:
	CHotKeyCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	void SetHotKey(WORD wVirtualKeyCode, WORD wModifiers);
	DWORD GetHotKey() const;
	void GetHotKey(WORD &wVirtualKeyCode, WORD &wModifiers) const;
	CString GetHotKeyName() const;

// Operations
	void SetRules(WORD wInvalidComb, WORD wModifiers);
	static CString GetKeyName(UINT vk, BOOL fExtended);

// Implementation
public:
	virtual ~CHotKeyCtrl();

};

/////////////////////////////////////////////////////////////////////////////
// CToolTipCtrl

class CToolTipCtrl : public CWnd
{
	DECLARE_DYNAMIC(CToolTipCtrl)

// Constructors
public:
	CToolTipCtrl();
	virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = 0);
	virtual BOOL CreateEx(CWnd* pParentWnd, DWORD dwStyle = 0, DWORD dwStyleEx = 0);

// Attributes
	void GetText(CString& str, CWnd* pWnd, UINT_PTR nIDTool = 0) const;
	BOOL GetToolInfo(CToolInfo& ToolInfo, CWnd* pWnd, UINT_PTR nIDTool = 0) const;
	void SetToolInfo(LPTOOLINFO lpToolInfo);
	void SetToolRect(CWnd* pWnd, UINT_PTR nIDTool, LPCRECT lpRect);
	int GetToolCount() const;
	int GetDelayTime(DWORD dwDuration) const;
	void SetDelayTime(DWORD dwDuration, int iTime);
	void GetMargin(LPRECT lprc) const;
	void SetMargin(LPRECT lprc);
	int GetMaxTipWidth() const;
	int SetMaxTipWidth(int iWidth);
	COLORREF GetTipBkColor() const;
	void SetTipBkColor(COLORREF clr);
	COLORREF GetTipTextColor() const;
	void SetTipTextColor(COLORREF clr);

#if _WIN32_IE >= 0x0500
	CSize GetBubbleSize(LPTOOLINFO lpToolInfo) const;
#endif

#if (_WIN32_WINNT >= 0x0501)
	HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
#endif


// Operations
	void Activate(BOOL bActivate);

	BOOL AddTool(CWnd* pWnd, UINT nIDText, LPCRECT lpRectTool = NULL,
		UINT_PTR nIDTool = 0);
	BOOL AddTool(CWnd* pWnd, LPCTSTR lpszText = LPSTR_TEXTCALLBACK,
		LPCRECT lpRectTool = NULL, UINT_PTR nIDTool = 0);

	void DelTool(CWnd* pWnd, UINT_PTR nIDTool = 0);

	BOOL HitTest(CWnd* pWnd, CPoint pt, LPTOOLINFO lpToolInfo) const;
	void RelayEvent(LPMSG lpMsg);
	void SetDelayTime(UINT nDelay);
	void UpdateTipText(LPCTSTR lpszText, CWnd* pWnd, UINT_PTR nIDTool = 0);
	void UpdateTipText(UINT nIDText, CWnd* pWnd, UINT_PTR nIDTool = 0);
	void Update();

	void Pop();

#if _WIN32_IE >= 0x0500
	BOOL AdjustRect(LPRECT lprc, BOOL bLarger = TRUE);
	BOOL SetTitle(UINT uIcon, LPCTSTR lpstrTitle);
#endif

// Implementation
public:
	void FillInToolInfo(TOOLINFO& ti, CWnd* pWnd, UINT_PTR nIDTool) const;
	virtual ~CToolTipCtrl();
#ifndef _AFXDLL
	virtual BOOL DestroyToolTipCtrl();
#else
	BOOL DestroyToolTipCtrl();
#endif

protected:
	//{{AFX_MSG(CToolTipCtrl)
	afx_msg LRESULT OnDisableModal(WPARAM, LPARAM);
	afx_msg LRESULT OnWindowFromPoint(WPARAM, LPARAM);
	afx_msg LRESULT OnAddTool(WPARAM, LPARAM);
	afx_msg void OnEnable(BOOL bEnable);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CMapStringToPtr m_mapString;

	friend class CWnd;
	friend class CToolBar;
};

/////////////////////////////////////////////////////////////////////////////
// CTabCtrl

class CTabCtrl : public CWnd
{
	DECLARE_DYNAMIC(CTabCtrl)

// Constructors
public:
	CTabCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	CImageList* GetImageList() const;
	CImageList* SetImageList(CImageList* pImageList);
	int GetItemCount() const;
	BOOL GetItem(int nItem, TCITEM* pTabCtrlItem) const;
	BOOL SetItem(int nItem, TCITEM* pTabCtrlItem);
	BOOL SetItemExtra(int nBytes);
	BOOL GetItemRect(int nItem, LPRECT lpRect) const;
	int GetCurSel() const;
	int SetCurSel(int nItem);
	void SetCurFocus(int nItem);
	CSize SetItemSize(CSize size);
	void SetPadding(CSize size);
	int GetRowCount() const;
	CToolTipCtrl* GetToolTips() const;
	void SetToolTips(CToolTipCtrl* pWndTip);
	int GetCurFocus() const;
	int SetMinTabWidth(int cx);
	DWORD GetExtendedStyle();
	DWORD SetExtendedStyle(DWORD dwNewStyle, DWORD dwExMask = 0);
	DWORD GetItemState(int nItem, DWORD dwMask) const;
	BOOL SetItemState(int nItem, DWORD dwMask, DWORD dwState);

// Operations
	LONG InsertItem(int nItem, TCITEM* pTabCtrlItem);
	LONG InsertItem(int nItem, LPCTSTR lpszItem);
	LONG InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	LONG InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem,
		int nImage, LPARAM lParam);
	LONG InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem,
		int nImage, LPARAM lParam, DWORD dwState, DWORD dwStateMask);
	BOOL DeleteItem(int nItem);
	BOOL DeleteAllItems();
	void AdjustRect(BOOL bLarger, LPRECT lpRect);
	void RemoveImage(int nImage);
	int HitTest(TCHITTESTINFO* pHitTestInfo) const;
	void DeselectAll(BOOL fExcludeFocus);
	BOOL HighlightItem(int idItem, BOOL fHighlight = TRUE);

// Overridables
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	virtual ~CTabCtrl();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
	//{{AFX_MSG(CTabCtrl)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrl

class CAnimateCtrl : public CWnd
{
	DECLARE_DYNAMIC(CAnimateCtrl)

// Constructors
public:
	CAnimateCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Operations
	BOOL Open(LPCTSTR lpszFileName);
	BOOL Open(UINT nID);
	BOOL Play(UINT nFrom, UINT nTo, UINT nRep);
	BOOL Stop();
	BOOL Close();
	BOOL Seek(UINT nTo);

// Implementation
public:
	virtual ~CAnimateCtrl();
};

/////////////////////////////////////////////////////////////////////////////
// CImageList

class CImageList : public CObject
{
	DECLARE_DYNCREATE(CImageList)

// Constructors
public:
	CImageList();
	BOOL Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow);
	BOOL Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(CImageList& imagelist1, int nImage1, CImageList& imagelist2,
		int nImage2, int dx, int dy);
	BOOL Create(CImageList* pImageList);

// Attributes
	HIMAGELIST m_hImageList;            // must be first data member
	operator HIMAGELIST() const;
	HIMAGELIST GetSafeHandle() const;

	static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
	static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HIMAGELIST hImageList);
	HIMAGELIST Detach();

	int GetImageCount() const;
	COLORREF SetBkColor(COLORREF cr);
	COLORREF GetBkColor() const;
	BOOL GetImageInfo(int nImage, IMAGEINFO* pImageInfo) const;

// Operations
	BOOL DeleteImageList();
	BOOL SetImageCount(UINT uNewCount);

	int Add(CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(CBitmap* pbmImage, COLORREF crMask);
	BOOL Remove(int nImage);
	BOOL Replace(int nImage, CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(HICON hIcon);
	int Replace(int nImage, HICON hIcon);
	HICON ExtractIcon(int nImage);
	BOOL Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle);
	BOOL DrawEx(CDC* pDC, int nImage, POINT pt, SIZE sz, COLORREF clrBk, COLORREF clrFg, UINT nStyle);
	BOOL SetOverlayImage(int nImage, int nOverlay);
	BOOL Copy(int iDst, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL Copy(int iDst, CImageList* pSrc, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);
	BOOL DrawIndirect(CDC* pDC, int nImage, POINT pt, SIZE sz, POINT ptOrigin,
			UINT fStyle = ILD_NORMAL, DWORD dwRop = SRCCOPY,
			COLORREF rgbBack = CLR_DEFAULT, COLORREF rgbFore = CLR_DEFAULT,
			DWORD fState = ILS_NORMAL, DWORD Frame = 0, COLORREF crEffect = CLR_DEFAULT);

#ifndef _AFX_NO_OLE_SUPPORT
	BOOL Read(CArchive* pArchive);
	BOOL Write(CArchive* pArchive);
#endif

// Drag APIs
	BOOL BeginDrag(int nImage, CPoint ptHotSpot);
	static void PASCAL EndDrag();
	static BOOL PASCAL DragMove(CPoint pt);
	BOOL SetDragCursorImage(int nDrag, CPoint ptHotSpot);
	static BOOL PASCAL DragShowNolock(BOOL bShow);
	static CImageList* PASCAL GetDragImage(LPPOINT lpPoint, LPPOINT lpPointHotSpot);
	static BOOL PASCAL DragEnter(CWnd* pWndLock, CPoint point);
	static BOOL PASCAL DragLeave(CWnd* pWndLock);

// Implementation
public:
	virtual ~CImageList();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CToolBarCtrl

struct IDropTarget; // forward declaration

// NOTE: This class must remain a binary-compatible subset
// of CToolBar. Do not add data members or virtual functions
// directly to this class.
class CToolBarCtrl : public CWnd
{
	// DECLARE_DYNAMIC OK here - CWnd already has virtual from DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CToolBarCtrl)

// Construction
public:
	CToolBarCtrl();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
public:
	BOOL IsButtonEnabled(int nID) const;
	BOOL IsButtonChecked(int nID) const;
	BOOL IsButtonPressed(int nID) const;
	BOOL IsButtonHidden(int nID) const;
	BOOL IsButtonIndeterminate(int nID) const;
	BOOL SetState(int nID, UINT nState);
	int GetState(int nID) const;
	BOOL GetButton(int nIndex, LPTBBUTTON lpButton) const;
	int GetButtonCount() const;
	BOOL GetItemRect(int nIndex, LPRECT lpRect) const;
	BOOL GetRect(int nID, LPRECT lpRect) const;
	void SetButtonStructSize(int nSize);
	DWORD GetButtonSize() const;
	BOOL SetButtonSize(CSize size);
	BOOL SetBitmapSize(CSize size);
	CToolTipCtrl* GetToolTips() const;
	void SetToolTips(CToolTipCtrl* pTip);
	void SetOwner(CWnd* pWnd);
	void SetRows(int nRows, BOOL bLarger, LPRECT lpRect);
	int GetRows() const;
	BOOL SetCmdID(int nIndex, UINT nID);
	UINT GetBitmapFlags() const;
	int GetBitmap(int nID) const;
	CImageList* GetDisabledImageList() const;
	CImageList* GetHotImageList() const;
	CImageList* GetImageList() const;
	DWORD GetStyle() const;
	int GetMaxTextRows() const;
	BOOL IsButtonHighlighted(int nID) const;
	BOOL SetButtonWidth(int cxMin, int cxMax);
	CImageList* SetDisabledImageList(CImageList* pImageList);
	CImageList* SetHotImageList(CImageList* pImageList);
	CImageList* SetImageList(CImageList* pImageList);
	HRESULT GetDropTarget(IDropTarget** ppDropTarget) const;
	BOOL SetIndent(int iIndent);
	BOOL SetMaxTextRows(int iMaxRows);
	void SetStyle(DWORD dwStyle);
	BOOL GetButtonInfo(int nID, TBBUTTONINFO* ptbbi) const;
	BOOL SetButtonInfo(int nID, TBBUTTONINFO* ptbbi);
	DWORD SetDrawTextFlags(DWORD dwMask, DWORD dwDTFlags);
	BOOL GetAnchorHighlight() const;
	BOOL SetAnchorHighlight(BOOL fAnchor = TRUE);
	int GetHotItem() const;
	int SetHotItem(int nHot);
	void GetInsertMark(TBINSERTMARK* ptbim) const;
	void SetInsertMark(TBINSERTMARK* ptbim);
	BOOL GetMaxSize(LPSIZE pSize) const;
	BOOL InsertMarkHitTest(LPPOINT ppt, LPTBINSERTMARK ptbim) const;
	DWORD GetExtendedStyle() const;
	DWORD SetExtendedStyle(DWORD dwExStyle);
	COLORREF GetInsertMarkColor() const;
	COLORREF SetInsertMarkColor(COLORREF clrNew);

#if (_WIN32_WINNT >= 0x0501)

	void GetMetrics(LPTBMETRICS ptbm) const;
	void SetMetrics(LPTBMETRICS ptbm);
	HRESULT SetWindowTheme(LPCWSTR pszSubAppName);

#endif


// Operations
public:
	BOOL EnableButton(int nID, BOOL bEnable = TRUE);
	BOOL CheckButton(int nID, BOOL bCheck = TRUE);
	BOOL PressButton(int nID, BOOL bPress = TRUE);
	BOOL HideButton(int nID, BOOL bHide = TRUE);
	BOOL Indeterminate(int nID, BOOL bIndeterminate = TRUE);
	int AddBitmap(int nNumButtons, UINT nBitmapID);
	int AddBitmap(int nNumButtons, CBitmap* pBitmap);
	BOOL AddButtons(int nNumButtons, LPTBBUTTON lpButtons);
	BOOL InsertButton(int nIndex, LPTBBUTTON lpButton);
	BOOL DeleteButton(int nIndex);
	UINT CommandToIndex(UINT nID) const;
	void SaveState(HKEY hKeyRoot, LPCTSTR lpszSubKey,
		LPCTSTR lpszValueName);
	void RestoreState(HKEY hKeyRoot, LPCTSTR lpszSubKey,
		LPCTSTR lpszValueName);
	void LoadImages(int iBitmapID, HINSTANCE hinst);
	BOOL MapAccelerator(TCHAR chAccel, UINT* pIDBtn);
	BOOL MarkButton(int nID, BOOL fHighlight = TRUE);
	BOOL MoveButton(UINT nOldPos, UINT nNewPos);
	int HitTest(LPPOINT ppt) const;

	void Customize();
	int AddString(UINT nStringID);
	int AddStrings(LPCTSTR lpszStrings);
	void AutoSize();

#if _WIN32_IE >= 0x0500
	int GetString(__in int nString, __out_ecount_part_z(cchMaxLen, return + 1) LPTSTR lpstrString, __in int cchMaxLen) const;
	int GetString(int nString, CString& str) const;
#endif

// Implementation
public:
	// virtual OK here: ~CWnd() is already virtual
	virtual ~CToolBarCtrl();

protected:
	//{{AFX_MSG(CToolBarCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

// NOTE: This class must remain a binary-compatible subset
// of CReBar. Do not add data members or virtual functions
// directly to this class.
class CReBarCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual is OK here - CWnd already has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CReBarCtrl)

// Construction
public:
	CReBarCtrl();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
public:
	UINT GetBandCount() const;
	BOOL GetBandInfo(UINT uBand, REBARBANDINFO* prbbi) const;
	UINT GetBarHeight() const;
	BOOL GetBarInfo(REBARINFO* prbi) const;
	COLORREF GetBkColor() const;
	IDropTarget* GetDropTarget() const;
	BOOL GetRect(UINT uBand, LPRECT prc) const;
	UINT GetRowCount() const;
	UINT GetRowHeight(UINT uRow) const;
	COLORREF GetTextColor() const;
	CToolTipCtrl* GetToolTips() const;
	int IDToIndex(UINT uBandID) const;
	BOOL SetBandInfo(UINT uBand, REBARBANDINFO* prbbi);
	BOOL SetBarInfo(REBARINFO* prbi);
	COLORREF SetBkColor(COLORREF clr);
	CWnd* SetOwner(CWnd* pWnd);
	COLORREF SetTextColor(COLORREF clr);
	void SetToolTips(CToolTipCtrl* pToolTip);
	CImageList* GetImageList() const;
	BOOL SetImageList(CImageList* pImageList);
	void GetBandBorders(UINT uBand, LPRECT prc) const;
	CPalette* GetPalette() const;
	CPalette* SetPalette(HPALETTE hPal);
	BOOL GetColorScheme(COLORSCHEME* lpcs);
	void SetColorScheme(const COLORSCHEME* lpcs);

#if (_WIN32_WINNT >= 0x0501)
	void GetBandMargins(PMARGINS pMargins);
	HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
#endif


// Operations
public:
	void BeginDrag(UINT uBand, DWORD dwPos = (DWORD)-1);
	BOOL DeleteBand(UINT uBand);
	void DragMove(DWORD dwPos = (DWORD)-1);
	void EndDrag();
	int HitTest(RBHITTESTINFO* prbht);
	BOOL InsertBand(UINT uIndex, REBARBANDINFO* prbbi);
	void MaximizeBand(UINT uBand);
	void MinimizeBand(UINT uBand);
	void RestoreBand(UINT uBand);
	BOOL ShowBand(UINT uBand, BOOL fShow = TRUE);
	BOOL SizeToRect(CRect& rect);
	BOOL MoveBand(UINT uFrom, UINT uTo);

#if _WIN32_IE >= 0x0500
	void PushChevron(UINT uBand, LPARAM lAppValue);
#endif
};

#ifndef _AFX_NO_RICHEDIT_SUPPORT
/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrl

// NOTE: This class must remain a binary-compatible subset
// of CRichEditView. Do not add data members or virtual functions
// directly to this class.
class CRichEditCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual OK here - CWnd has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CRichEditCtrl)

// Constructors
public:
	CRichEditCtrl();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	BOOL CanUndo() const;
	BOOL CanRedo() const;
	UNDONAMEID GetUndoName() const;
	UNDONAMEID GetRedoName() const;
	int GetLineCount() const;
	BOOL GetModify() const;
	void SetModify(BOOL bModified = TRUE);
	BOOL SetTextMode(UINT fMode);
	UINT GetTextMode() const;
	void GetRect(LPRECT lpRect) const;
	CPoint GetCharPos(long lChar) const;
	UINT GetOptions() const;
	void SetOptions(WORD wOp, DWORD dwFlags);
	BOOL SetAutoURLDetect(BOOL bEnable = TRUE);
	UINT GetWordWrapMode() const;
	UINT SetWordWrapMode(UINT uFlags) const;
	BOOL GetPunctuation(UINT fType, PUNCTUATION* lpPunc) const;
	BOOL SetPunctuation(UINT fType, PUNCTUATION* lpPunc);

	// NOTE: first word in lpszBuffer must contain the size of the buffer!
	// NOTE: Copied line does not contain null character!
	int GetLine(__in int nIndex, LPTSTR lpszBuffer) const;
	// NOTE: Copied line does not contain null character!
	int GetLine(__in int nIndex, __out_ecount_part(nMaxLength, return) LPTSTR lpszBuffer, __in int nMaxLength) const;

	BOOL CanPaste(UINT nFormat = 0) const;
	void GetSel(long& nStartChar, long& nEndChar) const;
	void GetSel(CHARRANGE &cr) const;
	void LimitText(long nChars = 0);
	long LineFromChar(long nIndex) const;
	CPoint PosFromChar(UINT nChar) const;
	int CharFromPos(CPoint pt) const;

	void SetSel(long nStartChar, long nEndChar);
	void SetSel(CHARRANGE &cr);
	DWORD GetDefaultCharFormat(CHARFORMAT &cf) const;
	DWORD GetDefaultCharFormat(CHARFORMAT2 &cf) const;
	DWORD GetSelectionCharFormat(CHARFORMAT &cf) const;
	DWORD GetSelectionCharFormat(CHARFORMAT2 &cf) const;
	long GetEventMask() const;
	long GetLimitText() const;
	DWORD GetParaFormat(PARAFORMAT &pf) const;
	DWORD GetParaFormat(PARAFORMAT2 &pf) const;
	// richedit EM_GETSELTEXT is ANSI
	_AFX_INSECURE_DEPRECATE("GetSelText(char *) is unsafe. Instead, use GetSelText(void) returning CString") 
	long GetSelText(__out_z LPSTR lpBuf) const;
	int GetTextRange(int nFirst, int nLast, CString& refString) const;
	CString GetSelText() const;
	WORD GetSelectionType() const;
	COLORREF SetBackgroundColor(BOOL bSysColor, COLORREF cr);
	BOOL SetDefaultCharFormat(CHARFORMAT &cf);
	BOOL SetDefaultCharFormat(CHARFORMAT2 &cf);
	BOOL SetSelectionCharFormat(CHARFORMAT &cf);
	BOOL SetSelectionCharFormat(CHARFORMAT2 &cf);
	BOOL SetWordCharFormat(CHARFORMAT &cf);
	BOOL SetWordCharFormat(CHARFORMAT2 &cf);
	DWORD SetEventMask(DWORD dwEventMask);
	BOOL SetParaFormat(PARAFORMAT &pf);
	BOOL SetParaFormat(PARAFORMAT2 &pf);
	BOOL SetTargetDevice(HDC hDC, long lLineWidth);
	BOOL SetTargetDevice(CDC &dc, long lLineWidth);
	long GetTextLength() const;
	long GetTextLengthEx(DWORD dwFlags, UINT uCodePage = -1) const;
	BOOL SetReadOnly(BOOL bReadOnly = TRUE);
	int GetFirstVisibleLine() const;

// Operations
	void EmptyUndoBuffer();
	void StopGroupTyping();
	UINT SetUndoLimit(UINT nLimit);

	int LineIndex(int nLine = -1) const;
	int LineLength(int nLine = -1) const;
	void LineScroll(int nLines, int nChars = 0);
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
	void SetRect(LPCRECT lpRect);

	BOOL DisplayBand(LPRECT pDisplayRect);
	long FindText(DWORD dwFlags, FINDTEXTEX* pFindText) const;
	DWORD FindWordBreak(UINT nCode, DWORD nStart) const;
	long FormatRange(FORMATRANGE* pfr, BOOL bDisplay = TRUE);
	void HideSelection(BOOL bHide, BOOL bPerm);
	void PasteSpecial(UINT nClipFormat, DWORD dvAspect = 0, HMETAFILE hMF = 0);
	void RequestResize();
	long StreamIn(int nFormat, EDITSTREAM &es);
	long StreamOut(int nFormat, EDITSTREAM &es);

	// Clipboard operations
	BOOL Undo();
	BOOL Redo();
	void Clear();
	void Copy();
	void Cut();
	void Paste();

// OLE support
	IRichEditOle* GetIRichEditOle() const;
	BOOL SetOLECallback(IRichEditOleCallback* pCallback);

// Implementation
public:
	// virtual OK here - ~CWnd is already virtual
	virtual ~CRichEditCtrl();
};
#endif //!_AFX_NO_RICHEDIT_SUPPORT


/////////////////////////////////////////////////////////////////////////////
// CIPAddressCtrl

class CIPAddressCtrl : public CWnd
{
	DECLARE_DYNAMIC(CIPAddressCtrl)

public:
// Constructors
	CIPAddressCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	BOOL IsBlank() const;
	void ClearAddress();
	int GetAddress(BYTE& nField0, BYTE& nField1, BYTE& nField2, BYTE& nField3);
	int GetAddress(DWORD& dwAddress);
	void SetAddress(DWORD dwAddress);
	void SetAddress(BYTE nField0, BYTE nField1, BYTE nField2, BYTE nField3);
	void SetFieldFocus(WORD nField);
	void SetFieldRange(int nField, BYTE nLower, BYTE nUpper);

// Implementation
public:
	virtual ~CIPAddressCtrl();
};

#if (_WIN32_WINNT >= 0x0501)
/////////////////////////////////////////////////////////////////////////////
// CLinkCtrl

class CLinkCtrl : public CWnd
{
	DECLARE_DYNAMIC(CLinkCtrl)

// Constructors
public:
	CLinkCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd, UINT nID);

// Attributes
	int GetIdealHeight() const;

// operations	
	BOOL SetItem(PLITEM pItem);
	BOOL SetItemID(int iLink, LPCWSTR szID);
	BOOL SetItemUrl(int iLink, LPCWSTR szUrl);
	BOOL SetItemState(int iLink, UINT state, 
		UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED);

	BOOL GetItem(PLITEM pItem) const;
	BOOL GetItemID(int iLink, CString& strID) const;
	BOOL GetItemID(__in int iLink, __out_ecount_z(cchID) LPWSTR szID, __in UINT cchID) const;
	BOOL GetItemUrl(int iLink, CString& strUrl) const;
	BOOL GetItemUrl(__in int iLink, __out_ecount_z(cchUrl) LPWSTR szUrl, __in UINT cchUrl) const;
	BOOL GetItemState(int iLink, UINT *pnState, 
		UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED) const;	

	BOOL HitTest(PLHITTESTINFO phti) const;

//Implementation
public:
	virtual ~CLinkCtrl();	
};

#endif	// _WIN32_WINNT >= 0x0501

/////////////////////////////////////////////////////////////////////////////
// Inline function declarations

#ifdef _AFX_ALL_WARNINGS
#pragma warning(pop)
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#ifdef _AFX_ENABLE_INLINES
#define _AFXCMN_INLINE AFX_INLINE
#include <afxcmn.inl>
#include <afxcmn2.inl>
#undef _AFXCMN_INLINE
#endif
#include <afxcmn3.inl>

#undef AFX_DATA
#define AFX_DATA

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif
#ifndef _AFX_FULLTYPEINFO
#pragma component(mintypeinfo, off)
#endif

#endif //__AFXCMN_H__

/////////////////////////////////////////////////////////////////////////////
