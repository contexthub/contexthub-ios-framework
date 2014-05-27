//
//  CCBDeviceInformationService.h
//  ContextHub
//
//  Created by Kevin Lee on 12/16/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIDevice.h>
#import "CCHElementServiceProtocol.h"

#define kDeviceInfo @"device_information"
/**
Wraps common device information so that it can be easily assembled in context event packages.
 */
@interface CCHDeviceInformationService : NSObject <CCHElementServiceProtocol>

/**
 returns the static shared instance of the device information service
 */
+ (CCHDeviceInformationService *)sharedService;

- (NSDictionary *)deviceInformation;
@end
