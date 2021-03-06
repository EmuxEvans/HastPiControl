//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace com::hastarin::GarageDoor;

// Note: Unlike an Interface implementation, which provides a single handler for each member, the event
// model allows for 0 or more listeners to be registered. The EventAdapter implementation deals with this
// difference by implementing a last-writer-wins policy. The lack of any return value (i.e., 0 listeners)
// is handled by returning a null result.

// Methods
IAsyncOperation<GarageDoorOpenResult^>^ GarageDoorServiceEventAdapter::OpenAsync(_In_ AllJoynMessageInfo^ info, _In_ bool interfaceMemberPartialOpen)
{
    auto args = ref new GarageDoorOpenCalledEventArgs(info, interfaceMemberPartialOpen);
    OpenCalled(this, args);
    return GarageDoorOpenCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<GarageDoorCloseResult^>^ GarageDoorServiceEventAdapter::CloseAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new GarageDoorCloseCalledEventArgs(info);
    CloseCalled(this, args);
    return GarageDoorCloseCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<GarageDoorPushButtonResult^>^ GarageDoorServiceEventAdapter::PushButtonAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new GarageDoorPushButtonCalledEventArgs(info);
    PushButtonCalled(this, args);
    return GarageDoorPushButtonCalledEventArgs::GetResultAsync(args);
}

// Property Reads
IAsyncOperation<GarageDoorGetIsOpenResult^>^ GarageDoorServiceEventAdapter::GetIsOpenAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new GarageDoorGetIsOpenRequestedEventArgs(info);
    GetIsOpenRequested(this, args);
    return GarageDoorGetIsOpenRequestedEventArgs::GetResultAsync(args);
}

IAsyncOperation<GarageDoorGetIsPartiallyOpenResult^>^ GarageDoorServiceEventAdapter::GetIsPartiallyOpenAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new GarageDoorGetIsPartiallyOpenRequestedEventArgs(info);
    GetIsPartiallyOpenRequested(this, args);
    return GarageDoorGetIsPartiallyOpenRequestedEventArgs::GetResultAsync(args);
}

// Property Writes
