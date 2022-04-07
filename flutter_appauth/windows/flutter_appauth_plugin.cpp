#include "include/flutter_appauth/flutter_appauth_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <map>
#include <memory>
#include <sstream>

namespace {

class FlutterAppauthPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterAppauthPlugin();

  virtual ~FlutterAppauthPlugin();

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
      
  void AuthoriseAndExchangeCodeMethod();
  void AuthoriseMethod();
  void TokenMethod();
  void EndSessionMethod();
};

// static
void FlutterAppauthPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "crossingthestreams.io/flutter_appauth",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<FlutterAppauthPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

FlutterAppauthPlugin::FlutterAppauthPlugin() {}

FlutterAppauthPlugin::~FlutterAppauthPlugin() {}

void FlutterAppauthPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare(AUTHORIZE_AND_EXCHANGE_CODE_METHOD) == 0) {
    result->NotImplemented();
  } else if (method_call.method_name().compare(AUTHORIZE_METHOD) == 0) {
    result->NotImplemented();
  } else if (method_call.method_name().compare(TOKEN_METHOD) == 0) {
    result->NotImplemented();
  } else if (method_call.method_name().compare(END_SESSION_METHOD) == 0) {
    result->NotImplemented();
  } else {
    result->NotImplemented();
  }
  
  void FlutterAppauthPlugin::AuthoriseAndExchangeCodeMethod() {
    
  }
  
  void FlutterAppauthPlugin::AuthoriseMethod() {
    
  }
  
  void FlutterAppauthPlugin::TokenMethod() {
    
  }
  
  void FlutterAppauthPlugin::EndSessionMethod() {
    
  }
}  // namespace

void FlutterAppauthPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  FlutterAppauthPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
