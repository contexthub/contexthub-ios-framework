ios-framework
=============

1. download the framework
1. copy it into your framework folder
1. Link your binary with the following Libraries


- MobileCoreServices
- CoreLocation
- CoreMotion


Add ` #import <ContextHub/ContextHub.h>` to your AppDelegate.

```objective-c
- (BOOL)application:(UIApplication *)application 
			didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //Register your app
    [ContextHub registerWithAppId:@"ENTER-THE-UUID-FOR-YOURAPP"];

    return YES;
}

```
