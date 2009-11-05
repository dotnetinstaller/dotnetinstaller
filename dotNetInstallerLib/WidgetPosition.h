#pragma once

//
// a widget position
// unlike CRect represents a rectangle at x/y coordinates with width and height
//
class WidgetPosition
{
	int _left;
	int _top;
	int _width;
	int _height;
public:
	inline int Left() const { return _left; }
	inline int Top() const { return _top; }
	inline int Width() const { return _width; }
	inline int Height() const { return _height; }
	inline void Left(int value) { _left = value; }
	inline void Top(int value) { _top = value; }
	inline void Width(int value) { _width = value; }
	inline void Height(int value) { _height = value; }
	inline bool IsSet() const { return _left != 0 || _top != 0 || _width != 0 || _height != 0; }
	WidgetPosition();
	WidgetPosition(const std::wstring&);
	WidgetPosition(const WidgetPosition&);
	WidgetPosition& operator=(const WidgetPosition&);
	bool FromString(const std::wstring& p_RectString);
	void FromRect(const RECT& rect);
	std::wstring ToString() const;
	CRect ToRect() const;
};
