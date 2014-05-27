//
//  CCHSubscriptionService.h
//  CarbonBlack
//
//  Created by Kevin Lee on 4/17/14.
//  Copyright (c) 2014 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 ContextHub Subscription error codes.
 */
typedef NS_ENUM(NSInteger, CCBCarbonSubscriptionErrorCode) {
    /**
     Null tags error code.
     */
    CCHNullTagsCode = 0
};

#define kSubscriptionErrorDomain @"com.contexthub.subscription"

@interface CCHSubscriptionService : NSObject
+ (void)getSubscriptionsWithCompletion:(void(^)(NSArray *subscripitons, NSError *error))completion;

+ (void)addBeaconSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;
+ (void)removeBeaconSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;

+ (void)addGeofenceSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;
+ (void)removeGeofenceSubscriptionForTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;


@end
