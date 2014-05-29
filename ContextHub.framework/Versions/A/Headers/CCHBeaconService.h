//
//  CCHBeaconService.h
//  ContextHub
//
//  Created by Kevin Lee on 11/7/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#define CCHGlobalTag @""

/**
 The Beacon Service is used to work with the beacon api on ContextHub.
 */
@interface CCHBeaconService : NSObject

/**
 Creates a new beacon on the ContextHub server.
 @param beaconRegion CLBeaconRegion to be added to ContextHub.
 @param tags (optional) used to scope the beacon.  If nil is passed, a global beacon will be created.
 @param completion (optional) called when the request completes.  The block is passed an NSDictionary object that represents the iBeacon. If an error occurs, the NSError will be passed to the block.
 */
+ (void)createBeacon:(CLBeaconRegion *)beaconRegion withTags:(NSArray *)tags withCompletion:(void(^)(NSDictionary *beacon, NSError *error))completion;

/**
 Gets a beacon from ContextHub using the beacon Id.
 @param beaconId id of the iBeacon stored in ContextHub
 @param completion called when the request completes.  The block is passed an NSDictionary object that represents an iBeacon or an NSError object.
 */
+ (void)getBeaconWithId:(NSString *)beaconId completion:(void(^)(NSDictionary *beacon, NSError *error))completion;

/**
 Gets beacons from the ContextHub server.
 @param tag (optional) used to filter results.  Passing nil will return all beacons.  Passing CCHGlobalTag will return only global geofences.
 @param completion called when the request completes.  The block is passed an NSArray of NSDictionary objects that represent iBeacons.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)getBeaconsWithTag:(NSString *)tag completion:(void(^)(NSArray *beacons, NSError *error))completion;

/**
 Updates a beacon on the ContextHub server.
 @param beacon to be updated on ContextHub.
 @param completion called when the request completes.
 */
+ (void)updateBeacon:(NSDictionary *)beacon withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Deletes an existing beacon from ContextHub.
 @param beacon to be deleted from ContextHub.
 @param completion called when the request completes.
 */
+ (void)deleteBeacon:(NSDictionary *)beacon withCompletion:(void(^)(NSError *error))completion;

/**
 Creates a CLBeaconRegion from a beacon dictionary returned from ContextHub
 @param beacon NSDictionary that contains beacon information.
 @return CLBeaconRegion that is built using the beacon dictionary.
 */
+ (CLBeaconRegion *)regionForBeacon:(NSDictionary *)beacon;


@end
