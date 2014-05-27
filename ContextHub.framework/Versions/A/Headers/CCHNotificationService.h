//
//  CCBNotificationService.h
//  ContextHub
//
//  Created by Travis Fischer on 9/26/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The notification service should be used to register devices and to send push notifications with the ContextHub Push service.
 */
@interface CCHNotificationService : NSObject


/**
 * Singleton instance of notification service
 */
+ (id)sharedService;

/**
 * Register a device for push notification. Use the same method to update existing registrations as well.
 * @param token The device token
 * @param completion Completion block for registration. Returns nil if succeeded otherwise includes an error object.
 */
- (void)registerDeviceToken:(id)token withCompletion:(void(^)(NSError *error))completion;

/**
 * Register a device for push notification.
 * @param token The device token
 * @param alias A string alias to associate with the device token.
 * @param completion Completion block for registration. Returns nil if succeeded otherwise includes an error object.
 */
- (void)registerDeviceToken:(id)token withAlias:(NSString *)alias withCompletion:(void(^)(NSError *error))completion;

/**
 * Register a device for push notification.
 * @param token The device token
 * @param alias A string alias to associate with the device token.
 * @param tags An array of tags to associate with the token
 * @param completion Completion block for registration. Returns nil if succeeded otherwise includes an error object.
 */
- (void)registerDeviceToken:(id)token withAlias:(NSString *)alias andTags:(NSArray *)tags withCompletion:(void(^)(NSError *error))completion;


/**
 * Request the devices registered to receive push notifications
 * @param completion Completion block that takes a list of devices and an error. If the request succeeded, the error object will be nil.
 */
- (void)requestDevicesForNotificationWithCompletion:(void(^)(NSArray *devices, NSError * error))completion;

/**
 * Send a notification to multiple devices
 * @param devices The devices to notify
 * @param message The message to be sent
 * @param userInfo Other data to be sent in the notification
 * @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendNotificationToDevices:(NSArray *)devices withMessage:(NSString *)message userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;


/**
 * Send a notification to multiple registered aliases
 * @param aliases The aliases to notify
 * @param message The message to be sent
 * @param userInfo Other data to be sent in the notification
 * @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendNotificationToAliases:(NSArray *)aliases withMessage:(NSString *)message userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;



/**
 * Send a notification to multiple tag sets
 * @param tags The tags to notify
 * @param message The message to be sent
 * @param userInfo Other data to be sent in the notification
 * @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendNotificationToTags:(NSArray *)tags withMessage:(NSString *)message userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;



/**
 Send Apple Push Notifications to multiple devices
 The userInfo dictionary can contain custom data and standard apple push notification properties.
 This implementation will pull out the apns keys and pass all other items as custom data.
 
 | key | value|
 | --- | --- |
 | alert | the message you want sent |
 | sound | sound you want played |
 | content-available | pass in a 1 if you want to deliver a push in the background |
 | badge | the number to be displayed on the icon |

  @param devices The devices to notify
  @param userInfo Other data to be sent in the notification
  @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendAPNSNotificationToDevices:(NSArray *)devices userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;


/**
 * Send Apple Push Notification to multiple registered aliases
 *
 *
 * The userInfo dictionary can contain custom data and standard apple push notification properties.
 * This implementation will pull out the apns keys and pass all other items as custom data.
 *
 * | key | value|
 * | --- | --- |
 * | alert | the message you want sent |
 * | sound | sound you want played |
 * | content-available | pass in a 1 if you want to deliver a push in the background |
 * | badge | the number to be displayed on the icon |
 * @note this only sends notifications to iOS devices.
 *
 * @param aliases The aliases to notify
 * @param userInfo Other data to be sent in the notification
 * @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendAPNSNotificationToAliases:(NSArray *)aliases userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;


/**
 * Send Apple Push Notifications to multiple tag sets
 * @note this only sends notifications to iOS devices.
 * @param tags The tags to notify
 * @param userInfo Other data to be sent in the notification
 * @param completion Completion block. Not sure what this should take yet.
 */
- (void)sendAPNSNotificationToTags:(NSArray *)tags userInfo:(NSDictionary *)userInfo withCompletion:(void (^)(NSError *error))completion;



@end
