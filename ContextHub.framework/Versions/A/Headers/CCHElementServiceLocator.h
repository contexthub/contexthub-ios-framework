//
//  CCBElementServiceLocator.h
//  ContextHub
//
//  Created by Kevin Lee on 10/24/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHLocationService.h"
#import "CCHMotionService.h"
#import "CCHDeviceInformationService.h"

/** 
 The elemente service locator is the class that manages all of the objects that implement the CCBElementServiceProtocol.  
 It listens for notifications that are typically posted from the CCBElementManifestService.  It provides a method for registering user defined CCBElementServiceProtocol classes.
 When an element notification is received for a registered service, it will find the registered service and call the [CCBElementServiceProtocol requestServiceAuthorizationForElement:element] method
 for the related element.
 */
@interface CCHElementServiceLocator : NSObject

/**
 returns the shared instance of the Element Service Locator
 */
+ (CCHElementServiceLocator *)sharedLocator;

/** 
 Used to exted the service with userdefined elements.
 @param elementService service that implements the CCBElementServiceProtocol
 @param element is the element that the service will manage.
 */
- (void)registerService:(id<CCHElementServiceProtocol>)elementService forElement:(NSString *)element;
- (NSArray *)registeredServices;
- (NSMutableArray *)contextInformation;
@end
