#include "StdAfx.h"
#include "SetControlValuesTask.h"

SetControlValuesTask::SetControlValuesTask(const htmlayout::dom::element& root, HANDLE evt)
	: m_root(root)
	, m_event(evt)
{

}

void SetControlValuesTask::exec(htmlayout::dom::element elt)
{
	if (elt.is_valid())
	{
		const wchar_t * id = elt.get_attribute("id");
		const wchar_t * type = elt.get_attribute("type");
		const wchar_t * control_ptr = elt.get_attribute("control_ptr");

		if (id != NULL && type != NULL)
		{
			if (0 == wcscmp(type, L"checkbox"))
			{
				std::wstring value;
				if (control_ptr != NULL)
				{
					ControlCheckBox * p_checkbox = reinterpret_cast<ControlCheckBox *>(DVLib::wstring2long(control_ptr, 16));
					value = elt.get_state(STATE_CHECKED) ? p_checkbox->checked_value.GetValue() : p_checkbox->unchecked_value.GetValue();
				}
				else
				{
					value = elt.get_state(STATE_CHECKED) ? L"1" : L"";
				}

				LOG(L"--- Setting user-defined value '" << id << L"'=" << value);
				InstallerSession::Instance->AdditionalControlArgs[id] = value;
			}
		}

		for(unsigned int child_index = 0; child_index < m_root.children_count(); child_index++)
		{
			exec(elt.child(child_index));
		}
	}
}

void SetControlValuesTask::exec()
{
	exec(m_root);

	CHECK_WIN32_BOOL(SetEvent(m_event),
		L"SetEvent");
}
