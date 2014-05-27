//
//  CCBElementServiceProtocol.h
//  ContextHub
//
//  Created by Kevin Lee on 10/24/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
/** 
 The Service protocol defines the methods that need to be implemented if you want to register a custom element service.
 */
@protocol CCHElementServiceProtocol <NSObject>

/**
 called when an element is detected.  Use this method to ask users for permission and/or to set up your serivec.  This method is called when ContextHub detects that it needs to work with your service.
 @returns yes if successful and no if not
 */
- (BOOL)requestServiceAuthorizationForElement:(NSString *)element;

/**
 return the context information for the service.  These are typically defined by the ContextHub API, but can also be custom context dictionaries.  This method is called when a context event occurs.  The context package is passed along with the event and will be posted to the context API.
 */
- (NSDictionary *)contextInfoForElement:(NSString *)element;

/**
returns information about the authorization status for the service. For example:
 
    {location:denied}
 
 @note returns nil if authorization is not required.
 */
- (NSDictionary *)authorizationStatus;

/**
 returns the key that will be used to store the context data.
 
 @note this key can be used in ContextHub buisness rules.
 */
- (NSString *)contextKey;
@end
