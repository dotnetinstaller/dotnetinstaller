#pragma once

#include "HTMLayoutCtrl.h"
// CHTMPanel

class CHTMPanel : public CHTMLayoutCtrl
{
  DECLARE_DYNAMIC(CHTMPanel)

public:
  CHTMPanel();
  virtual ~CHTMPanel();

  BEGIN_HTML_COMMAND_MAP
    ON_HTML_COMMAND(L"cmd-step1", OnStep1)
  ON_HTML_COMMAND(L"cmd-step2", OnStep2)
  ON_HTML_COMMAND(L"cmd-step3", OnStep3)
  END_HTML_COMMAND_MAP

  void OnStep(const wchar_t* no) 
  { 
    htmlayout::dom::element root = htmlayout::dom::element::root_element(GetSafeHwnd());
    htmlayout::dom::element body = root.find_first("body");
    body.set_attribute("step",no);
    body.update();  
  }

  void OnStep1() { OnStep(L"1"); }
  void OnStep2() { OnStep(L"2"); }
  void OnStep3() { OnStep(L"3"); }


protected:
  DECLARE_MESSAGE_MAP()
};


