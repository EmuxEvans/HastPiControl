//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace concurrency;
using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Devices::AllJoyn;
using namespace com::hastarin::GarageDoor;

std::map<alljoyn_interfacedescription, WeakReference*> GarageDoorConsumer::SourceInterfaces;

GarageDoorConsumer::GarageDoorConsumer(AllJoynBusAttachment^ busAttachment)
    : m_busAttachment(busAttachment),
    m_proxyBusObject(nullptr),
    m_busObject(nullptr),
    m_sessionListener(nullptr),
    m_sessionId(0)
{
    m_weak = new WeakReference(this);
    m_signals = ref new GarageDoorSignals();
    m_nativeBusAttachment = AllJoynHelpers::GetInternalBusAttachment(m_busAttachment);
}

GarageDoorConsumer::~GarageDoorConsumer()
{
    AllJoynBusObjectManager::ReleaseBusObject(m_nativeBusAttachment, AllJoynHelpers::PlatformToMultibyteString(ServiceObjectPath).data());
    if (SessionListener != nullptr)
    {
        alljoyn_busattachment_setsessionlistener(m_nativeBusAttachment, m_sessionId, nullptr);
        alljoyn_sessionlistener_destroy(SessionListener);
    }
    if (nullptr != ProxyBusObject)
    {
        alljoyn_proxybusobject_destroy(ProxyBusObject);
    }
    delete m_weak;
}

void GarageDoorConsumer::OnSessionLost(_In_ alljoyn_sessionid sessionId, _In_ alljoyn_sessionlostreason reason)
{
    if (sessionId == m_sessionId)
    {
        AllJoynSessionLostEventArgs^ args = ref new AllJoynSessionLostEventArgs(static_cast<AllJoynSessionLostReason>(reason));
        SessionLost(this, args);
    }
}

void GarageDoorConsumer::OnSessionMemberAdded(_In_ alljoyn_sessionid sessionId, _In_ PCSTR uniqueName)
{
    if (sessionId == m_sessionId)
    {
        auto args = ref new AllJoynSessionMemberAddedEventArgs(AllJoynHelpers::MultibyteToPlatformString(uniqueName));
        SessionMemberAdded(this, args);
    }
}

void GarageDoorConsumer::OnSessionMemberRemoved(_In_ alljoyn_sessionid sessionId, _In_ PCSTR uniqueName)
{
    if (sessionId == m_sessionId)
    {
        auto args = ref new AllJoynSessionMemberRemovedEventArgs(AllJoynHelpers::MultibyteToPlatformString(uniqueName));
        SessionMemberRemoved(this, args);
    }
}

QStatus GarageDoorConsumer::AddSignalHandler(_In_ alljoyn_busattachment busAttachment, _In_ alljoyn_interfacedescription interfaceDescription, _In_ PCSTR methodName, _In_ alljoyn_messagereceiver_signalhandler_ptr handler)
{
    alljoyn_interfacedescription_member member;
    if (!alljoyn_interfacedescription_getmember(interfaceDescription, methodName, &member))
    {
        return ER_BUS_INTERFACE_NO_SUCH_MEMBER;
    }

    return alljoyn_busattachment_registersignalhandler(busAttachment, handler, member, NULL);
}

IAsyncOperation<GarageDoorJoinSessionResult^>^ GarageDoorConsumer::JoinSessionAsync(
    _In_ AllJoynServiceInfo^ serviceInfo, _Inout_ GarageDoorWatcher^ watcher)
{
    return create_async([serviceInfo, watcher]() -> GarageDoorJoinSessionResult^
    {
        auto result = ref new GarageDoorJoinSessionResult();
        result->Consumer = ref new GarageDoorConsumer(watcher->BusAttachment);
        result->Status = result->Consumer->JoinSession(serviceInfo);
        return result;
    });
}

