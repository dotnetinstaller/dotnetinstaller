#include "StdAfx.h"
#include "Components.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

Components::Components()
{
}

void Components::add(const ComponentPtr& component)
{
    components_map.insert(std::make_pair(component->id, component));
    push_back(component);
}

bool Components::contains(const std::wstring& id) const
{
    return components_map.find(id) != components_map.end();
}

Components::Components(const Components& rhs)
{
    operator=(rhs);
}

Components& Components::operator=(const Components& rhs)
{
    components_map = rhs.components_map;
    std::vector<ComponentPtr>::operator=(rhs);
    return * this;
}

ComponentPtr Components::GetComponentPtr(Component * pc) const
{
    for each (const ComponentPtr& component in * this)
    {
        if (get(component) == pc)
            return component;
    }

    THROW_EX(L"Invalid component: " << pc->GetString());
}

Components Components::GetSupportedComponents(DVLib::LcidType lcidtype, InstallSequence sequence) const
{
    LCID lcid = DVLib::GetOperatingSystemLCID(lcidtype);
    LOG(L"-- Loading supported components (lcid=" << lcid << L")");
    Components result;
    for each (const ComponentPtr& component in * this)
    {
        bool supported = component->IsSupported(lcid);

        // component install/uninstall support
        if (! component->supports_install && InstallerSession::Instance->sequence == SequenceInstall)
            supported = false;

        if (! component->supports_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
            supported = false;

        if (supported)
        {
            switch(sequence)
            {
            case SequenceInstall:
                result.push_back(component);
                break;
            case SequenceUninstall:
                result.insert(result.begin(), component);
                break;
            default:
                THROW_EX(L"Invalid sequence: " << InstallSequenceUtil::towstring(sequence));
            }
        }

        LOG(L"-- " << component->id << L" (display_name='" << component->GetDisplayName() << L"', os_filter_lcid=" << component->os_filter_lcid
            << L", os_filter=" << component->os_filter
            << L", os_filter_min=" << DVLib::os2wstring(component->os_filter_min)
            << L", os_filter_max=" << DVLib::os2wstring(component->os_filter_max)
            << L", os_type_filter=" << component->os_type_filter
            << L", processor_architecture_filter=" << component->processor_architecture_filter
            << L"): " << (supported ? L"LOADED" : L"SKIPPED"));
    }

    LOG(L"--- Loaded " << result.size() << L" supported component(s)");
    return result;
}

int Components::Exec(IExecuteCallback * callback)
{
    if (callback)
    {
        callback->OnExecBegin();
    }

    int rc = 0;
    for each(const ComponentPtr& component in * this)
    {
        if (! component->checked)
        {
            LOG(L"--- Component '" << component->id << L"' (" << component->GetDisplayName() << L"): SKIPPED");
            continue;
        }

        try
        {
            LOG(L"--- Component '" << component->id << L"' (" << component->GetDisplayName() << L"): EXECUTING");

            if (callback && ! callback->OnComponentExecBegin(component))
                break;

            component->Exec();

            if (callback && ! callback->OnComponentExecWait(component))
                break;

            component->Wait();

            LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): SUCCESS");

            if (callback && ! callback->OnComponentExecSuccess(component))
                break;
        }
        catch(std::exception& ex)
        {
            if (rc == 0) rc = component->GetExitCode();
            if (rc == 0) rc = -1;

            LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): ERROR - " 
                << DVLib::string2wstring(ex.what()));

            if (callback && ! callback->OnComponentExecError(component, ex))
                break;
        }
    }

    return rc;
}

std::wstring Components::GetString(int indent) const
{
    std::wstringstream ss;
    for each(const ComponentPtr& component in * this)
    {
        ss << component->GetString(indent) << std::endl;
    }

    return ss.str();
}
