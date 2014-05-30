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

#define kSubscriptionErrorDomain @"com.contexthub.subscription"

/**
 The subscription service allows you to notify ContextHub that you are interested in getting notified when tagged beacons and geofences are changed.
 By default the SDK is only notified when a Global object is changed.  This services gives you the ability to get updates for tagged objects too.
 */
@interface CCHSubscriptionService : NSObject

/**
 Gets all subscriptions for the current device.
 @param completion executed when the request completes.  The block is passed an NSArray of subscriptions.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)getSubscriptionsWithCompletion:(void(^)(NSArray *subscripitons, NSError *error))completion;

/**
 Subscribes the device to beacon change notifications for the specified tags.
 @param tags An NSArray of tags
 @param completion (optional) Is executed when the request complets.  The block is passed a BOOL indicating the success of the reuqest.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)addBeaconSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Unsubscribes the device from beacon change notifications for the specified tags.
 @param tags An NSArray of tags
 @param completion (optional) Is executed when the request complets.  The block is passed a BOOL indicating the success of the reuqest.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)removeBeaconSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Subscribes the device to geofence change notifications for the specified tags.
 @param tags An NSArray of tags
 @param completion (optional) Is executed when the request complets.  The block is passed a BOOL indicating the success of the reuqest.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)addGeofenceSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Unubscribes the device from geofence change notifications for the specified tags.
 @param tags An NSArray of tags
 @param completion (optional) Is executed when the request complets.  The block is passed a BOOL indicating the success of the reuqest.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)removeGeofenceSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;


@end
