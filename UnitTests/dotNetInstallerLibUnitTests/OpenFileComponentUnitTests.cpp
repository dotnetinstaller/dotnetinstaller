#include "StdAfx.h"
#include "OpenFileComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void OpenFileComponentUnitTests::testExec()
{
    OpenFileComponent component;
    component.file = L"cmd.exe /C";
    component.Exec();
}

void OpenFileComponentUnitTests::testMustReboot()
{
    OpenFileComponent component;
    Assert::IsTrue(! component.IsRebootRequired());
    component.mustreboot = true;
    Assert::IsTrue(component.IsRebootRequired());
}
