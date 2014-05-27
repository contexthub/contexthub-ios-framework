//
//  CCBLocationService.h
//  ContextHub
//
//  Created by Kevin Lee on 10/24/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "CCHElementServiceProtocol.h"
#import "CCHGeofenceService.h"
#import "CCHBeaconService.h"


#define kGeofenceInEvent @"geofence_in"
#define kGeofenceOutEvent @"geofence_out"
#define kLocationChangedEvent @"location_changed"
#define kBeaconInEvent @"beacon_in"
#define kBeaconOutEvent @"beacon_out"
#define kBeaconChangedEvent @"beacon_changed"
#define kBeaconProximityFar @"far_state"
#define kBeaconProximityNear @"near_state"
#define kBeaconProximityImmediate @"immediate_state"

/**
The CCBLocation service works the CLLocationManager to track and register location based information.  It will detect and register Geofences that are configured in the ContextHub api.
 If the location element is configured for the app, it will also monitor for significant location changes.  When region events or location change events are triggered, it posts a context_event_triggered notification and sets the event package as the contents.
 

 This class implements the CCBElementServiceProtocol and the CLLocationManagerDelegate.
 */
@interface CCHLocationService : NSObject <CCHElementServiceProtocol, CLLocationManagerDelegate>

/**
returns the static shared instance f the CCBLocationService
 */
+ (CCHLocationService *)sharedService;

/**
 returns the location from the location manager
 */
- (CLLocation*)currentLocation;

/**
 returns the authorization status for the application.

    @{@"location":"authorized"}
 
 */
- (NSDictionary *)authorizationStatus;

- (void)registerBeaconRegion:(NSDictionary *)beaconInfo;
- (void)registerGeofenceRegion:(NSDictionary *)geofenceInfo;

@property (nonatomic, readonly) BOOL isTrackingGeofences;
@property (nonatomic, readonly) BOOL isTrackingBeacons;


///--------------------
/// @name Notifications
///--------------------

/**
 Posted when location authorization status changes.
 */
extern NSString * const CCHDidChangeLocationAuthorizationStatus;


@end
