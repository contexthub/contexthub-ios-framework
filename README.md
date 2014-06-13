ContextHub iOS framework
=============

## Download the framework
https://github.com/contexthub/contexthub-ios-framework/archive/master.zip

## Add to Project
Copy `ContextHub.framework` into the framework group of your Xcode project.
Be sure you select `copy items into to destination's group folder (if needed)`
 
## Include Libraries
- MobileCoreServices
- CoreLocation
- CoreMotion

## Register
Add ` #import <ContextHub/ContextHub.h>` to your AppDelegate.

```objective-c
- (BOOL)application:(UIApplication *)application 
			didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //Register your app
    [ContextHub registerWithAppId:@"ENTER-THE-UUID-FOR-YOURAPP"];

    return YES;
}

```

##Support

If you have questions, bugs, or feature requests, please open an issue with us.  We are working hard to make this framework great and would love to hear from you.

https://github.com/contexthub/contexthub-ios-framework/issues
