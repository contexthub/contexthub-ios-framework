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

## Authorization Location Services

You must configure your project for location services:

- In the background mode section, check "Location Updates"
- Add the `NSLocationAlwaysUsageDescription` to your application plist.  You must do this if you ever intend to use geofences or location in your analytics.

## Register The App

Add ` #import <ContextHub/ContextHub.h>` to your AppDelegate.


```objective-c
- (BOOL)application:(UIApplication *)application 
			didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //Register your app
    [ContextHub registerWithAppId:@"ENTER-THE-UUID-FOR-YOURAPP"];

    return YES;
}

```

## Configure the Sensor Pipeline

By default we will tag each pipeline with your `<Application Id>`, `<Device Id>`, and `iOS`. This will allow you to send geofences and beacons to your install base.

You may want to add your own tags to further segment your install base.

```objective-c
[[CCHSensorPipeline sharedInstance] 
    addElementsWithTags: @[
        @"some-tag", 
        @"some-other-tag"
    ]
];
```

## Push Notifications

The ContextHub SDK provides an api for sending push notifications to your application.  You can send messages directly to a device token, or you can organize your installations using tags and alias so that you can send messages to groups of devices.

### Certificates

Before you can use the push services you will need to create a Production and Development push certificate for you application on iTunes Connect.

After you have downloaded your push certificates, you will need to create a PEM file out of both of them.  

1. Open the Keychain Access application and select your production certificate and its private key.
2. From the File menu select "Export Items..."
3. Name the export "Certificates.p12" and save it to your desktop.
4. Open a terminal window and change directories to your Desktop
5. Run the following command line:

```
openssl pkcs12 -in Certificates.p12 -out certificate.pem -nodes -clcerts
```

6. Open "certificate.pem" using your favorite text editor.
7. Copy all of the contents of the pem file and paste it into the certificate field located under the settings for your application on http://app.contextHub.com.

Now repeat the previous steps, this time start by exporting your Development certificate.

### Register for Push

In your app delegate:

``` objective-c
- (BOOL)application:(UIApplication *)application 
			didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Register your app
    [ContextHub registerWithAppId:@"ENTER-THE-UUID-FOR-YOURAPP"];

    // Register Push
    UIUserNotificationType notificationTypes = UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound;
    UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:notificationTypes categories:nil];
    [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    
    // Add pipeline tags
    [[CCHSensorPipeline sharedInstance] 
    addElementsWithTags: @[
        @"some-tag", 
        @"some-other-tag"
    ]
];

  return YES;
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
    // Register to receive notifications
    [application registerForRemoteNotifications];
}
 
- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void(^)())completionHandler {
    // Handle the actions
    if ([identifier isEqualToString:@"declineAction"]){
    
    } else if ([identifier isEqualToString:@"answerAction"]){
    
    }
}
```

## Online Documentation

http://docs.contexthub.com

## SDK Documentation

http://docs.contexthub.com/contexthub-ios-framework/

## Xcode DocSet Installation

1. Quit xcode
2. Copy `com.contexthub.ContextHub.docset` into your DocSet folder.  `~/Library/Developer/Shared/Documentation/DocSets/`
3. Launch xcode and you will see reference links when you access help on the ContextHub.framework classes.

##Support

If you have questions, bugs, or feature requests, please open an issue with us.  We are working hard to make this framework great and would love to hear from you.

https://github.com/contexthub/contexthub-ios-framework/issues
