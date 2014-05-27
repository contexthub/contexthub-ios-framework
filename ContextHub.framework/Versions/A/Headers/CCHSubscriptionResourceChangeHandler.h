//
//  CCHSubscriptionResourceChangeHandler.h
//  ContextHub
//
//  Created by Kevin Lee on 4/24/14.
//  Copyright (c) 2014 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHBeaconService.h"
#import "CCHGeofenceService.h"
#import "CCHLocationService.h"

@interface CCHSubscriptionResourceChangeHandler : NSObject
+ (void)handleResourceChanged:(NSDictionary *)resourceInfo withCompletion:(void(^)(BOOL didFetchData))completion;
@end
