//
//  CCBMotionService.h
//  ContextHub
//
//  Created by Kevin Lee on 12/13/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import "CCHElementServiceProtocol.h"

#define kMotionChangedEvent @"motion_changed"

/**
 The CCBMotionService uses a CMMotionActivityManager to track and register motion activities.
 
  This class implements the `CCBElementServiceProtocol`.
 
 ## Notifications
 
 Subscribe to the notification named __CCHMotionChangedNotification__ if you would like to be notified when change events occur.
 
 The object of the event is a CMMotionActivity.
 
 @note The userInfo object is not set.
 
 */
@interface CCHMotionService : NSObject <CCHElementServiceProtocol>

/**
 returs a static shared instnace of the CCBMotionService
 */
+ (CCHMotionService *)sharedService;

- (NSDictionary *)authorizationStatus;
@end


///--------------------
/// @name Notifications
///--------------------

/**
 Posted when an operation a motion change is detected.
*/
extern NSString * const CCHMotionChangedNotification;

