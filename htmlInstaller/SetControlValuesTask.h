#pragma once

class SetControlValuesTask : public htmlayout::gui_task
{
private:
	htmlayout::dom::element m_root;
	HANDLE m_event;
	std::wstring * m_perror;
public:
	SetControlValuesTask(const htmlayout::dom::element& root, HANDLE evt, std::wstring * perror);
	void exec(htmlayout::dom::element elt);
	void exec();	
};