IAsyncOperation<GarageDoorOpenResult^>^ GarageDoorConsumer::OpenAsync(_In_ bool interfaceMemberPartialOpen)
{
    return create_async([this, interfaceMemberPartialOpen]() -> GarageDoorOpenResult^
    {
        auto result = ref new GarageDoorOpenResult();
        
        alljoyn_message message = alljoyn_message_create(m_nativeBusAttachment);
        size_t argCount = 1;
        alljoyn_msgarg inputs = alljoyn_msgarg_array_create(argCount);

        QStatus status = ER_OK;
        if (ER_OK == status)
        {
            status = static_cast<QStatus>(TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(inputs, 0), "b", interfaceMemberPartialOpen));
        }
	
        if (ER_OK == status)
        {
            status = alljoyn_proxybusobject_methodcall(
                ProxyBusObject,
                "com.hastarin.GarageDoor",
                "Open",
                inputs,
                argCount,
                message,
                c_MessageTimeoutInMilliseconds,
                0);
        }
        result->Status = static_cast<int>(status);
        
        alljoyn_message_destroy(message);
        alljoyn_msgarg_destroy(inputs);

        return result;
    });
}
IAsyncOperation<GarageDoorCloseResult^>^ GarageDoorConsumer::CloseAsync()
{
    return create_async([this]() -> GarageDoorCloseResult^
    {
        auto result = ref new GarageDoorCloseResult();
        
        alljoyn_message message = alljoyn_message_create(m_nativeBusAttachment);
        size_t argCount = 0;
        alljoyn_msgarg inputs = alljoyn_msgarg_array_create(argCount);

        QStatus status = ER_OK;
        if (ER_OK == status)
        {
            status = alljoyn_proxybusobject_methodcall(
                ProxyBusObject,
                "com.hastarin.GarageDoor",
                "Close",
                inputs,
                argCount,
                message,
                c_MessageTimeoutInMilliseconds,
                0);
        }
        result->Status = static_cast<int>(status);
        
        alljoyn_message_destroy(message);
        alljoyn_msgarg_destroy(inputs);

        return result;
    });
}
IAsyncOperation<GarageDoorPushButtonResult^>^ GarageDoorConsumer::PushButtonAsync()
{
    return create_async([this]() -> GarageDoorPushButtonResult^
    {
        auto result = ref new GarageDoorPushButtonResult();
        
        alljoyn_message message = alljoyn_message_create(m_nativeBusAttachment);
        size_t argCount = 0;
        alljoyn_msgarg inputs = alljoyn_msgarg_array_create(argCount);

        QStatus status = ER_OK;
        if (ER_OK == status)
        {
            status = alljoyn_proxybusobject_methodcall(
                ProxyBusObject,
                "com.hastarin.GarageDoor",
                "PushButton",
                inputs,
                argCount,
                message,
                c_MessageTimeoutInMilliseconds,
                0);
        }
        result->Status = static_cast<int>(status);
        
        alljoyn_message_destroy(message);
        alljoyn_msgarg_destroy(inputs);

        return result;
    });
}

IAsyncOperation<GarageDoorGetIsOpenResult^>^ GarageDoorConsumer::GetIsOpenAsync()
{
    return create_async([this]() -> GarageDoorGetIsOpenResult^
    {
        PropertyGetContext<bool> getContext;
        
        alljoyn_proxybusobject_getpropertyasync(
            ProxyBusObject,
            "com.hastarin.GarageDoor",
            "IsOpen",
            [](QStatus status, alljoyn_proxybusobject obj, const alljoyn_msgarg value, void* context)
            {
                UNREFERENCED_PARAMETER(obj);
                auto propertyContext = static_cast<PropertyGetContext<bool>*>(context);

                if (ER_OK == status)
                {
                    bool argument;
                    status = static_cast<QStatus>(TypeConversionHelpers::GetAllJoynMessageArg(value, "b", &argument));

                    propertyContext->SetValue(argument);
                }
                propertyContext->SetStatus(status);
                propertyContext->SetEvent();
            },
            c_MessageTimeoutInMilliseconds,
            &getContext);

        getContext.Wait();

        auto result = ref new GarageDoorGetIsOpenResult();
        result->Status = getContext.GetStatus();
        result->IsOpen = getContext.GetValue();
        return result;
    });
}

