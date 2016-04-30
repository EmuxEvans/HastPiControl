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
#pragma once

using namespace concurrency;

namespace com { namespace hastarin { namespace GarageDoor {

ref class GarageDoorConsumer;

public ref class GarageDoorOpenResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static GarageDoorOpenResult^ CreateSuccessResult()
    {
        auto result = ref new GarageDoorOpenResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static GarageDoorOpenResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new GarageDoorOpenResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class GarageDoorCloseResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static GarageDoorCloseResult^ CreateSuccessResult()
    {
        auto result = ref new GarageDoorCloseResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static GarageDoorCloseResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new GarageDoorCloseResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class GarageDoorPushButtonResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static GarageDoorPushButtonResult^ CreateSuccessResult()
    {
        auto result = ref new GarageDoorPushButtonResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static GarageDoorPushButtonResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new GarageDoorPushButtonResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class GarageDoorJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property GarageDoorConsumer^ Consumer
    {
        GarageDoorConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ GarageDoorConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    GarageDoorConsumer^ m_consumer;
};

public ref class GarageDoorGetIsOpenResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property bool IsOpen
    {
        bool get() { return m_value; }
    internal:
        void set(_In_ bool value) { m_value = value; }
    }

    static GarageDoorGetIsOpenResult^ CreateSuccessResult(_In_ bool value)
    {
        auto result = ref new GarageDoorGetIsOpenResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->IsOpen = value;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }

    static GarageDoorGetIsOpenResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new GarageDoorGetIsOpenResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    bool m_value;
};

public ref class GarageDoorGetIsPartiallyOpenResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property bool IsPartiallyOpen
    {
        bool get() { return m_value; }
    internal:
        void set(_In_ bool value) { m_value = value; }
    }

    static GarageDoorGetIsPartiallyOpenResult^ CreateSuccessResult(_In_ bool value)
    {
        auto result = ref new GarageDoorGetIsPartiallyOpenResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->IsPartiallyOpen = value;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }

    static GarageDoorGetIsPartiallyOpenResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new GarageDoorGetIsPartiallyOpenResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
    bool m_value;
};

} } } 
