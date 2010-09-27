#pragma once

#include "HtmlWindow.h"

// a widget task
struct widget_task : public htmlayout::gui_task
{
	htmlayout::dom::element * m_p;

	widget_task(htmlayout::dom::element * p)
		: m_p(p)
	{
		
	}

	virtual void exec_valid() = 0;

	virtual void exec()
	{
		if (m_p->is_valid())
		{
			exec_valid();
		}
	}
};

// remove an attribute from a widget
struct html_remove_attribute_task : public widget_task
{
	std::string m_attribute;

	html_remove_attribute_task(htmlayout::dom::element * p, const std::string& attribute)
		: widget_task(p)
		, m_attribute(attribute)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->remove_attribute(m_attribute.c_str());
	}
};

// set style attribute
struct html_set_style_attribute_task : public widget_task
{
	std::string m_attribute_name;
	std::wstring m_attribute_value;

	html_set_style_attribute_task(htmlayout::dom::element * p, 
		const std::string& attribute_name, const std::wstring& attribute_value)
		: widget_task(p)
		, m_attribute_name(attribute_name)
		, m_attribute_value(attribute_value)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->set_style_attribute(m_attribute_name.c_str(), m_attribute_value.c_str());
	}
};

// clear style attribute
struct html_clear_style_attribute_task : public widget_task
{
	std::string m_attribute_name;

	html_clear_style_attribute_task(htmlayout::dom::element * p, 
		const std::string& attribute_name)
		: widget_task(p)
		, m_attribute_name(attribute_name)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->clear_style_attribute(m_attribute_name.c_str());
	}
};

struct html_set_text_task : public widget_task
{
	std::wstring m_text;

	html_set_text_task(htmlayout::dom::element * p, 
		const std::wstring& text)
		: widget_task(p)
		, m_text(text)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->set_text(m_text.c_str());
	}
};

struct html_set_attribute_task : public widget_task
{
	std::string m_attribute_name;
	std::wstring m_attribute_value;

	html_set_attribute_task(htmlayout::dom::element * p, 
		const std::string& attribute_name, const std::wstring& attribute_value)
		: widget_task(p)
		, m_attribute_name(attribute_name)
		, m_attribute_value(attribute_value)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->set_attribute(m_attribute_name.c_str(), m_attribute_value.c_str());
	}
};

struct html_insert_task : public widget_task
{
	htmlayout::dom::element m_widget;
	unsigned int m_index;
	static const unsigned int last = 0xFFFF;

	html_insert_task(htmlayout::dom::element * p, 
		htmlayout::dom::element widget, unsigned int index)
		: widget_task(p)
		, m_widget(widget)
		, m_index(index)
	{
		
	}

	virtual void exec_valid()
	{
		int index = m_index;
		
		if (m_index == last)
		{
			index = m_p->children_count();
		}

		m_p->insert(m_widget, index);
	}
};


struct html_clear_task : public widget_task
{
	html_clear_task(htmlayout::dom::element * p)
		: widget_task(p)
	{
		
	}

	virtual void exec_valid()
	{
		m_p->clear();
	}
};
// auto pointers

struct html_disabled
{
    static void close(htmlayout::dom::element * p)
    {
		htmlayout::queue::push(new html_remove_attribute_task(p, "disabled"), HtmlWindow::s_hwnd);
    }
};

struct html_save_progress
{
	int m_value;
	int m_maxvalue;
	htmlayout::dom::element * m_p;

	html_save_progress(htmlayout::dom::element * p, int value, int maxvalue)
		: m_p(p)
		, m_value(value)
		, m_maxvalue(maxvalue)
	{

	}

    virtual ~html_save_progress()
    {	
		htmlayout::queue::push(new html_set_attribute_task(m_p, "maxvalue", DVLib::towstring(m_maxvalue).c_str()), HtmlWindow::s_hwnd);
		htmlayout::queue::push(new html_set_attribute_task(m_p, "value", DVLib::towstring(m_value).c_str()), HtmlWindow::s_hwnd);
    }
};