IAsyncOperation<GarageDoorGetIsPartiallyOpenResult^>^ GarageDoorConsumer::GetIsPartiallyOpenAsync()
{
    return create_async([this]() -> GarageDoorGetIsPartiallyOpenResult^
    {
        PropertyGetContext<bool> getContext;
        
        alljoyn_proxybusobject_getpropertyasync(
            ProxyBusObject,
            "com.hastarin.GarageDoor",
            "IsPartiallyOpen",
            [](QStatus status, alljoyn_proxybusobject obj, const alljoyn_msgarg value, void* context)
            {
                UNREFERENCED_PARAMETER(obj);
                auto propertyContext = static_cast<PropertyGetContext<bool>*>(context);

                if (ER_OK == status)
                {
                    bool argument;
                    status = static_cast<QStatus>(TypeConversionHelpers::GetAllJoynMessageArg(value, "b", &argument));

                    propertyContext->SetValue(argument);
                }
                propertyContext->SetStatus(status);
                propertyContext->SetEvent();
            },
            c_MessageTimeoutInMilliseconds,
            &getContext);

        getContext.Wait();

        auto result = ref new GarageDoorGetIsPartiallyOpenResult();
        result->Status = getContext.GetStatus();
        result->IsPartiallyOpen = getContext.GetValue();
        return result;
    });
}

void GarageDoorConsumer::OnPropertyChanged(_In_ alljoyn_proxybusobject obj, _In_ PCSTR interfaceName, _In_ const alljoyn_msgarg changed, _In_ const alljoyn_msgarg invalidated)
{
    UNREFERENCED_PARAMETER(obj);
    UNREFERENCED_PARAMETER(interfaceName);
    UNREFERENCED_PARAMETER(invalidated);

    alljoyn_msgarg changedProperties;
    size_t changedPropertyCount;
    if (ER_OK != alljoyn_msgarg_get(changed, "a{sv}", &changedPropertyCount, &changedProperties))
    {
        return;
    }

    for (size_t i = 0; i < changedPropertyCount; i++)
    {
        char* propertyName;
        alljoyn_msgarg propertyValue;
        if (ER_OK != alljoyn_msgarg_get(alljoyn_msgarg_array_element(changedProperties, i), "{sv}", &propertyName, &propertyValue))
        {
            return;
        }


        if (strcmp("IsOpen", propertyName) == 0)
        {
            bool argument;
            (void)TypeConversionHelpers::GetAllJoynMessageArg(propertyValue, "b", &argument);
            IsOpenChanged(this, (Platform::Object^)argument);
        }
        if (strcmp("IsPartiallyOpen", propertyName) == 0)
        {
            bool argument;
            (void)TypeConversionHelpers::GetAllJoynMessageArg(propertyValue, "b", &argument);
            IsPartiallyOpenChanged(this, (Platform::Object^)argument);
        }
    }
}

