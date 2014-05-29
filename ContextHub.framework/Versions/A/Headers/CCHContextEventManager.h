//
//  CCHContextEventManager.h
//  ContextHub
//
//  Created by Kevin Lee on 10/25/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHElementServiceLocator.h"


/**
 The context event manager listens for context_event_triggered notifications.  
 When a notification is received, the manager assembles the event package from
 the notification object. After the the package is assembled, the manager will call delegate lifecycle methods and post lifecycle notifications.
 
 ## Notifications
 
 The following life-cycle notifications are posted.  The notifications are called before the associated delegate methods are called.

 ### CCHContextEventManagerWillPostEvent
 the object is the assembled context event and the userInfo object is not set.

 ### CCHContextEventManagerDidPostEvent
 the object is the assembled context event and the userInfo object is not set.
 
 ### CCHContextEventManagerDidCancelEvent
 the object is the assembled context event and the userInfo object is not set.
 
 ### CCHContextEventManagerDidDetectEvent
 the object is the triggered event and the userInfo object is not set.
 @warning the notification object is not the fully assembled event.
 
*/
@interface CCHContextEventManager : NSObject
/** 
 Returns the static instnace of the CCHContextEventManager
 */
+ (CCHContextEventManager *)sharedManager;

@end

/**
 Implement the delegate if you want to take action before or after an event is sent to ContextHub.  You can also decide keep an event from firing.
 */
@protocol CCHContextEventManagerDelegate <NSObject>

@optional
/**
 Sometimes you may want to keep an event from posting to the ContextHub service.  This method gives you the opportunity to stop the call.
 If you return NO, none of the other delegate methods will git called, and the event will be discarded.  
 @note No history of the event will be captured if you return NO here.
 returns boolean indicating if the event should be posted to ContextHUB
 @param eventManager the CCHContextEventManager that handling the context event.
 @param event the context event that triggered the call.
 */
- (BOOL)contextEventManager:(CCHContextEventManager *)eventManager
            shouldPostEvent:(NSDictionary *)event;


/**
 Called before an event was sent to ContextHub.
 @param eventManager the CCHContextEventManager that will the event
 @param event the context event that was sent to ContextHub
 */
- (void)contextEventManager:(CCHContextEventManager *)eventManager
              willPostEvent:(NSDictionary *)event;


/**
 Called after an event was sent to ContextHub.
 @param eventManager the CCHContextEventManager that sent the event
 @param event the context event that was sent to ContextHub
 */
- (void)contextEventManager:(CCHContextEventManager *)eventManager
               didPostEvent:(NSDictionary *)event;

@end

/**
Implement the data source when you want to add custom data to the context event.
 */
@protocol CCHContextEventManagerDataSource <NSObject>

@optional

/**
 Returns a serializable dictionary that will get added to context event payload property.
 @param event is the event that will be sent to the server.
 */
- (NSDictionary *)payloadForEvent:(NSDictionary *)event;

/**
 Returns a serializable dictionary that will get added to context event payload property.
 @param event is the event that will be sent to the server.
 @param eventManager the CCHContextEventManager that will send the event.
 */
- (NSDictionary *)contextEventManager:(CCHContextEventManager *)eventManager payloadForEvent:(NSDictionary *)event;

@end


@interface CCHContextEventManager ()
/**
 The CCHContextEventManagerDelegate
 */
@property id<CCHContextEventManagerDelegate> delegate;

/**
 The CCHContextEventManagerDataSource
 */
@property id<CCHContextEventManagerDataSource> dataSource;

@end

///--------------------
/// @name Notifications
///--------------------

/**
 Posted before an event is posted to ContextHub
 */
extern NSString * const CCHContextEventManagerWillPostEvent;

/**
 Posted after an event has been posted to ContextHub
 */
extern NSString * const CCHContextEventManagerDidPostEvent;

/**
 Posted when the event was cancelled.
 */
extern NSString * const CCHContextEventManagerDidCancelEvent;

/**
 Posted when an event is detected.
 */
extern NSString * const CCHContextEventManagerDidDetectEvent;
