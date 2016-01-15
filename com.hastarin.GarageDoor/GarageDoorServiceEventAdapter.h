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
#pragma once

namespace com { namespace hastarin { namespace GarageDoor {

// This class, and the associated EventArgs classes, exist for the benefit of JavaScript developers who
// do not have the ability to implement IGarageDoorService. Instead, GarageDoorServiceEventAdapter
// provides the Interface implementation and exposes a set of compatible events to the developer.
public ref class GarageDoorServiceEventAdapter sealed : [Windows::Foundation::Metadata::Default] IGarageDoorService
{
public:
    // Method Invocation Events
    event Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorOpenCalledEventArgs^>^ OpenCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorOpenCalledEventArgs^>^ handler) 
        { 
            return _OpenCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<GarageDoorServiceEventAdapter^>(sender), safe_cast<GarageDoorOpenCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _OpenCalled -= token; 
        } 
    internal: 
        void raise(GarageDoorServiceEventAdapter^ sender, GarageDoorOpenCalledEventArgs^ args) 
        { 
            _OpenCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorCloseCalledEventArgs^>^ CloseCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorCloseCalledEventArgs^>^ handler) 
        { 
            return _CloseCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<GarageDoorServiceEventAdapter^>(sender), safe_cast<GarageDoorCloseCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _CloseCalled -= token; 
        } 
    internal: 
        void raise(GarageDoorServiceEventAdapter^ sender, GarageDoorCloseCalledEventArgs^ args) 
        { 
            _CloseCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorPushButtonCalledEventArgs^>^ PushButtonCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorPushButtonCalledEventArgs^>^ handler) 
        { 
            return _PushButtonCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<GarageDoorServiceEventAdapter^>(sender), safe_cast<GarageDoorPushButtonCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _PushButtonCalled -= token; 
        } 
    internal: 
        void raise(GarageDoorServiceEventAdapter^ sender, GarageDoorPushButtonCalledEventArgs^ args) 
        { 
            _PushButtonCalled(sender, args);
        } 
    }

    // Property Read Events
    event Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorGetIsOpenRequestedEventArgs^>^ GetIsOpenRequested 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorGetIsOpenRequestedEventArgs^>^ handler) 
        { 
            return _GetIsOpenRequested += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<GarageDoorServiceEventAdapter^>(sender), safe_cast<GarageDoorGetIsOpenRequestedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetIsOpenRequested -= token; 
        } 
    internal: 
        void raise(GarageDoorServiceEventAdapter^ sender, GarageDoorGetIsOpenRequestedEventArgs^ args) 
        { 
            _GetIsOpenRequested(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorGetIsPartiallyOpenRequestedEventArgs^>^ GetIsPartiallyOpenRequested 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<GarageDoorServiceEventAdapter^, GarageDoorGetIsPartiallyOpenRequestedEventArgs^>^ handler) 
        { 
            return _GetIsPartiallyOpenRequested += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<GarageDoorServiceEventAdapter^>(sender), safe_cast<GarageDoorGetIsPartiallyOpenRequestedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetIsPartiallyOpenRequested -= token; 
        } 
    internal: 
        void raise(GarageDoorServiceEventAdapter^ sender, GarageDoorGetIsPartiallyOpenRequestedEventArgs^ args) 
        { 
            _GetIsPartiallyOpenRequested(sender, args);
        } 
    }

    // Property Write Events
    // IGarageDoorService Implementation
    virtual Windows::Foundation::IAsyncOperation<GarageDoorOpenResult^>^ OpenAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ bool interfaceMemberPartialOpen);
    virtual Windows::Foundation::IAsyncOperation<GarageDoorCloseResult^>^ CloseAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);
    virtual Windows::Foundation::IAsyncOperation<GarageDoorPushButtonResult^>^ PushButtonAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

    virtual Windows::Foundation::IAsyncOperation<GarageDoorGetIsOpenResult^>^ GetIsOpenAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);
    virtual Windows::Foundation::IAsyncOperation<GarageDoorGetIsPartiallyOpenResult^>^ GetIsPartiallyOpenAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);


private:
    event Windows::Foundation::EventHandler<Platform::Object^>^ _OpenCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _CloseCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _PushButtonCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetIsOpenRequested;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetIsPartiallyOpenRequested;
};

} } } 
