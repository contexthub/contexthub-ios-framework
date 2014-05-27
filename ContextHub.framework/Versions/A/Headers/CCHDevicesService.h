//
//  CCBDevicesService.h
//  ContextHub
//
//  Created by Kevin Lee on 2/12/14.
//  Copyright (c) 2014 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHDeviceInformationService.h"
#import "CCHElementServiceLocator.h"


/**
 This service is intended to be used by the SDK.
 */
@interface CCHDevicesService : NSObject

/**
 Send the device profile to ContextHub.
 */
+ (void)registerDevice;
@end
