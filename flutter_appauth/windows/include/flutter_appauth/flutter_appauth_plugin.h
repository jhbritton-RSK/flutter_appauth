#ifndef FLUTTER_PLUGIN_FLUTTER_APPAUTH_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_APPAUTH_PLUGIN_H_

#include <flutter_plugin_registrar.h>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

const std::string AUTHORIZE_AND_EXCHANGE_CODE_METHOD = "authorizeAndExchangeCode";
const std::string AUTHORIZE_METHOD = "authorize";
const std::string TOKEN_METHOD = "token";
const std::string END_SESSION_METHOD = "endSession";

FLUTTER_PLUGIN_EXPORT void FlutterAppauthPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_FLUTTER_APPAUTH_PLUGIN_H_
