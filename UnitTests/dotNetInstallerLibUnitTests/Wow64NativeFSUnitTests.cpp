#include "StdAfx.h"
#include "Wow64NativeFSUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Wow64NativeFSUnitTests::testAuto()
{
    if (DVLib::IsWow64())
    {
        LPVOID old_value = (LPVOID) 0xDEADBEEF;

        {
            auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
            Assert::IsTrue(wow64_native_fs->IsDisabled());
            Assert::IsTrue(DVLib::Wow64DisableWow64FsRedirection(& old_value));
            Assert::IsTrue(old_value != NULL);
            // will revert automatically
        }

        Assert::IsTrue(DVLib::Wow64DisableWow64FsRedirection(& old_value));
        Assert::IsTrue(old_value == NULL);
        Assert::IsTrue(DVLib::Wow64RevertWow64FsRedirection(old_value));
    }
    else
    {
        auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
        Assert::IsTrue(! wow64_native_fs->IsDisabled());
    }
}

