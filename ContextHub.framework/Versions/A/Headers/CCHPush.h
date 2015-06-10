//
//  CCHPush.h
//  ContextHub
//
//  Created by Travis Fischer on 9/26/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CCHContextHubPush.h"

 /**
 The push service is used to register devices and to send push notifications with the ContextHub Push service.
 
 The userInfo dictionary that is passed to the methods in this api can contain custom data and standard apple push notification properties.
 This implementation will pull out the apns and ContextHub keys and pass all other items as custom data.
 
       Keys
 | key   | value |
 | ----- | ----- |
 | alert | the message you want sent |
 | sound | sound file you want played |
 | content-available | pass in a 1 if you want to deliver a push in the background |
 | badge | the number to be displayed on the icon |
 | exclude_device_ids | an array of the device ids that should be excluded |
 | exclude_push_tokens | an array of push tokens that should be excluded |
 | mdm | mobile device management key |
 | priority | can be either be set to 10 (immediate) or 5 (conserve power) |
 | expiry | identifies when a notification is no longer valid and can be discarded.  The default is 1 day |
 | category | category for push |
 | url_args | sets the url arguments |
 | collapse_key | used to group messages on the Google Cloud Messaging service |
 
 */
@interface CCHPush : NSObject


/**
 @ return The singleton instance of the CCHPush service.
 */
+ (instancetype)sharedInstance;

/**
  Register a device for push notifications.
  @param token The device token.
  @param alias (optional) A string alias to associate with the device token. (pass nil to ignore value, @"" to remove current alias)
  @param tags (optional) An array of tags to associate with the token. (pass nil to ignore value, @[] to remove all current tags)
  @param completionHandler (optional) returns nil if succeeded otherwise includes an error object.
 */
- (void)registerDeviceToken:(id)token alias:(NSString *)alias tags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;

/**
 Update a device's alias and tags.
 @param alias (optional) A string alias to associate with the device token. (pass "nil" to ignore value, @"" to remove current alias)
 @param tags (optional) An array of tags to associate with the token. (pass nil to ignore value, @[] to remove all current tags)
 @param completionHandler (optional) returns nil if succeeded otherwise includes an error object.
 */
- (void)updateAlias:(NSString *)alias tags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;

/**
 Send Push Notifications to devices.
  @param devices The device ids to notify.
  @param userInfo The data to be sent in the notification.
  @param completionHandler Completion block.  If an error occurs an NSError will be passed to the block.
 */
- (void)sendNotificationToDevices:(NSArray *)devices userInfo:(NSDictionary *)userInfo completionHandler:(void (^)(NSError *error))completionHandler;


/**
 Send Push Notification to aliases.

 @param aliases The aliases to notify.
 @param userInfo The data to be sent in the notification. Exclude devices by passing an array of device IDs in the @"exclude_device_ids" key.
 @param completionHandler Completion block.  If an error occurs an NSError will be passed to the block.
 */
- (void)sendNotificationToAliases:(NSArray *)aliases userInfo:(NSDictionary *)userInfo completionHandler:(void (^)(NSError *error))completionHandler;


/**
 Send Push Notification to tags.
 @param tags The tags to notify.
 @param userInfo The data to be sent in the notification. Exclude devices by passing an array of device IDs in the @"exclude_device_ids" key.
 @param completionHandler Completion block.  If an error occurs an NSError will be passed to the block.
 */
- (void)sendNotificationToTags:(NSArray *)tags userInfo:(NSDictionary *)userInfo completionHandler:(void (^)(NSError *error))completionHandler;

/**
 Send Push Notification to tags.
 
 @param tags The tags to notify.
 @param tagOperator (optional) Operator used to build the query with the tags.  Passing ANY will find all geofences that match any of the tags. Passing ALL will find geofences that have all of the tags provided.  Passing nil will use the default ALL operator.
 @param userInfo  The data to be sent in the notification. Exclude devices by passing an array of device IDs in the @"exclude_device_ids" key.
 @param completionHandler Completion block.  If an error occurs an NSError will be passed to the block.
 */
- (void)sendNotificationToTags:(NSArray *)tags operator:(NSString *)tagOperator userInfo:(NSDictionary *)userInfo completionHandler:(void (^)(NSError *error))completionHandler;


/**
 When contextual elements are changed, ContextHub will send background push notifications to the application letting you know that new content is available.
 This will allow the context events to update and stay in sync with the server.
 @param application The UIApplication that received the remote notification.
 @param userInfo The NSDictionary that was delivered with the remote notification.
 @param completionHandler A completion block that is executed when the context sync is completed.  The CCHContextHubPush BOOL indicates if the push notification was generated by ContextHub.
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo completionHandler:(void(^)(enum UIBackgroundFetchResult result, CCHContextHubPush *contextHubPush))completionHandler;

@end