int32 GarageDoorConsumer::JoinSession(_In_ AllJoynServiceInfo^ serviceInfo)
{
    alljoyn_sessionlistener_callbacks callbacks =
    {
        AllJoynHelpers::SessionLostHandler<GarageDoorConsumer>,
        AllJoynHelpers::SessionMemberAddedHandler<GarageDoorConsumer>,
        AllJoynHelpers::SessionMemberRemovedHandler<GarageDoorConsumer>
    };

    alljoyn_busattachment_enableconcurrentcallbacks(AllJoynHelpers::GetInternalBusAttachment(m_busAttachment));

    SessionListener = alljoyn_sessionlistener_create(&callbacks, m_weak);
    alljoyn_sessionopts sessionOpts = alljoyn_sessionopts_create(ALLJOYN_TRAFFIC_TYPE_MESSAGES, true, ALLJOYN_PROXIMITY_ANY, ALLJOYN_TRANSPORT_ANY);

    std::vector<char> sessionNameUtf8 = AllJoynHelpers::PlatformToMultibyteString(serviceInfo->UniqueName);
    RETURN_IF_QSTATUS_ERROR(alljoyn_busattachment_joinsession(
        m_nativeBusAttachment,
        &sessionNameUtf8[0],
        serviceInfo->SessionPort,
        SessionListener,
        &m_sessionId,
        sessionOpts));
    alljoyn_sessionopts_destroy(sessionOpts);

    ServiceObjectPath = serviceInfo->ObjectPath;
    std::vector<char> objectPath = AllJoynHelpers::PlatformToMultibyteString(ServiceObjectPath);

    if (objectPath.empty())
    {
        return AllJoynStatus::Fail;
    }

    ProxyBusObject = alljoyn_proxybusobject_create(m_nativeBusAttachment, &sessionNameUtf8[0], &objectPath[0], m_sessionId);
    if (nullptr == ProxyBusObject)
    {
        return AllJoynStatus::Fail;
    }

    PCSTR propertyNames[] = { "IsOpen", "IsPartiallyOpen" };

    RETURN_IF_QSTATUS_ERROR(alljoyn_proxybusobject_registerpropertieschangedlistener(
        ProxyBusObject,
        "com.hastarin.GarageDoor",
        propertyNames,
        _countof(propertyNames),
        AllJoynHelpers::PropertyChangedHandler<GarageDoorConsumer>, 
        m_weak));


    alljoyn_interfacedescription description = alljoyn_busattachment_getinterface(m_nativeBusAttachment, "com.hastarin.GarageDoor");
    if (nullptr == description)
    {
        return AllJoynStatus::Fail;
    }

    RETURN_IF_QSTATUS_ERROR(AllJoynBusObjectManager::GetBusObject(m_nativeBusAttachment, AllJoynHelpers::PlatformToMultibyteString(ServiceObjectPath).data(), &m_busObject));
   
    if (!AllJoynBusObjectManager::BusObjectIsRegistered(m_nativeBusAttachment, m_busObject))
    {
        RETURN_IF_QSTATUS_ERROR(alljoyn_busobject_addinterface(BusObject, description));
    }


    SourceInterfaces[description] = m_weak;

    unsigned int noneMechanismIndex = 0;
    bool authenticationMechanismsContainsNone = m_busAttachment->AuthenticationMechanisms->IndexOf(AllJoynAuthenticationMechanism::None, &noneMechanismIndex);
    QCC_BOOL interfaceIsSecure = alljoyn_interfacedescription_issecure(description);

    // If the current set of AuthenticationMechanisms supports authentication, 
    // determine whether to secure the connection.
    if (AllJoynHelpers::CanSecure(m_busAttachment->AuthenticationMechanisms))
    {
        // Secure the connection if the org.alljoyn.Bus.Secure XML annotation
        // is specified, or if None is not present in AuthenticationMechanisms.
        if (!authenticationMechanismsContainsNone || interfaceIsSecure)
        {
            RETURN_IF_QSTATUS_ERROR(alljoyn_proxybusobject_secureconnection(ProxyBusObject, QCC_FALSE));
            RETURN_IF_QSTATUS_ERROR(AllJoynBusObjectManager::TryRegisterBusObject(m_nativeBusAttachment, BusObject, true));
        }
        else
        {
            RETURN_IF_QSTATUS_ERROR(AllJoynBusObjectManager::TryRegisterBusObject(m_nativeBusAttachment, BusObject, false));
        }
    }
    else
    {
        // If the current set of AuthenticationMechanisms does not support authentication
        // but the interface requires security, report an error.
        if (interfaceIsSecure)
        {
            return static_cast<int32>(ER_BUS_NO_AUTHENTICATION_MECHANISM);
        }
        else
        {
            RETURN_IF_QSTATUS_ERROR(AllJoynBusObjectManager::TryRegisterBusObject(m_nativeBusAttachment, BusObject, false));
        }
    }

    RETURN_IF_QSTATUS_ERROR(alljoyn_proxybusobject_addinterface(ProxyBusObject, description));
    
    m_signals->Initialize(BusObject, m_sessionId);

    return AllJoynStatus::Ok;
}
