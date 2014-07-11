//
//  CCHSubscriptionService.h
//  ContextHub
//
//  Created by Kevin Lee on 4/17/14.
//  Copyright (c) 2014 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 ContextHub Subscription error codes.
 */
typedef NS_ENUM(NSInteger, CCHSubscriptionErrorCode) {
    /**
     Null tags error code.
     */
    CCHNullTagsCode = 0
};


///--------------------
/// @name Notifications
///--------------------

/**
 Posted to tagged beacon subscribers when a corresponding tagged beacon is created.
 */
extern NSString * const CCHBeaconCreatedNotification;

/**
 Posted to tagged beacon subscribers when a corresponding tagged beacon is updated.
 */
extern NSString * const CCHBeaconUpdatedNotification;

/**
 Posted to tagged beacon subscribers when a corresponding tagged beacon is deleted.
 */
extern NSString * const CCHBeaconDeletedNotification;


/**
 Posted to tagged geofence subscribers when a corresponding tagged geofence is created.
 */
extern NSString * const CCHGeofenceCreatedNotification;

/**
 Posted to tagged geofence subscribers when a corresponding tagged geofence is updated.
 */
extern NSString * const CCHGeofenceUpdatedNotification;

/**
 Posted to tagged geofence subscribers when a corresponding tagged geofence is deleted.
 */
extern NSString * const CCHGeofenceDeletedNotification;

/**
 Posted to tagged vault subscribers when a corresponding tagged vault item is created.
 */
extern NSString * const CCHVaultItemCreatedNotification;

/**
 Posted to tagged vault subscribers when a corresponding tagged vault item is updated.
 */
extern NSString * const CCHVaultItemUpdatedNotification;

/**
 Posted to tagged vault subscribers when a corresponding tagged vault item is deleted.
 */
extern NSString * const CCHVaultItemDeletedNotification;



#define kSubscriptionErrorDomain @"com.contexthub.subscription"

/**
 The subscription service is used tell ContextHub that you want to be notified when tagged elements are created, updated, and deleted on the server.  You must enable configure the push notifications if you want to receive updates from the server.
When changes are detected, the subscription service will post notifications to the NSNotificationCenter.

 ## Notifications
 
 When you subscribe to tags, the following notifications are posted when tagged elements are created, updated, and deleted.
 
 ### CCHBeaconCreatedNotification
 the notification object is an NSDictionary representation of the beacon that was created.  The userInfo object is not set.

 ### CCHBeaconUpdatedNotification
 the notification object is an NSDictionary representation of the beacon that was updated.  The userInfo object is not set.

 ### CCHBeaconDeletedNotification
 the notification object is an id of the beacon that was deleted.  The userInfo object is not set.

 ### CCHGeofenceCreatedNotification
 the notification object is an NSDictionary representation of the geofence that was created.  The userInfo object is not set.
 
 ### CCHGeofenceUpdatedNotification
 the notification object is an NSDictionary representation of the geofence that was updated.  The userInfo object is not set.
 
 ### CCHGeofenceDeletedNotification
 the notification object is an id of the geofence that was deleted.  The userInfo object is not set.

 ### CCHVaultItemCreatedNotification
 the notification object is an NSDictionary representation of the vault item that was created.  The userInfo object is not set.
 
 ### CCHVaultItemUpdatedNotification
 the notification object is an NSDictionary of representation of the vault item that was updated.  The userInfo object is not set.
 
 ### CCHVaultItemDeletedNotification
 the notification object is an id of the vualt item that was deleted.  The userInfo object is not set.

 */
@interface CCHSubscriptionService : NSObject

/** 
 @return The singleton instance of the CCHSubscriptionService.
 */
+ (instancetype)sharedInstance;

/**
 Gets all subscriptions for the current device.
 @note Access individual subscriptions using "BeaconSubscription" and "GeofenceSubscription" keys
 @param completion executed when the request completes.  The block is passed an NSDictionary of subscriptions.  If an error occurs, the NSError will be passed to the block.
 */
- (void)getSubscriptionsWithCompletion:(void(^)(NSDictionary *subscriptions, NSError *error))completion;

/**
 Subscribes the device to beacon change notifications for the specified tags.
 @param tags An NSArray of tags.
 @param completionHandler (optional) Is executed when the request completes.  If an error occurs, the NSError will be passed to the block.
 */
- (void)addBeaconSubscriptionForTags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;

/**
 Unsubscribes the device from beacon change notifications for the specified tags.
 @param tags An NSArray of tags.
 @param completionHandler (optional) Is executed when the request completes.  If an error occurs, the NSError will be passed to the block.
 */
- (void)removeBeaconSubscriptionForTags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;

/**
 Subscribes the device to geofence change notifications for the specified tags.
 @param tags An NSArray of tags
 @param completionHandler (optional) Is executed when the request completes.  If an error occurs, the NSError will be passed to the block.
 */
- (void)addGeofenceSubscriptionForTags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;

/**
 Unubscribes the device from geofence change notifications for the specified tags.
 @param tags An NSArray of tags.
 @param completionHandler (optional) Is executed when the request completes.  If an error occurs, the NSError will be passed to the block.
 */
- (void)removeGeofenceSubscriptionForTags:(NSArray *)tags completionHandler:(void(^)(NSError *error))completionHandler;


@end
