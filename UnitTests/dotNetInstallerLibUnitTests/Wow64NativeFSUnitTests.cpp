#include "StdAfx.h"
#include "Wow64NativeFSUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(Wow64NativeFSUnitTests);

void Wow64NativeFSUnitTests::testAuto()
{
    if (DVLib::IsWow64())
    {
        LPVOID old_value = (LPVOID) 0xDEADBEEF;

        {
            auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
            CPPUNIT_ASSERT(wow64_native_fs->IsDisabled());
            CPPUNIT_ASSERT(DVLib::Wow64DisableWow64FsRedirection(& old_value));
            CPPUNIT_ASSERT(old_value != NULL);
            // will revert automatically
        }

        CPPUNIT_ASSERT(DVLib::Wow64DisableWow64FsRedirection(& old_value));
        CPPUNIT_ASSERT(old_value == NULL);
        CPPUNIT_ASSERT(DVLib::Wow64RevertWow64FsRedirection(old_value));
    }
    else
    {
        auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
        CPPUNIT_ASSERT(! wow64_native_fs->IsDisabled());
    }
}

